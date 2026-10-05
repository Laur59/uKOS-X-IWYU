#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# Purpose:
#   Remove the build trees and the prebuilt libraries of every third-party
#   package that ships a cleaner.
#
# Usage:
#   ./very_clean_libs.sh

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL NULL_GLOB

readonly PATH_PRG="${0:a:h}"

cd "${PATH_PRG}"

local -a cleaners
cleaners=(*/very_clean.sh)

if (( ${#cleaners} == 0 )); then
    print -u2 "No very_clean.sh found under ${PATH_PRG}"
    exit 1
fi

for cleaner in ${cleaners}; do
    print "Cleaning ${cleaner:h} ..."
    ( cd "${cleaner:h}" && ./very_clean.sh )
done
