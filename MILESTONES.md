# Reproduction Milestones

**Current: core_claim_plus**

## Progress Log

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

## Stop Justification
- Completed at milestone `core_claim_plus`.
