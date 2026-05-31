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

TABLE1_RBG_PAIRS = {
    "breakthrough.hrg": "breakthrough.rbg",
    "connect4.hrg": "connect4.rbg",
    "yavalath.hrg": "yavalath.rbg",
    "reversi.hrg": "reversi.rbg",
    "hex.hrg": "hex.rbg",
    "knightthrough.hrg": "knightthrough.rbg",
}


def run(cmd: list[str], cwd: Path, *, env: dict[str, str] | None = None) -> subprocess.CompletedProcess[str]:
    merged_env = os.environ.copy()
    merged_env.setdefault("CARGO_NET_OFFLINE", "true")
    if env:
        merged_env.update(env)
    rendered = " ".join(cmd)
    print(f"[run] {cwd.relative_to(ROOT) if cwd.is_relative_to(ROOT) else cwd}: {rendered}", flush=True)
    process = subprocess.Popen(
        cmd,
        cwd=cwd,
        env=merged_env,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
    )
    output_parts: list[str] = []
    assert process.stdout is not None
    for line in process.stdout:
        output_parts.append(line)
        print(line, end="", flush=True)
    returncode = process.wait()
    output = "".join(output_parts)
    if returncode != 0:
        raise RuntimeError(f"Command failed with exit code {returncode}: {rendered}\n{output}")
    return subprocess.CompletedProcess(cmd, returncode, output, "")


def game_path(game: str) -> Path:
    path = Path(game)
    if path.is_absolute():
        return path
    if len(path.parts) == 1:
        suffix = path.suffix.lstrip(".")
        if suffix in {"hrg", "rbg", "kif", "rg"}:
            return RG_ROOT / "games" / suffix / game
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
        "pipeline_error": "",
    }
    elapsed = re.search(r"\|\s*sims\s+([0-9.]+)s", output)
    if elapsed:
        metrics["raw_sims_elapsed_seconds"] = float(elapsed.group(1))
    throughput = re.search(
        r"\|\s*sims\s+([0-9.]+)s\s+([0-9 .]+?)\s+states/s\s+([0-9 .]+?)\s+sims/s",
        output,
    )
    if throughput:
        elapsed_seconds = float(throughput.group(1))
        states_per_second = float(throughput.group(2).replace(" ", ""))
        sims_per_second = float(throughput.group(3).replace(" ", ""))
        metrics.update(
            {
                "raw_sims_elapsed_seconds": elapsed_seconds,
                "states_per_second": states_per_second,
                "sims_per_second": sims_per_second,
                "simulations_completed": int(round(sims_per_second * max(elapsed_seconds, 0.001))),
                "states_visited": int(round(states_per_second * max(elapsed_seconds, 0.001))),
                "playout_completion_rate": 1.0 if sims_per_second > 0 else 0.0,
            }
        )
    fixed_work = re.search(r"sims:\s+(\d+)\s+states:\s+(\d+)", output)
    if fixed_work:
        completed = int(fixed_work.group(1))
        metrics["simulations_completed"] = completed
        metrics["states_visited"] = int(fixed_work.group(2))
        metrics["playout_completion_rate"] = completed / max(requested, 1)
    depth = re.search(r"depth:\s+min\s+(\d+)\s+avg\s+([0-9.]+)\s+max\s+(\d+)", output)
    moves = re.search(r"moves:\s+min\s+(\d+)\s+avg\s+([0-9.]+)\s+max\s+(\d+)", output)
    scores = re.search(r"avg scores:\s+([0-9. \-]+)\s+min scores:\s+([0-9 \-]+)\s+max scores:\s+([0-9 \-]+)", output)
    if depth:
        metrics.update(
            {
                "min_depth": int(depth.group(1)),
                "avg_depth": float(depth.group(2)),
                "max_depth": int(depth.group(3)),
            }
        )
    if moves:
        metrics.update(
            {
                "min_legal_moves": int(moves.group(1)),
                "avg_legal_moves": float(moves.group(2)),
                "max_legal_moves": int(moves.group(3)),
            }
        )
    if scores:
        avg_scores = [float(value) for value in scores.group(1).split()]
        min_scores = [int(value) for value in scores.group(2).split()]
        max_scores = [int(value) for value in scores.group(3).split()]
        if avg_scores:
            metrics["avg_score_mean"] = sum(avg_scores) / len(avg_scores)
            metrics["min_score_min"] = min(min_scores)
            metrics["max_score_max"] = max(max_scores)
    error_match = re.search(r"ERROR(?:\x1b\[[0-9;]*m)?\s+(.*)", output)
    if error_match:
        metrics["pipeline_error"] = re.sub(r"\x1b\[[0-9;]*m", "", error_match.group(1)).strip()
    return metrics


