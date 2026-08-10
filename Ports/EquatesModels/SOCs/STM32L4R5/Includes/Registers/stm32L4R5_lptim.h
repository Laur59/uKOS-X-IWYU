/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_lptim equates.
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

#define LPTIM_ISR_CMPM          (0x1U<<0U)
#define LPTIM_ISR_ARRM          (0x1U<<1U)
#define LPTIM_ISR_EXTTRIG       (0x1U<<2U)
#define LPTIM_ISR_CMPOK         (0x1U<<3U)
#define LPTIM_ISR_ARROK         (0x1U<<4U)
#define LPTIM_ISR_UP            (0x1U<<5U)
#define LPTIM_ISR_DOWN          (0x1U<<6U)

// ICR Configuration

#define LPTIM_ICR_CMPMCF        (0x1U<<0U)
#define LPTIM_ICR_ARRMCF        (0x1U<<1U)
#define LPTIM_ICR_EXTTRIGCF     (0x1U<<2U)
#define LPTIM_ICR_CMPOKCF       (0x1U<<3U)
#define LPTIM_ICR_ARROKCF       (0x1U<<4U)
#define LPTIM_ICR_UPCF          (0x1U<<5U)
#define LPTIM_ICR_DOWNCF        (0x1U<<6U)

// IER Configuration

#define LPTIM_IER_CMPMIE        (0x1U<<0U)
#define LPTIM_IER_ARRMIE        (0x1U<<1U)
#define LPTIM_IER_EXTTRIGIE     (0x1U<<2U)
#define LPTIM_IER_CMPOKIE       (0x1U<<3U)
#define LPTIM_IER_ARROKIE       (0x1U<<4U)
#define LPTIM_IER_UPIE          (0x1U<<5U)
#define LPTIM_IER_DOWNIE        (0x1U<<6U)

// CFGR Configuration

#define LPTIM_CFGR_CKSEL        (0x1U<<0U)
#define LPTIM_CFGR_CKPOL        (0x3U<<1U)
#define LPTIM_CFGR_CKPOL_0      (0x1U<<1U)
#define LPTIM_CFGR_CKFLT        (0x3U<<3U)
#define LPTIM_CFGR_CKFLT_0      (0x1U<<3U)
#define LPTIM_CFGR_TRGFLT       (0x3U<<6U)
#define LPTIM_CFGR_TRGFLT_0     (0x1U<<6U)
#define LPTIM_CFGR_PRESC        (0x7U<<9U)
#define LPTIM_CFGR_PRESC_0      (0x1U<<9U)
#define LPTIM_CFGR_TRIGSEL      (0x7U<<13U)
#define LPTIM_CFGR_TRIGSEL_0    (0x1U<<13U)
#define LPTIM_CFGR_TRIGEN       (0x3U<<17U)
#define LPTIM_CFGR_TRIGEN_0     (0x1U<<17U)
#define LPTIM_CFGR_TIMOUT       (0x1U<<19U)
#define LPTIM_CFGR_WAVE         (0x1U<<20U)
#define LPTIM_CFGR_WAVPOL       (0x1U<<21U)
#define LPTIM_CFGR_PRELOAD      (0x1U<<22U)
#define LPTIM_CFGR_COUNTMODE    (0x1U<<23U)
#define LPTIM_CFGR_ENC          (0x1U<<24U)

// CR Configuration

#define LPTIM_CR_ENABLE         (0x1U<<0U)
#define LPTIM_CR_SNGSTRT        (0x1U<<1U)
#define LPTIM_CR_CNTSTRT        (0x1U<<2U)

// CMP Configuration

#define LPTIM_CMP_CMP           (0xFFFFU<<0U)
#define LPTIM_CMP_CMP_0         (0x1U<<0U)

// ARR Configuration

#define LPTIM_ARR_ARR           (0xFFFFU<<0U)
#define LPTIM_ARR_ARR_0         (0x1U<<0U)

// CNT Configuration

#define LPTIM_CNT_CNT           (0xFFFFU<<0U)
#define LPTIM_CNT_CNT_0         (0x1U<<0U)
