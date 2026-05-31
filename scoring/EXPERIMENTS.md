# Experiments

## hrg_optimization_structure

This experiment checks whether a game-rule compiler can reduce the structural size of generated forward models while still producing reasoners that execute legal deterministic playouts. Scores compare each optimized game against the same game translated without optimizer passes, then average across the selected game set.
