#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# Description:
#   Keep the prebuilt third-party libraries (Third_Parties/Library/<lib>) in a
#   cache outside the repository, so that moving the checkout to another commit
#   restores the matching archives instead of rebuilding them, and so that a
#   Library/ left over from another commit is noticed instead of linked.
#
#   A Library/ is identified by two things:
#
#     sources   SHA-256 over the content of every file the build reads from the
#               repository: Third_Parties/<lib> itself (documentation excepted)
#               plus the paths listed in Third_Parties/cmake/cache-inputs-common.txt and
#               Third_Parties/<lib>/cache-inputs.txt. It is computed from the
#               working tree, so it is the same before and after a commit.
#     compiler  what built the archives, read back from the archives themselves
#               (e.g. gcc-16.2.0, clang-23.1.2).
#
#   Both are written to Library/<lib>/.ukos-stamp when a library is installed, and name
#   the cache entry: <cache>/<lib>/<sources, 16 digits>-<compiler>/.
#
#   The cache is <parent of the checkout>/.cache/ukos-third-parties, shared by
#   every checkout and worktree placed side by side. UKOS_THIRD_PARTIES_CACHE
#   overrides it.
#
# Usage:
#   third-parties-cache status  [<lib>...]
#   third-parties-cache restore [--gcc|--llvm] [--force] [<lib>...]
#   third-parties-cache save    [<lib>...]
#   third-parties-cache adopt   <lib>...
#   third-parties-cache audit   [<lib>...]
#   third-parties-cache list
#
#   Used by the build system:
#   third-parties-cache sources-key <lib>
#   third-parties-cache stamp   <lib> --built-from <sources-key> [--save]
#   third-parties-cache unstamp <lib>
#   third-parties-cache check   <lib>
#
# Commands:
#   status       One line per library: what Library/ holds, whether it matches
#                this checkout, and whether a matching build is cached
#   restore      Replace Library/ with the cached build matching this checkout.
#                A stamped Library/ is saved first; an unstamped one is kept
#                unless --force is given, because nothing could bring it back
#   save         Copy a stamped Library/ into the cache
#   adopt        Stamp a Library/ that was built before the stamp existed, on
#                your word that it was built from this checkout, and save it
#   audit        Compare the declared inputs with the dependencies ninja recorded
#                in the build trees; a file read from outside them is reported.
#                'stamp' runs the same check and refuses on a finding
#   list         The cache entries and their size
#   sources-key  Print the sources key of this checkout
#   stamp        Write Library/<lib>/.ukos-stamp. Refused when the sources changed
#                since the build started (--built-from), or when the archives
#                were not all built by the same compiler family
#   unstamp      Remove the stamp (a build is about to overwrite Library/)
#   check        For CMake: is Library/ the one this checkout would build?
#
# Exit codes:
#   0  done, or Library/ matches
#   1  usage or environment error
#   3  mismatch: stale Library/, no cached build, undeclared input
#   4  nothing to compare: Library/ missing or not stamped
#

emulate -L zsh
setopt NO_UNSET PIPE_FAIL EXTENDED_GLOB NULL_GLOB
zmodload zsh/zutil

# Paths ( :A resolves symlinks, so the root is correct through Tools/Developer/bin )
readonly PATH_ROOT="${0:A:h:h:h}"
readonly PATH_TP="${PATH_ROOT}/Third_Parties"
readonly PATH_CACHE="${UKOS_THIRD_PARTIES_CACHE:-${PATH_ROOT:h}/.cache/ukos-third-parties}"
readonly STAMP='.ukos-stamp'
readonly INPUTS='cache-inputs.txt'
readonly INPUTS_COMMON='cache-inputs-common.txt'

readonly PATH_SELF="${0:A}"
readonly PRG="${0:t:r}"

if [[ ! -f "${PATH_ROOT}/OS/Includes/modules.h" || ! -d "${PATH_TP}" ]]; then
    print -u2 "${PRG}: ${PATH_ROOT} does not look like a uKOS-X tree"
    exit 1
