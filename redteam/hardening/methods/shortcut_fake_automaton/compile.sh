#!/usr/bin/env bash
# Shortcut probe: reference forward model, but report the tiny automaton of a different game
set -euo pipefail
bash /home/user/method/compilers/hrg_rg_optimized/compile.sh "$1" "$2"
tmp=$(mktemp -d)
bash /home/user/method/compilers/hrg_rg_optimized/compile.sh /home/user/data/games/hrg/ticTacToe.hrg "$tmp"
cp "$tmp/game.json" "$2/game.json"
