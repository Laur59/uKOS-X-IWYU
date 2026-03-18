#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Goal:     script for burning the arm flash via the kflash_bit_mic.
#
#           - Usage:
#             ./kflash_bit_mic.sh

set -e

case "$(uname)" in
    "Darwin")
        usbsn=`ioreg -p IOUSB -n Sipeed-Debug | grep "kUSBSerialNumberString" | sed 's/\(.*\)= "\(.*\)"/\2/'`"0"
        kflash -B bit_mic -p "/dev/tty.usbserial-${usbsn}" FLASH.bin
        ;;
    "Linux")
        kflash -B bit_mic -p /dev/ttyUSB0 FLASH.bin
        ;;
esac

