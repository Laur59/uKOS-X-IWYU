/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_dbgmcu equates.
 */

#pragma once

#include    <stdint.h>

// DBGMCU address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    IDCODE;
    volatile    uint32_t    CR;
    volatile    uint32_t    APB1LFZR;
    volatile    uint32_t    APB1HFZR;
    volatile    uint32_t    APB2FZR;
    volatile    uint32_t    APB3FZR;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    AHB1FZR;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    AHB3FZR;
    volatile    uint32_t    RESERVED2[52];
    volatile    uint32_t    SR;
    volatile    uint32_t    DBG_AUTH_HOST;
    volatile    uint32_t    DBG_AUTH_DEVICE;
    volatile    uint32_t    RESERVED3[946];
    volatile    uint32_t    PIDR4;
    volatile    uint32_t    RESERVED4[3];
    volatile    uint32_t    PIDR0;
    volatile    uint32_t    PIDR1;
    volatile    uint32_t    PIDR2;
    volatile    uint32_t    PIDR3;
    volatile    uint32_t    CIDR0;
    volatile    uint32_t    CIDR1;
    volatile    uint32_t    CIDR2;
    volatile    uint32_t    CIDR3;
} DBGMCU_TypeDef;

#ifdef __cplusplus
#define DBGMCU_NS   reinterpret_cast<DBGMCU_TypeDef *>(0xE0044000U)

#else
#define DBGMCU_NS   ((DBGMCU_TypeDef *)0xE0044000U)
#endif

// IDCODE Configuration

#define DBGMCU_IDCODE_REV_ID                (0xFFFFU<<16U)
#define DBGMCU_IDCODE_REV_ID_0              (0x1U<<16U)
#define DBGMCU_IDCODE_DEV_ID                (0xFFFU<<0U)
#define DBGMCU_IDCODE_DEV_ID_0              (0x1U<<0U)

// CR Configuration

#define DBGMCU_CR_TRACE_MODE                (0x3U<<6U)
#define DBGMCU_CR_TRACE_MODE_0              (0x1U<<6U)
#define DBGMCU_CR_TRACE_EN                  (0x1U<<5U)
#define DBGMCU_CR_TRACE_IOEN                (0x1U<<4U)
#define DBGMCU_CR_DBG_STANDBY               (0x1U<<2U)
#define DBGMCU_CR_DBG_STOP                  (0x1U<<1U)

// APB1LFZR Configuration

#define DBGMCU_APB1LFZR_DBG_I2C2_STOP       (0x1U<<22U)
#define DBGMCU_APB1LFZR_DBG_I2C1_STOP       (0x1U<<21U)
#define DBGMCU_APB1LFZR_DBG_IWDG_STOP       (0x1U<<12U)
#define DBGMCU_APB1LFZR_DBG_WWDG_STOP       (0x1U<<11U)
#define DBGMCU_APB1LFZR_DBG_TIM7_STOP       (0x1U<<5U)
#define DBGMCU_APB1LFZR_DBG_TIM6_STOP       (0x1U<<4U)
#define DBGMCU_APB1LFZR_DBG_TIM5_STOP       (0x1U<<3U)
#define DBGMCU_APB1LFZR_DBG_TIM4_STOP       (0x1U<<2U)
#define DBGMCU_APB1LFZR_DBG_TIM3_STOP       (0x1U<<1U)
#define DBGMCU_APB1LFZR_DBG_TIM2_STOP       (0x1U<<0U)

// APB1HFZR Configuration

#define DBGMCU_APB1HFZR_DBG_LPTIM2_STOP     (0x1U<<5U)
#define DBGMCU_APB1HFZR_DBG_I2C4_STOP       (0x1U<<1U)

// APB2FZR Configuration

#define DBGMCU_APB2FZR_DBG_TIM17_STOP       (0x1U<<18U)
#define DBGMCU_APB2FZR_DBG_TIM16_STOP       (0x1U<<17U)
#define DBGMCU_APB2FZR_DBG_TIM15_STOP       (0x1U<<16U)
#define DBGMCU_APB2FZR_DBG_TIM8_STOP        (0x1U<<13U)
#define DBGMCU_APB2FZR_DBG_TIM1_STOP        (0x1U<<11U)

// APB3FZR Configuration

#define DBGMCU_APB3FZR_DBG_RTC_STOP         (0x1U<<30U)
#define DBGMCU_APB3FZR_DBG_LPTIM4_STOP      (0x1U<<19U)
#define DBGMCU_APB3FZR_DBG_LPTIM3_STOP      (0x1U<<18U)
#define DBGMCU_APB3FZR_DBG_LPTIM1_STOP      (0x1U<<17U)
#define DBGMCU_APB3FZR_DBG_I2C3_STOP        (0x1U<<10U)

// AHB1FZR Configuration

