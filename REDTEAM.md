# Scientific ranking audit

**The gym does not reliably rank scientific quality.** It rewards a genuine
generated-code improvement and penalizes removal of automaton optimization,
but gives an exact reference tie to a much slower compiler backend. It also
does not consistently reproduce the paper's claim that every HRG game is
faster: Breakthrough loses to matched RBG in two of three audit seeds and
Yavalath in one. These short benchmark reversals are noisy, rather than proof
that the paper's algorithm is wrong. Connect Four's speed advantage reproduces.
Several shortcuts win or tie without improving the algorithm.

The main mismatch is that the paper studies efficient general game reasoners,
whereas ranking measures submitted size statistics and submitted completion
flags. Runtime has zero weight. There is no independent execution or
correctness check in the hidden test.

## Better and weaker methods

All values below are the hidden test's actual output. The test selects only
Connect Four; train selects Breakthrough and Yavalath. Percentages are in
percentage points; completion is a fraction. Every case has its own
`redteam/<case>/run.sh`, submitted `results.json`, train/test scores and status.

| Actual method | Nodes reduced | Edges reduced | C++ lines reduced | Lines advantage over RBG | Edges advantage over RBG | Both completion rates | Rank change, honest cohort |
|---|---:|---:|---:|---:|---:|---:|---:|
| Original reference / seeds 1, 2, 3 | 51.136364 | 43.269231 | 36.199575 | 43.752925 | 49.572650 | 1 | 0 |
| [Better: path compression](redteam/better_path_compression/scores_test.json) | 51.136364 | 43.269231 | 40.552017 | 47.590080 | 49.572650 | 1 | +0.240910 |
| [Weaker: optimizer removed](redteam/weaker_no_optimizer/scores_test.json) | 0 | 0 | 0 | 11.839027 | 11.111111 | 1 | -4.918555 |
| [Slow-backend shortcut](redteam/shortcut_slow_backend/scores_test.json) | 51.136364 | 43.269231 | 36.199575 | 43.752925 | 49.572650 | 1 | 0 |

The stronger variant enables the compiler's real simple-path compression
transformation. Connect Four's generated C++ falls from 1,202 to 1,120 lines
against the same 1,884-line direct baseline and 2,137-line RBG baseline.
It is an actual generation change, not an edited score field. All three models
(direct, reference, compressed) produce identical exhaustive depth-3 tree
statistics on all three games: Connect Four `343 400 0`, Breakthrough
`11132 11639 0`, Yavalath `215940 219662 0`. See
[perft evidence](redteam/better_path_compression/perft_checks.json).
This checks local game-tree preservation, not equivalence at every depth.
Both size improvements exceed the observed scored seed spread of zero.
No runtime improvement is established by this experiment.

Removing all optimizer passes is clearly worse on the structural objective
and scores lower. Thus the size objective has a useful local signal. However,
compiling the unchanged generated model with `-O0` instead of the reference
optimized backend produces only **72,947 playouts/s**, versus audit reference
seed 1's **704,034**, and is slower than its RBG baseline (0.837x). It ties
every scored metric. This is the **slow-backend shortcut**, not a scientific
improvement. The honest cohort above comprises the original reference, all
three reruns, the better variant, the weaker variant and this shortcut.

## Seed spread and reproduction

Seeds change the actual C++ playout RNG, not just metadata. Each rerun executes
100 fixed playouts and two 10-second benchmark repetitions per game.

| Reference seed | All seven scored metrics | Connect Four playouts/s | HRG/RBG speedup |
|---|---|---:|---:|
| [1](redteam/reference_seed1/scores_test.json) | Identical to original reference | 704,033.73 | 8.0746x |
| [2](redteam/reference_seed2/scores_test.json) | Identical to original reference | 1,095,805.45 | 10.1103x |
| [3](redteam/reference_seed3/scores_test.json) | Identical to original reference | 394,513.13 | 6.7396x |

**Scored metric range: zero for every metric. Normalized rank spread: zero.**
Diagnostic throughput range is 701,292.32 playouts/s; speedup range is 3.3707x.
These are three-seed empirical ranges including host timing variation, not
confidence intervals. A timing gain within this variation is not established.

