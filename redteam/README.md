# Audit execution

Run `bash redteam/run_all.sh` in the gym's compute container. Individual
`redteam/<case>/run.sh` scripts prepare actual method outputs and invoke the
unchanged hidden test, with no arguments. They save both submitted artifacts
and train/test scores locally before restoring the temporary method output.
Construction of candidates reads only visible rule sources and the public
reproduction code. It does not read hidden evaluation code, hidden scores,
reference coefficients, or the paper. The separate reporting code may read
these for the audit.

The original reproduction artifact under `initial/` is used only for restoration
and comparison. Shortcuts reuse `reference_seed1/results.json`, produced by this
audit's own execution of the visible pipeline, rather than hidden answers.
All shortcuts are explicitly named as shortcuts.

The reference uses its existing three-game benchmark configuration, 100 fixed
playouts and two 10-second benchmark repetitions per game. Seeds 1, 2, and 3
change the actual C++ playout RNG. The stronger candidate enables the existing
path-compression transformation in the generated-model compiler; the weaker
candidate disables automaton optimizations. A separate weak backend compiles
identical generated models without optimization. Exhaustive depth-3 tree counts
compare direct, reference and compressed models. The brute-force probe attempts
to enumerate complete state-transition tables and stops at 50,000 states or
20 seconds per game; incomplete tables are reported as failures.

`cache/` holds reproducible build outputs and is ignored by the nested gitignore.
`job.log` is diagnostic and ignored. JSON scores, submitted results, per-case
status and compiler-failure evidence are tracked. No Python environment or
running evaluator is modified.
