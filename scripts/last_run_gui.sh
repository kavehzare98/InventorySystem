#!/usr/bin/env bash
set -e
BUILD_DIR=${1:-build}

cd "$BUILD_DIR"
./inventory_gui

