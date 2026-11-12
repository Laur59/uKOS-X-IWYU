#!/usr/bin/env zsh
#
# build.
# ======
#
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
#------------------------------------------------------------------------
# Author:	Edo. Franzi			The 2025-01-01
# Modifs:	Laurent von Allmen	The 2026-11-12
#
# Project:	uKOS-X
# Goal:		Create the TF model
#
#   (c) 2025-2026, Edo. Franzi
#   --------------------------
#                                              __ ______  _____
#   Edo. Franzi                         __  __/ //_/ __ \/ ___/
#   5-Route de Cheseaux                / / / / ,< / / / /\__ \
#   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
#                                     \__,_/_/ |_\____//____/
#   edo.franzi@ukos.ch
#
#   Description: Lightweight, real-time multitasking operating
#   system for embedded microcontroller and DSP-based systems.
#
#   Permission is hereby granted, free of charge, to any person
#   obtaining a copy of this software and associated documentation
#   files (the "Software"), to deal in the Software without restriction,
#   including without limitation the rights to use, copy, modify,
#   merge, publish, distribute, sublicense, and/or sell copies of the
#   Software, and to permit persons to whom the Software is furnished
#   to do so, subject to the following conditions:
#
#   The above copyright notice and this permission notice shall be
#   included in all copies or substantial portions of the Software.
#
#   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
#   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
#   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
#   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
#   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
#   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
#   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#   SOFTWARE.
#
#------------------------------------------------------------------------

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL

if [[ -z "${PATH_UKOS_X_PACKAGE:-}" ]]; then
	echo "Variable PATH_UKOS_X_PACKAGE is not set!"
	exit 1
fi

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
