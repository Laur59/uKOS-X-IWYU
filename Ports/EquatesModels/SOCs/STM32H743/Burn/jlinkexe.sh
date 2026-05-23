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
device STM32H743II
r h
loadfile Variant_Test/System/FLASH.hex
r
g
q
EOF
