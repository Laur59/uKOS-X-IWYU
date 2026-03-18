#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     script for burning the arm flash via the jlinkexe.
#           !!! It is mandatory to program the CM7 before the CM4
#
#           - Usage:
#             ./jlinkexe.sh

set -e

CALL_DIR="${PWD:A}"
PROJECT_ROOT="${CALL_DIR:h:h}"

cd "${PROJECT_ROOT}"

JLinkExe << EOF
device STM32H747XI
si SWD
speed 4000
r
connect /Reset
erase
loadbin Variant_Test_CM7/Artefacts/FLASH.bin 0x08000000
loadbin Variant_Test_CM4/Artefacts/FLASH.bin 0x08100000
r
g
exit
EOF
