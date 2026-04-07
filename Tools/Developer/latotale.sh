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
do_U=1
do_Y=1

OPTSTRING=":CGLMNPUYh"
while getopts ${OPTSTRING} option; do
    case ${option} in
        h)
            echo "USAGE: ./latotale.sh [-L] [-G] [-N] [-P] [-U] [-Y]"
            echo
            echo "OPTIONS:"
            echo "    -G: exclude gcc"
            echo "    -L: exclude clang"
            echo "    -P: exclude picolibc"
            echo "    -U: exclude user mode"
            echo "    -Y: exclude canary"
            exit 0
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
cd "${PROJECT_DIRECTORY}"/Ports/Targets
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
    [[ $do_gcc ]] && ./_build_cmake.sh
    [[ $do_clang ]] && ./_build_cmake.sh -L

    if [[ $do_Y ]]; then
        [[ $do_gcc ]] && ./_build_cmake.sh -Y
        [[ $do_clang ]] && ./_build_cmake.sh -LY
    fi

    if [[ $do_U ]]; then
        [[ $do_gcc ]] && ./_build_cmake.sh -U
        [[ $do_clang ]] && ./_build_cmake.sh -LU

        if [[ $do_Y ]]; then
            [[ $do_gcc ]] && ./_build_cmake.sh -UY
            [[ $do_clang ]] && ./_build_cmake.sh -LUY
        fi
    fi
fi
#
if [[ $do_picolibc ]]; then
    [[ $do_gcc ]] && ./_build_cmake.sh -P
    [[ $do_clang ]] && ./_build_cmake.sh -PL

    if [[ $do_Y ]]; then
        [[ $do_gcc ]] && ./_build_cmake.sh -PY
        [[ $do_clang ]] && ./_build_cmake.sh -PLY
    fi

    if [[ $do_U ]]; then
        [[ $do_gcc ]] && ./_build_cmake.sh -PU
        [[ $do_clang ]] && ./_build_cmake.sh -PLU

        if [[ $do_Y ]]; then
            [[ $do_gcc ]] && ./_build_cmake.sh -PUY
            [[ $do_clang ]] && ./_build_cmake.sh -PLUY
        fi
    fi
fi

./clean.sh > /dev/null 2>&1
tac=$(date +%s)
print "$(date -r $tac)"
elapsed=$(( tac - tic ))
printf 'Elapsed: %d min %d sec\n' $(( elapsed / 60 )) $(( elapsed % 60 ))
exit 0
