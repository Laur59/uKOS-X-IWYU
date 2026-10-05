#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# Purpose:
#   Remove the build trees and the prebuilt library of the FatFs package.
#
# Usage:
#   ./very_clean.sh

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL

readonly PATH_PRG="${0:a:h}"

cd "${PATH_PRG}"

rm -rf build
rm -rf Library
find Construction -type d -name "build*" -prune -exec rm -r "{}" +
