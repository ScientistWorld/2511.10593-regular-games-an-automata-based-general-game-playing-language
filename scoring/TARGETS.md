# Scoring Targets

## hrg_optimization_structure

Optimize HRG game descriptions through the paper's Regular Games pipeline and preserve a working generated forward model.

Primary benefit metric:
- `automaton_edge_reduction_pct`: percentage reduction in automaton edges versus the same HRG game translated without optimizer passes.

Secondary benefit metrics:
- `automaton_node_reduction_pct`
- `generated_cpp_line_reduction_pct`

Constraint metric:
- `playout_completion_rate`: generated C++ reasoners must complete deterministic fixed-count random playouts. A compact model that cannot produce legal playouts is not a valid improvement.

## table1_playout_throughput_subset

Run the paper's flat Monte Carlo playout benchmark through the official generated C++ reasoner path on a matched subset of games with both HRG and RBG source descriptions.

Primary benefit metric:
- `speedup_vs_rbg_rg`: mean per-game ratio of HRG->RG playout throughput to RBG->RG playout throughput from the same job.

Supporting metrics:
- `sims_per_second`
- `states_per_second`
- `games_completed`

Constraint metric:
- `benchmark_completion_rate`: benchmark-mode generated reasoners must complete positive playout work for every selected game and source language.
