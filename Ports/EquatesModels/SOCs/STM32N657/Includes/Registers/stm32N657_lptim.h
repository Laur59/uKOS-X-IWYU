/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_lptim equates.
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
#define LPTIM1_NS   reinterpret_cast<LPTIM_TypeDef *>(0x40002400U)
#define LPTIM1_S    reinterpret_cast<LPTIM_TypeDef *>(0x50002400U)
#define LPTIM2_NS   reinterpret_cast<LPTIM_TypeDef *>(0x46002400U)
#define LPTIM2_S    reinterpret_cast<LPTIM_TypeDef *>(0x56002400U)
#define LPTIM3_NS   reinterpret_cast<LPTIM_TypeDef *>(0x46002800U)
#define LPTIM3_S    reinterpret_cast<LPTIM_TypeDef *>(0x56002800U)
#define LPTIM4_NS   reinterpret_cast<LPTIM_TypeDef *>(0x46002C00U)
#define LPTIM4_S    reinterpret_cast<LPTIM_TypeDef *>(0x56002C00U)
#define LPTIM5_NS   reinterpret_cast<LPTIM_TypeDef *>(0x46003000U)
#define LPTIM5_S    reinterpret_cast<LPTIM_TypeDef *>(0x56003000U)

#else
#define LPTIM1_NS   ((LPTIM_TypeDef *)0x40002400U)
#define LPTIM1_S    ((LPTIM_TypeDef *)0x50002400U)
#define LPTIM2_NS   ((LPTIM_TypeDef *)0x46002400U)
#define LPTIM2_S    ((LPTIM_TypeDef *)0x56002400U)
#define LPTIM3_NS   ((LPTIM_TypeDef *)0x46002800U)
#define LPTIM3_S    ((LPTIM_TypeDef *)0x56002800U)
#define LPTIM4_NS   ((LPTIM_TypeDef *)0x46002C00U)
#define LPTIM4_S    ((LPTIM_TypeDef *)0x56002C00U)
#define LPTIM5_NS   ((LPTIM_TypeDef *)0x46003000U)
#define LPTIM5_S    ((LPTIM_TypeDef *)0x56003000U)
#endif

// ISR Configuration

#define LPTIM_ISR_DIEROK                        (0x1U<<24U)
#define LPTIM_ISR_CMP2OK                        (0x1U<<19U)
#define LPTIM_ISR_CC2IF                         (0x1U<<9U)
#define LPTIM_ISR_REPOK                         (0x1U<<8U)
#define LPTIM_ISR_UE                            (0x1U<<7U)
#define LPTIM_ISR_DOWN                          (0x1U<<6U)
#define LPTIM_ISR_UP                            (0x1U<<5U)
#define LPTIM_ISR_ARROK                         (0x1U<<4U)
#define LPTIM_ISR_CMP1OK                        (0x1U<<3U)
#define LPTIM_ISR_EXTTRIG                       (0x1U<<2U)
#define LPTIM_ISR_ARRM                          (0x1U<<1U)
#define LPTIM_ISR_CC1IF                         (0x1U<<0U)

#define LPTIM_ISR_CC2IF_B_0X0                   (0x0U<<9U)
#define LPTIM_ISR_CC2IF_B_0X1                   (0x1U<<9U)
#define LPTIM_ISR_CC1IF_B_0X0                   (0x0U<<0U)
#define LPTIM_ISR_CC1IF_B_0X1                   (0x1U<<0U)

// ICR Configuration

#define LPTIM_ICR_DIEROKCF                      (0x1U<<24U)
#define LPTIM_ICR_CMP2OKCF                      (0x1U<<19U)
#define LPTIM_ICR_CC2CF                         (0x1U<<9U)
#define LPTIM_ICR_REPOKCF                       (0x1U<<8U)
#define LPTIM_ICR_UECF                          (0x1U<<7U)
#define LPTIM_ICR_DOWNCF                        (0x1U<<6U)
#define LPTIM_ICR_UPCF                          (0x1U<<5U)
#define LPTIM_ICR_ARROKCF                       (0x1U<<4U)
#define LPTIM_ICR_CMP1OKCF                      (0x1U<<3U)
#define LPTIM_ICR_EXTTRIGCF                     (0x1U<<2U)
#define LPTIM_ICR_ARRMCF                        (0x1U<<1U)
#define LPTIM_ICR_CC1CF                         (0x1U<<0U)

