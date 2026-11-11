#!/usr/bin/env bash
# One-time, input-independent setup: build the official RG toolchain.
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../../.." && pwd)"
bash "$ROOT/method/toolchain/build.sh"
