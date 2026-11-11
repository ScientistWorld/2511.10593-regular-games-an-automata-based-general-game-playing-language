#!/usr/bin/env bash
# Reproduce the reference end to end in the compute container (no internet):
# build the official RG toolchain, then score every method on disk
# (method/compilers/*/compile.sh) on the train slice and the held-out slice,
# and validate the workspace.
set -euo pipefail
cd /home/user
for prep in method/compilers/*/prepare.sh; do
  [ -f "$prep" ] && bash "$prep"
done
bash scripts/evaluate_train.sh
bash scripts/evaluate_test.sh
python3 validate.py --post-design
