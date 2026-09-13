#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# Goal:     Build the Tflite-micro package
#
# Usage:
#   ./build.sh [-G]
#
#   -G  Build with GNU gcc instead of Clang/LLVM (the default)
#
# Upstream's make is only used to export the standalone source trees
# (create_tflm_tree.py); CMakeLists.txt compiles them with the uKOS-X toolchains.

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL

zparseopts -D -F -- G=opt_gcc || exit 1
if (( ${#opt_gcc} )); then
    use_llvm=OFF
else
    use_llvm=ON
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
║           TFlite-micro Package Build System                ║
║      Fetching upstream + Building all architectures        ║
╚════════════════════════════════════════════════════════════╝
'
printf '%b%s%b' "${BLUE}" "${splash}" "${NC}"

if [[ -d 'Construction/Pyenv/Tflite_Pyenv/bin' ]]; then
    source 'Construction/Pyenv/Tflite_Pyenv/bin/activate'
fi

# Packages
# --------

readonly hash=f8c117b

printf '\n%bDownload the Tflite-micro package ...%b\n\n' "${BOLD}" "${NC}"

# Clone the right package
cd "${PATH_PRG}"
if [[ ! -d Tflite-micro-current ]]; then
    git clone https://github.com/tensorflow/tflite-micro.git Tflite-micro-current
else
    git -C Tflite-micro-current fetch
fi
git -C Tflite-micro-current checkout "${hash}"

# Upstream's make checks for its GCC toolchains while it lists the sources, and
# downloads them when they are missing. Point it at the installed ones before
# the export; nothing is compiled with them.
cd "Tflite-micro-current/tensorflow/lite/micro/tools/make"
mkdir -p downloads
cd downloads
if [[ ! -L gcc_embedded ]]; then
    rm -fr gcc_embedded
    ln -s "${PATH_GCC_ARM}" gcc_embedded
fi
if [[ ! -L riscv_toolchain ]]; then
    rm -fr riscv_toolchain
    ln -s "${PATH_GCC_RVXX}" riscv_toolchain
fi
cd "${PATH_PRG}"

# Export the standalone source trees (and the headers the applications include):
# cortex-M with the CMSIS-NN kernels, RISC-V with the reference kernels.
# The exporter writes over an existing tree, so clear it first.

printf '\n%bExport the Tflite-micro source trees ...%b\n\n' "${BOLD}" "${NC}"

rm -fr Library/Generic/CORTEX_M_generic Library/Generic/RISCV64_generic
cd Tflite-micro-current

python3 tensorflow/lite/micro/tools/project_generation/create_tflm_tree.py \
    --makefile_options='TARGET=cortex_m_generic OPTIMIZED_KERNEL_DIR=cmsis_nn TARGET_ARCH=project_generation' \
    ../Library/Generic/CORTEX_M_generic

python3 tensorflow/lite/micro/tools/project_generation/create_tflm_tree.py \
    --makefile_options='TARGET=riscv32_generic TARGET_ARCH=project_generation' \
    ../Library/Generic/RISCV64_generic

cd "${PATH_PRG}"

# Build and install Library/<CORE>/libTFLite.a for every core

printf '\n%bBuilding all the Tflite-micro libraries (USE_LLVM=%s) ...%b\n' "${BOLD}" "${use_llvm}" "${NC}"

rm -fr build
cmake -S . -B build -G Ninja -DUSE_LLVM="${use_llvm}"
cmake --build build
cmake --install build

printf '\n🎉 %bBuild Complete%b\n\n' "${GREEN}" "${NC}"
