#!/usr/bin/env bash
# Reference method: the paper's HRG -> RG translation, fixed-point automaton
# optimizer with inferred pragmas, and rg2cpp C++ forward-model generation.
# Usage: compile.sh <rules.hrg> <outdir>   (writes game.json, reasoner.hpp, reasoner.cpp)
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../../.." && pwd)"
bash "$ROOT/method/toolchain/build.sh"
exec python3 "$ROOT/method/toolchain/compile_game.py" "$1" "$2" \
  --translate="--enable-all-optimizations --enable-all-pragmas"
