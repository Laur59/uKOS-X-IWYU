#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     Create the TF model

set -euo pipefail

PATH_UKOS_X_PACKAGE="${0:A:h:h:h:h:h:h}"
if [[ -z "${PATH_UKOS_X_PACKAGE:-}" ]]; then
    echo "Variable PATH_UKOS_X_PACKAGE is not set!"
    exit 1
fi

TFLITE_PYENV="${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Construction/Pyenv/Tflite_Pyenv"

if [[ -d "${TFLITE_PYENV:-}" ]]; then
    source "${TFLITE_PYENV}/bin/activate"
fi

MODEL_FILE=NN_model

python3 NN_model.py --model_file ${MODEL_FILE}.tflite --mode full 2>"${MODEL_FILE}_warnings.log"

xxd "${MODEL_FILE}.tflite" > "${MODEL_FILE}.xxd"
