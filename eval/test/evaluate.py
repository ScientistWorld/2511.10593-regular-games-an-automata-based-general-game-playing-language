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

Steps 1-5 run on two tracks: the HRG rule files (experiments
forward_model_efficiency and automaton_optimization) and the matched RBG rule
files (experiment translated_rules_optimization, compared with the frozen
direct RBG->RG translation).

Any failure, impossible value or missing artifact makes the method's run fail:
it then receives the worst value of every scored metric of every experiment.
"""

from __future__ import annotations

import argparse
import concurrent.futures as cf
import hashlib
import json
import math
import os
import re
import shutil
import signal
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
RBG_GAMES: dict[str, dict[str, Any]] = CONFIG["rbg_games"]
RBG_GAME_DIR = ROOT / CONFIG["rbg_games_dir"]
TRACKS = {"hrg": (GAMES, GAME_DIR), "rbg": (RBG_GAMES, RBG_GAME_DIR)}
BASELINE_DIR = HERE / "baselines"
MANIFEST = json.loads((BASELINE_DIR / "manifest.json").read_text())
DRIVER = HERE / "driver" / "fm_driver.cpp"
PROBE = HERE / "probe.cpp"
RGCOMPILER_SRC = HERE / "tools" / "rgcompiler"

DIRECT = "direct_translation_baseline"
RBG = "rbg_translation_baseline"
RBG_DIRECT = "direct_rbg_translation_baseline"
REFERENCE_RG2CPP_FLAGS = (
    "--simple-path-compression 0 --disjoint 1 --all-unique 0 --arithmetic 1 --max-move-len -1 --gccinline 0 "
    "--support-apply-move-for-keeper 0 --remove-unecessary-funcion-arguments 1 --no-cycle-detection 0 "
    "--print-function-names 0 --preserve-original-node-names 1 --verification 0"
).split()
CXX = shutil.which(os.environ.get("RG_EVAL_CXX", "g++")) or "g++"
NM = shutil.which("nm") or "nm"
VALGRIND = shutil.which("valgrind") or "valgrind"
# Evaluator sources are read once, before any method code runs, and written
# fresh into every build directory.
DRIVER_SRC = DRIVER.read_text()
PROBE_SRC = PROBE.read_text()
CXXFLAGS = [
    "-std=c++23", "-O3", "-flto=auto", "-ftracer", "--param", "max-inline-insns-auto=1024",
    "-march=x86-64-v2", "-mtune=generic", "-DNDEBUG", "-w",
]
SCAN_FLAGS = ["-std=c++23", "-O1", "-march=x86-64-v2", "-DNDEBUG", "-w", "-fno-lto"]

EFF = "forward_model_efficiency"
STRUCT = "automaton_optimization"
TRANS = "translated_rules_optimization"
WORST = {
    EFF: {
        "speedup_vs_rbg_translation": 0.0,
        "worst_game_speedup_vs_rbg_translation": 0.0,
        "speedup_vs_direct_translation": 0.0,
        "verified_game_fraction": 0.0,
        "games_faster_than_rbg_fraction": 0.0,
    },
    STRUCT: {"automaton_edge_reduction_pct": -100.0, "automaton_node_reduction_pct": -100.0, "verified_automaton_fraction": 0.0},
    TRANS: {
        "speedup_vs_direct_rbg_translation": 0.0,
        "rbg_automaton_edge_reduction_pct": -100.0,
        "rbg_automaton_node_reduction_pct": -100.0,
        "verified_rbg_game_fraction": 0.0,
    },
}
# Concurrency follows the CPUs this process may actually use (cgroup/cpuset),
# not the host's core count, to bound memory from parallel LTO builds.
MAX_WORKERS = max(1, min(int(os.environ.get("RG_EVAL_WORKERS", len(os.sched_getaffinity(0)) + 1)), 12))

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


CHILD_ENV = dict(os.environ)


def run(cmd: list[str], *, timeout: float, cwd: Path | None = None, env: dict[str, str] | None = None) -> subprocess.CompletedProcess:
    try:
        return subprocess.run(cmd, cwd=cwd, env=env or CHILD_ENV, capture_output=True, text=True, timeout=timeout)
    except subprocess.TimeoutExpired as exc:
        raise RunFailure(f"timeout after {timeout}s: {' '.join(map(str, cmd[:3]))}") from exc


def run_method(cmd: list[str], *, timeout: float) -> subprocess.CompletedProcess:
    """Run method code in its own session and kill everything it left behind."""
    proc = subprocess.Popen(cmd, cwd=ROOT, env=CHILD_ENV, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, start_new_session=True)
    try:
        out, err = proc.communicate(timeout=timeout)
    except subprocess.TimeoutExpired as exc:
        raise RunFailure(f"timeout after {timeout}s: {' '.join(map(str, cmd[:3]))}") from exc
    finally:
        try:
            os.killpg(proc.pid, signal.SIGKILL)
        except ProcessLookupError:
            pass
        proc.wait()
    return subprocess.CompletedProcess(cmd, proc.returncode, out, err)


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
    probe = work / "rg_eval_probe.cpp"
    probe.write_text(PROBE_SRC)
    objs = []
    for src in [src_dir / "reasoner.cpp", probe]:
        obj = work / (src.stem + ".scan.o")
        check(run([CXX, *SCAN_FLAGS, *boost_include_flags(), "-c", str(src), "-I", str(src_dir), "-o", str(obj)], timeout=900), f"scan compile {src.name}")
        objs.append(obj)
    for obj in objs:
        undefined = check(run([NM, "-u", "-C", str(obj)], timeout=120), "nm").stdout
        for line in undefined.splitlines():
            sym = line.strip().removeprefix("U ").strip()
            if FORBIDDEN_UNDEFINED.search(sym):
                raise RunFailure(f"submitted reasoner references forbidden symbol: {sym}")
        defined = check(run([NM, "--defined-only", "-C", str(obj)], timeout=120), "nm").stdout
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
    driver = out.with_name(out.name + "_driver.cpp")
    driver.write_text(DRIVER_SRC)
    check(run([CXX, *CXXFLAGS, *boost_include_flags(), str(driver), str(src_dir / "reasoner.cpp"), "-I", str(src_dir), "-o", str(out)], timeout=1800), "C++ build")
    return out


def run_perft(binary: Path, depth: int) -> tuple[int, int, int]:
    proc = check(run([str(binary), "perft", str(depth)], timeout=1200), "perft")
    match = re.search(r"^PERFT (\d+) (\d+) (\d+)$", proc.stdout, re.M)
    if not match:
        raise RunFailure(f"perft output missing: {proc.stdout[-300:]}")
    return tuple(int(x) for x in match.groups())  # type: ignore[return-value]


def rg_depth(cfg: dict[str, Any]) -> int:
    """Tree depth for checking a submitted automaton (compiled without pragmas, so slower)."""
    return int(cfg.get("rg_perft_depth", cfg["perft_depth"]))


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


SLOWDOWN_CAP = 30.0  # a model this many times slower (wall clock) than the direct translation fails fast


def native_seconds(binary: Path, count: int, seed: int, timeout: float = 3600) -> float:
    start = time.monotonic()
    check(run([str(binary), "play", str(count), str(seed)], timeout=timeout), "native playouts")
    return time.monotonic() - start


def run_play(binary: Path, count: int, seed: int, *, valgrind: bool) -> tuple[dict[str, Any] | None, int | None]:
    cmd = [str(binary), "play", str(count), str(seed)]
    if valgrind:
        cmd = [VALGRIND, "--tool=cachegrind", "--cache-sim=no", "--cachegrind-out-file=/dev/null", *cmd]
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
        self.rg2cpp_digest = ""
        self.rg2cpp_tampered = False
        self.rg2cpp_builds = 0
        self.truth: dict[tuple[str, str], dict[str, Any]] = {}
        self.cost: dict[str, dict[str, float]] = {DIRECT: {}, RBG: {}, RBG_DIRECT: {}}
        self.floor: dict[tuple[str, str], int] = {}
        self.native: dict[tuple[str, str], float] = {}

    def build_reference_rg2cpp(self) -> Path:
        if os.environ.get("RG_EVAL_PREBUILT_RG2CPP"):
            return Path(os.environ["RG_EVAL_PREBUILT_RG2CPP"])
        self.rg2cpp_builds += 1
        build = self.work / f"rgcompiler_build_{self.rg2cpp_builds}"
        src = self.work / f"rgcompiler_src_{self.rg2cpp_builds}"
        shutil.copytree(RGCOMPILER_SRC, src)
        build.mkdir()
        check(run(["cmake", str(src), "-DCMAKE_BUILD_TYPE=Release"], cwd=build, timeout=600), "cmake reference rg2cpp")
        check(run(["make", f"-j{MAX_WORKERS}", "rg2cpp"], cwd=build, timeout=3600), "make reference rg2cpp")
        return build / "src" / "rg2cpp"

    def baseline_task(self, game: str) -> None:
        cfg = GAMES[game]
        gdir = self.work / "baselines" / game
        gdir.mkdir(parents=True)
        direct = build_binary(BASELINE_DIR / game / "direct", gdir / "direct")
        rbg = build_binary(BASELINE_DIR / game / "rbg", gdir / "rbg")
        perft = run_perft(direct, cfg["perft_depth"])
        rg_perft = run_perft(direct, rg_depth(cfg)) if rg_depth(cfg) != cfg["perft_depth"] else perft
        stats, instr = run_play(direct, cfg["playouts"], self.seed, valgrind=True)
        _, floor = run_play(direct, 0, self.seed, valgrind=True)
        rbg_stats, rbg_instr = run_play(rbg, cfg["playouts"], self.seed, valgrind=True)
        self.truth[("hrg", game)] = {"perft": perft, "rg_perft": rg_perft, "play": stats}
        self.native[("hrg", game)] = native_seconds(direct, cfg["playouts"], self.seed)
        self.floor[("hrg", game)] = floor
        self.cost[DIRECT][game] = (instr - floor) / cfg["playouts"]
        self.cost[RBG][game] = (rbg_instr - floor) / cfg["playouts"]
        if self.cost[DIRECT][game] <= 0 or self.cost[RBG][game] <= 0:
            raise RunFailure(f"baseline cost not positive for {game}")

    def rbg_baseline_task(self, game: str) -> None:
        cfg = RBG_GAMES[game]
        gdir = self.work / "baselines_rbg" / game
        gdir.mkdir(parents=True)
        direct = build_binary(BASELINE_DIR / game / "rbg_direct", gdir / "rbg_direct")
        perft = run_perft(direct, cfg["perft_depth"])
        rg_perft = run_perft(direct, rg_depth(cfg)) if rg_depth(cfg) != cfg["perft_depth"] else perft
        stats, instr = run_play(direct, cfg["playouts"], self.seed, valgrind=True)
        _, floor = run_play(direct, 0, self.seed, valgrind=True)
        self.truth[("rbg", game)] = {"perft": perft, "rg_perft": rg_perft, "play": stats}
        self.native[("rbg", game)] = native_seconds(direct, cfg["playouts"], self.seed)
        self.floor[("rbg", game)] = floor
        self.cost[RBG_DIRECT][game] = (instr - floor) / cfg["playouts"]
        if self.cost[RBG_DIRECT][game] <= 0:
            raise RunFailure(f"baseline cost not positive for {game}")

    def check_reasoner(self, binary: Path, track: str, game: str, *, automaton_check: bool = False) -> None:
        cfg, truth = TRACKS[track][0][game], self.truth[(track, game)]
        depth = rg_depth(cfg) if automaton_check else cfg["perft_depth"]
        expected = truth["rg_perft"] if automaton_check else truth["perft"]
        perft = run_perft(binary, depth)
        if perft != expected:
            raise RunFailure(f"{game}: game-tree counts {perft} differ from ground truth {expected}")

    def method_game_task(self, method: str, track: str, game: str, out: Path) -> dict[str, Any]:
        cfg = TRACKS[track][0][game]
        gwork = self.work / "methods" / method / f"{track}_{game}"
        gwork.mkdir(parents=True, exist_ok=True)
        scan_submission(out, gwork)
        binary = build_binary(out, gwork / "fm")
        self.check_reasoner(binary, track, game)
        # Fail fast (before the slow instruction count) on models that are far
        # slower than even the untransformed translation; wall clock is only a
        # pass/fail guard here, never a score.
        cap = max(60.0, SLOWDOWN_CAP * self.native[(track, game)])
        try:
            native_seconds(binary, cfg["playouts"], self.seed, timeout=cap)
        except RunFailure as exc:
            raise RunFailure(f"{game}: playout workload exceeds {SLOWDOWN_CAP:.0f}x the direct translation's time ({exc})") from exc
        stats, instr = run_play(binary, cfg["playouts"], self.seed, valgrind=True)
        problem = same_distribution(stats, self.truth[(track, game)]["play"], CONFIG["stat_tolerance_z"])
        if problem:
            raise RunFailure(f"{game}: playout statistics differ: {problem}")
        cost = (instr - self.floor[(track, game)]) / cfg["playouts"]
        if not math.isfinite(cost) or cost <= 0:
            raise RunFailure(f"{game}: impossible instruction cost {cost}")
        # Structural experiment: the submitted RG automaton, compiled by the reference rg2cpp.
        ast = json.loads((out / "game.json").read_text())
        size = automaton_size(out / "game.json")
        ast["pragmas"] = []
        rgdir = gwork / "rg"
        rgdir.mkdir(exist_ok=True)
        (rgdir / "game.json").write_text(json.dumps(ast))
        if hashlib.sha256(self.rg2cpp.read_bytes()).hexdigest() != self.rg2cpp_digest:
            self.rg2cpp_tampered = True
            raise RunFailure("evaluator's reference rg2cpp was modified during this method's evaluation")
        check(run([str(self.rg2cpp), "--file", "game.json", "-o", "reasoner", *REFERENCE_RG2CPP_FLAGS], cwd=rgdir, timeout=600), f"{game}: reference rg2cpp on submitted automaton")
        rg_binary = build_binary(rgdir, gwork / "rg_fm")
        self.check_reasoner(rg_binary, track, game, automaton_check=True)
        rg_stats, _ = run_play(rg_binary, cfg.get("rg_playouts", cfg["playouts"]), self.seed, valgrind=False)
        problem = same_distribution(rg_stats, self.truth[(track, game)]["play"], CONFIG["stat_tolerance_z"])
        if problem:
            raise RunFailure(f"{game}: submitted automaton playout statistics differ: {problem}")
        return {"cost": cost, "nodes": size["nodes"], "edges": size["edges"], "mean_playout_length": stats["depth"][0] / stats["count"]}

    def compile_method(self, method: str, mdir: Path, scratch: Path) -> dict[tuple[str, str], Path]:
        outs: dict[tuple[str, str], Path] = {}
        prepare = mdir / "prepare.sh"
        if prepare.exists():
            check(run_method(["bash", str(prepare)], timeout=CONFIG["prepare_timeout_s"]), f"{method} prepare.sh")
        for track, game in [(t, g) for t, (games, _) in TRACKS.items() for g in games]:
            gin = Path(tempfile.mkdtemp(prefix="rules_", dir=scratch))
            rules = gin / f"rules.{track}"
            shutil.copyfile(TRACKS[track][1] / f"{game}.{track}", rules)
            out = Path(tempfile.mkdtemp(prefix="out_", dir=scratch))
            check(run_method(["bash", str(mdir / "compile.sh"), str(rules), str(out)], timeout=CONFIG["compile_timeout_s"]), f"{method} compile.sh on {game}")
            for name in ["reasoner.hpp", "reasoner.cpp", "game.json"]:
                if not (out / name).is_file():
                    raise RunFailure(f"{method} produced no {name} for {game}.{track}")
            outs[(track, game)] = out
        return outs

    def evaluate_method(self, method: str, mdir: Path) -> tuple[dict[str, dict[str, float]], dict[str, Any]]:
        status: dict[str, Any] = {"status": "ok"}
        scratch = self.work / "methods" / method
        scratch.mkdir(parents=True, exist_ok=True)
        if self.rg2cpp_tampered:
            self.rg2cpp = self.build_reference_rg2cpp()
            self.rg2cpp_digest = hashlib.sha256(self.rg2cpp.read_bytes()).hexdigest()
            self.rg2cpp_tampered = False
        try:
            outs = self.compile_method(method, mdir, scratch)
            futures = {key: self.pool.submit(self.method_game_task, method, key[0], key[1], out) for key, out in outs.items()}
            cf.wait(list(futures.values()))
            per_game = {key: fut.result() for key, fut in futures.items()}
        except (RunFailure, OSError, ValueError, KeyError, TypeError, json.JSONDecodeError) as exc:
            status = {"status": "failed", "reason": str(exc)[:2000]}
            return {exp: dict(vals) for exp, vals in WORST.items()}, status
        finally:
            shutil.rmtree(scratch, ignore_errors=True)
        status["per_game"] = {f"{t}:{g}": row for (t, g), row in per_game.items()}
        return self.metrics(per_game), status

    def metrics(self, per_game: dict[tuple[str, str], dict[str, Any]]) -> dict[str, dict[str, float]]:
        def geomean(values: list[float]) -> float:
            return math.exp(sum(math.log(v) for v in values) / len(values))

        hrg = {g: per_game[("hrg", g)] for g in GAMES}
        rbg = {g: per_game[("rbg", g)] for g in RBG_GAMES}
        vs_rbg = geomean([self.cost[RBG][g] / hrg[g]["cost"] for g in GAMES])
        worst_vs_rbg = min(self.cost[RBG][g] / hrg[g]["cost"] for g in GAMES)
        vs_direct = geomean([self.cost[DIRECT][g] / hrg[g]["cost"] for g in GAMES])

        def reduction(rows: dict[str, dict[str, Any]], key: str, base: str) -> float:
            vals = [max(-100.0, 100.0 * (1 - rows[g][key] / MANIFEST[g][base][key])) for g in rows]
            return sum(vals) / len(vals)

        faster = sum(self.cost[RBG][g] > hrg[g]["cost"] for g in GAMES) / len(GAMES)
        values = {
            EFF: {
                "speedup_vs_rbg_translation": vs_rbg,
                "worst_game_speedup_vs_rbg_translation": worst_vs_rbg,
                "speedup_vs_direct_translation": vs_direct,
                "verified_game_fraction": 1.0,
                "games_faster_than_rbg_fraction": faster,
            },
            STRUCT: {
                "automaton_edge_reduction_pct": reduction(hrg, "edges", "direct_automaton"),
                "automaton_node_reduction_pct": reduction(hrg, "nodes", "direct_automaton"),
                "verified_automaton_fraction": 1.0,
            },
            TRANS: {
                "speedup_vs_direct_rbg_translation": geomean([self.cost[RBG_DIRECT][g] / rbg[g]["cost"] for g in RBG_GAMES]),
                "rbg_automaton_edge_reduction_pct": reduction(rbg, "edges", "rbg_direct_automaton"),
                "rbg_automaton_node_reduction_pct": reduction(rbg, "nodes", "rbg_direct_automaton"),
                "verified_rbg_game_fraction": 1.0,
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
    parser.add_argument("--resume", action="store_true", help="keep methods already scored in --output (same seed) and score the rest")
    args = parser.parse_args()
    if shutil.which("valgrind") is None:
        sys.exit("valgrind is required to measure executed instructions")

    started = time.time()
    previous: dict[str, Any] = {}
    seed_id = hashlib.sha256(f"rg-eval-{args.seed}".encode()).hexdigest()[:12]
    if args.resume and Path(args.output).is_file():
        old = json.loads(Path(args.output).read_text())
        if old.get("metadata", {}).get("seed_id") == seed_id:
            previous = old
    # Scratch space lives in the workspace (container /tmp can be a tiny tmpfs);
    # compilers and methods get it as TMPDIR.
    base = Path(os.environ.get("RG_EVAL_WORKDIR", ROOT / "tmp" / "eval_work"))
    base.mkdir(parents=True, exist_ok=True)
    work = Path(tempfile.mkdtemp(prefix=f"rg_eval_{SLICE}_", dir=base))
    (work / "tmp").mkdir()
    CHILD_ENV["TMPDIR"] = str(work / "tmp")
    ev = Evaluator(work, args.seed)
    methods = discover_methods(Path(args.methods_dir).resolve())
    try:
        rg2cpp_future = ev.pool.submit(ev.build_reference_rg2cpp)
        for fut in [ev.pool.submit(ev.baseline_task, game) for game in GAMES] + [ev.pool.submit(ev.rbg_baseline_task, game) for game in RBG_GAMES]:
            fut.result()
        ev.rg2cpp = rg2cpp_future.result()
        ev.rg2cpp_digest = hashlib.sha256(ev.rg2cpp.read_bytes()).hexdigest()

        results: dict[str, dict[str, dict[str, float]]] = {EFF: {}, STRUCT: {}, TRANS: {}}
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
        results[TRANS][RBG_DIRECT] = {
            "speedup_vs_direct_rbg_translation": 1.0,
            "rbg_automaton_edge_reduction_pct": 0.0,
            "rbg_automaton_node_reduction_pct": 0.0,
            "verified_rbg_game_fraction": 1.0,
        }
        details["baselines"] = {
            f"hrg:{g}": {
                "direct_instructions_per_playout": ev.cost[DIRECT][g],
                "rbg_instructions_per_playout": ev.cost[RBG][g],
                "ground_truth_perft": ev.truth[("hrg", g)]["perft"],
                "ground_truth_mean_playout_length": ev.truth[("hrg", g)]["play"]["depth"][0] / ev.truth[("hrg", g)]["play"]["count"],
                "direct_automaton": MANIFEST[g]["direct_automaton"],
            }
            for g in GAMES
        }
        details["baselines"].update({
            f"rbg:{g}": {
                "direct_rbg_instructions_per_playout": ev.cost[RBG_DIRECT][g],
                "ground_truth_perft": ev.truth[("rbg", g)]["perft"],
                "rbg_direct_automaton": MANIFEST[g]["rbg_direct_automaton"],
            }
            for g in RBG_GAMES
        })
        if not methods:
            methods_status = {"no_method_found": {"status": "failed", "reason": "no method/compilers/<name>/compile.sh on disk"}}
            for exp, vals in WORST.items():
                results[exp]["no_method_found"] = dict(vals)
        else:
            methods_status = {}
        def write_scores(final: bool) -> None:
            payload = {
                "metadata": {
                    "slice": SLICE,
                    "seed_id": seed_id,
                    "complete": final,
                    "games": list(GAMES),
                    "rbg_games": list(RBG_GAMES),
                    "methods": {k: {"status": v["status"], **({"reason": v["reason"]} if "reason" in v else {})} for k, v in methods_status.items()},
                    "elapsed_seconds": round(time.time() - started, 1),
                },
                "experiments": {exp: {"results": res} for exp, res in results.items()},
            }
            out = Path(args.output)
            out.parent.mkdir(parents=True, exist_ok=True)
            tmp_out = out.with_suffix(out.suffix + ".partial")
            tmp_out.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n")
            tmp_out.replace(out)
            if args.details:
                Path(args.details).write_text(json.dumps(details, indent=2, sort_keys=True, default=list) + "\n")

        old_status = previous.get("metadata", {}).get("methods", {})
        old_details: dict[str, Any] = {}
        if previous and args.details and Path(args.details).is_file():
            old_details = json.loads(Path(args.details).read_text()).get("methods", {})
        for name, mdir in methods.items():
            if name in old_status and all(name in previous["experiments"].get(exp, {}).get("results", {}) for exp in results):
                for exp in results:
                    results[exp][name] = previous["experiments"][exp]["results"][name]
                methods_status[name] = dict(old_details.get(name, old_status[name]))
                print(f"[{SLICE}] {name}: resumed {methods_status[name]['status']}", flush=True)
                continue
            vals, status = ev.evaluate_method(name, mdir)
            for exp in results:
                results[exp][name] = vals[exp]
            for key, row in status.get("per_game", {}).items():
                track, g = key.split(":", 1)
                if track == "hrg":
                    row["speedup_vs_direct"] = ev.cost[DIRECT][g] / row["cost"]
                    row["speedup_vs_rbg"] = ev.cost[RBG][g] / row["cost"]
                else:
                    row["speedup_vs_direct_rbg"] = ev.cost[RBG_DIRECT][g] / row["cost"]
            methods_status[name] = status
            details["methods"] = methods_status
            write_scores(final=False)
            print(f"[{SLICE}] {name}: {status['status']} {json.dumps(vals)}", flush=True)
        details["methods"] = methods_status
        write_scores(final=True)
    finally:
        ev.pool.shutdown(wait=True, cancel_futures=True)
        shutil.rmtree(work, ignore_errors=True)

    scores = json.loads(Path(args.output).read_text())
    print(json.dumps(scores, indent=2, sort_keys=True))


if __name__ == "__main__":
    main()
