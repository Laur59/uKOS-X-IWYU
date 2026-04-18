#!/usr/bin/env zsh
set -euo pipefail

readonly library_name=libLVGL

rm -rf build
rm -fr Library
find Construction -type d -name "build*" -prune -exec rm -r "{}" +
rm -f Construction/*/${library_name}_ready.txt(N)
