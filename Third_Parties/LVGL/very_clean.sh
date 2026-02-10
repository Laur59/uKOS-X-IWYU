#!/usr/bin/env zsh
set -euo pipefail

rm -rf build
find Library -type d -name "build*" -prune -exec rm -r "{}" +
rm -f Library/*/libLVGL.a(N)
rm -f Library/*/libLVGL_ready.txt(N)
