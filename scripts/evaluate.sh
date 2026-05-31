#!/usr/bin/env bash
set -euo pipefail

cd /home/user
INPUT="${1:-method/outputs/results.json}"
mkdir -p scoring
python3 eval/evaluate_results.py --input "$INPUT" --output scoring/scores.json
