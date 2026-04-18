#!/usr/bin/env zsh
set -euo pipefail

rm -rf build
rm -fr Library
find Construction -type d -name "build*" -prune -exec rm -rf "{}" +
rm -f Construction/Family/*/*/*/libTinyUSB_ready.txt(N)
