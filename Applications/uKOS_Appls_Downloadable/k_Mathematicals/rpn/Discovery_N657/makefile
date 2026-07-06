# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:		makefile for the "rpn" application.
#

PROJECT			=  rpn

PATH_DECNUMBER	=  $(PATH_UKOS)/Third_Parties/decnumber
MYLIB			=  $(PATH_DECNUMBER)/Library/$(CORE)/libdecnumber.a

# Paths overloaded

# - PATH_BASE	PATH_BASE ?= $(PATH_UKOS)/Ports/Targets/$(BOARD)/Base

PATH_BASE		=  $(PATH_UKOS)/Ports/Targets/$(BOARD)/Base_CM7

# Target & Infrastructure

PREFIX			?=  arm-none-eabi-
COMPILER_FAMILY	?=  gcc

BOARD			=  Discovery_N657
VARIANT			=  Variant_Test_CM7
SOC				=  STM32N657
CORE			=  Nucleo_N657
OPTIMISATION	=  -Os

CFLAGS			+= -I$(PATH_DECNUMBER)/decnumber-current/include
CFLAGS			+= -I$(PATH_DECNUMBER)/decnumber-current/include/libdecnumber

include ../../../../Mkfiles/common.mk
