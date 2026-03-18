#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Purpose:
#   Cleaning all the uKOS downloadable applications.
#
# Usage:
#   ./_clean.sh

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL EXTENDED_GLOB
setopt NULL_GLOB

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

# Parse apps.yaml file using yq
parse_apps_yaml() {
    local yaml_file="${PATH_PRG}/apps.yaml"

    if ! [[ -f "${yaml_file}" ]]; then
        printf "%bError: YAML file not found: %s%b\n" "${RED}" "${yaml_file}" "${NC}" >&2
        exit 1
    fi

    if ! command -v yq >/dev/null 2>&1; then
        printf "%bError: yq is not installed%b\n" "${RED}" "${NC}" >&2
        exit 1
    fi

    # Parse YAML: iterate through families, projects, and targets
    yq eval 'to_entries[] | .key as $family | .value | to_entries[] | .key as $project | .value[] | "\($family)/\($project)/\(.)"' "${yaml_file}"
}

printf "%bCleaning all the downloadable applications ...%b\n" "${BOLD}" "${NC}"
# Parse YAML and iterate through all build targets
while IFS= read -r CURRENT_TARGET; do
    printf '.'
    cd "${PATH_PRG}/${CURRENT_TARGET}"
    rm -fr build *.bin *.elf *.hex *.map *.s3
done < <(parse_apps_yaml)
printf '\n%bTerminated!%b\n' "${BOLD}" "${NC}"
