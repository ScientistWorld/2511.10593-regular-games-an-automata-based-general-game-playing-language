#!/usr/bin/env bash
# Visible train-slice evaluation over every method directory on disk
# (method/compilers/<name>/compile.sh); writes scoring/scores_train.json.
# Optional extra arguments are passed through (e.g. --details path.json).
set -euo pipefail
cd "$(dirname "${BASH_SOURCE[0]}")/.."
python3 eval/train/evaluate.py --output scoring/scores_train.json "$@"
