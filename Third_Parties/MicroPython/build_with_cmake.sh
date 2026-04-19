#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Purpose:
#   Build the MicroPython package and the libMicroPython.a (including the uKOS interface)

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL

# Determine script directory (works if executed via ./script.sh or zsh script.sh)

readonly PATH_PRG="${0:a:h}"

use_clang=0
while getopts ":Lh" option; do
    case ${option} in
        h)
            echo "USAGE: ./build_with_cmake.sh [-L]"
            echo
            echo "OPTIONS:"
            echo "    -L: compiler is LLVM/clang"
            exit 0
            ;;
        L)
            use_clang=1
            ;;
        ?)
            echo "Invalid option: -${OPTARG}"
            exit 1
            ;;
    esac
done
# Shift away the processed options
shift $((OPTIND-1))

# Colours for messages

readonly RED=$'\033[0;31m'
readonly GREEN=$'\033[0;32m'
readonly YELLOW=$'\033[0;33m'
readonly BOLD=$'\033[1m'
readonly FAINT=$'\033[2m'
readonly ITALIC=$'\033[3m'
readonly NC=$'\033[0m' # No Color

# Package version / commit / tag and directories

MICROPY_REF="${1:-v1.28.0}"   # default tag v1.27.0 if none passed
MICROPY_DIR="${PATH_PRG}/MicroPython-current"
MICROPY_LIBRARY_DIR="${PATH_PRG}/Construction"
MICROPY_URL="https://github.com/micropython/micropython.git"

# Clone or update MicroPython safely

echo -e "\n${BOLD}Preparing MicroPython source: ${MICROPY_REF}${NC}"

cd "${PATH_PRG}"

if [ ! -d "${MICROPY_DIR}/.git" ]; then
    echo "Cloning MicroPython..."
    git clone "$MICROPY_URL" "$MICROPY_DIR"
fi

cd "${MICROPY_DIR}"

# Check if the ref exists as a branch

if git ls-remote --heads origin "${MICROPY_REF}" | grep -q .; then
    echo "Fetching branch ${MICROPY_REF}..."
    git fetch origin "${MICROPY_REF}"
    git checkout -B "${MICROPY_REF}" "origin/${MICROPY_REF}"
else
    # Assume it is a tag or commit SHA
    echo "Fetching tag or commit ${MICROPY_REF}..."
    git fetch --tags --quiet
    git checkout "tags/${MICROPY_REF}" 2>/dev/null || git checkout "${MICROPY_REF}"
fi

echo "MicroPython ready at $(git rev-parse HEAD)"

# Build per-core function

build_core() {
    CORE="$1"
    CORE_DIR="${MICROPY_LIBRARY_DIR}/${CORE}"
    BUILD_DIR="${CORE_DIR}/build"

    echo -e "\n${BOLD}Building for ${CORE}! ...${NC}"

    mkdir -p "${BUILD_DIR}"
    cd "${BUILD_DIR}"

    echo "Start of building ${CORE}: $(date)" > libMicroPython_temp.log

    # Configure, build, and install with CMake
    if [ $use_clang -eq 1 ]
    then
        cmake "${CORE_DIR}" -GNinja -DUSE_LLVM=ON
    else
        cmake "${CORE_DIR}" -GNinja
    fi
    cmake --build . --parallel
    cmake --install . --prefix "${PATH_PRG}"   # installs libMicroPython.a in Library/${CORE}/

    echo "End of building ${CORE}: $(date)" >> libMicroPython_temp.log
    mv libMicroPython_temp.log "${PATH_PRG}/Library/${CORE}/libMicroPython_ready.txt"
    cd "${PATH_PRG}"
    rm -r "${BUILD_DIR}"
}

# Build all cores

for core in CORTEX_M4 CORTEX_M7 CORTEX_M33 CORTEX_M55 CORTEX_M85; do
    build_core "${core}"
done

echo -e "\n${GREEN}All MicroPython libraries built successfully!${NC}"
