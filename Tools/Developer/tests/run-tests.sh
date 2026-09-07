#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# Description:
#   Build and run the host (native) unit tests for uKOS-X CLI modules.
#   The modules under test are compiled unmodified; a force-included shim
#   neutralises the three things a Mach-O host cannot take.
#
#   Before configuring, two drift checks compare the hand-copied production
#   code in this directory against its original. They exist because a silent
#   divergence would leave the tests passing against stale semantics.
#
# Usage:
#   ./run-tests.sh [-v] [-s] [-k] [-i] [-t <name>]
#
# Options:
#   -v  Verbose: show the full build output and each test name
#   -s  Build with the address and undefined-behaviour sanitizers
#   -k  Keep the build directory (do not wipe it first)
#   -i  Isolate: run every test in its own process
#   -c  Drive the run through ctest instead of the executables
#   -t  Run only the tests whose name contains <name>
#

emulate -L zsh
setopt NO_UNSET PIPE_FAIL
zmodload zsh/zutil

# Colours
readonly RED=$'\033[0;31m'
readonly GREEN=$'\033[0;32m'
readonly YELLOW=$'\033[0;33m'
readonly BOLD=$'\033[1m'
readonly NC=$'\033[0m'

# Paths ( :A resolves symlinks, so the root is correct when called through
#         Tools/Developer/bin; one :h deeper than the Tools/Developer scripts )
readonly PATH_TESTS="${0:A:h}"
readonly PATH_ROOT="${0:A:h:h:h:h}"
readonly PATH_BUILD="${PATH_ROOT:h}/artefacts/host-tests"

# PATH_BUILD is removed below and sits outside the repository; refuse to run on a wrong root
if [[ ! -f "${PATH_ROOT}/OS/Includes/modules.h" || ! -f "${PATH_ROOT}/OS/CLI/date/date.c" ]]; then
    printf "%bError: %s does not look like a uKOS-X tree%b\n" "${RED}" "${PATH_ROOT}" "${NC}" >&2
    exit 1
fi

local -a o_verbose o_sanitize o_keep o_isolate o_ctest o_filter
zparseopts -D -E -- v=o_verbose s=o_sanitize k=o_keep i=o_isolate c=o_ctest t:=o_filter || {
    printf "Usage: %s [-v] [-s] [-k] [-i] [-c] [-t <name>]\n" "${0:t}" >&2
    exit 1
}

