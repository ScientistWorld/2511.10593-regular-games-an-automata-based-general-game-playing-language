#!/usr/bin/env bash
# Hardening variant: no automaton transformations (pragmas only)
set -euo pipefail
ROOT=/home/user
bash "$ROOT/method/toolchain/build.sh"
exec python3 "$ROOT/method/toolchain/compile_game.py" "$1" "$2" --translate="--enable-all-pragmas" --rg2cpp="--simple-path-compression 0 --gccinline 0 --disjoint 1 --all-unique 0 --arithmetic 1 --max-move-len -1 --support-apply-move-for-keeper 0 --remove-unecessary-funcion-arguments 1 --no-cycle-detection 0 --print-function-names 0 --preserve-original-node-names 1 --verification 0"
