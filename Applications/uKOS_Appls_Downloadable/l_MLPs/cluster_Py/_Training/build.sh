#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     Build the mlpn model

set -euo pipefail

PATH_UKOS_X_PACKAGE="${0:A:h:h:h:h:h:h}"
if [[ -z "${PATH_UKOS_X_PACKAGE:-}" ]]; then
    echo "Variable PATH_UKOS_X_PACKAGE is not set!"
    exit 1
fi

export  PYTHONPATH="$PYTHONPATH:$(pwd)"

python3 "${PATH_UKOS_X_PACKAGE}/OS/Lib_neurals/mlpn/backprop.py"
rm -rf __pycache__
