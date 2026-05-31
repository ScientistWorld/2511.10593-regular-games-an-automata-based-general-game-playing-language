#!/usr/bin/env python3
"""Run the official RG-to-C++ forward-model pipeline on selected games."""

from __future__ import annotations

import argparse
import json
import os
import re
import subprocess
from datetime import datetime, timezone
from pathlib import Path
from typing import Any


ROOT = Path(__file__).resolve().parents[1]
RG_ROOT = ROOT / "method" / "rg"
COMPILER_ROOT = ROOT / "method" / "rgcompiler"
OUT_DIR = ROOT / "method" / "outputs"

VARIANTS = {
    "hrg_rg_no_optimizations": "--enable-all-pragmas",
    "hrg_rg_optimized": "--enable-all-optimizations --enable-all-pragmas",
}


def run(cmd: list[str], cwd: Path, *, env: dict[str, str] | None = None) -> subprocess.CompletedProcess[str]:
    merged_env = os.environ.copy()
    merged_env.setdefault("CARGO_NET_OFFLINE", "true")
    if env:
        merged_env.update(env)
    return subprocess.run(
        cmd,
        cwd=cwd,
        env=merged_env,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        check=True,
    )


def game_path(game: str) -> Path:
    path = Path(game)
    if path.is_absolute():
        return path
    if len(path.parts) == 1:
        return RG_ROOT / "games" / "hrg" / game
    return RG_ROOT / "games" / path


def ast_stats(ast_file: Path) -> dict[str, int]:
    data = json.loads(ast_file.read_text())
    edges = data.get("edges", [])
    nodes: set[str] = set()
    label_kinds: dict[str, int] = {}
    for edge in edges:
        lhs = edge.get("lhs")
        rhs = edge.get("rhs")
        if lhs is not None:
            nodes.add(json.dumps(lhs, sort_keys=True))
        if rhs is not None:
            nodes.add(json.dumps(rhs, sort_keys=True))
        label = edge.get("label", {})
        kind = label.get("kind", "unknown") if isinstance(label, dict) else "unknown"
        label_kinds[f"label_{kind.lower()}_count"] = label_kinds.get(f"label_{kind.lower()}_count", 0) + 1
    return {
        "automaton_nodes": len(nodes),
        "automaton_edges": len(edges),
        "variables": len(data.get("variables", [])),
        "constants": len(data.get("constants", [])),
        "typedefs": len(data.get("types", [])),
        "pragmas": len(data.get("pragmas", [])),
        **label_kinds,
    }


def file_metrics(base: Path) -> dict[str, int]:
    metrics: dict[str, int] = {}
    for suffix, name in [(".cpp", "generated_cpp"), (".hpp", "generated_header")]:
        path = base.with_suffix(suffix)
        if path.exists():
            text = path.read_text(errors="replace")
            metrics[f"{name}_bytes"] = path.stat().st_size
            metrics[f"{name}_lines"] = text.count("\n") + int(bool(text))
    return metrics


def parse_sims_output(output: str, requested: int) -> dict[str, Any]:
    metrics: dict[str, Any] = {
        "simulations_requested": requested,
        "simulations_completed": 0,
        "states_visited": 0,
        "playout_completion_rate": 0.0,
    }
    match = re.search(r"\|\s*sims\s+([0-9.]+)s\s+(\d+)\s+(\d+)", output)
    if match:
        completed = int(match.group(2))
        metrics["raw_sims_elapsed_seconds"] = float(match.group(1))
        metrics["simulations_completed"] = completed
        metrics["states_visited"] = int(match.group(3))
        metrics["playout_completion_rate"] = completed / max(requested, 1)
    extra = re.search(
        r"score\s+(-?\d+)\s+(-?\d+)\s+([0-9.]+),\s*depth\s+(\d+)\s+(\d+)\s+([0-9.]+),\s*moves\s+(\d+)\s+(\d+)\s+([0-9.]+)",
        output,
    )
    if extra:
        metrics.update(
            {
                "min_score": int(extra.group(1)),
                "max_score": int(extra.group(2)),
                "avg_score": float(extra.group(3)),
                "min_depth": int(extra.group(4)),
                "max_depth": int(extra.group(5)),
                "avg_depth": float(extra.group(6)),
                "min_legal_moves": int(extra.group(7)),
                "max_legal_moves": int(extra.group(8)),
                "avg_legal_moves": float(extra.group(9)),
            }
        )
    return metrics


def clean_build_test() -> None:
    build_test = COMPILER_ROOT / "build-test"
    build_test.mkdir(exist_ok=True)
    for pattern in ["*.json", "reasoner.cpp", "reasoner.hpp", "sims", "perft"]:
        for path in build_test.glob(pattern):
            if path.is_file():
                path.unlink()


def run_variant(game: str, variant: str, transform_flags: str, sims: int) -> dict[str, Any]:
    clean_build_test()
    game_file = game_path(game)
    rel_game = os.path.relpath(game_file, COMPILER_ROOT)
    command = ["python3", "scripts/sims.py", rel_game, str(sims), "--test", "-t", transform_flags]
    proc = run(command, cwd=COMPILER_ROOT)
    ast_file = COMPILER_ROOT / "build-test" / f"{game_file.stem}.json"
    result: dict[str, Any] = {
        "experiment": "hrg_optimization_structure",
        "method": variant,
        "game": game_file.name,
        "source_path": str(game_file.relative_to(ROOT)),
        "transform_flags": transform_flags,
        "build_success": 1,
        "raw_log": proc.stdout,
    }
    result.update(parse_sims_output(proc.stdout, sims))
    if ast_file.exists():
        result.update(ast_stats(ast_file))
    result.update(file_metrics(COMPILER_ROOT / "build-test" / "reasoner"))
    return result


def compute_reductions(runs: list[dict[str, Any]]) -> None:
    by_game: dict[str, dict[str, dict[str, Any]]] = {}
    for run_data in runs:
        by_game.setdefault(run_data["game"], {})[run_data["method"]] = run_data
    for game_runs in by_game.values():
        base = game_runs.get("hrg_rg_no_optimizations")
        opt = game_runs.get("hrg_rg_optimized")
        if not base or not opt:
            continue
        for key in ["automaton_nodes", "automaton_edges", "generated_cpp_lines", "generated_cpp_bytes"]:
            base[f"{key}_reduction_pct"] = 0.0
            if base.get(key, 0):
                opt[f"{key}_reduction_pct"] = 100.0 * (base[key] - opt.get(key, base[key])) / base[key]


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--games", nargs="+", default=["connect4.hrg", "breakthrough.hrg"])
    parser.add_argument("--sims", type=int, default=200)
    parser.add_argument("--output", default=str(OUT_DIR / "results.json"))
    args = parser.parse_args()

    OUT_DIR.mkdir(parents=True, exist_ok=True)
    run(["python3", "scripts/rebuild.py"], cwd=COMPILER_ROOT)

    runs: list[dict[str, Any]] = []
    for game in args.games:
        for variant, flags in VARIANTS.items():
            runs.append(run_variant(game, variant, flags, args.sims))
    compute_reductions(runs)

    payload = {
        "metadata": {
            "created_utc": datetime.now(timezone.utc).isoformat(),
            "paper": "Regular Games - an Automata-Based General Game Playing Language",
            "sims_per_variant": args.sims,
            "notes": "Official RG interpreter, HRG optimizer, rg2cpp compiler, and C++ reasoner pipeline.",
        },
        "runs": runs,
    }
    Path(args.output).write_text(json.dumps(payload, indent=2, sort_keys=True))
    print(f"Wrote {args.output}")


if __name__ == "__main__":
    main()
