# Evaluation

The paper evaluates generated game reasoners primarily by random playout throughput. Because wall-clock speed is hardware dependent, this reproduction scores machine-independent proxies from the same pipeline: automaton node and edge reductions, generated C++ size reductions, and fixed-work playout completion.

Evaluation reads method artifacts from `method/outputs/results.json`; it does not regenerate games or import from `method/`. The reusable command is:

```bash
bash scripts/evaluate.sh method/outputs/results.json
```

The evaluator writes `scoring/scores.json`. For the core experiment, the no-optimization translation is the baseline and the optimized HRG-to-RG-to-C++ pipeline is the proposed method. A valid optimized model must complete the deterministic fixed playout count, so compactness alone is not sufficient.
