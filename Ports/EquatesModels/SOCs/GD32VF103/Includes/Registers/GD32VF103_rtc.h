/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; GD32VF103_rtc.
; ==============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     GD32VF103_rtc equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// RTC address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    INTEN;
    volatile    uint32_t    CTL;
    volatile    uint32_t    PSCH;
    volatile    uint32_t    PSCL;
    volatile    uint32_t    DIVH;
    volatile    uint32_t    DIVL;
    volatile    uint32_t    CNTH;
    volatile    uint32_t    CNTL;
    volatile    uint32_t    ALRMH;
    volatile    uint32_t    ALRML;
} RTC_TypeDef;

#ifdef __cplusplus
#define RTC reinterpret_cast<RTC_TypeDef *>(0x40002800U)

#else
#define RTC ((RTC_TypeDef *)0x40002800U)
#endif

// INTEN Configuration

#define RTC_INTEN_SCIE      (0x1U<<0)
#define RTC_INTEN_ALRMIE    (0x1U<<1)
#define RTC_INTEN_OVIE      (0x1U<<2)

// CTL Configuration

#define RTC_CTL_SCIF        (0x1U<<0)
#define RTC_CTL_ALRMIF      (0x1U<<1)
#define RTC_CTL_OVIF        (0x1U<<2)
#define RTC_CTL_RSYNF       (0x1U<<3)
#define RTC_CTL_CMF         (0x1U<<4)
#define RTC_CTL_LWOFF       (0x1U<<5)

// PSCH Configuration

#define RTC_PSCH_PSC        (0xFU<<0)
#define RTC_PSCH_PSC_0      (0x1U<<0)

// PSCL Configuration

#define RTC_PSCL_PSC        (0xFFFFU<<0)
#define RTC_PSCL_PSC_0      (0x1U<<0)

// DIVH Configuration

#define RTC_DIVH_DIV        (0xFU<<0)
#define RTC_DIVH_DIV_0      (0x1U<<0)

// DIVL Configuration

#define RTC_DIVL_DIV        (0xFFFFU<<0)
#define RTC_DIVL_DIV_0      (0x1U<<0)

// CNTH Configuration

#define RTC_CNTH_CNT        (0xFFFFU<<0)
#define RTC_CNTH_CNT_0      (0x1U<<0)

// CNTL Configuration

#define RTC_CNTL_CNT        (0xFFFFU<<0)
#define RTC_CNTL_CNT_0      (0x1U<<0)

// ALRMH Configuration

#define RTC_ALRMH_ALRM      (0xFFFFU<<0)
#define RTC_ALRMH_ALRM_0    (0x1U<<0)

// ALRML Configuration

#define RTC_ALRML_ALRM      (0xFFFFU<<0)
#define RTC_ALRML_ALRM_0    (0x1U<<0)
