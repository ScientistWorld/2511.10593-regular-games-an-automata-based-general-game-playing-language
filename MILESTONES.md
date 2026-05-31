# Reproduction Milestones

**Current: none**

## Progress Log

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

## Stop Justification
