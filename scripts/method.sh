#!/usr/bin/env bash
set -euo pipefail

cd /home/user
python3 method/run_experiments.py --games connect4.hrg breakthrough.hrg --sims "${SIMS:-200}"
bash scripts/evaluate.sh method/outputs/results.json
