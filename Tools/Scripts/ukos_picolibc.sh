#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen

# ukos_picolibc.
# ==============

#------------------------------------------------------------------------
# Purpose:
#   Toolchain for generating generic the picolibc libraries for Arm & RISC-V
#
# Usage:
#   ./ukos_picolibc.sh arm
#   ./ukos_picolibc.sh riscv
#
# OS:
#   macOS 26.xx         yes
#   Ubuntu 24.04 LTS    yes
#------------------------------------------------------------------------

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL

if [ -z "${PATH_TOOLS_ROOT}" ]; then
    echo "Variable PATH_TOOLS_ROOT is not set!"
    exit 1
fi

if [ -z "${PICOLIBC_VER}" ]; then
    echo "Variable PICOLIBC_VER is not set!"
    exit 1
fi

if [ "$#" -eq "0"  ]; then
    echo "Must give a parameter: arm | riscv"
    exit 1
fi

# Choice of the native compiler
# -----------------------------

# For OSX, the native compiler is LLVM
# For Ubuntu, the native compiler is gcc

case "$(uname)" in
    "Darwin")
        echo "Target OSX clang"
        export CC=clang
        export CXX=clang++
        ;;
    "Linux")
        echo "Target Linux"
        ;;
esac

# Choice of the compiler/machine
# ------------------------------

case "${1}" in
    "arm")
        PATH=${PATH}:${PATH_GCC_ARM}/bin
        export PATH
        echo "Machine arm"
        export MACHINE=arm
        export SCRIPT=do-arm-configure
        export APP_STRIP=${PATH_TOOLS_ROOT}/cross/gcc-${GCC_ARM_VER}/${MACHINE}/bin/arm-none-eabi-strip
        ;;
    "riscv")
        PATH=${PATH}:${PATH_GCC_RVXX}/bin
        export PATH
        echo "Machine riscv 32 & 64"
        export MACHINE=riscv
        export SCRIPT=do-riscv-configure
        APP_STRIP=${PATH_TOOLS_ROOT}/cross/gcc-${GCC_RVXX_VER}/${MACHINE}/bin/riscv64-unknown-elf-strip
        ;;
esac

# Environment
# -----------

export PACKS=${PATH_TOOLS_ROOT}/Packages/picolibc-${PICOLIBC_VER}
export BUILD=${PATH_TOOLS_ROOT}/builds/picolibc-${PICOLIBC_VER}
export CROSS=${PATH_TOOLS_ROOT}/cross/picolibc-${PICOLIBC_VER}

# Building the library
# --------------------

rm -rf ${BUILD}/${MACHINE}
rm -rf ${CROSS}/${MACHINE}
mkdir -p ${BUILD}/${MACHINE}

echo "Start of build: $(date)" > ${BUILD}/${MACHINE}/picolibc_temp.txt

cd ${BUILD}/${MACHINE}
${PACKS}/scripts/${SCRIPT} -Dprefix=${CROSS}/${MACHINE}/    \
                        -Dtests=false                   \
                        -Dmultilib=true                 \
                        -Dio-c99-formats=true           \
                        -Dio-long-long=true             \
                        -Dpicolib=true                  \
                        -Dposix-console=true            \
                        -Dpicocrt=false                 \
                        -Dpicocrt-lib=false

ninja
ninja install

cd ${CROSS}/${MACHINE}/picolibc
find . -name "lib*.a" -exec ${APP_STRIP} --strip-unneeded {} \;

# Update path links

if [ ! -d "${PATH_TOOLS_ROOT}/cross/picolibc-current" ]; then
mkdir ${PATH_TOOLS_ROOT}/cross/picolibc-current
fi
cd ${PATH_TOOLS_ROOT}/cross/picolibc-current
rm -f ${MACHINE}
ln -s ../picolibc-${PICOLIBC_VER}/${MACHINE} ${MACHINE}

echo "End of build:   $(date)" >> ${BUILD}/${MACHINE}/picolibc_temp.txt
mv ${BUILD}/${MACHINE}/picolibc_temp.txt ${BUILD}/${MACHINE}/picolibc_ready.txt
