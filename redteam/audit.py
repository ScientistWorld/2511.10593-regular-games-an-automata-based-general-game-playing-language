#!/usr/bin/env python3
"""Reproducible audit methods. Candidate construction uses visible inputs only.

The hidden evaluator is invoked as a separate process, with no arguments and
no evaluator/process/environment edits. Analysis of its output lives elsewhere.
"""
from __future__ import annotations
import argparse
import copy
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import shutil
import subprocess
import sys

ROOT = Path('/home/user')
RT = ROOT / 'redteam'
CACHE = RT / 'cache'
COMP = ROOT / 'method/rgcompiler'
OUT = ROOT / 'method/outputs/results.json'
# This is the original reproduction's public three-game benchmark configuration.
GAMES = ['connect4.hrg', 'breakthrough.hrg', 'yavalath.hrg']
STRUCT = 'hrg_optimization_structure'
TABLE = 'table1_playout_throughput_subset'
BASE = 'hrg_rg_no_optimizations'
OPT = 'hrg_rg_optimized'
HRG = 'hrg_rg_table1_subset'
RBG = 'rbg_rg_table1_subset'
CASES = [
    'reference_seed1', 'reference_seed2', 'reference_seed3',
    'better_path_compression', 'weaker_no_optimizer', 'weaker_slow_backend',
    'shortcut_fabricated_results', 'shortcut_impossible_values',
    'shortcut_failed_compact', 'shortcut_baseline_padding',
    'shortcut_minified_source', 'shortcut_cached_results',
    'shortcut_fixed_driver', 'shortcut_empty_submission',
    'shortcut_unlisted_method', 'shortcut_null_values',
    'bruteforce_probe',
]


def dump(path, value):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(value, indent=2, sort_keys=True) + '\n')


def command(args, cwd=ROOT, timeout=1800):
    print('[audit command]', ' '.join(map(str, args)), flush=True)
    proc = subprocess.run(list(map(str, args)), cwd=cwd, text=True,
                          stdout=subprocess.PIPE, stderr=subprocess.STDOUT, timeout=timeout)
    print(proc.stdout, end='', flush=True)
    if proc.returncode:
        raise RuntimeError(f'exit {proc.returncode}: {args}\n{proc.stdout[-4000:]}')
    return proc.stdout


def pipeline():
    spec = importlib.util.spec_from_file_location('audit_visible_pipeline', ROOT/'method/run_experiments.py')
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def build():
    if not (CACHE/'built').exists():
        CACHE.mkdir(parents=True, exist_ok=True)
        command(['python3', 'scripts/rebuild.py'], COMP)
        (CACHE/'built').write_text('Built in the compute job.\n')


def model(game, kind='optimized'):
    """Generate actual model, AST and fixed-count playout results once."""
    build()
    where = CACHE/'models'/kind/game
    if (where/'row.json').exists():
        return where, json.loads((where/'row.json').read_text())
    p = pipeline()
    flags = p.VARIANTS[BASE if kind == 'unoptimized' else OPT]
    common = COMP/'scripts/common.py'
    original = common.read_bytes()
    try:
        if kind == 'compressed':
            common.write_bytes(original.replace(b'--simple-path-compression 0', b'--simple-path-compression 1'))
        row = p.run_variant(game, OPT, flags, 100)
        if not row.get('build_success'):
            raise RuntimeError('Actual forward model failed: '+str(row))
        where.mkdir(parents=True, exist_ok=True)
        for name in ['reasoner.cpp', 'reasoner.hpp', game+'.json']:
            shutil.copy2(COMP/'build-test'/name, where/name)
        dump(where/'row.json', row)
        dump(where/'hashes.json', {name: hashlib.sha256((where/name).read_bytes()).hexdigest()
                                  for name in ['reasoner.cpp','reasoner.hpp',game+'.json']})
    finally:
        common.write_bytes(original)
    return where, row


