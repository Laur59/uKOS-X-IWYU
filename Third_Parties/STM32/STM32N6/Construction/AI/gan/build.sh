#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     Generate the code from the TF model to the NPU

set -euo pipefail

export PATH_UKOS_X_PACKAGE="${0:A:h:h:h:h:h:h:h}"
if [[ -z "${PATH_UKOS_X_PACKAGE:-}" ]]; then
    echo "Variable PATH_UKOS_X_PACKAGE is not set!"
    exit 1
fi

SCRIPT_DIR="${0:A:h}"

readonly NETWORK="gan"
readonly MODEL="NN_model"
readonly DST_WEIGHTS="NN_weight"
readonly SRC_WEIGHTS="stedgeai-output/network_atonbuf.xSPI2"

readonly TFLITE_PYENV="${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Construction/Pyenv/Tflite_Pyenv"
readonly PROFILE="${PATH_UKOS_X_PACKAGE}/Third_Parties/STM32/STM32N6/Construction/AI/${NETWORK}/mapping/mapping.json"
readonly MPOOL="${PATH_UKOS_X_PACKAGE}/Third_Parties/STM32/STM32N6/Construction/AI/${NETWORK}/mapping/mapping.mpool"
readonly OUTPUT="${PATH_UKOS_X_PACKAGE}/Third_Parties/STM32/STM32N6/Library/AI/${NETWORK}/stedgeai-output"
readonly STM32_NEURAL_ART="${PATH_UKOS_X_PACKAGE}/Third_Parties/STM32/STM32N6/STEdgeAI/4.0/Utilities/mac"

if [[ -d "${TFLITE_PYENV}" ]]; then
    source "${TFLITE_PYENV}/bin/activate"
fi

if [[ ! -f "${MODEL}.xxd" ]]; then
    echo "Model not found: ${MODEL}.xxd"
    exit 1
fi

if [[ ! -f "${PROFILE}" ]]; then
    echo "Neural-ART profile not found: ${PROFILE}"
    exit 1
fi

if [[ ! -f "${MPOOL}" ]]; then
    echo "Neural-ART memory pool not found: ${MPOOL}"
    exit 1
fi

rm -rf "${OUTPUT}"
mkdir -p "${OUTPUT}"

xxd -r "${MODEL}.xxd" > "${MODEL}.tflite"
${STM32_NEURAL_ART}/stedgeai generate --model "${MODEL}.tflite" --target stm32n6 --st-neural-art "default@${PROFILE}" --output "${OUTPUT}"

make

# Copy the weight set

cp "${SRC_WEIGHTS}.raw" "${DST_WEIGHTS}.bin"

rm -rf st_ai_ws
rm -rf stedgeai-output
rm -rf "${MODEL}.tflite"

