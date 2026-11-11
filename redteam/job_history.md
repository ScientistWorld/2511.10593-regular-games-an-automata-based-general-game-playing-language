# Compute audit history

- `676cc982-768`: job wrapper exited 0, but no scored audit case completed.
  The audit harness failed when compiling a copied playout driver because its
  include search path omitted `method/rgcompiler/test/fast_random.hpp`.
  Original model generation succeeded and was cached. The brute-force probe
  explored roughly 50,000 states in each game without completing enumeration.
  Fixed the include paths and changed the bundle to return a nonzero exit code
  if any case fails. These infrastructure failures are not method results.

- `174f8808-ade`: corrected CPU bundle completed all 17 cases and both train
  and hidden-test evaluations (exit 0). All per-case status files are successful.
  The slow backend case was named `weaker_slow_backend` during execution; its
  evidence directory and replay command are now named `shortcut_slow_backend`
  because its exact reference tie pays despite substantially worse throughput.
- Final verification uses a separate fresh CPU job to replay saved artifacts
  through the hidden test with no arguments. No build or candidate process from
  the construction job survives into this verification.

- `12cf7f46-91a`: fresh-container scoring job exited 0. All 17 persisted
  submissions matched their construction-job hidden-test scores exactly; no
  candidate code executed. Rank calculations were regenerated successfully.
  Job stdout/stderr are preserved under `job_evidence/12cf7f46-91a/`.
