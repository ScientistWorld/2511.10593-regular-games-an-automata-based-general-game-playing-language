#!/usr/bin/env bash
# Build the official RG CLI (Rust) and rg2cpp (C++) once; idempotent.
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
export CARGO_NET_OFFLINE="${CARGO_NET_OFFLINE:-true}"
CLI="$ROOT/method/rg/interpreter_rust/target/release/cli"
RG2CPP="$ROOT/method/rgcompiler/build/src/rg2cpp"
(
  flock 9
  if [ ! -x "$CLI" ] || ! "$CLI" --version >/dev/null 2>&1; then
    cargo build --release --manifest-path "$ROOT/method/rg/interpreter_rust/Cargo.toml" --package cli --bin cli
  fi
  if [ ! -x "$RG2CPP" ] || ! "$RG2CPP" --help >/dev/null 2>&1; then
    rm -rf "$ROOT/method/rgcompiler/build"
    mkdir -p "$ROOT/method/rgcompiler/build"
    (cd "$ROOT/method/rgcompiler/build" && cmake .. -DCMAKE_BUILD_TYPE=Release >/dev/null && make -j"$(nproc)" rg2cpp)
  fi
) 9>"$ROOT/method/.toolchain.lock"
