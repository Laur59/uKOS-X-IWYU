#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     script for burning a demo into the arm flash via the stm32programmer.
#           This is for discovery boards.
#
#           - Usage:
#             ./burn.sh

set -euo pipefail

SCRIPT_PATH="${0:A:h}"

DEMO="gan"

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

"${STM32_PROGRAMMER_SIG}" -s -bin "${DEMO}.bin" -nk -of 0x80000000 -t fsbl -o "${DEMO}-trusted.bin" -hv 2.3 -dump "${DEMO}-trusted.bin" -align

chmod +w "${DEMO}-trusted.bin"

"${STM32_PROGRAMMER_CLI}" -c port=SWD mode=HOTPLUG ap=1 -el "${STM32_PROGRAMMER_BIN}/ExternalLoader/MX66UW1G45G_STM32N6570-DK.stldr" -d "${DEMO}-trusted.bin" 0x70300000 -v
