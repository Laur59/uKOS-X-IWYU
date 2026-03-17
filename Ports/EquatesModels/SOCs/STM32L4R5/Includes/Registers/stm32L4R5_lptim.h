/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32L4R5_lptim.
; ================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32L4R5_lptim equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// LPTIM address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    ISR;
    volatile    uint32_t    ICR;
    volatile    uint32_t    IER;
    volatile    uint32_t    CFGR;
    volatile    uint32_t    CR;
    volatile    uint32_t    CMP;
    volatile    uint32_t    ARR;
    volatile    uint32_t    CNT;
} LPTIM_TypeDef;

#ifdef __cplusplus
#define LPTIM1  reinterpret_cast<LPTIM_TypeDef *>(0x40007C00U)
#define LPTIM2  reinterpret_cast<LPTIM_TypeDef *>(0x40009400U)

#else
#define LPTIM1  ((LPTIM_TypeDef *)0x40007C00U)
#define LPTIM2  ((LPTIM_TypeDef *)0x40009400U)
#endif

// ISR Configuration

#define LPTIM_ISR_CMPM          (0x1U<<0)
#define LPTIM_ISR_ARRM          (0x1U<<1)
#define LPTIM_ISR_EXTTRIG       (0x1U<<2)
#define LPTIM_ISR_CMPOK         (0x1U<<3)
#define LPTIM_ISR_ARROK         (0x1U<<4)
#define LPTIM_ISR_UP            (0x1U<<5)
#define LPTIM_ISR_DOWN          (0x1U<<6)

// ICR Configuration

#define LPTIM_ICR_CMPMCF        (0x1U<<0)
#define LPTIM_ICR_ARRMCF        (0x1U<<1)
#define LPTIM_ICR_EXTTRIGCF     (0x1U<<2)
#define LPTIM_ICR_CMPOKCF       (0x1U<<3)
#define LPTIM_ICR_ARROKCF       (0x1U<<4)
#define LPTIM_ICR_UPCF          (0x1U<<5)
#define LPTIM_ICR_DOWNCF        (0x1U<<6)

// IER Configuration

#define LPTIM_IER_CMPMIE        (0x1U<<0)
#define LPTIM_IER_ARRMIE        (0x1U<<1)
#define LPTIM_IER_EXTTRIGIE     (0x1U<<2)
#define LPTIM_IER_CMPOKIE       (0x1U<<3)
#define LPTIM_IER_ARROKIE       (0x1U<<4)
#define LPTIM_IER_UPIE          (0x1U<<5)
#define LPTIM_IER_DOWNIE        (0x1U<<6)

// CFGR Configuration

#define LPTIM_CFGR_CKSEL        (0x1U<<0)
#define LPTIM_CFGR_CKPOL        (0x3U<<1)
#define LPTIM_CFGR_CKPOL_0      (0x1U<<1)
#define LPTIM_CFGR_CKFLT        (0x3U<<3)
#define LPTIM_CFGR_CKFLT_0      (0x1U<<3)
#define LPTIM_CFGR_TRGFLT       (0x3U<<6)
#define LPTIM_CFGR_TRGFLT_0     (0x1U<<6)
#define LPTIM_CFGR_PRESC        (0x7U<<9)
#define LPTIM_CFGR_PRESC_0      (0x1U<<9)
#define LPTIM_CFGR_TRIGSEL      (0x7U<<13)
#define LPTIM_CFGR_TRIGSEL_0    (0x1U<<13)
#define LPTIM_CFGR_TRIGEN       (0x3U<<17)
#define LPTIM_CFGR_TRIGEN_0     (0x1U<<17)
#define LPTIM_CFGR_TIMOUT       (0x1U<<19)
#define LPTIM_CFGR_WAVE         (0x1U<<20)
#define LPTIM_CFGR_WAVPOL       (0x1U<<21)
#define LPTIM_CFGR_PRELOAD      (0x1U<<22)
#define LPTIM_CFGR_COUNTMODE    (0x1U<<23)
#define LPTIM_CFGR_ENC          (0x1U<<24)

// CR Configuration

#define LPTIM_CR_ENABLE         (0x1U<<0)
#define LPTIM_CR_SNGSTRT        (0x1U<<1)
#define LPTIM_CR_CNTSTRT        (0x1U<<2)

// CMP Configuration

#define LPTIM_CMP_CMP           (0xFFFFU<<0)
#define LPTIM_CMP_CMP_0         (0x1U<<0)

// ARR Configuration

#define LPTIM_ARR_ARR           (0xFFFFU<<0)
#define LPTIM_ARR_ARR_0         (0x1U<<0)

// CNT Configuration

#define LPTIM_CNT_CNT           (0xFFFFU<<0)
#define LPTIM_CNT_CNT_0         (0x1U<<0)
