#!/usr/bin/env bash
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Goal:     script for burning the arm flash via the jlinkexe.
#
#           - Usage:
#             ./jlinkexe.sh

set -e

JLinkExe -device STM32L4R5ZI -if SWD -speed 8000 <<EOF
Connect
Reset
Halt
LoadFile FLASH.hex
Reset
Go
Exit
EOF
