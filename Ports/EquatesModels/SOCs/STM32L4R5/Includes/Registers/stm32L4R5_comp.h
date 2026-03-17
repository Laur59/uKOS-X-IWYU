/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32L4R5_comp.
; ===============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32L4R5_comp equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// COMP address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    COMP1_CSR;
    volatile    uint32_t    COMP2_CSR;
} COMP_TypeDef;

#ifdef __cplusplus
#define COMP    reinterpret_cast<COMP_TypeDef *>(0x40010200U)

#else
#define COMP    ((COMP_TypeDef *)0x40010200U)
#endif

// COMP1_CSR Configuration

#define COMP_COMP1_CSR_COMP1_LOCK       (0x1U<<31)
#define COMP_COMP1_CSR_COMP1_VALUE      (0x1U<<30)
#define COMP_COMP1_CSR_COMP1_SCALEN     (0x1U<<23)
#define COMP_COMP1_CSR_COMP1_BRGEN      (0x1U<<22)
#define COMP_COMP1_CSR_COMP1_BLANKING   (0x7U<<18)
#define COMP_COMP1_CSR_COMP1_BLANKING_0 (0x1U<<18)
#define COMP_COMP1_CSR_COMP1_HYST       (0x3U<<16)
#define COMP_COMP1_CSR_COMP1_HYST_0     (0x1U<<16)
#define COMP_COMP1_CSR_COMP1_POLARITY   (0x1U<<15)
#define COMP_COMP1_CSR_COMP1_INPSEL     (0x1U<<7)
#define COMP_COMP1_CSR_COMP1_INMSEL     (0x7U<<4)
#define COMP_COMP1_CSR_COMP1_INMSEL_0   (0x1U<<4)
#define COMP_COMP1_CSR_COMP1_PWRMODE    (0x3U<<2)
#define COMP_COMP1_CSR_COMP1_PWRMODE_0  (0x1U<<2)
#define COMP_COMP1_CSR_COMP1_EN         (0x1U<<0)

// COMP2_CSR Configuration

#define COMP_COMP2_CSR_COMP2_LOCK       (0x1U<<31)
#define COMP_COMP2_CSR_COMP2_VALUE      (0x1U<<30)
#define COMP_COMP2_CSR_COMP2_SCALEN     (0x1U<<23)
#define COMP_COMP2_CSR_COMP2_BRGEN      (0x1U<<22)
#define COMP_COMP2_CSR_COMP2_BLANKING   (0x7U<<18)
#define COMP_COMP2_CSR_COMP2_BLANKING_0 (0x1U<<18)
#define COMP_COMP2_CSR_COMP2_HYST       (0x3U<<16)
#define COMP_COMP2_CSR_COMP2_HYST_0     (0x1U<<16)
#define COMP_COMP2_CSR_COMP2_POLARITY   (0x1U<<15)
#define COMP_COMP2_CSR_COMP2_WINMODE    (0x1U<<9)
#define COMP_COMP2_CSR_COMP2_INPSEL     (0x1U<<7)
#define COMP_COMP2_CSR_COMP2_INMSEL     (0x7U<<4)
#define COMP_COMP2_CSR_COMP2_INMSEL_0   (0x1U<<4)
#define COMP_COMP2_CSR_COMP2_PWRMODE    (0x3U<<2)
#define COMP_COMP2_CSR_COMP2_PWRMODE_0  (0x1U<<2)
#define COMP_COMP2_CSR_COMP2_EN         (0x1U<<0)
