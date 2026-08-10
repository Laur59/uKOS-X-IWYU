/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     GD32VF103_timer2 equates.
 */

#pragma once

#include    <stdint.h>

// TIMER2 address definitions
// --------------------------

typedef struct {
    volatile    uint16_t    CTL0;
    volatile    uint16_t    RESERVED0;
    volatile    uint16_t    CTL1;
    volatile    uint16_t    RESERVED1;
    volatile    uint16_t    SMCFG;
    volatile    uint16_t    RESERVED2;
    volatile    uint16_t    DMAINTEN;
    volatile    uint16_t    RESERVED3;
    volatile    uint16_t    INTF;
    volatile    uint16_t    RESERVED4;
    volatile    uint16_t    SWEVG;
    volatile    uint16_t    RESERVED5;
    volatile    uint16_t    CHCTL0;
    volatile    uint16_t    RESERVED6;
    volatile    uint16_t    CHCTL1;
    volatile    uint16_t    RESERVED7;
    volatile    uint16_t    CHCTL2;
    volatile    uint16_t    RESERVED8;
    volatile    uint16_t    CNT;
    volatile    uint16_t    RESERVED9;
    volatile    uint16_t    PSC;
    volatile    uint16_t    RESERVED10;
    volatile    uint16_t    CAR;
    volatile    uint16_t    RESERVED11[3];
    volatile    uint32_t    CH0CV;
    volatile    uint32_t    CH1CV;
    volatile    uint32_t    CH2CV;
    volatile    uint32_t    CH3CV;
    volatile    uint32_t    RESERVED12;
    volatile    uint16_t    DMACFG;
    volatile    uint16_t    RESERVED13;
    volatile    uint32_t    DMATB;
} TIMER2_TypeDef;

#ifdef __cplusplus
#define TIMER2  reinterpret_cast<TIMER2_TypeDef *>(0x40000400U)

#else
#define TIMER2  ((TIMER2_TypeDef *)0x40000400U)
#endif

// CTL0 Configuration

#define TIMER2_CTL0_CEN             (0x1U<<0U)
#define TIMER2_CTL0_UPDIS           (0x1U<<1U)
#define TIMER2_CTL0_UPS             (0x1U<<2U)
#define TIMER2_CTL0_SPM             (0x1U<<3U)
#define TIMER2_CTL0_DIR             (0x1U<<4U)
#define TIMER2_CTL0_CAM             (0x3U<<5U)
#define TIMER2_CTL0_CAM_0           (0x1U<<5U)
#define TIMER2_CTL0_ARSE            (0x1U<<7U)
#define TIMER2_CTL0_CKDIV           (0x3U<<8U)
#define TIMER2_CTL0_CKDIV_0         (0x1U<<8U)

// CTL1 Configuration

#define TIMER2_CTL1_DMAS            (0x1U<<3U)
#define TIMER2_CTL1_MMC             (0x7U<<4U)
#define TIMER2_CTL1_MMC_0           (0x1U<<4U)
#define TIMER2_CTL1_TI0S            (0x1U<<7U)

// SMCFG Configuration

#define TIMER2_SMCFG_SMC            (0x7U<<0U)
#define TIMER2_SMCFG_SMC_0          (0x1U<<0U)
#define TIMER2_SMCFG_TRGS           (0x7U<<4U)
#define TIMER2_SMCFG_TRGS_0         (0x1U<<4U)
#define TIMER2_SMCFG_MSM            (0x1U<<7U)
#define TIMER2_SMCFG_ETFC           (0xFU<<8U)
#define TIMER2_SMCFG_ETFC_0         (0x1U<<8U)
#define TIMER2_SMCFG_ETPSC          (0x3U<<12U)
#define TIMER2_SMCFG_ETPSC_0        (0x1U<<12U)
#define TIMER2_SMCFG_SMC1           (0x1U<<14U)
#define TIMER2_SMCFG_ETP            (0x1U<<15U)

// DMAINTEN Configuration

#define TIMER2_DMAINTEN_UPIE        (0x1U<<0U)
#define TIMER2_DMAINTEN_CH0IE       (0x1U<<1U)
#define TIMER2_DMAINTEN_CH1IE       (0x1U<<2U)
#define TIMER2_DMAINTEN_CH2IE       (0x1U<<3U)
#define TIMER2_DMAINTEN_CH3IE       (0x1U<<4U)
#define TIMER2_DMAINTEN_TRGIE       (0x1U<<6U)
#define TIMER2_DMAINTEN_UPDEN       (0x1U<<8U)
#define TIMER2_DMAINTEN_CH0DEN      (0x1U<<9U)
#define TIMER2_DMAINTEN_CH1DEN      (0x1U<<10U)
#define TIMER2_DMAINTEN_CH2DEN      (0x1U<<11U)
#define TIMER2_DMAINTEN_CH3DEN      (0x1U<<12U)
#define TIMER2_DMAINTEN_TRGDEN      (0x1U<<14U)

// INTF Configuration

#define TIMER2_INTF_UPIF            (0x1U<<0U)
#define TIMER2_INTF_CH0IF           (0x1U<<1U)
#define TIMER2_INTF_CH1IF           (0x1U<<2U)
#define TIMER2_INTF_CH2IF           (0x1U<<3U)
#define TIMER2_INTF_CH3IF           (0x1U<<4U)
#define TIMER2_INTF_TRGIF           (0x1U<<6U)
#define TIMER2_INTF_CH0OF           (0x1U<<9U)
#define TIMER2_INTF_CH1OF           (0x1U<<10U)
#define TIMER2_INTF_CH2OF           (0x1U<<11U)
#define TIMER2_INTF_CH3OF           (0x1U<<12U)

