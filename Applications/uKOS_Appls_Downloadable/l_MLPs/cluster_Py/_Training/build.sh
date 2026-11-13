#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Goal:     Build the mlpn model

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL

PATH_UKOS_X_PACKAGE="${0:A:h:h:h:h:h:h}"

# Dataset creation
if [[ ! (-f "DB_L_file.txt" && -f "DB_V_file.txt") ]]; then
    # Create the learning DB_L_file.txt and the validation DB_V_file.txt files
    python3 DB_Creator.py
fi

# Add current directory to PYTHONPATH
export PYTHONPATH="${PYTHONPATH:+$PYTHONPATH:}$(pwd)"

python3 "${PATH_UKOS_X_PACKAGE}/OS/Lib_neurals/mlpn/backprop.py"
rm -rf __pycache__
