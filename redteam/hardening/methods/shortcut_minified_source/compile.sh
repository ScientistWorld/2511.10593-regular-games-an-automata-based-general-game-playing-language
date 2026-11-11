#!/usr/bin/env bash
# Shortcut probe: reference output with comments, blank lines and indentation removed
set -euo pipefail
bash /home/user/method/compilers/hrg_rg_optimized/compile.sh "$1" "$2"
python3 - "$2" <<'PY'
import re, sys, pathlib
for name in ["reasoner.hpp", "reasoner.cpp"]:
    p = pathlib.Path(sys.argv[1]) / name
    out = []
    for line in p.read_text().splitlines():
        line = re.sub(r"^\s*//.*$", "", line).strip()
        if line:
            out.append(line)
    p.write_text("\n".join(out) + "\n")
PY
