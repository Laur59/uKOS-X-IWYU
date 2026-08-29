#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Purpose: Build all the projects.
#
# Usage:
#       cd cloned_directory/Ports/Targets
#       ./_build.sh [-G] [-P|-L] [-U] [-Y] [-v|-w]

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL EXTENDED_GLOB
zmodload zsh/zutil

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
readonly NC=$'\033[0m' # No Color

# Defaults

COMPILER_TOOL="LLVM clang"
VERBOSITY=""
CANARY_MODE="ON"
USER_MODE="ON"
C_LIB="newlib"

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
Usage: ./_build.sh [-G] [-P|-L] [-U] [-Y] [-v|-w]

Options:
  -G  Use gcc compiler
  -P  Use picolibc
  -L  Use llvmlibc (LLVM libc; requires clang, ARM and RISC-V targets)
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

o_gcc=() clib_flag=() o_user=() o_canary=() o_verbose=() o_write=() o_help=()

zparseopts -D -F - \
    G=o_gcc \
    P=clib_flag \
    L=clib_flag \
    U=o_user \
    Y=o_canary \
    v=o_verbose \
    w=o_write \
    h=o_help || { usage; exit 1; }

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
# -L cannot be combined with -G (gcc). Checked before -L rewrites COMPILER_TOOL.
if (( $#o_gcc )) && [[ ${clib_flag[1]:-} == -L ]]; then
    printf "%bError:%b -L (llvmlibc) cannot be combined with -G (gcc); llvmlibc requires clang.\n" "${RED}" "${NC}" >&2
    exit 1
fi

# Apply the parsed options
(( $#o_gcc ))    && { COMPILER_TOOL="gcc"; TOOLCHAIN_VAR="-DUSE_LLVM=OFF"; }
(( $#o_user ))   && USER_MODE="OFF"
(( $#o_canary )) && CANARY_MODE="OFF"

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

# Version reported by a toolchain binary, or "unknown" when it cannot be run.
# Without this the script dies on ERR_EXIT at the first missing toolchain, right
# after warning that the corresponding targets "will not build" -- so the warning
# could never be followed by the partial build it promises.
#   $1 toolchain root   $2 binary under bin/   $3 gcc|clang (version field layout)
toolchain_version() {
    local root="$1" binary="$2" flavour="$3" program

    case "${flavour}" in
        gcc)   program='NR==1{print $3; exit}' ;;
        clang) program='NR==1{for(i=1;i<=NF;i++)if($i=="version"){print $(i+1); exit}}' ;;
    esac

    [[ -n "${root}" && -x "${root}/bin/${binary}" ]] || { print -r -- unknown; return 0; }
    print -r -- "$("${root}/bin/${binary}" --version 2>/dev/null | awk "${program}")"
}

case ${COMPILER_TOOL} in
    "gcc")
        # No llvmlibc branch here: -L forces COMPILER_TOOL to clang and -G -L is
        # rejected above, so C_LIB is newlib or picolibc whenever this case runs.
        if [[ "${C_LIB}" == "picolibc" ]]; then
            # picolibc uses dedicated toolchains: PATH_GCC_ARMP (ARM) and PATH_GCC_RVXXP (RISC-V)
            if [[ -z "${PATH_GCC_ARMP:-}" ]]; then
                printf "%bWarning:%b PATH_GCC_ARMP not set; picolibc ARM targets will not build!\n" "${YELLOW}" "${NC}" >&2
            fi
            if [[ -z "${PATH_GCC_RVXXP:-}" ]]; then
                printf "%bWarning:%b PATH_GCC_RVXXP not set; picolibc RISC-V targets will not build!\n" "${YELLOW}" "${NC}" >&2
            fi
            gcc_arm_version=$(toolchain_version "${PATH_GCC_ARMP:-}" arm-none-eabi-gcc gcc)
            gcc_rvxx_version=$(toolchain_version "${PATH_GCC_RVXXP:-}" riscv64-unknown-elf-gcc gcc)
        else
            if [[ -z "${PATH_GCC_ARM:-}" ]]; then
                if ! command -v arm-none-eabi-gcc >/dev/null 2>&1; then
                    printf "%bWarning:%b PATH_GCC_ARM not set and arm-none-eabi-gcc not in PATH; ARM targets will not build!\n" "${YELLOW}" "${NC}" >&2
                fi
            fi
            if [[ -z "${PATH_GCC_RVXX:-}" ]]; then
                if ! command -v riscv64-unknown-elf-gcc >/dev/null 2>&1; then
                    printf "%bWarning:%b PATH_GCC_RVXX not set and riscv64-unknown-elf-gcc not in PATH; RISC-V targets will not build!\n" "${YELLOW}" "${NC}" >&2
                fi
            fi
            gcc_arm_version=$(toolchain_version "${PATH_GCC_ARM:-}" arm-none-eabi-gcc gcc)
            gcc_rvxx_version=$(toolchain_version "${PATH_GCC_RVXX:-}" riscv64-unknown-elf-gcc gcc)
        fi
        COMPILER_VERSIONS="arm:${gcc_arm_version} - riscv:${gcc_rvxx_version}"
        CMAKE_PRESET="gcc"
        ;;
    "LLVM clang")
        if [[ "${C_LIB}" == "llvmlibc" ]]; then
            # llvmlibc uses dedicated toolchains: PATH_LLVM_ARML (ARM) and PATH_LLVM_RVXXL (RISC-V)
            if [[ -z "${PATH_LLVM_ARML:-}" ]]; then
                printf "%bWarning:%b PATH_LLVM_ARML not set; llvmlibc ARM targets will not build!\n" "${YELLOW}" "${NC}" >&2
            fi
            if [[ -z "${PATH_LLVM_RVXXL:-}" ]]; then
                printf "%bWarning:%b PATH_LLVM_RVXXL not set; llvmlibc RISC-V targets will not build!\n" "${YELLOW}" "${NC}" >&2
            fi
            llvm_arm_version=$(toolchain_version "${PATH_LLVM_ARML:-}" clang clang)
            llvm_rvxx_version=$(toolchain_version "${PATH_LLVM_RVXXL:-}" clang clang)
        elif [[ "${C_LIB}" == "picolibc" ]]; then
            # picolibc uses dedicated toolchains: PATH_LLVM_ARMP (ARM) and PATH_LLVM_RVXXP (RISC-V)
            if [[ -z "${PATH_LLVM_ARMP:-}" ]]; then
                printf "%bWarning:%b PATH_LLVM_ARMP not set; picolibc ARM targets will not build!\n" "${YELLOW}" "${NC}" >&2
            fi
            if [[ -z "${PATH_LLVM_RVXXP:-}" ]]; then
                printf "%bWarning:%b PATH_LLVM_RVXXP not set; picolibc RISC-V targets will not build!\n" "${YELLOW}" "${NC}" >&2
            fi
            llvm_arm_version=$(toolchain_version "${PATH_LLVM_ARMP:-}" clang clang)
            llvm_rvxx_version=$(toolchain_version "${PATH_LLVM_RVXXP:-}" clang clang)
        else
            if [[ -z "${PATH_LLVM_ARM:-}" ]]; then
                printf "%bWarning:%b PATH_LLVM_ARM not set; ARM targets will not build!\n" "${YELLOW}" "${NC}" >&2
            fi
            if [[ -z "${PATH_LLVM_RVXX:-}" ]]; then
                printf "%bWarning:%b PATH_LLVM_RVXX not set; RISC-V targets will not build!\n" "${YELLOW}" "${NC}" >&2
            fi
            llvm_arm_version=$(toolchain_version "${PATH_LLVM_ARM:-}" clang clang)
            llvm_rvxx_version=$(toolchain_version "${PATH_LLVM_RVXX:-}" clang clang)
        fi
        COMPILER_VERSIONS="arm:${llvm_arm_version} - riscv:${llvm_rvxx_version}"
        CMAKE_PRESET="llvm"
        ;;
esac

readonly cmake_version=$(cmake --version | awk 'NR==1{print $3; exit}')

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

printf "%bUsing cmake (%s) and %s (%s) to build all the systems with\n" "${YELLOW}" "${cmake_version}" "${COMPILER_TOOL}" "${COMPILER_VERSIONS}"
printf "   %bcmake --preset %s -DC_LIBRARY=%s -DUSER_MODE=%s -DCANARY=%s%b\n" "${BOLD}" "${CMAKE_PRESET}" "${C_LIB}" "${USER_MODE}" "${CANARY_MODE}" "${NC}"
# Parse YAML and iterate through all build targets
while IFS=$'\t' read -r family variant_name; do
    CURRENT_VARIANT="${family}/Variant_${variant_name}"
    printf "%-40s " "${CURRENT_VARIANT}"
    cd "${PATH_PRG}/${CURRENT_VARIANT}"

    # Normal output on the stdout, error/warnings on comp.log
    # If comp.log empty     -> "PASS"
    # If comp.log not empty -> "WARNING"
    # If make error         -> "FAIL"

    was_error=0
    rm -fr build
    cmake --preset "${CMAKE_PRESET}" -DC_LIBRARY=${C_LIB} -DUSER_MODE=${USER_MODE} -DCANARY=${CANARY_MODE} &>/dev/null && \
    cmake --build build --parallel >"${LOG_FILE}" 2>&1 || was_error=1

    # Filter out Ninja progress lines (e.g., "[1/100] Building...") to keep only warnings/errors
    if [ -f "${LOG_FILE}" ]; then
        grep -v '^\[' "${LOG_FILE}" > "${LOG_FILE}.filtered" 2>/dev/null || true
        mv "${LOG_FILE}.filtered" "${LOG_FILE}"
        sed -i '' '/Memory region/,$d' "${LOG_FILE}"    # macOS / BSD sed
    fi

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
