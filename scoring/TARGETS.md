# Scoring Targets

## hrg_optimization_structure

Produce compact generated forward models from the selected high-level game-rule descriptions while preserving executable legal playouts.

Primary benefit metric:
- `automaton_edge_reduction_pct`: percentage reduction in automaton edges versus a direct generated-model baseline for the same game.

Secondary benefit metrics:
- `automaton_node_reduction_pct`
- `generated_cpp_line_reduction_pct`

Constraint metric:
- `playout_completion_rate`: generated C++ reasoners must complete deterministic fixed-count random playouts. A compact model that cannot produce legal playouts is not a valid improvement.

## table1_playout_throughput_subset

Run the flat Monte Carlo playout benchmark on a matched subset of games with two source-rule families.

Primary benefit metric:
- `generated_cpp_line_advantage_vs_rbg_pct`: mean percentage by which the candidate source family's generated C++ reasoner is shorter than the matched baseline source family's generated reasoner for the same games.

Supporting metrics:
- `automaton_edge_advantage_vs_rbg_pct`
- `speedup_vs_rbg_rg`
- `sims_per_second`
- `states_per_second`
- `games_completed`

Constraint metric:
- `benchmark_completion_rate`: benchmark-mode generated reasoners must complete positive playout work for every selected game and source language.
