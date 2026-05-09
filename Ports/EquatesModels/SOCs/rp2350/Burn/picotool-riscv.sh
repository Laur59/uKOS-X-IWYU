#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Goal:     script for burning the RISC-V flash via the picotool.
#
#           - Usage:
#             ./picotool-riscv.sh

#set -euo pipefail

picotool load FLASH.elf --family rp2350-riscv --verify
picotool reboot
