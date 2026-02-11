#!/usr/bin/env zsh
set -euo pipefail

rm -rf build
find Library -type d -name "build*" -prune -exec rm -r "{}" +
rm -f Library/*/libFatFs.a(N)
rm -f Library/*/libFatFs_ready.txt(N)