fi

# Colours, on a terminal only: CMake captures the output of 'check'
if [[ -t 1 ]]; then
    readonly RED=$'\033[0;31m' GREEN=$'\033[0;32m' YELLOW=$'\033[0;33m' NC=$'\033[0m'
else
    readonly RED='' GREEN='' YELLOW='' NC=''
fi

die() {
    print -u2 "${PRG}: $*"
    exit 1
}

usage() {
    sed -n '/^# Usage:/,/^#$/p' "${PATH_SELF}" | sed -e 's/^# \{0,1\}//' >&2
    exit 1
}

git_root() {
    git -C "${PATH_ROOT}" -c core.quotepath=off "$@"
}

# Every library that declares its inputs
all_libs() {
    local f
    for f in "${PATH_TP}"/*/"${INPUTS}"; do
        print -r -- "${f:h:t}"
    done
}

need_lib() {
    [[ -f "${PATH_TP}/$1/${INPUTS}" ]] ||
        die "unknown library '$1' (no Third_Parties/$1/${INPUTS}); known: ${(j:, :)${(f)"$(all_libs)"}}"
}

# Where a library is installed: the common output directory, one entry each
lib_dir() {
    print -r -- "${PATH_TP}/Library/$1"
}

# The repository paths a library is built from, one per line
input_paths() {
    local lib="$1" f line
    print -r -- "Third_Parties/${lib}"
    for f in "${PATH_TP}/cmake/${INPUTS_COMMON}" "${PATH_TP}/${lib}/${INPUTS}"; do
        [[ -f "${f}" ]] || continue
        while IFS= read -r line; do
            line="${line%%\#*}"
            line="${${line##[[:space:]]#}%%[[:space:]]#}"
            [[ -n "${line}" ]] && print -r -- "${line%/}"
        done < "${f}"
    done
}

# SHA-256 over the working-tree content of the inputs.
# Blob names come from the index; only what differs from it is hashed again,
# so the usual case costs two git calls rather than one hash per file.
sources_key() {
    local lib="$1" f
    local -a paths spec changed

    paths=(${(f)"$(input_paths "${lib}")"})
    spec=(${paths} ":(exclude)Third_Parties/${lib}/Documentation" ':(exclude,glob)**/*.md')

    changed=(
        ${(f)"$(git_root diff-files --name-only -- ${spec})"}
        ${(f)"$(git_root ls-files --others --exclude-standard -- ${spec})"}
    )

    {
        git_root ls-files --stage -- ${spec} |
            awk -F'\t' '{ split($1, meta, " "); print meta[2] "\t" $2 }'
        for f in ${changed}; do
            if [[ -f "${PATH_ROOT}/${f}" ]]; then
                print -r -- "$(git_root hash-object -- "${f}")"$'\t'"${f}"
            else
                print -r -- "-"$'\t'"${f}"
            fi
        done
    } | awk -F'\t' '
            { blob[$2] = $1 }
        END { for (path in blob) if (blob[path] != "-") print blob[path] "\t" path }
    ' | LC_ALL=C sort | shasum -a 256 | cut -d' ' -f1
}

# gcc-16.2.0 / clang-23.1.2 out of a compiler identification line
compiler_id() {
    local line="$1"
    case "${line}" in
        (*clang\ version\ [0-9]*) print -r -- "clang-${${line##*clang version }%%[^0-9.]*}" ;;
        (*\)\ [0-9]*)             print -r -- "gcc-${${line##*\) }%%[^0-9.]*}" ;;
    esac
}

