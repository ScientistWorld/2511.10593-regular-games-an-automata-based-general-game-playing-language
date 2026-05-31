#!/usr/bin/env bash
# Estimated download size: about 150 MB for Rust crate sources if
# data/downloads/rg_cargo_vendor is missing. Source snapshots are committed;
# upstream clone commands below are fallbacks for a damaged checkout.
set -euo pipefail

cd /home/user
[ -d method/rg ] || git clone --depth 1 https://github.com/radekmie/rg method/rg
[ -d method/rgcompiler ] || git clone --depth 1 https://github.com/WoojtekP/RGcompiler method/rgcompiler

if ! command -v cargo >/dev/null 2>&1; then
  curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs -o tmp/rustup-init.sh
  sh tmp/rustup-init.sh -y --default-toolchain 1.89.0 --profile minimal
  # shellcheck disable=SC1091
  . "$HOME/.cargo/env"
fi

mkdir -p data/downloads
if [ ! -d data/downloads/rg_cargo_vendor ]; then
  (cd method/rg/interpreter_rust && cargo vendor ../../../data/downloads/rg_cargo_vendor >/dev/null)
fi

rm -f method/rg/interpreter_rust/vendor
ln -s ../../../data/downloads/rg_cargo_vendor method/rg/interpreter_rust/vendor