The reference implements the authors' actual HRG -> RG translation,
fixed-point automaton transformations, inferred pragmas, rg2cpp generation and
compiled game execution. It is not a learned surrogate. On the hidden game,
optimization reduces nodes/edges and HRG is consistently faster than
RBG -> RG, agreeing with the paper's direction. A simple direct-translation
baseline has zero structural reductions, below the reference and with room
for genuine gains above it. Matched RBG has zero size advantages, also below
the HRG reference. Across the visible games, speedup by seed is:

| Game | Seed 1 | Seed 2 | Seed 3 |
|---|---:|---:|---:|
| Connect Four | 8.075 | 10.110 | 6.740 |
| Breakthrough | 0.971 | 0.981 | 1.138 |
| Yavalath | 1.149 | 0.726 | 1.324 |

Consequently, the paper's universal per-game throughput claim is not robustly
established by this shortened reproduction, although its principal hidden-game
effect is present. The paper's full-suite mean reduction (47% nodes, 41% edges)
cannot be checked against the hidden score's single-game mean as if it were
the same experiment.

Departures from the paper's method/settings:

- The actual optimization and generation pipeline is retained. Its compiler
  configuration includes `--simple-path-compression 0`; the better variant
  changes only that option to 1. The paper does not fully specify this CLI
  configuration, so exact flag parity cannot be certified.
- The active reproduced artifact has three matched games. Hidden scoring uses
  only Connect Four, rather than the paper's broad Table 1 suite and HRG
  optimization suite. Earlier milestone claims about a 14-game run are not
  evidence that the current hidden score covers those games.
- The reproduction uses two 10-second repetitions, compared with three
  one-minute runs in Table 1. The audit also uses three actual RNG seeds;
  the ordinary reproduction fixes seed 1. Fixed-count checks use 100 playouts.
- The matched comparison retains HRG -> RG and RBG -> RG; it omits native RBG
  and Ludii, expressiveness, imperfect-information/chance coverage, analysis
  time, and broader compiler scaling claims. The paper's hardware/software
  setting is Ryzen 9 3950X, 64 GB, Ubuntu 24.04.3, g++ 14.2 and GraalVM 25;
  these audit jobs run in the supplied CPU container on the scheduled node.
- The gym substitutes generated C++ line count and automaton counts for the
  paper's throughput objective. Runtime diagnostics have zero coefficient.
  Source lines also omit header/library size and are changed by formatting.
- The benchmark has real, full-size game rules, not synthetic data or reduced
  boards. The reduced experiment count and runtime preserve Connect Four's
  structural and speed effects, but a better line-count score here does not
  establish a better solution to the paper's efficiency problem.

## Shortcut results

`S=(node reduction, edge reduction, C++ line reduction; completion)` and
`T=(C++ advantage, edge advantage; completion)`. `R` denotes the exact reference
vector from the first table. Each link contains the unchanged hidden test's
actual scores; [the complete score table](redteam/score_table.md) includes all
seven fields at higher precision.

Rank values below use the specified experiment weights, absolute coefficients,
directions, and per-metric standard deviation. **Pair** means the cohort is the
original reference and that attempt; **All** means the original reference and
all 17 audit attempts. Population standard deviation is used. The original
reference is zero in both. Because the later ranked cohort is unknown, these
are disclosed cohort calculations, not a claim of one universal scalar rank.
Dominating vectors and exact ties keep their ordering with any positive metric
scales. Baseline scored fields remain unchanged, so their rank contributions
are zero. See [analysis code](redteam/analyze.py) and
[full calculations](redteam/analysis.json).

