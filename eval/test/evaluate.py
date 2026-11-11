#!/usr/bin/env python3
"""Held-out evaluator for generated game forward models (test slice).

For every method directory on disk (``method/compilers/<name>/compile.sh``)
this evaluator, without trusting anything the method reports:

1. runs the method's compiler on rule files that only this directory holds
   (a temporary copy is passed; per-game time cap),
2. checks the submitted C++ forward model for process/IO hijacking and
   backend overrides, then compiles it with the evaluator-owned driver and
   fixed compiler flags,
3. verifies it against ground truth computed from the frozen direct
   translation: exact game-tree counts to a fixed depth and the statistics of
   uniformly random playouts (playout length, branching, every player's score),
4. measures the work of a fixed flat Monte Carlo workload (fixed playout count,
   hidden seed) as executed machine instructions (valgrind) and compares it
   with the frozen baselines measured in the same run,
5. recompiles the submitted RG automaton (game.json) with the evaluator-owned
   reference rg2cpp (pragmas stripped), verifies it the same way and counts
   its nodes and edges against the frozen direct translation.

Any failure, impossible value or missing artifact makes the method's run fail:
it then receives the worst value of every scored metric of every experiment.
"""

from __future__ import annotations

import argparse
import concurrent.futures as cf
import json
import math
import os
import re
import shutil
import subprocess
import sys
import tempfile
import time
from pathlib import Path
from typing import Any

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
CONFIG = json.loads((HERE / "config.json").read_text())
SLICE = CONFIG["slice"]
GAMES: dict[str, dict[str, Any]] = CONFIG["games"]
GAME_DIR = ROOT / CONFIG["games_dir"]
BASELINE_DIR = HERE / "baselines"
MANIFEST = json.loads((BASELINE_DIR / "manifest.json").read_text())
DRIVER = HERE / "driver" / "fm_driver.cpp"
PROBE = HERE / "probe.cpp"
RGCOMPILER_SRC = HERE / "tools" / "rgcompiler"

DIRECT = "direct_translation_baseline"
RBG = "rbg_translation_baseline"
REFERENCE_RG2CPP_FLAGS = (
    "--simple-path-compression 0 --disjoint 1 --all-unique 0 --arithmetic 1 --max-move-len -1 --gccinline 0 "
    "--support-apply-move-for-keeper 0 --remove-unecessary-funcion-arguments 1 --no-cycle-detection 0 "
    "--print-function-names 0 --preserve-original-node-names 1 --verification 0"
).split()
CXX = os.environ.get("RG_EVAL_CXX", "g++")
CXXFLAGS = [
    "-std=c++23", "-O3", "-flto=auto", "-ftracer", "--param", "max-inline-insns-auto=1024",
    "-march=x86-64-v2", "-mtune=generic", "-DNDEBUG", "-w",
]
SCAN_FLAGS = ["-std=c++23", "-O1", "-march=x86-64-v2", "-DNDEBUG", "-w", "-fno-lto"]

EFF = "forward_model_efficiency"
STRUCT = "automaton_optimization"
WORST = {
    EFF: {
        "speedup_vs_rbg_translation": 0.0,
        "worst_game_speedup_vs_rbg_translation": 0.0,
        "speedup_vs_direct_translation": 0.0,
        "verified_game_fraction": 0.0,
        "games_faster_than_rbg_fraction": 0.0,
    },
    STRUCT: {"automaton_edge_reduction_pct": -100.0, "automaton_node_reduction_pct": -100.0, "verified_automaton_fraction": 0.0},
}
MAX_WORKERS = max(1, min(int(os.environ.get("RG_EVAL_WORKERS", os.cpu_count() or 4)), 12))

