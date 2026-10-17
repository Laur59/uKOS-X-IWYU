# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# Resolve the SoC an overlay SoC builds on.
#
# Most SoC directories under Ports/EquatesModels/SOCs are complete. An overlay
# directory holds only what its SoC adds to another one, named SOC_BASE, which
# is found in this order:
#
#   1. SOCs/${SOC}/soc_base.cmake, one line naming the base explicitly, e.g.
#
#        set(SOC_BASE STM32H743)
#
#      No SoC uses one today (the STM32H753 did until STM32H7x3 existed).
#
#   2. The family directory of an STM32H7 pair, if it exists: SoCs that differ
#      only by the crypto accelerators share SOCs/STM32H7x<n>, so the STM32H743
#      and STM32H753 build on STM32H7x3, the STM32H747 and STM32H757 on
#      STM32H7x7. Each is the only directory of its two SoCs: what one part
#      adds is guarded there by its own ${SOC}_S. soc_base() in Tools/Developer/tests/board/ukos_board.py
#      applies the same rule; keep the two in step.
#
#   3. SOC itself, for a complete directory.
#
# The build searches SOCs/${SOC} first and SOCs/${SOC_BASE} second, defines both
# ${SOC}_S and ${SOC_BASE}_S, and looks up per-SoC third-party archives (TinyUSB)
# under SOC, then SOC_BASE. A file present in both directories is taken from the
# overlay.
#
# Requires: SOC, PATH_UKOS.

if(NOT DEFINED SOC)
    message(FATAL_ERROR "soc-base: SOC must be set before include(proj_config)")
endif()

set(SOC_BASE ${SOC})
set(_ukos_socs "${PATH_UKOS}/Ports/EquatesModels/SOCs")
set(_ukos_soc_base_file "${_ukos_socs}/${SOC}/soc_base.cmake")
if(EXISTS "${_ukos_soc_base_file}")
    include("${_ukos_soc_base_file}")
    if(SOC_BASE STREQUAL SOC OR NOT IS_DIRECTORY "${_ukos_socs}/${SOC_BASE}")
        message(FATAL_ERROR "soc-base: ${_ukos_soc_base_file} names no other SoC directory (SOC_BASE=${SOC_BASE})")
    endif()
elseif(SOC MATCHES "^STM32H7[0-9]([0-9])$")
    # Not one condition with the test below: arguments are expanded before
    # MATCHES runs, so CMAKE_MATCH_1 would still be empty there
    if(IS_DIRECTORY "${_ukos_socs}/STM32H7x${CMAKE_MATCH_1}")
        set(SOC_BASE STM32H7x${CMAKE_MATCH_1})
    endif()
endif()
if(NOT IS_DIRECTORY "${_ukos_socs}/${SOC}" AND NOT IS_DIRECTORY "${_ukos_socs}/${SOC_BASE}")
    message(FATAL_ERROR "soc-base: no directory for SoC ${SOC} under ${_ukos_socs}")
endif()
if(NOT SOC_BASE STREQUAL SOC)
    message(STATUS "SoC ${SOC} is an overlay on ${SOC_BASE}")
endif()
unset(_ukos_soc_base_file)
unset(_ukos_socs)
