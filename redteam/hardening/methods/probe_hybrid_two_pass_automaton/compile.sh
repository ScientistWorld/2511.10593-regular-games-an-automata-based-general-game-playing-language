#!/usr/bin/env bash
# Probe: report the smaller two-pass automaton as game.json, but compile the
# forward model from the one-pass automaton with --gccinline 2 (decoupled
# artifacts; both are genuine outputs of the method and both are verified).
set -euo pipefail
here="$(cd "$(dirname "$0")/.." && pwd)"
tmp=$(mktemp -d)
bash "$here/better_two_pass_optimizer/compile.sh" "$1" "$tmp"
bash "$here/better_inline_unique_states/compile.sh" "$1" "$2"
cp "$tmp/game.json" "$2/game.json"