# ---------------------------------------------------------------- integrity
FORBIDDEN_UNDEFINED = re.compile(
    r"^(exit|_exit|_Exit|quick_exit|atexit|at_quick_exit|write|writev|pwrite|pwrite64|pwritev|read|readv|pread|pread64|"
    r"open|open64|openat|openat64|creat|creat64|close|fopen|fopen64|freopen|fdopen|fclose|popen|pclose|system|printf|"
    r"fprintf|vprintf|vfprintf|dprintf|vdprintf|puts|fputs|putchar|putchar_unlocked|fputc|putc|fwrite|fwrite_unlocked|"
    r"fflush|fileno|sendfile|sendfile64|send|sendto|sendmsg|socket|connect|mmap|mmap64|munmap|mprotect|dup|dup2|dup3|"
    r"ioctl|fcntl|fcntl64|syscall|getenv|secure_getenv|setenv|putenv|unsetenv|fork|vfork|clone|clone3|execv|execve|"
    r"execvp|execvpe|execl|execlp|execle|posix_spawn|posix_spawnp|kill|raise|signal|sigaction|alarm|setitimer|dlopen|"
    r"dlsym|dlvsym|pthread_create|thrd_create|ptrace|prctl|chdir|unlink|unlinkat|rename|remove|truncate|ftruncate|"
    r"clock_gettime|gettimeofday|time|times|getrusage|clock|sched_yield|nanosleep|usleep|sleep|__libc_start_main|"
    r"stdout|stderr|stdin|_IO_2_1_stdout_|_IO_2_1_stderr_|_IO_2_1_stdin_|environ|__environ|program_invocation_name)$"
    r"|std::(cout|cerr|clog|cin|wcout|wcerr|wclog|wcin)\b|basic_filebuf|basic_ofstream|basic_ifstream|basic_fstream|"
    r"stdio_filebuf|stdio_sync_filebuf|std::thread|std::this_thread|std::chrono|std::random_device|std::exit|std::quick_exit"
)
PROTECTED_DEFINED = re.compile(
    r"basic_ostream|__ostream_insert|std::ostream|std::endl|std::flush|ios_base::Init|num_put|stoul|stoull|"
    r"\bstrto|std::exit|std::terminate|sync_with_stdio|std::cout|std::cerr|std::clog|__cxa_|_Unwind_|"
    r"(^|[\s*&])(main|memcpy|memmove|memset|malloc|calloc|realloc|free|operator new|operator delete)\("
)
FORBIDDEN_SOURCE = [
    (re.compile(r"\b(asm|__asm|__asm__)\b"), "inline assembly"),
    (re.compile(r"#\s*pragma\s+(GCC|clang)\s+(target|optimize|push_options|pop_options|reset_options)"), "backend override pragma"),
    (re.compile(r"__attribute__\s*\(\(\s*(\w+\s*(\([^()]*\))?\s*,\s*)*(constructor|destructor|target|target_clones|optimize|ifunc|alias|weakref|weak|section|visibility)\b"), "attribute override"),
    (re.compile(r"\[\[\s*gnu::(constructor|destructor|target|target_clones|optimize|ifunc|alias|weakref|weak|section|visibility)"), "attribute override"),
    (re.compile(r"\binit_priority\b"), "init priority"),
]


class RunFailure(Exception):
    pass


def run(cmd: list[str], *, timeout: float, cwd: Path | None = None, env: dict[str, str] | None = None) -> subprocess.CompletedProcess:
    try:
        return subprocess.run(cmd, cwd=cwd, env=env, capture_output=True, text=True, timeout=timeout)
    except subprocess.TimeoutExpired as exc:
        raise RunFailure(f"timeout after {timeout}s: {' '.join(map(str, cmd[:3]))}") from exc


def check(proc: subprocess.CompletedProcess, what: str) -> subprocess.CompletedProcess:
    if proc.returncode != 0:
        tail = (proc.stdout + proc.stderr)[-1500:]
        raise RunFailure(f"{what} failed (exit {proc.returncode}): {tail}")
    return proc


def boost_include_flags() -> list[str]:
    extra = os.environ.get("RG_EVAL_EXTRA_INCLUDE")
    return ["-isystem", extra] if extra else []


