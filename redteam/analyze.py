#!/usr/bin/env python3
"""Audit-only reporting. This is never imported by candidate construction."""
import json
from pathlib import Path
from statistics import mean, pstdev

RT = Path(__file__).resolve().parent
ROOT = RT.parent
SPEC = json.loads((ROOT/'scoring/reference.json').read_text())['experiments']
METHODS = {'hrg_optimization_structure': 'hrg_rg_optimized',
           'table1_playout_throughput_subset': 'hrg_rg_table1_subset'}
FIELDS = [(exp, metric, spec['weight']*abs(cfg['coefficient']),
           1 if cfg['higher_is_better'] else -1)
          for exp, spec in SPEC.items() for metric, cfg in spec['metrics'].items()
          if cfg['coefficient']]


def flatten(score):
    return {(exp, metric): score.get('experiments', {}).get(exp, {}).get('results', {})
            .get(METHODS[exp], {}).get(metric)
            for exp, metric, _, _ in FIELDS}


def rank(attempt, cohort, reference):
    total, terms = 0.0, {}
    for exp, metric, weight, direction in FIELDS:
        key = exp, metric
        value = attempt.get(key)
        observed = [row[key] for row in cohort if row.get(key) is not None]
        sigma = pstdev(observed) if observed else 0.0
        term = weight*direction*(value-reference[key])/sigma if value is not None and sigma else 0.0
        total += term
        terms[exp+':'+metric] = {'std': sigma, 'contribution': term}
    return {'rank_improvement': total, 'terms': terms}


def main():
    scores = {'original_reference': json.loads((RT/'initial/scores_test.json').read_text())}
    for path in sorted(RT.glob('*/status.json')):
        assert json.loads(path.read_text())['completed'], path
        folder = path.parent
        scores[folder.name] = json.loads((folder/'scores_test.json').read_text())
        fresh = folder/'fresh_scores_test.json'
        if fresh.exists():
            assert json.loads(fresh.read_text()) == scores[folder.name]
    flat = {name: flatten(score) for name, score in scores.items()}
    reference = flat['original_reference']
    honest = ['original_reference', 'reference_seed1', 'reference_seed2', 'reference_seed3',
              'better_path_compression', 'weaker_no_optimizer', 'shortcut_slow_backend']
    cohort = list(flat.values())
    output = {'normalization': 'population standard deviation per proposed experiment/metric; missing values skipped',
              'full_cohort': list(flat), 'honest_cohort': honest, 'cases': {}, 'seed_spread': {},
              'per_game_speedups': {}}
    for name, value in flat.items():
        output['cases'][name] = {
            'metric_values': {e+':'+m: v for (e,m), v in value.items()},
            'pairwise': rank(value, [reference, value], reference),
            'full_cohort': rank(value, cohort, reference),
        }
        if name in honest:
            output['cases'][name]['honest_cohort'] = rank(value, [flat[n] for n in honest], reference)
    for exp, metric, _, _ in FIELDS:
        vals = [flat['reference_seed'+str(seed)][exp, metric] for seed in [1,2,3]]
        output['seed_spread'][exp+':'+metric] = {'minimum': min(vals), 'maximum': max(vals),
                                               'range': max(vals)-min(vals)}
    for name in ['reference_seed1', 'reference_seed2', 'reference_seed3', 'shortcut_slow_backend']:
        rows = json.loads((RT/name/'results.json').read_text())['runs']
        rates = {}
        for row in rows:
            if row['experiment'] == 'table1_playout_throughput_subset':
                rates.setdefault(row['game'], []).append(row['sims_per_second'])
        rates = {game: mean(values) for game, values in rates.items()}
        output['per_game_speedups'][name] = {Path(game).stem: rate/rates[game[:-3]+'rbg']
                                            for game, rate in rates.items() if game.endswith('hrg')}
    (RT/'analysis.json').write_text(json.dumps(output, indent=2, sort_keys=True)+'\n')
    lines = ['| Case | Structure N / E / L / C | Matched L / E / C | Pairwise rank Δ | Full-cohort rank Δ |',
             '|---|---|---|---:|---:|']
    for name, row in output['cases'].items():
        vals = list(flat[name].values())
        fmt = lambda v: 'missing' if v is None else f'{v:.6f}'
        lines.append(f"| {name} | {' / '.join(map(fmt, vals[:4]))} | {' / '.join(map(fmt, vals[4:]))} | "
                     f"{row['pairwise']['rank_improvement']:+.6f} | {row['full_cohort']['rank_improvement']:+.6f} |")
    (RT/'score_table.md').write_text('\n'.join(lines)+'\n')
    print('\n'.join(lines))
    print('PER-GAME SPEEDUPS', json.dumps(output['per_game_speedups'], indent=2))


if __name__ == '__main__':
    main()
