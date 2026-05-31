# Progress

## What Works

- Official source snapshots are staged in `method/rg` and `method/rgcompiler`.
- The container build prefetches the Rust crates needed by the native Regular Games CLI, allowing offline builds on compute nodes.
- `method/run_experiments.py` drives the paper's actual pipeline: HRG parsing, RG optimization, `rg2cpp` C++ generation, C++ compilation, and deterministic playout checks.
- The method wrapper now also drives the official benchmark-mode playout path for a Table 1 subset, comparing paired HRG->RG and RBG->RG generated reasoners.
- `eval/evaluate_results.py` scores only method-produced artifacts and does not import from `method/`.
- The C++ reasoner pipeline now compiles and completes deterministic playouts for both no-optimization and optimized variants.
- `scripts/run.sh` now regenerates method artifacts before evaluation, so compute jobs do not depend on gitignored `method/outputs/` from a previous run.
- Final verification confirmed the evaluator works standalone, committed portable benchmark rule sources under `data/games/`, and cleaned from-scratch-facing documentation.

## Results

Job `a0586e53-f4a` validated the full reusable reproduction path. Across Connect4 and Breakthrough, the optimized HRG pipeline produced 44.854% fewer automaton nodes and 39.167% fewer automaton edges, close to the paper's reported 47% node and 41% edge reductions. Generated C++ line count also fell by 33.356%. Both the no-optimization baseline and optimized generated reasoners completed 200/200 playouts, so the correctness constraint is satisfied (`playout_completion_rate = 1.0`).

Job `2e7a31ea-181` expanded the same experiment to six HRG games: Connect4, Breakthrough, Hex, Yavalath, Tic-Tac-Toe, and Tic-Tac-Die. The optimized pipeline averaged 49.427% fewer automaton nodes, 44.911% fewer automaton edges, and 39.283% fewer generated C++ lines, with `playout_completion_rate = 1.0` for every baseline and optimized reasoner. This supports `core_claim_plus`.

Job `b2caa90d-a53` expanded the same experiment to 14 HRG games. The optimized pipeline averaged 48.942% fewer automaton nodes, 44.325% fewer automaton edges, and 39.930% fewer generated C++ lines. Every one of the 28 baseline/optimized generated reasoners completed 200/200 deterministic playouts, and `validate.py --compare` passed.

Job `2049a1f1-1ef` ran the new paired Table 1 subset benchmark on Connect Four, Breakthrough, and Yavalath using two 10-second benchmark repeats per game. The HRG->RG generated reasoners averaged 560407.0 playouts/s and 12964347.333 states/s. The matched RBG->RG generated reasoners averaged 171690.333 playouts/s and 4537365.333 states/s. The primary hardware-normalized score, within-job HRG/RBG playout speedup, was 4.051x versus the paper subset reference of 4.254x. All three paired benchmark games completed, and `python3 validate.py --compare` passed.

## Remaining

No required work remains for `core_claim_plus`. The reusable environment now scores both the Section 4 HRG-vs-RBG playout-throughput comparison on a matched three-game subset and the optimizer-size/correctness experiment on HRG games. The next submitted CPU job attempts to expand the matched Table 1 subset to six paired HRG/RBG games using the current `scripts/run.sh` entrypoint. Higher milestones beyond that would require extending the benchmark matrix toward all Table 1 games and packaging additional baselines that are not currently available in the official RG source tree, especially native RBG and Ludii.

## Issues

