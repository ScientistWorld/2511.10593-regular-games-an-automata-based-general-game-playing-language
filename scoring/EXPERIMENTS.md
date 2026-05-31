# Experiments

## hrg_optimization_structure

This experiment checks whether a game-rule compiler can reduce the structural size of generated forward models while still producing reasoners that execute legal deterministic playouts. Scores compare each optimized game against the same game translated without optimizer passes, then average across the selected game set. The current expanded run covers six HRG games; the reusable script defaults have been broadened to a larger 14-game subset for the next run.
