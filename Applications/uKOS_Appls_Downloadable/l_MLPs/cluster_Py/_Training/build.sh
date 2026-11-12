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
# Goal:		Build the mlpn model
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

# Add current directory to PYTHONPATH
export PYTHONPATH="${PYTHONPATH:+$PYTHONPATH:}$(pwd)"

python3 "${PATH_UKOS_X_PACKAGE}/OS/Lib_neurals/mlpn/backprop.py"
rm -rf __pycache__
