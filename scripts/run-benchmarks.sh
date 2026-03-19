#!/bin/bash
set -e # Exit immediately if a command exits with a non-zero status.

BUILD_DIR="build"
BENCHMARK_BIN="${BUILD_DIR}/bin/run_benchmarks"

# Check if the benchmark executable exists.
if [ ! -f "$BENCHMARK_BIN" ]; then
    echo "Error: Benchmark executable '${BENCHMARK_BIN}' not found."
    echo "Please run the build script first in Release mode: ./scripts/build.sh Release"
    exit 1
fi

echo "==== Running Movement Benchmarks ===="
"./${BUILD_DIR}/bin/run_benchmarks"

echo ""
echo "==== Running Board Benchmarks ===="
"./${BUILD_DIR}/bin/run_board_benchmarks"

echo ""
echo "Benchmark execution complete."
