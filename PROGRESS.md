# Progress

## What Works

- Official source snapshots are staged in `method/rg` and `method/rgcompiler`.
- The container build prefetches the Rust crates needed by the native Regular Games CLI, allowing offline builds on compute nodes.
- `method/run_experiments.py` drives the paper's actual pipeline: HRG parsing, RG optimization, `rg2cpp` C++ generation, C++ compilation, and deterministic playout checks.
- `eval/evaluate_results.py` scores only method-produced artifacts and does not import from `method/`.

## Results

No compute job results have returned yet. The next submitted CPU job will build the compiler and produce `scoring/scores.json`.

## Remaining

- Run the first smoke job.
- If the pipeline succeeds, compare reproduced structural reductions with the paper and raise the milestone to `method_runs` or `core_claim` depending on the scores.

## Issues

- Continuation audit found no `method/outputs/results.json`, no `scoring/scores.json`, and no returned job logs. The implementation is staged but has not yet demonstrated `method_runs`.
- Fixed a portability issue in `scripts/download.sh`: it now creates `tmp/` before downloading `rustup-init.sh` on a fresh checkout.
- Job `d7726f8b-004` built the container and reached `method/run_experiments.py`, but failed before running playouts. The wrapper passed a full relative path to `scripts/sims.py`, whose upstream parser expects a bare game filename, and passed translate flags in a form argparse treated as options. The wrapper now passes bare filenames, uses `-t=<flags>`, parses upstream fixed-work playout output, and prints captured command output on failures.
- Job `a9b0ccce-9e1` reached the official Rust interpreter build, then failed in offline Cargo resolution for a wasm-only panic-hook dependency. The reproduction path only needs the native CLI used by the HRG/RG optimizer and AST generator, so the upstream wrapper now builds the `cli` binary directly and wasm bindings/dependencies in the CLI crate are gated to `wasm32`. `scripts/download.sh` also verifies the vendored crate set before reusing it on internet-enabled setup runs.
- Job `e48b7a66-f6e` confirmed the compute checkout did not contain ignored Cargo vendor sources, failing next on `rand`. The repository hook correctly blocks committing dependency archives. A setup-script fetch did not populate the read-only overlay used by the next job. The first container-build prefetch attempt used `%files`, but the scheduler resolved that path outside the synced workspace and the image build failed before job submission. The container definition now avoids `%files` and instead creates a temporary Cargo manifest during `%post` to prefetch the native Regular Games CLI crate dependencies into `/usr/local/cargo`.

## Deviations from Paper

The paper's primary table reports playouts per second. This workspace records raw timing in method logs but does not score wall-clock speed, because hardware differs across jobs. The scored reproduction uses the paper's reported HRG structural optimization claim: 47% fewer nodes and 41% fewer edges after optimization, with generated playout completion as a correctness constraint.