- Continuation audit found no `method/outputs/results.json`, no `scoring/scores.json`, and no returned job logs. The implementation is staged but has not yet demonstrated `method_runs`.
- Fixed a portability issue in `scripts/download.sh`: it now creates `tmp/` before downloading `rustup-init.sh` on a fresh checkout.
- Job `d7726f8b-004` built the container and reached `method/run_experiments.py`, but failed before running playouts. The wrapper passed a full relative path to `scripts/sims.py`, whose upstream parser expects a bare game filename, and passed translate flags in a form argparse treated as options. The wrapper now passes bare filenames, uses `-t=<flags>`, parses upstream fixed-work playout output, and prints captured command output on failures.
- Job `a9b0ccce-9e1` reached the official Rust interpreter build, then failed in offline Cargo resolution for a wasm-only panic-hook dependency. The reproduction path only needs the native CLI used by the HRG/RG optimizer and AST generator, so the upstream wrapper now builds the `cli` binary directly and wasm bindings/dependencies in the CLI crate are gated to `wasm32`. `scripts/download.sh` also verifies the vendored crate set before reusing it on internet-enabled setup runs.
- Job `e48b7a66-f6e` confirmed the compute checkout did not contain ignored Cargo vendor sources, failing next on `rand`. The repository hook correctly blocks committing dependency archives. A setup-script fetch did not populate the read-only overlay used by the next job. The first container-build prefetch attempt used `%files`, but the scheduler resolved that path outside the synced workspace and the image build failed before job submission. The next attempt used a synthetic manifest and the image built, but the runtime Cargo lock still required the wasm-only `console_error_panic_hook` crate. The container definition now fetches the official RG repository during image build and runs `cargo fetch --locked` against its real lockfile, which covers target-specific and yanked historical crates without copying host files into the image.
- Job `3e8551a2-cf4` built the image, compiled the official Rust CLI, translated HRG games to RG automata, and wrote method outputs. It still failed before valid playouts because `rg2cpp` was invoked with stale option `--simple-path`; an upstream script bug ignored that failure and tried to compile empty generated C++ files. The compiler wrapper now uses `--simple-path-compression`, checks the `rg2cpp` return value correctly, and evaluation now writes only metrics declared in `reference.json`.
- Job `773e609f-499` showed the flag fix was necessary but not sufficient. `rg2cpp` aborted on a nlohmann JSON assertion while reading SimpleApply pragmas. The current official RG interpreter writes typed pragma variables as `{"type": ...}`, while rgcompiler expected the older `type_` field. `PragmaSimpleApplyOperator` now accepts both spellings. `method/run_experiments.py` also marks runs without completed playouts as failed, so future jobs cannot pass validation with zero correctness-constraint scores.
- Job `552e1382-378` confirmed the SimpleApply schema bridge fixed `rg2cpp`. The smoke job completed four generated-reasoner runs with 20/20 playouts each and produced `scoring/scores.json` matching the declared scoring structure.
- Job `a0586e53-f4a` ran `scripts/reproduce.sh` end to end with the default 200 playouts. The job completed in about four minutes and `validate.py --compare` passed all scoring and separation checks.
- Continuation audit restored confidence in `core_claim`: `method/run_experiments.py` uses the official HRG/RG optimizer, `rg2cpp` compiler, generated C++ reasoner compilation, and fixed playout checker; `eval/evaluate_results.py` reads only method-produced artifacts and `validate.py --compare` passes.
- Job `2e7a31ea-181` completed the six-game expansion in about 12 minutes on CPU and `validate.py --compare` passed.
- Job `279135c0-94d` was cancelled after 20 minutes because no method progress had appeared in stdout. The cause was the experiment wrapper buffering subprocess output until each command completed, making normal rebuild/compile work indistinguishable from a hang during scheduler progress checks. `method/run_experiments.py` now streams subprocess output and emits per-game/per-variant progress lines.
- Job `b2caa90d-a53` reran the broader 14-game subset with streamed progress and completed in about 26 minutes on CPU.
- Follow-up audit found the existing scoring covered the Section 3.3 structural optimization claim, not the Section 4 Table 1 playout-throughput core claim. Added `table1_playout_throughput_subset` to `reference.json`, `TARGETS.md`, and the evaluator, using within-job HRG/RBG throughput ratio as the primary benefit metric and benchmark completion as the constraint.
- Job `2049a1f1-1ef` completed the Table 1 subset benchmark and validation on a CPU test node. This restored the milestone beyond the reset audit level: the core throughput claim is now measured by the evaluator rather than only documented as pending.
- Continuation audit found that the top-level evaluator omitted the Table 1 generated-code and automaton-size advantage metrics even though `reference.json` declared them. `eval/evaluate_results.py` now computes those metrics, `TARGETS.md` is aligned with the hardware-independent primary metric, `scripts/run.sh` regenerates artifacts before scoring, and `scripts/download.sh` pins fallback upstream clones to verified commits.
- Final verification found two gym-readiness issues: the benchmark rule sources were only reachable through the paper method checkout, and several from-scratch-facing docs used implementation-specific wording. The selected rule files are now tracked in `data/games/`, and `briefing/evaluation.md`, `scoring/EXPERIMENTS.md`, `scoring/TARGETS.md`, `scoring/CONSTRAINTS.md`, and `scoring/DIRECTION.md` have been tightened.

## Deviations from Paper

The paper's primary table reports playouts per second from three 1-minute runs. The reproduced Table 1 subset used two 10-second benchmark repeats in the submitted smoke/test job and scores the within-job HRG/RBG speedup ratio rather than raw wall-clock rates. Ludii and native RBG baselines are not packaged; the implemented baseline is the paper's RBG->RG translation path, which is available in the official RG source tree.

The final committed `scores.json` is regenerated from the current method artifact and covers a representative three-game matched subset plus the structural compactness subset in that artifact. Earlier job logs document a broader 14-game structural run, but the gym baseline is the committed score artifact.
