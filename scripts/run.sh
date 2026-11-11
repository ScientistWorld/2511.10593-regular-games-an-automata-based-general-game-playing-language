#!/usr/bin/env bash
# Hardening job: reproduce the reference end to end on the rebuilt gym, then
# run the better/weaker variants, the shortcut probes and the seed-noise check
# through the same evaluators. Each step writes its own file so a partial run
# keeps what finished.
set -uo pipefail
cd /home/user
OUT=redteam/hardening/results
mkdir -p "$OUT"
step() { echo "=== $(date -u +%H:%M:%S) $*"; }
command -v valgrind && valgrind --version
nproc; free -g || true

step "prepare reference toolchain"
bash method/compilers/hrg_rg_optimized/prepare.sh || exit 1

step "held-out test (canonical script, reference methods on disk)"
bash scripts/evaluate_test.sh > "$OUT/evaluate_test.log" 2>&1 || { tail -50 "$OUT/evaluate_test.log"; exit 1; }
tail -5 "$OUT/evaluate_test.log"

step "train slice (canonical script)"
bash scripts/evaluate_train.sh --details "$OUT/train_reference_details.json" > "$OUT/evaluate_train.log" 2>&1 || { tail -50 "$OUT/evaluate_train.log"; exit 1; }
tail -5 "$OUT/evaluate_train.log"

step "held-out test: variants and shortcut probes"
python3 eval/test/evaluate.py --methods-dir redteam/hardening/methods \
  --output "$OUT/test_probes.json" --details "$OUT/test_probes_details.json" > "$OUT/test_probes.log" 2>&1
grep "^\[test\]" "$OUT/test_probes.log" | cut -c1-200

step "held-out test: reference + variants with the default seed (details)"
python3 eval/test/evaluate.py --methods-dir redteam/hardening/seed_methods \
  --output "$OUT/test_seed_default.json" --details "$OUT/test_seed_default_details.json" > "$OUT/test_seed_default.log" 2>&1

for seed in 101 202; do
  step "held-out test: seed $seed"
  python3 eval/test/evaluate.py --methods-dir redteam/hardening/seed_methods --seed "$seed" \
    --output "$OUT/test_seed_$seed.json" --details "$OUT/test_seed_${seed}_details.json" > "$OUT/test_seed_$seed.log" 2>&1
done

step "train slice: variants"
python3 eval/train/evaluate.py --methods-dir redteam/hardening/seed_methods \
  --output "$OUT/train_variants.json" --details "$OUT/train_variants_details.json" > "$OUT/train_variants.log" 2>&1

step "validate"
python3 validate.py --post-design || true
step "done"
