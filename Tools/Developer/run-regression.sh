#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Description:
#   Full regression build script using CMake out-of-source builds.
#   Builds all system targets followed by all applications into a
#   dedicated 'artefacts' directory.
#   Applications tied to a single C library (see CLIB_ONLY_GROUPS) are
#   skipped when another C library is selected.
#   Everything printed on stdout is mirrored into a generated
#   regression-results-XXXXXX.sh, which prints those results again when run.
#
# Usage:
#   ./run-regression.sh [-G] [-P|-L] [-U] [-Y] [-v] [-n] [-t <target>]
#
# Options:
#   -G  Use gcc compiler
#   -P  Use picolibc
#   -L  Use llvmlibc (LLVM libc; requires clang, ARM and RISC-V targets)
#   -U  Privileged mode only (User mode OFF)
#   -Y  Disable canary stack protection
#   -v  Verbose: display full build output
#   -n  Do not produce a results script
#   -t  Filter by target name (e.g. Nucleo_H743)
#

emulate -L zsh
setopt NO_UNSET PIPE_FAIL EXTENDED_GLOB NULL_GLOB
zmodload zsh/zutil

# Recorded in the results script; zparseopts -D consumes the options further down
readonly -a ARGV_ORIG=("$@")

# Colours
readonly RED=$'\033[0;31m'
readonly GREEN=$'\033[0;32m'
readonly YELLOW=$'\033[0;33m'
readonly BLUE=$'\033[0;34m'
readonly BOLD=$'\033[1m'
readonly NC=$'\033[0m'

# Paths ( :A resolves symlinks, so the root is correct when called through Tools/Developer/bin )
readonly PATH_ROOT="${0:A:h:h:h}"
readonly PATH_ARTEFACTS="${PATH_ROOT:h}/artefacts"
readonly PATH_VARIANTS_YAML="${PATH_ROOT}/Ports/Targets/variants.yaml"
readonly PATH_APPS_YAML="${PATH_ROOT}/Applications/uKOS_Appls_Downloadable/apps.yaml"

# PATH_ARTEFACTS is removed below and sits outside the repository; refuse to run on a wrong root
if [[ ! -f "${PATH_VARIANTS_YAML}" || ! -f "${PATH_APPS_YAML}" ]]; then
    printf "%bError: %s does not look like a uKOS-X tree%b\n" "${RED}" "${PATH_ROOT}" "${NC}" >&2
    exit 1
fi

# Application groups that only build against one specific C library. n_NewLibs
# demonstrates the newlib manager: its source includes "newlib/newlib.h", which
# pulls <sys/reent.h> - a header picolibc and LLVM libc do not provide.
typeset -rA CLIB_ONLY_GROUPS=(
    n_NewLibs newlib
)

# Defaults (LLVM, as in the _build.sh scripts)
COMPILER="llvm"
USE_LLVM="ON"
USER_MODE="ON"
CANARY="ON"
VERBOSE=0
NO_RESULTS=0
TARGET_FILTER=""
C_LIB="newlib"

usage() {
    cat <<'EOF'
Usage: ./run-regression.sh [-G] [-P|-L] [-U] [-Y] [-v] [-n] [-t <target>]

Options:
  -G  Use gcc compiler
  -P  Use picolibc
  -L  Use llvmlibc (LLVM libc; requires clang, ARM and RISC-V targets)
  -U  Privileged mode only
  -Y  Disable canary stack protection
  -v  Verbose: display full build output
  -n  Do not produce a results script
  -t  Filter by target name (e.g. Nucleo_H743)
  -h  Show this help message
EOF
}

# Parse options with zparseopts. -P and -L both feed a single array so that
# passing both can be detected as a conflict (they are mutually exclusive).
# Pre-initialise every result array because the script runs under NO_UNSET.

o_gcc=() clib_flag=() o_user=() o_canary=() o_verbose=() o_nores=() o_filter=() o_help=()

