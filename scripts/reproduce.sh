#!/usr/bin/env bash
# Reproduce the reference end to end: build the official RG toolchain, then
# score every method on disk on the train and held-out slices.
set -euo pipefail
cd "$(dirname "${BASH_SOURCE[0]}")/.."
for prep in method/compilers/*/prepare.sh; do
  [ -f "$prep" ] && bash "$prep"
done
bash scripts/evaluate_train.sh
bash scripts/evaluate_test.sh
python3 validate.py --post-design
