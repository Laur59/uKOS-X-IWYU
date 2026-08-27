#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Switch the default target used by clangd for shared code (OS/, Applications/,
# Third_Parties/). Rewrites the CompilationDatabase line in the repository's
# root .clangd file and updates the clangd binary in .zed/settings.json to
# match the target architecture (ARM or RISC-V).
#
# When the root .clangd file is missing, offer to create it from the versioned
# template Tools/Developer/dot-clangd.text and sync the clangd binary with the
# target the template selects.
#
# Usage:
#   clangd-target.sh                       # show current default and list targets
#   clangd-target.sh <Target>              # use <Target>/Variant_Test/build
#   clangd-target.sh <Target>/<Variant>    # use <Target>/<Variant>/build

emulate -L zsh
setopt NO_UNSET PIPE_FAIL

readonly REPO_ROOT="${0:A:h:h:h}"
readonly CLANGD_FILE="${REPO_ROOT}/.clangd"
readonly ZED_SETTINGS="${REPO_ROOT}/.zed/settings.json"
readonly TARGETS_DIR="${REPO_ROOT}/Ports/Targets"
readonly VARIANTS_YAML="${TARGETS_DIR}/variants.yaml"
readonly CLANGD_TEMPLATE="${REPO_ROOT}/Tools/Developer/dot-clangd.text"

fresh_install=0

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
    local db_line clangd_line
    db_line=$(grep -E '^\s*CompilationDatabase:' "$CLANGD_FILE" | head -n1)
    if [[ -n $db_line ]]; then
        print "Current default:${db_line#*CompilationDatabase:}"
    else
        print "Current default: (no CompilationDatabase line in $CLANGD_FILE)"
    fi
    if [[ -f $ZED_SETTINGS ]]; then
        local clangd_path
        clangd_path=$(grep -E '"path":' "$ZED_SETTINGS" | head -n1 | sed -E 's/.*"path":[[:space:]]*"([^"]+)".*/\1/')
        if [[ -n $clangd_path ]]; then
            print "clangd binary:  $clangd_path"
        fi
    fi
}

# Print the CompilationDatabase path currently set in the .clangd file.
current_db_path() {
    sed -nE 's/^[[:space:]]*CompilationDatabase:[[:space:]]*//p' "$CLANGD_FILE" | head -n1
}

# Detect architecture from an existing compile_commands.json.
# Returns "riscv" or "arm".
detect_arch_from_compdb() {
    local compdb=$1
    if grep -qE '"--target=riscv|-march=rv' "$compdb" 2>/dev/null; then
        print riscv
    else
        print arm
    fi
}

# Detect architecture from variants.yaml given target and variant names.
# Returns "riscv", "arm", or empty string if not found.
detect_arch_from_yaml() {
    local target=$1 variant=$2
    [[ -f $VARIANTS_YAML ]] || return
    awk -v t="$target" -v v="$variant" '
        /^[^ ]/ { blk = substr($1, 1, length($1)-1) }
        blk == t && /name:/ { gsub(/.*name: /, ""); cur_v = $0 }
        blk == t && cur_v == v && /core:/ { gsub(/.*core: /, ""); print; exit }
    ' "$VARIANTS_YAML"
}

# Determine architecture for the given build path.
# Prefers compile_commands.json (ground truth for dual-arch targets like Pico2).
detect_arch() {
    local build_path=$1
    local compdb="${REPO_ROOT}/${build_path}/compile_commands.json"
    if [[ -f $compdb ]]; then
        detect_arch_from_compdb "$compdb"
        return
    fi
    # Fallback: parse variants.yaml
    # build_path is e.g. "Ports/Targets/Pico2_rp2350/Variant_Test/build"
    local rel="${build_path#Ports/Targets/}"      # Pico2_rp2350/Variant_Test/build
    local target="${rel%%/*}"                     # Pico2_rp2350
    local rest="${rel#*/}"                        # Variant_Test/build
    local variant_dir="${rest%%/*}"               # Variant_Test
    local variant="${variant_dir#Variant_}"       # Test
    local arch
    arch=$(detect_arch_from_yaml "$target" "$variant")
    print "${arch:-arm}"
}

# Update the clangd binary path in .zed/settings.json.
update_zed_clangd() {
    local clangd_bin=$1
    [[ -f $ZED_SETTINGS ]] || return
    # macOS BSD sed requires an explicit (possibly empty) backup suffix after -i.
    sed -i '' -E "s|(\"path\":[[:space:]]*\")[^\"]*\"|\1${clangd_bin}\"|" "$ZED_SETTINGS"
}

# Resolve the clangd binary path for the given architecture.
# Prints the path, or prints an empty string and warns if the env var is unset.
get_clangd_binary() {
    local arch=$1
    local clangd_bin
    if [[ $arch == riscv ]]; then
        if [[ -z ${PATH_LLVM_RVXX:-} ]]; then
            print -u2 "warning: PATH_LLVM_RVXX is not set — skipping clangd binary update"
            print ""
            return
        fi
        clangd_bin="${PATH_LLVM_RVXX}/bin/clangd"
    else
        if [[ -z ${PATH_LLVM_ARM:-} ]]; then
            print -u2 "warning: PATH_LLVM_ARM is not set — skipping clangd binary update"
            print ""
            return
        fi
        clangd_bin="${PATH_LLVM_ARM}/bin/clangd"
    fi
    print "$clangd_bin"
}

# Point .zed/settings.json at the clangd matching the build path architecture.
sync_zed_clangd() {
    local build_path=$1 arch clangd_bin
    arch=$(detect_arch "$build_path")
    clangd_bin=$(get_clangd_binary "$arch")
    if [[ -n $clangd_bin ]]; then
        update_zed_clangd "$clangd_bin"
        print "clangd binary:  ${clangd_bin}  (${arch})"
    fi
}

if [[ ! -f $CLANGD_FILE ]]; then
    print -u2 "warning: ${CLANGD_FILE#$REPO_ROOT/} not found"
    if [[ ! -f $CLANGD_TEMPLATE ]]; then
        print -u2 "error: template ${CLANGD_TEMPLATE#$REPO_ROOT/} not found"
        exit 1
    fi
    if [[ ! -t 0 ]]; then
        print -u2 "error: run the script from a terminal to install the default configuration"
        exit 1
    fi
    reply=""
    read "reply?install the default one from ${CLANGD_TEMPLATE#$REPO_ROOT/}? [y/N] " || print
    if [[ ${reply:l} != (y|yes) ]]; then
        print -u2 "error: no ${CLANGD_FILE#$REPO_ROOT/} — aborted"
        exit 1
    fi
    cp "$CLANGD_TEMPLATE" "$CLANGD_FILE" || exit 1
    print "created ${CLANGD_FILE#$REPO_ROOT/} from ${CLANGD_TEMPLATE#$REPO_ROOT/}"
    fresh_install=1
fi

if (( $# == 0 )); then
    # A fresh .clangd brings the template default with it: align the binary.
    if (( fresh_install )); then
        db_path=$(current_db_path)
        [[ -n $db_path ]] && sync_zed_clangd "$db_path"
    fi
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

sync_zed_clangd "$new_path"

show_current
