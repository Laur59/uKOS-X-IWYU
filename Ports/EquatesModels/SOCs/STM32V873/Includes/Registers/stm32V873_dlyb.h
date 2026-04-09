/*
; stm32V873_dlyb.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32V873_dlyb equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;                                              __ ______  _____
;   Edo. Franzi                         __  __/ //_/ __ \/ ___/
;   5-Route de Cheseaux                / / / / ,< / / / /\__ \
;   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
;                                     \__,_/_/ |_\____//____/
;   edo.franzi@ukos.ch
;
;   Description: Lightweight, real-time multitasking operating
;   system for embedded microcontroller and DSP-based systems.
;
;   Permission is hereby granted, free of charge, to any person
;   obtaining a copy of this software and associated documentation
;   files (the "Software"), to deal in the Software without restriction,
;   including without limitation the rights to use, copy, modify,
;   merge, publish, distribute, sublicense, and/or sell copies of the
;   Software, and to permit persons to whom the Software is furnished
;   to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be
;   included in all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
;   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
;   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
;   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
;   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;   SOFTWARE.
;
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// DLYB address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CFGR;
    volatile    uint32_t    CR;
} DLYB_TypeDef;

#if (defined(__cplusplus))
#define DLYB1_NS    reinterpret_cast<DLYB_TypeDef *>(0x48027400u)
#define DLYB1_S     reinterpret_cast<DLYB_TypeDef *>(0x58027400u)
#define DLYB2_NS    reinterpret_cast<DLYB_TypeDef *>(0x48026C00u)
#define DLYB2_S     reinterpret_cast<DLYB_TypeDef *>(0x58026C00u)

#else
#define DLYB1_NS    ((DLYB_TypeDef *)0x48027400u)
#define DLYB1_S     ((DLYB_TypeDef *)0x58027400u)
#define DLYB2_NS    ((DLYB_TypeDef *)0x48026C00u)
#define DLYB2_S     ((DLYB_TypeDef *)0x58026C00u)
#endif

// CFGR Configuration

#define DLYB_CFGR_SEL       (0x3Fu<<0)
#define DLYB_CFGR_SEL_0     (0x1u<<0)

// CR Configuration

#define DLYB_CR_DEN         (0x1u<<0)

#define DLYB_CR_DEN_B_0X0   (0x0u<<0)
#define DLYB_CR_DEN_B_0X1   (0x1u<<0)
