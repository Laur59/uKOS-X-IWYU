/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; GD32VF103_timer0.
; =================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     GD32VF103_timer0 equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// TIMER0 address definitions
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
    volatile    uint16_t    RESERVED11;
    volatile    uint16_t    CREP;
    volatile    uint16_t    RESERVED12;
    volatile    uint16_t    CH0CV;
    volatile    uint16_t    RESERVED13;
    volatile    uint16_t    CH1CV;
    volatile    uint16_t    RESERVED14;
    volatile    uint16_t    CH2CV;
    volatile    uint16_t    RESERVED15;
    volatile    uint16_t    CH3CV;
    volatile    uint16_t    RESERVED16;
    volatile    uint16_t    CCHP;
    volatile    uint16_t    RESERVED17;
    volatile    uint16_t    DMACFG;
    volatile    uint16_t    RESERVED18;
    volatile    uint16_t    DMATB;
} TIMER0_TypeDef;

#ifdef __cplusplus
#define TIMER0  reinterpret_cast<TIMER0_TypeDef *>(0x40012C00U)

#else
#define TIMER0  ((TIMER0_TypeDef *)0x40012C00U)
#endif

// CTL0 Configuration

#define TIMER0_CTL0_CEN             (0x1U<<0)
#define TIMER0_CTL0_UPDIS           (0x1U<<1)
#define TIMER0_CTL0_UPS             (0x1U<<2)
#define TIMER0_CTL0_SPM             (0x1U<<3)
#define TIMER0_CTL0_DIR             (0x1U<<4)
#define TIMER0_CTL0_CAM             (0x3U<<5)
#define TIMER0_CTL0_CAM_0           (0x1U<<5)
#define TIMER0_CTL0_ARSE            (0x1U<<7)
#define TIMER0_CTL0_CKDIV           (0x3U<<8)
#define TIMER0_CTL0_CKDIV_0         (0x1U<<8)

// CTL1 Configuration

#define TIMER0_CTL1_CCSE            (0x1U<<0)
#define TIMER0_CTL1_CCUC            (0x1U<<2)
#define TIMER0_CTL1_DMAS            (0x1U<<3)
#define TIMER0_CTL1_MMC             (0x7U<<4)
#define TIMER0_CTL1_MMC_0           (0x1U<<4)
#define TIMER0_CTL1_TI0S            (0x1U<<7)
#define TIMER0_CTL1_ISO0            (0x1U<<8)
#define TIMER0_CTL1_ISO0N           (0x1U<<9)
#define TIMER0_CTL1_ISO1            (0x1U<<10)
#define TIMER0_CTL1_ISO1N           (0x1U<<11)
#define TIMER0_CTL1_ISO2            (0x1U<<12)
#define TIMER0_CTL1_ISO2N           (0x1U<<13)
#define TIMER0_CTL1_ISO3            (0x1U<<14)

// SMCFG Configuration

#define TIMER0_SMCFG_SMC            (0x7U<<0)
#define TIMER0_SMCFG_SMC_0          (0x1U<<0)
#define TIMER0_SMCFG_TRGS           (0x7U<<4)
#define TIMER0_SMCFG_TRGS_0         (0x1U<<4)
#define TIMER0_SMCFG_MSM            (0x1U<<7)
#define TIMER0_SMCFG_ETFC           (0xFU<<8)
#define TIMER0_SMCFG_ETFC_0         (0x1U<<8)
#define TIMER0_SMCFG_ETPSC          (0x3U<<12)
#define TIMER0_SMCFG_ETPSC_0        (0x1U<<12)
#define TIMER0_SMCFG_SMC1           (0x1U<<14)
#define TIMER0_SMCFG_ETP            (0x1U<<15)

// DMAINTEN Configuration

