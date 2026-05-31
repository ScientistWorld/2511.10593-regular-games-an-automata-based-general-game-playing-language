# Overview

**Paper ID:** 2511.10593
**Title:** Regular Games - an Automata-Based General Game Playing Language
**Domain:** General game playing / formal game languages / compiler optimization

Regular Games proposes an automata-based rule language and compiler for general game playing. The core claim is that game rules can be translated, optimized, and compiled into compact generated forward models that run legal game simulations efficiently.

This workspace packages the official RG interpreter and RGcompiler sources, vendors Rust dependencies for offline compute nodes, and provides a reproducible harness for HRG game optimization plus generated C++ playout checks.

---

# Problem Definition

The task is to represent finite turn-based games, including games with chance and imperfect information, in a machine-readable rule language and produce a reusable forward model. A forward model must expose the current player, legal moves, state transitions, terminal detection, and scores without relying on game-specific handwritten code.

Success is measured by whether the generated model stays compact enough to analyze and compile while still executing legal playouts from the original game rules. The problem definition is method-agnostic: any future solution may use a different implementation, but it must consume the same game-rule inputs and produce artifacts that `scripts/evaluate.sh` can score.

---

# Paper's Method

The paper introduces Regular Games (RG), a low-level automata language for finite games, and High-Level Regular Games (HRG), a more convenient source language. HRG and existing rule languages are translated into RG automata. The automata are then validated, optimized through static transformation passes, and compiled into C++ forward models.

The reproduced method uses the authors' official pipeline:

1. Parse HRG game descriptions.
2. Translate them into RG automata.
3. Run the paper's optimizer passes, including skip-edge compaction, assignment and comparison simplifications, reachability/tag simplifications, and exclusive-edge joins.
4. Compile the optimized automaton with `rg2cpp` into a C++ reasoner exposing legal-move generation, move application, terminal checks, current player, and scores.
5. Run deterministic random playouts through the generated reasoner as a correctness check.

The reproduction keeps the paper's computation intact but scores structural metrics instead of wall-clock throughput.

---

# Evaluation

The paper evaluates generated game reasoners primarily by random playout throughput. Because wall-clock speed is hardware dependent, this reproduction scores machine-independent proxies from the same pipeline: automaton node and edge reductions, generated C++ size reductions, and fixed-work playout completion.

Evaluation reads method artifacts from `method/outputs/results.json`; it does not regenerate games or import from `method/`. The reusable command is:

```bash
bash scripts/evaluate.sh method/outputs/results.json
```

The evaluator writes `scoring/scores.json`. For the core experiment, the no-optimization translation is the baseline and the optimized HRG-to-RG-to-C++ pipeline is the proposed method. A valid optimized model must complete the deterministic fixed playout count, so compactness alone is not sufficient.

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


---

# Reproduction Milestones

**Current: core_claim**

## Stop Justification
- Completed at milestone `core_claim`.
