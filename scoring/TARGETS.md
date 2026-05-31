# Scoring Targets

## hrg_optimization_structure

Optimize HRG game descriptions through the paper's Regular Games pipeline and preserve a working generated forward model.

Primary benefit metric:
- `automaton_edge_reduction_pct`: percentage reduction in automaton edges versus the same HRG game translated without optimizer passes.

Secondary benefit metrics:
- `automaton_node_reduction_pct`
- `generated_cpp_line_reduction_pct`
- `generated_cpp_byte_reduction_pct`

Constraint metric:
- `playout_completion_rate`: generated C++ reasoners must complete deterministic fixed-count random playouts. A compact model that cannot produce legal playouts is not a valid improvement.
