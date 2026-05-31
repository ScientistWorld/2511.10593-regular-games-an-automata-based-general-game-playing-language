#!/usr/bin/env python3
"""Evaluate RG reproduction artifacts without importing method code."""

from __future__ import annotations

import argparse
import json
from collections import defaultdict
from pathlib import Path
from statistics import mean
from typing import Any


def avg(rows: list[dict[str, Any]], key: str) -> float:
    values = [float(row[key]) for row in rows if key in row and row[key] is not None]
    return mean(values) if values else 0.0


def aggregate(rows: list[dict[str, Any]]) -> dict[str, float]:
    return {
        "automaton_node_reduction_pct": avg(rows, "automaton_nodes_reduction_pct"),
        "automaton_edge_reduction_pct": avg(rows, "automaton_edges_reduction_pct"),
        "generated_cpp_line_reduction_pct": avg(rows, "generated_cpp_lines_reduction_pct"),
        "playout_completion_rate": avg(rows, "playout_completion_rate"),
    }


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--input", default="method/outputs/results.json")
    parser.add_argument("--output", default="scoring/scores.json")
    args = parser.parse_args()

    payload = json.loads(Path(args.input).read_text())
    by_method: dict[str, list[dict[str, Any]]] = defaultdict(list)
    for row in payload.get("runs", []):
        if row.get("experiment") == "hrg_optimization_structure":
            by_method[row["method"]].append(row)

    scores = {
        "experiments": {
            "hrg_optimization_structure": {
                "results": {method: aggregate(rows) for method, rows in sorted(by_method.items())}
            }
        }
    }
    Path(args.output).write_text(json.dumps(scores, indent=2, sort_keys=True))
    print(json.dumps(scores, indent=2, sort_keys=True))


if __name__ == "__main__":
    main()
