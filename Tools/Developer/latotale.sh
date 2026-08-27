#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Goal: Build all systems for each configuration and all toolchains
#
# Usage:
#       ./latotale.sh

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL

# Paths ( :A resolves symlinks, so the root is correct when called through Tools/Developer/bin )

readonly PATH_ROOT="${0:A:h:h:h}"

# Colours for messages

readonly RED=$'\033[0;31m'
readonly GREEN=$'\033[0;32m'
readonly YELLOW=$'\033[0;33m'
readonly BOLD=$'\033[1m'
readonly FAINT=$'\033[2m'
readonly ITALIC=$'\033[3m'
readonly NC=$'\033[0m' # No Color

do_clang=1
do_gcc=1
do_newlib=1
do_picolibc=1
do_llvmlibc=1
do_U=1
do_Y=1

OPTSTRING=":GLMNPUYh"
while getopts ${OPTSTRING} option; do
    case ${option} in
        h)
            echo "USAGE: ./latotale.sh [-L] [-G] [-M] [-N] [-P] [-U] [-Y]"
            echo
            echo "OPTIONS:"
            echo "    -G: exclude gcc"
            echo "    -L: exclude clang"
            echo "    -M: exclude llvmlibc"
            echo "    -P: exclude picolibc"
            echo "    -U: exclude user mode"
            echo "    -Y: exclude canary"
            exit 0
            ;;
        M)
            do_llvmlibc=
            ;;
        L)
            if [[ ! $do_gcc ]]; then
                print 'Nothing to be done.'
                exit 0
            fi
            do_clang=
            ;;
        G)
            if [[ ! $do_clang ]]; then
                print 'Nothing to be done.'
                exit 0
            fi
            do_gcc=
            ;;
        N)
            if [[ ! $do_picolibc ]]; then
                print 'Nothing to be done.'
                exit 0
            fi
            do_newlib=
            ;;
        P)
            if [[ ! $do_newlib ]]; then
                print 'Nothing to be done.'
                exit 0
            fi
            do_picolibc=
            ;;
        U)
            do_U=
            ;;
        Y)
            do_Y=
            ;;
        ?)
            echo "Invalid option: -${OPTARG}"
            exit 1
        ;;
    esac
done

tic=$(date +%s)
print "$(date -r $tic)"
cd "${PATH_ROOT}/Ports/Targets"
print "${YELLOW}\ngit branch $(git branch --show-current)${NC}\n"
export NOLISTING=1
#
print 'Version of gcc for Arm'
"$PATH_GCC_ARM"/bin/arm-none-eabi-gcc --version
print 'Version of gcc for RISC-V'
"$PATH_GCC_RVXX"/bin/riscv64-unknown-elf-gcc --version
print 'Version of clang for Arm'
"$PATH_LLVM_ARM"/bin/clang --version
print "\nVersion of clang for RISC-V"
"$PATH_LLVM_RVXX"/bin/clang --version
print
#
if [[ $do_newlib ]]; then
    [[ $do_gcc ]] && ./_build.sh -G
    [[ $do_clang ]] && ./_build.sh

    if [[ $do_Y ]]; then
        [[ $do_gcc ]] && ./_build.sh -GY
        [[ $do_clang ]] && ./_build.sh -Y
    fi

    if [[ $do_U ]]; then
        [[ $do_gcc ]] && ./_build.sh -GU
        [[ $do_clang ]] && ./_build.sh -U

        if [[ $do_Y ]]; then
            [[ $do_gcc ]] && ./_build.sh -GUY
            [[ $do_clang ]] && ./_build.sh -UY
        fi
    fi
fi
#
if [[ $do_picolibc ]]; then
    [[ $do_gcc ]] && ./_build.sh -GP
    [[ $do_clang ]] && ./_build.sh -P

    if [[ $do_Y ]]; then
        [[ $do_gcc ]] && ./_build.sh -GPY
        [[ $do_clang ]] && ./_build.sh -PY
    fi

    if [[ $do_U ]]; then
        [[ $do_gcc ]] && ./_build.sh -GPU
        [[ $do_clang ]] && ./_build.sh -PU

        if [[ $do_Y ]]; then
            [[ $do_gcc ]] && ./_build.sh -GPUY
            [[ $do_clang ]] && ./_build.sh -PUY
        fi
    fi
fi
#
# llvmlibc is Clang/LLVM-only: ARM builds against the Arm Toolchain for Embedded
# (PATH_LLVM_ARML), RISC-V against its own LLVM libc toolchain (PATH_LLVM_RVXXL).
# The pass runs only when PATH_LLVM_ARML is available; without PATH_LLVM_RVXXL
# the RISC-V targets stop on a missing-variable configuration error.
if [[ $do_llvmlibc ]] && [[ $do_clang ]]; then
    if [[ -n "${PATH_LLVM_ARML:-}" ]]; then
        ./_build.sh -L
        [[ $do_Y ]] && ./_build.sh -LY

        if [[ $do_U ]]; then
            ./_build.sh -LU
            [[ $do_Y ]] && ./_build.sh -LUY
        fi
    else
        print "${YELLOW}Skipping llvmlibc: PATH_LLVM_ARML not set${NC}"
    fi
fi

./_clean.sh > /dev/null 2>&1
tac=$(date +%s)
print "$(date -r $tac)"
elapsed=$(( tac - tic ))
printf 'Elapsed: %d min %d sec\n' $(( elapsed / 60 )) $(( elapsed % 60 ))
exit 0
