#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     script for burning the arm flash via the stm32programmer.
#           script mainly generated with chatgpt
#
#           - Usage:
#             ./secure.sh

set -euo pipefail

SCRIPT_PATH="${0:A:h}"

BOOT="FSBL"
APPL="FLASH"

if [ -f "${SCRIPT_PATH}/fsbl/build/release/fsbl.bin" ]; then
    cp -f "${SCRIPT_PATH}/fsbl/build/release/fsbl.bin" "${SCRIPT_PATH}/fsbl.noSignature"
    cp -f "${SCRIPT_PATH}/fsbl.noSignature" "${BOOT}.bin"

elif [ -f "${SCRIPT_PATH}/fsbl.noSignature" ]; then
    cp -f "${SCRIPT_PATH}/fsbl.noSignature" "${BOOT}.bin"

else
    echo "You need to build the fsbl.bin"
    exit 1
fi

STM32_PROGRAMMER_BIN="${STM32_PROGRAMMER_BIN:-/Applications/STMicroelectronics/STM32Cube/STM32CubeProgrammer/STM32CubeProgrammer.app/Contents/Resources/bin}"
STM32_PROGRAMMER_CLI="${STM32_PROGRAMMER_BIN}/STM32_Programmer_CLI"
STM32_PROGRAMMER_SIG="${STM32_PROGRAMMER_BIN}/STM32_SigningTool_CLI"

"${STM32_PROGRAMMER_SIG}" -s -bin "${BOOT}.bin" -nk -of 0x80000000 -t fsbl -o "${BOOT}-trusted.bin" -hv 2.3 -dump "${BOOT}-trusted.bin" -align
"${STM32_PROGRAMMER_SIG}" -s -bin "${APPL}.bin" -nk -of 0x80000000 -t fsbl -o "${APPL}-trusted.bin" -hv 2.3 -dump "${APPL}-trusted.bin" -align

chmod +w "${BOOT}-trusted.bin" "${APPL}-trusted.bin"

"${STM32_PROGRAMMER_CLI}" -c port=SWD mode=HOTPLUG ap=1 -el "${STM32_PROGRAMMER_BIN}/ExternalLoader/MX25UM51245G_STM32N6570-NUCLEO.stldr" -d "${BOOT}-trusted.bin" 0x70000000
"${STM32_PROGRAMMER_CLI}" -c port=SWD mode=HOTPLUG ap=1 -el "${STM32_PROGRAMMER_BIN}/ExternalLoader/MX25UM51245G_STM32N6570-NUCLEO.stldr" -d "${APPL}-trusted.bin" 0x70100000
