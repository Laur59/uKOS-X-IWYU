#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     script for burning the arm flash via the stm32programmer.
#           script mainly generated with chatgpt.
#           This is for discovery boards.
#
#           - Usage:
#             ./secure_nucleo.sh

set -euo pipefail

SCRIPT_PATH="${0:A:h}"

BOOT="FSBL"
APPL="FLASH"

if [ -f "${SCRIPT_PATH}/fsbl/build/discovery/fsbl.bin" ]; then
    cp -f "${SCRIPT_PATH}/fsbl/build/discovery/fsbl.bin" "${SCRIPT_PATH}/fsbl_discovery.noSignature"
    cp -f "${SCRIPT_PATH}/fsbl_discovery.noSignature" "${BOOT}.bin"

elif [ -f "${SCRIPT_PATH}/fsbl_discovery.noSignature" ]; then
    cp -f "${SCRIPT_PATH}/fsbl_discovery.noSignature" "${BOOT}.bin"

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

"${STM32_PROGRAMMER_SIG}" -s -bin "${BOOT}.bin" -nk -of 0x80000000 -t fsbl -o "${BOOT}-trusted.bin" -hv 2.3 -dump "${BOOT}-trusted.bin" -align
"${STM32_PROGRAMMER_SIG}" -s -bin "${APPL}.bin" -nk -of 0x80000000 -t fsbl -o "${APPL}-trusted.bin" -hv 2.3 -dump "${APPL}-trusted.bin" -align

chmod +w "${BOOT}-trusted.bin" "${APPL}-trusted.bin"

"${STM32_PROGRAMMER_CLI}" -c port=SWD mode=HOTPLUG ap=1 -el "${STM32_PROGRAMMER_BIN}/ExternalLoader/MX66UW1G45G_STM32N6570-DK.stldr" -d "${BOOT}-trusted.bin" 0x70000000 -v
"${STM32_PROGRAMMER_CLI}" -c port=SWD mode=HOTPLUG ap=1 -el "${STM32_PROGRAMMER_BIN}/ExternalLoader/MX66UW1G45G_STM32N6570-DK.stldr" -d "${APPL}-trusted.bin" 0x70100000 -v
