#!/usr/bin/env bash
set -e

BUILD_DIR=${1:-build}

echo "[configure] Using build directory: $BUILD_DIR"

mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

cmake .. -DCMAKE_BUILD_TYPE=Debug

echo "[configure] Configuration complete."

