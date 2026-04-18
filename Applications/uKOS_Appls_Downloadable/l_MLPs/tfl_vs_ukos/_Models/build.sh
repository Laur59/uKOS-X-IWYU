#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     Create the mlpn model

set -euo pipefail

if [[ -z "${PATH_UKOS_X_PACKAGE:-}" ]]; then
    echo "Variable PATH_UKOS_X_PACKAGE is not set!"
    exit 1
fi

TFLITE_PYENV="${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Construction/Pyenv/Tflite_Pyenv"
MLPN_CONVERTER="${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Construction/Tools/tflite_structure"

if [[ -d "${TFLITE_PYENV:-}" ]]; then
    source "${TFLITE_PYENV}/bin/activate"
fi

MODEL_FILE="mlp_model.tflite"

xxd -i "${MODEL_FILE}" > mlp_model.c_inc

# Now generate the uKOS-X mlpn model

python3 "${MLPN_CONVERTER}/tflite_structure.py" "${MODEL_FILE}" -o structure.c


