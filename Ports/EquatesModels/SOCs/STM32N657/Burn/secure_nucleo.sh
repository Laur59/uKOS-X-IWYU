#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# Goal:     script for burning the arm flash via the stm32programmer.
#           script mainly generated with chatgpt.
#           This is for nucleo boards.
#
#           - Usage:
#             ./secure_nucleo.sh
#
#           The ST-Link used is the one whose firmware reports the board
#           name NUCLEO-N657X0-Q, so a Discovery_N657 may stay attached.

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL

SCRIPT_PATH="${0:A:h}"
PATH_UKOS_X_PACKAGE="${SCRIPT_PATH:A:h:h:h:h:h}"

BOOT="FSBL"
APPL="FLASH"
readonly BOARD_NAME='NUCLEO-N657X0-Q'

if [ -f "${PATH_UKOS_X_PACKAGE}/Third_Parties/STM32/STM32N6/Library/fsbl/fsbl_nucleo.noSignature" ]; then
    cp -f "${PATH_UKOS_X_PACKAGE}/Third_Parties/STM32/STM32N6/Library/fsbl/fsbl_nucleo.noSignature" "${SCRIPT_PATH}/fsbl_nucleo.noSignature"
    cp -f "${SCRIPT_PATH}/fsbl_nucleo.noSignature" "${BOOT}.bin"

elif [ -f "${SCRIPT_PATH}/fsbl_nucleo.noSignature" ]; then
    cp -f "${SCRIPT_PATH}/fsbl_nucleo.noSignature" "${BOOT}.bin"

else
    echo "You need to build the fsbl.bin"
    exit 1
fi

STM32_PROGRAMMER_CLI="${STM32_PROGRAMMER_CLI:-/Applications/STMicroelectronics/STM32Cube/STM32CubeProgrammer/STM32CubeProgrammer.app/Contents/Resources/bin/STM32_Programmer_CLI}"
if [[ ! -x "${STM32_PROGRAMMER_CLI}" ]]; then
 print -u2 "Error: STM32_Programmer_CLI not found."
 print -u2 "Install STM32CubeProgrammer, or set STM32_PROGRAMMER_CLI to its full path:"
 print -u2 "  export STM32_PROGRAMMER_CLI=/path/to/STM32_Programmer_CLI"
 exit 1
fi

STM32_PROGRAMMER_BIN=${STM32_PROGRAMMER_CLI:h}
STM32_PROGRAMMER_SIG="${STM32_PROGRAMMER_BIN}/STM32_SigningTool_CLI"

if [[ ! -x "${STM32_PROGRAMMER_SIG}" ]]; then
    print -u2 "Error: STM32_SigningTool_CLI not found at ${STM32_PROGRAMMER_SIG}"
    exit 1
fi

# Select the ST-Link of this board by the board name its firmware reports and
# set SN. Both N657 boards report the same device, so the device name cannot
# tell them apart. "-l st" only enumerates the probes: it connects to no
# target, so no attached board is reset. Only the probe list is parsed: the
# UART section after it repeats "Board Name" and "ST-LINK SN" for every
# ST-Link VCOM port, name first.

find_probe() {
    local listing line sn='' in_list=0
    local -a probes matches

    listing=$("${STM32_PROGRAMMER_CLI}" -l st 2>&1 | sed $'s/\e\\[[0-9;]*m//g') || true

    for line in "${(@f)listing}"; do
        if [[ "${line}" == *'ST-LINK Probes List'* ]]; then
            in_list=1
        elif (( ! in_list )); then
            continue
        elif [[ "${line}" =~ '^(-----|=====)' ]]; then
            break
        elif [[ "${line}" =~ 'ST-LINK SN *: *([^[:space:]]+)' ]]; then
            sn="${match[1]}"
        elif [[ "${line}" =~ 'Board Name *: *([^[:space:]]+)' ]]; then
            probes+=("${sn}  ${match[1]}")
            if [[ "${match[1]}" == "${BOARD_NAME}" ]]; then
                matches+=("${sn}")
            fi
        fi
    done

    if (( ${#matches} == 1 )); then
        SN="${matches[1]}"
        print "ST-Link ${SN} (${BOARD_NAME})"
        return 0
    fi

    if (( ${#matches} == 0 )); then
        print -u2 "Error: no ST-Link reports the board name ${BOARD_NAME}."
    else
        print -u2 "Error: several ST-Links report the board name ${BOARD_NAME}: ${matches[*]}"
    fi
    if (( ${#probes} == 0 )); then
        print -u2 "No ST-Link detected."
    else
        print -u2 "Connected ST-Links:"
        printf '  %s\n' "${probes[@]}" >&2
    fi
    exit 1
}

find_probe

"${STM32_PROGRAMMER_SIG}" -s -bin "${BOOT}.bin" -nk -of 0x80000000 -t fsbl -o "${BOOT}-trusted.bin" -hv 2.3 -dump "${BOOT}-trusted.bin" -align
"${STM32_PROGRAMMER_SIG}" -s -bin "${APPL}.bin" -nk -of 0x80000000 -t fsbl -o "${APPL}-trusted.bin" -hv 2.3 -dump "${APPL}-trusted.bin" -align

chmod +w "${BOOT}-trusted.bin" "${APPL}-trusted.bin"

"${STM32_PROGRAMMER_CLI}" -c port=SWD sn="${SN}" mode=HOTPLUG ap=1 -el "${STM32_PROGRAMMER_BIN}/ExternalLoader/MX25UM51245G_STM32N6570-NUCLEO.stldr" -e all
"${STM32_PROGRAMMER_CLI}" -c port=SWD sn="${SN}" mode=HOTPLUG ap=1 -el "${STM32_PROGRAMMER_BIN}/ExternalLoader/MX25UM51245G_STM32N6570-NUCLEO.stldr" -d "${BOOT}-trusted.bin" 0x70000000
"${STM32_PROGRAMMER_CLI}" -c port=SWD sn="${SN}" mode=HOTPLUG ap=1 -el "${STM32_PROGRAMMER_BIN}/ExternalLoader/MX25UM51245G_STM32N6570-NUCLEO.stldr" -d "${APPL}-trusted.bin" 0x70100000
