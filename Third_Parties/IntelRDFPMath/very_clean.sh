#!/usr/bin/env zsh
set -euo pipefail

readonly library_name=libIntelRDFPMath

rm -rf build
find Library -type d -name "build*" -prune -exec rm -r "{}" +
rm -f Library/*/${library_name}.a(N)
rm -f Library/*/${library_name}_ready.txt(N)
