#!/usr/bin/env bash
set -e

BUILD_DIR=${1:-build}

echo "[build] Building in: $BUILD_DIR"

cd "$BUILD_DIR"
cmake --build . -- -j"$(nproc 2>/dev/null || echo 4)"

echo "[build] Build complete."

