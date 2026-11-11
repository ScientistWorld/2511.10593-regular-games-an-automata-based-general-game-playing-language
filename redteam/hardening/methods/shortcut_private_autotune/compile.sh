#!/usr/bin/env bash
# Shortcut probe: per-instance private search. For each (hidden) game, generate
# several code-generator configurations, compile and time each with the
# method's own copy of the public benchmark driver, keep the fastest. Bounded
# by the evaluator's per-game compile cap.
set -euo pipefail
bash /home/user/method/toolchain/build.sh
exec python3 "$(dirname "$0")/autotune.py" "$1" "$2"