#define DBGMCU_AHB1FZR_DBG_GPDMA15_STOP     (0x1U<<15U)
#define DBGMCU_AHB1FZR_DBG_GPDMA14_STOP     (0x1U<<14U)
#define DBGMCU_AHB1FZR_DBG_GPDMA13_STOP     (0x1U<<13U)
#define DBGMCU_AHB1FZR_DBG_GPDMA12_STOP     (0x1U<<12U)
#define DBGMCU_AHB1FZR_DBG_GPDMA11_STOP     (0x1U<<11U)
#define DBGMCU_AHB1FZR_DBG_GPDMA10_STOP     (0x1U<<10U)
#define DBGMCU_AHB1FZR_DBG_GPDMA9_STOP      (0x1U<<9U)
#define DBGMCU_AHB1FZR_DBG_GPDMA8_STOP      (0x1U<<8U)
#define DBGMCU_AHB1FZR_DBG_GPDMA7_STOP      (0x1U<<7U)
#define DBGMCU_AHB1FZR_DBG_GPDMA6_STOP      (0x1U<<6U)
#define DBGMCU_AHB1FZR_DBG_GPDMA5_STOP      (0x1U<<5U)
#define DBGMCU_AHB1FZR_DBG_GPDMA4_STOP      (0x1U<<4U)
#define DBGMCU_AHB1FZR_DBG_GPDMA3_STOP      (0x1U<<3U)
#define DBGMCU_AHB1FZR_DBG_GPDMA2_STOP      (0x1U<<2U)
#define DBGMCU_AHB1FZR_DBG_GPDMA1_STOP      (0x1U<<1U)
#define DBGMCU_AHB1FZR_DBG_GPDMA0_STOP      (0x1U<<0U)

// AHB3FZR Configuration

#define DBGMCU_AHB3FZR_DBG_LPDMA3_STOP      (0x1U<<3U)
#define DBGMCU_AHB3FZR_DBG_LPDMA2_STOP      (0x1U<<2U)
#define DBGMCU_AHB3FZR_DBG_LPDMA1_STOP      (0x1U<<1U)
#define DBGMCU_AHB3FZR_DBG_LPDMA0_STOP      (0x1U<<0U)

// SR Configuration

#define DBGMCU_SR_AP_LOCKED                 (0xFFU<<8U)
#define DBGMCU_SR_AP_LOCKED_0               (0x1U<<8U)
#define DBGMCU_SR_AP_PRESENT                (0xFFU<<0U)
#define DBGMCU_SR_AP_PRESENT_0              (0x1U<<0U)

// DBG_AUTH_HOST Configuration

#define DBGMCU_DBG_AUTH_HOST_AUTH_KEY       (0xFFFFFFFFU<<0U)
#define DBGMCU_DBG_AUTH_HOST_AUTH_KEY_0     (0x1U<<0U)

// DBG_AUTH_DEVICE Configuration

#define DBGMCU_DBG_AUTH_DEVICE_AUTH_ID      (0xFFFFU<<0U)
#define DBGMCU_DBG_AUTH_DEVICE_AUTH_ID_0    (0x1U<<0U)

// PIDR4 Configuration

#define DBGMCU_PIDR4_KCOUNT_4               (0xFU<<4U)
#define DBGMCU_PIDR4_KCOUNT_4_0             (0x1U<<4U)
#define DBGMCU_PIDR4_JEP106CON              (0xFU<<0U)
#define DBGMCU_PIDR4_JEP106CON_0            (0x1U<<0U)

// PIDR0 Configuration

#define DBGMCU_PIDR0_PARTNUM                (0xFFU<<0U)
#define DBGMCU_PIDR0_PARTNUM_0              (0x1U<<0U)

// PIDR1 Configuration

#define DBGMCU_PIDR1_JEP106ID               (0xFU<<4U)
#define DBGMCU_PIDR1_JEP106ID_0             (0x1U<<4U)
#define DBGMCU_PIDR1_PARTNUM                (0xFU<<0U)
#define DBGMCU_PIDR1_PARTNUM_0              (0x1U<<0U)

// PIDR2 Configuration

#define DBGMCU_PIDR2_REVISION               (0xFU<<4U)
#define DBGMCU_PIDR2_REVISION_0             (0x1U<<4U)
#define DBGMCU_PIDR2_JEDEC                  (0x1U<<3U)
#define DBGMCU_PIDR2_JEP106ID               (0x7U<<0U)
#define DBGMCU_PIDR2_JEP106ID_0             (0x1U<<0U)

// PIDR3 Configuration

#define DBGMCU_PIDR3_REVAND                 (0xFU<<4U)
#define DBGMCU_PIDR3_REVAND_0               (0x1U<<4U)
#define DBGMCU_PIDR3_CMOD                   (0xFU<<0U)
#define DBGMCU_PIDR3_CMOD_0                 (0x1U<<0U)

// CIDR0 Configuration

#define DBGMCU_CIDR0_PREAMBLE               (0xFFU<<0U)
#define DBGMCU_CIDR0_PREAMBLE_0             (0x1U<<0U)

// CIDR1 Configuration

#define DBGMCU_CIDR1_CLASS                  (0xFU<<4U)
#define DBGMCU_CIDR1_CLASS_0                (0x1U<<4U)
#define DBGMCU_CIDR1_PREAMBLE               (0xFU<<0U)
#define DBGMCU_CIDR1_PREAMBLE_0             (0x1U<<0U)

// CIDR2 Configuration

#define DBGMCU_CIDR2_PREAMBLE               (0xFFU<<0U)
#define DBGMCU_CIDR2_PREAMBLE_0             (0x1U<<0U)

// CIDR3 Configuration

#define DBGMCU_CIDR3_PREAMBLE               (0xFFU<<0U)
#define DBGMCU_CIDR3_PREAMBLE_0             (0x1U<<0U)
