#!/usr/bin/env bash

# build.
# ======

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:   Laurent von Allmen  The 2025-10-07
# Modifs:
#
# Project:  uKOS-X
# Goal:     Build the MicroPython package and the libMicroPython.a (including the uKOS interface)
#
#   Copyright 2025-2026, Laurent von Allmen
#   ---------------------------------------
#                                              __ ______  _____
#   Edo. Franzi                         __  __/ //_/ __ \/ ___/
#   5-Route de Cheseaux                / / / / ,< / / / /\__ \
#   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
#                                     \__,_/_/ |_\____//____/
#   edo.franzi@ukos.ch
#
#   Permission is hereby granted, free of charge, to any person
#   obtaining a copy of this software and associated documentation
#   files (the "Software"), to deal in the Software without restriction,
#   including without limitation the rights to use, copy, modify,
#   merge, publish, distribute, sublicense, and/or sell copies of the
#   Software, and to permit persons to whom the Software is furnished
#   to do so, subject to the following conditions:
#
#   The above copyright notice and this permission notice shall be
#   included in all copies or substantial portions of the Software.
#
#   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
#   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
#   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
#   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
#   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
#   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
#   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#   SOFTWARE.
#
#------------------------------------------------------------------------

set -euo pipefail

# Determine script directory

# Script runs under bash (see shebang), so use BASH_SOURCE
PATH_PRG="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

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

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BOLD='\033[1m'
FAINT='\033[2m'
ITALIC='\033[3m'
NC='\033[0m' # No Color

# Package version / commit / tag and directories

MICROPY_REF="${1:-v1.26.1}"   # default tag v1.26.1 if none passed
MICROPY_DIR="${PATH_PRG}/MicroPython-current"
MICROPY_LIBRARY_DIR="${PATH_PRG}/Library"
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
    cmake --install .   # installs libMicroPython.a in ${CORE_DIR}

    echo "End of building ${CORE}: $(date)" >> libMicroPython_temp.log
    mv libMicroPython_temp.log ../libMicroPython_ready.txt
    cd ..
    rm -r "${BUILD_DIR}"
}

# Build all cores

for core in CORTEX_M4 CORTEX_M7 CORTEX_M33 CORTEX_M55; do
    build_core "${core}"
done

echo -e "\n${GREEN}All MicroPython libraries built successfully!${NC}"