#define TIMER0_DMAINTEN_UPIE        (0x1U<<0)
#define TIMER0_DMAINTEN_CH0IE       (0x1U<<1)
#define TIMER0_DMAINTEN_CH1IE       (0x1U<<2)
#define TIMER0_DMAINTEN_CH2IE       (0x1U<<3)
#define TIMER0_DMAINTEN_CH3IE       (0x1U<<4)
#define TIMER0_DMAINTEN_CMTIE       (0x1U<<5)
#define TIMER0_DMAINTEN_TRGIE       (0x1U<<6)
#define TIMER0_DMAINTEN_BRKIE       (0x1U<<7)
#define TIMER0_DMAINTEN_UPDEN       (0x1U<<8)
#define TIMER0_DMAINTEN_CH0DEN      (0x1U<<9)
#define TIMER0_DMAINTEN_CH1DEN      (0x1U<<10)
#define TIMER0_DMAINTEN_CH2DEN      (0x1U<<11)
#define TIMER0_DMAINTEN_CH3DEN      (0x1U<<12)
#define TIMER0_DMAINTEN_CMTDEN      (0x1U<<13)
#define TIMER0_DMAINTEN_TRGDEN      (0x1U<<14)

// INTF Configuration

#define TIMER0_INTF_UPIF            (0x1U<<0)
#define TIMER0_INTF_CH0IF           (0x1U<<1)
#define TIMER0_INTF_CH1IF           (0x1U<<2)
#define TIMER0_INTF_CH2IF           (0x1U<<3)
#define TIMER0_INTF_CH3IF           (0x1U<<4)
#define TIMER0_INTF_CMTIF           (0x1U<<5)
#define TIMER0_INTF_TRGIF           (0x1U<<6)
#define TIMER0_INTF_BRKIF           (0x1U<<7)
#define TIMER0_INTF_CH0OF           (0x1U<<9)
#define TIMER0_INTF_CH1OF           (0x1U<<10)
#define TIMER0_INTF_CH2OF           (0x1U<<11)
#define TIMER0_INTF_CH3OF           (0x1U<<12)

// SWEVG Configuration

#define TIMER0_SWEVG_UPG            (0x1U<<0)
#define TIMER0_SWEVG_CH0G           (0x1U<<1)
#define TIMER0_SWEVG_CH1G           (0x1U<<2)
#define TIMER0_SWEVG_CH2G           (0x1U<<3)
#define TIMER0_SWEVG_CH3G           (0x1U<<4)
#define TIMER0_SWEVG_CMTG           (0x1U<<5)
#define TIMER0_SWEVG_TRGG           (0x1U<<6)
#define TIMER0_SWEVG_BRKG           (0x1U<<7)

// CHCTL0 Configuration

#define TIMER0_CHCTL0_CH0MS         (0x3U<<0)
#define TIMER0_CHCTL0_CH0MS_0       (0x1U<<0)
#define TIMER0_CHCTL0_CH0COMFEN     (0x1U<<2)
#define TIMER0_CHCTL0_CH0COMSEN     (0x1U<<3)
#define TIMER0_CHCTL0_CH0COMCTL     (0x7U<<4)
#define TIMER0_CHCTL0_CH0COMCTL_0   (0x1U<<4)
#define TIMER0_CHCTL0_CH0COMCEN     (0x1U<<7)
#define TIMER0_CHCTL0_CH1MS         (0x3U<<8)
#define TIMER0_CHCTL0_CH1MS_0       (0x1U<<8)
#define TIMER0_CHCTL0_CH1COMFEN     (0x1U<<10)
#define TIMER0_CHCTL0_CH1COMSEN     (0x1U<<11)
#define TIMER0_CHCTL0_CH1COMCTL     (0x7U<<12)
#define TIMER0_CHCTL0_CH1COMCTL_0   (0x1U<<12)
#define TIMER0_CHCTL0_CH1COMCEN     (0x1U<<15)

// CHCTL1 Configuration

#define TIMER0_CHCTL1_CH2MS         (0x3U<<0)
#define TIMER0_CHCTL1_CH2MS_0       (0x1U<<0)
#define TIMER0_CHCTL1_CH2COMFEN     (0x1U<<2)
#define TIMER0_CHCTL1_CH2COMSEN     (0x1U<<3)
#define TIMER0_CHCTL1_CH2COMCTL     (0x7U<<4)
#define TIMER0_CHCTL1_CH2COMCTL_0   (0x1U<<4)
#define TIMER0_CHCTL1_CH2COMCEN     (0x1U<<7)
#define TIMER0_CHCTL1_CH3MS         (0x3U<<8)
#define TIMER0_CHCTL1_CH3MS_0       (0x1U<<8)
#define TIMER0_CHCTL1_CH3COMFEN     (0x1U<<10)
#define TIMER0_CHCTL1_CH3COMSEN     (0x1U<<11)
#define TIMER0_CHCTL1_CH3COMCTL     (0x7U<<12)
#define TIMER0_CHCTL1_CH3COMCTL_0   (0x1U<<12)
#define TIMER0_CHCTL1_CH3COMCEN     (0x1U<<15)

