#!/usr/bin/env zsh

#------------------------------------------------------------------------
# SPDX-License-Identifier: MIT
#
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Project: uKOS-X
#
# Purpose:
#   Building all the uKOS downloadable applications using CMake.
#
# Usage:
#    cd cloned_directory/Applications/uKOS_Appls_Downloadable
#    ./_build_cmake.sh [-L] [-U] [-Y] [-v|-w]
#------------------------------------------------------------------------

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL EXTENDED_GLOB

# Determine script directory (works if executed via ./script.sh or bash script.sh)

readonly PATH_PRG="${0:a:h}"

if [[ -z "${PATH_GCC_ARM:-}" ]]; then
    printf "Variable PATH_GCC_ARM is not set! ARM targets will not build!\n" >&2
fi

if [[ -z "${PATH_GCC_RVXX:-}" ]]; then
    printf "Variable PATH_GCC_RVXX is not set! RISC-V targets will not build!\n" >&2
fi

if [[ -z "${PATH_LLVM_ARM:-}" ]]; then
    printf "Variable PATH_LLVM_ARM is not set! ARM targets will not build!\n" >&2
fi

if [[ -z "${PATH_LLVM_RVXX:-}" ]]; then
    printf "Variable PATH_LLVM_RVXX is not set! RISC-V targets will not build!\n" >&2
fi

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

CMAKE_CANARY_MODE=""
CMAKE_USER_MODE=""
COMPILER_TOOL="LLVM clang"
TOOLCHAIN_VAR=""
VERBOSITY=""

usage() {
    cat <<EOF
Usage: ./_build_cmake.sh [-L] [-U] [-Y] [-v|-w]

Options:
  -G    Use gcc compiler
  -U    Privileged mode only (USER_MODE=OFF)
  -Y    Disable canary stack protection (CANARY_MODE=OFF)
  -v    Verbose: display warnings and errors
  -w    Keep warnings/errors in log files
  -h    Show this help message
EOF
}

OPTSTRING=":GUYvwh"
while getopts ${OPTSTRING} option; do
    case ${option} in
        h)
            usage
            exit 0
            ;;
        G)
            COMPILER_TOOL="gcc"
            TOOLCHAIN_VAR="-DUSE_LLVM=OFF"
            ;;
        U)
            CMAKE_USER_MODE="-DUSER_MODE=OFF"
            ;;
        Y)
            CMAKE_CANARY_MODE="-DCANARY=OFF"
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

case ${COMPILER_TOOL} in
    "gcc")
        gcc_arm_version=$(${PATH_GCC_ARM}/bin/arm-none-eabi-gcc --version | awk 'NR==1{print $3; exit}')
        gcc_rvxx_version=$(${PATH_GCC_RVXX}/bin/riscv64-unknown-elf-gcc --version | awk 'NR==1{print $3; exit}')
        COMPILER_VERSIONS="arm:${gcc_arm_version} - riscv:${gcc_rvxx_version}"
        ;;
    "LLVM clang")
        llvm_arm_version=$(${PATH_LLVM_ARM}/bin/clang --version | awk 'NR==1{for(i=1;i<=NF;i++)if($i=="version"){print $(i+1); exit}}')
        llvm_rvxx_version=$(${PATH_LLVM_RVXX}/bin/clang --version | awk 'NR==1{for(i=1;i<=NF;i++)if($i=="version"){print $(i+1); exit}}')
        COMPILER_VERSIONS="arm:${llvm_arm_version} - riscv:${llvm_rvxx_version}"
        ;;
esac

cmake_version=$(cmake --version | head -1 | awk '{print $3}')
printf "%bUsing cmake %s and %s (%s)%b\n" "${YELLOW}" "${cmake_version}" "${COMPILER_TOOL}" "${COMPILER_VERSIONS}" "${NC}"

process_option() {
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

# Parse apps.yaml file using yq
parse_apps_yaml() {
    local yaml_file="${PATH_PRG}/apps.yaml"

    if ! [[ -f "${yaml_file}" ]]; then
        printf "%bError: YAML file not found: %s%b\n" "${RED}" "${yaml_file}" "${NC}" >&2
        exit 1
    fi

    if ! command -v yq >/dev/null 2>&1; then
        printf "%bError: yq is not installed%b\n" "${RED}" "${NC}" >&2
        exit 1
    fi

    # Parse YAML: iterate through families, projects, and targets
    yq eval 'to_entries[] | .key as $family | .value | to_entries[] | .key as $project | .value[] | "\($family)/\($project)/\(.)"' "${yaml_file}"
}

build_failure=""
build_warning=""
build_success=""
readonly LOG_FILE="build/compilation.log"

printf "%bBuilding all the downloadable applications with CMake options %s %s %s%b\n" "${BOLD}" "${TOOLCHAIN_VAR}" "${CMAKE_USER_MODE}" "${CMAKE_CANARY_MODE}" "${NC}"
# Parse YAML and iterate through all build targets
while IFS= read -r CURRENT_TARGET; do
    printf "%s " "${CURRENT_TARGET}"
    cd "${PATH_PRG}/${CURRENT_TARGET}"
    rm -fr build >/dev/null

    # Normal output on the stdout, error/warnings on comp.log
    # If comp.log empty     -> "PASS"
    # If comp.log not empty -> "WARNING"
    # If make error         -> "FAIL"

    was_error=0
    cmake -S . -B build ${TOOLCHAIN_VAR} ${CMAKE_CANARY_MODE} ${CMAKE_USER_MODE} >/dev/null && \
    cmake --build build >/dev/null 2>"${LOG_FILE}" || was_error=1
    if (( was_error == 0 )); then
        if [[ ! -s "${LOG_FILE}" ]]; then
            build_success+=$'\n'"${CURRENT_TARGET}"
            printf "%bPASS%b\n" "${GREEN}" "${NC}"
            rm -f "${LOG_FILE}"
        else
            build_warning+=$'\n'"${CURRENT_TARGET}"
            printf "%bWARNING%b\n" "${YELLOW}" "${NC}"
            process_option "${LOG_FILE}"
        fi
    else
        build_failure+=$'\n'"${CURRENT_TARGET}"
        printf "%bFAIL%b\n" "${RED}" "${NC}"
        process_option "${LOG_FILE}"
    fi
done < <(parse_apps_yaml)

# Display the target list that with warnings

if [[ -n "${build_warning}" ]]; then
    printf "%bBuild with warning:%b%s\n" "${YELLOW}" "${NC}" "${build_warning}"
fi

# Display the target list that have failed

if [[ -n "${build_failure}" ]]; then
    printf "%bFailed builds:%b%s\n" "${RED}" "${NC}" "${build_failure}"
fi
printf "%bTerminated!%b\n" "${BOLD}" "${NC}"