// SWEVG Configuration

#define TIMER2_SWEVG_UPG            (0x1U<<0U)
#define TIMER2_SWEVG_CH0G           (0x1U<<1U)
#define TIMER2_SWEVG_CH1G           (0x1U<<2U)
#define TIMER2_SWEVG_CH2G           (0x1U<<3U)
#define TIMER2_SWEVG_CH3G           (0x1U<<4U)
#define TIMER2_SWEVG_TRGG           (0x1U<<6U)

// CHCTL0 Configuration

#define TIMER2_CHCTL0_CH0MS         (0x3U<<0U)
#define TIMER2_CHCTL0_CH0MS_0       (0x1U<<0U)
#define TIMER2_CHCTL0_CH0COMFEN     (0x1U<<2U)
#define TIMER2_CHCTL0_CH0COMSEN     (0x1U<<3U)
#define TIMER2_CHCTL0_CH0COMCTL     (0x7U<<4U)
#define TIMER2_CHCTL0_CH0COMCTL_0   (0x1U<<4U)
#define TIMER2_CHCTL0_CH0COMCEN     (0x1U<<7U)
#define TIMER2_CHCTL0_CH1MS         (0x3U<<8U)
#define TIMER2_CHCTL0_CH1MS_0       (0x1U<<8U)
#define TIMER2_CHCTL0_CH1COMFEN     (0x1U<<10U)
#define TIMER2_CHCTL0_CH1COMSEN     (0x1U<<11U)
#define TIMER2_CHCTL0_CH1COMCTL     (0x7U<<12U)
#define TIMER2_CHCTL0_CH1COMCTL_0   (0x1U<<12U)
#define TIMER2_CHCTL0_CH1COMCEN     (0x1U<<15U)

// CHCTL1 Configuration

#define TIMER2_CHCTL1_CH2MS         (0x3U<<0U)
#define TIMER2_CHCTL1_CH2MS_0       (0x1U<<0U)
#define TIMER2_CHCTL1_CH2COMFEN     (0x1U<<2U)
#define TIMER2_CHCTL1_CH2COMSEN     (0x1U<<3U)
#define TIMER2_CHCTL1_CH2COMCTL     (0x7U<<4U)
#define TIMER2_CHCTL1_CH2COMCTL_0   (0x1U<<4U)
#define TIMER2_CHCTL1_CH2COMCEN     (0x1U<<7U)
#define TIMER2_CHCTL1_CH3MS         (0x3U<<8U)
#define TIMER2_CHCTL1_CH3MS_0       (0x1U<<8U)
#define TIMER2_CHCTL1_CH3COMFEN     (0x1U<<10U)
#define TIMER2_CHCTL1_CH3COMSEN     (0x1U<<11U)
#define TIMER2_CHCTL1_CH3COMCTL     (0x7U<<12U)
#define TIMER2_CHCTL1_CH3COMCTL_0   (0x1U<<12U)
#define TIMER2_CHCTL1_CH3COMCEN     (0x1U<<15U)

// CHCTL2 Configuration

#define TIMER2_CHCTL2_CH0EN         (0x1U<<0U)
#define TIMER2_CHCTL2_CH0P          (0x1U<<1U)
#define TIMER2_CHCTL2_CH1EN         (0x1U<<4U)
#define TIMER2_CHCTL2_CH1P          (0x1U<<5U)
#define TIMER2_CHCTL2_CH2EN         (0x1U<<8U)
#define TIMER2_CHCTL2_CH2P          (0x1U<<9U)
#define TIMER2_CHCTL2_CH3EN         (0x1U<<12U)
#define TIMER2_CHCTL2_CH3P          (0x1U<<13U)

// CNT Configuration

#define TIMER2_CNT_CNT              (0xFFFFU<<0U)
#define TIMER2_CNT_CNT_0            (0x1U<<0U)

// PSC Configuration

#define TIMER2_PSC_PSC              (0xFFFFU<<0U)
#define TIMER2_PSC_PSC_0            (0x1U<<0U)

// CAR Configuration

#define TIMER2_CAR_CARL             (0xFFFFU<<0U)
#define TIMER2_CAR_CARL_0           (0x1U<<0U)

// CH0CV Configuration

#define TIMER2_CH0CV_CH0VAL         (0xFFFFU<<0U)
#define TIMER2_CH0CV_CH0VAL_0       (0x1U<<0U)

// CH1CV Configuration

#define TIMER2_CH1CV_CH1VAL         (0xFFFFU<<0U)
#define TIMER2_CH1CV_CH1VAL_0       (0x1U<<0U)

// CH2CV Configuration

#define TIMER2_CH2CV_CH2VAL         (0xFFFFU<<0U)
#define TIMER2_CH2CV_CH2VAL_0       (0x1U<<0U)

// CH3CV Configuration

#define TIMER2_CH3CV_CH3VAL         (0xFFFFU<<0U)
#define TIMER2_CH3CV_CH3VAL_0       (0x1U<<0U)

// DMACFG Configuration

#define TIMER2_DMACFG_DMATA         (0x1FU<<0U)
#define TIMER2_DMACFG_DMATA_0       (0x1U<<0U)
#define TIMER2_DMACFG_DMATC         (0x1FU<<8U)
#define TIMER2_DMACFG_DMATC_0       (0x1U<<8U)

// DMATB Configuration

#define TIMER2_DMATB_DMATB          (0xFFFFU<<0U)
#define TIMER2_DMATB_DMATB_0        (0x1U<<0U)
