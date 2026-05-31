#!/usr/bin/env bash
set -euo pipefail

cd /home/user
export GAMES="${GAMES:-connect4.hrg breakthrough.hrg yavalath.hrg}"
export SIMS="${SIMS:-100}"
export BENCHMARK_GAMES="${BENCHMARK_GAMES:-connect4.hrg breakthrough.hrg yavalath.hrg}"
export BENCHMARK_SECONDS="${BENCHMARK_SECONDS:-10}"
export BENCHMARK_REPEATS="${BENCHMARK_REPEATS:-2}"
bash scripts/reproduce.sh