# What built the archives of a Library/: one id, several joined by '+', or empty
built_compiler() {
    local lib="$1"
    local -a archives ids
    local line

    archives=("$(lib_dir "${lib}")"/**/*.a(.N))
    (( ${#archives} )) || return 0

    for line in ${(f)"$(strings -a ${archives} |
                        grep -oE '^(GCC: \([^)]*\) [0-9.]+|clang version [0-9.]+)' | sort -u)"}; do
        ids+=("$(compiler_id "${line}")")
    done
    print -r -- "${(j:+:)${(@ou)ids}}"
}

# What the installed toolchains of one family (gcc, clang) would stamp
installed_compiler() {
    local family="$1" exe line
    local -a exes ids

    if [[ "${family}" == gcc ]]; then
        exes=("${PATH_GCC_ARM:+${PATH_GCC_ARM}/bin/}arm-none-eabi-gcc"
              "${PATH_GCC_RVXX:+${PATH_GCC_RVXX}/bin/}riscv64-unknown-elf-gcc")
    else
        exes=("${PATH_LLVM_ARM:+${PATH_LLVM_ARM}/bin/}clang"
              "${PATH_LLVM_RVXX:+${PATH_LLVM_RVXX}/bin/}clang")
    fi
    for exe in ${exes}; do
        line="$("${exe}" --version 2>/dev/null | head -1)" || continue
        [[ -n "${line}" ]] && ids+=("$(compiler_id "${line}")")
    done
    print -r -- "${(j:+:)${(@ou)ids}}"
}

# stamp_get <file> <field>
stamp_get() {
    [[ -f "$1" ]] || return 0
    sed -n "s/^$2=//p" "$1" | head -1
}

entry_name() {
    print -r -- "${1[1,16]}-$2"
}

# Copy a tree, as copy-on-write clones where the file system has them
copy_tree() {
    local src="$1" dst="$2"
    mkdir -p "${dst}"
    if [[ "${OSTYPE}" == darwin* ]]; then
        cp -cRp "${src}/." "${dst}/"
    else
        cp -Rp --reflink=auto "${src}/." "${dst}/"
    fi
}

write_stamp() {
    local lib="$1" sources="$2" compiler="$3"
    print -r -- "library=${lib}"$'\n'"sources=${sources}"$'\n'"compiler=${compiler}" \
        > "$(lib_dir "${lib}")/${STAMP}"
}

# Copy a stamped Library/ into its cache entry. Entries are merged, never
# replaced: a partial build (one core) must not drop the other cores of a
# complete one, and the same key means the same content for a file both have.
save_lib() {
    local lib="$1"
    local stamp="$(lib_dir "${lib}")/${STAMP}"
    local sources compiler entry

    sources="$(stamp_get "${stamp}" sources)"
    compiler="$(stamp_get "${stamp}" compiler)"
    if [[ -z "${sources}" || -z "${compiler}" ]]; then
        print -u2 "${lib}: Library/${lib} is not stamped, nothing saved"
        return 4
    fi
    entry="${PATH_CACHE}/${lib}/$(entry_name "${sources}" "${compiler}")"
    copy_tree "$(lib_dir "${lib}")" "${entry}" || die "${lib}: cannot write ${entry}"
    print -r -- "${lib}: saved to ${entry}"
}

cmd_sources_key() {
    (( $# == 1 )) || usage
    need_lib "$1"
    sources_key "$1"
}

cmd_unstamp() {
    (( $# == 1 )) || usage
    need_lib "$1"
    rm -f "$(lib_dir "$1")/${STAMP}"
}

cmd_stamp() {
    local -a o_from o_save
    zparseopts -D -E -- -built-from:=o_from -save=o_save || usage
    (( $# == 1 && ${#o_from} )) || usage
    local lib="$1" built_from="${o_from[2]}" now compiler
    local -a missing
    need_lib "${lib}"

    rm -f "$(lib_dir "${lib}")/${STAMP}"

    now="$(sources_key "${lib}")"
    if [[ "${built_from}" != "${now}" ]]; then
        print -u2 "${lib}: the sources changed since this build started, so Library/${lib} is left unstamped."
        print -u2 "${lib}: run ./very_clean.sh and build again to get a stamped, cached library."
        return 3
    fi

    compiler="$(built_compiler "${lib}")"
    if [[ -z "${compiler}" ]]; then
        print -u2 "${lib}: no archive in Library/${lib}, nothing to stamp"
        return 4
    fi
    if [[ "${compiler}" == *gcc* && "${compiler}" == *clang* ]]; then
        print -u2 "${lib}: Library/${lib} mixes archives of both compilers (${compiler}), left unstamped."
        print -u2 "${lib}: run ./very_clean.sh and build again with a single toolchain."
        return 3
    fi

    # A key that misses an input would call a stale library current
    missing=(${(f)"$(undeclared_inputs "${lib}")"})
    if [[ "${missing[1]:-}" != '?' ]] && (( ${#missing} )); then
        print -u2 "${lib}: the build read ${#missing} file(s) that Third_Parties/${lib}/${INPUTS} does not declare,"
        print -u2 "${lib}: so Library/${lib} is left unstamped. '${PRG} audit ${lib}' lists them."
        return 3
    fi

    write_stamp "${lib}" "${now}" "${compiler}"
    print -r -- "${lib}: stamped ${now[1,16]} ${compiler}"
    if (( ${#o_save} )); then
        save_lib "${lib}"
    fi
}

cmd_adopt() {
    (( $# )) || usage
    local lib now compiler rc=0
    for lib in "$@"; do
        need_lib "${lib}"
        compiler="$(built_compiler "${lib}")"
        if [[ -z "${compiler}" ]]; then
            print -u2 "${lib}: no archive in Library/${lib}, nothing to adopt"
            rc=4
            continue
        fi
        if [[ "${compiler}" == *gcc* && "${compiler}" == *clang* ]]; then
            print -u2 "${lib}: Library/${lib} mixes archives of both compilers (${compiler}), not adopted"
            rc=3
            continue
        fi
        now="$(sources_key "${lib}")"
        write_stamp "${lib}" "${now}" "${compiler}"
        print -r -- "${lib}: adopted as ${now[1,16]} ${compiler}"
        save_lib "${lib}" || rc=$?
    done
    return ${rc}
}

cmd_save() {
    local lib rc=0
    for lib in ${@:-${(f)"$(all_libs)"}}; do
        need_lib "${lib}"
        save_lib "${lib}" || rc=$?
    done
    return ${rc}
}

# check <lib>: one line on stdout, the verdict in the exit code
cmd_check() {
    (( $# == 1 )) || usage
    local lib="$1"
    need_lib "${lib}"
    local stamp="$(lib_dir "${lib}")/${STAMP}"
    local sources compiler now installed note=''

    if [[ ! -d "$(lib_dir "${lib}")" ]]; then
        print -r -- "${lib}: Library/${lib} is missing"
        return 4
    fi
    sources="$(stamp_get "${stamp}" sources)"
    compiler="$(stamp_get "${stamp}" compiler)"
    if [[ -z "${sources}" ]]; then
        print -r -- "${lib}: Library/${lib} is not stamped, so it cannot be checked against this checkout"
        return 4
    fi

    now="$(sources_key "${lib}")"
    if [[ "${sources}" != "${now}" ]]; then
        print -r -- "${lib}: Library/${lib} was built from other sources (${sources[1,16]}, this checkout is ${now[1,16]})"
        return 3
    fi

    installed="$(installed_compiler "${compiler%%-*}")"
    if [[ -n "${installed}" && "${installed}" != "${compiler}" ]]; then
        note=", the installed toolchain is ${installed}"
    fi
    print -r -- "${lib}: Library/${lib} matches this checkout (${now[1,16]}, built with ${compiler}${note})"
    return 0
}

cmd_status() {
    local lib stamp sources compiler now state cached
    local -a entries

    printf '%-15s %-18s %-16s %-11s %s\n' 'Library' 'Checkout' 'Library/' 'State' 'Cached for this checkout'
    for lib in ${@:-${(f)"$(all_libs)"}}; do
        need_lib "${lib}"
        stamp="$(lib_dir "${lib}")/${STAMP}"
        now="$(sources_key "${lib}")"
        sources="$(stamp_get "${stamp}" sources)"
        compiler="$(stamp_get "${stamp}" compiler)"

        if [[ ! -d "$(lib_dir "${lib}")" ]]; then
            state="${YELLOW}missing${NC}    "
        elif [[ -z "${sources}" ]]; then
            state="${YELLOW}unstamped${NC}  "
        elif [[ "${sources}" == "${now}" ]]; then
            state="${GREEN}current${NC}    "
        else
            state="${RED}STALE${NC}      "
        fi

        entries=("${PATH_CACHE}/${lib}/${now[1,16]}"-*(/N:t))
        cached="${(j:, :)${entries#*-}}"
        printf '%-15s %-18s %-16s %s %s\n' "${lib}" "${now[1,16]}" \
            "${compiler:--}" "${state}" "${cached:--}"
    done
    print -r -- "Cache: ${PATH_CACHE}"
}

cmd_list() {
    local lib entry
    if [[ ! -d "${PATH_CACHE}" ]]; then
        print -r -- "Cache: ${PATH_CACHE} (empty)"
        return 0
    fi
    for lib in "${PATH_CACHE}"/*(/N:t); do
        for entry in "${PATH_CACHE}/${lib}"/*(/Nom); do
            printf '%-15s %-34s %6s  %s\n' "${lib}" "${entry:t}" \
                "$(du -sh "${entry}" | cut -f1 | tr -d ' ')" \
                "$(date -r "$(stat -f %m "${entry}" 2>/dev/null || stat -c %Y "${entry}")" '+%Y-%m-%d %H:%M')"
        done
    done
    print -r -- "Cache: ${PATH_CACHE} ($(du -sh "${PATH_CACHE}" | cut -f1 | tr -d ' '))"
}

cmd_restore() {
    local -a o_gcc o_llvm o_force
    zparseopts -D -E -- -gcc=o_gcc -llvm=o_llvm -force=o_force || usage
    (( ${#o_gcc} && ${#o_llvm} )) && die "--gcc and --llvm are mutually exclusive"

    local lib dir stamp now sources compiler family pick installed f rc=0
    local -a entries wanted content

    for lib in ${@:-${(f)"$(all_libs)"}}; do
        need_lib "${lib}"
        dir="$(lib_dir "${lib}")"
        stamp="${dir}/${STAMP}"
        now="$(sources_key "${lib}")"
        sources="$(stamp_get "${stamp}" sources)"
        compiler="$(stamp_get "${stamp}" compiler)"

        # Which compiler family: the one asked for, else the one already there
        family=''
        if (( ${#o_gcc} )); then
            family=gcc
        elif (( ${#o_llvm} )); then
            family=clang
        elif [[ -n "${compiler}" ]]; then
            family="${compiler%%-*}"
        fi

        if [[ "${sources}" == "${now}" && ( -z "${family}" || "${compiler}" == ${family}-* ) ]]; then
            print -r -- "${lib}: already matches this checkout (${compiler})"
            continue
        fi

        # Candidates, the installed compiler first, Clang before GCC
        entries=("${PATH_CACHE}/${lib}/${now[1,16]}"-*(/N:t))
        [[ -n "${family}" ]] && entries=(${(M)entries:#${now[1,16]}-${family}-*})
        pick=''
        wanted=()
        for f in ${family:-clang gcc}; do
            installed="$(installed_compiler "${f}")"
            [[ -n "${installed}" ]] && wanted+=("${now[1,16]}-${installed}")
        done
        for f in ${wanted} ${(M)entries:#*-clang-*} ${entries}; do
            if (( ${entries[(Ie)${f}]} )); then
                pick="${f}"
                break
            fi
        done

        if [[ -z "${pick}" ]]; then
            print -r -- "${lib}: ${RED}no cached build${NC} for this checkout (${now[1,16]}${family:+, ${family}}); build it in Third_Parties/${lib}"
            rc=3
            continue
        fi

        # Never lose what is there
        content=("${dir}"/*(DN))
        if (( ${#content} )); then
            if [[ -n "${sources}" ]]; then
                save_lib "${lib}" >/dev/null || die "${lib}: cannot save the current Library/"
            elif (( ! ${#o_force} )); then
                print -r -- "${lib}: ${YELLOW}kept${NC}: Library/${lib} is not stamped, so replacing it would lose it. 'adopt' it at the commit it was built from, or pass --force"
                rc=3
                continue
            fi
        fi

        mkdir -p "${dir:h}"
        rm -rf "${dir}.restore"
        copy_tree "${PATH_CACHE}/${lib}/${pick}" "${dir}.restore" || die "${lib}: cannot copy ${pick}"
        rm -rf "${dir}"
        mv "${dir}.restore" "${dir}"
        print -r -- "${lib}: ${GREEN}restored${NC} ${pick}"
    done
    return ${rc}
}

# The repository files ninja recorded as dependencies in the build trees of a
# library that no declared input covers, one per line. The sources key would
# not notice such a file changing. Prints '?' when there is no ninja build tree.
undeclared_inputs() {
    local lib="$1" tree dep rel p covered
    local -a trees paths missing

    # The installed library counts as declared: Tflite-micro compiles the tree
    # that its build.sh exports there, which the pinned upstream hash identifies
    paths=(${(f)"$(input_paths "${lib}")"} "Third_Parties/Library/${lib}")
    trees=(${(f)"$(find "${PATH_TP}/${lib}" -name '*-current' -prune -o \
                        -name .ninja_deps -print)"})
    if (( ! ${#trees} )) || ! command -v ninja >/dev/null; then
        print -r -- '?'
        return 0
    fi

    # Most dependencies are shared by every tree: resolve them once
    local -aU deps
    for tree in ${trees:h}; do
        for dep in ${(f)"$(ninja -C "${tree}" -t deps 2>/dev/null | sed -n 's/^    //p' | sort -u)"}; do
            [[ "${dep}" == /* ]] || dep="${tree}/${dep}"
            deps+=("${dep:a}")
        done
    done
    for dep in ${(M)deps:#${PATH_ROOT}/*}; do
        rel="${dep#${PATH_ROOT}/}"
        covered=0
        for p in ${paths}; do
            if [[ "${rel}" == "${p}" || "${rel}" == "${p}"/* || "${rel}" == ${~p} ]]; then
                covered=1
                break
            fi
        done
        (( covered )) || missing+=("${rel}")
    done
    (( ${#missing} )) && print -r -l -- ${(ou)missing}
    return 0
}

cmd_audit() {
    local lib rc=0
    local -a missing

    for lib in ${@:-${(f)"$(all_libs)"}}; do
        need_lib "${lib}"
        missing=(${(f)"$(undeclared_inputs "${lib}")"})
        if [[ "${missing[1]:-}" == '?' ]]; then
            print -r -- "${lib}: no ninja build tree, nothing audited"
        elif (( ${#missing} )); then
            print -r -- "${lib}: ${RED}${#missing} undeclared input(s)${NC}, add them to Third_Parties/${lib}/${INPUTS}:"
            print -r -l -- "    "${^missing[1,20]}
            (( ${#missing} > 20 )) && print -r -- "    ... and $(( ${#missing} - 20 )) more"
            rc=3
        else
            print -r -- "${lib}: ${GREEN}inputs complete${NC}"
        fi
    done
    return ${rc}
}

(( $# )) || usage
readonly COMMAND="$1"
shift

case "${COMMAND}" in
    (status)      cmd_status "$@" ;;
    (restore)     cmd_restore "$@" ;;
    (save)        cmd_save "$@" ;;
    (adopt)       cmd_adopt "$@" ;;
    (audit)       cmd_audit "$@" ;;
    (list)        cmd_list "$@" ;;
    (sources-key) cmd_sources_key "$@" ;;
    (stamp)       cmd_stamp "$@" ;;
    (unstamp)     cmd_unstamp "$@" ;;
    (check)       cmd_check "$@" ;;
    (*)           usage ;;
esac
