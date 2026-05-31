#!/usr/bin/env bash
set -euo pipefail

cd /home/user
INPUT="${1:-method/outputs/results.json}"
mkdir -p scoring
python3 eval/train/evaluate.py --input "$INPUT" --output scoring/scores_train.json
