#!/usr/bin/env bash
set -euo pipefail

cd /home/user
bash scripts/method.sh
python3 validate.py --compare