// CHCTL2 Configuration

#define TIMER0_CHCTL2_CH0EN         (0x1U<<0)
#define TIMER0_CHCTL2_CH0P          (0x1U<<1)
#define TIMER0_CHCTL2_CH0NEN        (0x1U<<2)
#define TIMER0_CHCTL2_CH0NP         (0x1U<<3)
#define TIMER0_CHCTL2_CH1EN         (0x1U<<4)
#define TIMER0_CHCTL2_CH1P          (0x1U<<5)
#define TIMER0_CHCTL2_CH1NEN        (0x1U<<6)
#define TIMER0_CHCTL2_CH1NP         (0x1U<<7)
#define TIMER0_CHCTL2_CH2EN         (0x1U<<8)
#define TIMER0_CHCTL2_CH2P          (0x1U<<9)
#define TIMER0_CHCTL2_CH2NEN        (0x1U<<10)
#define TIMER0_CHCTL2_CH2NP         (0x1U<<11)
#define TIMER0_CHCTL2_CH3EN         (0x1U<<12)
#define TIMER0_CHCTL2_CH3P          (0x1U<<13)

// CNT Configuration

#define TIMER0_CNT_CNT              (0xFFFFU<<0)
#define TIMER0_CNT_CNT_0            (0x1U<<0)

// PSC Configuration

#define TIMER0_PSC_PSC              (0xFFFFU<<0)
#define TIMER0_PSC_PSC_0            (0x1U<<0)

// CAR Configuration

#define TIMER0_CAR_CARL             (0xFFFFU<<0)
#define TIMER0_CAR_CARL_0           (0x1U<<0)

// CREP Configuration

#define TIMER0_CREP_CREP            (0xFFU<<0)
#define TIMER0_CREP_CREP_0          (0x1U<<0)

// CH0CV Configuration

#define TIMER0_CH0CV_CH0VAL         (0xFFFFU<<0)
#define TIMER0_CH0CV_CH0VAL_0       (0x1U<<0)

// CH1CV Configuration

#define TIMER0_CH1CV_CH1VAL         (0xFFFFU<<0)
#define TIMER0_CH1CV_CH1VAL_0       (0x1U<<0)

// CH2CV Configuration

#define TIMER0_CH2CV_CH2VAL         (0xFFFFU<<0)
#define TIMER0_CH2CV_CH2VAL_0       (0x1U<<0)

// CH3CV Configuration

#define TIMER0_CH3CV_CH3VAL         (0xFFFFU<<0)
#define TIMER0_CH3CV_CH3VAL_0       (0x1U<<0)

// CCHP Configuration

#define TIMER0_CCHP_DTCFG           (0xFFU<<0)
#define TIMER0_CCHP_DTCFG_0         (0x1U<<0)
#define TIMER0_CCHP_PROT            (0x3U<<8)
#define TIMER0_CCHP_PROT_0          (0x1U<<8)
#define TIMER0_CCHP_IOS             (0x1U<<10)
#define TIMER0_CCHP_ROS             (0x1U<<11)
#define TIMER0_CCHP_BRKEN           (0x1U<<12)
#define TIMER0_CCHP_BRKP            (0x1U<<13)
#define TIMER0_CCHP_OAEN            (0x1U<<14)
#define TIMER0_CCHP_POEN            (0x1U<<15)

// DMACFG Configuration

#define TIMER0_DMACFG_DMATA         (0x1FU<<0)
#define TIMER0_DMACFG_DMATA_0       (0x1U<<0)
#define TIMER0_DMACFG_DMATC         (0x1FU<<8)
#define TIMER0_DMACFG_DMATC_0       (0x1U<<8)

// DMATB Configuration

#define TIMER0_DMATB_DMATB          (0xFFFFU<<0)
#define TIMER0_DMATB_DMATB_0        (0x1U<<0)
