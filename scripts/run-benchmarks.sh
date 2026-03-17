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

echo "==== Running Benchmarks ===="

# Run the benchmark executable
"./${BENCHMARK_BIN}"

echo ""
echo "Benchmark execution complete."
