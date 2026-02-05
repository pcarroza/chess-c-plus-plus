#!/bin/bash
set -e # Exit immediately if a command exits with a non-zero status.

BUILD_DIR="build"

# Check if the user wants to clean the build artifacts
if [ "$1" == "clean" ]; then
    if [ -d "${BUILD_DIR}" ]; then
        echo "==== Cleaning compilation objects in ${BUILD_DIR}/lib ===="
        cmake --build "${BUILD_DIR}" --target clean
    fi
    exit 0
fi

# Set the build type (Debug/Release). Default to Debug if no argument is provided.
BUILD_TYPE=${1:-Debug}

# Inform the user
# Check if configuration is needed (missing cache or different build type)
if [ ! -f "${BUILD_DIR}/CMakeCache.txt" ] || ! grep -q "CMAKE_BUILD_TYPE:STRING=${BUILD_TYPE}" "${BUILD_DIR}/CMakeCache.txt"; then
    echo "==== Configuring Project ===="
    echo "Build Type: ${BUILD_TYPE}"
    echo "Build Directory: ${BUILD_DIR}"

    # Configure the project using CMake
    # -S . : Source directory is the current one
    # -B ${BUILD_DIR}: Binary (build) directory
    cmake -S . -B "${BUILD_DIR}" -DCMAKE_BUILD_TYPE="${BUILD_TYPE}"
else
    echo "==== Skipping Configuration (Already configured) ===="
fi

# Determine the number of available cores for parallel build
if command -v nproc &> /dev/null; then
    JOBS=$(nproc)
else
    JOBS=2 # Fallback to 2 cores if nproc is not available
fi

# Inform the user
echo ""
echo "==== Building Project (using up to ${JOBS} cores) ===="

# Build the project using the --build flag
cmake --build "${BUILD_DIR}" --parallel "${JOBS}"

echo ""
echo "Build complete. The executable is available at '${BUILD_DIR}/bin/chess'"
