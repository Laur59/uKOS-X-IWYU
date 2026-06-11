#!/bin/zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal: Setup the esp32 environment.
#
#       usage:
#       source setup.sh

# Set the esp32 tool paths

IDF_PATH="${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32/esp-idf-current"
IDF_TOOLS_PATH="${IDF_PATH}/espressif-tools"
IDF_PYTHON_ENV_PATH="${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32/Construction/Pyenv/esp32_Pyenv"

export IDF_PATH
export IDF_TOOLS_PATH
export IDF_PYTHON_ENV_PATH

source "${IDF_PYTHON_ENV_PATH}/bin/activate"
PYTHON="${IDF_PYTHON_ENV_PATH}/bin/python"
export PYTHON

eval "$("${PYTHON}" "${IDF_PATH}/tools/idf_tools.py" export --format shell)"
export PATH="${IDF_PATH}/tools:${PATH}"

echo "Set the esp32 environment path for the project: ${PROJECT}"
