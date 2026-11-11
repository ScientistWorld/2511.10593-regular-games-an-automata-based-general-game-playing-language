#!/usr/bin/env bash
# Better variant (code generation for translated rules): the reference
# pipeline; when the input is an automatically translated description (.rbg),
# whose automaton is a long chain of small state functions from the
# regular-expression construction, force full inlining
# (__attribute__((flatten))) of the generated entry points getAllMoves /
# applyMove / applyAnyMove. Skipped for very large models (> 4000 lines) to
# bound compile memory. HRG inputs are compiled exactly like the reference.
set -euo pipefail
bash /home/user/method/compilers/hrg_rg_optimized/compile.sh "$1" "$2"
case "$1" in
  *.rbg) ;;
  *) exit 0 ;;
esac
python3 - "$2/reasoner.cpp" <<'PY'
import re, sys, pathlib
p = pathlib.Path(sys.argv[1])
src = p.read_text()
if src.count("\n") <= 4000:
    src = re.sub(r"^void GameState::(getAllMoves|applyMove|applyAnyMove)\(",
                 r"__attribute__((flatten)) void GameState::\1(", src, flags=re.M)
    p.write_text(src)
PY
