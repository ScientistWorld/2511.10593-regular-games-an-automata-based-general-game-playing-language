#!/usr/bin/env bash
# Probe (code generation, all inputs): the reference pipeline, then force full
# inlining (__attribute__((flatten))) of the generated forward-model entry
# points getAllMoves / applyMove / applyAnyMove, so the automaton walk compiles
# into one straight-line function per entry point. Forced inlining is skipped
# for very large generated models (> 4000 lines) to bound compile memory.
set -euo pipefail
bash /home/user/method/compilers/hrg_rg_optimized/compile.sh "$1" "$2"
python3 - "$2/reasoner.cpp" <<'PY'
import re, sys, pathlib
p = pathlib.Path(sys.argv[1])
src = p.read_text()
if src.count("\n") <= 4000:
    src = re.sub(r"^void GameState::(getAllMoves|applyMove|applyAnyMove)\(",
                 r"__attribute__((flatten)) void GameState::\1(", src, flags=re.M)
    p.write_text(src)
PY
