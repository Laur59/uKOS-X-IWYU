#!/usr/bin/env bash

# build_with_cmake.
# =================

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:   Laurent von Allmen      The 2025-10-11
# Modifs:
#
# Project:  uKOS-X
# Goal:     Build the TinyUSB package using CMake
#
#   © 2025-2026, Laurent von Allmen
#   -------------------------------
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

# Determine script directory (works if executed via ./script.sh or bash script.sh)

PATH_PRG="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Colours for messages

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BOLD='\033[1m'
FAINT='\033[2m'
ITALIC='\033[3m'
NC='\033[0m' # No Colour

# Packages
# --------

package=0.20.0
hash=2b9a778

TinyUSB_PACK="TinyUSB-current"

# Clone the right package

printf '\n%bDownload the TinyUSB package ...%b\n\n' "${BOLD}" "${NC}"

cd "${PATH_PRG}"
if [ ! -d "${TinyUSB_PACK}" ]; then
    git clone https://github.com/hathach/tinyusb "${TinyUSB_PACK}"
    git -C "${TinyUSB_PACK}" submodule update --init lib
else
    git -C "${TinyUSB_PACK}" fetch --quiet
fi
git -C "${TinyUSB_PACK}" checkout ${hash}

# Clone the pico-sdk package

printf '\n%bDownload the pico-sdk package ...%b\n\n' "${BOLD}" "${NC}"

if [[ ! -d "${TinyUSB_PACK}"/lib/pico-sdk ]]; then
    cd "${TinyUSB_PACK}"/lib
    git clone https://github.com/raspberrypi/pico-sdk.git
    cd pico-sdk
    git submodule update --init --recursive
    cd "${PATH_PRG}"
fi
git -C "${TinyUSB_PACK}"/lib/pico-sdk pull


# Parse core.yaml file using yq
parse_core_yaml() {
    local yaml_file="core.yaml"

    if ! [[ -f "${yaml_file}" ]]; then
        printf "%bError: YAML file not found: %s%b\n" "${RED}" "${yaml_file}" "${NC}" >&2
        exit 1
    fi

    if ! command -v yq >/dev/null 2>&1; then
        printf "%bError: yq is not installed%b\n" "${RED}" "${NC}" >&2
        exit 1
    fi

    # Parse YAML: iterate through families, SOCs, and profiles
    # Output format: family \t dependency \t soc \t profile
    yq eval 'to_entries[] | .key as $family | .value[] | .dependency as $dep | .soc as $soc | .profiles[] | "\($family)\t\($dep)\t\($soc)\t\(.)"' "${yaml_file}"
}

printf '\n%bBuilding all TinyUSB libraries with CMake ...%b\n' "${BOLD}" "${NC}"

# Check if PATH_GCC_ARM is set
if [ -z "${PATH_GCC_ARM:-}" ]; then
    echo -e "${RED}Error: PATH_GCC_ARM environment variable is not set${NC}"
    echo -e "Please set it to your ARM GCC toolchain path, e.g.:"
    echo -e "  export PATH_GCC_ARM=/path/to/gcc-arm-none-eabi"
    exit 1
fi

# Track the current SOC to avoid running get-deps multiple times for the same SOC
prev_soc=""


# Parse YAML and iterate through all build targets
while IFS=$'\t' read -r family dependency soc profile; do

    # Note: Dependencies (like Nordic nrfx) are now fetched automatically by CMake
    # using FetchContent when needed. No manual intervention required.

    # Check if CMakeLists.txt exists for this SOC
    SOC_DIR="${PATH_PRG}/Library/Family/${family}/${soc}"
    if [ ! -f "${SOC_DIR}/CMakeLists.txt" ]; then
        echo -e "${YELLOW}Skipping $${soc} - CMakeLists.txt not found${NC}"
        continue
    fi

    # Build using CMake
    printf '%bBuilding libraries for SOC %s using CMake ...%b\n' "${BOLD}" "${soc}" "${NC}"

    cd "${SOC_DIR}"
    BUILD_DIR="build_cmake"

    # Clean previous build if it exists
    if [ -d "${BUILD_DIR}" ]; then
        rm -rf "${BUILD_DIR}"
    fi

    # Create build directory and run CMake
    mkdir -p "${BUILD_DIR}"
    cd "${BUILD_DIR}"

    echo "Start of building: $(date)" > ../libTinyUSB_temp.log

    # Configure with CMake
    if cmake .. -G Ninja; then
        # Build all targets
        if cmake --build . -j ; then
            echo "End of building: $(date)" >> ../libTinyUSB_temp.log
            mv ../libTinyUSB_temp.log ../libTinyUSB_cmake_ready.txt
            echo -e "${GREEN}Successfully built ${soc}${NC}"
        else
            echo -e "${RED}Build failed for ${soc}${NC}"
            echo "Build failed: $(date)" >> ../libTinyUSB_temp.log
            mv ../libTinyUSB_temp.log ../libTinyUSB_cmake_error.txt
        fi
    else
        echo -e "${RED}CMake configuration failed for ${soc}${NC}"
        echo "CMake configuration failed: $(date)" >> ../libTinyUSB_temp.log
        mv ../libTinyUSB_temp.log ../libTinyUSB_cmake_error.txt
    fi

    # Go back to script directory
    cd "${PATH_PRG}"
done < <(parse_core_yaml)

printf '\n🎉 %bCMake build  process completed%b\n\n' "${GREEN}" "${NC}"
