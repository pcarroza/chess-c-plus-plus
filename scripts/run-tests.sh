#!/bin/bash
set -e # Exit immediately if a command exits with a non-zero status.

BUILD_DIR="build"

# Check if the build directory exists.
if [ ! -d "$BUILD_DIR" ]; then
    echo "Error: Build directory '${BUILD_DIR}' not found."
    echo "Please run the build script first: ./scripts/build.sh"
    exit 1
fi

echo "==== Running Tests ===="

# Run tests using CTest
# --test-dir points to the directory containing CTest configuration (CTestTestfile.cmake)
ctest --test-dir "${BUILD_DIR}" --output-on-failure

echo ""
echo "Test execution complete."
