# Scoring Targets

## forward_model_efficiency  (weight 0.60)

Generate, from each HRG rule file, a C++ forward model that executes a fixed
flat Monte Carlo workload with as few instructions as possible while playing
exactly the game.

- Primary benefit: `speedup_vs_rbg_translation` — geometric mean over games of
  (instructions per playout of the frozen RBG->RG model) / (instructions per
  playout of the submitted model).
- Secondary benefit: `worst_game_speedup_vs_rbg_translation` — the same ratio
  on the least favourable game (the paper claims a win on every game).
- Constraint: `verified_game_fraction` — every game's model must compile under
  the evaluator's driver, pass the integrity checks and reproduce the ground
  truth game tree and playout statistics; otherwise the run fails.
- Diagnostics (zero coefficient): `speedup_vs_direct_translation`,
  `games_faster_than_rbg_fraction`.

## automaton_optimization  (weight 0.15)

Derive, from each HRG rule file, an RG rules automaton with as few nodes and
edges as possible that still plays exactly the game.

- Primary benefit: `automaton_edge_reduction_pct` (vs the direct translation).
- Secondary benefit: `automaton_node_reduction_pct`.
- Constraint: `verified_automaton_fraction` — the automaton, compiled by the
  reference compiler, must reproduce the ground truth; otherwise the run fails.

## translated_rules_optimization  (weight 0.25)

Compile the RBG descriptions of the same games (automatically translated rules)
into efficient, exact forward models and compact automata.

- Benefit (largest coefficient): `speedup_vs_direct_rbg_translation` —
  geometric mean over games of the direct RBG->RG translation's instructions
  per playout divided by the submitted model's.
- Benefit (primary metric, the paper's reported quantity):
  `rbg_automaton_edge_reduction_pct`; secondary `rbg_automaton_node_reduction_pct`.
- Constraint: `verified_rbg_game_fraction` — every RBG file's model and
  automaton must reproduce the ground truth; otherwise the run fails.
