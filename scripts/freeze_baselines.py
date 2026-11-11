#!/usr/bin/env python3
"""One-time provenance script: freeze the evaluator-owned comparison artifacts.

For every game of a slice this writes, under eval/<slice>/baselines/<game>/:
  direct/reasoner.{hpp,cpp}  direct HRG->RG translation (inferred pragmas, no
                             automaton transformations) compiled by rg2cpp
  rbg/reasoner.{hpp,cpp}     the matched RBG description translated RBG->RG
                             with the full optimizer (the paper's RBG->RG column)
  rbg_direct/reasoner.{hpp,cpp}  the matched RBG description translated
                             RBG->RG directly (inferred pragmas, no automaton
                             transformations): ground truth and comparison
                             point of the translated-rules experiment
and eval/<slice>/baselines/manifest.json with the automata's node and edge
counts. The evaluators only read these frozen files; they never call the
method code. Re-running this script is only needed to rebuild the gym.
"""

from __future__ import annotations

import argparse
import json
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
COMPILE = ROOT / "method" / "toolchain" / "compile_game.py"
DIRECT = "--enable-all-pragmas"
OPTIMIZED = "--enable-all-optimizations --enable-all-pragmas"

SLICES = {
    "train": {
        "hrg_dir": ROOT / "data" / "games" / "hrg",
        "rbg_dir": ROOT / "data" / "games" / "rbg",
        "games": ["connect4", "breakthrough", "yavalath", "hex", "reversi", "knightthrough", "gomoku_standard", "foxAndHounds"],
    },
    "test": {
        "hrg_dir": ROOT / "eval" / "test" / "games" / "hrg",
        "rbg_dir": ROOT / "eval" / "test" / "games" / "rbg",
        "games": ["breakthrough_7x7", "hex_9x9", "reversi_6x6", "gomoku_standard_13x13", "foxAndHounds_10x10"],
    },
}


def automaton_size(ast_file: Path) -> dict[str, int]:
    data = json.loads(ast_file.read_text())
    nodes: set[str] = set()
    for edge in data["edges"]:
        nodes.add(json.dumps(edge["lhs"], sort_keys=True))
        nodes.add(json.dumps(edge["rhs"], sort_keys=True))
    return {"nodes": len(nodes), "edges": len(data["edges"])}


def build(game: Path, outdir: Path, translate: str) -> dict[str, int]:
    with tempfile.TemporaryDirectory() as tmp_name:
        tmp = Path(tmp_name)
        subprocess.run([sys.executable, str(COMPILE), str(game), str(tmp), f"--translate={translate}"], check=True)
        outdir.mkdir(parents=True, exist_ok=True)
        for name in ["reasoner.hpp", "reasoner.cpp"]:
            (outdir / name).write_text((tmp / name).read_text())
        return automaton_size(tmp / "game.json")


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("slices", nargs="*", default=["train", "test"])
    args = parser.parse_args()
    subprocess.run(["bash", str(ROOT / "method" / "toolchain" / "build.sh")], check=True)
    for slice_name in args.slices:
        spec = SLICES[slice_name]
        base = ROOT / "eval" / slice_name / "baselines"
        manifest = {}
        for game in spec["games"]:
            direct = build(spec["hrg_dir"] / f"{game}.hrg", base / game / "direct", DIRECT)
            rbg = build(spec["rbg_dir"] / f"{game}.rbg", base / game / "rbg", OPTIMIZED)
            rbg_direct = build(spec["rbg_dir"] / f"{game}.rbg", base / game / "rbg_direct", DIRECT)
            manifest[game] = {"direct_automaton": direct, "rbg_automaton": rbg, "rbg_direct_automaton": rbg_direct}
            print(slice_name, game, manifest[game], flush=True)
        (base / "manifest.json").write_text(json.dumps(manifest, indent=2, sort_keys=True) + "\n")


if __name__ == "__main__":
    main()
