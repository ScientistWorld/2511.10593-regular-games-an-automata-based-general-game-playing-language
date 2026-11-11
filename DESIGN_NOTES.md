> Superseded by HARDENING.md (iteration 11): the evaluator, metrics and scripts described below were replaced.

# Design Notes

## Checks Performed

- Read `scripts/evaluate_train.sh` and `scripts/evaluate_test.sh` side by side. The test script now calls `eval/test/evaluate.py` and writes only `scoring/scores_test.json`.
- Read both train/test evaluators for cross-imports and method coupling. They read method-produced `method/outputs/results.json` artifacts and do not import from `method/` or from each other.
- Checked `scoring/reference.json` for paper-agreement metrics. No scored metric has a "match the paper" floor.
- Checked that `scoring/scores_train.json` and `scoring/scores_test.json` are absent.
- Ran static-only checks: `bash -n` on both evaluate scripts, `py_compile` on the train/test evaluators, and JSON parsing for `scoring/reference.json`.

## Changes Made

- Fixed a self-contained test-slice problem: `eval/test/evaluate.py` no longer requires `scoring/scores_train.json` to decide which methods to score. It enumerates method entries directly from the submitted artifact and emits zero-valued held-out scores for methods without test rows.
- Strengthened the split against game-specific shortcuts. `table1_playout_throughput_subset` now uses a game split: visible train scores Breakthrough and Yavalath, while held-out test scores Connect Four. The previous repeat-parity split exposed the same games in both slices and mainly tested timing noise.
- Added explicit score metadata markers: train outputs `slice: train`; test outputs `slice: test`.
- Added machine-independent Table 1 metrics:
  - `generated_cpp_line_advantage_vs_rbg_pct`
  - `automaton_edge_advantage_vs_rbg_pct`
- Updated `scoring/reference.json` so nonzero Table 1 scoring emphasizes generated-code and automaton-size advantages instead of hardware-sensitive throughput. Raw throughput fields remain with coefficient `0.0` as diagnostics.
- Added required `description` fields for all reference metrics.

## Runtime Concerns For Runner Iteration

- The held-out Table 1 slice is only one game (`connect4`) because the current default benchmark artifact covers three matched games. This is intentional for anti-shortcut pressure but small; if future runs expand `BENCHMARK_GAMES`, the split should be expanded while keeping test games hidden.
- `scoring/TARGETS.md` still describes `speedup_vs_rbg_rg` as the primary Table 1 benefit metric. I did not edit it because this iteration's allowed edit set excluded `scoring/TARGETS.md`; the scoring schema now treats throughput as diagnostic and uses generated-code compactness as the scored machine-independent proxy.
- The evaluators assume method artifacts retain the existing row schema: `experiment`, `method`, `game`, `generated_cpp_lines`, `automaton_edges`, playout completion fields, and optional throughput fields.

## Runner Iteration Results

- Job `7e3746a0-4b8` ran `scripts/evaluate_train.sh` and `scripts/evaluate_test.sh` successfully on CPU against `method/outputs/results.json`.
- Both `scoring/scores_train.json` and `scoring/scores_test.json` contain complete numeric values for all expected method identifiers; no `null` scores were emitted.
- Train/test values are distinct rather than byte-identical. Structural optimization reductions are close across slices; Table 1 generated-code and automaton advantages are higher on held-out `connect4`, reflecting the intentionally small one-game test slice.
- After observing the run, `games_completed` was changed to diagnostic-only because train and test contain different numbers of games, making raw counts non-comparable as a scored metric.