def clean_build_test() -> None:
    build_test = COMPILER_ROOT / "build-test"
    build_test.mkdir(exist_ok=True)
    for pattern in ["*.json", "reasoner.cpp", "reasoner.hpp", "sims", "perft"]:
        for path in build_test.glob(pattern):
            if path.is_file():
                path.unlink()


def run_variant(
    game: str,
    variant: str,
    transform_flags: str,
    sims: int,
    *,
    experiment: str = "hrg_optimization_structure",
    compile_mode: str = "test",
    repeat: int = 1,
) -> dict[str, Any]:
    clean_build_test()
    game_file = game_path(game)
    print(f"[variant] game={game_file.name} method={variant} mode={compile_mode} limit={sims}", flush=True)
    command = ["python3", "scripts/sims.py", game_file.name, str(sims), f"--{compile_mode}", f"-t={transform_flags}"]
    proc = run(command, cwd=COMPILER_ROOT)
    ast_file = COMPILER_ROOT / "build-test" / f"{game_file.name}.json"
    result: dict[str, Any] = {
        "experiment": experiment,
        "method": variant,
        "game": game_file.name,
        "repeat": repeat,
        "source_path": str(game_file.relative_to(ROOT)),
        "transform_flags": transform_flags,
        "compile_mode": compile_mode,
        "build_success": 1,
        "raw_log": proc.stdout,
    }
    result.update(parse_sims_output(proc.stdout, sims))
    result["build_success"] = int(result.get("simulations_completed", 0) > 0 and not result.get("pipeline_error"))
    if ast_file.exists():
        result.update(ast_stats(ast_file))
    result.update(file_metrics(COMPILER_ROOT / "build-test" / "reasoner"))
    return result


def run_table1_subset(games: list[str], seconds: float, repeats: int) -> list[dict[str, Any]]:
    runs: list[dict[str, Any]] = []
    limit = f"{seconds:g}s"
    for repeat in range(1, repeats + 1):
        for hrg_game in games:
            runs.append(
                run_variant(
                    hrg_game,
                    "hrg_rg_table1_subset",
                    VARIANTS["hrg_rg_optimized"],
                    limit,
                    experiment="table1_playout_throughput_subset",
                    compile_mode="benchmark",
                    repeat=repeat,
                )
            )
            rbg_game = TABLE1_RBG_PAIRS.get(Path(hrg_game).name)
            if rbg_game:
                runs.append(
                    run_variant(
                        rbg_game,
                        "rbg_rg_table1_subset",
                        VARIANTS["hrg_rg_optimized"],
                        limit,
                        experiment="table1_playout_throughput_subset",
                        compile_mode="benchmark",
                        repeat=repeat,
                    )
                )
    return runs


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
    parser.add_argument("--benchmark-games", nargs="+", default=[])
    parser.add_argument("--benchmark-seconds", type=float, default=0.0)
    parser.add_argument("--benchmark-repeats", type=int, default=3)
    parser.add_argument("--output", default=str(OUT_DIR / "results.json"))
    args = parser.parse_args()

    OUT_DIR.mkdir(parents=True, exist_ok=True)
    run(["python3", "scripts/rebuild.py"], cwd=COMPILER_ROOT)

    runs: list[dict[str, Any]] = []
    for game in args.games:
        for variant, flags in VARIANTS.items():
            runs.append(run_variant(game, variant, flags, args.sims))
    if args.benchmark_games and args.benchmark_seconds > 0:
        runs.extend(run_table1_subset(args.benchmark_games, args.benchmark_seconds, args.benchmark_repeats))
    compute_reductions(runs)

    payload = {
        "metadata": {
            "created_utc": datetime.now(timezone.utc).isoformat(),
            "paper": "Regular Games - an Automata-Based General Game Playing Language",
            "sims_per_variant": args.sims,
            "benchmark_seconds": args.benchmark_seconds,
            "benchmark_repeats": args.benchmark_repeats,
            "notes": "Official RG interpreter, HRG/RBG optimizers, rg2cpp compiler, and C++ reasoner pipeline.",
        },
        "runs": runs,
    }
    Path(args.output).write_text(json.dumps(payload, indent=2, sort_keys=True))
    print(f"Wrote {args.output}")
    failed = [run_data for run_data in runs if not run_data.get("build_success")]
    if failed:
        details = ", ".join(f"{run_data['game']}:{run_data['method']}" for run_data in failed)
        raise RuntimeError(f"rg2cpp/C++ playout pipeline failed for {details}; see raw_log in {args.output}")


if __name__ == "__main__":
    main()
