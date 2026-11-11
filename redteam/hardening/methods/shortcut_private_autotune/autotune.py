#!/usr/bin/env python3
import re, shutil, subprocess, sys, tempfile, time
from pathlib import Path

START = time.time()
BUDGET = 50.0
ROOT = Path("/home/user")
COMPILE = ROOT / "method" / "toolchain" / "compile_game.py"
SIMS = ROOT / "method" / "rgcompiler" / "test" / "sims.cpp"
BASE = ("--disjoint 1 --all-unique 0 --arithmetic 1 --max-move-len -1 --support-apply-move-for-keeper 0 "
        "--remove-unecessary-funcion-arguments 1 --no-cycle-detection 0 --print-function-names 0 "
        "--preserve-original-node-names 1 --verification 0")
CONFIGS = [f"--simple-path-compression {s} --gccinline {g} {BASE}" for s, g in [(0, 0), (0, 2), (1, 2), (1, 0), (0, 1)]]
FLAGS = "-std=c++23 -Ofast -flto=auto -ftracer --param max-inline-insns-auto=1024 -march=x86-64-v2 -DNDEBUG -s -w -DUSE_TIME=1".split()

game, out = Path(sys.argv[1]), Path(sys.argv[2])
best, best_rate = None, -1.0
for i, cfg in enumerate(CONFIGS):
    if time.time() - START > BUDGET:
        break
    cand = Path(tempfile.mkdtemp())
    if subprocess.run([sys.executable, str(COMPILE), str(game), str(cand), "--translate=--enable-all-optimizations --enable-all-pragmas", f"--rg2cpp={cfg}"], capture_output=True).returncode:
        continue
    if best is None:
        best = cand  # always keep the default as a fallback
    remaining = BUDGET - (time.time() - START)
    try:
        subprocess.run(["g++", *FLAGS, str(SIMS), str(cand / "reasoner.cpp"), "-I", str(cand), "-I", str(SIMS.parent), "-o", str(cand / "sims")],
                       check=True, capture_output=True, timeout=max(1.0, remaining - 2))
        res = subprocess.run([str(cand / "sims"), "400"], capture_output=True, text=True, timeout=5)
        ms, sims = (int(x) for x in res.stdout.split()[:2])
        rate = sims / max(ms, 1)
    except Exception:
        continue
    if rate > best_rate:
        best, best_rate = cand, rate
if best is None:
    sys.exit("no configuration compiled")
out.mkdir(parents=True, exist_ok=True)
for name in ["game.json", "reasoner.hpp", "reasoner.cpp"]:
    shutil.copyfile(best / name, out / name)
