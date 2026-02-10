#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# Goal:	Build all systems for each configuration and all toolchains
#
# Usage:
#		./latotale.sh
#------------------------------------------------------------------------

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

exclude_clang=0
exclude_gcc=0

OPTSTRING=":LGph"
while getopts ${OPTSTRING} option; do
	case ${option} in
		h)
			echo "USAGE: ./latotale.sh [-L] [-G] [-p]"
			echo
			echo "OPTIONS:"
			echo "    -G: exclude gcc"
			echo "    -L: exclude clang"
			echo "    -p: build with picolibc"
			exit 0
			;;
		L)
			exclude_clang=1
			;;
		G)
			exclude_gcc=1
			;;
		p)
			picolibc_flag="-P"
			;;
		?)
			echo "Invalid option: -${OPTARG}"
			exit 1
		;;
	esac
done

if [[ "${exclude_clang}" = 1 ]] && [[ "${exclude_gcc}" = 1 ]]; then
	print "Nothing to be done."
	exit 0
fi

date
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
run_pass()
{
	local canary=$1
	local usermode=$2
	if [ "${exclude_gcc}" != 1 ]; then
		# cmake and gcc
		./_build.sh -G $canary $usermode
		print
	fi
	if [[ "${exclude_clang}" != 1 ]]; then
		# cmake and clang
		./_build.sh $canary $usermode
		print
	fi
}

# Build with USER mode and canary
run_pass "" ""
# Build without canary
run_pass -Y ""
# Build without USER mode
run_pass "" -U
# Build without USER mode and without canary
run_pass -Y -U
./clean.sh > /dev/null
date
