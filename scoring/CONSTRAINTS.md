# Constraints

Future methods are evaluated on the same game sources under `method/rg/games/hrg/` unless they explicitly add a separate experiment.

For `hrg_optimization_structure`, hold fixed:
- The input game rules and initial states.
- The fixed deterministic playout count and upstream `test/sims.cpp` checker.
- The public forward-model API used by the generated C++ reasoner.
- The distinction between the no-optimization baseline and the optimized pipeline.

For `table1_playout_throughput_subset`, hold fixed:
- The selected paired HRG/RBG game sources unless adding a separately named experiment.
- The upstream `scripts/sims.py` benchmark mode and generated `test/sims.cpp` playout driver.
- The random playout policy and fixed RNG seed from the upstream benchmark.
- The paired comparison: HRG->RG and RBG->RG must both pass through the same compiler and generated-reasoner interface.

Do not improve scores by deleting game rules, bypassing legal move generation, hardcoding playout traces, or replacing the automaton-to-reasoner pipeline with an unrelated forward model.
