#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Purpose:
#   Cleaning all the projects.
#
# Usage:
#   ./_clean.sh

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL EXTENDED_GLOB
setopt NULL_GLOB

# Determine script directory
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

    # Parse YAML: iterate through families and their variants. Boards that build
    # several architectures out of one variant directory have several entries
    # pointing at the same directory, so the list is deduplicated: cleaning it
    # once removes every build/ and Artefacts*/ it holds.
    yq eval '[to_entries[] | .key as $family | .value[] | "\($family)\t\(.name)"] | unique | .[]' "${yaml_file}"
}

printf "%bCleaning all the systems ...%b\n" "${BOLD}" "${NC}"
# Parse YAML and iterate through all build targets
while IFS=$'\t' read -r family variant_name; do
    printf '.'
    cd "${PATH_PRG}/${family}/Variant_${variant_name}"
    rm -fr build Artefacts*(N)
done < <(parse_variants_yaml)
printf '\n%bTerminated!%b\n' "${BOLD}" "${NC}"
