/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     GD32VF103_dac equates.
 */

#pragma once

#include    <stdint.h>

// DAC address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CTL;
    volatile    uint32_t    SWT;
    volatile    uint32_t    DAC0_R12DH;
    volatile    uint32_t    DAC0_L12DH;
    volatile    uint32_t    DAC0_R8DH;
    volatile    uint32_t    DAC1_R12DH;
    volatile    uint32_t    DAC1_L12DH;
    volatile    uint32_t    DAC1_R8DH;
    volatile    uint32_t    DACC_R12DH;
    volatile    uint32_t    DACC_L12DH;
    volatile    uint32_t    DACC_R8DH;
    volatile    uint32_t    DAC0_DO;
    volatile    uint32_t    DAC1_DO;
} DAC_TypeDef;

#ifdef __cplusplus
#define DAC reinterpret_cast<DAC_TypeDef *>(0x40007400U)

#else
#define DAC ((DAC_TypeDef *)0x40007400U)
#endif

// CTL Configuration

#define DAC_CTL_DDMAEN1             (0x1U<<28U)
#define DAC_CTL_DWBW1               (0xFU<<24U)
#define DAC_CTL_DWBW1_0             (0x1U<<24U)
#define DAC_CTL_DWM1                (0x3U<<22U)
#define DAC_CTL_DWM1_0              (0x1U<<22U)
#define DAC_CTL_DTSEL1              (0x7U<<19U)
#define DAC_CTL_DTSEL1_0            (0x1U<<19U)
#define DAC_CTL_DTEN1               (0x1U<<18U)
#define DAC_CTL_DBOFF1              (0x1U<<17U)
#define DAC_CTL_DEN1                (0x1U<<16U)
#define DAC_CTL_DDMAEN0             (0x1U<<12U)
#define DAC_CTL_DWBW0               (0xFU<<8U)
#define DAC_CTL_DWBW0_0             (0x1U<<8U)
#define DAC_CTL_DWM0                (0x3U<<6U)
#define DAC_CTL_DWM0_0              (0x1U<<6U)
#define DAC_CTL_DTSEL0              (0x7U<<3U)
#define DAC_CTL_DTSEL0_0            (0x1U<<3U)
#define DAC_CTL_DTEN0               (0x1U<<2U)
#define DAC_CTL_DBOFF0              (0x1U<<1U)
#define DAC_CTL_DEN0                (0x1U<<0U)

// SWT Configuration

#define DAC_SWT_SWTR1               (0x1U<<1U)
#define DAC_SWT_SWTR0               (0x1U<<0U)

// DAC0_R12DH Configuration

#define DAC_DAC0_R12DH_DAC0_DH      (0xFFFU<<0U)
#define DAC_DAC0_R12DH_DAC0_DH_0    (0x1U<<0U)

// DAC0_L12DH Configuration

#define DAC_DAC0_L12DH_DAC0_DH      (0xFFFU<<4U)
#define DAC_DAC0_L12DH_DAC0_DH_0    (0x1U<<4U)

// DAC0_R8DH Configuration

#define DAC_DAC0_R8DH_DAC0_DH       (0xFFU<<0U)
#define DAC_DAC0_R8DH_DAC0_DH_0     (0x1U<<0U)

// DAC1_R12DH Configuration

#define DAC_DAC1_R12DH_DAC1_DH      (0xFFFU<<0U)
#define DAC_DAC1_R12DH_DAC1_DH_0    (0x1U<<0U)

// DAC1_L12DH Configuration

#define DAC_DAC1_L12DH_DAC1_DH      (0xFFFU<<4U)
#define DAC_DAC1_L12DH_DAC1_DH_0    (0x1U<<4U)

// DAC1_R8DH Configuration

#define DAC_DAC1_R8DH_DAC1_DH       (0xFFU<<0U)
#define DAC_DAC1_R8DH_DAC1_DH_0     (0x1U<<0U)

// DACC_R12DH Configuration

#define DAC_DACC_R12DH_DAC1_DH      (0xFFFU<<16U)
#define DAC_DACC_R12DH_DAC1_DH_0    (0x1U<<16U)
#define DAC_DACC_R12DH_DAC0_DH      (0xFFFU<<0U)
#define DAC_DACC_R12DH_DAC0_DH_0    (0x1U<<0U)

// DACC_L12DH Configuration

#define DAC_DACC_L12DH_DAC1_DH      (0xFFFU<<20U)
#define DAC_DACC_L12DH_DAC1_DH_0    (0x1U<<20U)
#define DAC_DACC_L12DH_DAC0_DH      (0xFFFU<<4U)
#define DAC_DACC_L12DH_DAC0_DH_0    (0x1U<<4U)

// DACC_R8DH Configuration

#define DAC_DACC_R8DH_DAC1_DH       (0xFFU<<8U)
#define DAC_DACC_R8DH_DAC1_DH_0     (0x1U<<8U)
#define DAC_DACC_R8DH_DAC0_DH       (0xFFU<<0U)
#define DAC_DACC_R8DH_DAC0_DH_0     (0x1U<<0U)

// DAC0_DO Configuration

#define DAC_DAC0_DO_DAC0_DO         (0xFFFU<<0U)
#define DAC_DAC0_DO_DAC0_DO_0       (0x1U<<0U)

// DAC1_DO Configuration

#define DAC_DAC1_DO_DAC1_DO         (0xFFFU<<0U)
#define DAC_DAC1_DO_DAC1_DO_0       (0x1U<<0U)
