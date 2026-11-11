# Overview

**Paper ID:** 2511.10593
**Title:** Regular Games - an Automata-Based General Game Playing Language
**Domain:** General game playing / formal game languages / compiler optimization

Regular Games proposes an automata-based rule language and compiler for general
game playing. Its central claim is that game rules translated into optimized
rule automata compile into forward models that are faster than those of the
previous fastest system (Regular Boardgames), with much smaller automata than
a direct translation.

This gym asks for a compiler from game-rule files to C++ forward models. It
verifies every produced model against ground truth and scores the executed
instructions per random playout (relative to frozen comparison models) and the
size of the produced rules automaton. The official RG toolchain is packaged in
`method/` as the reference compiler.

---

# Problem Definition

General game playing needs **forward models**: programs that, given only a
formal description of a finite turn-based game, expose its current player,
legal moves, move application, terminal detection and final scores, without
any hand-written game-specific code. Search and learning agents spend most of
their time inside the forward model, so its efficiency matters.

In this gym the rules are written in the High-level Regular Games (HRG)
language (`data/games/hrg/*.hrg`) and, for the same games, in the Regular
Boardgames (RBG) language (`data/games/rbg/*.rbg`); both languages are defined
in `method/rg/` and the paper in `paper/`. A method is a **compiler**: given
one rule file (HRG or RBG) it must produce

1. a C++ forward model (`reasoner.hpp`, `reasoner.cpp`) implementing the
   `reasoner::` API described below, and
2. the low-level Regular Games (RG) rules automaton it derived for the game
   (`game.json`, the RG abstract-syntax JSON accepted by the official RG
   compiler `rg2cpp`, i.e. after the upstream `adjust_AST.py` normalisation).

The forward model must play exactly the game in the rule file. The goal is a
forward model that executes uniformly random playouts with as little work as
possible, and an automaton for the game that is as small as possible.

## Interface

A method lives in `method/compilers/<name>/` and provides

- `compile.sh <rules> <outdir>` — must write `reasoner.hpp`,
  `reasoner.cpp` and `game.json` into `<outdir>`. It is called once per rule
  file with a copy named `rules.hrg` or `rules.rbg`, with the workspace as working directory, and
  must finish within 15 seconds per game (the reference needs about 1-2 s).
- optionally `prepare.sh` — one-time, input-independent setup (for example
  building tools), run once before the per-game calls (time cap 1 hour).

Every directory under `method/compilers/` that contains a `compile.sh` is a
method and is scored; one that fails gets the worst score.

The forward model API (namespace `reasoner`), as used by the evaluator's
driver:

- `reasoner::GameState` — default-constructible initial state, copyable;
  `getCurrentPlayer()`, `isTerminal()`, `getPlayerScore(p)` for players
  `2 .. 1 + PLAYERS_COUNT`, `getAllMoves(std::vector<reasoner::Move>&, reasoner::RgCache&)`,
  `applyMove(const reasoner::Move&, reasoner::RgCache&)`, `applyAnyMove(reasoner::RgCache&)`
  (applies the single move of the deterministic `keeper` system player);
- `reasoner::RgCache` (default-constructible), `reasoner::Move`,
  `reasoner::PLAYERS_COUNT`, `reasoner::keeper`, `reasoner::random`.

The reference compiler in `method/compilers/hrg_rg_optimized/` produces
exactly this interface.

## Rules of the game for submissions

The submitted C++ is compiled and run by the evaluator together with its own
driver. It may only implement the forward model: it may not perform I/O, read
the environment, spawn processes or threads, terminate the process, use inline
assembly, define symbols outside its own `reasoner` namespace that could
replace library or driver functions, or override the evaluator's compiler
settings (`#pragma GCC optimize/target`, `optimize`/`target`/`constructor`
attributes). Such submissions fail.

---

# Paper's Method

The paper introduces Regular Games (RG), a low-level language whose rules are a
nondeterministic finite automaton over game states, and High-level Regular
Games (HRG), a structured source language translated to RG. An RG description
is improved by a fixed-point loop of static transformations (dataflow-based
analysis, constant propagation, inlining of assignments and reachability
checks, compaction of skip edges, joining exclusive edges, pruning redundant
tags, ...) and annotated with inferred pragmas (`@disjoint`, `@unique`,
`@repeat`, `@simpleApply`, `@tagIndex`, ...). The `rg2cpp` compiler then
generates a C++ forward model that enumerates legal moves by walking the
automaton.

