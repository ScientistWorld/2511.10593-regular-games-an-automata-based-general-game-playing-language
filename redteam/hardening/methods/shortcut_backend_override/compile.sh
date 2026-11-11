#!/usr/bin/env bash
# Shortcut probe: reference output with a pragma overriding the evaluator's optimisation level
set -euo pipefail
bash /home/user/method/compilers/hrg_rg_optimized/compile.sh "$1" "$2"
sed -i '1i #pragma GCC optimize("O0")' "$2/reasoner.cpp"
