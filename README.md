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

The paper evaluates generated game reasoners primarily by flat Monte Carlo random playout throughput: Table 1 reports playouts per second, averaged over three one-minute runs, for HRG->RG, RBG->RG, native RBG, and Ludii where available. This reproduction includes a matched Table 1 subset that runs the official benchmark-mode generated C++ reasoners for HRG->RG and RBG->RG. Because raw wall-clock speed is hardware dependent, the primary scored benefit is the within-job HRG/RBG throughput ratio; raw playout and state rates are retained as supporting metrics.

The reproduction also scores the paper's structural optimizer claim from Section 3.3: automaton node and edge reductions after optimization, plus fixed-work playout completion as a correctness constraint.

Evaluation reads method artifacts from `method/outputs/results.json`; it does not regenerate games or import from `method/`. The reusable command is:

```bash
bash scripts/evaluate.sh method/outputs/results.json
```

The evaluator writes `scoring/scores.json`. For the throughput subset, RBG->RG is the baseline and HRG->RG is the proposed method. For the structural experiment, no-optimization translation is the baseline and the optimized HRG-to-RG-to-C++ pipeline is the proposed method. A valid generated model must complete its playout workload, so compactness or speed alone is not sufficient.

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


---

# Reproduction Milestones

**Current: core_claim_plus**

## Stop Justification
- Completed at milestone `core_claim_plus`.
