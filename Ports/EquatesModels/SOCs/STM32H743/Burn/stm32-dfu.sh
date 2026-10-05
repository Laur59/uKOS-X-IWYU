#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# Burn the STM32H743 flash over USB DFU with the STM32_Programmer_CLI.
#
# Usage, from the directory that holds FLASH.hex:
#       ./stm32-dfu.sh
#
# The board must already be in DFU mode. The DFU device used is the one whose
# device ID is that of the STM32H742/743/753/750, so another STM32 in DFU mode
# may stay attached.

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL

# Colours for messages

readonly RED=$'\033[0;31m'
readonly GREEN=$'\033[0;32m'
readonly NC=$'\033[0m' # No Color

readonly target_device='STM32H7xx'
readonly target_id='0x0450'
readonly HEX='FLASH.hex'
readonly FLASH_BASE='0x08000000'

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

# Find the DFU device whose device ID is ${target_id} and set the global PORT
# variable to its index (USB1, USB2, ...). "-l usb" only enumerates the
# devices: it connects to none of them.

find_dfu() {
    local listing line index=''
    local -a devices matches

    listing=$("${CLI}" -l usb 2>&1 | sed $'s/\e\\[[0-9;]*m//g') || true

    for line in "${(@f)listing}"; do
        if [[ "${line}" =~ 'Device Index *: *([^[:space:]]+)' ]]; then
            index="${match[1]}"
        elif [[ "${line}" =~ 'Device ID *: *([^[:space:]]+)' ]]; then
            devices+=("${index}  ${match[1]}")
            if [[ "${match[1]:l}" == "${target_id}" ]]; then
                matches+=("${index}")
            fi
        fi
    done

    if (( ${#matches} == 1 )); then
        PORT="${matches[1]}"
        return 0
    fi

    if (( ${#matches} == 0 )); then
        printf '%s\n' "${RED}No ${target_device} in DFU mode.${NC}"
    else
        printf '%s\n' "${RED}Several ${target_device} in DFU mode : ${matches[*]}${NC}"
    fi
    if (( ${#devices} > 0 )); then
        printf '%s\n' 'STM32 devices in DFU mode (index, device ID) :'
        printf '  %s\n' "${devices[@]}"
    fi
    exit 1
}

# Locate the STM32_Programmer_CLI
# Find the DFU device
# Burn the FLASH.hex, verify it and start the application

CLI="$(detect_cli)"

if [[ -z "${CLI}" ]]; then
    printf '%s\n' "${RED}STM32_Programmer_CLI not found${NC}"
    exit 1
fi

if [[ ! -f "${HEX}" ]]; then
    printf '%s\n' "${RED}File not found : ${HEX}${NC}"
    exit 1
fi

find_dfu

printf '%s\n' "${GREEN}DFU device : ${PORT}${NC}"
printf '%s\n' "${GREEN}Device name : ${target_device}${NC}"
printf '%s\n' "${GREEN}Flashing of the ${HEX} ...${NC}"

"${CLI}" -c port="${PORT}" -w "${HEX}" -v -g "${FLASH_BASE}"
