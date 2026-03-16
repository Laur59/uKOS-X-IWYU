#!/usr/bin/env zsh

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# run-regression.sh
# =================
#
# Project:  uKOS-X
#
# Description:
#   Full regression build script using CMake out-of-source builds.
#   Builds all system targets followed by all applications into a
#   dedicated 'artefacts' directory.
#
# Usage:
#   ./run-regression.sh [-L] [-U] [-Y] [-v] [-t <target>]
#
# Options:
#   -L  Use LLVM/clang compiler
#   -U  Privileged mode only (User mode OFF)
#   -Y  Disable canary stack protection
#   -v  Verbose: display full build output
#   -t  Filter by target name (e.g. Nucleo_H743)
#
#------------------------------------------------------------------------

emulate -L zsh
setopt NO_UNSET PIPE_FAIL EXTENDED_GLOB NULL_GLOB

# Colours
readonly RED=$'\033[0;31m'
readonly GREEN=$'\033[0;32m'
readonly YELLOW=$'\033[0;33m'
readonly BLUE=$'\033[0;34m'
readonly BOLD=$'\033[1m'
readonly NC=$'\033[0m'

# Paths
readonly PATH_ROOT="${0:a:h:h:h}"
readonly PATH_ARTEFACTS="${PATH_ROOT:h}/artefacts"
readonly PATH_VARIANTS_YAML="${PATH_ROOT}/Ports/Targets/variants.yaml"
readonly PATH_APPS_YAML="${PATH_ROOT}/Applications/uKOS_Appls_Downloadable/apps.yaml"

# Defaults
COMPILER="gcc"
USE_LLVM="OFF"
USER_MODE="ON"
CANARY="ON"
VERBOSE=0
TARGET_FILTER=""

while getopts "LUYvt:" option; do
    case "${option}" in
        L) COMPILER="llvm"; USE_LLVM="ON" ;;
        U) USER_MODE="OFF" ;;
        Y) CANARY="OFF" ;;
        v) VERBOSE=1 ;;
        t) TARGET_FILTER="${OPTARG}" ;;
        *) exit 1 ;;
    esac
done

# Determine Preset (only used for Systems)
PRESET="${COMPILER}"
[[ "${USER_MODE}" == "OFF" ]] && PRESET+="-nouser"
[[ "${CANARY}" == "OFF" ]] && PRESET+="-nocanary"

printf "%bStarting Regression Test%b\n" "${BOLD}${BLUE}" "${NC}"
printf "Source:    %s\n" "${PATH_ROOT}"
printf "Artefacts: %s\n" "${PATH_ARTEFACTS}"
printf "Compiler:  %s (LLVM=%s)\n" "${COMPILER}" "${USE_LLVM}"
printf "Options:   USER_MODE=%s, CANARY=%s\n" "${USER_MODE}" "${CANARY}"
[[ -n "${TARGET_FILTER}" ]] && printf "Filter:    Target = %s\n" "${TARGET_FILTER}"
printf "\n"

# Statistics
integer total_builds=0
integer success_count=0
integer fail_count=0
failed_list=()

# Helper to build a target
build_target() {
    local source_dir="$1"
    local build_dir="$2"
    local name="$3"
    shift 3
    local extra_args=("$@")

    (( total_builds++ ))
    printf "Building %-65s " "${name}"

    local log_file="${build_dir}/build.log"
    mkdir -p "${build_dir}" || return 1

    # Clean previous log
    : > "${log_file}"

    # Configuration step
    if [[ "$name" == App:* ]]; then
        # Applications don't have presets, use manual flags
        cmake -S "${source_dir}" -B "${build_dir}" \
              -DUSE_LLVM="${USE_LLVM}" \
              -DUSER_MODE="${USER_MODE}" \
              -DCANARY="${CANARY}" \
              "${extra_args[@]}" >> "${log_file}" 2>&1
    else
        # Systems use presets
        cmake -S "${source_dir}" -B "${build_dir}" --preset "${PRESET}" \
              -DARTEFACTS_DIR="${build_dir}/System" "${extra_args[@]}" >> "${log_file}" 2>&1
    fi

    if [[ $? -eq 0 ]]; then
        # Build step
        cmake --build "${build_dir}" -j >> "${log_file}" 2>&1
        if [[ $? -eq 0 ]]; then
            printf "%b[PASS]%b\n" "${GREEN}" "${NC}"
            (( success_count++ ))
            return 0
        fi
    fi

    printf "%b[FAIL]%b\n" "${RED}" "${NC}"
    (( fail_count++ ))
    failed_list+=("${name}")
    [[ ${VERBOSE} -eq 1 ]] && cat "${log_file}"
    return 1
}

