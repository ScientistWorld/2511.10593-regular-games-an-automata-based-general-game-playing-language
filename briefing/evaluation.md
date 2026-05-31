# Evaluation

The benchmark evaluates generated game reasoners on two properties:

1. Structural compactness of the generated forward model, compared with a direct translation of the same rule input.
2. Compactness on a matched-source subset where the same games are available in two rule-description families.

Raw playout throughput and state throughput are retained as diagnostic context, but they have zero scoring coefficient because wall-clock rates are hardware dependent. The scored benefit metrics are generated source size and automaton size reductions. Completion of fixed playout workloads is a correctness constraint: a smaller generated model is not valid if it cannot execute legal playouts.

Evaluation reads submitted artifacts from a JSON file; it does not regenerate games or import from a submitted implementation. The reusable command is:

```bash
bash scripts/evaluate.sh path/to/results.json
```

The evaluator writes `scoring/scores.json`. A compatible method output must list per-game runs with method identifiers, source game names, generated artifact sizes, automaton node/edge counts, playout completion, and optional diagnostic throughput fields.
