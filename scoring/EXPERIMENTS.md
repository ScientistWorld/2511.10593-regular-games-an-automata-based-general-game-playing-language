# Experiments

## hrg_optimization_structure

This experiment checks whether a game-rule compiler can reduce the structural size of generated forward models while still producing reasoners that execute legal deterministic playouts. Scores compare each optimized game against the same game translated without optimizer passes, then average across the selected game set. The current expanded run covers a 14-game HRG subset from the paper's benchmark set.

## table1_playout_throughput_subset

This experiment checks the paper's matched-source benchmark form on a small subset of games that have both HRG and RBG descriptions. Scores emphasize machine-independent generated-code and automaton-size advantages over the matched RBG-translated baseline, while playout throughput and raw game counts remain diagnostic fields rather than ranking metrics.
