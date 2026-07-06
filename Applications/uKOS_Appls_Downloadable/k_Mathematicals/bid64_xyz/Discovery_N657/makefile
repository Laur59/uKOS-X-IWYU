# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:		makefile for the "bid64_xyz" application.
#

PROJECT			=  bid64_xyz

PATH_DECNUMBER	=  $(PATH_UKOS)/Third_Parties/decnumber
MYLIB			=  $(PATH_DECNUMBER)/Library/$(CORE)/libdecnumber.a

# Target & Infrastructure

PREFIX			?=  arm-none-eabi-
COMPILER_FAMILY	?=  gcc

BOARD			=  Discovery_N657
VARIANT			=  Variant_Test
SOC				=  STM32N657
CORE			=  CORTEX_M55
OPTIMISATION	=  -Os

CFLAGS			+= -I$(PATH_DECNUMBER)/decnumber-current/include
CFLAGS			+= -I$(PATH_DECNUMBER)/decnumber-current/include/libdecnumber

include ../../../../Mkfiles/common.mk
