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

TFL_PYTHON_ENV="${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Tflite-env"
MLPN_CONVERTER="${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/uKOS_Tools/tflite_structure"

if [[ -d "${TFL_PYTHON_ENV:-}" ]]; then
    source "${TFL_PYTHON_ENV}/bin/activate"
fi

MODEL_FILE="mlp_model.tflite"

xxd -i "${MODEL_FILE}" > mlp_model.c_inc

# Now generate the uKOS-X mlpn model

python3 "${MLPN_CONVERTER}/tflite_structure.py" "${MODEL_FILE}" -o structure.c


