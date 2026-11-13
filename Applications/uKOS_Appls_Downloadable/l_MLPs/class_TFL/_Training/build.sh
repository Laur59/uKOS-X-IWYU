#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Goal:     Create the TF model

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL

PATH_UKOS_X_PACKAGE="${0:A:h:h:h:h:h:h}"

# Dataset creation
if [[ ! (-f "DB_L_file.txt" && -f "DB_V_file.txt") ]]; then
    # Create the learning DB_L_file.txt and the validation DB_V_file.txt files
    python3 DB_Creator.py
fi

TFLITE_PYENV="${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Construction/Pyenv/Tflite_Pyenv"

if [[ -f "${TFLITE_PYENV}/bin/activate" ]]; then
    source "${TFLITE_PYENV}/bin/activate"
else
    print "No Python virtual environment available"
    exit 1
fi

MODEL_FILE=NN_model

python3 NN_model.py --model_file ${MODEL_FILE}.tflite 2>"${MODEL_FILE}_warnings.log"

# Keep the log only when the script printed something on stderr
[[ -s "${MODEL_FILE}_warnings.log" ]] || rm -f "${MODEL_FILE}_warnings.log"

xxd "${MODEL_FILE}.tflite" > "${MODEL_FILE}.xxd"

rm -f *.keras *.tflite
