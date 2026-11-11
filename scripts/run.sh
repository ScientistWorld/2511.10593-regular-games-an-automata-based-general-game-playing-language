#!/usr/bin/env bash
# Hardening job 4 (restart-safe): the scheduler may preempt and restart this
# script; finished steps are skipped (markers in tmp/job_markers) and the probe,
# seed and train-variant evaluations resume from their partial outputs.
set -uo pipefail
cd /home/user
OUT=redteam/hardening/results
MARK=tmp/job_markers
mkdir -p "$OUT" "$MARK"
step() { echo "=== $(date -u +%H:%M:%S) $*"; }
nproc; df -h /tmp | tail -1
rm -rf tmp/eval_work

step "prepare reference toolchain"
bash method/compilers/hrg_rg_optimized/prepare.sh || exit 1

if [ ! -f "$MARK/test" ]; then
  step "held-out test (canonical script)"
  bash scripts/evaluate_test.sh > "$OUT/evaluate_test.log" 2>&1 || { tail -50 "$OUT/evaluate_test.log"; exit 1; }
  touch "$MARK/test"
fi
if [ ! -f "$MARK/train" ]; then
  step "train slice (canonical script)"
  bash scripts/evaluate_train.sh --details "$OUT/train_reference_details.json" > "$OUT/evaluate_train.log" 2>&1 || { tail -50 "$OUT/evaluate_train.log"; exit 1; }
  touch "$MARK/train"
fi

step "held-out test: variants and shortcut probes"
python3 eval/test/evaluate.py --methods-dir redteam/hardening/methods --resume \
  --output "$OUT/test_probes.json" --details "$OUT/test_probes_details.json" >> "$OUT/test_probes.log" 2>&1
grep "^\[test\]" "$OUT/test_probes.log" | cut -c1-160

step "held-out test: reference, better and weaker variant, seed 101"
python3 eval/test/evaluate.py --methods-dir redteam/hardening/seed2_methods --seed 101 --resume \
  --output "$OUT/test_seed_101.json" --details "$OUT/test_seed_101_details.json" >> "$OUT/test_seed_101.log" 2>&1

step "train slice: reference, better and weaker variant"
python3 eval/train/evaluate.py --methods-dir redteam/hardening/seed2_methods --resume \
  --output "$OUT/train_variants.json" --details "$OUT/train_variants_details.json" >> "$OUT/train_variants.log" 2>&1

step "validate"
python3 validate.py --post-design || true
step "done"