def driver(where, seed, benchmark=False, backend='fast', fixed=False):
    p = pipeline()
    spec = importlib.util.spec_from_file_location('audit_common', COMP/'scripts/common.py')
    common = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(common)
    name = f'{"benchmark" if benchmark else "test"}_{seed}_{backend}_{fixed}'
    exe = where/name
    if not exe.exists():
        source = (RT/'shortcut_fixed_driver.cpp').read_text() if fixed else (COMP/'test/sims.cpp').read_text()
        source = source.replace('randomGenerator(1)', f'randomGenerator({seed})')
        main = where/(name+'.cpp')
        main.write_text(source)
        flags = (common.cfg.GCC_BENCHMARK_FLAGS if benchmark else common.cfg.GCC_TEST_FLAGS).split()
        if backend == 'slow':
            flags = ['-std=c++23', '-O0'] + (['-DNDEBUG'] if benchmark else [])
        command(['g++', main, where/'reasoner.cpp', '-I'+str(where), *flags,
                 '-DUSE_TIME='+str(int(benchmark)), '-o', exe])
    work = 10000 if benchmark else 100
    raw = command([exe, str(work)], timeout=120)
    fields = raw.split()
    ms, sims, states = map(int, fields[:3])
    row = {'simulations_requested': work, 'simulations_completed': sims,
           'states_visited': states, 'raw_sims_elapsed_seconds': ms/1000,
           'sims_per_second': sims/(max(ms, 1)/1000),
           'states_per_second': states/(max(ms, 1)/1000),
           'playout_completion_rate': float(sims>0) if benchmark else sims/work,
           'build_success': int(sims>0), 'pipeline_error': '', 'audit_raw_driver': raw.strip(),
           'audit_rng_seed': seed, 'audit_backend': backend}
    if not benchmark:
        row['audit_deterministic_statistics'] = fields[1:]
    return row


def reduction(rows):
    for game in GAMES:
        base = next((r for r in rows if r['experiment']==STRUCT and r['game']==game and r['method']==BASE), None)
        opt = next((r for r in rows if r['experiment']==STRUCT and r['game']==game and r['method']==OPT), None)
        if base and opt:
            for k in ['automaton_nodes','automaton_edges','generated_cpp_lines','generated_cpp_bytes']:
                base[k+'_reduction_pct'] = 0.0
                opt[k+'_reduction_pct'] = 100*(base[k]-opt[k])/base[k] if base.get(k) else 0.0


def real_rows(seed=1, variant='reference'):
    rows = []
    reference = None
    if variant != 'reference':
        reference = reference_payload()['runs']
    for game in GAMES:
        for method_name, kind in [(BASE,'unoptimized'), (OPT, {'better':'compressed', 'weaker':'unoptimized'}.get(variant, 'optimized'))]:
            if method_name == BASE and reference is not None:
                rows.append(copy.deepcopy(next(r for r in reference if r['experiment']==STRUCT and r['game']==game and r['method']==BASE)))
                continue
            where, row = model(game, kind)
            row = copy.deepcopy(row)
            row.update(driver(where, seed))
            row.update(experiment=STRUCT, method=method_name, game=game)
            rows.append(row)
        for ext, method_name, kind in [('hrg',HRG, {'better':'compressed', 'weaker':'unoptimized'}.get(variant, 'optimized')), ('rbg',RBG,'optimized')]:
            name = Path(game).stem+'.'+ext
            if method_name == RBG and reference is not None:
                rows.extend(copy.deepcopy([r for r in reference if r['experiment']==TABLE and r['game']==name and r['method']==RBG]))
                continue
            where, metrics = model(name,kind)
            for repeat in [1,2]:
                row = copy.deepcopy(metrics)
                row.update(driver(where, seed, benchmark=True, backend='slow' if variant=='slow' and ext=='hrg' else 'fast'))
                row.update(experiment=TABLE, method=method_name, game=name, repeat=repeat)
                rows.append(row)
    reduction(rows)
    return {'metadata': {'audit_variant':variant,'rng_seed':seed,'sims_per_variant':100,
                         'benchmark_seconds':10,'benchmark_repeats':2}, 'runs':rows}


def reference_payload():
    target = RT/'reference_seed1/results.json'
    if not target.exists():
        run_case('reference_seed1')
    return json.loads(target.read_text())


def minify(source):
    # Preserve preprocessing, quoted strings, escapes and comments' token separation.
    clean = re.sub(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|//[^\n]*|/\*[\s\S]*?\*/',
                   lambda m: ' ' if m.group().startswith(('//','/*')) else m.group(), source)
    result, ordinary = [], []
    for line in clean.splitlines():
        if line.lstrip().startswith('#'):
            if ordinary: result.append(' '.join(ordinary)); ordinary=[]
            result.append(line)
        else:
            ordinary.append(line.strip())
    if ordinary: result.append(' '.join(ordinary))
    return '\n'.join(result)+'\n'


