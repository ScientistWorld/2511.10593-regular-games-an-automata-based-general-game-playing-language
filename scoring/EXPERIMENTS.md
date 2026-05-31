# Experiments

## hrg_optimization_structure

This experiment checks whether a game-rule compiler can reduce the structural size of generated forward models while still producing reasoners that execute legal deterministic playouts. Scores compare each optimized game against the same game translated without optimizer passes, then average across the selected game set. The current expanded run covers a 14-game HRG subset from the paper's benchmark set.

## table1_playout_throughput_subset

This experiment checks the paper's main benchmark form on a small matched subset of games that have both HRG and RBG descriptions. Each source is translated through the same Regular Games compiler path, compiled in benchmark mode, and run for fixed-time random playouts. Scores emphasize the within-job speedup ratio so future agents must improve the generated forward model relative to the matched RBG-translated baseline, not just rely on faster hardware.
