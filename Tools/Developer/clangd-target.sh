#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Switch the default target used by clangd for shared code (OS/, Applications/,
# Third_Parties/). Rewrites the CompilationDatabase line in the repository's
# root .clangd file.
#
# Usage:
#   clangd-target.sh                       # show current default and list targets
#   clangd-target.sh <Target>              # use <Target>/Variant_Test/build
#   clangd-target.sh <Target>/<Variant>    # use <Target>/<Variant>/build

emulate -L zsh
setopt NO_UNSET PIPE_FAIL

readonly REPO_ROOT="${0:A:h:h:h}"
readonly CLANGD_FILE="${REPO_ROOT}/.clangd"
readonly TARGETS_DIR="${REPO_ROOT}/Ports/Targets"

if [[ ! -f $CLANGD_FILE ]]; then
    print -u2 "error: $CLANGD_FILE not found"
    exit 1
fi

list_targets() {
    local variant_dir rel
    for variant_dir in $TARGETS_DIR/*/Variant_*(/N); do
        rel="${variant_dir#$REPO_ROOT/}"
        if [[ -f "$variant_dir/build/compile_commands.json" ]]; then
            print "  $rel/build"
        else
            print "  $rel/build  (no compile_commands.json — build it first)"
        fi
    done
}

show_current() {
    local line
    line=$(grep -E '^\s*CompilationDatabase:' "$CLANGD_FILE" | head -n1)
    if [[ -n $line ]]; then
        print "Current default:${line#*CompilationDatabase:}"
    else
        print "Current default: (no CompilationDatabase line in $CLANGD_FILE)"
    fi
}

if (( $# == 0 )); then
    show_current
    print
    print "Available variants:"
    list_targets
    exit 0
fi

arg=$1
if [[ $arg == */* ]]; then
    new_path="Ports/Targets/${arg}/build"
else
    new_path="Ports/Targets/${arg}/Variant_Test/build"
fi

if [[ ! -d "${REPO_ROOT}/${new_path%/build}" ]]; then
    print -u2 "error: ${new_path%/build} does not exist"
    print -u2 "run '${0:t}' with no arguments to list available variants"
    exit 2
fi

if [[ ! -f "${REPO_ROOT}/${new_path}/compile_commands.json" ]]; then
    print -u2 "warning: ${new_path}/compile_commands.json not found — build the variant first"
fi

# macOS BSD sed requires an explicit (possibly empty) backup suffix after -i.
sed -i '' -E "s|^([[:space:]]*CompilationDatabase:[[:space:]]*).*|\1${new_path}|" "$CLANGD_FILE"

show_current
