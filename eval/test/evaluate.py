#!/usr/bin/env python3
"""Held-out test-slice evaluator for RG reproduction artifacts."""

from __future__ import annotations

import argparse
import json
from collections import defaultdict
from pathlib import Path
from statistics import mean
from typing import Any


STRUCTURE_TEST_GAMES = {"connect4.hrg"}


def avg(rows: list[dict[str, Any]], key: str) -> float:
    values = [float(row[key]) for row in rows if key in row and row[key] is not None]
    return mean(values) if values else 0.0


def train_methods(train_scores: dict[str, Any], experiment: str) -> set[str]:
    exp = train_scores.get("experiments", {}).get(experiment, {})
    results = exp.get("results", {}) if isinstance(exp, dict) else {}
    return {method for method in results if not method.startswith("_")}


def aggregate_structure(rows: list[dict[str, Any]], methods: set[str] | None = None) -> dict[str, dict[str, float]]:
    by_method: dict[str, list[dict[str, Any]]] = defaultdict(list)
    for row in rows:
        by_method[row["method"]].append(row)
    method_names = sorted(methods if methods is not None else by_method)
    return {
        method: {
            "automaton_node_reduction_pct": avg(by_method.get(method, []), "automaton_nodes_reduction_pct"),
            "automaton_edge_reduction_pct": avg(by_method.get(method, []), "automaton_edges_reduction_pct"),
            "generated_cpp_line_reduction_pct": avg(by_method.get(method, []), "generated_cpp_lines_reduction_pct"),
            "playout_completion_rate": avg(by_method.get(method, []), "playout_completion_rate"),
        }
        for method in method_names
    }


def table1_stem(game: str) -> str:
    return Path(game).stem


def aggregate_table1(rows: list[dict[str, Any]], methods: set[str] | None = None) -> dict[str, dict[str, float]]:
    by_method_game: dict[str, dict[str, list[dict[str, Any]]]] = defaultdict(lambda: defaultdict(list))
    for row in rows:
        by_method_game[row["method"]][row["game"]].append(row)

    method_names = sorted(methods if methods is not None else by_method_game)
    mean_sims_by_method_game: dict[str, dict[str, float]] = {}
    per_method: dict[str, dict[str, float]] = {}
    for method in method_names:
        by_game = by_method_game.get(method, {})
        mean_sims_by_method_game[method] = {
            game: avg(game_rows, "sims_per_second") for game, game_rows in by_game.items()
        }
        flat_rows = [row for game_rows in by_game.values() for row in game_rows]
        game_rates = list(mean_sims_by_method_game[method].values())
        per_method[method] = {
            "sims_per_second": mean(game_rates) if game_rates else 0.0,
            "states_per_second": avg(flat_rows, "states_per_second"),
            "benchmark_completion_rate": avg(flat_rows, "playout_completion_rate"),
            "games_completed": float(sum(1 for value in game_rates if value > 0)),
            "speedup_vs_rbg_rg": 0.0,
        }

    rbg_methods = [
        method
        for method, rates in mean_sims_by_method_game.items()
        if any(game.endswith(".rbg") for game in rates)
    ]
    baseline_method = "rbg_rg_table1_subset" if "rbg_rg_table1_subset" in rbg_methods else (rbg_methods[0] if rbg_methods else "")
    baseline_by_stem = {
        table1_stem(game): rate
        for game, rate in mean_sims_by_method_game.get(baseline_method, {}).items()
        if game.endswith(".rbg")
    }

    for method in method_names:
        rates = mean_sims_by_method_game.get(method, {})
        if any(game.endswith(".rbg") for game in rates):
            per_method[method]["speedup_vs_rbg_rg"] = 1.0 if per_method[method]["games_completed"] > 0 else 0.0
            continue
        speedups = [
            rate / baseline_by_stem[table1_stem(game)]
            for game, rate in rates.items()
            if game.endswith(".hrg") and rate > 0 and baseline_by_stem.get(table1_stem(game), 0.0) > 0
        ]
        per_method[method]["speedup_vs_rbg_rg"] = mean(speedups) if speedups else 0.0
    return per_method


def select_structure_rows(runs: list[dict[str, Any]]) -> list[dict[str, Any]]:
    return [
        row
        for row in runs
        if row.get("experiment") == "hrg_optimization_structure"
        and row.get("game") in STRUCTURE_TEST_GAMES
    ]


def select_table1_rows(runs: list[dict[str, Any]]) -> list[dict[str, Any]]:
    table_rows = [row for row in runs if row.get("experiment") == "table1_playout_throughput_subset"]
    if any(int(row.get("repeat", 1)) % 2 == 0 for row in table_rows):
        return [row for row in table_rows if int(row.get("repeat", 1)) % 2 == 0]
    return [row for row in table_rows if table1_stem(str(row.get("game", ""))) == "connect4"]


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--input", default="method/outputs/results.json")
    parser.add_argument("--output", default="scoring/scores_test.json")
    parser.add_argument("--train-scores", default="scoring/scores_train.json")
    args = parser.parse_args()

    train_scores_path = Path(args.train_scores)
    if not train_scores_path.exists():
        raise FileNotFoundError(
            f"{args.train_scores} is required so the held-out test scores the same method entries as train"
        )

    payload = json.loads(Path(args.input).read_text())
    train_scores_payload = json.loads(train_scores_path.read_text())
    runs = payload.get("runs", [])
    scores = {"experiments": {}}

    structure_methods = train_methods(train_scores_payload, "hrg_optimization_structure")
    if structure_methods:
        scores["experiments"]["hrg_optimization_structure"] = {
            "results": aggregate_structure(select_structure_rows(runs), structure_methods)
        }

    table1_methods = train_methods(train_scores_payload, "table1_playout_throughput_subset")
    if table1_methods:
        scores["experiments"]["table1_playout_throughput_subset"] = {
            "results": aggregate_table1(select_table1_rows(runs), table1_methods)
        }

    Path(args.output).write_text(json.dumps(scores, indent=2, sort_keys=True))
    print(json.dumps(scores, indent=2, sort_keys=True))


if __name__ == "__main__":
    main()
