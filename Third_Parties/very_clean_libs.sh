#!/usr/bin/env zsh
set -euo pipefail

for dir in TinyUSB Tflite-micro MicroPython LVGL IntelRDFPMath FatFs decnumber
do
    cd "${dir}"
    ./very_clean.sh
    cd ..
done