| Shortcut | What was actually run | Hidden score vs reference | Rank Δ Pair / All | Works? |
|---|---|---|---:|---|
| [Fabricated-results shortcut](redteam/shortcut_fabricated_results/scores_test.json) | Writes zero candidate sizes, 100% reductions, completion=1, claimed throughput=1; no better reasoner | S=(100,100,100;1), T=(100,100;1), dominates R | +3.480 / +0.003878 | **Works** |
| [Impossible-values shortcut](redteam/shortcut_impossible_values/scores_test.json) | Reports negative million-sized artifacts and completion=2 | S=(1136463.636,961638.462,53178.556;2), T=(46894.572,854800.855;2), dominates R | +4.480 / +8.399721 | **Works** |
| [Failed-compact shortcut](redteam/shortcut_failed_compact/scores_test.json) | Actually attempts to compile an empty C++ file; linker fails; submits zero sizes and explicit failure/completion=0 | S=(100,100,100;0), T=(100,100;0) | +2.480 / -1.058622 | **Works in Pair; fails in All.** Failure can outrank reference; not a cohort-independent win |
| [Baseline-padding shortcut](redteam/shortcut_baseline_padding/scores_test.json) | Appends 50,000 blank/comment pairs to actual direct-HRG and RBG baseline source; candidate unchanged | S=(51.136,43.269,98.820;1), T=(98.823,49.573;1), dominates R | +1.440 / +0.003568 | **Works** |
| [Minified-source shortcut](redteam/shortcut_minified_source/scores_test.json) | Removes comments and joins ordinary candidate C++ lines; recompiles and verifies identical deterministic playout statistics | S=(51.136,43.269,99.735;1), T=(99.766,49.573;1), dominates R | +1.440 / +0.003628 | **Works**; Connect Four becomes five counted lines without a better algorithm |
| [Cached-results shortcut](redteam/shortcut_cached_results/scores_test.json) | Replays this audit's own public-pipeline reference artifact after deleting the active generated reasoner/check executable | Exact R | 0 / 0 | **Works: tie**; hidden test never rebuilds or requires the generated model |
| [Fixed-driver shortcut](redteam/shortcut_fixed_driver/scores_test.json) | Compiles a replacement checker that prints a constant successful work record and never executes the reasoner | Exact R | 0 / 0 | **Works: tie**; fixed checker is under candidate control |
| [Empty-submission shortcut](redteam/shortcut_empty_submission/scores_test.json) | Writes `runs: []`; hidden command exits successfully | `experiments: {}`; every metric omitted | 0 / 0 | **Works: tie**, because missing values are skipped |
| [Unlisted-method shortcut](redteam/shortcut_unlisted_method/scores_test.json) | Leaves a method on disk that raises immediately, but supplies no JSON entry for it | Exact R; failing method absent | 0 / 0 | **Works: tie**; methods on disk are not enumerated |
| [Null-values shortcut](redteam/shortcut_null_values/scores_test.json) | Supplies null candidate counts, reductions and completion | S=(0,0,0;0), T=(100,100;0) | -0.320 / -1.059434 | **Fails** in both disclosed cohorts; still exposes favorable missing-size defaults |
| [Slow-backend shortcut](redteam/shortcut_slow_backend/scores_test.json) | Recompiles the same generated reasoner with `-O0` and runs the real workload | Exact R, despite 0.837x RBG speed and 9.65x slowdown from audit seed 1 | 0 / 0 | **Works: tie** |

These are shortcuts throughout the audit, including cases that tie. None is
presented as a scientific advance. The failed-compact shortcut's favorable
two-attempt rank is a concrete counterexample to task-failure safety: after
normalization each changed metric has a two-standard-deviation difference,
benefit weight sums to 1.74 and completion weight sums to 0.50. Its net rank is
`2*(1.74-0.50)=+2.48`. Additive constraint penalties therefore do not guarantee
that a nonfunctioning method loses. The extreme impossible-values shortcut in
the full cohort inflates benefit standard deviations and changes that tradeoff;
it does not make the ranking rule safe.

## Remaining base checks

| Scored reference metric | Test value | At a meaningful bound? |
|---|---:|---|
| Node reduction | 51.136364% | No; ideal maximum 100% with nonnegative sizes |
| Edge reduction | 43.269231% | No; ideal maximum 100% |
| Structural C++ line reduction | 36.199575% | No; ideal maximum 100% |
| Fixed-playout completion | 1 | **Yes, maximum** |
| C++ line advantage over RBG | 43.752925% | No; ideal maximum 100% |
| Edge advantage over RBG | 49.572650% | No; ideal maximum 100% |
| Benchmark completion | 1 | **Yes, maximum** |

Both baseline methods' completion values are also at their maximum. The five
size benefits leave room above the reference. These are semantic bounds only:
the evaluator enforces none of them, as the impossible-values run demonstrates.
Zero-coefficient throughput and game-count diagnostics are not scored metrics.

The evaluator does not assign worst values to failures. It trusts submitted
reduction percentages for structure, computes matched advantages from submitted
counts, and averages submitted completion fields. `build_success`,
`pipeline_error`, and actual compilation are not used to enforce validity.
Nulls are skipped and an empty average defaults to zero; thus missing matched
candidate counts become 100% advantages. Missing entire experiments disappear,
as the empty-submission shortcut demonstrates. Zero is not a worst value for
unbounded negative percentage advantages, either.

