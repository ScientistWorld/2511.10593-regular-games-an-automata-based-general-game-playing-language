# Hardening report (iteration 11)

## Summary

The previous gym scored numbers that the method wrote about itself (automaton
sizes, generated C++ line counts, completion flags) and kept the baselines and
the playout checker inside the method's own outputs. Every fabricated,
padded, minified or empty submission tied or beat the reference, and the
paper's actual objective (forward-model speed, Table 1) had zero weight.

The rebuilt gym (`eval/train`, `eval/test`, `scripts/evaluate_{train,test}.sh`)
**treats a method as a compiler and executes it**:

* A method is any `method/compilers/<name>/compile.sh`. All of them on disk are
  scored, and a method that fails gets the worst value of every scored metric in
  every experiment. The evaluator calls `compile.sh` on rule files: the
  held-out ones exist only in `eval/test/games` (unseen board-size variants of
  five Table 1 games). There is a 15 s cap per file, and the method's process
  group is killed afterwards.
* The evaluator builds the produced C++ forward model with **its own driver
  and fixed flags** (`-O3 -flto -march=x86-64-v2`). It rejects I/O, exit,
  process/thread control, inline asm, symbol interposition and backend
  pragmas/attributes, checked with a preprocessed-source scan plus an `nm`
  scan of the reasoner and of an I/O-free API probe.
* It **verifies** each model against ground truth from a frozen direct
  translation:
  - exact game-tree counts to a fixed depth;
  - the mean playout length, branching and per-player score over a fixed
    playout workload, within 6 standard errors.
* It **measures** that workload (fixed count, hidden seed) as executed
  instructions under valgrind. This is deterministic and machine-independent,
  so no score depends on wall-clock time. It then compares against frozen
  comparison models measured in the same run.
* It **recompiles the submitted RG automaton** (`game.json`) with an
  evaluator-owned copy of rg2cpp (pragmas stripped) and verifies it the same
  way before its node and edge counts count.
* Everything on the other side of a comparison is frozen in `eval/<slice>/`:
  the baselines `direct` (HRG→RG, no transformations), `rbg` (RBG→RG,
  optimized) and `rbg_direct`, plus ground truth, depths, playout counts and
  seeds.

Three experiments (`scoring/reference.json`):

