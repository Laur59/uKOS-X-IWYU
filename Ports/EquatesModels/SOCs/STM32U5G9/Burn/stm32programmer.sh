#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     script for burning the arm flash via the stm32programmer.
#           script mainly generated with chatgpt
#
#           - Usage:
#             ./stm32programmer.sh

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL

# Colours for messages

readonly RED=$'\033[0;31m'
readonly GREEN=$'\033[0;32m'
readonly YELLOW=$'\033[0;33m'
readonly BLUE=$'\033[0;34m'
readonly BOLD=$'\033[1m'
readonly FAINT=$'\033[2m'
readonly ITALIC=$'\033[3m'
readonly NC=$'\033[0m' # No Color

readonly target_device='STM32U5xx'
readonly HEX='FLASH.hex'

# Detection of the STM32_Programmer_CLI on different OS

detect_cli() {

    # Already on the path?
    if command -v STM32_Programmer_CLI >/dev/null 2>&1; then
        echo 'STM32_Programmer_CLI'
        return
    fi

    # macOS (Spotlight via mdfind)
    if [[ "${OSTYPE}" == 'darwin'* ]]; then
        STM32_PROGRAMMER_CLI="${STM32_PROGRAMMER_CLI:-$(find /Applications -type f -name 'STM32_Programmer_CLI' | sort | head -n 1)}"

        # Verify if executable
        if [[ -x "${STM32_PROGRAMMER_CLI}" ]]; then
            echo "${STM32_PROGRAMMER_CLI}"
            return 0
        fi
    fi

    # Linux : search in /opt ou /usr/local
    if [[ -d '/opt/st' ]]; then
        find '/opt/st' -name STM32_Programmer_CLI 2>/dev/null | head -n 1
        return
    fi

    # Windows (Git Bash / WSL) : exemple of path
    if [[ -d '/c/Program Files/STMicroelectronics' ]]; then
        find '/c/Program Files/STMicroelectronics' -name STM32_Programmer_CLI.exe 2>/dev/null | head -n 1
        return
    fi
}

# Extract serial numbers and associated device names from all connected ST-Links
# Find the ST-Link whose device matches $1 and set the global SN variable

extract_targets() {
    local target_device="$1"
    local -a serials
    local sn

    # -getTargetSelList outputs to stderr; redirect accordingly
    local list
    list=$("${CLI}" -getTargetSelList 2>&1 >/dev/null)

    # Parse lines of the form:  Serial: "XXXX" , Name: "VXJYYMZ"
    while IFS= read -r line; do
        [[ "${line}" == *'Serial:'* ]] || continue
        sn=$(printf '%s' "${line}" | sed 's/.*Serial:[[:space:]]*"\([^"]*\)".*/\1/')
        [[ -n "${sn}" ]] && serials+=("${sn}")
    done <<< "${list}"

    if (( ${#serials[@]} == 0 )); then
        printf '%s\n' "${RED}No ST-Link detected.${NC}"
        exit 1
    fi

    printf '%s\n' "${BLUE}${BOLD}Detected targets : ${#serials[@]}${NC}"

    local info device_name fw_name
    for sn in "${serials[@]}"; do
        # Connect briefly (Under Reset) just to read the device info
        info=$("${CLI}" -c port=SWD mode=UR sn="${sn}" 2>&1)

        device_name=$(printf '%s' "${info}" | grep 'Device name' | awk -F':' '{gsub(/^[[:space:]]+|[[:space:]]+$/, "", $2); print $2}')
        fw_name=$(printf '%s'     "${info}" | grep 'ST-LINK FW'  | awk -F':' '{gsub(/^[[:space:]]+|[[:space:]]+$/, "", $2); print $2}')

        printf '  %sSN%s : %s%s%s\n'          "${BOLD}" "${NC}" "${YELLOW}" "${sn}"          "${NC}"
        printf '  %sFW%s : %s%s%s\n'          "${BOLD}" "${NC}" "${FAINT}"  "${fw_name}"    "${NC}"
        printf '  %sDevice name%s : %s%s%s\n' "${BOLD}" "${NC}" "${GREEN}"  "${device_name}" "${NC}"
        printf '\n'

        if [[ "${device_name}" == "${target_device}" ]]; then
            SN="${sn}"
            return 0
        fi
    done

    printf '%s\n' "${RED}No ST-Link found for device '${target_device}'.${NC}"
    exit 1
}

# Locate the STM32_Programmer_CLI
# Extract the serial number of the ST link
# Burn the FLASH.hex

CLI="$(detect_cli)"

if [[ -z "${CLI}" ]]; then
    printf '%s\n' "${RED}STM32_Programmer_CLI not found${NC}"
    exit 1
fi

if [[ ! -f "${HEX}" ]]; then
    printf '%s\n' "${RED}File not found : ${HEX}${NC}"
    exit 1
fi

extract_targets ${target_device}

printf '%s\n' "${GREEN}ST-Link detected : ${SN}${NC}"
printf '%s\n' "${GREEN}Device name : ${target_device}${NC}"
printf '%s\n' "${GREEN}Flashing of the ${HEX} ...${NC}"

"$CLI" -c port=SWD mode=UR sn="$SN" freq=8000 ap=0 -e all -w "$HEX" -v -rst
