#!/usr/bin/env zsh
set -euo pipefail

rm -rf build Library
find Construction -type d -name "build*" -prune -exec rm -r "{}" +
