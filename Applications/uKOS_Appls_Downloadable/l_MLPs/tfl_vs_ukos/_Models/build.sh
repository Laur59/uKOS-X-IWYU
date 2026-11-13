#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     Create the mlpn model

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL

PATH_UKOS_X_PACKAGE="${0:A:h:h:h:h:h:h}"

# Work in this script's directory, wherever it is started from
cd "${0:A:h}"

# Copy the models of the examples class_TFL (NN_model.xxd) and class_Py (network.c_inc).
# Both are refreshed at every run: network.c_inc gets its weights from the TFLite model
# below, so it is never edited by hand.
for src_model in ../../class_TFL/_Training/NN_model.xxd ../../class_Py/_Training/network.c_inc; do
    if [[ ! -f "${src_model}" ]]; then
        print -u2 "Create first models in ${src_model:h:h:t}"
        exit 1
    fi
    cp "${src_model}" .
done

TFLITE_PYENV="${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Construction/Pyenv/Tflite_Pyenv"
MLPN_CONVERTER="${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Construction/Tools/tflite_structure"

if [[ -f "${TFLITE_PYENV}/bin/activate" ]]; then
    source "${TFLITE_PYENV}/bin/activate"
else
    print "No Python virtual environment available"
    exit 1
fi

MODEL_FILE=NN_model

xxd -r "${MODEL_FILE}.xxd" > "${MODEL_FILE}.tflite"

# Now generate the uKOS-X mlpn model

python3 "${MLPN_CONVERTER}/tflite_structure.py" "${MODEL_FILE}.tflite" -o structure.c

# Give the MLPN network the weights of the TFLite model, so both infer the same network
python3 inject_weights.py structure.c network.c_inc
