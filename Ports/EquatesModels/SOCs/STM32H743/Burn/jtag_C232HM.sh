#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     script for burning the arm flash via the openocd.
#           Cable C232HM
#           Full jtag transport
#
#           - Usage:
#             ./jtag_C232HM.sh

set -e

SCRIPT_PATH="${0:A:h}"

# Allow the user to choose its prefered application

if [[ -z "$OPENOCD" ]]; then
    if command -v openocd-cortex &> /dev/null
    then
        OPENOCD=openocd-cortex
    elif command -v openocd &> /dev/null
    then
        OPENOCD=openocd
    else
        echo "openocd could not be found"
        exit 1
    fi
fi

"${OPENOCD}" -f "${SCRIPT_PATH}/jtag_C232HM.cfg"
