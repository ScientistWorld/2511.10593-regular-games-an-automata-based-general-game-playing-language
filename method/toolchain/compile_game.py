#!/usr/bin/env python3
"""Translate one rule file (HRG/RBG/RG) through the official RG pipeline.

rule file --(Rust CLI: translation + optimizer passes + pragma inference)-->
RG AST --(adjust_AST)--> game.json --(rg2cpp)--> reasoner.hpp / reasoner.cpp

Outputs in OUTDIR:
  game.json      RG automaton (AST JSON consumed by rg2cpp)
  reasoner.hpp   generated C++ forward model
  reasoner.cpp
"""

from __future__ import annotations

import argparse
import os
import shlex
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
CLI = ROOT / "method" / "rg" / "interpreter_rust" / "target" / "release" / "cli"
RG2CPP = ROOT / "method" / "rgcompiler" / "build" / "src" / "rg2cpp"
ADJUST = ROOT / "method" / "rgcompiler" / "scripts" / "adjust_AST.py"

OPTIMIZED_TRANSLATE = "--enable-all-optimizations --enable-all-pragmas"
DIRECT_TRANSLATE = "--enable-all-pragmas"
DEFAULT_RG2CPP = (
    "--simple-path-compression 0 --disjoint 1 --all-unique 0 --arithmetic 1 --max-move-len -1 "
    "--gccinline 0 --support-apply-move-for-keeper 0 --remove-unecessary-funcion-arguments 1 "
    "--no-cycle-detection 0 --print-function-names 0 --preserve-original-node-names 1 --verification 0"
)


def compile_game(game: Path, outdir: Path, translate: str, rg2cpp_flags: str) -> None:
    outdir.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory() as tmp_name:
        tmp = Path(tmp_name)
        raw = tmp / "raw.json"
        with raw.open("w") as handle:
            subprocess.run([str(CLI), "ast", *shlex.split(translate), str(game)], check=True, stdout=handle)
        subprocess.run([sys.executable, str(ADJUST), str(raw), str(tmp / "game.json")], check=True)
        subprocess.run([str(RG2CPP), "--file", "game.json", "-o", "reasoner", *shlex.split(rg2cpp_flags)], check=True, cwd=tmp)
        for name in ["game.json", "reasoner.hpp", "reasoner.cpp"]:
            shutil.copyfile(tmp / name, outdir / name)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("game", type=Path)
    parser.add_argument("outdir", type=Path)
    parser.add_argument("--translate", default=os.environ.get("RG_TRANSLATE_FLAGS", OPTIMIZED_TRANSLATE))
    parser.add_argument("--rg2cpp", default=os.environ.get("RG2CPP_FLAGS", DEFAULT_RG2CPP))
    args = parser.parse_args()
    compile_game(args.game.resolve(), args.outdir.resolve(), args.translate, args.rg2cpp)


if __name__ == "__main__":
    main()
