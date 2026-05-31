# Verification Report

## Initial Assessment

The workspace started this verification at `core_claim_plus`. That milestone is justified: the method code runs the paper's official rule-to-reasoner pipeline, `scores.json` contains a successful structural compactness experiment plus a matched Table 1 subset, and `python3 validate.py --compare` passes.

## Issues Found

- Minor: `scoring/reference.json` used machine-independent substitute metrics for generated source size and automaton size where the paper reports wall-clock playout throughput. This is the right scoring choice for the gym, but it needed explicit notes so the values are not mistaken for direct published table entries.
- Minor: `MILESTONES.md`, `PROGRESS.md`, and `action.yaml` still reflected an optional benchmark-expansion submission rather than final verification.

## Fixes Applied

- Added `notes` fields in `scoring/reference.json` explaining which values are directly paper-reported and which are machine-independent substitute metrics computed from reproduced artifacts.
- Updated milestone/progress text to record final verification and remove stale pending-submission language.
- Rechecked `scripts/download.sh` URLs with `curl -I -L --max-time 15`; the RG repository, RGcompiler repository, and rustup installer all returned HTTP 200.
- Re-ran `python3 validate.py --compare`; scoring, import separation, train/test independence, shared-path checks, and method-key checks all passed.

## Final Judgment

The workspace is ready to serve as a research gym. Improve-mode agents can build on the packaged paper method, and from-scratch agents have portable rule files, method-agnostic problem/evaluation documentation, and evaluators that score submitted artifacts without importing from `method/`. Scored metrics avoid wall-clock-dependent ranking; throughput remains diagnostic with zero coefficient.

- Milestone: core_claim_plus
- Ready for gym use: yes
- Confidence: high
- Key limitation: the committed baseline covers a representative matched subset rather than the full Table 1 benchmark.
