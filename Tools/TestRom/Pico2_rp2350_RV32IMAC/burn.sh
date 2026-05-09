#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
#
# Goal:     script for burning the arm flash via the picotool.
#
#           - Usage:
#           ./burn.sh

set -euo pipefail

picotool load testROM.elf --family rp2350-riscv --verify
picotool reboot
