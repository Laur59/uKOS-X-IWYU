#!/usr/bin/env zsh

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# Goal:     Check header file self-containment using preprocessor
#
#           Usage:
#               ./check-self-contained.sh
#
#------------------------------------------------------------------------

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL EXTENDED_GLOB

# Determine script directory
readonly PATH_PRG="${0:A:h}"
readonly workspace="${0:A:h:h:h:h}"
readonly iwyu_cfg_rootdir="${workspace}/compile_flags"

# Colours for messages
readonly RED='\033[0;31m'
readonly GREEN='\033[0;32m'
readonly YELLOW='\033[0;33m'
readonly BLUE='\033[0;34m'
readonly BOLD='\033[1m'
readonly FAINT='\033[2m'
readonly ITALIC='\033[3m'
readonly NC='\033[0m' # No Color

# Source configurations
source "${iwyu_cfg_rootdir}/Alastor_H743/iwyu.cfg"
source "${iwyu_cfg_rootdir}/Asmodee_CM4/iwyu.cfg"
source "${iwyu_cfg_rootdir}/Asmodee_CM7/iwyu.cfg"
source "${iwyu_cfg_rootdir}/nRF5340_App/iwyu.cfg"
source "${iwyu_cfg_rootdir}/nRF5340_Net/iwyu.cfg"
source "${iwyu_cfg_rootdir}/Discovery_U5G9/iwyu.cfg"
source "${iwyu_cfg_rootdir}/Longan/iwyu.cfg"
source "${iwyu_cfg_rootdir}/MAiXDUiNO/iwyu.cfg"
source "${iwyu_cfg_rootdir}/Nucleo_F207/iwyu.cfg"
source "${iwyu_cfg_rootdir}/Nucleo_H743/iwyu.cfg"
source "${iwyu_cfg_rootdir}/Nucleo_L4R5/iwyu.cfg"
source "${iwyu_cfg_rootdir}/Nucleo_N657/iwyu.cfg"
source "${iwyu_cfg_rootdir}/Pico2_rp2350/iwyu.cfg"

# Function to check header self-containment
check_header() {
    local target_name=$1
    local toolchain=$2
    shift 2
    local flags_array_name=$1
    shift
    local header_file=$1

    printf '%b%-30s%b' "${GREEN}" "${target_name}" "${NC}"

    if ${toolchain} -E "${(@P)flags_array_name}" "${workspace}/${header_file}" > /dev/null 2>&1; then
        printf ' %b✓ PASS%b\n' "${GREEN}" "${NC}"
        return 0
    else
        printf ' %b✗ FAIL%b\n' "${RED}" "${NC}"
        return 1
    fi
}

file_under_test="OS/Lib_neurals/mlpn/mlpn.h"
printf '%b
╔════════════════════════════════════════════════════════════╗
║   Self-Containment: mlpn.h                                 ║
╚════════════════════════════════════════════════════════════╝
%b' "${BLUE}" "${NC}"
printf 'File path: %s\n\n' "${file_under_test}"

check_header "Alastor_H743" "$PATH_LLVM_ARM/bin/clang" AlastorFLAG "${file_under_test}"
check_header "Asmodee_H747 (CM7)" "$PATH_LLVM_ARM/bin/clang" Asmode_CM7FLAGS_A "${file_under_test}"
check_header "DevKit_nRF5340 (App)" "$PATH_LLVM_ARM/bin/clang" nRF_AppFLAGS_A "${file_under_test}"
check_header "Discovery_U5G9" "$PATH_LLVM_ARM/bin/clang" Discovery_U5G9FLAGS_A "${file_under_test}"
check_header "MAiXDUiNO_K210" "$PATH_LLVM_RVXX/bin/clang" MaixduinoFLAGS "${file_under_test}"
check_header "Nucleo_H743" "$PATH_LLVM_ARM/bin/clang" Nucleo_H743FLAGS_A "${file_under_test}"
check_header "Nucleo_L4R5" "$PATH_LLVM_ARM/bin/clang" Nucleo_L4R5FLAGS_A "${file_under_test}"
check_header "Nucleo_N657" "$PATH_LLVM_ARM/bin/clang" Nucleo_N657FLAGS_A "${file_under_test}"
check_header "Pico2_rp2350" "$PATH_LLVM_ARM/bin/clang" Pico2FLAGS_A "${file_under_test}"

