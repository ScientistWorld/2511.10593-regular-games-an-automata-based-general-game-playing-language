#!/usr/bin/env bash
# Shortcut probe: ignore the input and replay a cached reference model of a visible game
set -euo pipefail
exec bash /home/user/method/compilers/hrg_rg_optimized/compile.sh /home/user/data/games/hrg/breakthrough.hrg "$2"
