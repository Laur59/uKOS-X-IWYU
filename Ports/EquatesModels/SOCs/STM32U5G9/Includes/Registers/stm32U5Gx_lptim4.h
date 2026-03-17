/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32U5Gx_lptim4.
; =================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32U5Gx_lptim4 equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// LPTIM4 address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    ISR;
    volatile    uint32_t    ICR;
    volatile    uint32_t    DIER;
    volatile    uint32_t    CFGR;
    volatile    uint32_t    CR;
    volatile    uint32_t    CCR1;
    volatile    uint32_t    ARR;
    volatile    uint32_t    CNT;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    CFGR2;
    volatile    uint32_t    RCR;
    volatile    uint32_t    CCMR1;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    CCR2;
} LPTIM4_TypeDef;

#ifdef __cplusplus
#define LPTIM4_NS   reinterpret_cast<LPTIM4_TypeDef *>(0x46004C00U)
#define LPTIM4_S    reinterpret_cast<LPTIM4_TypeDef *>(0x56004C00U)

#else
#define LPTIM4_NS   ((LPTIM4_TypeDef *)0x46004C00U)
#define LPTIM4_S    ((LPTIM4_TypeDef *)0x56004C00U)
#endif

// ISR Configuration

#define LPTIM4_ISR_CC1IF        (0x1U<<0)
#define LPTIM4_ISR_ARRM         (0x1U<<1)
#define LPTIM4_ISR_EXTTRIG      (0x1U<<2)
#define LPTIM4_ISR_CMP1OK       (0x1U<<3)
#define LPTIM4_ISR_ARROK        (0x1U<<4)
#define LPTIM4_ISR_UP           (0x1U<<5)
#define LPTIM4_ISR_DOWN         (0x1U<<6)
#define LPTIM4_ISR_UE           (0x1U<<7)
#define LPTIM4_ISR_REPOK        (0x1U<<8)
#define LPTIM4_ISR_DIEROK       (0x1U<<24)

// ICR Configuration

#define LPTIM4_ICR_CC1IF        (0x1U<<0)
#define LPTIM4_ICR_ARRMCF       (0x1U<<1)
#define LPTIM4_ICR_EXTTRIGCF    (0x1U<<2)
#define LPTIM4_ICR_CMP1OKCF     (0x1U<<3)
#define LPTIM4_ICR_ARROKCF      (0x1U<<4)
#define LPTIM4_ICR_UPCF         (0x1U<<5)
#define LPTIM4_ICR_DOWNCF       (0x1U<<6)
#define LPTIM4_ICR_UECF         (0x1U<<7)
#define LPTIM4_ICR_REPOKCF      (0x1U<<8)
#define LPTIM4_ICR_DIEROKCF     (0x1U<<24)

// DIER Configuration

#define LPTIM4_DIER_CC1IF       (0x1U<<0)
#define LPTIM4_DIER_ARRMIE      (0x1U<<1)
#define LPTIM4_DIER_EXTTRIGIE   (0x1U<<2)
#define LPTIM4_DIER_CMP1OKIE    (0x1U<<3)
#define LPTIM4_DIER_ARROKIE     (0x1U<<4)
#define LPTIM4_DIER_UPIE        (0x1U<<5)
#define LPTIM4_DIER_DOWNIE      (0x1U<<6)
#define LPTIM4_DIER_UEIE        (0x1U<<7)
#define LPTIM4_DIER_REPOKIE     (0x1U<<8)

// CFGR Configuration

