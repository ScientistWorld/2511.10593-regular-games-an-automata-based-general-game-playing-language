#!/usr/bin/env bash
set -euo pipefail

cd /home/user
SIMS=20 bash scripts/method.sh
python3 validate.py --compare
