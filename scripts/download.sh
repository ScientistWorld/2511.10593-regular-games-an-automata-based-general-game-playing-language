#!/usr/bin/env bash
# Estimated download size: about 150 MB for Rust crate sources if
# data/downloads/rg_cargo_vendor is missing. Source snapshots are committed;
# upstream clone commands below are fallbacks for a damaged checkout.
set -euo pipefail

cd /home/user
RG_COMMIT="915b69c835c38312cfeeac45b5774f45da17eff8"
RGCOMPILER_COMMIT="7fc24da037de760d2235fa4a39faf004f9fb6719"

if [ ! -d method/rg ]; then
  git clone https://github.com/radekmie/rg method/rg
  (cd method/rg && git checkout "$RG_COMMIT")
fi
if [ ! -d method/rgcompiler ]; then
  git clone https://github.com/WoojtekP/RGcompiler method/rgcompiler
  (cd method/rgcompiler && git checkout "$RGCOMPILER_COMMIT")
fi

if ! command -v cargo >/dev/null 2>&1; then
  mkdir -p tmp
  curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs -o tmp/rustup-init.sh
  sh tmp/rustup-init.sh -y --default-toolchain 1.89.0 --profile minimal
  # shellcheck disable=SC1091
  . "$HOME/.cargo/env"
fi

mkdir -p data/downloads
if [ ! -d data/downloads/rg_cargo_vendor ] || [ ! -e data/downloads/rg_cargo_vendor/console_error_panic_hook/.cargo-checksum.json ]; then
  rm -rf data/downloads/rg_cargo_vendor
  (cd method/rg/interpreter_rust && cargo vendor ../../../data/downloads/rg_cargo_vendor >/dev/null)
fi

rm -f method/rg/interpreter_rust/vendor
ln -s ../../../data/downloads/rg_cargo_vendor method/rg/interpreter_rust/vendor
