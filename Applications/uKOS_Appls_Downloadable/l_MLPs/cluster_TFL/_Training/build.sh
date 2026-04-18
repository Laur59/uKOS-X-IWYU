#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     Create the TF model

set -euo pipefail

# Determine script directory (works if executed via ./script.sh or bash script.sh)
readonly PATH_PRG="${0:a:h}"
readonly PATH_UKOS="$(cd "$PATH_PRG/../../../../.." && pwd)"

    echo "Variable PATH_UKOS_X_PACKAGE is not set!"
    exit 1
fi

TFLITE_PYENV="${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Construction/Pyenv/Tflite_Pyenv"

if [[ -d "${TFLITE_PYENV:-}" ]]; then
    source "${TFLITE_PYENV}/bin/activate"
fi

MODEL_FILE="mlp_model.tflite"

python3 mlp_model.py --model_file ${MODEL_FILE} 2>mlp_model_warnings.log

xxd -i "${MODEL_FILE}" > mlp_model.c_inc