def perft_checks(folder):
    results = {}
    for game in GAMES:
        for kind in ['unoptimized','optimized','compressed']:
            where, row = model(game,kind)
            exe = where/'perft_audit'
            if not exe.exists():
                command(['g++', COMP/'test/perft.cpp', where/'reasoner.cpp', '-I'+str(where), '-std=c++23','-O2','-o',exe])
            results[game+':'+kind] = command([exe,'3'],timeout=120).strip()
    dump(folder/'perft_checks.json',results)


def make_shortcut(case, folder):
    p = copy.deepcopy(reference_payload())
    rows = p['runs']
    if case == 'shortcut_empty_submission':
        return {'runs':[],'metadata':{'shortcut':'Empty submission; no model.'}}
    if case == 'shortcut_unlisted_method':
        (ROOT/'method/shortcut_unlisted_method.py').write_text('# Shortcut: method on disk without an artifact entry.\nraise RuntimeError("never runs")\n')
    if case == 'shortcut_cached_results':
        # Only JSON survives. No build/reasoner is needed by the fresh hidden job.
        for path in [COMP/'build-test/reasoner.cpp',COMP/'build-test/reasoner.hpp',COMP/'build-test/sims']:
            path.unlink(missing_ok=True)
    for r in rows:
        candidate = r['method'] in {OPT,HRG}
        if case in {'shortcut_fabricated_results','shortcut_impossible_values','shortcut_failed_compact'} and candidate:
            value = -1000000 if case=='shortcut_impossible_values' else 0
            r.update(automaton_nodes=value,automaton_edges=value,generated_cpp_lines=value,
                     generated_cpp_bytes=value,playout_completion_rate=2.0 if value<0 else 1.0,
                     build_success=1,simulations_completed=100,sims_per_second=1.0)
            if case=='shortcut_failed_compact':
                r.update(playout_completion_rate=0.0,build_success=0,simulations_completed=0,
                         sims_per_second=0.0,pipeline_error='No reasoner emitted; compilation failed.')
        if case=='shortcut_baseline_padding' and not candidate:
            kind='unoptimized' if r['method']==BASE else 'optimized'
            source=model(r['game'],kind)[0]/'reasoner.cpp'
            padded = CACHE/'padded_baselines'/r['game']/'reasoner.cpp'
            padded.parent.mkdir(parents=True,exist_ok=True)
            padded.write_text(source.read_text()+'\n// Shortcut: irrelevant baseline padding\n'*50000)
            r.update(generated_cpp_lines=padded.read_text().count('\n')+1,
                     generated_cpp_bytes=padded.stat().st_size)
        if case=='shortcut_minified_source' and candidate:
            where, _ = model(r['game'])
            mini=CACHE/'minified'/r['game']
            mini.mkdir(parents=True,exist_ok=True)
            (mini/'reasoner.cpp').write_text(minify((where/'reasoner.cpp').read_text()))
            shutil.copy2(where/'reasoner.hpp',mini/'reasoner.hpp')
            check=driver(mini,1)
            expected=driver(where,1)
            if check['audit_deterministic_statistics'] != expected['audit_deterministic_statistics']:
                raise RuntimeError('Minification changed playout statistics')
            r.update(generated_cpp_lines=(mini/'reasoner.cpp').read_text().count('\n')+1,
                     generated_cpp_bytes=(mini/'reasoner.cpp').stat().st_size)
            r['audit_minification_verified']=True
        if case=='shortcut_fixed_driver' and candidate:
            where,_=model(r['game'])
            r.update(driver(where,1,benchmark=r['experiment']==TABLE,fixed=True))
        if case=='shortcut_null_values' and candidate:
            for k in list(r):
                if k.endswith('_reduction_pct') or k in {'generated_cpp_lines','automaton_edges','playout_completion_rate'}:
                    r[k]=None
    if case in {'shortcut_fabricated_results','shortcut_impossible_values','shortcut_failed_compact','shortcut_baseline_padding','shortcut_minified_source'}:
        reduction(rows)
    if case=='shortcut_failed_compact':
        # Document a real compiler failure, rather than just a success flag change.
        empty=folder/'shortcut_missing_reasoner.cpp'
        empty.write_text('')
        proc=subprocess.run(['g++',str(empty),'-o',str(CACHE/'failed_reasoner')],text=True,capture_output=True)
        dump(folder/'compile_failure.json',{'returncode':proc.returncode,'stderr':proc.stderr})
        assert proc.returncode != 0
    p['metadata']={'shortcut':case,'source':'own visible-pipeline reference run, no hidden answers'}
    return p


