# Constraints

Future methods are evaluated on the same game sources under `data/games/` unless they explicitly add a separate experiment.

For `hrg_optimization_structure`, hold fixed:
- The input game rules and initial states.
- The fixed deterministic playout count and upstream `test/sims.cpp` checker.
- The public forward-model API used by the generated C++ reasoner.
- The distinction between the direct generated-model baseline and the compacted generated-model candidate.

For `table1_playout_throughput_subset`, hold fixed:
- The selected paired rule source files unless adding a separately named experiment.
- The benchmark-mode playout driver used to generate the scored artifacts.
- The random playout policy and fixed RNG seed from the upstream benchmark.
- The paired comparison: both source families must pass through the same generated-reasoner interface.

Do not improve scores by deleting game rules, bypassing legal move generation, hardcoding playout traces, or replacing formal rule execution with an unrelated hand-written simulator.
