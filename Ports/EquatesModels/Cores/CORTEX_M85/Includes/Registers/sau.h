/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; sau.
; ====

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     sau equates.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

// SAU address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CTRL;
    volatile    uint32_t    TYPE;
    volatile    uint32_t    RNR;
    volatile    uint32_t    RBAR;
    volatile    uint32_t    RLAR;
    volatile    uint32_t    SFSR;
    volatile    uint32_t    SFAR;
} SAU_TypeDef;

#if (defined(__cplusplus))
#define SAU_S   reinterpret_cast<SAU_TypeDef *>(0xE000EDD0U)
#define SAU_NS  reinterpret_cast<SAU_TypeDef *>(0xE000EDD0U)

#else
#define SAU_S   ((SAU_TypeDef *)0xE000EDD0U)
#define SAU_NS  ((SAU_TypeDef *)0xE000EDD0U)
#endif

// CTRL Configuration

#define SAU_CTRL_ENABLE     (0x1U<<0)
#define SAU_CTRL_ALLNS      (0x1U<<1)

// TYPE Configuration

#define SAU_TYPE_SREGION    (0xFFU<<0)
#define SAU_TYPE_SREGION_0  (0x1U<<0)

// RNR Configuration

#define SAU_RNR_REGION      (0xFFU<<0)
#define SAU_RNR_REGION_0    (0x1U<<0)

// RBAR Configuration

#define SAU_RBAR_BADDR      (0x7FFFFFFU<<5)
#define SAU_RBAR_BADDR_0    (0x1U<<5)

// RLAR Configuration

#define SAU_RLAR_ENABLE     (0x1U<<0)
#define SAU_RLAR_NSC        (0x1U<<1)
#define SAU_RLAR_LADDR      (0x7FFFFFFU<<5)
#define SAU_RLAR_LADDR_0    (0x1U<<5)

// SFSR Configuration

#define SAU_SFSR_INVEP      (0x1U<<0)
#define SAU_SFSR_INVIS      (0x1U<<1)
#define SAU_SFSR_INVER      (0x1U<<2)
#define SAU_SFSR_AUVIOL     (0x1U<<3)
#define SAU_SFSR_INVTRAN    (0x1U<<4)
#define SAU_SFSR_LSPERR     (0x1U<<5)
#define SAU_SFSR_SFARVALID  (0x1U<<6)
#define SAU_SFSR_LSERR      (0x1U<<7)

// SFAR Configuration

#define SAU_SFAR_ADDRESS    (0xFFFFFFFFU<<0)
#define SAU_SFAR_ADDRESS_0  (0x1U<<0)