readonly VERBOSE=${#o_verbose}
readonly SANITIZE=${#o_sanitize}
readonly KEEP=${#o_keep}
readonly ISOLATE=${#o_isolate}
readonly USE_CTEST=${#o_ctest}
readonly FILTER=${o_filter[2]:-}

# ---------------------------------------------------------------------------
# Drift checks
#
# Two pieces of production code are duplicated under this directory because
# their original cannot be compiled on the host. Both are compared here so the
# copies cannot rot unnoticed.
# ---------------------------------------------------------------------------

# Extract the multi-line MODULE() definition (a #define continued with '\')
extract_module() {
    awk '/^#define[[:blank:]]+MODULE\(/ { f = 1 }
         f                              { print; if ($0 !~ /\\$/) { exit } }' "$1"
}

# Extract the PRIVILEGE_ELEVATE / PRIVILEGE_RESTORE block. Both are #ifndef
# guarded in the real per-core headers, which is what makes the stub a copy of an
# override-sanctioned block rather than an invention - and what makes this check
# possible at all.
# Two spellings exist in the tree: "#ifndef PRIVILEGE_ELEVATE" and
# "#if (!defined(PRIVILEGE_ELEVATE))". Match either, so a core using the second
# is compared rather than silently skipped; normalise() folds them together.
extract_privilege() {
    awk '/^#if.*PRIVILEGE_(ELEVATE|RESTORE)/ { f = 1; d = 0 }
         f { print
             if ($0 ~ /^#if/)    { d++ }
             if ($0 ~ /^#endif/) { d--; if (d == 0) { f = 0 } } }' "$1"
}

# Extract the text_checkAsciiBuffer() definition, up to its closing brace
extract_checkascii() {
    awk '/^int32_t[[:blank:]]+text_checkAsciiBuffer\(/ { f = 1 }
         f                                             { print; if ($0 ~ /^\}/) { exit } }' "$1"
}

# Ignore line continuations, the deliberately changed section literal and any
# difference in horizontal whitespace
normalise() {
    sed -e 's/[[:space:]]*\\$//' \
        -e 's/"__DATA,__directory"/".directory"/' \
        -e 's/^#if[[:blank:]]*(!defined(\([A-Z_]*\)))[[:blank:]]*$/#ifndef \1/' \
        -e 's/^#if[[:blank:]]*(defined(\([A-Z_]*\)))[[:blank:]]*$/#ifdef \1/' \
    | tr -s ' \t' '  ' \
    | sed -e 's/^ *//' -e 's/ *$//' \
    | grep -v '^$'
}

check_drift() {
    local label="$1" original="$2" copy="$3" extractor="$4"

    # An anchor that matches nothing extracts nothing, and two empty extractions
    # diff clean - so without this the check would report success while checking
    # nothing at all. That is the failure mode these guards exist to prevent, so
    # it must never be the quiet one.
    local nb_original nb_copy
    nb_original=$("${extractor}" "${original}" | wc -l | tr -d ' ')
    nb_copy=$("${extractor}" "${copy}" | wc -l | tr -d ' ')
    if [[ "${nb_original}" -eq 0 || "${nb_copy}" -eq 0 ]]; then
        printf "%bExtractor found nothing: %s%b\n" "${RED}" "${label}" "${NC}" >&2
        printf "  %s: %s lines\n  %s: %s lines\n" \
               "${original}" "${nb_original}" "${copy}" "${nb_copy}" >&2
        printf "  the anchor no longer matches; the check was verifying nothing\n" >&2
        return 1
    fi

    if ! diff -u <("${extractor}" "${original}" | normalise) \
                 <("${extractor}" "${copy}"     | normalise) > /dev/null; then
        printf "%bDrift: %s%b\n" "${RED}" "${label}" "${NC}" >&2
        printf "  original: %s\n  copy:     %s\n" "${original}" "${copy}" >&2
        diff -u <("${extractor}" "${original}" | normalise) \
                <("${extractor}" "${copy}"     | normalise) >&2
        return 1
    fi
    printf "  %bok%b  %s\n" "${GREEN}" "${NC}" "${label}"
    return 0
}

printf "%bDrift checks%b\n" "${BOLD}" "${NC}"

typeset -i drift=0
check_drift "MODULE()            shim vs OS/Includes/modules.h" \
            "${PATH_ROOT}/OS/Includes/modules.h" \
            "${PATH_TESTS}/shim/ukos_host_shim.h" \
            extract_module || drift=1

check_drift "text_checkAsciiBuffer  fake vs OS/Lib_generics/text/text.c" \
            "${PATH_ROOT}/OS/Lib_generics/text/text.c" \
            "${PATH_TESTS}/fakes/ukos_fakes_text.c" \
            extract_checkascii || drift=1

check_drift "PRIVILEGE_*         port stub vs Cores/CORTEX_M7" \
            "${PATH_ROOT}/Ports/EquatesModels/Cores/CORTEX_M7/Includes/macros_core.h" \
            "${PATH_TESTS}/port/macros_core.h" \
            extract_privilege || drift=1

# The same block should be identical across the cores. A divergence here is a
# warning, not an abort: a new core legitimately arriving with a different
# scheme must not block the host suite. CORTEX_M85 writes the guard as
# "#if (!defined(X))" and its inner guard as "#if (defined(X))"; normalise()
# folds both into the #ifndef / #ifdef forms, so it is compared like the rest -
# those are spellings, not differences in what the macros do. RV64IMAFDC has no PRIVILEGED_USER_S arm at all and is
# the one genuine exception, excluded by name rather than silently tolerated.
readonly -a PRIV_CORES=(CORTEX_M3 CORTEX_M4 CORTEX_M33 CORTEX_M55 CORTEX_M85 RV32IMAC)
for core in "${PRIV_CORES[@]}"; do
    header="${PATH_ROOT}/Ports/EquatesModels/Cores/${core}/Includes/macros_core.h"
    [[ -f "${header}" ]] || continue
    if ! diff -q <(extract_privilege "${PATH_ROOT}/Ports/EquatesModels/Cores/CORTEX_M7/Includes/macros_core.h" | normalise) \
                 <(extract_privilege "${header}" | normalise) > /dev/null; then
        printf "  %bwarn%b  PRIVILEGE_* differs in %s (stub follows CORTEX_M7)\n" \
               "${YELLOW}" "${NC}" "${core}"
    fi
done

if (( drift )); then
    printf "%bAborting: a copied definition no longer matches its original.%b\n" "${RED}" "${NC}" >&2
    exit 1
fi

# ---------------------------------------------------------------------------
# Configure, build, run
# ---------------------------------------------------------------------------

if (( ! KEEP )); then
    rm -rf "${PATH_BUILD}"
fi
mkdir -p "${PATH_BUILD}"

local -a cmake_args=(-G Ninja -S "${PATH_TESTS}" -B "${PATH_BUILD}")
if (( SANITIZE )); then
    cmake_args+=(-DUKOS_TESTS_SANITIZE=ON)
fi

printf "\n%bConfigure%b\n" "${BOLD}" "${NC}"
if (( VERBOSE )); then
    cmake "${cmake_args[@]}" || exit 1
else
    cmake "${cmake_args[@]}" > /dev/null || {
        printf "%bConfigure failed; re-run with -v%b\n" "${RED}" "${NC}" >&2
        exit 1
    }
fi

printf "\n%bBuild%b\n" "${BOLD}" "${NC}"
if (( VERBOSE )); then
    cmake --build "${PATH_BUILD}" || exit 1
else
    cmake --build "${PATH_BUILD}" > /dev/null || {
        printf "%bBuild failed; re-run with -v%b\n" "${RED}" "${NC}" >&2
        exit 1
    }
fi

# A suite must never hang, and two of them do: the loaders spin forever against
# unfixed code, which is the defect they exist to detect. macOS ships no
# timeout(1), so run in the background, poll, and kill. 124 is what GNU timeout
# uses, kept so a caller can tell a timeout from a failure.
#
# 10 seconds is not a guess: a suite takes about 3 MILLISECONDS, so this is
# three orders of magnitude of headroom and still bounds a hung run at a few
# seconds rather than minutes. Sanitizers slow things down but nowhere near
# that far; the budget triples under -s anyway.

typeset -i KTIMEOUT=10
(( SANITIZE )) && KTIMEOUT=30

local_runTimed() {
    local outfile="$1"; shift
    local -i waited=0

    "$@" > "${outfile}" 2>&1 &
    local -i pid=$!

    while (( waited < KTIMEOUT * 10 )); do
        kill -0 ${pid} 2>/dev/null || break
        sleep 0.1
        (( waited++ ))
    done

    if kill -0 ${pid} 2>/dev/null; then
        kill -9 ${pid} 2>/dev/null
        wait ${pid} 2>/dev/null
        return 124
    fi
    wait ${pid}
    return $?
}

# Suites this branch expects to fail, because it adds the tests without the
# source fixes they assert. See EXPECTED-FAILURES for the reasoning; the file is
# the record of what has been detected, not a way to silence anything.

typeset -A EXPECTED
typeset expected_file="${PATH_TESTS}/EXPECTED-FAILURES"
if [[ -r "${expected_file}" ]]; then
    typeset -a fields
    while IFS= read -r line; do
        [[ "${line}" == \#* || -z "${line// }" ]] && continue

        # Word-split rather than pattern-strip: the columns are padded for
        # legibility, and rejoining fields 2.. normalises that away.
        fields=(${=line})
        (( ${#fields} >= 2 )) || continue
        EXPECTED[${fields[1]}]="${fields[2,-1]}"
    done < "${expected_file}"
fi

printf "\n%bRun%b\n" "${BOLD}" "${NC}"

# One process per test: a crash becomes a single reported failure instead of
# losing the whole run.
if (( ISOLATE )); then
    typeset -i failed=0 total=0
    typeset exe_filter
    typeset tmp_out; tmp_out=$(mktemp)
    for exe in "${PATH_BUILD}"/ukos_tests_*(N.x); do
        printf "%b%s%b\n" "${BOLD}" "${exe:t}" "${NC}"
        # As in the default path, -t matches an executable name as well as a
        # test name; otherwise "-i -t port_x" silently runs nothing.
        if [[ -n "${FILTER}" && "${exe:t}" == *"${FILTER}"* ]]; then
            exe_filter=""
        else
            exe_filter="${FILTER}"
        fi
        for name in $("${exe}" --list); do
            if [[ -n "${exe_filter}" && "${name}" != *"${exe_filter}"* ]]; then
                continue
            fi
            (( total++ ))
            local_runTimed "${tmp_out}" env TZ=Pacific/Kiritimati LC_ALL=C "${exe}" --only "${name}"
            case $? in
                0) ;;
                124) printf "  %bTIMED OUT%b %s (after %ds)\n" "${RED}" "${NC}" "${name}" "${KTIMEOUT}"
                     (( failed++ )) ;;
                *)   printf "  %bFAIL%b %s\n" "${RED}" "${NC}" "${name}"
                     sed 's/^/       /' "${tmp_out}"
                     (( failed++ )) ;;
            esac
        done
    done
    rm -f "${tmp_out}"
    printf "\n%d test(s) run, %d failed\n" "${total}" "${failed}"
    (( failed == 0 )) || exit 1
    exit 0
fi

# ctest reports pass/fail but hides a passing test's output, which is where the
# known-bug tally lives. It stays available behind -c for CI-style use; the
# default runs the executables so their report is actually visible.
if (( USE_CTEST )); then
    local -a ctest_args=(--test-dir "${PATH_BUILD}" --output-on-failure)
    if (( VERBOSE )); then
        ctest_args+=(--verbose)
    fi
    if [[ -n "${FILTER}" ]]; then
        ctest_args+=(-R "${FILTER}")
    fi

    if ctest "${ctest_args[@]}"; then
        printf "\n%bAll host tests passed.%b\n" "${GREEN}" "${NC}"
        exit 0
    fi
    printf "\n%bHost tests failed.%b\n" "${RED}" "${NC}" >&2
    exit 1
fi

typeset -i rc=0
typeset -i nb_pass=0 nb_expected=0 nb_unexpected=0 nb_fixed=0
typeset -a exe_args fixed_suites
typeset out tmp_out
tmp_out=$(mktemp)

for exe in "${PATH_BUILD}"/ukos_tests_*(N.x); do
    exe_args=()
    if (( VERBOSE )); then
        exe_args+=(--verbose)
    fi

    # -t matches an executable name as well as a test name, so "-t port_"
    # selects a whole tier and "-t dump_" selects cases across every suite that
    # has them. Without this, a filter naming an executable would silently run
    # nothing and still report success.
    if [[ -n "${FILTER}" && "${exe:t}" != *"${FILTER}"* ]]; then
        exe_args+=(--filter "${FILTER}")
    fi

    # A filter that selects nothing leaves a suite silent; do not print a header
    # for it, or a narrow -t looks like a dozen empty runs.
    local_runTimed "${tmp_out}" env TZ=Pacific/Kiritimati LC_ALL=C "${exe}" "${exe_args[@]}"
    typeset -i suite_rc=$?          # not "status": zsh reserves that name
    out=$(<"${tmp_out}")

    typeset suite="${exe:t}"
    typeset reason="${EXPECTED[${suite}]-}"

    # A --filter that selects nothing leaves the suite silent and exiting 0.
    # That is not a pass and must not be read as one - without this, "-t
    # <one suite>" reports every OTHER expected failure as newly fixed.
    if [[ -n "${FILTER}" && -z "${out}" && suite_rc -eq 0 ]]; then
        continue
    fi

    if [[ -n "${out}" ]]; then
        printf "\n%b%s%b\n" "${BOLD}" "${suite}" "${NC}"
        print -r -- "${out}"
    fi

    if (( suite_rc == 0 )); then
        if [[ -n "${reason}" ]]; then

# The suite-level twin of the harness's XPASS: it was expected to fail and did
# not, so the fix has landed and the entry is now a lie. Fail the run to force
# the line out of EXPECTED-FAILURES, exactly as an XPASS forces a KNOWN_BUG tag
# to be updated.

            printf "\n%b%s%b\n" "${BOLD}" "${suite}" "${NC}"
            printf "   %bFIXED%b - this suite now passes; remove its line from EXPECTED-FAILURES\n" \
                   "${GREEN}" "${NC}"
            fixed_suites+=("${suite}")
            (( nb_fixed++ ))
            rc=1
        else
            (( nb_pass++ ))
        fi
        continue
    fi

    if (( suite_rc == 124 )); then
        printf "\n%b%s%b\n" "${BOLD}" "${suite}" "${NC}"
        printf "   %bTIMED OUT%b after %ds - killed\n" "${RED}" "${NC}" "${KTIMEOUT}"
    fi

    if [[ -n "${reason}" ]]; then
        printf "   %bexpected%b: %s\n" "${YELLOW}" "${NC}" "${reason}"
        (( nb_expected++ ))
    else
        (( nb_unexpected++ ))
        rc=1
    fi
done
rm -f "${tmp_out}"

# The summary is the point of the exercise on a branch that carries the tests
# without the fixes: an expected failure is a detected defect and must not be
# confused with a regression.

printf "\n%bSummary%b\n" "${BOLD}" "${NC}"
printf "   %d suite(s) passed\n" "${nb_pass}"
(( nb_expected   )) && printf "   %d suite(s) failed as expected - see EXPECTED-FAILURES\n" "${nb_expected}"
(( nb_fixed      )) && printf "   %b%d suite(s) no longer fail: %s%b\n" "${GREEN}" "${nb_fixed}" "${fixed_suites[*]}" "${NC}"
(( nb_unexpected )) && printf "   %b%d suite(s) failed unexpectedly%b\n" "${RED}" "${nb_unexpected}" "${NC}"

if (( rc == 0 )); then
    if (( nb_expected )); then
        printf "\n%bNo unexpected failures.%b\n" "${GREEN}" "${NC}"
    else
        printf "\n%bAll host tests passed.%b\n" "${GREEN}" "${NC}"
    fi
else
    printf "\n%bHost tests failed.%b\n" "${RED}" "${NC}" >&2
fi
exit ${rc}
