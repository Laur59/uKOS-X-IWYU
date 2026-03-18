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

TFL_PYTHON_ENV="${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Tflite-env"

if [[ -d "${TFL_PYTHON_ENV:-}" ]]; then
    source "${TFL_PYTHON_ENV}/bin/activate"
fi

MODEL_FILE="mlp_TFL_test.tflite"

# Create the TensorFlowLite C executable

xxd -i "${MODEL_FILE}" > mlp_TFL_test.c_inc
