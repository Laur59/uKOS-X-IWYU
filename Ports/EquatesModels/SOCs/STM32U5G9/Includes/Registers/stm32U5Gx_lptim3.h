/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_lptim3 equates.
 */

#pragma once

#include    <stdint.h>

// LPTIM3 address definitions
// --------------------------

typedef struct {
        union {
    volatile    uint32_t    ISR_OUTPUT;
    volatile    uint32_t    ISR_INPUT;
        };
        union {
    volatile    uint32_t    ICR_OUTPUT;
    volatile    uint32_t    ICR_INPUT;
        };
        union {
    volatile    uint32_t    DIER_OUTPUT;
    volatile    uint32_t    DIER_INPUT;
        };
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
} LPTIM3_TypeDef;

#ifdef __cplusplus
#define LPTIM3_NS   reinterpret_cast<LPTIM3_TypeDef *>(0x46004800U)
#define LPTIM3_S    reinterpret_cast<LPTIM3_TypeDef *>(0x56004800U)

#else
#define LPTIM3_NS   ((LPTIM3_TypeDef *)0x46004800U)
#define LPTIM3_S    ((LPTIM3_TypeDef *)0x56004800U)
#endif

// ISR_OUTPUT Configuration

#define LPTIM3_ISR_OUTPUT_CC1IF         (0x1U<<0)
#define LPTIM3_ISR_OUTPUT_ARRM          (0x1U<<1)
#define LPTIM3_ISR_OUTPUT_EXTTRIG       (0x1U<<2)
#define LPTIM3_ISR_OUTPUT_CMP1OK        (0x1U<<3)
#define LPTIM3_ISR_OUTPUT_ARROK         (0x1U<<4)
#define LPTIM3_ISR_OUTPUT_UP            (0x1U<<5)
#define LPTIM3_ISR_OUTPUT_DOWN          (0x1U<<6)
#define LPTIM3_ISR_OUTPUT_UE            (0x1U<<7)
#define LPTIM3_ISR_OUTPUT_REPOK         (0x1U<<8)
#define LPTIM3_ISR_OUTPUT_CC2IF         (0x1U<<9)
#define LPTIM3_ISR_OUTPUT_CMP2OK        (0x1U<<19)
#define LPTIM3_ISR_OUTPUT_DIEROK        (0x1U<<24)

// ISR_INPUT Configuration

#define LPTIM3_ISR_INPUT_CC1IF          (0x1U<<0)
#define LPTIM3_ISR_INPUT_ARRM           (0x1U<<1)
#define LPTIM3_ISR_INPUT_EXTTRIG        (0x1U<<2)
#define LPTIM3_ISR_INPUT_ARROK          (0x1U<<4)
#define LPTIM3_ISR_INPUT_UP             (0x1U<<5)
#define LPTIM3_ISR_INPUT_DOWN           (0x1U<<6)
#define LPTIM3_ISR_INPUT_UE             (0x1U<<7)
#define LPTIM3_ISR_INPUT_REPOK          (0x1U<<8)
#define LPTIM3_ISR_INPUT_CC2IF          (0x1U<<9)
#define LPTIM3_ISR_INPUT_CC1OF          (0x1U<<12)
#define LPTIM3_ISR_INPUT_CC2OF          (0x1U<<13)
#define LPTIM3_ISR_INPUT_DIEROK         (0x1U<<24)

// ICR_OUTPUT Configuration

#define LPTIM3_ICR_OUTPUT_CC1IF         (0x1U<<0)
#define LPTIM3_ICR_OUTPUT_ARRMCF        (0x1U<<1)
#define LPTIM3_ICR_OUTPUT_EXTTRIGCF     (0x1U<<2)
#define LPTIM3_ICR_OUTPUT_CMP1OKCF      (0x1U<<3)
#define LPTIM3_ICR_OUTPUT_ARROKCF       (0x1U<<4)
#define LPTIM3_ICR_OUTPUT_UPCF          (0x1U<<5)
#define LPTIM3_ICR_OUTPUT_DOWNCF        (0x1U<<6)
#define LPTIM3_ICR_OUTPUT_UECF          (0x1U<<7)
#define LPTIM3_ICR_OUTPUT_REPOKCF       (0x1U<<8)
#define LPTIM3_ICR_OUTPUT_CC2CF         (0x1U<<9)
#define LPTIM3_ICR_OUTPUT_CMP2OKCF      (0x1U<<19)
#define LPTIM3_ICR_OUTPUT_DIEROKCF      (0x1U<<24)

