#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# Purpose:
#   Remove the build trees and the prebuilt libraries of the TensorFlow Lite
#   Micro package.
#
# Usage:
#   ./very_clean.sh

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL

readonly PATH_PRG="${0:a:h}"

cd "${PATH_PRG}"

rm -rf build
rm -f Library/*/libTFLite.a(N)
