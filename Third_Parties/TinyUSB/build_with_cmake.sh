#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Purpose:
#   Build the TinyUSB package using CMake

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL

# Determine script directory (works if executed via ./script.sh or zsh script.sh)

readonly PATH_PRG="${0:a:h}"

# Colours for messages

readonly RED=$'\033[0;31m'
readonly GREEN=$'\033[0;32m'
readonly YELLOW=$'\033[0;33m'
readonly BLUE=$'\033[0;34m'
readonly BOLD=$'\033[1m'
readonly FAINT=$'\033[2m'
readonly ITALIC=$'\033[3m'
readonly NC=$'\033[0m' # No Colour

# Packages
# --------

readonly package=0.21.0
readonly hash=4354b24

TinyUSB_PACK="TinyUSB-current"

# Clone the right package

printf '\n%bDownload the TinyUSB package ...%b\n\n' "${BOLD}" "${NC}"

cd "${PATH_PRG}"
if [[ ! -d "${TinyUSB_PACK}" ]]; then
    git clone https://github.com/hathach/tinyusb.git "${TinyUSB_PACK}"
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


# Patch the package (for pico2 hazard3)
echo "$PWD"
local patch_rc=0
local patch_output
patch_output=$(patch -p1 --forward < ./Construction/Interface/Patches/mcu/raspberrypi/pico2/hazard3.patch 2>&1) \
    || patch_rc=$?

if (( patch_rc == 0 )); then
    print "  [patch] hazard3: applied."
elif print "$patch_output" | grep -q "Reversed.*patch detected\|previously applied"; then
    print "  [patch] hazard3: already applied, ignored."
else
    print "  [patch] hazard3: FAIL (rc=${patch_rc})" >&2
    print "$patch_output" >&2
    return 1
fi

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
    SOC_DIR="${PATH_PRG}/Construction/Family/${family}/${soc}"
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
    if cmake .. -G Ninja -DCMAKE_INSTALL_PREFIX="${PATH_PRG}"; then
        # Build all targets
        if cmake --build . -j ; then
            # Install the built libraries
            if cmake --install . ; then
            echo "End of building: $(date)" >> ../libTinyUSB_temp.log
            mv ../libTinyUSB_temp.log ../libTinyUSB_cmake_ready.txt
                echo -e "${GREEN}Successfully built and installed ${soc}${NC}"
        else
                echo -e "${RED}Install failed for ${soc}${NC}"
                echo "Install failed: $(date)" >> ../libTinyUSB_temp.log
                mv ../libTinyUSB_temp.log ../libTinyUSB_cmake_error.txt
            fi
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
