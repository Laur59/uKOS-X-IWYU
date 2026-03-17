/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32H743_crc.
; ==============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32H743_crc equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// CRC address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    DR;
    volatile    uint32_t    IDR;
    volatile    uint32_t    CR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    INIT;
    volatile    uint32_t    POL;
} CRC_TypeDef;

#ifdef __cplusplus
#define CRC reinterpret_cast<CRC_TypeDef *>(0x58024C00U)

#else
#define CRC ((CRC_TypeDef *)0x58024C00U)
#endif

// DR Configuration

#define CRC_DR_DR           (0xFFFFFFFFU<<0)
#define CRC_DR_DR_0         (0x1U<<0)

// IDR Configuration

#define CRC_IDR_IDR         (0xFFFFFFFFU<<0)
#define CRC_IDR_IDR_0       (0x1U<<0)

// CR Configuration

#define CRC_CR_REV_OUT      (0x1U<<7)
#define CRC_CR_REV_IN       (0x3U<<5)
#define CRC_CR_REV_IN_0     (0x1U<<5)
#define CRC_CR_POLYSIZE     (0x3U<<3)
#define CRC_CR_POLYSIZE_0   (0x1U<<3)
#define CRC_CR_RESET        (0x1U<<0)

// INIT Configuration

#define CRC_INIT_CRC_INIT   (0xFFFFFFFFU<<0)
#define CRC_INIT_CRC_INIT_0 (0x1U<<0)

// POL Configuration

#define CRC_POL_POL         (0xFFFFFFFFU<<0)
#define CRC_POL_POL_0       (0x1U<<0)
