# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:		makefile for the "uKOS_minimal" application.
#

PROJECT			=  uKOS_minimal

# Target & Infrastructure

PREFIX			?=  arm-none-eabi-
COMPILER_FAMILY	?=  gcc

BOARD			=  Discovery_N657
VARIANT			=  Variant_Test
SOC				=  STM32N657
CORE			=  CORTEX_M55
OPTIMISATION	=  -Os

OBJ				+= $(PATH_MYPR)/process_actuator.o
OBJ				+= $(PATH_MYPR)/process_dispatcher.o
OBJ				+= $(PATH_MYPR)/process_sensor.o

include ../../../../Mkfiles/common.mk