// DIER Configuration

#define LPTIM_DIER_UEDE                         (0x1U<<23U)
#define LPTIM_DIER_CMP2OKIE                     (0x1U<<19U)
#define LPTIM_DIER_CC2IE                        (0x1U<<9U)
#define LPTIM_DIER_REPOKIE                      (0x1U<<8U)
#define LPTIM_DIER_UEIE                         (0x1U<<7U)
#define LPTIM_DIER_DOWNIE                       (0x1U<<6U)
#define LPTIM_DIER_UPIE                         (0x1U<<5U)
#define LPTIM_DIER_ARROKIE                      (0x1U<<4U)
#define LPTIM_DIER_CMP1OKIE                     (0x1U<<3U)
#define LPTIM_DIER_EXTTRIGIE                    (0x1U<<2U)
#define LPTIM_DIER_ARRMIE                       (0x1U<<1U)
#define LPTIM_DIER_CC1IE                        (0x1U<<0U)

#define LPTIM_DIER_UEDE_B_0X0                   (0x0U<<23U)
#define LPTIM_DIER_UEDE_B_0X1                   (0x1U<<23U)
#define LPTIM_DIER_CMP2OKIE_B_0X0               (0x0U<<19U)
#define LPTIM_DIER_CMP2OKIE_B_0X1               (0x1U<<19U)
#define LPTIM_DIER_CC2IE_B_0X0                  (0x0U<<9U)
#define LPTIM_DIER_CC2IE_B_0X1                  (0x1U<<9U)
#define LPTIM_DIER_REPOKIE_B_0X0                (0x0U<<8U)
#define LPTIM_DIER_REPOKIE_B_0X1                (0x1U<<8U)
#define LPTIM_DIER_UEIE_B_0X0                   (0x0U<<7U)
#define LPTIM_DIER_UEIE_B_0X1                   (0x1U<<7U)
#define LPTIM_DIER_DOWNIE_B_0X0                 (0x0U<<6U)
#define LPTIM_DIER_DOWNIE_B_0X1                 (0x1U<<6U)
#define LPTIM_DIER_UPIE_B_0X0                   (0x0U<<5U)
#define LPTIM_DIER_UPIE_B_0X1                   (0x1U<<5U)
#define LPTIM_DIER_ARROKIE_B_0X0                (0x0U<<4U)
#define LPTIM_DIER_ARROKIE_B_0X1                (0x1U<<4U)
#define LPTIM_DIER_CMP1OKIE_B_0X0               (0x0U<<3U)
#define LPTIM_DIER_CMP1OKIE_B_0X1               (0x1U<<3U)
#define LPTIM_DIER_EXTTRIGIE_B_0X0              (0x0U<<2U)
#define LPTIM_DIER_EXTTRIGIE_B_0X1              (0x1U<<2U)
#define LPTIM_DIER_ARRMIE_B_0X0                 (0x0U<<1U)
#define LPTIM_DIER_ARRMIE_B_0X1                 (0x1U<<1U)
#define LPTIM_DIER_CC1IE_B_0X0                  (0x0U<<0U)
#define LPTIM_DIER_CC1IE_B_0X1                  (0x1U<<0U)

// CFGR Configuration

#define LPTIM_CFGR_ENC                          (0x1U<<24U)
#define LPTIM_CFGR_COUNTMODE                    (0x1U<<23U)
#define LPTIM_CFGR_PRELOAD                      (0x1U<<22U)
#define LPTIM_CFGR_WAVPOL                       (0x1U<<21U)
#define LPTIM_CFGR_WAVE                         (0x1U<<20U)
#define LPTIM_CFGR_TIMOUT                       (0x1U<<19U)
#define LPTIM_CFGR_TRIGEN                       (0x3U<<17U)
#define LPTIM_CFGR_TRIGEN_0                     (0x1U<<17U)
#define LPTIM_CFGR_TRIGSEL                      (0x7U<<13U)
#define LPTIM_CFGR_TRIGSEL_0                    (0x1U<<13U)
#define LPTIM_CFGR_PRESC                        (0x7U<<9U)
#define LPTIM_CFGR_PRESC_0                      (0x1U<<9U)
#define LPTIM_CFGR_TRGFLT                       (0x3U<<6U)
#define LPTIM_CFGR_TRGFLT_0                     (0x1U<<6U)
#define LPTIM_CFGR_CKFLT                        (0x3U<<3U)
#define LPTIM_CFGR_CKFLT_0                      (0x1U<<3U)
#define LPTIM_CFGR_CKPOL                        (0x3U<<1U)
#define LPTIM_CFGR_CKPOL_0                      (0x1U<<1U)
#define LPTIM_CFGR_CKSEL                        (0x1U<<0U)

