#!/usr/bin/env zsh

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# Goal:     Execute manually an IWYU check
#
#           Usage:
#               ./iwyu.sh
#
#------------------------------------------------------------------------

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL EXTENDED_GLOB

if ! command -v include-what-you-use &>/dev/null; then
    print "Command 'include-what-you-use' is not in your PATH"
    exit 1
fi

if ! command -v yq &>/dev/null; then
    print "Command 'yq' is not in your PATH"
    exit 1
fi

# Determine script directory
readonly workspace="${0:A:h:h:h:h}"
readonly iwyu_cfg_rootdir="${workspace}/compile_flags"

# Colours for messages
readonly RED='\033[0;31m'
readonly GREEN='\033[0;32m'
readonly YELLOW='\033[0;33m'
readonly BLUE='\033[0;34m'
readonly BOLD='\033[1m'
readonly FAINT='\033[2m'
readonly ITALIC='\033[3m'
readonly NC='\033[0m' # No Color

source "${iwyu_cfg_rootdir}/Alastor_H743/iwyu.cfg"
source "${iwyu_cfg_rootdir}/Asmodee_CM4/iwyu.cfg"
source "${iwyu_cfg_rootdir}/Asmodee_CM7/iwyu.cfg"
source "${iwyu_cfg_rootdir}/nRF5340_App/iwyu.cfg"
source "${iwyu_cfg_rootdir}/nRF5340_Net/iwyu.cfg"
source "${iwyu_cfg_rootdir}/Discovery_U5G9/iwyu.cfg"
source "${iwyu_cfg_rootdir}/Longan/iwyu.cfg"
source "${iwyu_cfg_rootdir}/MAiXDUiNO/iwyu.cfg"
source "${iwyu_cfg_rootdir}/Nucleo_F207/iwyu.cfg"
source "${iwyu_cfg_rootdir}/Nucleo_H743/iwyu.cfg"
source "${iwyu_cfg_rootdir}/Nucleo_L4R5/iwyu.cfg"
source "${iwyu_cfg_rootdir}/Nucleo_N657/iwyu.cfg"
source "${iwyu_cfg_rootdir}/Pico2_rp2350/iwyu.cfg"

# YAML configuration file
readonly iwyu_config_file="${0:A:h}/iwyu.yaml"

if [[ ! -f "${iwyu_config_file}" ]]; then
    print "Error: Configuration file not found: ${iwyu_config_file}"
    exit 1
fi

# Process YAML configuration with yq
# Format: file_path|board_name|iwyu_flag
local current_file=""

while IFS=$'\t' read -r file_path board_name iwyu_flag; do
    # Print file header when we encounter a new file
    if [[ "${file_path}" != "${current_file}" ]]; then
        current_file="${file_path}"

        printf '%b
╔════════════════════════════════════════════════════════════╗
║   IWYU check: %-44s ║
╚════════════════════════════════════════════════════════════╝
%b' "${BLUE}" "${file_path:t}" "${NC}"
        printf 'File path: %s\n\n' "${file_path}"
    fi

    # Run IWYU check for this board
    printf '%b%s%b' "${GREEN}" "${board_name}" "${NC}"

    # Use (P) flag for indirect expansion, @ flag for array elements
    include-what-you-use "${(@P)iwyu_flag}" "${workspace}/${file_path}" 2>&1
done < <(yq -r '.files[] | .path as $path | .boards[] | [$path, .name, .iwyu_flag] | @tsv' "${iwyu_config_file}")
