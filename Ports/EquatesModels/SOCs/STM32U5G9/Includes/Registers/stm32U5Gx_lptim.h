/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_lptim equates.
 */

#pragma once

#include    <stdint.h>

// LPTIM address definitions
// -------------------------

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
} LPTIM_TypeDef;

#ifdef __cplusplus
#define LPTIM1_NS   reinterpret_cast<LPTIM_TypeDef *>(0x46004400U)
#define LPTIM1_S    reinterpret_cast<LPTIM_TypeDef *>(0x56004400U)
#define LPTIM2_NS   reinterpret_cast<LPTIM_TypeDef *>(0x40009400U)
#define LPTIM2_S    reinterpret_cast<LPTIM_TypeDef *>(0x50009400U)
#define LPTIM3_NS   reinterpret_cast<LPTIM_TypeDef *>(0x46004800U)
#define LPTIM3_S    reinterpret_cast<LPTIM_TypeDef *>(0x56004800U)
#define LPTIM4_NS   reinterpret_cast<LPTIM_TypeDef *>(0x46004C00U)
#define LPTIM4_S    reinterpret_cast<LPTIM_TypeDef *>(0x56004C00U)

#else
#define LPTIM1_NS   ((LPTIM_TypeDef *)0x46004400U)
#define LPTIM1_S    ((LPTIM_TypeDef *)0x56004400U)
#define LPTIM2_NS   ((LPTIM_TypeDef *)0x40009400U)
#define LPTIM2_S    ((LPTIM_TypeDef *)0x50009400U)
#define LPTIM3_NS   ((LPTIM_TypeDef *)0x46004800U)
#define LPTIM3_S    ((LPTIM_TypeDef *)0x56004800U)
#define LPTIM4_NS   ((LPTIM_TypeDef *)0x46004C00U)
#define LPTIM4_S    ((LPTIM_TypeDef *)0x56004C00U)
#endif

// ISR Configuration

#define LPTIM_ISR_CC1IF         (0x1U<<0)
#define LPTIM_ISR_ARRM          (0x1U<<1)
#define LPTIM_ISR_EXTTRIG       (0x1U<<2)
#define LPTIM_ISR_CMP1OK        (0x1U<<3)
#define LPTIM_ISR_ARROK         (0x1U<<4)
#define LPTIM_ISR_UP            (0x1U<<5)
#define LPTIM_ISR_DOWN          (0x1U<<6)
#define LPTIM_ISR_UE            (0x1U<<7)
#define LPTIM_ISR_REPOK         (0x1U<<8)
#define LPTIM_ISR_CC2IF         (0x1U<<9)
#define LPTIM_ISR_CMP2OK        (0x1U<<19)
#define LPTIM_ISR_DIEROK        (0x1U<<24)

// ICR Configuration

#define LPTIM_ICR_CC1IF         (0x1U<<0)
#define LPTIM_ICR_ARRMCF        (0x1U<<1)
#define LPTIM_ICR_EXTTRIGCF     (0x1U<<2)
#define LPTIM_ICR_CMP1OKCF      (0x1U<<3)
#define LPTIM_ICR_ARROKCF       (0x1U<<4)
#define LPTIM_ICR_UPCF          (0x1U<<5)
#define LPTIM_ICR_DOWNCF        (0x1U<<6)
#define LPTIM_ICR_UECF          (0x1U<<7)
#define LPTIM_ICR_REPOKCF       (0x1U<<8)
#define LPTIM_ICR_CC2CF         (0x1U<<9)
#define LPTIM_ICR_CMP2OKCF      (0x1U<<19)
#define LPTIM_ICR_DIEROKCF      (0x1U<<24)

// DIER Configuration

#define LPTIM_DIER_CC1IF        (0x1U<<0)
#define LPTIM_DIER_ARRMIE       (0x1U<<1)
#define LPTIM_DIER_EXTTRIGIE    (0x1U<<2)
#define LPTIM_DIER_CMP1OKIE     (0x1U<<3)
#define LPTIM_DIER_ARROKIE      (0x1U<<4)
#define LPTIM_DIER_UPIE         (0x1U<<5)
#define LPTIM_DIER_DOWNIE       (0x1U<<6)
#define LPTIM_DIER_UEIE         (0x1U<<7)
#define LPTIM_DIER_REPOKIE      (0x1U<<8)
#define LPTIM_DIER_CC2IE        (0x1U<<9)
#define LPTIM_DIER_CMP2OKIE     (0x1U<<19)
#define LPTIM_DIER_UEDE         (0x1U<<23)

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
#define LPTIM_CR_COUNTRST       (0x1U<<3)
#define LPTIM_CR_RSTARE         (0x1U<<4)

// CCR1 Configuration

#define LPTIM_CCR1_CCR1         (0xFFFFU<<0)
#define LPTIM_CCR1_CCR1_0       (0x1U<<0)

// ARR Configuration

#define LPTIM_ARR_ARR           (0xFFFFU<<0)
#define LPTIM_ARR_ARR_0         (0x1U<<0)

// CNT Configuration

#define LPTIM_CNT_CNT           (0xFFFFU<<0)
#define LPTIM_CNT_CNT_0         (0x1U<<0)

// CFGR2 Configuration

#define LPTIM_CFGR2_IN1SEL      (0x3U<<0)
#define LPTIM_CFGR2_IN1SEL_0    (0x1U<<0)
#define LPTIM_CFGR2_IN2SEL      (0x3U<<4)
#define LPTIM_CFGR2_IN2SEL_0    (0x1U<<4)
#define LPTIM_CFGR2_IC1SEL      (0x3U<<16)
#define LPTIM_CFGR2_IC1SEL_0    (0x1U<<16)
#define LPTIM_CFGR2_IC2SEL      (0x3U<<20)
#define LPTIM_CFGR2_IC2SEL_0    (0x1U<<20)

// RCR Configuration

#define LPTIM_RCR_REP           (0xFFU<<0)
#define LPTIM_RCR_REP_0         (0x1U<<0)

// CCMR1 Configuration

#define LPTIM_CCMR1_IC2F        (0x3U<<28)
#define LPTIM_CCMR1_IC2F_0      (0x1U<<28)
#define LPTIM_CCMR1_IC2PSC      (0x3U<<24)
#define LPTIM_CCMR1_IC2PSC_0    (0x1U<<24)
#define LPTIM_CCMR1_CC2P        (0x3U<<18)
#define LPTIM_CCMR1_CC2P_0      (0x1U<<18)
#define LPTIM_CCMR1_CC2E        (0x1U<<17)
#define LPTIM_CCMR1_CC2SEL      (0x1U<<16)
#define LPTIM_CCMR1_IC1F        (0x3U<<12)
#define LPTIM_CCMR1_IC1F_0      (0x1U<<12)
#define LPTIM_CCMR1_IC1PSC      (0x3U<<8)
#define LPTIM_CCMR1_IC1PSC_0    (0x1U<<8)
#define LPTIM_CCMR1_CC1P        (0x3U<<2)
#define LPTIM_CCMR1_CC1P_0      (0x1U<<2)
#define LPTIM_CCMR1_CC1E        (0x1U<<1)
#define LPTIM_CCMR1_CC1SEL      (0x1U<<0)

// CCR2 Configuration

#define LPTIM_CCR2_CCR2         (0xFFFFU<<0)
#define LPTIM_CCR2_CCR2_0       (0x1U<<0)
