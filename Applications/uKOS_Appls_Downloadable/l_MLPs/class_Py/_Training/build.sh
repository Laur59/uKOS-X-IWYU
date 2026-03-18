#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     Build the mlpn model

set -euo pipefail

# Determine script directory (works if executed via ./script.sh or bash script.sh)
readonly PATH_PRG="${0:a:h}"
readonly PATH_UKOS="$(cd "$PATH_PRG/../../../../.." && pwd)"

export  PYTHONPATH="$PYTHONPATH:$(pwd)"

python3 "${PATH_UKOS_X_PACKAGE}/OS/Lib_neurals/mlpn/backprop.py"
rm -rf __pycache__