The reference method `method/compilers/hrg_rg_optimized/` runs the authors'
official pipeline unchanged:

1. `method/rg/interpreter_rust` CLI: HRG -> RG translation with
   `--enable-all-optimizations --enable-all-pragmas` (all transformations and
   pragma inference);
2. `method/rgcompiler/scripts/adjust_AST.py` normalisation -> `game.json`;
3. `method/rgcompiler` `rg2cpp` with the upstream default code-generation
   options (`--simple-path-compression 0 --disjoint 1 --arithmetic 1 --gccinline 0 ...`)
   -> `reasoner.hpp`, `reasoner.cpp`.

`method/toolchain/build.sh` builds both tools offline; `method/toolchain/compile_game.py`
runs steps 1-3 for any HRG/RBG/RG input with configurable flags.

The paper measures efficiency as flat Monte Carlo playouts per second (Table 1)
and reports mean automaton reductions of 47% nodes / 41% edges for HRG games
(Section 3.3).

---

# Evaluation

Two scripts score **every method on disk** (`method/compilers/<name>/compile.sh`):

```bash
bash scripts/evaluate_train.sh   # visible games in data/games/{hrg,rbg} -> scoring/scores_train.json
bash scripts/evaluate_test.sh    # held-out games (not visible)    -> scoring/scores_test.json
```

`evaluate_test.sh` takes no arguments. `evaluate_train.sh` accepts
`--details <file>` for per-game diagnostics and `--methods-dir <dir>`.
Both need `valgrind`, `g++`, `cmake` and `nm` (all in the container).

For each method and each rule file of the slice (the HRG files, and the RBG
descriptions of the same kind of games) the evaluator:

1. runs `compile.sh` on a copy of the rule file (15 s cap per game, the method's own process group is killed afterwards);
2. checks the generated C++ (no I/O, process control, inline assembly,
   symbol interposition or compiler-setting overrides), then compiles it with
   its own driver and fixed flags (`g++ -std=c++23 -O3 -flto -march=x86-64-v2 -DNDEBUG`);
3. **verifies** the forward model against ground truth computed from a frozen
   reference translation of the same rule file: exact game-tree counts
   (leaves, states, terminals) to a fixed depth, and the statistics of a fixed
   number of uniformly random playouts (mean playout length, mean branching
   factor, every player's mean score) within six standard errors;
4. fails the run if that workload takes more than 30 times as long (wall
   clock, pass/fail only) as the frozen direct translation, then **measures**
   the work of that fixed playout workload (fixed count, fixed
   seed) as executed machine instructions under valgrind, and divides it by
   the playout count;
5. recompiles the submitted `game.json` with the official RG compiler
   (pragmas removed), verifies it the same way, and counts its nodes and edges.

Comparison points are frozen by the evaluator and measured in the same run:
the matched RBG description of each game translated RBG->RG, the direct HRG->RG
translation without automaton transformations, and the direct RBG->RG
translation without automaton transformations. Ground truth for an HRG file
comes from its direct translation; for an RBG file from its direct RBG->RG
translation.

If any step fails for any game, the method's run fails and it receives the
worst value of every scored metric (speedups 0, reductions -100, fractions 0) in all three experiments.

Metrics written under `experiments.<name>.results.<method>`:

| Experiment | Metric | Scored | Meaning |
|---|---|---|---|
| `forward_model_efficiency` | `speedup_vs_rbg_translation` | yes (primary) | geometric mean over games of RBG->RG instructions per playout / method instructions per playout |
| | `worst_game_speedup_vs_rbg_translation` | yes | minimum of the same ratio over games |
| | `verified_game_fraction` | yes (constraint) | 1 if every game verified, else the run failed |
| | `speedup_vs_direct_translation` | no | geometric-mean speedup over the direct translation |
| | `games_faster_than_rbg_fraction` | no | fraction of games beating RBG->RG |
| `automaton_optimization` | `automaton_edge_reduction_pct` | yes (primary) | mean % fewer edges than the direct translation |
| | `automaton_node_reduction_pct` | yes | mean % fewer nodes |
| | `verified_automaton_fraction` | yes (constraint) | 1 if every submitted automaton verified |
| `translated_rules_optimization` | `speedup_vs_direct_rbg_translation` | yes | geometric mean over RBG files of direct RBG->RG instructions per playout / method instructions per playout |
| | `rbg_automaton_edge_reduction_pct` | yes (primary) | mean % fewer edges than the direct RBG->RG translation |
| | `rbg_automaton_node_reduction_pct` | yes | mean % fewer nodes |
| | `verified_rbg_game_fraction` | yes (constraint) | 1 if every RBG file's model and automaton verified |

Experiment weights: 0.60, 0.15 and 0.25.

Instruction counts are deterministic for a given binary and seed, so scores do
not depend on wall-clock time or machine load. The train slice uses eight
standard-size games; the held-out slice uses different, unseen games of the
same kind at comparable difficulty (the translated-rules experiment uses
seven train games and four held-out games).

---

# Reproduction Log

### Iteration 1: gpt-5.5
- **Milestone**: `none` | **Status**: error
- **Working time**: 15m | **GPU**: 0.0h

<details>
<summary>Progress Log</summary>

<!-- Write your progress here -->

</details>

### Iteration 1: gpt-5.5
- **Milestone**: `none` | **Status**: error
- **Working time**: 30m | **GPU**: 0.0h

### Iteration 1: gpt-5.5
- **Milestone**: `none` | **Status**: error
- **Working time**: 31m | **GPU**: 0.0h

### Iteration 1: gpt-5.5
- **Milestone**: `none` | **Status**: error
- **Working time**: 30m | **GPU**: 0.0h

### Iteration 1: gpt-5.5
- **Milestone**: `core_claim` | **Status**: done
- **Working time**: 1.1h | **GPU**: 0.0h
- **Jobs**: 9 total (3 completed, 6 failed)

<details>
<summary>Progress Log</summary>

### [2026-05-31 00:00] - none
- Read the paper and identified the central pipeline: HRG/RBG inputs, RG automata, static optimizer, and C++ forward-model compiler.
- Fetched official source snapshots and prepared a CPU smoke job; no method execution result has returned yet.

### [2026-05-31 00:00] - none
- Continuation audit confirmed the method code wraps the paper's actual HRG/RG optimizer and C++ compiler pipeline, not a surrogate.
- No reproduced scores are present yet, so the milestone remains `none` until the submitted smoke job returns.

### [2026-05-31 00:00] - none
- First CPU smoke job built the container and started the official pipeline, but failed while invoking `scripts/sims.py`.
- Fixed the wrapper invocation and output parsing; no successful method run has completed yet.

### [2026-05-31 00:00] - none
- Second CPU smoke job reached the official Rust interpreter build, but offline Cargo resolution failed on a wasm-only dependency.
- Gated wasm-only CLI bindings/dependencies behind `wasm32` and narrowed the upstream build step to the native CLI binary needed by the reproduction.

### [2026-05-31 00:00] - none
- Third CPU smoke job failed on `rand`, showing the ignored Cargo vendor tree was absent from the compute checkout.
- Removed the vendored-source override and moved Cargo dependency prefetching into the container build so offline compute builds resolve native Rust crates from the image cache.

### [2026-05-31 00:00] - none
- Fourth CPU smoke job still failed on `rand`, showing the setup overlay cache was not being used by the job.
- Updated `environment/container.def` to prefetch Cargo crates during image build and set `CARGO_HOME` explicitly for runtime.

### [2026-05-31 16:37] - none
- The next environment build failed before job submission because `%files` could not find the Rust source tree from the scheduler's build context.
- Removed the `%files` dependency and changed the image build to prefetch native Rust crates from a temporary manifest created inside `%post`.

### [2026-05-31 17:03] - none
- Job `dc418534-e51` confirmed the image now builds and the method reaches the official Rust build, but offline Cargo still lacked a target-specific wasm crate from the workspace lockfile.
- Replaced the synthetic prefetch manifest with a build-time clone of the official RG repository and `cargo fetch --locked`, so the image cache matches the real upstream lockfile.

### [2026-05-31 17:15] - none
- Job `3e8551a2-cf4` reached HRG translation and automaton optimization, but generated C++ playouts did not compile because `rg2cpp` was called with a stale flag name.
- Updated the compiler flags, fixed the upstream `rg2cpp` error check, and narrowed `scores.json` to declared metrics before retrying.

### [2026-05-31 17:24] - none
- Job `773e609f-499` reproduced near-paper automaton reductions, but `rg2cpp` still aborted before C++ playouts, leaving the correctness constraint at zero.
- Found and patched an AST schema mismatch in SimpleApply pragmas (`type` emitted by the current RG interpreter versus `type_` expected by rgcompiler) and made failed playout pipelines fail the method job instead of passing validation with zero playouts.

### [2026-05-31 17:32] - core_claim
- Job `552e1382-378` generated and compiled C++ reasoners for both no-optimization and optimized HRG pipelines on Connect4 and Breakthrough.
- The optimized pipeline reproduced the core structural claim with 44.854% fewer automaton nodes and 39.167% fewer edges, close to the paper's 47% and 41%, while both baseline and optimized reasoners completed all playouts (`playout_completion_rate = 1.0`).

### [2026-05-31 17:37] - core_claim
- Job `a0586e53-f4a` validated the reusable `scripts/reproduce.sh` path with the default 200 playouts per generated reasoner.
- All four generated C++ reasoner runs completed 200/200 playouts and reproduced the same structural scores, so the packaged environment is usable at `core_claim`.

</details>

### Iteration 2: gpt-5.5
- **Milestone**: `core_claim_plus` | **Status**: done
- **Working time**: 6m | **GPU**: 0.0h
- **Jobs**: 12 total (5 completed, 6 failed)

<details>
<summary>Progress Log</summary>

### [2026-05-31 17:38] - core_claim
- Ran the official Regular Games HRG-to-RG optimizer, rg2cpp C++ generation, C++ compilation, and deterministic playout pipeline on Connect4 and Breakthrough.
- Reproduced the paper's core structural optimization claim: 44.854% fewer automaton nodes and 39.167% fewer automaton edges, close to the reported 47% and 41%.
- Preserved the correctness constraint: both baseline and optimized generated reasoners completed 200/200 deterministic playouts.

### [2026-05-31 18:05] - core_claim
- Continuation audit confirmed the implementation is the paper's actual automata optimization and C++ reasoner generation pipeline, not a surrogate.
- Queued an expanded HRG-game run to test the same claim on additional settings.

### [2026-05-31 18:15] - core_claim_plus
- Expanded the core experiment from two HRG games to six: Connect4, Breakthrough, Hex, Yavalath, Tic-Tac-Toe, and Tic-Tac-Die.
- The optimized pipeline averaged 49.427% fewer automaton nodes and 44.911% fewer automaton edges, exceeding the paper's reported 47% and 41% HRG structural reductions on this subset.
- The correctness constraint still held: all baseline and optimized generated reasoners completed 200/200 deterministic playouts.

### [2026-05-31 18:45] - core_claim_plus
- Expanded the same experiment to 14 HRG games from the paper's benchmark set.
- The optimized pipeline averaged 48.942% fewer automaton nodes, 44.325% fewer automaton edges, and 39.930% fewer generated C++ lines.
- All 28 generated reasoner variants completed 200/200 deterministic playouts and `validate.py --compare` passed.

</details>

### Iteration 3: gpt-5.5
- **Milestone**: `core_claim_plus` | **Status**: done
- **Working time**: 7m | **GPU**: 0.0h
- **Jobs**: 13 total (6 completed, 6 failed)

<details>
<summary>Progress Log</summary>

### [2026-05-31 18:46] - method_runs
- Validated the official HRG -> optimized RG -> rg2cpp -> generated C++ reasoner pipeline on the expanded 14-game subset.
- Reproduced the paper's structural optimization claim with 48.942% fewer automaton nodes and 44.325% fewer automaton edges, while all generated reasoners completed fixed playout checks.
- Follow-up audit found the existing scored experiment covered the paper's optimizer-size claim but not the Section 4 Table 1 playout-throughput core claim.
- Added a benchmark-mode Table 1 subset harness for paired HRG->RG and RBG->RG generated reasoners; a compute job is needed before claiming `core_claim`.

### [2026-05-31 19:08] - core_claim_plus
- Job `2049a1f1-1ef` completed the paired Table 1 subset benchmark for Connect Four, Breakthrough, and Yavalath.
- HRG->RG generated reasoners averaged 560407.0 playouts/s versus 171690.333 playouts/s for matched RBG->RG generated reasoners, a 4.051x within-job speedup.
- The benchmark completed all three matched games and `python3 validate.py --compare` passed.
- Together with the previously validated 14-game structural optimization run, the environment supports the core Section 4 throughput claim plus an additional optimizer-size claim.

</details>

### Iteration 4: gpt-5.5 (designer_stage_1)
- **Milestone**: `core_claim_plus` | **Status**: done
- **Working time**: 4m | **GPU**: 0.0h
- **Jobs**: 13 total (6 completed, 6 failed)

<details>
<summary>Progress Log</summary>

### [2026-05-31 18:46] - method_runs
- Validated the official HRG -> optimized RG -> rg2cpp -> generated C++ reasoner pipeline on the expanded 14-game subset.
- Reproduced the paper's structural optimization claim with 48.942% fewer automaton nodes and 44.325% fewer automaton edges, while all generated reasoners completed fixed playout checks.
- Follow-up audit found the existing scored experiment covered the paper's optimizer-size claim but not the Section 4 Table 1 playout-throughput core claim.
- Added a benchmark-mode Table 1 subset harness for paired HRG->RG and RBG->RG generated reasoners; a compute job is needed before claiming `core_claim`.

### [2026-05-31 19:08] - core_claim_plus
- Job `2049a1f1-1ef` completed the paired Table 1 subset benchmark for Connect Four, Breakthrough, and Yavalath.
- HRG->RG generated reasoners averaged 560407.0 playouts/s versus 171690.333 playouts/s for matched RBG->RG generated reasoners, a 4.051x within-job speedup.
- The benchmark completed all three matched games and `python3 validate.py --compare` passed.
- Together with the previously validated 14-game structural optimization run, the environment supports the core Section 4 throughput claim plus an additional optimizer-size claim.

</details>

### Iteration 5: gpt-5.5 (designer_stage_2)
- **Milestone**: `core_claim_plus` | **Status**: done
- **Working time**: 4m | **GPU**: 0.0h
- **Jobs**: 13 total (6 completed, 6 failed)

<details>
<summary>Progress Log</summary>

### [2026-05-31 18:46] - method_runs
- Validated the official HRG -> optimized RG -> rg2cpp -> generated C++ reasoner pipeline on the expanded 14-game subset.
- Reproduced the paper's structural optimization claim with 48.942% fewer automaton nodes and 44.325% fewer automaton edges, while all generated reasoners completed fixed playout checks.
- Follow-up audit found the existing scored experiment covered the paper's optimizer-size claim but not the Section 4 Table 1 playout-throughput core claim.
- Added a benchmark-mode Table 1 subset harness for paired HRG->RG and RBG->RG generated reasoners; a compute job is needed before claiming `core_claim`.

### [2026-05-31 19:08] - core_claim_plus
- Job `2049a1f1-1ef` completed the paired Table 1 subset benchmark for Connect Four, Breakthrough, and Yavalath.
- HRG->RG generated reasoners averaged 560407.0 playouts/s versus 171690.333 playouts/s for matched RBG->RG generated reasoners, a 4.051x within-job speedup.
- The benchmark completed all three matched games and `python3 validate.py --compare` passed.
- Together with the previously validated 14-game structural optimization run, the environment supports the core Section 4 throughput claim plus an additional optimizer-size claim.

</details>

### Iteration 6: gpt-5.5 (designer_stage_3)
- **Milestone**: `core_claim_plus` | **Status**: done
- **Working time**: 3m | **GPU**: 0.0h
- **Jobs**: 14 total (7 completed, 6 failed)

<details>
<summary>Progress Log</summary>

### [2026-05-31 18:46] - method_runs
- Validated the official HRG -> optimized RG -> rg2cpp -> generated C++ reasoner pipeline on the expanded 14-game subset.
- Reproduced the paper's structural optimization claim with 48.942% fewer automaton nodes and 44.325% fewer automaton edges, while all generated reasoners completed fixed playout checks.
- Follow-up audit found the existing scored experiment covered the paper's optimizer-size claim but not the Section 4 Table 1 playout-throughput core claim.
- Added a benchmark-mode Table 1 subset harness for paired HRG->RG and RBG->RG generated reasoners; a compute job is needed before claiming `core_claim`.

### [2026-05-31 19:08] - core_claim_plus
- Job `2049a1f1-1ef` completed the paired Table 1 subset benchmark for Connect Four, Breakthrough, and Yavalath.
- HRG->RG generated reasoners averaged 560407.0 playouts/s versus 171690.333 playouts/s for matched RBG->RG generated reasoners, a 4.051x within-job speedup.
- The benchmark completed all three matched games and `python3 validate.py --compare` passed.
- Together with the previously validated 14-game structural optimization run, the environment supports the core Section 4 throughput claim plus an additional optimizer-size claim.

</details>

### Iteration 7: gpt-5.5 (packager)
- **Milestone**: `core_claim_plus` | **Status**: done
- **Working time**: 2m | **GPU**: 0.0h
- **Jobs**: 14 total (7 completed, 6 failed)

<details>
<summary>Progress Log</summary>

### [2026-05-31 18:46] - method_runs
- Validated the official HRG -> optimized RG -> rg2cpp -> generated C++ reasoner pipeline on the expanded 14-game subset.
- Reproduced the paper's structural optimization claim with 48.942% fewer automaton nodes and 44.325% fewer automaton edges, while all generated reasoners completed fixed playout checks.
- Follow-up audit found the existing scored experiment covered the paper's optimizer-size claim but not the Section 4 Table 1 playout-throughput core claim.
- Added a benchmark-mode Table 1 subset harness for paired HRG->RG and RBG->RG generated reasoners; a compute job is needed before claiming `core_claim`.

### [2026-05-31 19:08] - core_claim_plus
- Job `2049a1f1-1ef` completed the paired Table 1 subset benchmark for Connect Four, Breakthrough, and Yavalath.
- HRG->RG generated reasoners averaged 560407.0 playouts/s versus 171690.333 playouts/s for matched RBG->RG generated reasoners, a 4.051x within-job speedup.
- The benchmark completed all three matched games and `python3 validate.py --compare` passed.
- Together with the previously validated 14-game structural optimization run, the environment supports the core Section 4 throughput claim plus an additional optimizer-size claim.

</details>

### Iteration 8: gpt-5.5 (verifier)
- **Milestone**: `core_claim_plus` | **Status**: done
- **Working time**: 9m | **GPU**: 0.0h
- **Jobs**: 14 total (7 completed, 6 failed)

<details>
<summary>Progress Log</summary>

### [2026-05-31 18:46] - method_runs
- Validated the official HRG -> optimized RG -> rg2cpp -> generated C++ reasoner pipeline on the expanded 14-game subset.
- Reproduced the paper's structural optimization claim with 48.942% fewer automaton nodes and 44.325% fewer automaton edges, while all generated reasoners completed fixed playout checks.
- Follow-up audit found the existing scored experiment covered the paper's optimizer-size claim but not the Section 4 Table 1 playout-throughput core claim.
- Added a benchmark-mode Table 1 subset harness for paired HRG->RG and RBG->RG generated reasoners; a compute job is needed before claiming `core_claim`.

### [2026-05-31 19:08] - core_claim_plus
- Job `2049a1f1-1ef` completed the paired Table 1 subset benchmark for Connect Four, Breakthrough, and Yavalath.
- HRG->RG generated reasoners averaged 560407.0 playouts/s versus 171690.333 playouts/s for matched RBG->RG generated reasoners, a 4.051x within-job speedup.
- The benchmark completed all three matched games and `python3 validate.py --compare` passed.
- Together with the previously validated 14-game structural optimization run, the environment supports the core Section 4 throughput claim plus an additional optimizer-size claim.

### [2026-05-31 19:29] - core_claim_plus
- Fixed the top-level evaluator to report the Table 1 generated-code and automaton-size advantage metrics declared in `reference.json`.
- Updated `scripts/run.sh` so submitted jobs regenerate method artifacts before scoring, avoiding stale gitignored outputs.
- Prepared a CPU rerun that expands the matched Table 1 subset from three to six paired HRG/RBG games.

### [2026-05-31 19:34] - core_claim_plus
- Final verification copied benchmark rule sources into tracked `data/games/` for from-scratch agents.
- Cleaned method-agnostic problem/evaluation/scoring docs so they describe the task and metrics without exposing implementation details.
- Re-ran standalone evaluators and `python3 validate.py --compare`; all checks passed.

</details>

### Iteration 9: gpt-5.5 (verifier)
- **Milestone**: `core_claim_plus` | **Status**: done
- **Working time**: 5m | **GPU**: 0.0h
- **Jobs**: 14 total (7 completed, 6 failed)

<details>
<summary>Progress Log</summary>

### [2026-05-31 18:46] - method_runs
- Validated the official HRG -> optimized RG -> rg2cpp -> generated C++ reasoner pipeline on the expanded 14-game subset.
- Reproduced the paper's structural optimization claim with 48.942% fewer automaton nodes and 44.325% fewer automaton edges, while all generated reasoners completed fixed playout checks.
- Follow-up audit found the existing scored experiment covered the paper's optimizer-size claim but not the Section 4 Table 1 playout-throughput core claim.
- Added a benchmark-mode Table 1 subset harness for paired HRG->RG and RBG->RG generated reasoners; a compute job is needed before claiming `core_claim`.

### [2026-05-31 19:08] - core_claim_plus
- Job `2049a1f1-1ef` completed the paired Table 1 subset benchmark for Connect Four, Breakthrough, and Yavalath.
- HRG->RG generated reasoners averaged 560407.0 playouts/s versus 171690.333 playouts/s for matched RBG->RG generated reasoners, a 4.051x within-job speedup.
- The benchmark completed all three matched games and `python3 validate.py --compare` passed.
- Together with the previously validated 14-game structural optimization run, the environment supports the core Section 4 throughput claim plus an additional optimizer-size claim.

### [2026-05-31 19:29] - core_claim_plus
- Fixed the top-level evaluator to report the Table 1 generated-code and automaton-size advantage metrics declared in `reference.json`.
- Updated `scripts/run.sh` so submitted jobs regenerate method artifacts before scoring, avoiding stale gitignored outputs.
- Prepared a CPU rerun that expands the matched Table 1 subset from three to six paired HRG/RBG games.

### [2026-05-31 19:34] - core_claim_plus
- Final verification copied benchmark rule sources into tracked `data/games/` for from-scratch agents.
- Cleaned method-agnostic problem/evaluation/scoring docs so they describe the task and metrics without exposing implementation details.
- Re-ran standalone evaluators and `python3 validate.py --compare`; all checks passed.

### [2026-05-31 19:47] - core_claim_plus
- Local validation still passes for the committed three-game matched benchmark artifact and train/test slices.
- Prepared a CPU rerun with the existing entrypoint's broader six-game Table 1 matched benchmark configuration.
- Current milestone remains `core_claim_plus` until that expansion job returns with measured results.

### [2026-05-31 19:55] - core_claim_plus
- Final verification rechecked validation, method/evaluation separation, download URL reachability, train/test artifacts, and method-agnostic documentation.
- Added explicit notes for machine-independent substitute metrics in `scoring/reference.json`.
- No reproduction downgrade was needed; the validated gym baseline remains the committed three-game matched Table 1 subset plus the structural compactness experiment.

</details>

### Iteration 10: gpt-6.1-sol (redteam)
- **Milestone**: `core_claim_plus` | **Status**: done
- **Working time**: 18m | **GPU**: 0.0h

<details>
<summary>Progress Log</summary>

### [2026-05-31 18:46] - method_runs
- Validated the official HRG -> optimized RG -> rg2cpp -> generated C++ reasoner pipeline on the expanded 14-game subset.
- Reproduced the paper's structural optimization claim with 48.942% fewer automaton nodes and 44.325% fewer automaton edges, while all generated reasoners completed fixed playout checks.
- Follow-up audit found the existing scored experiment covered the paper's optimizer-size claim but not the Section 4 Table 1 playout-throughput core claim.
- Added a benchmark-mode Table 1 subset harness for paired HRG->RG and RBG->RG generated reasoners; a compute job is needed before claiming `core_claim`.

### [2026-05-31 19:08] - core_claim_plus
- Job `2049a1f1-1ef` completed the paired Table 1 subset benchmark for Connect Four, Breakthrough, and Yavalath.
- HRG->RG generated reasoners averaged 560407.0 playouts/s versus 171690.333 playouts/s for matched RBG->RG generated reasoners, a 4.051x within-job speedup.
- The benchmark completed all three matched games and `python3 validate.py --compare` passed.
- Together with the previously validated 14-game structural optimization run, the environment supports the core Section 4 throughput claim plus an additional optimizer-size claim.

### [2026-05-31 19:29] - core_claim_plus
- Fixed the top-level evaluator to report the Table 1 generated-code and automaton-size advantage metrics declared in `reference.json`.
- Updated `scripts/run.sh` so submitted jobs regenerate method artifacts before scoring, avoiding stale gitignored outputs.
- Prepared a CPU rerun that expands the matched Table 1 subset from three to six paired HRG/RBG games.

### [2026-05-31 19:34] - core_claim_plus
- Final verification copied benchmark rule sources into tracked `data/games/` for from-scratch agents.
- Cleaned method-agnostic problem/evaluation/scoring docs so they describe the task and metrics without exposing implementation details.
- Re-ran standalone evaluators and `python3 validate.py --compare`; all checks passed.

### [2026-05-31 19:47] - core_claim_plus
- Local validation still passes for the committed three-game matched benchmark artifact and train/test slices.
- Prepared a CPU rerun with the existing entrypoint's broader six-game Table 1 matched benchmark configuration.
- Current milestone remains `core_claim_plus` until that expansion job returns with measured results.

### [2026-05-31 19:55] - core_claim_plus
- Final verification rechecked validation, method/evaluation separation, download URL reachability, train/test artifacts, and method-agnostic documentation.
- Added explicit notes for machine-independent substitute metrics in `scoring/reference.json`.
- No reproduction downgrade was needed; the validated gym baseline remains the committed three-game matched Table 1 subset plus the structural compactness experiment.

</details>

### Iteration 11: claude-opus-5-5 (hardener)
- **Milestone**: `core_claim_plus` | **Status**: done
- **Working time**: 1.8h | **GPU**: 0.0h
- **Jobs**: 6 total (1 completed, 0 failed)

<details>
<summary>Progress Log</summary>

### [2026-05-31 18:46] - method_runs
- Validated the official HRG -> optimized RG -> rg2cpp -> generated C++ reasoner pipeline on the expanded 14-game subset.
- Reproduced the paper's structural optimization claim with 48.942% fewer automaton nodes and 44.325% fewer automaton edges, while all generated reasoners completed fixed playout checks.
- Follow-up audit found the existing scored experiment covered the paper's optimizer-size claim but not the Section 4 Table 1 playout-throughput core claim.
- Added a benchmark-mode Table 1 subset harness for paired HRG->RG and RBG->RG generated reasoners; a compute job is needed before claiming `core_claim`.

### [2026-05-31 19:08] - core_claim_plus
- Job `2049a1f1-1ef` completed the paired Table 1 subset benchmark for Connect Four, Breakthrough, and Yavalath.
- HRG->RG generated reasoners averaged 560407.0 playouts/s versus 171690.333 playouts/s for matched RBG->RG generated reasoners, a 4.051x within-job speedup.
- The benchmark completed all three matched games and `python3 validate.py --compare` passed.
- Together with the previously validated 14-game structural optimization run, the environment supports the core Section 4 throughput claim plus an additional optimizer-size claim.

### [2026-05-31 19:29] - core_claim_plus
- Fixed the top-level evaluator to report the Table 1 generated-code and automaton-size advantage metrics declared in `reference.json`.
- Updated `scripts/run.sh` so submitted jobs regenerate method artifacts before scoring, avoiding stale gitignored outputs.
- Prepared a CPU rerun that expands the matched Table 1 subset from three to six paired HRG/RBG games.

### [2026-05-31 19:34] - core_claim_plus
- Final verification copied benchmark rule sources into tracked `data/games/` for from-scratch agents.
- Cleaned method-agnostic problem/evaluation/scoring docs so they describe the task and metrics without exposing implementation details.
- Re-ran standalone evaluators and `python3 validate.py --compare`; all checks passed.

### [2026-05-31 19:47] - core_claim_plus
- Local validation still passes for the committed three-game matched benchmark artifact and train/test slices.
- Prepared a CPU rerun with the existing entrypoint's broader six-game Table 1 matched benchmark configuration.
- Current milestone remains `core_claim_plus` until that expansion job returns with measured results.

### [2026-05-31 19:55] - core_claim_plus
- Final verification rechecked validation, method/evaluation separation, download URL reachability, train/test artifacts, and method-agnostic documentation.
- Added explicit notes for machine-independent substitute metrics in `scoring/reference.json`.
- No reproduction downgrade was needed; the validated gym baseline remains the committed three-game matched Table 1 subset plus the structural compactness experiment.

### [2026-11-11 22:50] - core_claim_plus (hardening, iteration 11)
- Rebuilt the gym so a method is a compiler that the evaluator executes on hidden rule files. The evaluator verifies each generated forward model against frozen ground truth, measures executed instructions per random playout against frozen RBG->RG / direct-translation models, and verifies submitted automata through its own rg2cpp. Nothing self-reported is scored.
- Held-out reference: 3.48x faster than RBG->RG (geomean; every game faster, worst 1.09x); 46.7% / 51.7% fewer automaton edges / nodes (paper 41 / 47); new translated-rules experiment 4.04x vs the direct RBG translation, with 70.8% / 75.4% reductions (paper 66 / 72). Train: 3.38x, 45.8 / 51.1, 4.05x.
- A genuine code-generation improvement scores higher (+1.4% main, +4.2% translated). Every red-team shortcut now fails or ties exactly. Details in HARDENING.md.

</details>


---

# Reproduction Milestones

**Current: core_claim_plus**

## Stop Justification
- Completed at milestone `core_claim_plus`.