// ICR_INPUT Configuration

#define LPTIM3_ICR_INPUT_CC1IF          (0x1U<<0)
#define LPTIM3_ICR_INPUT_ARRMCF         (0x1U<<1)
#define LPTIM3_ICR_INPUT_EXTTRIGCF      (0x1U<<2)
#define LPTIM3_ICR_INPUT_ARROKCF        (0x1U<<4)
#define LPTIM3_ICR_INPUT_UPCF           (0x1U<<5)
#define LPTIM3_ICR_INPUT_DOWNCF         (0x1U<<6)
#define LPTIM3_ICR_INPUT_UECF           (0x1U<<7)
#define LPTIM3_ICR_INPUT_REPOKCF        (0x1U<<8)
#define LPTIM3_ICR_INPUT_CC2CF          (0x1U<<9)
#define LPTIM3_ICR_INPUT_CC1OCF         (0x1U<<12)
#define LPTIM3_ICR_INPUT_CC2OCF         (0x1U<<13)
#define LPTIM3_ICR_INPUT_DIEROKCF       (0x1U<<24)

// DIER_OUTPUT Configuration

#define LPTIM3_DIER_OUTPUT_CC1IF        (0x1U<<0)
#define LPTIM3_DIER_OUTPUT_ARRMIE       (0x1U<<1)
#define LPTIM3_DIER_OUTPUT_EXTTRIGIE    (0x1U<<2)
#define LPTIM3_DIER_OUTPUT_CMP1OKIE     (0x1U<<3)
#define LPTIM3_DIER_OUTPUT_ARROKIE      (0x1U<<4)
#define LPTIM3_DIER_OUTPUT_UPIE         (0x1U<<5)
#define LPTIM3_DIER_OUTPUT_DOWNIE       (0x1U<<6)
#define LPTIM3_DIER_OUTPUT_UEIE         (0x1U<<7)
#define LPTIM3_DIER_OUTPUT_REPOKIE      (0x1U<<8)
#define LPTIM3_DIER_OUTPUT_CC2IE        (0x1U<<9)
#define LPTIM3_DIER_OUTPUT_CMP2OKIE     (0x1U<<19)
#define LPTIM3_DIER_OUTPUT_UEDE         (0x1U<<23)

// DIER_INPUT Configuration

#define LPTIM3_DIER_INPUT_CC1IF         (0x1U<<0)
#define LPTIM3_DIER_INPUT_ARRMIE        (0x1U<<1)
#define LPTIM3_DIER_INPUT_EXTTRIGIE     (0x1U<<2)
#define LPTIM3_DIER_INPUT_ARROKIE       (0x1U<<4)
#define LPTIM3_DIER_INPUT_UPIE          (0x1U<<5)
#define LPTIM3_DIER_INPUT_DOWNIE        (0x1U<<6)
#define LPTIM3_DIER_INPUT_UEIE          (0x1U<<7)
#define LPTIM3_DIER_INPUT_REPOKIE       (0x1U<<8)
#define LPTIM3_DIER_INPUT_CC2IE         (0x1U<<9)
#define LPTIM3_DIER_INPUT_CC1OIE        (0x1U<<12)
#define LPTIM3_DIER_INPUT_CC2OIE        (0x1U<<13)
#define LPTIM3_DIER_INPUT_CC1DE         (0x1U<<16)
#define LPTIM3_DIER_INPUT_CC2DE         (0x1U<<25)

// CFGR Configuration

