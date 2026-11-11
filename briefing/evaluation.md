# Evaluation

Two scripts score **every method on disk** (`method/compilers/<name>/compile.sh`):

```bash
bash scripts/evaluate_train.sh   # visible games in data/games/{hrg,rbg} -> scoring/scores_train.json
bash scripts/evaluate_test.sh    # held-out games (not visible)    -> scoring/scores_test.json
```

`evaluate_test.sh` takes no arguments. `evaluate_train.sh` accepts
`--details <file>` for per-game diagnostics and `--methods-dir <dir>`.
Both need `valgrind`, `g++`, `cmake` and `nm` (all in the container).

For each method and each rule file of the slice (the HRG files, and the RBG
descriptions of the same kind of games) the evaluator:

1. runs `compile.sh` on a copy of the rule file (15 s cap per game, the method's own process group is killed afterwards);
2. checks the generated C++ (no I/O, process control, inline assembly,
   symbol interposition or compiler-setting overrides), then compiles it with
   its own driver and fixed flags (`g++ -std=c++23 -O3 -flto -march=x86-64-v2 -DNDEBUG`);
3. **verifies** the forward model against ground truth computed from a frozen
   reference translation of the same rule file: exact game-tree counts
   (leaves, states, terminals) to a fixed depth, and the statistics of a fixed
   number of uniformly random playouts (mean playout length, mean branching
   factor, every player's mean score) within six standard errors;
4. fails the run if that workload takes more than 30 times as long (wall
   clock, pass/fail only) as the frozen direct translation, then **measures**
   the work of that fixed playout workload (fixed count, fixed
   seed) as executed machine instructions under valgrind, and divides it by
   the playout count;
5. recompiles the submitted `game.json` with the official RG compiler
   (pragmas removed), verifies it the same way, and counts its nodes and edges.

Comparison points are frozen by the evaluator and measured in the same run:
the matched RBG description of each game translated RBG->RG, the direct HRG->RG
translation without automaton transformations, and the direct RBG->RG
translation without automaton transformations. Ground truth for an HRG file
comes from its direct translation; for an RBG file from its direct RBG->RG
translation.

If any step fails for any game, the method's run fails and it receives the
worst value of every scored metric (speedups 0, reductions -100, fractions 0) in all three experiments.

Metrics written under `experiments.<name>.results.<method>`:

| Experiment | Metric | Scored | Meaning |
|---|---|---|---|
| `forward_model_efficiency` | `speedup_vs_rbg_translation` | yes (primary) | geometric mean over games of RBG->RG instructions per playout / method instructions per playout |
| | `worst_game_speedup_vs_rbg_translation` | yes | minimum of the same ratio over games |
| | `verified_game_fraction` | yes (constraint) | 1 if every game verified, else the run failed |
| | `speedup_vs_direct_translation` | no | geometric-mean speedup over the direct translation |
| | `games_faster_than_rbg_fraction` | no | fraction of games beating RBG->RG |
| `automaton_optimization` | `automaton_edge_reduction_pct` | yes (primary) | mean % fewer edges than the direct translation |
| | `automaton_node_reduction_pct` | yes | mean % fewer nodes |
| | `verified_automaton_fraction` | yes (constraint) | 1 if every submitted automaton verified |
| `translated_rules_optimization` | `speedup_vs_direct_rbg_translation` | yes | geometric mean over RBG files of direct RBG->RG instructions per playout / method instructions per playout |
| | `rbg_automaton_edge_reduction_pct` | yes (primary) | mean % fewer edges than the direct RBG->RG translation |
| | `rbg_automaton_node_reduction_pct` | yes | mean % fewer nodes |
| | `verified_rbg_game_fraction` | yes (constraint) | 1 if every RBG file's model and automaton verified |

Experiment weights: 0.60, 0.15 and 0.25.

Instruction counts are deterministic for a given binary and seed, so scores do
not depend on wall-clock time or machine load. The train slice uses eight
standard-size games; the held-out slice uses different, unseen games of the
same kind at comparable difficulty (the translated-rules experiment uses
seven train games and four held-out games).
