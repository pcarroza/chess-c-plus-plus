#!/bin/bash
set -e # Exit immediately if a command exits with a non-zero status.

# Set the build type (Debug/Release). Default to Debug if no argument is provided.
BUILD_TYPE=${1:-Debug}
BUILD_DIR="build"

# Inform the user
echo "==== Configuring Project ===="
echo "Build Type: ${BUILD_TYPE}"
echo "Build Directory: ${BUILD_DIR}"

# Configure the project using CMake
# -S . : Source directory is the current one
# -B ${BUILD_DIR}: Binary (build) directory
cmake -S . -B "${BUILD_DIR}" -DCMAKE_BUILD_TYPE="${BUILD_TYPE}"

# Inform the user
echo ""
echo "==== Building Project ===="

# Build the project using the --build flag
cmake --build "${BUILD_DIR}"

echo ""
echo "Build complete. The executable is available at '${BUILD_DIR}/bin/chess'"
