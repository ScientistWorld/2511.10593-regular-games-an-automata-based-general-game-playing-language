# Progress

## What Works

- Official source snapshots are staged in `method/rg` and `method/rgcompiler`.
- The container build prefetches the Rust crates needed by the native Regular Games CLI, allowing offline builds on compute nodes.
- `method/run_experiments.py` drives the paper's actual pipeline: HRG parsing, RG optimization, `rg2cpp` C++ generation, C++ compilation, and deterministic playout checks.
- `eval/evaluate_results.py` scores only method-produced artifacts and does not import from `method/`.
- The C++ reasoner pipeline now compiles and completes deterministic playouts for both no-optimization and optimized variants.

## Results

Job `552e1382-378` reached `core_claim`. Across Connect4 and Breakthrough, the optimized HRG pipeline produced 44.854% fewer automaton nodes and 39.167% fewer automaton edges, close to the paper's reported 47% node and 41% edge reductions. Generated C++ line count also fell by 33.356%. Both the no-optimization baseline and optimized generated reasoners completed all requested playouts, so the correctness constraint is satisfied (`playout_completion_rate = 1.0`).

## Remaining

- Run the reusable end-to-end `scripts/reproduce.sh` path with its default 200 playouts as final packaging validation.
- If that passes, no additional work is required for the core gym; further expansion would add more HRG games to the same experiment.

## Issues

- Continuation audit found no `method/outputs/results.json`, no `scoring/scores.json`, and no returned job logs. The implementation is staged but has not yet demonstrated `method_runs`.
- Fixed a portability issue in `scripts/download.sh`: it now creates `tmp/` before downloading `rustup-init.sh` on a fresh checkout.
- Job `d7726f8b-004` built the container and reached `method/run_experiments.py`, but failed before running playouts. The wrapper passed a full relative path to `scripts/sims.py`, whose upstream parser expects a bare game filename, and passed translate flags in a form argparse treated as options. The wrapper now passes bare filenames, uses `-t=<flags>`, parses upstream fixed-work playout output, and prints captured command output on failures.
- Job `a9b0ccce-9e1` reached the official Rust interpreter build, then failed in offline Cargo resolution for a wasm-only panic-hook dependency. The reproduction path only needs the native CLI used by the HRG/RG optimizer and AST generator, so the upstream wrapper now builds the `cli` binary directly and wasm bindings/dependencies in the CLI crate are gated to `wasm32`. `scripts/download.sh` also verifies the vendored crate set before reusing it on internet-enabled setup runs.
- Job `e48b7a66-f6e` confirmed the compute checkout did not contain ignored Cargo vendor sources, failing next on `rand`. The repository hook correctly blocks committing dependency archives. A setup-script fetch did not populate the read-only overlay used by the next job. The first container-build prefetch attempt used `%files`, but the scheduler resolved that path outside the synced workspace and the image build failed before job submission. The next attempt used a synthetic manifest and the image built, but the runtime Cargo lock still required the wasm-only `console_error_panic_hook` crate. The container definition now fetches the official RG repository during image build and runs `cargo fetch --locked` against its real lockfile, which covers target-specific and yanked historical crates without copying host files into the image.
- Job `3e8551a2-cf4` built the image, compiled the official Rust CLI, translated HRG games to RG automata, and wrote method outputs. It still failed before valid playouts because `rg2cpp` was invoked with stale option `--simple-path`; an upstream script bug ignored that failure and tried to compile empty generated C++ files. The compiler wrapper now uses `--simple-path-compression`, checks the `rg2cpp` return value correctly, and evaluation now writes only metrics declared in `reference.json`.
- Job `773e609f-499` showed the flag fix was necessary but not sufficient. `rg2cpp` aborted on a nlohmann JSON assertion while reading SimpleApply pragmas. The current official RG interpreter writes typed pragma variables as `{"type": ...}`, while rgcompiler expected the older `type_` field. `PragmaSimpleApplyOperator` now accepts both spellings. `method/run_experiments.py` also marks runs without completed playouts as failed, so future jobs cannot pass validation with zero correctness-constraint scores.
- Job `552e1382-378` confirmed the SimpleApply schema bridge fixed `rg2cpp`. The smoke job completed four generated-reasoner runs with 20/20 playouts each and produced `scoring/scores.json` matching the declared scoring structure.

## Deviations from Paper

The paper's primary table reports playouts per second. This workspace records raw timing in method logs but does not score wall-clock speed, because hardware differs across jobs. The scored reproduction uses the paper's reported HRG structural optimization claim: 47% fewer nodes and 41% fewer edges after optimization, with generated playout completion as a correctness constraint.
