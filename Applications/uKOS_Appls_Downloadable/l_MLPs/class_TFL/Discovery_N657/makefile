# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:		makefile for the "class_TFL" application.
#

PROJECT			=  class_TFL

# Target & Infrastructure

PREFIX			?=  arm-none-eabi-
COMPILER_FAMILY	?=  gcc

BOARD			=  Discovery_N657
VARIANT			=  Variant_Test
SOC				=  STM32N657
CORE			=  CORTEX_M55
OPTIMISATION	=  -Os

CXXFLAGS		+= -DTF_LITE_STATIC_MEMORY=1 -DCORTEX

MYLIB			=    $(PATH_UKOS)/Third_Parties/Tflite-micro/Library/$(CORE)/libTFLite.a
PATH_INCLUDES	+= -I$(PATH_UKOS)/Third_Parties/Tflite-micro/Library/Generic/CORTEX_M_generic
PATH_INCLUDES	+= -I$(PATH_UKOS)/Third_Parties/Tflite-micro/Library/Generic/CORTEX_M_generic/third_party/flatbuffers/include
PATH_INCLUDES	+= -I$(PATH_UKOS)/Third_Parties/Tflite-micro/Library/Generic/CORTEX_M_generic/third_party/gemmlowp

include ../../../../Mkfiles/common.mk
