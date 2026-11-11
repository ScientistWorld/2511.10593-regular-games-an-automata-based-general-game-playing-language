#!/usr/bin/env bash
set -euo pipefail
cd /home/user
python3 -u redteam/rescore_saved.py
python3 redteam/analyze.py