| Experiment | Weight | Scored metrics (coefficient) |
|---|---:|---|
| `forward_model_efficiency` (Table 1) | 0.60 | `speedup_vs_rbg_translation` geomean (1.0, primary), `worst_game_speedup_vs_rbg_translation` (0.5), `verified_game_fraction` (1.0, constraint) |
| `automaton_optimization` (Sec. 3.3) | 0.15 | edge (1.0) / node (0.8) reduction vs direct translation, `verified_automaton_fraction` (0.5) |
| `translated_rules_optimization` (new: where the paper falls short) | 0.25 | `speedup_vs_direct_rbg_translation` (1.0), RBG automaton edge (0.5, primary: paper's number) / node (0.3) reduction, `verified_rbg_game_fraction` (1.0) |

## Reference before and after (hidden test)

| | Before (old gym) | After |
|---|---|---|
| Scored | node/edge/C++-line reduction 51.14 / 43.27 / 36.20, completion 1; C++-line / edge advantage over RBG 43.75 / 49.57, completion 1 | **Efficiency:** speedup vs RBG→RG **3.4806** (geomean), worst game 1.0906, verified 1 (diagnostic: 3.0406 vs direct translation, all 5 games faster than RBG). **Automaton:** 46.69% fewer edges / 51.69% fewer nodes, verified 1. **Translated rules:** **4.0353×** vs direct RBG translation, 70.76% / 75.37% fewer edges / nodes, verified 1 |
| Train slice | — | 3.3835 / 1.0502; 45.81 / 51.12; 4.0462 / 70.25 / 74.73 |

The reproduction now shows the paper's claim in the paper's direction, on the
paper's own quantity:
* HRG→RG beats RBG→RG on every held-out and every train game.
* The train per-game ratios sit next to Table 1's:

  | Game | Train | Table 1 |
  |---|---:|---:|
  | Connect Four | 11.9 | 10.6 |
  | Hex | 11.0 | 9.6 |
  | Reversi | 19.4 | 12.6 |
  | Yavalath | 1.16 | 1.15 |
  | Gomoku | 1.05 | 1.09 |
  | Knightthrough | 1.52 | 1.76 |
  | Fox and Hounds | 1.59 | 1.38 |
  | Breakthrough | 2.29 | 1.04 |

* Automaton reductions are 46–47% edges / 51% nodes (paper: 41/47) for HRG,
  and 70–71% / 75% (paper: 66/72) for RBG.

The reference method is unchanged: the official HRG→RG translation, all
optimizer passes and pragma inference, `adjust_AST`, and rg2cpp with upstream
default options (`method/compilers/hrg_rg_optimized`, `method/toolchain`).
`scoring/scores_test.json` and `scoring/scores_train.json` hold only the
reference and the frozen baselines.

## Do better results score higher? (variants, hidden test, same run)

Rank Δ uses the gym's rule: weight × |coef| × Δ / cohort population std. The
cohort is all 18 runs in `redteam/hardening/results/test_probes.json`; see
`redteam/hardening/rank.py` and `test_probes_rank.txt`.

| Variant (`redteam/hardening/methods/`) | Before (old gym) | After: eff. geomean / worst | after: automaton E/N % | after: translated speedup | Rank Δ |
|---|---|---|---|---|---:|
| reference | 0 | 3.4806 / 1.0906 | 46.69 / 51.69 | 4.0353 | 0 |
| `probe_flatten_all_inputs` (force-inline generated entry points, gated ≤4000 lines) | — | **3.5287 / 1.1013** | 46.69 / 51.69 | **4.2045** | **+0.046** |
| `better_flatten_translated_rules` (same, only for translated .rbg inputs) | — | 3.4806 / 1.0906 | 46.69 / 51.69 | **4.2045** | **+0.022** |
| `better_inline_unique_states` (rg2cpp `--gccinline 2`) | — | 3.3827 / 1.0906 | same | 3.9016 | −0.054 |
| `better_two_pass_optimizer` (optimizer re-run on its own RG output) | — | 1.2968 / 0.2074 | **50.09 / 55.45** | 4.0353 | −1.345 |
| `weaker_no_optimizations` (no automaton transformations) | −4.92 | 1.1447 / 0.5061 | 0 / 0 | 1.0000 | −1.986 |
| `better_path_compression` (rg2cpp `--simple-path-compression 1`, fallback on crash) | **+0.24 (rewarded)** | failed | failed | failed | −5.330 |

* **Genuinely better scores higher.** Forcing full inlining of the generated
  automaton walk is faster on 3 of 5 hidden HRG games and on all translated
  games. It beats the reference by +1.4% (main geomean) and +4.2% (translated
  rules). A genuinely worse code generator (`--gccinline 2`) and the
  no-optimizer translation score lower.
* **The old gym's "better" variant was a correctness bug.** rg2cpp's
  experimental simple-path compression crashes on the Hex and Fox and Hounds
  automata. On translated Hex 9×9 it silently generates a model with the
  wrong game tree (4,095,360 leaves at depth 3 instead of 511,920). The old
  gym rewarded it for shorter C++; the new evaluator fails it.
* **The size–speed trade-off is real.** The two-pass optimizer yields smaller
  verified automata but 1.3–7× slower code. It removes skip edges that keep
  automaton states unique, so rg2cpp must cache states. The weights make
  efficiency dominate.
* **Weaker variant not rerun.** `weaker_no_pragmas` (optimizer without
  pragma inference) measured 0.006× vs RBG in a local two-game run. It was
  not rerun in the job: a 160× slower model takes hours under valgrind on
  1 CPU. The evaluator now fails any model more than 30× slower (wall clock,
  pass/fail only) than the frozen direct translation before counting.

**Seed noise** (hidden test, reference, default seed vs seed 101; job 1):

| Run | Default seed | Seed 101 |
|---|---:|---:|
| Reference, speedup vs RBG | 3.4806 | 3.4776 |
| Reference, worst game | 1.0906 | 1.0890 |
| Reference − `--gccinline 2` gap | 0.0979 | 0.0977 |

So seed noise is about 0.1%, an order of magnitude below the better
variants' gains. Methods that keep the reference's move order produce
identical trajectories, so the comparisons are paired. SEED101_PLACEHOLDER

**Train vs test** (same thing at comparable difficulty): reference
3.38 / 3.48 (efficiency), 45.8 / 46.7 (edges), 4.05 / 4.04 (translated).
TRAIN_PLACEHOLDER

## Shortcuts: fix, score before and after (hidden test)

"Before" is the red-team result on the old gym; "after" is the unchanged
hidden test (`redteam/hardening/results/test_probes.json`).

| Shortcut | Before | Fix | After |
|---|---|---|---|
| Fabricated results (self-reported 100% / perfect numbers) | dominates R, +3.48 | Nothing reported is read. Every number is recomputed by compiling, verifying and executing the model | `shortcut_fabricated_results`: fails (stub model does not build), worst everywhere, −5.33 |
| Impossible values (negative sizes, completion 2) | +4.48 / +8.40 | Values are computed by the evaluator; non-finite/non-positive costs fail; reductions floored at −100 | no surface left (covered by the fabricated probe) |
| Failed compact (empty C++ + failure flag) | +2.48 pairwise | Any build/verification failure gives the worst value of every metric of every experiment | fails, −5.33 (same mechanism as `shortcut_empty_submission`) |
| Baseline padding | +1.44 | Baselines are frozen C++ in `eval/<slice>/baselines`, built and measured before any method code runs | no surface left (candidate never supplies baselines); tampering with evaluator tools is caught (below) |
| Minified source | +1.44 | Line counts no longer scored; instructions are formatting-invariant | `shortcut_minified_source`: exact tie (0.000) — no gain |
| Cached results (replay a stored artifact) | tie | Hidden rule files only in `eval/test`; the evaluator runs the compiler on them | `shortcut_cached_train_output`: fails (game tree differs), −5.33 |
| Fixed driver (replace the checker) | tie | Driver and API probe sources are evaluator-owned, held in memory, written fresh per build. The reasoner may not reference exit/IO/... nor define symbols outside `reasoner::` | `shortcut_process_hijack` (static initializer prints fake driver output and exits): rejected, −5.33 |
| Empty submission | tie (missing skipped) | Worst value in every scored metric; "no method on disk" also produces a worst-valued entry | `shortcut_empty_submission`: −5.33 |
| Unlisted method | tie | Methods are enumerated from disk | `shortcut_failing_method`: scored, worst, −5.33 |
| Null values | fails | n/a (nothing read) | — |
| Slow backend (-O0) | tie | Backend fixed by the evaluator; `#pragma GCC optimize/target` and `optimize/target` attributes rejected; slower code scores lower | `shortcut_backend_override`: rejected, −5.33 |
| New: fake automaton (report a tiny automaton of another game) | — | Submitted automaton recompiled by reference rg2cpp and verified | fails, −5.33 |
| New: tamper with the evaluator's reference rg2cpp during compile | — | rg2cpp hash checked before each use; tamper fails the method and rg2cpp is rebuilt | `shortcut_tamper_evaluator`: fails, −5.33 |
| New: private per-instance search (compile/time several codegen configs per hidden game) | — | Compile cap 15 s per file (reference: 0.2–2.3 s) | `shortcut_private_autotune`: cannot finish inside the cap, fails, −5.33. On a 2-game local run with a 50 s budget it only matched the reference |

**Brute force** (enumerate reachable states into a lookup table): the red team
could not complete Connect Four within 50k states. The hidden games are larger
(Hex 9×9, Gomoku 13×13, ...). Any precomputation runs inside the measured
process and is counted.

## Shortcuts left (and why)

* **Decoupled automaton reporting.** `game.json` is verified independently of
  the C++. A method can therefore report a smaller verified automaton (e.g.
  the two-pass optimizer's) while compiling its C++ from a different one.
  Computed from the measured components (reference code + two-pass
  automata), this ranks **+0.014**, below both genuine better variants
  (+0.022, +0.046). The automaton it reports is real and verified, so this is
  a reporting decoupling, not a fake. Closing it would require generating the
  C++ from the submitted automaton with a fixed code generator, which would
  remove code generation from the research space. The grader can check that
  `game.json` is the automaton compiled. (The probe actually run,
  `probe_hybrid_two_pass_automaton`, used the slower `--gccinline 2` code and
  ranked −0.040.)
* **Process escape with `setsid`.** The method's process group is killed
  after each compile. A process that detaches into a new session survives;
  the hidden test runs in a fresh container. Evaluator inputs it could touch
  are protected: the driver is held in memory, rg2cpp is hash-checked, and
  baselines are measured before methods run.
* **Game-specific code.** Hidden games are unseen variants, but a method
  could try to recognise a family (e.g. "connect-N") and emit a hand-written
  engine. DIRECTION/CONSTRAINTS forbid it; the grader checks.
* **Denylist scans.** The source/symbol scans block the obvious hijacks
  (verified by the probes), not every obfuscation.
* **Wall-clock guards.** The 15 s compile cap and the 30× slowdown cap are
  pass/fail guards, not scores, and depend on the machine. The margins are
  ≥7× and ≥30× for the reference.

## Headroom

* No scored benefit metric of the reference is at a bound:
  - speedups are unbounded;
  - reductions are 46.7 / 51.7 / 70.8 / 75.4, with a ceiling of 100.
* The three `verified_*` fractions are constraints and equal 1 for every
  working method by design.
* The paper's main experiment had no simple variant above the reference
  among rg2cpp options, all 21 single-pass ablations and the translator's
  expansion/normalisation flags (all neutral or slower; one,
  `--expand-assignment-any`, produced a wrong Breakthrough model, which the
  verification rejects). We therefore added `translated_rules_optimization`.
  This is the paper's own documented shortfall (Table 1: RBG→RG Connect
  Four, Hex and Reversi are 7–9× slower than native RBG; the paper says
  translated games beat RBG only "in part"). The reference and the direct
  baseline were run on it (4.04× vs 1.0).
* A code-generation variant beats the reference on both efficiency
  experiments (+1.4% main, +4.2% translated), above seed noise (~0.1%), and
  the old gym's metrics could not see it.
* Simple baselines sit clearly below the reference on every experiment:
  - direct translation: 1.14× vs RBG, against the reference's 3.48×;
  - direct RBG translation: 1.0×, against 4.04×.

## Weights

* Old: structure 0.35 / Table-1 proxy 0.65.
* New: efficiency 0.60 / automaton 0.15 / translated rules 0.25.
  - Efficiency is the paper's headline claim (abstract, Section 4,
    conclusion).
  - Automaton size is supporting analysis (Section 3.3). Smaller is not
    automatically faster (two-pass result), so it gets a small weight.
  - The translated-rules experiment is where the paper's own data shows
    headroom.
