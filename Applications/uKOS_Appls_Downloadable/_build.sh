#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Purpose:
#   Building all the uKOS downloadable applications using CMake.
#
# Usage:
#    cd cloned_directory/Applications/uKOS_Appls_Downloadable
#    ./_build.sh [-L] [-U] [-Y] [-v|-w]

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL EXTENDED_GLOB
zmodload zsh/zutil

# Determine script directory (works if executed via ./script.sh or bash script.sh)

readonly PATH_PRG="${0:a:h}"

if [[ -z "${PATH_GCC_ARM:-}" ]]; then
    printf 'Variable PATH_GCC_ARM is not set! ARM targets will not build!\n' >&2
fi

if [[ -z "${PATH_GCC_RVXX:-}" ]]; then
    printf 'Variable PATH_GCC_RVXX is not set! RISC-V targets will not build!\n' >&2
fi

if [[ -z "${PATH_LLVM_ARM:-}" ]]; then
    printf 'Variable PATH_LLVM_ARM is not set! ARM targets will not build!\n' >&2
fi

if [[ -z "${PATH_LLVM_RVXX:-}" ]]; then
    printf 'Variable PATH_LLVM_RVXX is not set! RISC-V targets will not build!\n' >&2
fi

# Colours for messages

readonly RED=$'\033[0;31m'
readonly GREEN=$'\033[0;32m'
readonly YELLOW=$'\033[0;33m'
readonly BLUE=$'\033[0;34m'
readonly BOLD=$'\033[1m'
readonly FAINT=$'\033[2m'
readonly ITALIC=$'\033[3m'
readonly NC=$'\033[0m' # No Color

# Defaults

CMAKE_CANARY_MODE=''
CMAKE_USER_MODE=''
COMPILER_TOOL='LLVM clang'
TOOLCHAIN_VAR=''
VERBOSITY=''
C_LIB="newlib"

usage() {
    cat <<'EOF'
Usage: ./_build.sh [-G] [-P|-L] [-U] [-Y] [-v|-w]

Options:
  -G  Use gcc compiler
  -P  Use picolibc
  -L  Use llvmlibc (LLVM libc; requires clang, ARM targets only)
  -U  Privileged mode only
  -Y  Disable canary stack protection
  -v  Verbose: display warnings and errors
  -w  Keep error and warning messages in log file
  -h  Show this help message
EOF
}

# Parse options with zparseopts. -P and -L both feed a single array so that
# passing both can be detected as a conflict (they are mutually exclusive).
# Pre-initialise every result array because the script runs under NO_UNSET.

o_gcc=() o_user=() o_canary=() o_verbose=() o_write=() o_help=() clib_flag=()

zparseopts -D -F - \
    G=o_gcc \
    U=o_user \
    Y=o_canary \
    v=o_verbose \
    w=o_write \
    h=o_help \
    P=clib_flag \
    L=clib_flag || { usage; exit 1; }

