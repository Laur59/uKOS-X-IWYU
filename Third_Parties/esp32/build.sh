#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     Build the esp-idf & AT firmware package

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL

PATH_UKOS_X_PACKAGE="${PATH_UKOS_X_PACKAGE:-${0:a:h:h:h}}"

# Colours for messages

readonly RED=$'\033[0;31m'
readonly GREEN=$'\033[0;32m'
readonly YELLOW=$'\033[0;33m'
readonly BLUE=$'\033[0;34m'
readonly BOLD=$'\033[1m'
readonly FAINT=$'\033[2m'
readonly ITALIC=$'\033[3m'
readonly NC=$'\033[0m' # No Color

readonly splash='
╔════════════════════════════════════════════════════════════╗
║        esp-idf & AT firmware Package Build System          ║
║      Fetching upstream + Building all architectures        ║
╚════════════════════════════════════════════════════════════╝
'
printf '%b%s%b' "${BLUE}" "${splash}" "${NC}"

# Packages
# --------

readonly URL="https://dl.espressif.com/esp-at/firmwares/esp32/ESP32-WROOM-32/ESP32-WROOM-32-AT-V4.1.1.0.zip"
readonly ARCHIVE="ESP32-WROOM-32-AT-V4.1.1.0"
readonly package=6.0
readonly hash=338f341

# Clone the right packages

printf '\n%bDownload the esp-idf package ...%b\n\n' "${BOLD}" "${NC}"

cd "${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32"
rm -rf "${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32/esp-idf-${package}"
git clone --recursive https://github.com/espressif/esp-idf.git "esp-idf-${package}"
cd "esp-idf-${package}"
git checkout "${hash}"

# Update path links

cd ..
rm -f esp-idf-current
ln -s "esp-idf-${package}" esp-idf-current

printf '\n%bDownload the AT firmware package ...%b\n\n' "${BOLD}" "${NC}"

cd esp-idf-current
mkdir -p AT_firmware

wget -O "$ARCHIVE".zip "$URL"
unzip "$ARCHIVE".zip

cd "$ARCHIVE"
mv "$ARCHIVE" ../AT_firmware
cd ..
rm "$ARCHIVE".zip
rm -rf "$ARCHIVE"

printf '\n🎉 %bBuild Complete%b\n\n' "${GREEN}" "${NC}"
