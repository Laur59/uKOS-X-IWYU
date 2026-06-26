# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:		makefile for the "cortexFPU" application.
#

PROJECT			=  cortexFPU

# Target & Infrastructure

PREFIX			?=  arm-none-eabi-
COMPILER_FAMILY	?=  gcc

BOARD			=  Discovery_N657
VARIANT			=  Variant_Test
SOC				=  STM32N657
CORE			=  CORTEX_M55
OPTIMISATION	=  -Os

APPL_SRC		+= $(PATH_MYPR)/_math_algos

include ../../../../Mkfiles/common.mk
