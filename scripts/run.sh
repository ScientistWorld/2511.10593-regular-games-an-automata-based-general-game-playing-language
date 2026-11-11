#!/usr/bin/env bash
set -euo pipefail

cd /home/user

# Regenerate method artifacts in the compute container. method/outputs is
# gitignored, so evaluating without this step can score stale local artifacts.
export GAMES="${GAMES:-connect4.hrg breakthrough.hrg hex.hrg yavalath.hrg ticTacToe.hrg ticTacDie.hrg reversi.hrg gomoku_standard.hrg knightthrough.hrg foxAndHounds.hrg amazons_split2.hrg pentago.hrg clobber.hrg bombardment.hrg}"
export BENCHMARK_GAMES="${BENCHMARK_GAMES:-connect4.hrg breakthrough.hrg yavalath.hrg reversi.hrg hex.hrg knightthrough.hrg}"
export BENCHMARK_SECONDS="${BENCHMARK_SECONDS:-10}"
export BENCHMARK_REPEATS="${BENCHMARK_REPEATS:-2}"
export SIMS="${SIMS:-200}"

bash scripts/method.sh
bash scripts/evaluate_train.sh /home/user/method/outputs/results.json
bash scripts/evaluate_test.sh /home/user/method/outputs/results.json
python3 validate.py --compare
