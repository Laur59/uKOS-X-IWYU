/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32N657_crc.
; ==============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32N657_crc equates.
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
#define CRC_NS  reinterpret_cast<CRC_TypeDef *>(0x46024C00U)
#define CRC_S   reinterpret_cast<CRC_TypeDef *>(0x56024C00U)

#else
#define CRC_NS  ((CRC_TypeDef *)0x46024C00U)
#define CRC_S   ((CRC_TypeDef *)0x56024C00U)
#endif

// DR Configuration

#define CRC_DR_DR               (0xFFFFFFFFU<<0)
#define CRC_DR_DR_0             (0x1U<<0)

// IDR Configuration

#define CRC_IDR_IDR             (0xFFFFFFFFU<<0)
#define CRC_IDR_IDR_0           (0x1U<<0)

// CR Configuration

#define CRC_CR_RTYPE_OUT        (0x1U<<10)
#define CRC_CR_RTYPE_IN         (0x1U<<9)
#define CRC_CR_REV_OUT          (0x3U<<7)
#define CRC_CR_REV_OUT_0        (0x1U<<7)
#define CRC_CR_REV_IN           (0x3U<<5)
#define CRC_CR_REV_IN_0         (0x1U<<5)
#define CRC_CR_POLYSIZE         (0x3U<<3)
#define CRC_CR_POLYSIZE_0       (0x1U<<3)
#define CRC_CR_RESET            (0x1U<<0)

#define CRC_CR_RTYPE_OUT_B_0X0  (0x0U<<10)
#define CRC_CR_RTYPE_OUT_B_0X1  (0x1U<<10)
#define CRC_CR_RTYPE_IN_B_0X0   (0x0U<<9)
#define CRC_CR_RTYPE_IN_B_0X1   (0x1U<<9)
#define CRC_CR_REV_OUT_B_0X0    (0x0U<<7)
#define CRC_CR_REV_OUT_B_0X1    (0x1U<<7)
#define CRC_CR_REV_OUT_B_0X2    (0x2U<<7)
#define CRC_CR_REV_OUT_B_0X3    (0x3U<<7)
#define CRC_CR_REV_IN_B_0X0     (0x0U<<5)
#define CRC_CR_REV_IN_B_0X1     (0x1U<<5)
#define CRC_CR_REV_IN_B_0X2     (0x2U<<5)
#define CRC_CR_REV_IN_B_0X3     (0x3U<<5)
#define CRC_CR_POLYSIZE_B_0X0   (0x0U<<3)
#define CRC_CR_POLYSIZE_B_0X1   (0x1U<<3)
#define CRC_CR_POLYSIZE_B_0X2   (0x2U<<3)
#define CRC_CR_POLYSIZE_B_0X3   (0x3U<<3)

// INIT Configuration

#define CRC_INIT_CRC_INIT       (0xFFFFFFFFU<<0)
#define CRC_INIT_CRC_INIT_0     (0x1U<<0)

// POL Configuration

#define CRC_POL_POL             (0xFFFFFFFFU<<0)
#define CRC_POL_POL_0           (0x1U<<0)
