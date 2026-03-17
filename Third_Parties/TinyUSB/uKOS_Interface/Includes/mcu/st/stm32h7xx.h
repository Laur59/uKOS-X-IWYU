/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32h7xx.
; ==========

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Import the uKOS definition (specially mcu) to provide
;           the file stm32h7xx.h.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

#define __NOP()     __asm volatile ("nop")

#include    "core_reg.h"
#include    "soc_reg.h"
