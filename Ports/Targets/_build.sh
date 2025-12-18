#!/usr/bin/env zsh

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:   Laurent von Allmen  The 2025-01-01
# Modifs:
#
# Project:  uKOS-X
# Goal:     Build all the projects.
#
#           usage: sourced by build.sh
#           cd cloned_directory/Ports/Targets
#           ./_build_cmake.sh [-L] [-U] [-Y] [-v|-w]
#
#   (c) 2025-20xx, Laurent von Allmen
#   ---------------------------------
#                                              __ ______  _____
#   Edo. Franzi                         __  __/ //_/ __ \/ ___/
#   5-Route de Cheseaux                / / / / ,< / / / /\__ \
#   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
#                                     \__,_/_/ |_\____//____/
#   edo.franzi@ukos.ch
#
#   Description: Lightweight, real-time multitasking operating
#   system for embedded microcontroller and DSP-based systems.
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

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL EXTENDED_GLOB

# Determine script directory (works if executed via ./script.sh or zsh script.sh)

readonly PATH_PRG="${0:a:h}"

# Colours for messages

readonly RED='\033[0;31m'
readonly GREEN='\033[0;32m'
readonly YELLOW='\033[0;33m'
readonly BLUE='\033[0;34m'
readonly BOLD='\033[1m'
readonly FAINT='\033[2m'
readonly ITALIC='\033[3m'
readonly NC='\033[0m' # No Color

# Defaults

COMPILER_TOOL="gcc"
VERBOSITY=""
CANARY_MODE="ON"
USER_MODE="ON"

# Cleanup trap (runs on Ctrl-C)
cleanup() {
    printf "\n%bBuild interrupted by user%b\n" "${YELLOW}" "${NC}" >&2

    # If -w was passed, keep BUILD_DIR for inspection
    if [ "${VERBOSITY}" = "-w" ]; then
        printf "%bBuild artifacts preserved in: %s%b\n" "${YELLOW}" "${BUILD_DIR}" "${NC}" >&2
    else
        # Clean up BUILD_DIR if not keeping logs
        if [ -n "${BUILD_DIR:-}" ] && [ -d "${BUILD_DIR}" ]; then
            rm -rf "${BUILD_DIR}" 2>/dev/null || true
            printf "%bBuild directory cleaned up%b\n" "${YELLOW}" "${NC}" >&2
        fi
    fi

    exit 130
}

trap cleanup INT TERM

usage() {
    cat <<'EOF'
Usage: ./_build_cmake.sh [-L] [-U] [-Y] [-v|-w]

Options:
  -L  Use LLVM/clang compiler
  -U  Privileged mode only
  -Y  Disable canary stack protection
  -v  Verbose: display warnings and errors
  -w  Keep error and warning messages in log file
  -h  Show this help message
EOF
}

readonly OPTSTRING=":LUYvwh"
while getopts "${OPTSTRING}" option; do
    case "${option}" in
        h)
            usage
            exit 0
            ;;
        L)
            COMPILER_TOOL="LLVM clang"
            ;;
        U)
            USER_MODE="OFF"
            ;;
        Y)
            CANARY_MODE="OFF"
            ;;
        v)
            VERBOSITY="-v"
            ;;
        w)
            # -v (verbose) takes precedence over -w (write log)
            if [[ "${VERBOSITY}" != "-v" ]]; then
                VERBOSITY="-w"
            fi
            ;;
        ?)
            printf "Invalid option: -%s\n" "${OPTARG}" >&2
            exit 1
            ;;
    esac
done

get_cmake_preset() {
    local compiler="$1"
    local user_mode="$2"
    local canary_mode="$3"
    local preset="${compiler}"

    if [ "$user_mode" = "OFF" ]; then
        preset="${preset}-nouser"
        if [ "$canary_mode" = "ON" ]; then
            preset="${preset}-canary"
        else
            preset="${preset}-nocanary"
        fi
    else
        # user_mode = ON
        if [ "$canary_mode" = "OFF" ]; then
            preset="${preset}-user-nocanary"
        fi
        # When user_mode=ON and canary_mode=ON, preset stays as just "${compiler}"
    fi

    echo "$preset"
}

