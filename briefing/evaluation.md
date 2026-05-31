# Evaluation

The paper evaluates generated game reasoners primarily by flat Monte Carlo random playout throughput: Table 1 reports playouts per second, averaged over three one-minute runs, for HRG->RG, RBG->RG, native RBG, and Ludii where available. This reproduction includes a matched Table 1 subset that runs the official benchmark-mode generated C++ reasoners for HRG->RG and RBG->RG. Because raw wall-clock speed is hardware dependent, the primary scored benefit is the within-job HRG/RBG throughput ratio; raw playout and state rates are retained as supporting metrics.

The reproduction also scores the paper's structural optimizer claim from Section 3.3: automaton node and edge reductions after optimization, plus fixed-work playout completion as a correctness constraint.

Evaluation reads method artifacts from `method/outputs/results.json`; it does not regenerate games or import from `method/`. The reusable command is:

```bash
bash scripts/evaluate.sh method/outputs/results.json
```

The evaluator writes `scoring/scores.json`. For the throughput subset, RBG->RG is the baseline and HRG->RG is the proposed method. For the structural experiment, no-optimization translation is the baseline and the optimized HRG-to-RG-to-C++ pipeline is the proposed method. A valid generated model must complete its playout workload, so compactness or speed alone is not sufficient.
