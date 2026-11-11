#!/usr/bin/env python3
"""Fresh-job verification of persisted submissions; no candidate executes here."""
import json
from pathlib import Path
import shutil
import subprocess

ROOT = Path('/home/user')
RT = ROOT / 'redteam'
OUT = ROOT / 'method/outputs/results.json'


def main():
    original = OUT.read_bytes()
    original_test = (ROOT/'scoring/scores_test.json').read_bytes()
    stub = ROOT/'method/shortcut_unlisted_method.py'
    cases = sorted(p.parent for p in RT.glob('*/status.json'))
    try:
        for folder in cases:
            if folder.name == 'shortcut_unlisted_method':
                stub.write_text('# Shortcut: omitted from submitted artifact.\nraise RuntimeError("never runs")\n')
            shutil.copyfile(folder/'results.json', OUT)
            result = subprocess.run(['bash', 'scripts/evaluate_test.sh'], cwd=ROOT,
                                    text=True, capture_output=True, check=True)
            (folder/'fresh_test_stdout.txt').write_text(result.stdout+result.stderr)
            actual = json.loads((ROOT/'scoring/scores_test.json').read_text())
            assert actual == json.loads((folder/'scores_test.json').read_text()), folder.name
            (folder/'fresh_scores_test.json').write_text(json.dumps(actual, indent=2, sort_keys=True)+'\n')
            (folder/'fresh_status.json').write_text(json.dumps({
                'completed': True, 'matches_construction_job': True,
                'command': 'bash scripts/evaluate_test.sh',
                'candidate_executed_in_this_job': False,
            }, indent=2)+'\n')
            stub.unlink(missing_ok=True)
            print('FRESH PASS', folder.name, flush=True)
    finally:
        OUT.write_bytes(original)
        (ROOT/'scoring/scores_test.json').write_bytes(original_test)
        stub.unlink(missing_ok=True)
    print('All', len(cases), 'saved submissions verified in fresh scoring job.', flush=True)


if __name__ == '__main__':
    main()
