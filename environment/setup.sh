#!/bin/bash
# Install Python packages into the container overlay.
#
# This script is run by the system on the login node (which has internet)
# inside the container with a persistent overlay. Changes persist across
# job submissions without rebuilding the container.
#
# Put ALL pip installs here, NOT in container.def.
# Only use container.def for the base Docker image and apt-get packages.
#
# IMPORTANT: Install into the SYSTEM Python, not a virtual environment.
# The overlay may be recreated on container rebuilds — a venv inside
# it will be lost and all subsequent jobs will fail.
# Use: uv pip install --system <packages>
# Do NOT create a venv (python -m venv, virtualenv, etc.).

set -e

# uv pip install --system <packages>

# Pre-fetch Rust crates into the persistent container overlay. Compute nodes run
# with no internet, so the native RG CLI build must resolve from Cargo's cache.
if [ -f /home/user/method/rg/interpreter_rust/Cargo.toml ]; then
  export CARGO_HOME="${CARGO_HOME:-/usr/local/cargo}"
  export CARGO_NET_OFFLINE=false
  cargo fetch --locked \
    --manifest-path /home/user/method/rg/interpreter_rust/Cargo.toml \
    --target x86_64-unknown-linux-gnu
fi