def scan_submission(src_dir: Path, work: Path) -> None:
    """Reject submissions that could hijack the driver process or override the fixed backend."""
    for name in ["reasoner.hpp", "reasoner.cpp"]:
        if not (src_dir / name).is_file():
            raise RunFailure(f"missing {name}")
    pre = check(run([CXX, *SCAN_FLAGS, *boost_include_flags(), "-E", str(src_dir / "reasoner.cpp"), "-I", str(src_dir)], timeout=300), "preprocess")
    current, own = "", []
    for line in pre.stdout.splitlines():
        marker = re.match(r'^#\s+\d+\s+"([^"]+)"', line)
        if marker:
            current = marker.group(1)
            continue
        if Path(current).name in {"reasoner.cpp", "reasoner.hpp"} and not current.startswith("/usr/"):
            own.append(line)
    text = "\n".join(own)
    for pattern, label in FORBIDDEN_SOURCE:
        if pattern.search(text):
            raise RunFailure(f"submitted reasoner uses forbidden construct: {label}")
    objs = []
    for src in [src_dir / "reasoner.cpp", PROBE]:
        obj = work / (src.stem + ".scan.o")
        check(run([CXX, *SCAN_FLAGS, *boost_include_flags(), "-c", str(src), "-I", str(src_dir), "-o", str(obj)], timeout=900), f"scan compile {src.name}")
        objs.append(obj)
    for obj in objs:
        undefined = check(run(["nm", "-u", "-C", str(obj)], timeout=120), "nm").stdout
        for line in undefined.splitlines():
            sym = line.strip().removeprefix("U ").strip()
            if FORBIDDEN_UNDEFINED.search(sym):
                raise RunFailure(f"submitted reasoner references forbidden symbol: {sym}")
        defined = check(run(["nm", "--defined-only", "-C", str(obj)], timeout=120), "nm").stdout
        for line in defined.splitlines():
            parts = line.split(" ", 2)
            if len(parts) < 3:
                continue
            kind, sym = parts[1], parts[2]
            if kind in {"i", "I"}:
                raise RunFailure(f"submitted reasoner defines indirect function {sym}")
            if (kind.islower() and kind != "u") or "reasoner" in sym or sym == "rg_eval_probe(unsigned int)":
                continue
            if kind in {"W", "V", "u"} and "::" in sym and not PROTECTED_DEFINED.search(sym):
                continue
            if sym.startswith("DW.ref.__gxx_personality_v0"):
                continue
            raise RunFailure(f"submitted reasoner defines global symbol outside its namespace: {kind} {sym}")


def build_binary(src_dir: Path, out: Path) -> Path:
    check(run([CXX, *CXXFLAGS, *boost_include_flags(), str(DRIVER), str(src_dir / "reasoner.cpp"), "-I", str(src_dir), "-o", str(out)], timeout=1800), "C++ build")
    return out


def run_perft(binary: Path, depth: int) -> tuple[int, int, int]:
    proc = check(run([str(binary), "perft", str(depth)], timeout=1200), "perft")
    match = re.search(r"^PERFT (\d+) (\d+) (\d+)$", proc.stdout, re.M)
    if not match:
        raise RunFailure(f"perft output missing: {proc.stdout[-300:]}")
    return tuple(int(x) for x in match.groups())  # type: ignore[return-value]


def parse_play(stdout: str, expected_count: int) -> dict[str, Any]:
    match = re.search(r"^PLAY (.+)$", stdout, re.M)
    if not match:
        raise RunFailure(f"playout output missing: {stdout[-300:]}")
    f = match.group(1).split()
    players = int(f[9])
    out = {
        "count": int(f[0]), "plies": int(f[1]), "moves": int(f[2]), "min_depth": int(f[3]), "max_depth": int(f[4]),
        "depth": (float(f[5]), float(f[6])), "branch": (float(f[7]), float(f[8])), "players": players,
        "scores": [(float(f[10 + 2 * p]), float(f[11 + 2 * p])) for p in range(players)],
    }
    if out["count"] != expected_count or out["plies"] < out["count"]:
        raise RunFailure("playout workload incomplete")
    return out


