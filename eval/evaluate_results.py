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


def aggregate_table1_subset(rows: list[dict[str, Any]]) -> dict[str, dict[str, float]]:
    by_method_game: dict[str, dict[str, list[dict[str, Any]]]] = defaultdict(lambda: defaultdict(list))
    for row in rows:
        by_method_game[row["method"]][row["game"]].append(row)

    per_method: dict[str, dict[str, float]] = {}
    mean_sims_by_method_game: dict[str, dict[str, float]] = {}
    for method, by_game in by_method_game.items():
        mean_sims_by_method_game[method] = {
            game: avg(game_rows, "sims_per_second") for game, game_rows in by_game.items()
        }
        game_rates = list(mean_sims_by_method_game[method].values())
        per_method[method] = {
            "sims_per_second": mean(game_rates) if game_rates else 0.0,
            "states_per_second": avg([row for game_rows in by_game.values() for row in game_rows], "states_per_second"),
            "benchmark_completion_rate": avg([row for game_rows in by_game.values() for row in game_rows], "playout_completion_rate"),
            "games_completed": float(sum(1 for value in game_rates if value > 0)),
        }

    hrg_rates = mean_sims_by_method_game.get("hrg_rg_table1_subset", {})
    rbg_rates = mean_sims_by_method_game.get("rbg_rg_table1_subset", {})
    speedups: list[float] = []
    for hrg_game, hrg_rate in hrg_rates.items():
        rbg_game = hrg_game.replace(".hrg", ".rbg")
        rbg_rate = rbg_rates.get(rbg_game)
        if hrg_rate > 0 and rbg_rate and rbg_rate > 0:
            speedups.append(hrg_rate / rbg_rate)

    if "hrg_rg_table1_subset" in per_method:
        per_method["hrg_rg_table1_subset"]["speedup_vs_rbg_rg"] = mean(speedups) if speedups else 0.0
    if "rbg_rg_table1_subset" in per_method:
        per_method["rbg_rg_table1_subset"]["speedup_vs_rbg_rg"] = 1.0
    return per_method


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
    table1_rows = [
        row for row in payload.get("runs", []) if row.get("experiment") == "table1_playout_throughput_subset"
    ]
    if table1_rows:
        scores["experiments"]["table1_playout_throughput_subset"] = {
            "results": aggregate_table1_subset(table1_rows)
        }
    Path(args.output).write_text(json.dumps(scores, indent=2, sort_keys=True))
    print(json.dumps(scores, indent=2, sort_keys=True))


if __name__ == "__main__":
    main()
