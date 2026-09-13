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
zmodload zsh/zutil

# Paths ( :A resolves symlinks, so the root is correct when called through Tools/Developer/bin )

readonly PATH_ROOT="${0:A:h:h:h}"

# Colours for messages

readonly RED=$'\033[0;31m'
readonly GREEN=$'\033[0;32m'
readonly YELLOW=$'\033[0;33m'
readonly BLUE=$'\033[0;34m'
readonly BOLD=$'\033[1m'
readonly FAINT=$'\033[2m'
readonly ITALIC=$'\033[3m'
readonly NC=$'\033[0m' # No Color

usage() {
    cat <<'EOF'
Usage: ./latotale.sh [-C] [-G] [-L] [-N] [-P] [-U] [-Y]

Options:
  -G  Exclude gcc
  -C  Exclude clang
  -L  Exclude llvmlibc
  -P  Exclude picolibc
  -U  Exclude user mode
  -Y  Exclude canary
  -N  Exclude newlib
  -h  Show this help message
EOF
}

o_clang=()
o_gcc=()
o_newlib=()
o_picolibc=()
o_llvmlibc=()
o_U=()
o_Y=()
o_help=()

zparseopts -D -F - \
    C=o_clang \
    G=o_gcc \
    N=o_newlib \
    P=o_picolibc \
    L=o_llvmlibc \
    U=o_U \
    Y=o_Y \
    h=o_help || { usage; exit 1; }

# -h short-circuits everything else
if (( $#o_help )); then
    usage
    exit 0
fi

# Apply the parsed options
(( $#o_gcc )) && (( $#o_clang )) && { print 'Nothing to be done.'; exit 0; }
(( $#o_newlib )) && (( $#o_picolibc )) && (( $#o_llvmlibc )) && { print 'Nothing to be done.'; exit 0; }

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
sweep_UY() {
    ./_build.sh "$@"
    if (( !$#o_Y )); then
        ./_build.sh "$@" -Y
    fi
    if (( !$#o_U )); then
        ./_build.sh "$@" -U
        if (( !$#o_Y )); then
            ./_build.sh "$@" -UY
        fi
    fi
}
#
if (( !$#o_newlib )); then
    if (( !$#o_gcc )); then sweep_UY -G; fi
    if (( !$#o_clang )); then sweep_UY; fi
fi
#
if (( !$#o_picolibc )); then
    if (( !$#o_gcc )); then sweep_UY -G -P; fi
    if (( !$#o_clang )); then sweep_UY -P; fi
fi
#
# llvmlibc is Clang/LLVM-only: ARM builds against the Arm Toolchain for Embedded
# (PATH_LLVM_ARML), RISC-V against its own LLVM libc toolchain (PATH_LLVM_RVXXL).
if (( !$#o_llvmlibc )); then
    if (( !$#o_clang )); then sweep_UY -L; fi
fi

./_clean.sh > /dev/null 2>&1
tac=$(date +%s)
print "$(date -r $tac)"
elapsed=$(( tac - tic ))
printf 'Elapsed: %d min %d sec\n' $(( elapsed / 60 )) $(( elapsed % 60 ))
exit 0
