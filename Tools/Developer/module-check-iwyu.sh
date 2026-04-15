#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Goal:     Execute IWYU check for all files in a module across all targets
#
#           Usage:
#               ./module-check-iwyu.sh <module_path>
#
#           Example:
#               ./module-check-iwyu.sh OS/CLI

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL EXTENDED_GLOB

# Check arguments
if [[ $# -ne 1 ]]; then
    print -u2 "Usage: $0 <module_path>"
    print -u2 "Example: $0 OS/CLI"
    exit 1
fi

module_path="$1"

# Determine project directory
readonly workspace="${0:A:h:h:h}"

# Validate module path exists
if [[ ! -d "${workspace}/${module_path}" ]]; then
    print -u2 "Error: Module path does not exist: ${workspace}/${module_path}"
    exit 1
fi

# Check for include-what-you-use
if ! command -v include-what-you-use &>/dev/null; then
    print "Command 'include-what-you-use' is not in your PATH"
    exit 1
fi

# Colours
readonly RED='\033[0;31m'
readonly GREEN='\033[0;32m'
readonly YELLOW='\033[0;33m'
readonly BLUE='\033[0;34m'
readonly BOLD='\033[1m'
readonly NC='\033[0m'

# Function to draw a box around text
draw_box() {
    local text="$1"
    local width=60
    local text_len=${#text}
    local left_pad=$(( (width - text_len) / 2 ))
    local right_pad=$(( width - text_len - left_pad ))

    print ""
    printf "%b╔%s╗\n" "${BLUE}" "${(l:width::═:):-}"
    printf "║%*s%s%*s║\n" $left_pad "" "$text" $right_pad ""
    printf "╚%s╝%b\n" "${(l:width::═:):-}" "${NC}"
}

# Find all Variant directories
print "${BLUE}Scanning for targets...${NC}"
typeset -a variant_dirs
variant_dirs=("${workspace}"/Ports/Targets/*/Variant_*(N))

if [[ ${#variant_dirs[@]} -eq 0 ]]; then
    print -u2 "${RED}No variant directories found${NC}"
    exit 1
fi

print "${GREEN}Found ${#variant_dirs[@]} variant directories${NC}"

# Step 1: Ensure all targets have compile_commands.json
print "${BLUE}Ensuring compile_commands.json exists for all targets...${NC}"

for variant_dir in "${variant_dirs[@]}"; do
    cd "$variant_dir"

    if [[ ! -f build/compile_commands.json ]]; then
        target_name=$(basename $(dirname "$variant_dir"))/$(basename "$variant_dir")
        print "${YELLOW}Generating compile_commands.json for ${target_name}${NC}"
        cmake --preset llvm -DCMAKE_EXPORT_COMPILE_COMMANDS=ON > /dev/null 2>&1 || {
            print "${RED}Failed to generate compile_commands.json for ${target_name}${NC}"
        }
    fi
done

# Step 2: Collect all commands for files in the module
print "${BLUE}Collecting commands for module: ${module_path}${NC}"

# Associative arrays: source_file -> list of targets, and (file,target) -> command
typeset -A file_to_targets
typeset -A file_commands

# Counter for debugging
typeset -i total_entries=0
typeset -i matched_entries=0

for variant_dir in "${variant_dirs[@]}"; do
    compile_db="${variant_dir}/build/compile_commands.json"

    if [[ ! -f "$compile_db" ]]; then
        continue
    fi

    target_base=$(basename "$(dirname "$variant_dir")")
    variant_name=$(basename "$variant_dir")

    print "${YELLOW}Processing: ${target_base}/${variant_name}${NC}"

    # Create display name
    if [[ "$variant_name" == *CM4* || "$variant_name" == *CM7* ]]; then
        target_display="${target_base} (${variant_name##*_})"
    elif [[ "$variant_name" == *App* || "$variant_name" == *Net* ]]; then
        target_display="${target_base} (${variant_name##*_})"
    else
        target_display="${target_base}"
    fi

    # Extract commands for files in this module
    while IFS= read -r entry; do
        [[ -z "$entry" ]] && continue

        file=$(jq -r '.[0]' <<< "$entry" 2>/dev/null || echo "")
        command=$(jq -r '.[1]' <<< "$entry" 2>/dev/null || echo "")

        [[ -z "$file" || -z "$command" ]] && continue

        total_entries=$(( total_entries + 1 ))

        # Skip if not in our module
        [[ "$file" != *"${module_path}"* ]] && continue

        matched_entries=$(( matched_entries + 1 ))

        # Skip assembly files
        [[ "$file" == *.S || "$file" == *.s ]] && continue

        # Skip FLASH.sig files
        [[ "$file" == *FLASH.sig* ]] && continue

        # Store this command for this file and target
        file_commands[$file,$target_display]="$command"

        # Add to list of targets for this file
        if [[ -z "${file_to_targets[$file]:-}" ]]; then
            file_to_targets[$file]="$target_display"
        else
            file_to_targets[$file]="${file_to_targets[$file]}|$target_display"
        fi
    done < <(jq -cr '.[] | [.file, .command]' "$compile_db" 2>/dev/null || true)
done

print "${BLUE}Processed ${total_entries} compilation entries, found ${matched_entries} matching ${module_path}${NC}"
print "${BLUE}Found ${#file_to_targets[@]} unique files to check${NC}"

# Check if we found any files
if [[ ${#file_to_targets[@]} -eq 0 ]]; then
    print "${YELLOW}No files found for module: ${module_path}${NC}"
    exit 0
fi

# Step 3: Process each file with all its targets
typeset -a sorted_files
sorted_files=("${(@k)file_to_targets}")
sorted_files=("${(@o)sorted_files}")  # Sort alphabetically

for file in "${sorted_files[@]}"; do
    # Get just the filename for the box
    filename=$(basename "$file")

    draw_box "IWYU check: ${filename}"
    print "File path: ${file}"
    print ""

    # Split targets by |
    IFS='|' read -rA targets <<< "${file_to_targets[$file]:-}"

    for target_display in "${targets[@]}"; do
        command="${file_commands[$file,$target_display]:-}"

        [[ -z "$command" ]] && continue

        # Determine architecture from original target
        original_target=$(sed -n 's/.*--target=\([^ ]*\).*/\1/p' <<< "$command")

        # Set architecture-specific paths based on target
        if [[ "$original_target" == thumb* || "$original_target" == arm* ]]; then
            iwyu_target="arm-unknown-none-eabi"
            isystem_path="/opt/embedded/cross/llvm-current/arm/lib/clang-runtimes/arm-none-eabi/include"
        elif [[ "$original_target" == riscv32* ]]; then
            iwyu_target="riscv32-unknown-elf"
            isystem_path="/opt/embedded/cross/llvm-current/riscv/lib/clang-runtimes/riscv32-unknown-elf/include"
        elif [[ "$original_target" == riscv64* ]]; then
            iwyu_target="riscv64-unknown-elf"
            isystem_path="/opt/embedded/cross/llvm-current/riscv/lib/clang-runtimes/riscv64-unknown-elf/include"
        else
            print "${YELLOW}Warning: Unknown architecture for target ${original_target}, skipping${NC}"
            continue
        fi

        # Transform the command
        transformed_cmd=$(sed -e "s|[^ ]*/clang --target=[^ ]*|include-what-you-use --target=${iwyu_target} -isystem${isystem_path}|" \
            -e 's/ -mcpu=[^ ]*//g' \
            -e 's/ -march=[^ ]*//g' \
            -e 's/ -mfloat-abi=[^ ]*//g' \
            -e 's/ -mfpu=[^ ]*//g' \
            -e 's/ -mabi=[^ ]*//g' \
            -e 's/ -mthumb//g' \
            -e 's/ -o [^ ]*//g' \
            -e 's/ -c / /' <<< "$command")

        # Print target name
        printf '%b%s%b' "${GREEN}" "${target_display}" "${NC}"

        # Run IWYU and capture output
        eval "$transformed_cmd" 2>&1
    done
done

print ""
print "${GREEN}IWYU check complete for module: ${module_path}${NC}"
