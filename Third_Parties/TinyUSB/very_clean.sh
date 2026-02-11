#!/usr/bin/env zsh
set -euo pipefail

rm -rf build
find Library -type d -name "build*" -prune -exec rm -rf "{}" +
rm -f Library/Family/*/*/*/libTinyUSB_?S.a(N)
rm -f Library/Family/*/*/*/libTinyUSB_ready.txt(N)
