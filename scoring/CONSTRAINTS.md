# Constraints

Future methods are evaluated on the same game sources under `method/rg/games/hrg/` unless they explicitly add a separate experiment.

For `hrg_optimization_structure`, hold fixed:
- The input game rules and initial states.
- The fixed deterministic playout count and upstream `test/sims.cpp` checker.
- The public forward-model API used by the generated C++ reasoner.
- The distinction between the no-optimization baseline and the optimized pipeline.

Do not improve scores by deleting game rules, bypassing legal move generation, hardcoding playout traces, or replacing the automaton-to-reasoner pipeline with an unrelated forward model.
