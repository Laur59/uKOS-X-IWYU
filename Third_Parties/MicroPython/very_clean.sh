#!/usr/bin/env zsh
set -euo pipefail

rm -rf build
find Library -type d -name "build*" -prune -exec rm -r "{}" +
rm -f Library/*/libMicroPython.a(N)
rm -f Library/*/libMicroPython_ready.txt(N)
