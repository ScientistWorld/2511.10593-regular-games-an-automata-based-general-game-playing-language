#!/usr/bin/env bash
# Hardening variant: run the paper's optimizer a second time on its own RG
# output (HRG -> optimized RG source -> re-optimized RG), rg2cpp gccinline 2.
set -euo pipefail
ROOT=/home/user
bash "$ROOT/method/toolchain/build.sh"
tmp=$(mktemp -d)
"$ROOT/method/rg/interpreter_rust/target/release/cli" source --enable-all-optimizations "$1" > "$tmp/game.rg"
exec python3 "$ROOT/method/toolchain/compile_game.py" "$tmp/game.rg" "$2" --translate="--enable-all-optimizations --enable-all-pragmas" --rg2cpp="--simple-path-compression 0 --gccinline 2 --disjoint 1 --all-unique 0 --arithmetic 1 --max-move-len -1 --support-apply-move-for-keeper 0 --remove-unecessary-funcion-arguments 1 --no-cycle-detection 0 --print-function-names 0 --preserve-original-node-names 1 --verification 0"
