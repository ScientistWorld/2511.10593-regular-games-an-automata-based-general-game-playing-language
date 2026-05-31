#!/usr/bin/env bash
set -euo pipefail

cd /home/user
bash scripts/evaluate_train.sh /home/user/method/outputs/results.json
bash scripts/evaluate_test.sh /home/user/method/outputs/results.json
