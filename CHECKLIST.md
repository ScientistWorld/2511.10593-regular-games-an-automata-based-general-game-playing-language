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
- [ ] Validate the end-to-end `scripts/reproduce.sh` path with default playout count.