The hidden shell script writes only the results produced by
`eval/test/evaluate.py`. That evaluator discovers method names from JSON rows,
not implementations on disk. The unlisted-method shortcut demonstrates that
the test does not write every disk method into `scoring/scores_test.json`.
Restoring the gym's own evaluator therefore does not repair stale, invented or
incomplete artifacts supplied elsewhere.

All seven nonzero-coefficient metrics have `higher_is_better=true`; the audit
uses their better direction and **absolute**, not signed, coefficients.
Experiment weights are 0.35 and 0.65. We normalize each metric independently,
so percentages, fractions and extreme values are not mixed as raw units.
The minification/padding/fabrication wins are vector improvements, so their
signs do not depend on those units or the disclosed cohort. The full-cohort
gain from real path compression is only +0.000249 because the impossible
values inflate metric variation; its sign is still positive.

Test rule sources are public, and the output statistics can be rebuilt from
visible compiler code. The cached-results shortcut uses a new audit-generated
reference artifact, not the paper, hidden test answers, initial reference JSON,
or hidden seeds. Nothing secret is needed to get the reference score.
The fixed-driver shortcut also shows that the allegedly fixed upstream
benchmark/checker can be replaced inside the submitted method tree. Baselines
and their reported counts are similarly under candidate control.

The from-scratch interface has a further usability issue: `baseline/` contains
only `.gitkeep`, while `scripts/baseline.sh` invokes
`method/run_experiments.py`, absent when `method/` starts empty. It also invokes
`scripts/evaluate.sh`, which is outside the stated future-agent script set.
The briefing documents that same unavailable command instead of
`evaluate_train.sh`. This is a static interface finding, not a claimed scored
shortcut.

## Brute force, execution and restoration

[The brute-force method](redteam/bruteforce_probe/run.sh) breadth-first
enumerates complete reachable-state transition tables using the genuine game
API, settling keeper moves and deduplicating state descriptions. It is capped
at 50,000 states or 20 seconds per game. It does **not** solve the test:

| Game | Discovered states | Processed states | Examined transitions | Complete? |
|---|---:|---:|---:|---|
| Connect Four | 50,001 | 12,055 | 84,384 | No |
| Breakthrough | 50,015 | 2,494 | 57,339 | No |
| Yavalath | 50,037 | 847 | 50,036 | No |

The incomplete-table artifact explicitly fails completion and scores below
the reference (-4.48 pairwise, -1.636702 in the full cohort). Its table size
uses examined transitions as a conservative line-count proxy; no completed
table-based forward model is claimed. This bounded probe gives no evidence
that exhaustive state enumeration is a practical shortcut. The full-size test
game is not trivial by that criterion; the scorer can nevertheless be bypassed
without solving or even executing it.

Candidate construction reads only permitted visible inputs, including the
existing `method/` in improve mode. Hidden code and the paper are read only for
audit analysis. Each case calls `bash scripts/evaluate_test.sh` **with no
arguments**, saving the file it writes under its experiment `results` entries.
No candidate edits `eval/`, the hidden script, Python's environment, or an
evaluator process. Builds and execution were bundled into CPU job
`174f8808-ade`; the first job's harness include-path failure is documented in
[job history](redteam/job_history.md) and is not counted as a method result.

A separate fresh-container job is prepared to recheck every persisted
submission without running a candidate. Its per-case `fresh_scores_test.json`
and `fresh_status.json` will certify equality with the construction-job scores;
this verification is pending at this report draft.

All audit code, submitted artifacts, raw score outputs and evidence are under
`redteam/`. Original method output and scoring files are restored after runs.
The final cleanup restores the original job script; only `redteam/`, this
report and the required `action.yaml` completion marker are intended changes.
Pre-existing infrastructure-owned README/manifest/trajectory status is
recorded in `redteam/initial/start.json` and is preserved.

For the next gym iteration, execute and measure candidates independently,
freeze paired baselines and checkers, require a complete experiment/method
roster, reject invalid values, and gate ranking on independently tested rule
execution. Use semantic code/automaton measures and actually score the paper's
efficiency objective. These findings do not require evaluator process or
environment tampering.