case ${COMPILER_TOOL} in
    "gcc")
        if [[ -z "${PATH_GCC_ARM}" ]]; then
            if ! command -v arm-none-eabi-gcc >/dev/null 2>&1; then
                printf "%bWarning:%b PATH_GCC_ARM not set and arm-none-eabi-gcc not in PATH; ARM targets will not build!\n" "${YELLOW}" "${NC}" >&2
            fi
        fi
        if [[ -z "${PATH_GCC_RVXX}" ]]; then
            if ! command -v riscv64-unknown-elf-gcc >/dev/null 2>&1; then
                printf "%bWarning:%b PATH_GCC_RVXX not set and riscv64-unknown-elf-gcc not in PATH; RISC-V targets will not build!\n" "${YELLOW}" "${NC}" >&2
            fi
        fi
        gcc_arm_version=$("${PATH_GCC_ARM}"/bin/arm-none-eabi-gcc --version | awk 'NR==1{print $3; exit}')
        gcc_rvxx_version=$("${PATH_GCC_RVXX}"/bin/riscv64-unknown-elf-gcc --version | awk 'NR==1{print $3; exit}')
        COMPILER_VERSIONS="arm:${gcc_arm_version} - riscv:${gcc_rvxx_version}"
        CMAKE_PRESET=$(get_cmake_preset "gcc" "${USER_MODE}" "${CANARY_MODE}")
        ;;
    "LLVM clang")
        if [[ -z "${PATH_LLVM_ARM}" ]]; then
            printf "%bWarning:%b PATH_LLVM_ARM not set; ARM targets will not build!\n" "${YELLOW}" "${NC}" >&2
        fi
        if [[ -z "${PATH_LLVM_RVXX}" ]]; then
            printf "%bWarning:%b PATH_LLVM_RVXX not set; RISC-V targets will not build!\n" "${YELLOW}" "${NC}" >&2
        fi
        llvm_arm_version=$("${PATH_LLVM_ARM}"/bin/clang --version | awk 'NR==1{for(i=1;i<=NF;i++)if($i=="version"){print $(i+1); exit}}')
        llvm_rvxx_version=$("${PATH_LLVM_RVXX}"/bin/clang --version | awk 'NR==1{for(i=1;i<=NF;i++)if($i=="version"){print $(i+1); exit}}')
        COMPILER_VERSIONS="arm:${llvm_arm_version} - riscv:${llvm_rvxx_version}"
        CMAKE_PRESET=$(get_cmake_preset "llvm" "${USER_MODE}" "${CANARY_MODE}")
        ;;
esac

readonly cmake_version=$(cmake --version | awk 'NR==1{print $3; exit}')
printf "%bUsing cmake (%s) and %s (%s)%b\n" "${YELLOW}" "${cmake_version}" "${COMPILER_TOOL}" "${COMPILER_VERSIONS}" "${NC}"

process_option()
{
    local log_file="$1"
    case "${VERBOSITY}" in
        "-v")
            cat "${log_file}"
            rm -f "${log_file}"
            ;;
        "-w")
            ;;
        *)
            rm -f "${log_file}"
            ;;
    esac
}

# Parse variants.yaml file using yq
parse_variants_yaml() {
    local yaml_file="${PATH_PRG}/variants.yaml"

    if ! [[ -f "${yaml_file}" ]]; then
        printf "%bError: YAML file not found: %s%b\n" "${RED}" "${yaml_file}" "${NC}" >&2
        exit 1
    fi

    if ! command -v yq >/dev/null 2>&1; then
        printf "%bError: yq is not installed%b\n" "${RED}" "${NC}" >&2
        exit 1
    fi

    # Parse YAML: iterate through families and their variants
    yq eval 'to_entries[] | .key as $family | .value[] | "\($family)\t\(.name)"' "${yaml_file}"
}

build_failure=""
build_success=""
readonly LOG_FILE="build/compilation.log"

printf "%bBuilding all the systems with --preset %s%b (USER_MODE=%s CANARY=%s)\n" "${BOLD}" "${CMAKE_PRESET}" "${NC}" "${USER_MODE}" "${CANARY_MODE})"
# Parse YAML and iterate through all build targets
while IFS=$'\t' read -r family variant_name; do
    CURRENT_VARIANT="${family}/Variant_${variant_name}"
    printf "%s " "${CURRENT_VARIANT}"
    cd "${PATH_PRG}/${CURRENT_VARIANT}"

    # Normal output on the stdout, error/warnings on comp.log
    # If comp.log empty     -> "PASS"
    # If comp.log not empty -> "WARNING"
    # If make error         -> "FAIL"

    was_error=0
    rm -fr build
    cmake --preset "${CMAKE_PRESET}" >/dev/null && \
    cmake --build build --parallel >"${LOG_FILE}" 2>&1 || was_error=1

    # Filter out Ninja progress lines (e.g., "[1/100] Building...") to keep only warnings/errors
    if [ -f "${LOG_FILE}" ]; then
        grep -v '^\[' "${LOG_FILE}" > "${LOG_FILE}.filtered" 2>/dev/null || true
        mv "${LOG_FILE}.filtered" "${LOG_FILE}"
    fi
    sed -i '' '/Memory region/,$d' "${LOG_FILE}"    # macOS / BSD sed

    if (( was_error == 0 )); then
        build_success+=$'\n'"${CURRENT_VARIANT}"
        # Check if the file is empty
        if [ ! -s "${LOG_FILE}" ]; then
            printf "%bPASS%b\n" "${GREEN}" "${NC}"
            rm -f "${LOG_FILE}"
        else
            printf "%bWARNING%b\n" "${YELLOW}" "${NC}"
            process_option "${LOG_FILE}"
        fi
    else
        build_failure+=$'\n'"${CURRENT_VARIANT}"
        printf "%bFAIL%b\n" "${RED}" "${NC}"
        process_option "${LOG_FILE}"
    fi
done < <(parse_variants_yaml)

# Display the target list that have failed

if [[ -n "${build_failure}" ]]; then
    printf "%bFailed builds:%b%s\n" "${RED}" "${NC}" "${build_failure}"
fi
printf "%bTerminated!%b\n" "${BOLD}" "${NC}"
