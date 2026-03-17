/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; RP2350_tbman.
; =============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     RP2350_tbman equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// TBMAN address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    PLATFORM;
} TBMAN_TypeDef;

#ifdef __cplusplus
#define TBMAN_NS    reinterpret_cast<TBMAN_TypeDef *>(0x40160000U)
#define TBMAN_S     reinterpret_cast<TBMAN_TypeDef *>(0x40160000U)
#else
#define TBMAN_NS    ((TBMAN_TypeDef *)0x40160000U)
#define TBMAN_S     ((TBMAN_TypeDef *)0x40160000U)
#endif

// PLATFORM Configuration

#define TBMAN_PLATFORM_ASIC     (0x1U<<0)
#define TBMAN_PLATFORM_FPGA     (0x1U<<1)
#define TBMAN_PLATFORM_HDLSIM   (0x1U<<2)
