# Progress

## What Works

- Official source snapshots are staged in `method/rg` and `method/rgcompiler`.
- Rust crates for the interpreter are cached under `data/downloads/rg_cargo_vendor` and linked from `method/rg/interpreter_rust/vendor`, allowing offline builds on compute nodes.
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

## Deviations from Paper

The paper's primary table reports playouts per second. This workspace records raw timing in method logs but does not score wall-clock speed, because hardware differs across jobs. The scored reproduction uses the paper's reported HRG structural optimization claim: 47% fewer nodes and 41% fewer edges after optimization, with generated playout completion as a correctness constraint.
