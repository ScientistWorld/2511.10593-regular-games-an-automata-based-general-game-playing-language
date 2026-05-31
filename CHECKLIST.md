# Reproduction Checklist

- [x] Read paper and identify the core claim.
- [x] Fetch official RG and RGcompiler source snapshots.
- [x] Vendor Rust crates for offline compute-node builds.
- [x] Write method wrapper around the official HRG/RG/rg2cpp pipeline.
- [x] Write method-agnostic evaluator.
- [x] Define scoring targets, constraints, and reference metrics.
- [x] Write environment container and setup scripts.
- [x] Run the first successful smoke job.
- [x] Inspect generated scores and update milestone to `core_claim`.
- [x] Validate the end-to-end `scripts/reproduce.sh` path with default playout count.
- [x] Reproduce the core claim on additional HRG games (`core_claim_plus`).
- [x] Run the broader 14-game HRG subset.
- [x] Add a Table 1 subset benchmark harness for HRG->RG versus RBG->RG.
- [x] Run the Table 1 subset benchmark job and validate the resulting scores.