def run_play(binary: Path, count: int, seed: int, *, valgrind: bool) -> tuple[dict[str, Any] | None, int | None]:
    cmd = [str(binary), "play", str(count), str(seed)]
    if valgrind:
        cmd = ["valgrind", "--tool=cachegrind", "--cache-sim=no", "--cachegrind-out-file=/dev/null", *cmd]
    proc = check(run(cmd, timeout=3600), "playouts")
    instr = None
    if valgrind:
        match = re.search(r"I\s+refs:\s+([\d,]+)", proc.stderr)
        if not match:
            raise RunFailure("instruction count missing")
        instr = int(match.group(1).replace(",", ""))
    stats = parse_play(proc.stdout, count) if count > 0 else None
    return stats, instr


def mean_var(moments: tuple[float, float], n: int) -> tuple[float, float]:
    mean = moments[0] / n
    var = max(moments[1] / n - mean * mean, 0.0)
    return mean, var


def same_distribution(cand: dict[str, Any], truth: dict[str, Any], z: float) -> str | None:
    n_c, n_t = cand["count"], truth["count"]
    if cand["players"] != truth["players"]:
        return "player count differs"
    pairs = [("playout length", cand["depth"], truth["depth"]), ("branching", cand["branch"], truth["branch"])]
    pairs += [(f"score of player {p + 1}", cand["scores"][p], truth["scores"][p]) for p in range(truth["players"])]
    for label, mc, mt in pairs:
        m1, v1 = mean_var(mc, n_c)
        m2, v2 = mean_var(mt, n_t)
        tol = z * math.sqrt(v1 / n_c + v2 / n_t) + 1e-9 * max(1.0, abs(m2))
        if not (math.isfinite(m1) and abs(m1 - m2) <= tol):
            return f"{label} mean {m1:.6g} vs ground truth {m2:.6g} (tolerance {tol:.3g})"
    return None


def automaton_size(ast_file: Path) -> dict[str, int]:
    data = json.loads(ast_file.read_text())
    edges = data["edges"]
    if not isinstance(edges, list) or not edges:
        raise RunFailure("automaton has no edges")
    nodes = set()
    for edge in edges:
        nodes.add(json.dumps(edge["lhs"], sort_keys=True))
        nodes.add(json.dumps(edge["rhs"], sort_keys=True))
    return {"nodes": len(nodes), "edges": len(edges)}


