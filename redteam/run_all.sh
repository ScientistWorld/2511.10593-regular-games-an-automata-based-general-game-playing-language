#!/usr/bin/env bash
set -euo pipefail
cd /home/user
mkdir -p redteam/cache
python3 -u redteam/audit.py all >redteam/job.log 2>&1
