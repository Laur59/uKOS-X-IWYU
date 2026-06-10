#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     Create the TF model

set -euo pipefail

if [[ -z "${PATH_UKOS_X_PACKAGE:-}" ]]; then
    echo "Variable PATH_UKOS_X_PACKAGE is not set!"
    exit 1
fi

TFLITE_PYENV="${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Construction/Pyenv/Tflite_Pyenv"

if [[ -d "${TFLITE_PYENV:-}" ]]; then
    source "${TFLITE_PYENV}/bin/activate"
fi

# First, load the image dataset

if [ ! -d "DB_faces" ]; then
    echo "DB_faces does not exist, create a new set"
    python DB_Creator.py
fi

MODEL_FILE="mlp_model.tflite"

python mlp_model.py --model_file ${MODEL_FILE} --mode full 2>mlp_model_warnings.log

xxd -i "${MODEL_FILE}" > mlp_model.c_inc