# ---------------------------------------------------------------- pipeline
class Evaluator:
    def __init__(self, work: Path, seed: int):
        self.work = work
        self.seed = seed
        self.pool = cf.ThreadPoolExecutor(MAX_WORKERS)
        self.rg2cpp: Path | None = None
        self.truth: dict[str, dict[str, Any]] = {}
        self.cost: dict[str, dict[str, float]] = {DIRECT: {}, RBG: {}}
        self.floor: dict[str, int] = {}

    def build_reference_rg2cpp(self) -> Path:
        if os.environ.get("RG_EVAL_PREBUILT_RG2CPP"):
            return Path(os.environ["RG_EVAL_PREBUILT_RG2CPP"])
        build = self.work / "rgcompiler_build"
        shutil.copytree(RGCOMPILER_SRC, self.work / "rgcompiler_src")
        build.mkdir()
        check(run(["cmake", str(self.work / "rgcompiler_src"), "-DCMAKE_BUILD_TYPE=Release"], cwd=build, timeout=600), "cmake reference rg2cpp")
        check(run(["make", f"-j{MAX_WORKERS}", "rg2cpp"], cwd=build, timeout=3600), "make reference rg2cpp")
        return build / "src" / "rg2cpp"

    def baseline_task(self, game: str) -> None:
        cfg = GAMES[game]
        gdir = self.work / "baselines" / game
        gdir.mkdir(parents=True)
        direct = build_binary(BASELINE_DIR / game / "direct", gdir / "direct")
        rbg = build_binary(BASELINE_DIR / game / "rbg", gdir / "rbg")
        perft = run_perft(direct, cfg["perft_depth"])
        stats, instr = run_play(direct, cfg["playouts"], self.seed, valgrind=True)
        _, floor = run_play(direct, 0, self.seed, valgrind=True)
        rbg_stats, rbg_instr = run_play(rbg, cfg["playouts"], self.seed, valgrind=True)
        self.truth[game] = {"perft": perft, "play": stats}
        self.floor[game] = floor
        self.cost[DIRECT][game] = (instr - floor) / cfg["playouts"]
        self.cost[RBG][game] = (rbg_instr - floor) / cfg["playouts"]
        if self.cost[DIRECT][game] <= 0 or self.cost[RBG][game] <= 0:
            raise RunFailure(f"baseline cost not positive for {game}")

    def check_reasoner(self, binary: Path, game: str) -> None:
        cfg, truth = GAMES[game], self.truth[game]
        perft = run_perft(binary, cfg["perft_depth"])
        if perft != truth["perft"]:
            raise RunFailure(f"{game}: game-tree counts {perft} differ from ground truth {truth['perft']}")

    def method_game_task(self, method: str, game: str, out: Path) -> dict[str, Any]:
        cfg = GAMES[game]
        gwork = self.work / "methods" / method / game
        gwork.mkdir(parents=True, exist_ok=True)
        scan_submission(out, gwork)
        binary = build_binary(out, gwork / "fm")
        self.check_reasoner(binary, game)
        stats, instr = run_play(binary, cfg["playouts"], self.seed, valgrind=True)
        problem = same_distribution(stats, self.truth[game]["play"], CONFIG["stat_tolerance_z"])
        if problem:
            raise RunFailure(f"{game}: playout statistics differ: {problem}")
        cost = (instr - self.floor[game]) / cfg["playouts"]
        if not math.isfinite(cost) or cost <= 0:
            raise RunFailure(f"{game}: impossible instruction cost {cost}")
        # Structural experiment: the submitted RG automaton, compiled by the reference rg2cpp.
        ast = json.loads((out / "game.json").read_text())
        size = automaton_size(out / "game.json")
        ast["pragmas"] = []
        rgdir = gwork / "rg"
        rgdir.mkdir(exist_ok=True)
        (rgdir / "game.json").write_text(json.dumps(ast))
        check(run([str(self.rg2cpp), "--file", "game.json", "-o", "reasoner", *REFERENCE_RG2CPP_FLAGS], cwd=rgdir, timeout=600), f"{game}: reference rg2cpp on submitted automaton")
        rg_binary = build_binary(rgdir, gwork / "rg_fm")
        self.check_reasoner(rg_binary, game)
        rg_stats, _ = run_play(rg_binary, cfg["playouts"], self.seed, valgrind=False)
        problem = same_distribution(rg_stats, self.truth[game]["play"], CONFIG["stat_tolerance_z"])
        if problem:
            raise RunFailure(f"{game}: submitted automaton playout statistics differ: {problem}")
        return {"cost": cost, "nodes": size["nodes"], "edges": size["edges"], "mean_playout_length": stats["depth"][0] / stats["count"]}

    def compile_method(self, method: str, mdir: Path) -> dict[str, Path]:
        outs: dict[str, Path] = {}
        prepare = mdir / "prepare.sh"
        if prepare.exists():
            check(run(["bash", str(prepare)], cwd=ROOT, timeout=CONFIG["prepare_timeout_s"]), f"{method} prepare.sh")
        for game in GAMES:
            gin = Path(tempfile.mkdtemp(prefix="rules_", dir=self.work))
            rules = gin / "rules.hrg"
            shutil.copyfile(GAME_DIR / f"{game}.hrg", rules)
            out = Path(tempfile.mkdtemp(prefix="out_", dir=self.work))
            check(run(["bash", str(mdir / "compile.sh"), str(rules), str(out)], cwd=ROOT, timeout=CONFIG["compile_timeout_s"]), f"{method} compile.sh on {game}")
            for name in ["reasoner.hpp", "reasoner.cpp", "game.json"]:
                if not (out / name).is_file():
                    raise RunFailure(f"{method} produced no {name} for {game}")
            outs[game] = out
        return outs

    def evaluate_method(self, method: str, mdir: Path) -> tuple[dict[str, dict[str, float]], dict[str, Any]]:
        status: dict[str, Any] = {"status": "ok"}
        try:
            outs = self.compile_method(method, mdir)
            futures = {game: self.pool.submit(self.method_game_task, method, game, outs[game]) for game in GAMES}
            per_game = {game: fut.result() for game, fut in futures.items()}
        except (RunFailure, OSError, ValueError, KeyError, TypeError, json.JSONDecodeError) as exc:
            status = {"status": "failed", "reason": str(exc)[:2000]}
            return {exp: dict(vals) for exp, vals in WORST.items()}, status
        status["per_game"] = per_game
        return self.metrics(per_game), status

    def metrics(self, per_game: dict[str, dict[str, Any]]) -> dict[str, dict[str, float]]:
        def geomean(values: list[float]) -> float:
            return math.exp(sum(math.log(v) for v in values) / len(values))

        vs_rbg = geomean([self.cost[RBG][g] / per_game[g]["cost"] for g in GAMES])
        worst_vs_rbg = min(self.cost[RBG][g] / per_game[g]["cost"] for g in GAMES)
        vs_direct = geomean([self.cost[DIRECT][g] / per_game[g]["cost"] for g in GAMES])
        edge_red = [max(-100.0, 100.0 * (1 - per_game[g]["edges"] / MANIFEST[g]["direct_automaton"]["edges"])) for g in GAMES]
        node_red = [max(-100.0, 100.0 * (1 - per_game[g]["nodes"] / MANIFEST[g]["direct_automaton"]["nodes"])) for g in GAMES]
        faster = sum(self.cost[RBG][g] > per_game[g]["cost"] for g in GAMES) / len(GAMES)
        values = {
            EFF: {
                "speedup_vs_rbg_translation": vs_rbg,
                "worst_game_speedup_vs_rbg_translation": worst_vs_rbg,
                "speedup_vs_direct_translation": vs_direct,
                "verified_game_fraction": 1.0,
                "games_faster_than_rbg_fraction": faster,
            },
            STRUCT: {
                "automaton_edge_reduction_pct": sum(edge_red) / len(edge_red),
                "automaton_node_reduction_pct": sum(node_red) / len(node_red),
                "verified_automaton_fraction": 1.0,
            },
        }
        for exp in values.values():
            for key, val in exp.items():
                if not math.isfinite(val):
                    raise RunFailure(f"impossible value for {key}")
        return values


