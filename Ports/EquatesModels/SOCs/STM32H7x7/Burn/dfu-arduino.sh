#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# Goal:     script for burning the arm flash through the DFU of the
#           Arduino Portenta bootloader (USB 2341:035b).
#           Enter the DFU by pressing RESET twice; the green LED pulses.
#           The CM7 image goes to 0x08040000 (behind the bootloader),
#           the CM4 image to 0x08100000.
#
#           - Usage (from the build or the Artefacts directory of a variant):
#             ./dfu-arduino.sh

set -e

readonly DFU_ID="2341:035b"

if ! command -v dfu-util &> /dev/null; then
    echo "dfu-util could not be found"
    exit 1
fi

VARIANT_DIR="${PWD:A:h}"
IMAGE="${VARIANT_DIR}/Artefacts/FLASH.bin"

case "${VARIANT_DIR:t}" in
    *CM7) ADDRESS=0x08040000 ;;
    *CM4) ADDRESS=0x08100000 ;;
    *)    echo "unknown core for ${VARIANT_DIR:t}"; exit 1 ;;
esac

if [[ ! -f "${IMAGE}" ]]; then
    echo "${IMAGE} not found"
    exit 1
fi

if ! dfu-util -l -d "${DFU_ID}" 2> /dev/null | grep -q "${DFU_ID}"; then
    echo "No Arduino DFU device (${DFU_ID}): press RESET twice, then run again"
    exit 1
fi

dfu-util -d "${DFU_ID}" -a 0 --dfuse-address "${ADDRESS}:leave" -D "${IMAGE}"