#define LPTIM_CFGR_ENC_B_0X0                    (0x0U<<24U)
#define LPTIM_CFGR_ENC_B_0X1                    (0x1U<<24U)
#define LPTIM_CFGR_COUNTMODE_B_0X0              (0x0U<<23U)
#define LPTIM_CFGR_COUNTMODE_B_0X1              (0x1U<<23U)
#define LPTIM_CFGR_PRELOAD_B_0X0                (0x0U<<22U)
#define LPTIM_CFGR_PRELOAD_B_0X1                (0x1U<<22U)
#define LPTIM_CFGR_WAVPOL_B_0X0                 (0x0U<<21U)
#define LPTIM_CFGR_WAVPOL_B_0X1                 (0x1U<<21U)
#define LPTIM_CFGR_WAVE_B_0X0                   (0x0U<<20U)
#define LPTIM_CFGR_WAVE_B_0X1                   (0x1U<<20U)
#define LPTIM_CFGR_TIMOUT_B_0X0                 (0x0U<<19U)
#define LPTIM_CFGR_TIMOUT_B_0X1                 (0x1U<<19U)
#define LPTIM_CFGR_TRIGEN_B_0X0                 (0x0U<<17U)
#define LPTIM_CFGR_TRIGEN_B_0X1                 (0x1U<<17U)
#define LPTIM_CFGR_TRIGEN_B_0X2                 (0x2U<<17U)
#define LPTIM_CFGR_TRIGEN_B_0X3                 (0x3U<<17U)
#define LPTIM_CFGR_TRIGSEL_B_0X0                (0x0U<<13U)
#define LPTIM_CFGR_TRIGSEL_B_0X1                (0x1U<<13U)
#define LPTIM_CFGR_TRIGSEL_B_0X2                (0x2U<<13U)
#define LPTIM_CFGR_TRIGSEL_B_0X3                (0x3U<<13U)
#define LPTIM_CFGR_TRIGSEL_B_0X4                (0x4U<<13U)
#define LPTIM_CFGR_TRIGSEL_B_0X5                (0x5U<<13U)
#define LPTIM_CFGR_TRIGSEL_B_0X6                (0x6U<<13U)
#define LPTIM_CFGR_TRIGSEL_B_0X7                (0x7U<<13U)
#define LPTIM_CFGR_PRESC_B_0X0                  (0x0U<<9U)
#define LPTIM_CFGR_PRESC_B_0X1                  (0x1U<<9U)
#define LPTIM_CFGR_PRESC_B_0X2                  (0x2U<<9U)
#define LPTIM_CFGR_PRESC_B_0X3                  (0x3U<<9U)
#define LPTIM_CFGR_PRESC_B_0X4                  (0x4U<<9U)
#define LPTIM_CFGR_PRESC_B_0X5                  (0x5U<<9U)
#define LPTIM_CFGR_PRESC_B_0X6                  (0x6U<<9U)
#define LPTIM_CFGR_PRESC_B_0X7                  (0x7U<<9U)
#define LPTIM_CFGR_TRGFLT_B_0X0                 (0x0U<<6U)
#define LPTIM_CFGR_TRGFLT_B_0X1                 (0x1U<<6U)
#define LPTIM_CFGR_TRGFLT_B_0X2                 (0x2U<<6U)
#define LPTIM_CFGR_TRGFLT_B_0X3                 (0x3U<<6U)
#define LPTIM_CFGR_CKFLT_B_0X0                  (0x0U<<3U)
#define LPTIM_CFGR_CKFLT_B_0X1                  (0x1U<<3U)
#define LPTIM_CFGR_CKFLT_B_0X2                  (0x2U<<3U)
#define LPTIM_CFGR_CKFLT_B_0X3                  (0x3U<<3U)
#define LPTIM_CFGR_CKPOL_B_0X0                  (0x0U<<1U)
#define LPTIM_CFGR_CKPOL_B_0X1                  (0x1U<<1U)
#define LPTIM_CFGR_CKPOL_B_0X2                  (0x2U<<1U)
#define LPTIM_CFGR_CKPOL_B_0X3                  (0x3U<<1U)
#define LPTIM_CFGR_CKSEL_B_0X0                  (0x0U<<0U)
#define LPTIM_CFGR_CKSEL_B_0X1                  (0x1U<<0U)

