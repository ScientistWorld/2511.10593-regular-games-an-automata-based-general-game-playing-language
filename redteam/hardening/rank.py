#!/usr/bin/env python3
"""Rank change vs the reference, as the gym ranks: sum over scored metrics of
experiment weight x |coefficient| x (value - reference value) / population
standard deviation of that metric across the cohort (better direction)."""
import json, statistics, sys
from pathlib import Path

ref = json.loads(Path(__file__).resolve().parents[2].joinpath("scoring/reference.json").read_text())
scores = json.loads(Path(sys.argv[1]).read_text())
reference = sys.argv[2] if len(sys.argv) > 2 else "reference_hrg_rg_optimized"
skip = {"direct_translation_baseline", "rbg_translation_baseline", "direct_rbg_translation_baseline"}
methods = [m for m in scores["experiments"]["forward_model_efficiency"]["results"] if m not in skip]
rank = {m: 0.0 for m in methods}
for exp, spec in ref["experiments"].items():
    res = scores["experiments"][exp]["results"]
    for metric, mdef in spec["metrics"].items():
        coef = abs(mdef["coefficient"])
        if not coef:
            continue
        vals = [res[m][metric] for m in methods]
        sd = statistics.pstdev(vals) or 1.0
        sign = 1 if mdef["higher_is_better"] else -1
        for m in methods:
            rank[m] += spec["weight"] * coef * sign * (res[m][metric] - res[reference][metric]) / sd
for m in sorted(rank, key=rank.get, reverse=True):
    print(f"{m:36s} {rank[m]:+.4f}")
