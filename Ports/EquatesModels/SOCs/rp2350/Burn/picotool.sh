#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     script for burning the arm flash via the picotool.
#
#           - Usage:
#             ./picotool.sh

#set -euo pipefail

picotool load FLASH.elf --family rp2350-arm-s --verify
picotool reboot
