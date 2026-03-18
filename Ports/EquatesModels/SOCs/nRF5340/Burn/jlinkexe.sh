#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     script for burning the arm flash via the jlinkexe.
#
#           - Usage:
#             ./jlinkexe.sh

set -e

CALL_DIR="${PWD:A}"
PROJECT_ROOT="${CALL_DIR:h:h}"

cd "${PROJECT_ROOT}"

JLinkExe -if swd -speed 8000 <<EOF
device nrf5340_xxAA_NET
r h
loadfile Variant_Test_Net/System/FLASH.hex
device nrf5340_xxAA_APP
r h
loadfile Variant_Test_App/System/FLASH.hex
r
g
device nrf5340_xxAA_NET
r
g
q
EOF