# 1. Build System Targets
printf "%b[1/2] Building System Targets%b\n" "${BOLD}" "${NC}"
while IFS=$'\t' read -r family variant; do
    # Apply filter if provided
    if [[ -n "${TARGET_FILTER}" && "${family}" != "${TARGET_FILTER}" ]]; then
        continue
    fi

    src="${PATH_ROOT}/Ports/Targets/${family}/Variant_${variant}"
    build_root="${PATH_ARTEFACTS}/build/Targets/${family}/${variant}/${PRESET}"
    install_dir="${PATH_ARTEFACTS}/Targets/${family}/${variant}/${PRESET}"

    if [[ ! -d "${src}" ]]; then
        printf "%b[SKIP]%b (Source not found: %s)\n" "${YELLOW}" "${NC}" "${family}/Variant_${variant}"
        continue
    fi

    build_target "${src}" "${build_root}" "System: ${family}/${variant}"

    if [[ $? -eq 0 ]]; then
        cmake --install "${build_root}" --prefix "${install_dir}" >> "${build_root}/build.log" 2>&1
    fi
done < <(yq eval 'to_entries[] | .key as $f | .value[] | "\($f)\t\(.name)"' "${PATH_VARIANTS_YAML}")

# 2. Build Applications
printf "\n%b[2/2] Building Applications%b\n" "${BOLD}" "${NC}"
while IFS=$'\t' read -r group project target_board; do
    # Apply filter if provided
    if [[ -n "${TARGET_FILTER}" && "${target_board}" != "${TARGET_FILTER}" ]]; then
        continue
    fi

    src="${PATH_ROOT}/Applications/uKOS_Appls_Downloadable/${group}/${project}/${target_board}"
    build_root="${PATH_ARTEFACTS}/build/Apps/${group}/${project}/${target_board}/${PRESET}"

    if [[ ! -d "${src}" ]]; then
        printf "%b[SKIP]%b (Source not found: %s)\n" "${YELLOW}" "${NC}" "${group}/${project}/${target_board}"
        continue
    fi

    # Detect which variant this app needs
    variant_name=$(grep "set(VARIANT " "${src}/CMakeLists.txt" | sed 's/.*Variant_\([^)]*\).*/\1/' | tr -d '[:space:]' | tr -d '"' | tr -d "'")
    [[ -z "${variant_name}" ]] && variant_name="Test"

    sys_install_dir="${PATH_ARTEFACTS}/Targets/${target_board}/${variant_name}/${PRESET}"

    # Fallback search if the specific variant isn't installed
    if [[ ! -d "${sys_install_dir}" ]]; then
        local candidates=(${PATH_ARTEFACTS}/Targets/${target_board}/*/${PRESET}(N/))
        if [[ ${#candidates} -gt 0 ]]; then
            sys_install_dir="${candidates[1]}"
        fi
    fi

    build_target "${src}" "${build_root}" "App: ${group}/${project} (${target_board})" \
                 "-DSYSTEM_INSTALL_DIR=${sys_install_dir}"
done < <(yq eval 'to_entries[] | .key as $g | .value | to_entries[] | .key as $p | .value[] | "\($g)\t\($p)\t\(.)"' "${PATH_APPS_YAML}")

# Summary
printf "\n%bRegression Summary%b\n" "${BOLD}${BLUE}" "${NC}"
printf "Total builds: %d\n" "${total_builds}"
printf "Success:      %b%d%b\n" "${GREEN}" "${success_count}" "${NC}"
printf "Failed:       %b%d%b\n" "${RED}" "${fail_count}" "${NC}"

if (( total_builds == 0 )); then
    printf "\n%bNo targets matched the filter: %s%b\n" "${YELLOW}" "${TARGET_FILTER}" "${NC}"
    exit 0
fi

if (( fail_count > 0 )); then
    printf "\n%bFailed Targets:%b\n" "${RED}" "${NC}"
    for f in "${failed_list[@]}"; do
        printf " - %s\n" "${f}"
    done
    exit 1
fi

printf "\n%bAll builds completed successfully.%b\n" "${GREEN}" "${NC}"
exit 0