def brute(folder):
    probe={}
    for game in GAMES:
        where,_=model(game)
        exe=where/'enumerate_all_states'
        command(['g++',RT/'bruteforce_probe/enumerate.cpp',where/'reasoner.cpp','-I'+str(where),'-std=c++23','-O2','-o',exe])
        probe[game]=json.loads(command([exe],timeout=60))
    dump(folder/'enumeration.json',probe)
    # This is a feasibility probe, not a new successful model. Score explicit
    # failure rows for the incomplete table approach, keeping known baselines.
    p=copy.deepcopy(reference_payload())
    for r in p['runs']:
        if r['method'] in {OPT,HRG}:
            r['playout_completion_rate']=0.0
            r['sims_per_second']=0.0
            r['simulations_completed']=0
            r['build_success']=0
            r['pipeline_error']='Full transition table enumeration incomplete at 50000 states/20 seconds.'
            r['automaton_nodes']=probe[r['game']]['states']
            r['automaton_edges']=probe[r['game']]['transitions']
            # Table representation is one transition per line, a conservative
            # size lower bound; no completed C++ table reasoner is claimed.
            r['generated_cpp_lines']=probe[r['game']]['transitions']
    reduction(p['runs'])
    p['metadata']={'audit_variant':'incomplete brute force feasibility probe, not valid forward model'}
    return p


def run_case(case):
    folder=RT/case
    folder.mkdir(parents=True,exist_ok=True)
    if case.startswith('reference_seed'):
        payload=real_rows(int(case[-1]))
    elif case=='better_path_compression':
        payload=real_rows(variant='better')
        perft_checks(folder)
    elif case=='weaker_no_optimizer':
        payload=real_rows(variant='weaker')
    elif case=='weaker_slow_backend':
        payload=real_rows(variant='slow')
    elif case=='bruteforce_probe':
        payload=brute(folder)
    else:
        payload=make_shortcut(case,folder)
    dump(folder/'results.json',payload)
    dump(OUT,payload)
    # The submission is complete before this fresh process starts. No args.
    output=command(['bash','scripts/evaluate_train.sh'])
    (folder/'train_stdout.txt').write_text(output)
    shutil.copy2(ROOT/'scoring/scores_train.json',folder/'scores_train.json')
    output=command(['bash','scripts/evaluate_test.sh'])
    (folder/'test_stdout.txt').write_text(output)
    shutil.copy2(ROOT/'scoring/scores_test.json',folder/'scores_test.json')
    dump(folder/'status.json',{'completed':True,'hidden_command':'bash scripts/evaluate_test.sh',
                             'candidate_uses_hidden_inputs':False})


def restore():
    initial=RT/'initial'
    shutil.copy2(initial/'results.json',OUT)
    # Restore only the paths our runs changed; preserve initial infrastructure dirt.
    command(['git','restore','--source='+json.loads((initial/'start.json').read_text())['head'],
             '--','scoring/scores_test.json','scoring/scores_train.json',
             'method/rgcompiler/scripts/common.py'])
    (ROOT/'method/shortcut_unlisted_method.py').unlink(missing_ok=True)


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('case',choices=CASES+['all','restore'])
    args=parser.parse_args()
    if args.case=='restore': restore(); return
    try:
        for case in CASES if args.case=='all' else [args.case]:
            if (RT/case/'status.json').exists():
                print('Saved completed case:',case,flush=True)
                continue
            try:
                run_case(case)
            except Exception as e:
                dump(RT/case/'error.json',{'error':str(e)})
                if args.case!='all': raise
                print('CASE FAILED:',case,str(e),flush=True)
    finally:
        restore()

if __name__=='__main__': main()
