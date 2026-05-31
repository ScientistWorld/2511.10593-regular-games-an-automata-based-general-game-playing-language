#!/usr/bin/env bash
set -euo pipefail

cd /home/user
read -r -a GAME_ARGS <<< "${GAMES:-connect4.hrg breakthrough.hrg hex.hrg yavalath.hrg ticTacToe.hrg ticTacDie.hrg reversi.hrg gomoku_standard.hrg knightthrough.hrg foxAndHounds.hrg amazons_split2.hrg pentago.hrg clobber.hrg bombardment.hrg}"
read -r -a BENCHMARK_GAME_ARGS <<< "${BENCHMARK_GAMES:-connect4.hrg breakthrough.hrg yavalath.hrg}"
BENCHMARK_SECONDS="${BENCHMARK_SECONDS:-10}"
BENCHMARK_REPEATS="${BENCHMARK_REPEATS:-3}"
python3 method/run_experiments.py \
  --games "${GAME_ARGS[@]}" \
  --sims "${SIMS:-200}" \
  --benchmark-games "${BENCHMARK_GAME_ARGS[@]}" \
  --benchmark-seconds "$BENCHMARK_SECONDS" \
  --benchmark-repeats "$BENCHMARK_REPEATS"
bash scripts/evaluate.sh method/outputs/results.json