zparseopts -D -F - \
    G=o_gcc \
    P=clib_flag \
    L=clib_flag \
    U=o_user \
    Y=o_canary \
    v=o_verbose \
    n=o_nores \
    t:=o_filter \
    h=o_help || { usage; exit 1; }

# -h short-circuits everything else
if (( $#o_help )); then
    usage
    exit 0
fi

# -P (picolibc) and -L (llvmlibc) are mutually exclusive
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
(( $#o_gcc ))    && { COMPILER="gcc"; USE_LLVM="OFF"; }
(( $#o_user ))   && USER_MODE="OFF"
(( $#o_canary )) && CANARY="OFF"
(( $#o_verbose )) && VERBOSE=1
(( $#o_nores ))  && NO_RESULTS=1
(( $#o_filter )) && TARGET_FILTER=${o_filter[2]}

case ${clib_flag[1]:-} in
    -P) C_LIB="picolibc" ;;
    -L) C_LIB="llvmlibc"; COMPILER="llvm"; USE_LLVM="ON" ;;
    '') ;;                             # keep default (newlib)
esac

# Determine the preset (systems and applications share the same matrix)
PRESET="${COMPILER}"

# Results script
#
# Everything this script prints on stdout goes through emit(), which mirrors the
# printf into a generated zsh script; running that script prints the results
# again. mktemp only substitutes trailing 'X's on BSD/macOS, so the '.sh' suffix
# is appended afterwards rather than being part of the template. Failing to
# create the file is not fatal: PATH_RESULTS stays empty and nothing is
# recorded. An interrupted run leaves a partial results script behind.
#
# -n suppresses the recording altogether rather than deleting the file at the
# end, so an interrupted run leaves nothing behind either.
PATH_RESULTS=""
results_tmp=""
results_argv=()
if (( NO_RESULTS == 0 )); then
    if results_tmp=$(mktemp "regression-results-XXXXXX" 2>/dev/null) &&
       mv -- "${results_tmp}" "${results_tmp}.sh" 2>/dev/null; then
        PATH_RESULTS="${PWD}/${results_tmp}.sh"
        chmod u+x "${PATH_RESULTS}"      # BSD chmod has no '--' separator

        # quote element by element; "${(q+)ARGV_ORIG}" would join first and quote once
        results_argv=("${(@q+)ARGV_ORIG}")

        {
            print -r -- '#!/usr/bin/env zsh'
            print -r -- '# SPDX-License-Identifier: MIT'
            print -r -- '# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen'
            print -r -- '#'
            print -r -- "# Regression results recorded on $(date '+%Y-%m-%d %H:%M:%S')."
            print -r -- "# Invocation: ${0:t} ${results_argv[*]}"
            cat <<'EOF'
# Run this script to print those results again.

emulate -L zsh

readonly RED=$'\033[0;31m'
readonly GREEN=$'\033[0;32m'
readonly YELLOW=$'\033[0;33m'
readonly BLUE=$'\033[0;34m'
readonly BOLD=$'\033[1m'
readonly NC=$'\033[0m'

EOF
        } > "${PATH_RESULTS}"
    else
        printf "%bWarning:%b cannot create a results script in %s; the results are not recorded.\n" \
               "${YELLOW}" "${NC}" "${PWD}" >&2
        [[ -n "${results_tmp}" ]] && rm -f -- "${results_tmp}"
    fi
fi

# Symbolic names for the colour arguments, so that the recorded commands read
# like the originals instead of carrying raw escape sequences
typeset -rA RESULT_COLOURS=(
    "${RED}"          '${RED}'
    "${GREEN}"        '${GREEN}'
    "${YELLOW}"       '${YELLOW}'
    "${BLUE}"         '${BLUE}'
    "${BOLD}"         '${BOLD}'
    "${NC}"           '${NC}'
    "${BOLD}${BLUE}"  '${BOLD}${BLUE}'
)

# printf on stdout, mirrored into the results script as a replayable command.
# (q+) quotes minimally and leaves the format string untouched, so the recorded
# printf interprets it exactly as this one does.
emit() {
    printf "$@"
    [[ -n "${PATH_RESULTS}" ]] || return 0

    local -a parts=()
    local arg name
    for arg in "$@"; do
        name="${RESULT_COLOURS[${arg}]:-}"
        if [[ -n "${name}" ]]; then
            parts+=("\"${name}\"")
        else
            parts+=("${(q+)arg}")
        fi
    done
    print -r -- "printf ${parts[*]}" >> "${PATH_RESULTS}"
}

# Dump a build log on stdout and embed it in the results script. The log itself
# is embedded rather than referenced, because it lives under PATH_ARTEFACTS,
# which the next regression run deletes.
emit_file() {
    local file="$1"

    cat -- "${file}"
    [[ -n "${PATH_RESULTS}" ]] || return 0

    {
        print -r -- "cat <<'UKOS_REGRESSION_LOG_EOF'"
        cat -- "${file}"
        # a log not ending in a newline would glue the terminator to its last line
        [[ -n "$(tail -c1 -- "${file}")" ]] && print
        print -r -- "UKOS_REGRESSION_LOG_EOF"
    } >> "${PATH_RESULTS}"
}

# Close the results script and ask whether to keep it. With -n there is no file,
# and the question is skipped when stdin is not a terminal (read -q would fail
# with "can't open terminal"), the file then being kept. The outcome describes
# the file rather than the run, so it is printed but not recorded.
finish_results() {
    local exit_code="$1"

    [[ -n "${PATH_RESULTS}" ]] || return 0

    print -r -- "exit ${exit_code}" >> "${PATH_RESULTS}"

    if [[ -t 0 ]]; then
        printf "\n"
        if ! read -q "?Keep the results script ${PATH_RESULTS} ? [y/N] "; then
            printf "\n"
            rm -f -- "${PATH_RESULTS}"
            printf "Results script removed.\n"
            return 0
        fi
        printf "\n"
    fi

    printf "\nResults script: %s\n" "${PATH_RESULTS}"
}

rm -fr "${PATH_ARTEFACTS}"

emit "%bStarting Regression Test%b\n" "${BOLD}${BLUE}" "${NC}"
emit "Source:    %s\n" "${PATH_ROOT}"
emit "Artefacts: %s\n" "${PATH_ARTEFACTS}"
emit "Compiler:  %s (LLVM=%s)\n" "${COMPILER}" "${USE_LLVM}"
emit "C library: %s\n" "${C_LIB}"
emit "Options:   USER_MODE=%s, CANARY=%s\n" "${USER_MODE}" "${CANARY}"
[[ -n "${TARGET_FILTER}" ]] && emit "Filter:    Target = %s\n" "${TARGET_FILTER}"
emit "\n"

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

    (( ++total_builds ))
    emit "Building %-65s " "${name}"

    local log_file="${build_dir}/build.log"
    mkdir -p "${build_dir}" || return 1

    # Clean previous log
    : > "${log_file}"

    # Configuration step
    # Systems and applications share the same preset matrix; only the system
    # build redirects its artefacts into the build tree. -B overrides the
    # binaryDir of the preset, which keeps the out-of-source layout.
    local -a config_args=(--preset "${PRESET}"
                          -DC_LIBRARY="${C_LIB}"
                          -DUSER_MODE="${USER_MODE}"
                          -DCANARY="${CANARY}")
    [[ "$name" == App:* ]] || config_args+=(-DARTEFACTS_DIR="${build_dir}/System")

    cmake -S "${source_dir}" -B "${build_dir}" "${config_args[@]}" \
          "${extra_args[@]}" >> "${log_file}" 2>&1

    if [[ $? -eq 0 ]]; then
        # Build step
        cmake --build "${build_dir}" -j >> "${log_file}" 2>&1
        if [[ $? -eq 0 ]]; then
            emit "%b[PASS]%b\n" "${GREEN}" "${NC}"
            (( ++success_count ))
            return 0
        fi
    fi

    emit "%b[FAIL]%b\n" "${RED}" "${NC}"
    (( ++fail_count ))
    failed_list+=("${name}")
    [[ ${VERBOSE} -eq 1 ]] && emit_file "${log_file}"
    return 1
}

# 1. Build System Targets
emit "%b[1/2] Building System Targets%b\n" "${BOLD}" "${NC}"
while IFS=$'\t' read -r family variant; do
    # Apply filter if provided
    if [[ -n "${TARGET_FILTER}" && "${family}" != "${TARGET_FILTER}" ]]; then
        continue
    fi

    src="${PATH_ROOT}/Ports/Targets/${family}/Variant_${variant}"
    build_root="${PATH_ARTEFACTS}/build/Targets/${family}/${variant}/${PRESET}"
    install_dir="${PATH_ARTEFACTS}/Targets/${family}/${variant}/${PRESET}"

    if [[ ! -d "${src}" ]]; then
        emit "%b[SKIP]%b (Source not found: %s)\n" "${YELLOW}" "${NC}" "${family}/Variant_${variant}"
        continue
    fi

    build_target "${src}" "${build_root}" "System: ${family}/${variant}"

    if [[ $? -eq 0 ]]; then
        cmake --install "${build_root}" --prefix "${install_dir}" >> "${build_root}/build.log" 2>&1
    fi
done < <(yq eval 'to_entries[] | .key as $f | .value[] | "\($f)\t\(.name)"' "${PATH_VARIANTS_YAML}")

# 2. Build Applications
emit "\n%b[2/2] Building Applications%b\n" "${BOLD}" "${NC}"
while IFS=$'\t' read -r group project target_board; do
    # Apply filter if provided
    if [[ -n "${TARGET_FILTER}" && "${target_board}" != "${TARGET_FILTER}" ]]; then
        continue
    fi

    # Skip the groups that require a C library other than the selected one
    required_clib="${CLIB_ONLY_GROUPS[${group}]:-}"
    if [[ -n "${required_clib}" && "${required_clib}" != "${C_LIB}" ]]; then
        emit "%b[SKIP]%b (%s requires the %s C library)\n" "${YELLOW}" "${NC}" \
             "${group}/${project}/${target_board}" "${required_clib}"
        continue
    fi

    src="${PATH_ROOT}/Applications/uKOS_Appls_Downloadable/${group}/${project}/${target_board}"
    build_root="${PATH_ARTEFACTS}/build/Apps/${group}/${project}/${target_board}/${PRESET}"

    if [[ ! -d "${src}" ]]; then
        emit "%b[SKIP]%b (Source not found: %s)\n" "${YELLOW}" "${NC}" "${group}/${project}/${target_board}"
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
emit "\n%bRegression Summary%b\n" "${BOLD}${BLUE}" "${NC}"
emit "Total builds: %d\n" "${total_builds}"
emit "Success:      %b%d%b\n" "${GREEN}" "${success_count}" "${NC}"
emit "Failed:       %b%d%b\n" "${RED}" "${fail_count}" "${NC}"

integer exit_code=0

if (( total_builds == 0 )); then
    emit "\n%bNo targets matched the filter: %s%b\n" "${YELLOW}" "${TARGET_FILTER}" "${NC}"
elif (( fail_count > 0 )); then
    emit "\n%bFailed Targets:%b\n" "${RED}" "${NC}"
    for f in "${failed_list[@]}"; do
        emit " - %s\n" "${f}"
    done
    exit_code=1
else
    emit "\n%bAll builds completed successfully.%b\n" "${GREEN}" "${NC}"
fi

finish_results ${exit_code}
exit ${exit_code}
