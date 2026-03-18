#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     script for burning the arm flash via the dfu-util.
#
#           - Usage:
#            ./dfu-util.sh

set -e

dfu-util -d 28e9:0189 --alt 0 --dfuse-address 0x08000000 --download FLASH.bin --reset