* `speedup_vs_direct_translation` has coefficient 0: per game it equals the
  primary metric times a fixed evaluator constant, so scoring both would
  double-count. The worst-game speedup (the paper claims a win on *every*
  game) replaces it.

## Could not fix / caveats (stated plainly)

* Instruction counts are a machine-independent proxy for the paper's
  playouts/s:
  - they ignore cache/memory effects;
  - the toolchain is the container's g++ 12 with fixed `-march=x86-64-v2`,
    not the paper's g++ 14 `-march=native`;
  - native RBG and Ludii are not part of the gym.
* The translated-rules experiment excludes Reversi: its direct RBG
  translation is a 49k-line model, too heavy for the hidden test.
* The automaton check compiles the submitted automaton without pragmas
  (wrong pragmas cannot cause false failures), so it uses a shallower tree
  depth and at most 2,000 playouts per game.
* Compute: jobs ran on 1 CPU and were preempted repeatedly (job 1's worker
  died; jobs 3–5 were drained). The final job script resumes from partial
  outputs.
  - The hidden test takes about 4 min (reference + baselines) on 1 CPU.
  - Job 1's probe results were invalidated by a 64 MB `/tmp`. The evaluator
    now keeps scratch in `tmp/eval_work` and deletes it per method.
* Job evidence: `redteam/hardening/results/` (job-1 files prefixed `job1_`).
