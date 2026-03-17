/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32U5Gx_comp.
; ===============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32U5Gx_comp equates.
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
#define COMP_NS reinterpret_cast<COMP_TypeDef *>(0x46005400U)
#define COMP_S  reinterpret_cast<COMP_TypeDef *>(0x56005400U)

#else
#define COMP_NS ((COMP_TypeDef *)0x46005400U)
#define COMP_S  ((COMP_TypeDef *)0x56005400U)
#endif

// COMP1_CSR Configuration

#define COMP_COMP1_CSR_COMP1_LOCK       (0x1U<<31)
#define COMP_COMP1_CSR_COMP1_VALUE      (0x1U<<30)
#define COMP_COMP1_CSR_COMP1_BLANKSEL   (0x1FU<<20)
#define COMP_COMP1_CSR_COMP1_BLANKSEL_0 (0x1U<<20)
#define COMP_COMP1_CSR_COMP1_PWRMODE    (0x3U<<18)
#define COMP_COMP1_CSR_COMP1_PWRMODE_0  (0x1U<<18)
#define COMP_COMP1_CSR_COMP1_HYST       (0x3U<<16)
#define COMP_COMP1_CSR_COMP1_HYST_0     (0x1U<<16)
#define COMP_COMP1_CSR_COMP1_POLARITY   (0x1U<<15)
#define COMP_COMP1_CSR_COMP1_WINOUT     (0x1U<<14)
#define COMP_COMP1_CSR_COMP1_WINMODE    (0x1U<<11)
#define COMP_COMP1_CSR_COMP1_INPSEL     (0x3U<<8)
#define COMP_COMP1_CSR_COMP1_INPSEL_0   (0x1U<<8)
#define COMP_COMP1_CSR_COMP1_INMSEL     (0xFU<<4)
#define COMP_COMP1_CSR_COMP1_INMSEL_0   (0x1U<<4)
#define COMP_COMP1_CSR_COMP1_EN         (0x1U<<0)

// COMP2_CSR Configuration

#define COMP_COMP2_CSR_COM2_LOCK        (0x1U<<31)
#define COMP_COMP2_CSR_COM2_VALUE       (0x1U<<30)
#define COMP_COMP2_CSR_COM2_BLANKSEL    (0x1FU<<20)
#define COMP_COMP2_CSR_COM2_BLANKSEL_0  (0x1U<<20)
#define COMP_COMP2_CSR_COM2_PWRMODE     (0x3U<<18)
#define COMP_COMP2_CSR_COM2_PWRMODE_0   (0x1U<<18)
#define COMP_COMP2_CSR_COM2_HYST        (0x3U<<16)
#define COMP_COMP2_CSR_COM2_HYST_0      (0x1U<<16)
#define COMP_COMP2_CSR_COM2_POLARITY    (0x1U<<15)
#define COMP_COMP2_CSR_COM2_WINOUT      (0x1U<<14)
#define COMP_COMP2_CSR_COM2_WINMODE     (0x1U<<11)
#define COMP_COMP2_CSR_COM2_INPSEL      (0x3U<<8)
#define COMP_COMP2_CSR_COM2_INPSEL_0    (0x1U<<8)
#define COMP_COMP2_CSR_COM2_INMSEL      (0xFU<<4)
#define COMP_COMP2_CSR_COM2_INMSEL_0    (0x1U<<4)
#define COMP_COMP2_CSR_COM2_EN          (0x1U<<0)