# -h short-circuits everything else
if (( $#o_help )); then
    usage
    exit 0
fi

# -P (picolibc) and -L (llvmlibc) are mutually exclusive
clib_flag=(${(u)clib_flag})            # dedupe so -PP / -MM is not a conflict
if (( $#clib_flag > 1 )); then
    printf "%bError:%b -P and -L are mutually exclusive.\n" "${RED}" "${NC}" >&2
    usage
    exit 1
fi

# llvmlibc is a Clang/LLVM-only C library (Arm Toolchain for Embedded), so
# -M cannot be combined with -G (gcc). Checked before -M rewrites COMPILER_TOOL.
if (( $#o_gcc )) && [[ ${clib_flag[1]:-} == -L ]]; then
    printf "%bError:%b -M (llvmlibc) cannot be combined with -G (gcc); llvmlibc requires clang.\n" "${RED}" "${NC}" >&2
    exit 1
fi

# Apply the parsed options
if (( $#o_gcc )); then
    COMPILER_TOOL="gcc"
    TOOLCHAIN_VAR="-DUSE_LLVM=OFF"
else
    COMPILER_TOOL="LLVM clang"
    TOOLCHAIN_VAR="-DUSE_LLVM=ON"
fi
if (( $#o_user )); then
    CMAKE_USER_MODE="-DUSER_MODE=OFF"
else
    CMAKE_USER_MODE="-DUSER_MODE=ON"
fi
if (( $#o_canary )); then
    CMAKE_CANARY_MODE="-DCANARY=OFF"
else
    CMAKE_CANARY_MODE="-DCANARY=ON"
fi

# -v (verbose) takes precedence over -w (write log)
if (( $#o_verbose )); then
    VERBOSITY="-v"
elif (( $#o_write )); then
    VERBOSITY="-w"
fi

case ${clib_flag[1]:-} in
    -P) C_LIB="picolibc" ;;
    -L) C_LIB="llvmlibc"; COMPILER_TOOL="LLVM clang"; TOOLCHAIN_VAR="" ;;
    '') ;;                             # keep default (newlib)
esac

case ${COMPILER_TOOL} in
    "gcc")
        gcc_arm_version=$(${PATH_GCC_ARM}/bin/arm-none-eabi-gcc --version | awk 'NR==1{print $3; exit}')
        gcc_rvxx_version=$(${PATH_GCC_RVXX}/bin/riscv64-unknown-elf-gcc --version | awk 'NR==1{print $3; exit}')
        COMPILER_VERSIONS="arm:${gcc_arm_version} - riscv:${gcc_rvxx_version}"
        ;;
    "LLVM clang")
        # llvmlibc uses a dedicated ARM toolchain (PATH_LLVM_ARML) and is ARM-only
        if [[ "${C_LIB}" == "llvmlibc" ]]; then
            llvm_arm_version=$(${PATH_LLVM_ARML:-}/bin/clang --version | awk 'NR==1{for(i=1;i<=NF;i++)if($i=="version"){print $(i+1); exit}}')
            COMPILER_VERSIONS="arm:${llvm_arm_version}"
        else
            llvm_arm_version=$(${PATH_LLVM_ARM:-}/bin/clang --version | awk 'NR==1{for(i=1;i<=NF;i++)if($i=="version"){print $(i+1); exit}}')
            llvm_rvxx_version=$(${PATH_LLVM_RVXX:-}/bin/clang --version | awk 'NR==1{for(i=1;i<=NF;i++)if($i=="version"){print $(i+1); exit}}')
            COMPILER_VERSIONS="arm:${llvm_arm_version} - riscv:${llvm_rvxx_version}"
        fi
        ;;
esac

cmake_version=$(cmake --version | awk 'NR==1{print $3; exit}')
printf '%bUsing cmake (%s) and %s (%s)%b\n' "${YELLOW}" "${cmake_version}" "${COMPILER_TOOL}" "${COMPILER_VERSIONS}" "${NC}"

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

printf '%bBuilding all the downloadable applications with:\n' "${YELLOW}"
printf '   %bcmake -S . -B build %s %s %s -DC_LIBRARY=%s%b\n' "${BOLD}" "${TOOLCHAIN_VAR}" "${CMAKE_USER_MODE}" "${CMAKE_CANARY_MODE}" "${C_LIB}" "${NC}"
# Parse YAML and iterate through all build targets
while IFS= read -r CURRENT_TARGET; do
    printf "%-40s " "${CURRENT_TARGET}"
    cd "${PATH_PRG}/${CURRENT_TARGET}"
    rm -fr build >/dev/null

    # Normal output on the stdout, error/warnings on comp.log
    # If comp.log empty     -> "PASS"
    # If comp.log not empty -> "WARNING"
    # If make error         -> "FAIL"

    was_error=0
    cmake -S . -B build ${TOOLCHAIN_VAR} ${CMAKE_CANARY_MODE} ${CMAKE_USER_MODE} -DC_LIBRARY=${C_LIB} >/dev/null && \
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
