#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     script for burning the arm flash via the jlinkexe.
#           !!! It is mandatory to program the CM7 before the CM4
#
#           - Usage:
#             cmake --build build --target burn     (sets SOC)
#             SOC=STM32H757 ./jlinkexe.sh           (from Variant_*/build)

set -e

: "${SOC:?set SOC to STM32H747 or STM32H757}"

CALL_DIR="${PWD:A}"
PROJECT_ROOT="${CALL_DIR:h:h}"

cd "${PROJECT_ROOT}"

JLinkExe << EOF
device ${SOC}XI_M7
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