def discover_methods(methods_dir: Path) -> dict[str, Path]:
    found = {}
    if methods_dir.is_dir():
        for child in sorted(methods_dir.iterdir()):
            if child.is_dir() and (child / "compile.sh").is_file():
                name = child.name if child.name not in {DIRECT, RBG} else f"{child.name}__method"
                found[name] = child
    return found


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--methods-dir", default=str(ROOT / "method" / "compilers"))
    parser.add_argument("--output", default=str(ROOT / "scoring" / f"scores_{SLICE}.json"))
    parser.add_argument("--seed", type=int, default=CONFIG["seed"])
    parser.add_argument("--details", default=None, help="optional path for per-game diagnostics")
    args = parser.parse_args()
    if shutil.which("valgrind") is None:
        sys.exit("valgrind is required to measure executed instructions")

    started = time.time()
    work = Path(tempfile.mkdtemp(prefix=f"rg_eval_{SLICE}_"))
    ev = Evaluator(work, args.seed)
    methods = discover_methods(Path(args.methods_dir).resolve())
    try:
        rg2cpp_future = ev.pool.submit(ev.build_reference_rg2cpp)
        for fut in [ev.pool.submit(ev.baseline_task, game) for game in GAMES]:
            fut.result()
        ev.rg2cpp = rg2cpp_future.result()

        results: dict[str, dict[str, dict[str, float]]] = {EFF: {}, STRUCT: {}}
        details: dict[str, Any] = {"baselines": {}, "methods": {}}
        geo = lambda xs: math.exp(sum(math.log(x) for x in xs) / len(xs))  # noqa: E731
        results[EFF][DIRECT] = {
            "speedup_vs_rbg_translation": geo([ev.cost[RBG][g] / ev.cost[DIRECT][g] for g in GAMES]),
            "worst_game_speedup_vs_rbg_translation": min(ev.cost[RBG][g] / ev.cost[DIRECT][g] for g in GAMES),
            "speedup_vs_direct_translation": 1.0,
            "verified_game_fraction": 1.0,
            "games_faster_than_rbg_fraction": sum(ev.cost[RBG][g] > ev.cost[DIRECT][g] for g in GAMES) / len(GAMES),
        }
        results[EFF][RBG] = {
            "speedup_vs_rbg_translation": 1.0,
            "worst_game_speedup_vs_rbg_translation": 1.0,
            "speedup_vs_direct_translation": geo([ev.cost[DIRECT][g] / ev.cost[RBG][g] for g in GAMES]),
        }
        results[STRUCT][DIRECT] = {"automaton_edge_reduction_pct": 0.0, "automaton_node_reduction_pct": 0.0, "verified_automaton_fraction": 1.0}
        details["baselines"] = {
            g: {
                "direct_instructions_per_playout": ev.cost[DIRECT][g],
                "rbg_instructions_per_playout": ev.cost[RBG][g],
                "ground_truth_perft": ev.truth[g]["perft"],
                "ground_truth_mean_playout_length": ev.truth[g]["play"]["depth"][0] / ev.truth[g]["play"]["count"],
                "direct_automaton": MANIFEST[g]["direct_automaton"],
            }
            for g in GAMES
        }
        if not methods:
            methods_status = {"no_method_found": {"status": "failed", "reason": "no method/compilers/<name>/compile.sh on disk"}}
            for exp, vals in WORST.items():
                results[exp]["no_method_found"] = dict(vals)
        else:
            methods_status = {}
        for name, mdir in methods.items():
            vals, status = ev.evaluate_method(name, mdir)
            for exp in results:
                results[exp][name] = vals[exp]
            for g, row in status.get("per_game", {}).items():
                row["speedup_vs_direct"] = ev.cost[DIRECT][g] / row["cost"]
                row["speedup_vs_rbg"] = ev.cost[RBG][g] / row["cost"]
            methods_status[name] = status
            print(f"[{SLICE}] {name}: {status['status']} {json.dumps(vals)}", flush=True)
        details["methods"] = methods_status
    finally:
        ev.pool.shutdown(wait=True, cancel_futures=True)
        shutil.rmtree(work, ignore_errors=True)

    scores = {
        "metadata": {
            "slice": SLICE,
            "games": list(GAMES),
            "methods": {k: {"status": v["status"], **({"reason": v["reason"]} if "reason" in v else {})} for k, v in methods_status.items()},
            "elapsed_seconds": round(time.time() - started, 1),
        },
        "experiments": {exp: {"results": res} for exp, res in results.items()},
    }
    Path(args.output).parent.mkdir(parents=True, exist_ok=True)
    Path(args.output).write_text(json.dumps(scores, indent=2, sort_keys=True) + "\n")
    if args.details:
        Path(args.details).write_text(json.dumps(details, indent=2, sort_keys=True, default=list) + "\n")
    print(json.dumps(scores, indent=2, sort_keys=True))


if __name__ == "__main__":
    main()
