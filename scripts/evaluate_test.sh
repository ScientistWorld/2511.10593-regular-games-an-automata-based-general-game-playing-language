#!/usr/bin/env bash
# Held-out evaluation. No arguments: every method directory on disk
# (method/compilers/<name>/compile.sh) is compiled on the hidden games, verified
# against ground truth and measured; results go to scoring/scores_test.json.
set -euo pipefail
cd "$(dirname "${BASH_SOURCE[0]}")/.."
python3 eval/test/evaluate.py --output scoring/scores_test.json
