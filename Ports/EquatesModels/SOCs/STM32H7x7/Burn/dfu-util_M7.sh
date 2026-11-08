#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal: script for burning the arm M7 flash via the dfu-util.
#
#       - Usage:
#        ./dfu-util_M7.sh

set -e

dfu-util -d 0483:df11 --alt 0 --dfuse-address 0x08000000:leave --download FLASH.bin \
    2> >(grep -vF 'dfu-util: Error during download get_status: -99 (LIBUSB_ERROR_OTHER)' >&2) || [ "$?" -eq 74 ]
