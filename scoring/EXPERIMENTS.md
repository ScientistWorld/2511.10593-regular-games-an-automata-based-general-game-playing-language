# Experiments

## hrg_optimization_structure

This experiment checks whether a game-rule system can reduce the structural size of generated forward models while still producing reasoners that execute legal deterministic playouts. Scores compare each transformed game against the same game translated directly, then average across the selected game set. The committed score artifact covers a representative subset of the benchmark rule files.

## table1_playout_throughput_subset

This experiment checks a matched-source benchmark form on a subset of games that have descriptions in two rule-file families. Scores emphasize machine-independent generated-code and automaton-size advantages over the matched baseline source family, while playout throughput and raw game counts remain diagnostic fields rather than ranking metrics.
