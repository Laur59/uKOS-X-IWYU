#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Checks that header files are self-contained across multiple targets.
# Usage: check-self-contained.sh <files-list> [target …]
#   <files-list>  text file with one header path per line; blank lines and
#                 lines starting with '#' are ignored.
#   [target …]   optional list of targets to check against; defaults to all
#                 known targets when omitted.
# For each target a CMake/LLVM build is configured once to produce
# compile_commands.json; the extracted compile command is then re-run with
# -fsyntax-only (full parse and type-check, no code generation) against every
# header under test. A header passes if and only if it compiles in isolation —
# no missing includes, no undeclared identifiers.

emulate -L zsh
setopt NO_UNSET PIPE_FAIL

# Colours for messages
readonly RED=$'\033[0;31m'
readonly GREEN=$'\033[0;32m'
readonly YELLOW=$'\033[0;33m'
readonly BLUE=$'\033[0;34m'
readonly BOLD=$'\033[1m'
readonly FAINT=$'\033[2m'
readonly ITALIC=$'\033[3m'
readonly NC=$'\033[0m' # No Color

# Build the clang -fsyntax-only command for a target (cmake configured once)
build_cmd() {
    local target_name=$1
    local build_dir=/tmp/check-self/${target_name//\//_}

    rm -fr "${build_dir}" && cmake -S Ports/Targets/${target_name} -B "${build_dir}" \
        -DUSE_LLVM=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=ON > /dev/null 2>&1 || return 1

    local cmd
    cmd=$(jq -r '.[0].command' "${build_dir}/compile_commands.json")
    cmd=${cmd%-o *}
    cmd=${cmd/ --/ -fsyntax-only --}
    cmd=${(S)cmd/ -DuKOS_OWNER=\"*\"/}
    printf '%s' "${cmd}"
}

# Check one header against a pre-built command
check_header() {
    local target_name=$1
    local cmd=$2
    local header_file=$3

    printf '%s%-40s%s' "${GREEN}" "${target_name}" "${NC}"

    local errors
    if errors=$(${=cmd} ${header_file} 2>&1 >/dev/null); then
        printf ' %s✓ PASS%s\n' "${GREEN}" "${NC}"
        return 0
    else
        printf ' %s✗ FAIL%s\n' "${RED}" "${NC}"
        printf '%s\n' "${errors}"
        return 1
    fi
}

if [[ $# -lt 1 || ! -f $1 ]]; then
    printf '%sUsage: %s <files-list> [target …]%s\n' "${RED}" "$0" "${NC}" >&2
    exit 1
fi

readonly files_list=$1
shift

all_targets=(
    "Alastor_H743/Variant_Test"
    "Asmodee_H747/Variant_Test_CM4"
    "Asmodee_H747/Variant_Test_CM7"
    "DevKit_nRF5340/Variant_Test_App"
    "Discovery_U5G9/Variant_Test"
    "MAiXDUiNO_K210/Variant_Test"
    "Nucleo_F207/Variant_Test"
    "Nucleo_H743/Variant_Test"
    "Nucleo_L4R5/Variant_Test"
    "Nucleo_N657/Variant_Test"
    "Pico2_rp2350/Variant_Test"
)
targets=("${@:-${all_targets[@]}}")

# Configure each target once and cache the clang command
printf '%sConfiguring targets…%s\n' "${FAINT}" "${NC}"
typeset -A target_cmds
for target in "${targets[@]}"; do
    printf '%s  %-40s%s' "${FAINT}" "${target}" "${NC}"
    if cmd=$(build_cmd "${target}"); then
        target_cmds[${target}]=${cmd}
        printf '%s ok%s\n' "${FAINT}" "${NC}"
    else
        printf '%s FAILED (skipped)%s\n' "${RED}" "${NC}"
    fi
done

# Run checks: one line per (header, target) pair
while IFS= read -r file_under_test || [[ -n ${file_under_test} ]]; do
    [[ -z ${file_under_test} || ${file_under_test} == '#'* ]] && continue
    printf '%s%s%s\n' "${BOLD}" "${file_under_test}" "${NC}"
    for target in "${targets[@]}"; do
        [[ -z ${target_cmds[${target}]} ]] && continue
        check_header "${target}" "${target_cmds[${target}]}" "${file_under_test}"
    done
done < "${files_list}"
