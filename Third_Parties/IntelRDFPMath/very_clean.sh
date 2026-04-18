#!/usr/bin/env zsh
set -euo pipefail

readonly library_name=libIntelRDFPMath

rm -rf build
rm -rf Library
find Construction -type d -name "build*" -prune -exec rm -r "{}" +
rm -f Construction/*/${library_name}_ready.txt(N)
