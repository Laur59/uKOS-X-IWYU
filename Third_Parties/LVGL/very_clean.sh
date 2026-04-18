#!/usr/bin/env zsh
set -euo pipefail

readonly library_name=libLVGL

rm -rf build
rm -fr Library
find LibraryBuild -type d -name "build*" -prune -exec rm -r "{}" +
rm -f LibraryBuild/*/${library_name}_ready.txt(N)
