#!/usr/bin/env bash
set -euo pipefail

cd /home/user
read -r -a GAME_ARGS <<< "${GAMES:-connect4.hrg breakthrough.hrg hex.hrg yavalath.hrg ticTacToe.hrg ticTacDie.hrg}"
python3 method/run_experiments.py --games "${GAME_ARGS[@]}" --sims "${SIMS:-200}"
bash scripts/evaluate.sh method/outputs/results.json