// CR Configuration

#define LPTIM_CR_RSTARE                         (0x1U<<4U)
#define LPTIM_CR_COUNTRST                       (0x1U<<3U)
#define LPTIM_CR_CNTSTRT                        (0x1U<<2U)
#define LPTIM_CR_SNGSTRT                        (0x1U<<1U)
#define LPTIM_CR_ENABLE                         (0x1U<<0U)

#define LPTIM_CR_ENABLE_B_0X0                   (0x0U<<0U)
#define LPTIM_CR_ENABLE_B_0X1                   (0x1U<<0U)

// CCR1 Configuration

#define LPTIM_CCR1_CCR1                         (0xFFFFU<<0U)
#define LPTIM_CCR1_CCR1_0                       (0x1U<<0U)

// ARR Configuration

#define LPTIM_ARR_ARR                           (0xFFFFU<<0U)
#define LPTIM_ARR_ARR_0                         (0x1U<<0U)

// CNT Configuration

#define LPTIM_CNT_CNT                           (0xFFFFU<<0U)
#define LPTIM_CNT_CNT_0                         (0x1U<<0U)

// CFGR2 Configuration

#define LPTIM_CFGR2_IC2SEL                      (0x3U<<20U)
#define LPTIM_CFGR2_IC2SEL_0                    (0x1U<<20U)
#define LPTIM_CFGR2_IC1SEL                      (0x3U<<16U)
#define LPTIM_CFGR2_IC1SEL_0                    (0x1U<<16U)
#define LPTIM_CFGR2_IN2SEL                      (0x3U<<4U)
#define LPTIM_CFGR2_IN2SEL_0                    (0x1U<<4U)
#define LPTIM_CFGR2_IN1SEL                      (0x3U<<0U)
#define LPTIM_CFGR2_IN1SEL_0                    (0x1U<<0U)

#define LPTIM_CFGR2_IC2SEL_B_0X0                (0x0U<<20U)
#define LPTIM_CFGR2_IC2SEL_B_0X1                (0x1U<<20U)
#define LPTIM_CFGR2_IC2SEL_B_0X2                (0x2U<<20U)
#define LPTIM_CFGR2_IC2SEL_B_0X3                (0x3U<<20U)
#define LPTIM_CFGR2_IC1SEL_B_0X0                (0x0U<<16U)
#define LPTIM_CFGR2_IC1SEL_B_0X1                (0x1U<<16U)
#define LPTIM_CFGR2_IC1SEL_B_0X2                (0x2U<<16U)
#define LPTIM_CFGR2_IC1SEL_B_0X3                (0x3U<<16U)
#define LPTIM_CFGR2_IN2SEL_B_0X0                (0x0U<<4U)
#define LPTIM_CFGR2_IN2SEL_B_0X1                (0x1U<<4U)
#define LPTIM_CFGR2_IN2SEL_B_0X2                (0x2U<<4U)
#define LPTIM_CFGR2_IN2SEL_B_0X3                (0x3U<<4U)
#define LPTIM_CFGR2_IN1SEL_B_0X0                (0x0U<<0U)
#define LPTIM_CFGR2_IN1SEL_B_0X1                (0x1U<<0U)
#define LPTIM_CFGR2_IN1SEL_B_0X2                (0x2U<<0U)
#define LPTIM_CFGR2_IN1SEL_B_0X3                (0x3U<<0U)

// RCR Configuration

#define LPTIM_RCR_REP                           (0xFFU<<0U)
#define LPTIM_RCR_REP_0                         (0x1U<<0U)

// CCMR1 Configuration