#define LPTIM4_CFGR_CKSEL       (0x1U<<0)
#define LPTIM4_CFGR_CKPOL       (0x3U<<1)
#define LPTIM4_CFGR_CKPOL_0     (0x1U<<1)
#define LPTIM4_CFGR_CKFLT       (0x3U<<3)
#define LPTIM4_CFGR_CKFLT_0     (0x1U<<3)
#define LPTIM4_CFGR_TRGFLT      (0x3U<<6)
#define LPTIM4_CFGR_TRGFLT_0    (0x1U<<6)
#define LPTIM4_CFGR_PRESC       (0x7U<<9)
#define LPTIM4_CFGR_PRESC_0     (0x1U<<9)
#define LPTIM4_CFGR_TRIGSEL     (0x7U<<13)
#define LPTIM4_CFGR_TRIGSEL_0   (0x1U<<13)
#define LPTIM4_CFGR_TRIGEN      (0x3U<<17)
#define LPTIM4_CFGR_TRIGEN_0    (0x1U<<17)
#define LPTIM4_CFGR_TIMOUT      (0x1U<<19)
#define LPTIM4_CFGR_WAVE        (0x1U<<20)
#define LPTIM4_CFGR_WAVPOL      (0x1U<<21)
#define LPTIM4_CFGR_PRELOAD     (0x1U<<22)
#define LPTIM4_CFGR_COUNTMODE   (0x1U<<23)
#define LPTIM4_CFGR_ENC         (0x1U<<24)

// CR Configuration

#define LPTIM4_CR_ENABLE        (0x1U<<0)
#define LPTIM4_CR_SNGSTRT       (0x1U<<1)
#define LPTIM4_CR_CNTSTRT       (0x1U<<2)
#define LPTIM4_CR_COUNTRST      (0x1U<<3)
#define LPTIM4_CR_RSTARE        (0x1U<<4)

// CCR1 Configuration

#define LPTIM4_CCR1_CCR1        (0xFFFFU<<0)
#define LPTIM4_CCR1_CCR1_0      (0x1U<<0)

// ARR Configuration

#define LPTIM4_ARR_ARR          (0xFFFFU<<0)
#define LPTIM4_ARR_ARR_0        (0x1U<<0)

// CNT Configuration

#define LPTIM4_CNT_CNT          (0xFFFFU<<0)
#define LPTIM4_CNT_CNT_0        (0x1U<<0)

// CFGR2 Configuration

#define LPTIM4_CFGR2_IN1SEL     (0x3U<<0)
#define LPTIM4_CFGR2_IN1SEL_0   (0x1U<<0)
#define LPTIM4_CFGR2_IN2SEL     (0x3U<<4)
#define LPTIM4_CFGR2_IN2SEL_0   (0x1U<<4)
#define LPTIM4_CFGR2_IC1SEL     (0x3U<<16)
#define LPTIM4_CFGR2_IC1SEL_0   (0x1U<<16)
#define LPTIM4_CFGR2_IC2SEL     (0x3U<<20)
#define LPTIM4_CFGR2_IC2SEL_0   (0x1U<<20)

// RCR Configuration

#define LPTIM4_RCR_REP          (0xFFU<<0)
#define LPTIM4_RCR_REP_0        (0x1U<<0)

// CCMR1 Configuration

#define LPTIM4_CCMR1_IC2F       (0x3U<<28)
#define LPTIM4_CCMR1_IC2F_0     (0x1U<<28)
#define LPTIM4_CCMR1_IC2PSC     (0x3U<<24)
#define LPTIM4_CCMR1_IC2PSC_0   (0x1U<<24)
#define LPTIM4_CCMR1_CC2P       (0x3U<<18)
#define LPTIM4_CCMR1_CC2P_0     (0x1U<<18)
#define LPTIM4_CCMR1_CC2E       (0x1U<<17)
#define LPTIM4_CCMR1_CC2SEL     (0x1U<<16)
#define LPTIM4_CCMR1_IC1F       (0x3U<<12)
#define LPTIM4_CCMR1_IC1F_0     (0x1U<<12)
#define LPTIM4_CCMR1_IC1PSC     (0x3U<<8)
#define LPTIM4_CCMR1_IC1PSC_0   (0x1U<<8)
#define LPTIM4_CCMR1_CC1P       (0x3U<<2)
#define LPTIM4_CCMR1_CC1P_0     (0x1U<<2)
#define LPTIM4_CCMR1_CC1E       (0x1U<<1)
#define LPTIM4_CCMR1_CC1SEL     (0x1U<<0)

// CCR2 Configuration

#define LPTIM4_CCR2_CCR2        (0xFFFFU<<0)
#define LPTIM4_CCR2_CCR2_0      (0x1U<<0)
