#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Goal: Build the First Stage Boot Loader package

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL

if [[ -z "${PATH_GCC_ARM:-}" ]]; then
    echo 'Variable PATH_GCC_ARM is not set!'
    exit 1
fi

# Determine script directory (works if executed via ./script.sh or zsh script.sh)

readonly PATH_PRG="${0:a:h}"

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
║                FSBL Package Build System                   ║
║      Fetching upstream + Building all architectures        ║
╚════════════════════════════════════════════════════════════╝
'
printf '%b%s%b' "${BLUE}" "${splash}" "${NC}"

# Packages
# --------

readonly package=1.4.0
readonly hash=c698033e

# export PATH="${PATH_GCC_ARM}/bin":"${PATH}"
# printf '%b%s%b\n' "${YELLOW}" "$(arm-none-eabi-gcc --version)" "${NC}"
readonly TOOLCHAIN_PATH="${PATH_GCC_ARM}/bin"

readonly CUBE_ROOT="${PATH_PRG}/STM32CubeN6"

# Clone the right package

printf '\n%bCloning STM32CubeN6 ...%b\n\n' "${BOLD}" "${NC}"

cd "${PATH_PRG}"
if [[ ! -d "${CUBE_ROOT}" ]]; then
    git clone --branch "v${package}" --recursive --quiet --depth 100 https://github.com/STMicroelectronics/STM32CubeN6.git "${CUBE_ROOT}"
else
    git -C "${CUBE_ROOT}" fetch --quiet
fi
git -C "${CUBE_ROOT}" checkout "v${package}"

rm -rf "Construction/build"

cmake -S Construction --preset nucleo -DCUBE_ROOT="${CUBE_ROOT}" -DTOOLCHAIN_PATH="${TOOLCHAIN_PATH}"
cmake --build "Construction/build/nucleo"

cmake -S Construction --preset discovery -DCUBE_ROOT="${CUBE_ROOT}" -DTOOLCHAIN_PATH="${TOOLCHAIN_PATH}"
cmake --build "Construction/build/discovery"

rm -fr "Library/n6"
mkdir -p "Library/n6"
cp -f  "Construction/build/nucleo/fsbl.bin" "Library/n6/fsbl_nucleo.noSignature"
cp -f "Construction/build/discovery/fsbl.bin" "Library/n6/fsbl_discovery.noSignature"

rm -fr "Construction/build"