#define LPTIM_CCMR1_IC2F                        (0x3U<<28U)
#define LPTIM_CCMR1_IC2F_0                      (0x1U<<28U)
#define LPTIM_CCMR1_IC2PSC                      (0x3U<<24U)
#define LPTIM_CCMR1_IC2PSC_0                    (0x1U<<24U)
#define LPTIM_CCMR1_CC2P                        (0x3U<<18U)
#define LPTIM_CCMR1_CC2P_0                      (0x1U<<18U)
#define LPTIM_CCMR1_CC2E                        (0x1U<<17U)
#define LPTIM_CCMR1_CC2SEL                      (0x1U<<16U)
#define LPTIM_CCMR1_IC1F                        (0x3U<<12U)
#define LPTIM_CCMR1_IC1F_0                      (0x1U<<12U)
#define LPTIM_CCMR1_IC1PSC                      (0x3U<<8U)
#define LPTIM_CCMR1_IC1PSC_0                    (0x1U<<8U)
#define LPTIM_CCMR1_CC1P                        (0x3U<<2U)
#define LPTIM_CCMR1_CC1P_0                      (0x1U<<2U)
#define LPTIM_CCMR1_CC1E                        (0x1U<<1U)
#define LPTIM_CCMR1_CC1SEL                      (0x1U<<0U)

#define LPTIM_CCMR1_IC2F_B_0X0                  (0x0U<<28U)
#define LPTIM_CCMR1_IC2F_B_0X1                  (0x1U<<28U)
#define LPTIM_CCMR1_IC2F_B_0X2                  (0x2U<<28U)
#define LPTIM_CCMR1_IC2F_B_0X3                  (0x3U<<28U)
#define LPTIM_CCMR1_IC2PSC_B_0X0                (0x0U<<24U)
#define LPTIM_CCMR1_IC2PSC_B_0X1                (0x1U<<24U)
#define LPTIM_CCMR1_IC2PSC_B_0X2                (0x2U<<24U)
#define LPTIM_CCMR1_IC2PSC_B_0X3                (0x3U<<24U)
#define LPTIM_CCMR1_CC2P_B_0X0_CC2_AS_OUTPUT    (0x0U<<18U)
#define LPTIM_CCMR1_CC2P_B_0X1_CC2_AS_OUTPUT    (0x1U<<18U)
#define LPTIM_CCMR1_CC2P_B_0X3_CC2_AS_INPUT     (0x3U<<18U)
#define LPTIM_CCMR1_CC2E_B_0X0_CC2_AS_OUTPUT    (0x0U<<17U)
#define LPTIM_CCMR1_CC2E_B_0X1_CC2_AS_OUTPUT    (0x1U<<17U)
#define LPTIM_CCMR1_CC2SEL_B_0X0                (0x0U<<16U)
#define LPTIM_CCMR1_CC2SEL_B_0X1                (0x1U<<16U)
#define LPTIM_CCMR1_IC1F_B_0X0                  (0x0U<<12U)
#define LPTIM_CCMR1_IC1F_B_0X1                  (0x1U<<12U)
#define LPTIM_CCMR1_IC1F_B_0X2                  (0x2U<<12U)
#define LPTIM_CCMR1_IC1F_B_0X3                  (0x3U<<12U)
#define LPTIM_CCMR1_IC1PSC_B_0X0                (0x0U<<8U)
#define LPTIM_CCMR1_IC1PSC_B_0X1                (0x1U<<8U)
#define LPTIM_CCMR1_IC1PSC_B_0X2                (0x2U<<8U)
#define LPTIM_CCMR1_IC1PSC_B_0X3                (0x3U<<8U)
#define LPTIM_CCMR1_CC1P_B_0X0_CC1_AS_OUTPUT    (0x0U<<2U)
#define LPTIM_CCMR1_CC1P_B_0X1_CC1_AS_OUTPUT    (0x1U<<2U)
#define LPTIM_CCMR1_CC1P_B_0X3_CC1_AS_INPUT     (0x3U<<2U)
#define LPTIM_CCMR1_CC1E_B_0X0_CC1_AS_OUTPUT    (0x0U<<1U)
#define LPTIM_CCMR1_CC1E_B_0X1_CC1_AS_OUTPUT    (0x1U<<1U)
#define LPTIM_CCMR1_CC1SEL_B_0X0                (0x0U<<0U)
#define LPTIM_CCMR1_CC1SEL_B_0X1                (0x1U<<0U)

// CCR2 Configuration

#define LPTIM_CCR2_CCR2                         (0xFFFFU<<0U)
#define LPTIM_CCR2_CCR2_0                       (0x1U<<0U)
