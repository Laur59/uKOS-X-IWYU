#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Goal:     Build the First Stage Boot Loader package

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
║            FSBL and NPU Package Build System               ║
║      Fetching upstream + Building all architectures        ║
╚════════════════════════════════════════════════════════════╝
'
printf '%b%s%b' "${BLUE}" "${splash}" "${NC}"

# Packages
# --------

readonly socFamily=STM32N6
readonly package=1.4.0
readonly hash=c698033e

readonly TOOLCHAIN_PATH="${PATH_GCC_ARM}/bin"
readonly SOC_ROOT="${PATH_PRG}"
readonly FSBL_ROOT="${SOC_ROOT}/Construction/fsbl"
readonly LIBRARY_ROOT="${SOC_ROOT}/Library"
readonly CUBE_ROOT="${SOC_ROOT}/STM32CubeN6"

# Clone the right package

printf '\n%bCloning STM32CubeN6 ...%b\n\n' "${BOLD}" "${NC}"

cd "${PATH_PRG}"
if [[ ! -d "${CUBE_ROOT}" ]]; then
    git clone --branch "v${package}" --recursive --quiet --depth 100 https://github.com/STMicroelectronics/STM32CubeN6.git "${CUBE_ROOT}"
else
    git -C "${CUBE_ROOT}" fetch --quiet
fi
git -C "${CUBE_ROOT}" checkout "v${package}"

# The FSBL

rm -rf "${FSBL_ROOT}/build"

cmake -S "${FSBL_ROOT}" --preset nucleo -DCUBE_ROOT="${CUBE_ROOT}" -DTOOLCHAIN_PATH="${TOOLCHAIN_PATH}"
cmake --build "${FSBL_ROOT}/build/nucleo" --parallel

cmake -S "${FSBL_ROOT}" --preset discovery -DCUBE_ROOT="${CUBE_ROOT}" -DTOOLCHAIN_PATH="${TOOLCHAIN_PATH}"
cmake --build "${FSBL_ROOT}/build/discovery" --parallel

rm -rf "${LIBRARY_ROOT}/fsbl"
mkdir -p "${LIBRARY_ROOT}/fsbl"
cp -f "${FSBL_ROOT}/build/nucleo/fsbl.bin"    "${LIBRARY_ROOT}/fsbl/fsbl_nucleo.noSignature"
cp -f "${FSBL_ROOT}/build/discovery/fsbl.bin" "${LIBRARY_ROOT}/fsbl/fsbl_discovery.noSignature"

rm -rf "${FSBL_ROOT}/build"

# The NPU

(
cd "${SOC_ROOT}/Construction/AI/gan" || exit 1
    ./build.sh
)