#define LPTIM3_CFGR_CKSEL               (0x1U<<0)
#define LPTIM3_CFGR_CKPOL               (0x3U<<1)
#define LPTIM3_CFGR_CKPOL_0             (0x1U<<1)
#define LPTIM3_CFGR_CKFLT               (0x3U<<3)
#define LPTIM3_CFGR_CKFLT_0             (0x1U<<3)
#define LPTIM3_CFGR_TRGFLT              (0x3U<<6)
#define LPTIM3_CFGR_TRGFLT_0            (0x1U<<6)
#define LPTIM3_CFGR_PRESC               (0x7U<<9)
#define LPTIM3_CFGR_PRESC_0             (0x1U<<9)
#define LPTIM3_CFGR_TRIGSEL             (0x7U<<13)
#define LPTIM3_CFGR_TRIGSEL_0           (0x1U<<13)
#define LPTIM3_CFGR_TRIGEN              (0x3U<<17)
#define LPTIM3_CFGR_TRIGEN_0            (0x1U<<17)
#define LPTIM3_CFGR_TIMOUT              (0x1U<<19)
#define LPTIM3_CFGR_WAVE                (0x1U<<20)
#define LPTIM3_CFGR_WAVPOL              (0x1U<<21)
#define LPTIM3_CFGR_PRELOAD             (0x1U<<22)
#define LPTIM3_CFGR_COUNTMODE           (0x1U<<23)
#define LPTIM3_CFGR_ENC                 (0x1U<<24)

// CR Configuration

#define LPTIM3_CR_ENABLE                (0x1U<<0)
#define LPTIM3_CR_SNGSTRT               (0x1U<<1)
#define LPTIM3_CR_CNTSTRT               (0x1U<<2)
#define LPTIM3_CR_COUNTRST              (0x1U<<3)
#define LPTIM3_CR_RSTARE                (0x1U<<4)

// CCR1 Configuration

#define LPTIM3_CCR1_CCR1                (0xFFFFU<<0)
#define LPTIM3_CCR1_CCR1_0              (0x1U<<0)

// ARR Configuration

#define LPTIM3_ARR_ARR                  (0xFFFFU<<0)
#define LPTIM3_ARR_ARR_0                (0x1U<<0)

// CNT Configuration

#define LPTIM3_CNT_CNT                  (0xFFFFU<<0)
#define LPTIM3_CNT_CNT_0                (0x1U<<0)

// CFGR2 Configuration

#define LPTIM3_CFGR2_IN1SEL             (0x3U<<0)
#define LPTIM3_CFGR2_IN1SEL_0           (0x1U<<0)
#define LPTIM3_CFGR2_IN2SEL             (0x3U<<4)
#define LPTIM3_CFGR2_IN2SEL_0           (0x1U<<4)
#define LPTIM3_CFGR2_IC1SEL             (0x3U<<16)
#define LPTIM3_CFGR2_IC1SEL_0           (0x1U<<16)
#define LPTIM3_CFGR2_IC2SEL             (0x3U<<20)
#define LPTIM3_CFGR2_IC2SEL_0           (0x1U<<20)

// RCR Configuration

#define LPTIM3_RCR_REP                  (0xFFU<<0)
#define LPTIM3_RCR_REP_0                (0x1U<<0)

// CCMR1 Configuration

#define LPTIM3_CCMR1_IC2F               (0x3U<<28)
#define LPTIM3_CCMR1_IC2F_0             (0x1U<<28)
#define LPTIM3_CCMR1_IC2PSC             (0x3U<<24)
#define LPTIM3_CCMR1_IC2PSC_0           (0x1U<<24)
#define LPTIM3_CCMR1_CC2P               (0x3U<<18)
#define LPTIM3_CCMR1_CC2P_0             (0x1U<<18)
#define LPTIM3_CCMR1_CC2E               (0x1U<<17)
#define LPTIM3_CCMR1_CC2SEL             (0x1U<<16)
#define LPTIM3_CCMR1_IC1F               (0x3U<<12)
#define LPTIM3_CCMR1_IC1F_0             (0x1U<<12)
#define LPTIM3_CCMR1_IC1PSC             (0x3U<<8)
#define LPTIM3_CCMR1_IC1PSC_0           (0x1U<<8)
#define LPTIM3_CCMR1_CC1P               (0x3U<<2)
#define LPTIM3_CCMR1_CC1P_0             (0x1U<<2)
#define LPTIM3_CCMR1_CC1E               (0x1U<<1)
#define LPTIM3_CCMR1_CC1SEL             (0x1U<<0)

// CCR2 Configuration

#define LPTIM3_CCR2_CCR2                (0xFFFFU<<0)
#define LPTIM3_CCR2_CCR2_0              (0x1U<<0)
