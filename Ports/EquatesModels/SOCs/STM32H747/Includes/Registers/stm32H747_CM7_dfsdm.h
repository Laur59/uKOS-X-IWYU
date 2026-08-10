/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H747_CM7_dfsdm equates.
 */

#pragma once

#include    <stdint.h>

// DFSDM address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    CH0CFGR1;
    volatile    uint32_t    CH0CFGR2;
    volatile    uint32_t    CH0AWSCDR;
    volatile    uint32_t    CH0WDATR;
    volatile    uint32_t    CH0DATINR;
    volatile    uint32_t    CH0DLYR;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    CH1CFGR1;
    volatile    uint32_t    CH1CFGR2;
    volatile    uint32_t    CH1AWSCDR;
    volatile    uint32_t    CH1WDATR;
    volatile    uint32_t    CH1DATINR;
    volatile    uint32_t    CH1DLYR;
    volatile    uint32_t    RESERVED1[2];
    volatile    uint32_t    CH2CFGR1;
    volatile    uint32_t    CH2CFGR2;
    volatile    uint32_t    CH2AWSCDR;
    volatile    uint32_t    CH2WDATR;
    volatile    uint32_t    CH2DATINR;
    volatile    uint32_t    CH2DLYR;
    volatile    uint32_t    RESERVED2[2];
    volatile    uint32_t    CH3CFGR1;
    volatile    uint32_t    CH3CFGR2;
    volatile    uint32_t    CH3AWSCDR;
    volatile    uint32_t    CH3WDATR;
    volatile    uint32_t    CH3DATINR;
    volatile    uint32_t    CH3DLYR;
    volatile    uint32_t    RESERVED3[2];
    volatile    uint32_t    CH4CFGR1;
    volatile    uint32_t    CH4CFGR2;
    volatile    uint32_t    CH4AWSCDR;
    volatile    uint32_t    CH4WDATR;
    volatile    uint32_t    CH4DATINR;
    volatile    uint32_t    CH4DLYR;
    volatile    uint32_t    RESERVED4[2];
    volatile    uint32_t    CH5CFGR1;
    volatile    uint32_t    CH5CFGR2;
    volatile    uint32_t    CH5AWSCDR;
    volatile    uint32_t    CH5WDATR;
    volatile    uint32_t    CH5DATINR;
    volatile    uint32_t    CH5DLYR;
    volatile    uint32_t    RESERVED5[2];
    volatile    uint32_t    CH6CFGR1;
    volatile    uint32_t    CH6CFGR2;
    volatile    uint32_t    CH6AWSCDR;
    volatile    uint32_t    CH6WDATR;
    volatile    uint32_t    CH6DATINR;
    volatile    uint32_t    CH6DLYR;
    volatile    uint32_t    RESERVED6[2];
    volatile    uint32_t    CH7CFGR1;
    volatile    uint32_t    CH7CFGR2;
    volatile    uint32_t    CH7AWSCDR;
    volatile    uint32_t    CH7WDATR;
    volatile    uint32_t    CH7DATINR;
    volatile    uint32_t    CH7DLYR;
    volatile    uint32_t    RESERVED7[2];
    volatile    uint32_t    FLT0CR1;
    volatile    uint32_t    FLT0CR2;
    volatile    uint32_t    FLT0ISR;
    volatile    uint32_t    FLT0ICR;
    volatile    uint32_t    FLT0JCHGR;
    volatile    uint32_t    FLT0FCR;
    volatile    uint32_t    FLT0JDATAR;
    volatile    uint32_t    FLT0RDATAR;
    volatile    uint32_t    FLT0AWHTR;
    volatile    uint32_t    FLT0AWLTR;
    volatile    uint32_t    FLT0AWSR;
    volatile    uint32_t    FLT0AWCFR;
    volatile    uint32_t    FLT0EXMAX;
    volatile    uint32_t    FLT0EXMIN;
    volatile    uint32_t    FLT0CNVTIMR;
    volatile    uint32_t    RESERVED8[17];
    volatile    uint32_t    FLT1CR1;
    volatile    uint32_t    FLT1CR2;
    volatile    uint32_t    FLT1ISR;
    volatile    uint32_t    FLT1ICR;
    volatile    uint32_t    FLT1CHGR;
    volatile    uint32_t    FLT1FCR;
    volatile    uint32_t    FLT1JDATAR;
    volatile    uint32_t    FLT1RDATAR;
    volatile    uint32_t    FLT1AWHTR;
    volatile    uint32_t    FLT1AWLTR;
    volatile    uint32_t    FLT1AWSR;
    volatile    uint32_t    FLT1AWCFR;
    volatile    uint32_t    FLT1EXMAX;
    volatile    uint32_t    FLT1EXMIN;
    volatile    uint32_t    FLT1CNVTIMR;
    volatile    uint32_t    RESERVED9[17];
    volatile    uint32_t    FLT2CR1;
    volatile    uint32_t    FLT2CR2;
    volatile    uint32_t    FLT2ISR;
    volatile    uint32_t    FLT2ICR;
    volatile    uint32_t    FLT2JCHGR;
    volatile    uint32_t    FLT2FCR;
    volatile    uint32_t    FLT2JDATAR;
    volatile    uint32_t    FLT2RDATAR;
    volatile    uint32_t    FLT2AWHTR;
    volatile    uint32_t    FLT2AWLTR;
    volatile    uint32_t    FLT2AWSR;
    volatile    uint32_t    FLT2AWCFR;
    volatile    uint32_t    FLT2EXMAX;
    volatile    uint32_t    FLT2EXMIN;
    volatile    uint32_t    FLT2CNVTIMR;
    volatile    uint32_t    RESERVED10[17];
    volatile    uint32_t    FLT3CR1;
    volatile    uint32_t    FLT3CR2;
    volatile    uint32_t    FLT3ISR;
    volatile    uint32_t    FLT3ICR;
    volatile    uint32_t    FLT3JCHGR;
    volatile    uint32_t    FLT3FCR;
    volatile    uint32_t    FLT3JDATAR;
    volatile    uint32_t    FLT3RDATAR;
    volatile    uint32_t    FLT3AWHTR;
    volatile    uint32_t    FLT3AWLTR;
    volatile    uint32_t    FLT3AWSR;
    volatile    uint32_t    FLT3AWCFR;
    volatile    uint32_t    FLT3EXMAX;
    volatile    uint32_t    FLT3EXMIN;
    volatile    uint32_t    FLT3CNVTIMR;
} DFSDM_TypeDef;

#ifdef __cplusplus
#define DFSDM   reinterpret_cast<DFSDM_TypeDef *>(0x40017000U)

#else
#define DFSDM   ((DFSDM_TypeDef *)0x40017000U)
#endif

// CH0CFGR1 Configuration

#define DFSDM_CH0CFGR1_SITP         (0x3U<<0U)
#define DFSDM_CH0CFGR1_SITP_0       (0x1U<<0U)
#define DFSDM_CH0CFGR1_SPICKSEL     (0x3U<<2U)
#define DFSDM_CH0CFGR1_SPICKSEL_0   (0x1U<<2U)
#define DFSDM_CH0CFGR1_SCDEN        (0x1U<<5U)
#define DFSDM_CH0CFGR1_CKABEN       (0x1U<<6U)
#define DFSDM_CH0CFGR1_CHEN         (0x1U<<7U)
#define DFSDM_CH0CFGR1_CHINSEL      (0x1U<<8U)
#define DFSDM_CH0CFGR1_DATMPX       (0x3U<<12U)
#define DFSDM_CH0CFGR1_DATMPX_0     (0x1U<<12U)
#define DFSDM_CH0CFGR1_DATPACK      (0x3U<<14U)
#define DFSDM_CH0CFGR1_DATPACK_0    (0x1U<<14U)
#define DFSDM_CH0CFGR1_CKOUTDIV     (0xFFU<<16U)
#define DFSDM_CH0CFGR1_CKOUTDIV_0   (0x1U<<16U)
#define DFSDM_CH0CFGR1_CKOUTSRC     (0x1U<<30U)
#define DFSDM_CH0CFGR1_DFSDMEN      (0x1U<<31U)

// CH0CFGR2 Configuration

#define DFSDM_CH0CFGR2_DTRBS        (0x1FU<<3U)
#define DFSDM_CH0CFGR2_DTRBS_0      (0x1U<<3U)
#define DFSDM_CH0CFGR2_OFFSET       (0xFFFFFFU<<8U)
#define DFSDM_CH0CFGR2_OFFSET_0     (0x1U<<8U)

// CH0AWSCDR Configuration

#define DFSDM_CH0AWSCDR_SCDT        (0xFFU<<0U)
#define DFSDM_CH0AWSCDR_SCDT_0      (0x1U<<0U)
#define DFSDM_CH0AWSCDR_BKSCD       (0xFU<<12U)
#define DFSDM_CH0AWSCDR_BKSCD_0     (0x1U<<12U)
#define DFSDM_CH0AWSCDR_AWFOSR      (0x1FU<<16U)
#define DFSDM_CH0AWSCDR_AWFOSR_0    (0x1U<<16U)
#define DFSDM_CH0AWSCDR_AWFORD      (0x3U<<22U)
#define DFSDM_CH0AWSCDR_AWFORD_0    (0x1U<<22U)

// CH0WDATR Configuration

#define DFSDM_CH0WDATR_WDATA        (0xFFFFU<<0U)
#define DFSDM_CH0WDATR_WDATA_0      (0x1U<<0U)

// CH0DATINR Configuration

#define DFSDM_CH0DATINR_INDAT0      (0xFFFFU<<0U)
#define DFSDM_CH0DATINR_INDAT0_0    (0x1U<<0U)
#define DFSDM_CH0DATINR_INDAT1      (0xFFFFU<<16U)
#define DFSDM_CH0DATINR_INDAT1_0    (0x1U<<16U)

// CH0DLYR Configuration

#define DFSDM_CH0DLYR_PLSSKP        (0x3FU<<0U)
#define DFSDM_CH0DLYR_PLSSKP_0      (0x1U<<0U)

// CH1CFGR1 Configuration

#define DFSDM_CH1CFGR1_SITP         (0x3U<<0U)
#define DFSDM_CH1CFGR1_SITP_0       (0x1U<<0U)
#define DFSDM_CH1CFGR1_SPICKSEL     (0x3U<<2U)
#define DFSDM_CH1CFGR1_SPICKSEL_0   (0x1U<<2U)
#define DFSDM_CH1CFGR1_SCDEN        (0x1U<<5U)
#define DFSDM_CH1CFGR1_CKABEN       (0x1U<<6U)
#define DFSDM_CH1CFGR1_CHEN         (0x1U<<7U)
#define DFSDM_CH1CFGR1_CHINSEL      (0x1U<<8U)
#define DFSDM_CH1CFGR1_DATMPX       (0x3U<<12U)
#define DFSDM_CH1CFGR1_DATMPX_0     (0x1U<<12U)
#define DFSDM_CH1CFGR1_DATPACK      (0x3U<<14U)
#define DFSDM_CH1CFGR1_DATPACK_0    (0x1U<<14U)

// CH1CFGR2 Configuration

#define DFSDM_CH1CFGR2_DTRBS        (0x1FU<<3U)
#define DFSDM_CH1CFGR2_DTRBS_0      (0x1U<<3U)
#define DFSDM_CH1CFGR2_OFFSET       (0xFFFFFFU<<8U)
#define DFSDM_CH1CFGR2_OFFSET_0     (0x1U<<8U)

// CH1AWSCDR Configuration

#define DFSDM_CH1AWSCDR_SCDT        (0xFFU<<0U)
#define DFSDM_CH1AWSCDR_SCDT_0      (0x1U<<0U)
#define DFSDM_CH1AWSCDR_BKSCD       (0xFU<<12U)
#define DFSDM_CH1AWSCDR_BKSCD_0     (0x1U<<12U)
#define DFSDM_CH1AWSCDR_AWFOSR      (0x1FU<<16U)
#define DFSDM_CH1AWSCDR_AWFOSR_0    (0x1U<<16U)
#define DFSDM_CH1AWSCDR_AWFORD      (0x3U<<22U)
#define DFSDM_CH1AWSCDR_AWFORD_0    (0x1U<<22U)

// CH1WDATR Configuration

#define DFSDM_CH1WDATR_WDATA        (0xFFFFU<<0U)
#define DFSDM_CH1WDATR_WDATA_0      (0x1U<<0U)

// CH1DATINR Configuration

#define DFSDM_CH1DATINR_INDAT0      (0xFFFFU<<0U)
#define DFSDM_CH1DATINR_INDAT0_0    (0x1U<<0U)
#define DFSDM_CH1DATINR_INDAT1      (0xFFFFU<<16U)
#define DFSDM_CH1DATINR_INDAT1_0    (0x1U<<16U)

// CH1DLYR Configuration

#define DFSDM_CH1DLYR_PLSSKP        (0x3FU<<0U)
#define DFSDM_CH1DLYR_PLSSKP_0      (0x1U<<0U)

// CH2CFGR1 Configuration

#define DFSDM_CH2CFGR1_SITP         (0x3U<<0U)
#define DFSDM_CH2CFGR1_SITP_0       (0x1U<<0U)
#define DFSDM_CH2CFGR1_SPICKSEL     (0x3U<<2U)
#define DFSDM_CH2CFGR1_SPICKSEL_0   (0x1U<<2U)
#define DFSDM_CH2CFGR1_SCDEN        (0x1U<<5U)
#define DFSDM_CH2CFGR1_CKABEN       (0x1U<<6U)
#define DFSDM_CH2CFGR1_CHEN         (0x1U<<7U)
#define DFSDM_CH2CFGR1_CHINSEL      (0x1U<<8U)
#define DFSDM_CH2CFGR1_DATMPX       (0x3U<<12U)
#define DFSDM_CH2CFGR1_DATMPX_0     (0x1U<<12U)
#define DFSDM_CH2CFGR1_DATPACK      (0x3U<<14U)
#define DFSDM_CH2CFGR1_DATPACK_0    (0x1U<<14U)

// CH2CFGR2 Configuration

#define DFSDM_CH2CFGR2_DTRBS        (0x1FU<<3U)
#define DFSDM_CH2CFGR2_DTRBS_0      (0x1U<<3U)
#define DFSDM_CH2CFGR2_OFFSET       (0xFFFFFFU<<8U)
#define DFSDM_CH2CFGR2_OFFSET_0     (0x1U<<8U)

// CH2AWSCDR Configuration

#define DFSDM_CH2AWSCDR_SCDT        (0xFFU<<0U)
#define DFSDM_CH2AWSCDR_SCDT_0      (0x1U<<0U)
#define DFSDM_CH2AWSCDR_BKSCD       (0xFU<<12U)
#define DFSDM_CH2AWSCDR_BKSCD_0     (0x1U<<12U)
#define DFSDM_CH2AWSCDR_AWFOSR      (0x1FU<<16U)
#define DFSDM_CH2AWSCDR_AWFOSR_0    (0x1U<<16U)
#define DFSDM_CH2AWSCDR_AWFORD      (0x3U<<22U)
#define DFSDM_CH2AWSCDR_AWFORD_0    (0x1U<<22U)

// CH2WDATR Configuration

#define DFSDM_CH2WDATR_WDATA        (0xFFFFU<<0U)
#define DFSDM_CH2WDATR_WDATA_0      (0x1U<<0U)

// CH2DATINR Configuration

#define DFSDM_CH2DATINR_INDAT0      (0xFFFFU<<0U)
#define DFSDM_CH2DATINR_INDAT0_0    (0x1U<<0U)
#define DFSDM_CH2DATINR_INDAT1      (0xFFFFU<<16U)
#define DFSDM_CH2DATINR_INDAT1_0    (0x1U<<16U)

// CH2DLYR Configuration

#define DFSDM_CH2DLYR_PLSSKP        (0x3FU<<0U)
#define DFSDM_CH2DLYR_PLSSKP_0      (0x1U<<0U)

// CH3CFGR1 Configuration

#define DFSDM_CH3CFGR1_SITP         (0x3U<<0U)
#define DFSDM_CH3CFGR1_SITP_0       (0x1U<<0U)
#define DFSDM_CH3CFGR1_SPICKSEL     (0x3U<<2U)
#define DFSDM_CH3CFGR1_SPICKSEL_0   (0x1U<<2U)
#define DFSDM_CH3CFGR1_SCDEN        (0x1U<<5U)
#define DFSDM_CH3CFGR1_CKABEN       (0x1U<<6U)
#define DFSDM_CH3CFGR1_CHEN         (0x1U<<7U)
#define DFSDM_CH3CFGR1_CHINSEL      (0x1U<<8U)
#define DFSDM_CH3CFGR1_DATMPX       (0x3U<<12U)
#define DFSDM_CH3CFGR1_DATMPX_0     (0x1U<<12U)
#define DFSDM_CH3CFGR1_DATPACK      (0x3U<<14U)
#define DFSDM_CH3CFGR1_DATPACK_0    (0x1U<<14U)

// CH3CFGR2 Configuration

#define DFSDM_CH3CFGR2_DTRBS        (0x1FU<<3U)
#define DFSDM_CH3CFGR2_DTRBS_0      (0x1U<<3U)
#define DFSDM_CH3CFGR2_OFFSET       (0xFFFFFFU<<8U)
#define DFSDM_CH3CFGR2_OFFSET_0     (0x1U<<8U)

// CH3AWSCDR Configuration

#define DFSDM_CH3AWSCDR_SCDT        (0xFFU<<0U)
#define DFSDM_CH3AWSCDR_SCDT_0      (0x1U<<0U)
#define DFSDM_CH3AWSCDR_BKSCD       (0xFU<<12U)
#define DFSDM_CH3AWSCDR_BKSCD_0     (0x1U<<12U)
#define DFSDM_CH3AWSCDR_AWFOSR      (0x1FU<<16U)
#define DFSDM_CH3AWSCDR_AWFOSR_0    (0x1U<<16U)
#define DFSDM_CH3AWSCDR_AWFORD      (0x3U<<22U)
#define DFSDM_CH3AWSCDR_AWFORD_0    (0x1U<<22U)

// CH3WDATR Configuration

#define DFSDM_CH3WDATR_WDATA        (0xFFFFU<<0U)
#define DFSDM_CH3WDATR_WDATA_0      (0x1U<<0U)

// CH3DATINR Configuration

#define DFSDM_CH3DATINR_INDAT0      (0xFFFFU<<0U)
#define DFSDM_CH3DATINR_INDAT0_0    (0x1U<<0U)
#define DFSDM_CH3DATINR_INDAT1      (0xFFFFU<<16U)
#define DFSDM_CH3DATINR_INDAT1_0    (0x1U<<16U)

// CH3DLYR Configuration

#define DFSDM_CH3DLYR_PLSSKP        (0x3FU<<0U)
#define DFSDM_CH3DLYR_PLSSKP_0      (0x1U<<0U)

// CH4CFGR1 Configuration

#define DFSDM_CH4CFGR1_SITP         (0x3U<<0U)
#define DFSDM_CH4CFGR1_SITP_0       (0x1U<<0U)
#define DFSDM_CH4CFGR1_SPICKSEL     (0x3U<<2U)
#define DFSDM_CH4CFGR1_SPICKSEL_0   (0x1U<<2U)
#define DFSDM_CH4CFGR1_SCDEN        (0x1U<<5U)
#define DFSDM_CH4CFGR1_CKABEN       (0x1U<<6U)
#define DFSDM_CH4CFGR1_CHEN         (0x1U<<7U)
#define DFSDM_CH4CFGR1_CHINSEL      (0x1U<<8U)
#define DFSDM_CH4CFGR1_DATMPX       (0x3U<<12U)
#define DFSDM_CH4CFGR1_DATMPX_0     (0x1U<<12U)
#define DFSDM_CH4CFGR1_DATPACK      (0x3U<<14U)
#define DFSDM_CH4CFGR1_DATPACK_0    (0x1U<<14U)

// CH4CFGR2 Configuration

#define DFSDM_CH4CFGR2_DTRBS        (0x1FU<<3U)
#define DFSDM_CH4CFGR2_DTRBS_0      (0x1U<<3U)
#define DFSDM_CH4CFGR2_OFFSET       (0xFFFFFFU<<8U)
#define DFSDM_CH4CFGR2_OFFSET_0     (0x1U<<8U)

// CH4AWSCDR Configuration

#define DFSDM_CH4AWSCDR_SCDT        (0xFFU<<0U)
#define DFSDM_CH4AWSCDR_SCDT_0      (0x1U<<0U)
#define DFSDM_CH4AWSCDR_BKSCD       (0xFU<<12U)
#define DFSDM_CH4AWSCDR_BKSCD_0     (0x1U<<12U)
#define DFSDM_CH4AWSCDR_AWFOSR      (0x1FU<<16U)
#define DFSDM_CH4AWSCDR_AWFOSR_0    (0x1U<<16U)
#define DFSDM_CH4AWSCDR_AWFORD      (0x3U<<22U)
#define DFSDM_CH4AWSCDR_AWFORD_0    (0x1U<<22U)

// CH4WDATR Configuration

#define DFSDM_CH4WDATR_WDATA        (0xFFFFU<<0U)
#define DFSDM_CH4WDATR_WDATA_0      (0x1U<<0U)

// CH4DATINR Configuration

#define DFSDM_CH4DATINR_INDAT0      (0xFFFFU<<0U)
#define DFSDM_CH4DATINR_INDAT0_0    (0x1U<<0U)
#define DFSDM_CH4DATINR_INDAT1      (0xFFFFU<<16U)
#define DFSDM_CH4DATINR_INDAT1_0    (0x1U<<16U)

// CH4DLYR Configuration

#define DFSDM_CH4DLYR_PLSSKP        (0x3FU<<0U)
#define DFSDM_CH4DLYR_PLSSKP_0      (0x1U<<0U)

// CH5CFGR1 Configuration

#define DFSDM_CH5CFGR1_SITP         (0x3U<<0U)
#define DFSDM_CH5CFGR1_SITP_0       (0x1U<<0U)
#define DFSDM_CH5CFGR1_SPICKSEL     (0x3U<<2U)
#define DFSDM_CH5CFGR1_SPICKSEL_0   (0x1U<<2U)
#define DFSDM_CH5CFGR1_SCDEN        (0x1U<<5U)
#define DFSDM_CH5CFGR1_CKABEN       (0x1U<<6U)
#define DFSDM_CH5CFGR1_CHEN         (0x1U<<7U)
#define DFSDM_CH5CFGR1_CHINSEL      (0x1U<<8U)
#define DFSDM_CH5CFGR1_DATMPX       (0x3U<<12U)
#define DFSDM_CH5CFGR1_DATMPX_0     (0x1U<<12U)
#define DFSDM_CH5CFGR1_DATPACK      (0x3U<<14U)
#define DFSDM_CH5CFGR1_DATPACK_0    (0x1U<<14U)

// CH5CFGR2 Configuration

#define DFSDM_CH5CFGR2_DTRBS        (0x1FU<<3U)
#define DFSDM_CH5CFGR2_DTRBS_0      (0x1U<<3U)
#define DFSDM_CH5CFGR2_OFFSET       (0xFFFFFFU<<8U)
#define DFSDM_CH5CFGR2_OFFSET_0     (0x1U<<8U)

// CH5AWSCDR Configuration

#define DFSDM_CH5AWSCDR_SCDT        (0xFFU<<0U)
#define DFSDM_CH5AWSCDR_SCDT_0      (0x1U<<0U)
#define DFSDM_CH5AWSCDR_BKSCD       (0xFU<<12U)
#define DFSDM_CH5AWSCDR_BKSCD_0     (0x1U<<12U)
#define DFSDM_CH5AWSCDR_AWFOSR      (0x1FU<<16U)
#define DFSDM_CH5AWSCDR_AWFOSR_0    (0x1U<<16U)
#define DFSDM_CH5AWSCDR_AWFORD      (0x3U<<22U)
#define DFSDM_CH5AWSCDR_AWFORD_0    (0x1U<<22U)

// CH5WDATR Configuration

#define DFSDM_CH5WDATR_WDATA        (0xFFFFU<<0U)
#define DFSDM_CH5WDATR_WDATA_0      (0x1U<<0U)

// CH5DATINR Configuration

#define DFSDM_CH5DATINR_INDAT0      (0xFFFFU<<0U)
#define DFSDM_CH5DATINR_INDAT0_0    (0x1U<<0U)
#define DFSDM_CH5DATINR_INDAT1      (0xFFFFU<<16U)
#define DFSDM_CH5DATINR_INDAT1_0    (0x1U<<16U)

// CH5DLYR Configuration

#define DFSDM_CH5DLYR_PLSSKP        (0x3FU<<0U)
#define DFSDM_CH5DLYR_PLSSKP_0      (0x1U<<0U)

// CH6CFGR1 Configuration

#define DFSDM_CH6CFGR1_SITP         (0x3U<<0U)
#define DFSDM_CH6CFGR1_SITP_0       (0x1U<<0U)
#define DFSDM_CH6CFGR1_SPICKSEL     (0x3U<<2U)
#define DFSDM_CH6CFGR1_SPICKSEL_0   (0x1U<<2U)
#define DFSDM_CH6CFGR1_SCDEN        (0x1U<<5U)
#define DFSDM_CH6CFGR1_CKABEN       (0x1U<<6U)
#define DFSDM_CH6CFGR1_CHEN         (0x1U<<7U)
#define DFSDM_CH6CFGR1_CHINSEL      (0x1U<<8U)
#define DFSDM_CH6CFGR1_DATMPX       (0x3U<<12U)
#define DFSDM_CH6CFGR1_DATMPX_0     (0x1U<<12U)
#define DFSDM_CH6CFGR1_DATPACK      (0x3U<<14U)
#define DFSDM_CH6CFGR1_DATPACK_0    (0x1U<<14U)

// CH6CFGR2 Configuration

#define DFSDM_CH6CFGR2_DTRBS        (0x1FU<<3U)
#define DFSDM_CH6CFGR2_DTRBS_0      (0x1U<<3U)
#define DFSDM_CH6CFGR2_OFFSET       (0xFFFFFFU<<8U)
#define DFSDM_CH6CFGR2_OFFSET_0     (0x1U<<8U)

// CH6AWSCDR Configuration

#define DFSDM_CH6AWSCDR_SCDT        (0xFFU<<0U)
#define DFSDM_CH6AWSCDR_SCDT_0      (0x1U<<0U)
#define DFSDM_CH6AWSCDR_BKSCD       (0xFU<<12U)
#define DFSDM_CH6AWSCDR_BKSCD_0     (0x1U<<12U)
#define DFSDM_CH6AWSCDR_AWFOSR      (0x1FU<<16U)
#define DFSDM_CH6AWSCDR_AWFOSR_0    (0x1U<<16U)
#define DFSDM_CH6AWSCDR_AWFORD      (0x3U<<22U)
#define DFSDM_CH6AWSCDR_AWFORD_0    (0x1U<<22U)

// CH6WDATR Configuration

#define DFSDM_CH6WDATR_WDATA        (0xFFFFU<<0U)
#define DFSDM_CH6WDATR_WDATA_0      (0x1U<<0U)

// CH6DATINR Configuration

#define DFSDM_CH6DATINR_INDAT0      (0xFFFFU<<0U)
#define DFSDM_CH6DATINR_INDAT0_0    (0x1U<<0U)
#define DFSDM_CH6DATINR_INDAT1      (0xFFFFU<<16U)
#define DFSDM_CH6DATINR_INDAT1_0    (0x1U<<16U)

// CH6DLYR Configuration

#define DFSDM_CH6DLYR_PLSSKP        (0x3FU<<0U)
#define DFSDM_CH6DLYR_PLSSKP_0      (0x1U<<0U)

// CH7CFGR1 Configuration

#define DFSDM_CH7CFGR1_SITP         (0x3U<<0U)
#define DFSDM_CH7CFGR1_SITP_0       (0x1U<<0U)
#define DFSDM_CH7CFGR1_SPICKSEL     (0x3U<<2U)
#define DFSDM_CH7CFGR1_SPICKSEL_0   (0x1U<<2U)
#define DFSDM_CH7CFGR1_SCDEN        (0x1U<<5U)
#define DFSDM_CH7CFGR1_CKABEN       (0x1U<<6U)
#define DFSDM_CH7CFGR1_CHEN         (0x1U<<7U)
#define DFSDM_CH7CFGR1_CHINSEL      (0x1U<<8U)
#define DFSDM_CH7CFGR1_DATMPX       (0x3U<<12U)
#define DFSDM_CH7CFGR1_DATMPX_0     (0x1U<<12U)
#define DFSDM_CH7CFGR1_DATPACK      (0x3U<<14U)
#define DFSDM_CH7CFGR1_DATPACK_0    (0x1U<<14U)

// CH7CFGR2 Configuration

#define DFSDM_CH7CFGR2_DTRBS        (0x1FU<<3U)
#define DFSDM_CH7CFGR2_DTRBS_0      (0x1U<<3U)
#define DFSDM_CH7CFGR2_OFFSET       (0xFFFFFFU<<8U)
#define DFSDM_CH7CFGR2_OFFSET_0     (0x1U<<8U)

// CH7AWSCDR Configuration

#define DFSDM_CH7AWSCDR_SCDT        (0xFFU<<0U)
#define DFSDM_CH7AWSCDR_SCDT_0      (0x1U<<0U)
#define DFSDM_CH7AWSCDR_BKSCD       (0xFU<<12U)
#define DFSDM_CH7AWSCDR_BKSCD_0     (0x1U<<12U)
#define DFSDM_CH7AWSCDR_AWFOSR      (0x1FU<<16U)
#define DFSDM_CH7AWSCDR_AWFOSR_0    (0x1U<<16U)
#define DFSDM_CH7AWSCDR_AWFORD      (0x3U<<22U)
#define DFSDM_CH7AWSCDR_AWFORD_0    (0x1U<<22U)

// CH7WDATR Configuration

#define DFSDM_CH7WDATR_WDATA        (0xFFFFU<<0U)
#define DFSDM_CH7WDATR_WDATA_0      (0x1U<<0U)

// CH7DATINR Configuration

#define DFSDM_CH7DATINR_INDAT0      (0xFFFFU<<0U)
#define DFSDM_CH7DATINR_INDAT0_0    (0x1U<<0U)
#define DFSDM_CH7DATINR_INDAT1      (0xFFFFU<<16U)
#define DFSDM_CH7DATINR_INDAT1_0    (0x1U<<16U)

// CH7DLYR Configuration

#define DFSDM_CH7DLYR_PLSSKP        (0x3FU<<0U)
#define DFSDM_CH7DLYR_PLSSKP_0      (0x1U<<0U)

// FLT0CR1 Configuration

#define DFSDM_FLT0CR1_DFEN          (0x1U<<0U)
#define DFSDM_FLT0CR1_JSWSTART      (0x1U<<1U)
#define DFSDM_FLT0CR1_JSYNC         (0x1U<<3U)
#define DFSDM_FLT0CR1_JSCAN         (0x1U<<4U)
#define DFSDM_FLT0CR1_JDMAEN        (0x1U<<5U)
#define DFSDM_FLT0CR1_JEXTSEL       (0x7U<<8U)
#define DFSDM_FLT0CR1_JEXTSEL_0     (0x1U<<8U)
#define DFSDM_FLT0CR1_JEXTEN        (0x3U<<13U)
#define DFSDM_FLT0CR1_JEXTEN_0      (0x1U<<13U)
#define DFSDM_FLT0CR1_RSWSTART      (0x1U<<17U)
#define DFSDM_FLT0CR1_RCONT         (0x1U<<18U)
#define DFSDM_FLT0CR1_RSYNC         (0x1U<<19U)
#define DFSDM_FLT0CR1_RDMAEN        (0x1U<<21U)
#define DFSDM_FLT0CR1_RCH           (0x7U<<24U)
#define DFSDM_FLT0CR1_RCH_0         (0x1U<<24U)
#define DFSDM_FLT0CR1_FAST          (0x1U<<29U)
#define DFSDM_FLT0CR1_AWFSEL        (0x1U<<30U)

// FLT0CR2 Configuration

#define DFSDM_FLT0CR2_JEOCIE        (0x1U<<0U)
#define DFSDM_FLT0CR2_REOCIE        (0x1U<<1U)
#define DFSDM_FLT0CR2_JOVRIE        (0x1U<<2U)
#define DFSDM_FLT0CR2_ROVRIE        (0x1U<<3U)
#define DFSDM_FLT0CR2_AWDIE         (0x1U<<4U)
#define DFSDM_FLT0CR2_SCDIE         (0x1U<<5U)
#define DFSDM_FLT0CR2_CKABIE        (0x1U<<6U)
#define DFSDM_FLT0CR2_EXCH          (0xFFU<<8U)
#define DFSDM_FLT0CR2_EXCH_0        (0x1U<<8U)
#define DFSDM_FLT0CR2_AWDCH         (0xFFU<<16U)
#define DFSDM_FLT0CR2_AWDCH_0       (0x1U<<16U)

// FLT0ISR Configuration

#define DFSDM_FLT0ISR_JEOCF         (0x1U<<0U)
#define DFSDM_FLT0ISR_REOCF         (0x1U<<1U)
#define DFSDM_FLT0ISR_JOVRF         (0x1U<<2U)
#define DFSDM_FLT0ISR_ROVRF         (0x1U<<3U)
#define DFSDM_FLT0ISR_AWDF          (0x1U<<4U)
#define DFSDM_FLT0ISR_JCIP          (0x1U<<13U)
#define DFSDM_FLT0ISR_RCIP          (0x1U<<14U)
#define DFSDM_FLT0ISR_CKABF         (0xFFU<<16U)
#define DFSDM_FLT0ISR_CKABF_0       (0x1U<<16U)
#define DFSDM_FLT0ISR_SCDF          (0xFFU<<24U)
#define DFSDM_FLT0ISR_SCDF_0        (0x1U<<24U)

// FLT0ICR Configuration

#define DFSDM_FLT0ICR_CLRJOVRF      (0x1U<<2U)
#define DFSDM_FLT0ICR_CLRROVRF      (0x1U<<3U)
#define DFSDM_FLT0ICR_CLRCKABF      (0xFFU<<16U)
#define DFSDM_FLT0ICR_CLRCKABF_0    (0x1U<<16U)
#define DFSDM_FLT0ICR_CLRSCDF       (0xFFU<<24U)
#define DFSDM_FLT0ICR_CLRSCDF_0     (0x1U<<24U)

// FLT0JCHGR Configuration

#define DFSDM_FLT0JCHGR_JCHG        (0xFFU<<0U)
#define DFSDM_FLT0JCHGR_JCHG_0      (0x1U<<0U)

// FLT0FCR Configuration

#define DFSDM_FLT0FCR_IOSR          (0xFFU<<0U)
#define DFSDM_FLT0FCR_IOSR_0        (0x1U<<0U)
#define DFSDM_FLT0FCR_FOSR          (0x3FFU<<16U)
#define DFSDM_FLT0FCR_FOSR_0        (0x1U<<16U)
#define DFSDM_FLT0FCR_FORD          (0x7U<<29U)
#define DFSDM_FLT0FCR_FORD_0        (0x1U<<29U)

// FLT0JDATAR Configuration

#define DFSDM_FLT0JDATAR_JDATACH    (0x7U<<0U)
#define DFSDM_FLT0JDATAR_JDATACH_0  (0x1U<<0U)
#define DFSDM_FLT0JDATAR_JDATA      (0xFFFFFFU<<8U)
#define DFSDM_FLT0JDATAR_JDATA_0    (0x1U<<8U)

// FLT0RDATAR Configuration

#define DFSDM_FLT0RDATAR_RDATACH    (0x7U<<0U)
#define DFSDM_FLT0RDATAR_RDATACH_0  (0x1U<<0U)
#define DFSDM_FLT0RDATAR_RPEND      (0x1U<<4U)
#define DFSDM_FLT0RDATAR_RDATA      (0xFFFFFFU<<8U)
#define DFSDM_FLT0RDATAR_RDATA_0    (0x1U<<8U)

// FLT0AWHTR Configuration

#define DFSDM_FLT0AWHTR_BKAWH       (0xFU<<0U)
#define DFSDM_FLT0AWHTR_BKAWH_0     (0x1U<<0U)
#define DFSDM_FLT0AWHTR_AWHT        (0xFFFFFFU<<8U)
#define DFSDM_FLT0AWHTR_AWHT_0      (0x1U<<8U)

// FLT0AWLTR Configuration

#define DFSDM_FLT0AWLTR_BKAWL       (0xFU<<0U)
#define DFSDM_FLT0AWLTR_BKAWL_0     (0x1U<<0U)
#define DFSDM_FLT0AWLTR_AWLT        (0xFFFFFFU<<8U)
#define DFSDM_FLT0AWLTR_AWLT_0      (0x1U<<8U)

// FLT0AWSR Configuration

#define DFSDM_FLT0AWSR_AWLTF        (0xFFU<<0U)
#define DFSDM_FLT0AWSR_AWLTF_0      (0x1U<<0U)
#define DFSDM_FLT0AWSR_AWHTF        (0xFFU<<8U)
#define DFSDM_FLT0AWSR_AWHTF_0      (0x1U<<8U)

// FLT0AWCFR Configuration

#define DFSDM_FLT0AWCFR_CLRAWLTF    (0xFFU<<0U)
#define DFSDM_FLT0AWCFR_CLRAWLTF_0  (0x1U<<0U)
#define DFSDM_FLT0AWCFR_CLRAWHTF    (0xFFU<<8U)
#define DFSDM_FLT0AWCFR_CLRAWHTF_0  (0x1U<<8U)

// FLT0EXMAX Configuration

#define DFSDM_FLT0EXMAX_EXMAXCH     (0x7U<<0U)
#define DFSDM_FLT0EXMAX_EXMAXCH_0   (0x1U<<0U)
#define DFSDM_FLT0EXMAX_EXMAX       (0xFFFFFFU<<8U)
#define DFSDM_FLT0EXMAX_EXMAX_0     (0x1U<<8U)

// FLT0EXMIN Configuration

#define DFSDM_FLT0EXMIN_EXMINCH     (0x7U<<0U)
#define DFSDM_FLT0EXMIN_EXMINCH_0   (0x1U<<0U)
#define DFSDM_FLT0EXMIN_EXMIN       (0xFFFFFFU<<8U)
#define DFSDM_FLT0EXMIN_EXMIN_0     (0x1U<<8U)

// FLT0CNVTIMR Configuration

#define DFSDM_FLT0CNVTIMR_CNVCNT    (0xFFFFFFFU<<4U)
#define DFSDM_FLT0CNVTIMR_CNVCNT_0  (0x1U<<4U)

// FLT1CR1 Configuration

#define DFSDM_FLT1CR1_DFEN          (0x1U<<0U)
#define DFSDM_FLT1CR1_JSWSTART      (0x1U<<1U)
#define DFSDM_FLT1CR1_JSYNC         (0x1U<<3U)
#define DFSDM_FLT1CR1_JSCAN         (0x1U<<4U)
#define DFSDM_FLT1CR1_JDMAEN        (0x1U<<5U)
#define DFSDM_FLT1CR1_JEXTSEL       (0x7U<<8U)
#define DFSDM_FLT1CR1_JEXTSEL_0     (0x1U<<8U)
#define DFSDM_FLT1CR1_JEXTEN        (0x3U<<13U)
#define DFSDM_FLT1CR1_JEXTEN_0      (0x1U<<13U)
#define DFSDM_FLT1CR1_RSWSTART      (0x1U<<17U)
#define DFSDM_FLT1CR1_RCONT         (0x1U<<18U)
#define DFSDM_FLT1CR1_RSYNC         (0x1U<<19U)
#define DFSDM_FLT1CR1_RDMAEN        (0x1U<<21U)
#define DFSDM_FLT1CR1_RCH           (0x7U<<24U)
#define DFSDM_FLT1CR1_RCH_0         (0x1U<<24U)
#define DFSDM_FLT1CR1_FAST          (0x1U<<29U)
#define DFSDM_FLT1CR1_AWFSEL        (0x1U<<30U)

// FLT1CR2 Configuration

#define DFSDM_FLT1CR2_JEOCIE        (0x1U<<0U)
#define DFSDM_FLT1CR2_REOCIE        (0x1U<<1U)
#define DFSDM_FLT1CR2_JOVRIE        (0x1U<<2U)
#define DFSDM_FLT1CR2_ROVRIE        (0x1U<<3U)
#define DFSDM_FLT1CR2_AWDIE         (0x1U<<4U)
#define DFSDM_FLT1CR2_SCDIE         (0x1U<<5U)
#define DFSDM_FLT1CR2_CKABIE        (0x1U<<6U)
#define DFSDM_FLT1CR2_EXCH          (0xFFU<<8U)
#define DFSDM_FLT1CR2_EXCH_0        (0x1U<<8U)
#define DFSDM_FLT1CR2_AWDCH         (0xFFU<<16U)
#define DFSDM_FLT1CR2_AWDCH_0       (0x1U<<16U)

// FLT1ISR Configuration

#define DFSDM_FLT1ISR_JEOCF         (0x1U<<0U)
#define DFSDM_FLT1ISR_REOCF         (0x1U<<1U)
#define DFSDM_FLT1ISR_JOVRF         (0x1U<<2U)
#define DFSDM_FLT1ISR_ROVRF         (0x1U<<3U)
#define DFSDM_FLT1ISR_AWDF          (0x1U<<4U)
#define DFSDM_FLT1ISR_JCIP          (0x1U<<13U)
#define DFSDM_FLT1ISR_RCIP          (0x1U<<14U)
#define DFSDM_FLT1ISR_CKABF         (0xFFU<<16U)
#define DFSDM_FLT1ISR_CKABF_0       (0x1U<<16U)
#define DFSDM_FLT1ISR_SCDF          (0xFFU<<24U)
#define DFSDM_FLT1ISR_SCDF_0        (0x1U<<24U)

// FLT1ICR Configuration

#define DFSDM_FLT1ICR_CLRJOVRF      (0x1U<<2U)
#define DFSDM_FLT1ICR_CLRROVRF      (0x1U<<3U)
#define DFSDM_FLT1ICR_CLRCKABF      (0xFFU<<16U)
#define DFSDM_FLT1ICR_CLRCKABF_0    (0x1U<<16U)
#define DFSDM_FLT1ICR_CLRSCDF       (0xFFU<<24U)
#define DFSDM_FLT1ICR_CLRSCDF_0     (0x1U<<24U)

// FLT1CHGR Configuration

#define DFSDM_FLT1CHGR_JCHG         (0xFFU<<0U)
#define DFSDM_FLT1CHGR_JCHG_0       (0x1U<<0U)

// FLT1FCR Configuration

#define DFSDM_FLT1FCR_IOSR          (0xFFU<<0U)
#define DFSDM_FLT1FCR_IOSR_0        (0x1U<<0U)
#define DFSDM_FLT1FCR_FOSR          (0x3FFU<<16U)
#define DFSDM_FLT1FCR_FOSR_0        (0x1U<<16U)
#define DFSDM_FLT1FCR_FORD          (0x7U<<29U)
#define DFSDM_FLT1FCR_FORD_0        (0x1U<<29U)

// FLT1JDATAR Configuration

#define DFSDM_FLT1JDATAR_JDATACH    (0x7U<<0U)
#define DFSDM_FLT1JDATAR_JDATACH_0  (0x1U<<0U)
#define DFSDM_FLT1JDATAR_JDATA      (0xFFFFFFU<<8U)
#define DFSDM_FLT1JDATAR_JDATA_0    (0x1U<<8U)

// FLT1RDATAR Configuration

#define DFSDM_FLT1RDATAR_RDATACH    (0x7U<<0U)
#define DFSDM_FLT1RDATAR_RDATACH_0  (0x1U<<0U)
#define DFSDM_FLT1RDATAR_RPEND      (0x1U<<4U)
#define DFSDM_FLT1RDATAR_RDATA      (0xFFFFFFU<<8U)
#define DFSDM_FLT1RDATAR_RDATA_0    (0x1U<<8U)

// FLT1AWHTR Configuration

#define DFSDM_FLT1AWHTR_BKAWH       (0xFU<<0U)
#define DFSDM_FLT1AWHTR_BKAWH_0     (0x1U<<0U)
#define DFSDM_FLT1AWHTR_AWHT        (0xFFFFFFU<<8U)
#define DFSDM_FLT1AWHTR_AWHT_0      (0x1U<<8U)

// FLT1AWLTR Configuration

#define DFSDM_FLT1AWLTR_BKAWL       (0xFU<<0U)
#define DFSDM_FLT1AWLTR_BKAWL_0     (0x1U<<0U)
#define DFSDM_FLT1AWLTR_AWLT        (0xFFFFFFU<<8U)
#define DFSDM_FLT1AWLTR_AWLT_0      (0x1U<<8U)

// FLT1AWSR Configuration

#define DFSDM_FLT1AWSR_AWLTF        (0xFFU<<0U)
#define DFSDM_FLT1AWSR_AWLTF_0      (0x1U<<0U)
#define DFSDM_FLT1AWSR_AWHTF        (0xFFU<<8U)
#define DFSDM_FLT1AWSR_AWHTF_0      (0x1U<<8U)

// FLT1AWCFR Configuration

#define DFSDM_FLT1AWCFR_CLRAWLTF    (0xFFU<<0U)
#define DFSDM_FLT1AWCFR_CLRAWLTF_0  (0x1U<<0U)
#define DFSDM_FLT1AWCFR_CLRAWHTF    (0xFFU<<8U)
#define DFSDM_FLT1AWCFR_CLRAWHTF_0  (0x1U<<8U)

// FLT1EXMAX Configuration

#define DFSDM_FLT1EXMAX_EXMAXCH     (0x7U<<0U)
#define DFSDM_FLT1EXMAX_EXMAXCH_0   (0x1U<<0U)
#define DFSDM_FLT1EXMAX_EXMAX       (0xFFFFFFU<<8U)
#define DFSDM_FLT1EXMAX_EXMAX_0     (0x1U<<8U)

// FLT1EXMIN Configuration

#define DFSDM_FLT1EXMIN_EXMINCH     (0x7U<<0U)
#define DFSDM_FLT1EXMIN_EXMINCH_0   (0x1U<<0U)
#define DFSDM_FLT1EXMIN_EXMIN       (0xFFFFFFU<<8U)
#define DFSDM_FLT1EXMIN_EXMIN_0     (0x1U<<8U)

// FLT1CNVTIMR Configuration

#define DFSDM_FLT1CNVTIMR_CNVCNT    (0xFFFFFFFU<<4U)
#define DFSDM_FLT1CNVTIMR_CNVCNT_0  (0x1U<<4U)

// FLT2CR1 Configuration

#define DFSDM_FLT2CR1_DFEN          (0x1U<<0U)
#define DFSDM_FLT2CR1_JSWSTART      (0x1U<<1U)
#define DFSDM_FLT2CR1_JSYNC         (0x1U<<3U)
#define DFSDM_FLT2CR1_JSCAN         (0x1U<<4U)
#define DFSDM_FLT2CR1_JDMAEN        (0x1U<<5U)
#define DFSDM_FLT2CR1_JEXTSEL       (0x7U<<8U)
#define DFSDM_FLT2CR1_JEXTSEL_0     (0x1U<<8U)
#define DFSDM_FLT2CR1_JEXTEN        (0x3U<<13U)
#define DFSDM_FLT2CR1_JEXTEN_0      (0x1U<<13U)
#define DFSDM_FLT2CR1_RSWSTART      (0x1U<<17U)
#define DFSDM_FLT2CR1_RCONT         (0x1U<<18U)
#define DFSDM_FLT2CR1_RSYNC         (0x1U<<19U)
#define DFSDM_FLT2CR1_RDMAEN        (0x1U<<21U)
#define DFSDM_FLT2CR1_RCH           (0x7U<<24U)
#define DFSDM_FLT2CR1_RCH_0         (0x1U<<24U)
#define DFSDM_FLT2CR1_FAST          (0x1U<<29U)
#define DFSDM_FLT2CR1_AWFSEL        (0x1U<<30U)

// FLT2CR2 Configuration

#define DFSDM_FLT2CR2_JEOCIE        (0x1U<<0U)
#define DFSDM_FLT2CR2_REOCIE        (0x1U<<1U)
#define DFSDM_FLT2CR2_JOVRIE        (0x1U<<2U)
#define DFSDM_FLT2CR2_ROVRIE        (0x1U<<3U)
#define DFSDM_FLT2CR2_AWDIE         (0x1U<<4U)
#define DFSDM_FLT2CR2_SCDIE         (0x1U<<5U)
#define DFSDM_FLT2CR2_CKABIE        (0x1U<<6U)
#define DFSDM_FLT2CR2_EXCH          (0xFFU<<8U)
#define DFSDM_FLT2CR2_EXCH_0        (0x1U<<8U)
#define DFSDM_FLT2CR2_AWDCH         (0xFFU<<16U)
#define DFSDM_FLT2CR2_AWDCH_0       (0x1U<<16U)

// FLT2ISR Configuration

#define DFSDM_FLT2ISR_JEOCF         (0x1U<<0U)
#define DFSDM_FLT2ISR_REOCF         (0x1U<<1U)
#define DFSDM_FLT2ISR_JOVRF         (0x1U<<2U)
#define DFSDM_FLT2ISR_ROVRF         (0x1U<<3U)
#define DFSDM_FLT2ISR_AWDF          (0x1U<<4U)
#define DFSDM_FLT2ISR_JCIP          (0x1U<<13U)
#define DFSDM_FLT2ISR_RCIP          (0x1U<<14U)
#define DFSDM_FLT2ISR_CKABF         (0xFFU<<16U)
#define DFSDM_FLT2ISR_CKABF_0       (0x1U<<16U)
#define DFSDM_FLT2ISR_SCDF          (0xFFU<<24U)
#define DFSDM_FLT2ISR_SCDF_0        (0x1U<<24U)

// FLT2ICR Configuration

#define DFSDM_FLT2ICR_CLRJOVRF      (0x1U<<2U)
#define DFSDM_FLT2ICR_CLRROVRF      (0x1U<<3U)
#define DFSDM_FLT2ICR_CLRCKABF      (0xFFU<<16U)
#define DFSDM_FLT2ICR_CLRCKABF_0    (0x1U<<16U)
#define DFSDM_FLT2ICR_CLRSCDF       (0xFFU<<24U)
#define DFSDM_FLT2ICR_CLRSCDF_0     (0x1U<<24U)

// FLT2JCHGR Configuration

#define DFSDM_FLT2JCHGR_JCHG        (0xFFU<<0U)
#define DFSDM_FLT2JCHGR_JCHG_0      (0x1U<<0U)

// FLT2FCR Configuration

#define DFSDM_FLT2FCR_IOSR          (0xFFU<<0U)
#define DFSDM_FLT2FCR_IOSR_0        (0x1U<<0U)
#define DFSDM_FLT2FCR_FOSR          (0x3FFU<<16U)
#define DFSDM_FLT2FCR_FOSR_0        (0x1U<<16U)
#define DFSDM_FLT2FCR_FORD          (0x7U<<29U)
#define DFSDM_FLT2FCR_FORD_0        (0x1U<<29U)

// FLT2JDATAR Configuration

#define DFSDM_FLT2JDATAR_JDATACH    (0x7U<<0U)
#define DFSDM_FLT2JDATAR_JDATACH_0  (0x1U<<0U)
#define DFSDM_FLT2JDATAR_JDATA      (0xFFFFFFU<<8U)
#define DFSDM_FLT2JDATAR_JDATA_0    (0x1U<<8U)

// FLT2RDATAR Configuration

#define DFSDM_FLT2RDATAR_RDATACH    (0x7U<<0U)
#define DFSDM_FLT2RDATAR_RDATACH_0  (0x1U<<0U)
#define DFSDM_FLT2RDATAR_RPEND      (0x1U<<4U)
#define DFSDM_FLT2RDATAR_RDATA      (0xFFFFFFU<<8U)
#define DFSDM_FLT2RDATAR_RDATA_0    (0x1U<<8U)

// FLT2AWHTR Configuration

#define DFSDM_FLT2AWHTR_BKAWH       (0xFU<<0U)
#define DFSDM_FLT2AWHTR_BKAWH_0     (0x1U<<0U)
#define DFSDM_FLT2AWHTR_AWHT        (0xFFFFFFU<<8U)
#define DFSDM_FLT2AWHTR_AWHT_0      (0x1U<<8U)

// FLT2AWLTR Configuration

#define DFSDM_FLT2AWLTR_BKAWL       (0xFU<<0U)
#define DFSDM_FLT2AWLTR_BKAWL_0     (0x1U<<0U)
#define DFSDM_FLT2AWLTR_AWLT        (0xFFFFFFU<<8U)
#define DFSDM_FLT2AWLTR_AWLT_0      (0x1U<<8U)

// FLT2AWSR Configuration

#define DFSDM_FLT2AWSR_AWLTF        (0xFFU<<0U)
#define DFSDM_FLT2AWSR_AWLTF_0      (0x1U<<0U)
#define DFSDM_FLT2AWSR_AWHTF        (0xFFU<<8U)
#define DFSDM_FLT2AWSR_AWHTF_0      (0x1U<<8U)

// FLT2AWCFR Configuration

#define DFSDM_FLT2AWCFR_CLRAWLTF    (0xFFU<<0U)
#define DFSDM_FLT2AWCFR_CLRAWLTF_0  (0x1U<<0U)
#define DFSDM_FLT2AWCFR_CLRAWHTF    (0xFFU<<8U)
#define DFSDM_FLT2AWCFR_CLRAWHTF_0  (0x1U<<8U)

// FLT2EXMAX Configuration

#define DFSDM_FLT2EXMAX_EXMAXCH     (0x7U<<0U)
#define DFSDM_FLT2EXMAX_EXMAXCH_0   (0x1U<<0U)
#define DFSDM_FLT2EXMAX_EXMAX       (0xFFFFFFU<<8U)
#define DFSDM_FLT2EXMAX_EXMAX_0     (0x1U<<8U)

// FLT2EXMIN Configuration

#define DFSDM_FLT2EXMIN_EXMINCH     (0x7U<<0U)
#define DFSDM_FLT2EXMIN_EXMINCH_0   (0x1U<<0U)
#define DFSDM_FLT2EXMIN_EXMIN       (0xFFFFFFU<<8U)
#define DFSDM_FLT2EXMIN_EXMIN_0     (0x1U<<8U)

// FLT2CNVTIMR Configuration

#define DFSDM_FLT2CNVTIMR_CNVCNT    (0xFFFFFFFU<<4U)
#define DFSDM_FLT2CNVTIMR_CNVCNT_0  (0x1U<<4U)

// FLT3CR1 Configuration

#define DFSDM_FLT3CR1_DFEN          (0x1U<<0U)
#define DFSDM_FLT3CR1_JSWSTART      (0x1U<<1U)
#define DFSDM_FLT3CR1_JSYNC         (0x1U<<3U)
#define DFSDM_FLT3CR1_JSCAN         (0x1U<<4U)
#define DFSDM_FLT3CR1_JDMAEN        (0x1U<<5U)
#define DFSDM_FLT3CR1_JEXTSEL       (0x7U<<8U)
#define DFSDM_FLT3CR1_JEXTSEL_0     (0x1U<<8U)
#define DFSDM_FLT3CR1_JEXTEN        (0x3U<<13U)
#define DFSDM_FLT3CR1_JEXTEN_0      (0x1U<<13U)
#define DFSDM_FLT3CR1_RSWSTART      (0x1U<<17U)
#define DFSDM_FLT3CR1_RCONT         (0x1U<<18U)
#define DFSDM_FLT3CR1_RSYNC         (0x1U<<19U)
#define DFSDM_FLT3CR1_RDMAEN        (0x1U<<21U)
#define DFSDM_FLT3CR1_RCH           (0x7U<<24U)
#define DFSDM_FLT3CR1_RCH_0         (0x1U<<24U)
#define DFSDM_FLT3CR1_FAST          (0x1U<<29U)
#define DFSDM_FLT3CR1_AWFSEL        (0x1U<<30U)

// FLT3CR2 Configuration

#define DFSDM_FLT3CR2_JEOCIE        (0x1U<<0U)
#define DFSDM_FLT3CR2_REOCIE        (0x1U<<1U)
#define DFSDM_FLT3CR2_JOVRIE        (0x1U<<2U)
#define DFSDM_FLT3CR2_ROVRIE        (0x1U<<3U)
#define DFSDM_FLT3CR2_AWDIE         (0x1U<<4U)
#define DFSDM_FLT3CR2_SCDIE         (0x1U<<5U)
#define DFSDM_FLT3CR2_CKABIE        (0x1U<<6U)
#define DFSDM_FLT3CR2_EXCH          (0xFFU<<8U)
#define DFSDM_FLT3CR2_EXCH_0        (0x1U<<8U)
#define DFSDM_FLT3CR2_AWDCH         (0xFFU<<16U)
#define DFSDM_FLT3CR2_AWDCH_0       (0x1U<<16U)

// FLT3ISR Configuration

#define DFSDM_FLT3ISR_JEOCF         (0x1U<<0U)
#define DFSDM_FLT3ISR_REOCF         (0x1U<<1U)
#define DFSDM_FLT3ISR_JOVRF         (0x1U<<2U)
#define DFSDM_FLT3ISR_ROVRF         (0x1U<<3U)
#define DFSDM_FLT3ISR_AWDF          (0x1U<<4U)
#define DFSDM_FLT3ISR_JCIP          (0x1U<<13U)
#define DFSDM_FLT3ISR_RCIP          (0x1U<<14U)
#define DFSDM_FLT3ISR_CKABF         (0xFFU<<16U)
#define DFSDM_FLT3ISR_CKABF_0       (0x1U<<16U)
#define DFSDM_FLT3ISR_SCDF          (0xFFU<<24U)
#define DFSDM_FLT3ISR_SCDF_0        (0x1U<<24U)

// FLT3ICR Configuration

#define DFSDM_FLT3ICR_CLRJOVRF      (0x1U<<2U)
#define DFSDM_FLT3ICR_CLRROVRF      (0x1U<<3U)
#define DFSDM_FLT3ICR_CLRCKABF      (0xFFU<<16U)
#define DFSDM_FLT3ICR_CLRCKABF_0    (0x1U<<16U)
#define DFSDM_FLT3ICR_CLRSCDF       (0xFFU<<24U)
#define DFSDM_FLT3ICR_CLRSCDF_0     (0x1U<<24U)

// FLT3JCHGR Configuration

#define DFSDM_FLT3JCHGR_JCHG        (0xFFU<<0U)
#define DFSDM_FLT3JCHGR_JCHG_0      (0x1U<<0U)

// FLT3FCR Configuration

#define DFSDM_FLT3FCR_IOSR          (0xFFU<<0U)
#define DFSDM_FLT3FCR_IOSR_0        (0x1U<<0U)
#define DFSDM_FLT3FCR_FOSR          (0x3FFU<<16U)
#define DFSDM_FLT3FCR_FOSR_0        (0x1U<<16U)
#define DFSDM_FLT3FCR_FORD          (0x7U<<29U)
#define DFSDM_FLT3FCR_FORD_0        (0x1U<<29U)

// FLT3JDATAR Configuration

#define DFSDM_FLT3JDATAR_JDATACH    (0x7U<<0U)
#define DFSDM_FLT3JDATAR_JDATACH_0  (0x1U<<0U)
#define DFSDM_FLT3JDATAR_JDATA      (0xFFFFFFU<<8U)
#define DFSDM_FLT3JDATAR_JDATA_0    (0x1U<<8U)

// FLT3RDATAR Configuration

#define DFSDM_FLT3RDATAR_RDATACH    (0x7U<<0U)
#define DFSDM_FLT3RDATAR_RDATACH_0  (0x1U<<0U)
#define DFSDM_FLT3RDATAR_RPEND      (0x1U<<4U)
#define DFSDM_FLT3RDATAR_RDATA      (0xFFFFFFU<<8U)
#define DFSDM_FLT3RDATAR_RDATA_0    (0x1U<<8U)

// FLT3AWHTR Configuration

#define DFSDM_FLT3AWHTR_BKAWH       (0xFU<<0U)
#define DFSDM_FLT3AWHTR_BKAWH_0     (0x1U<<0U)
#define DFSDM_FLT3AWHTR_AWHT        (0xFFFFFFU<<8U)
#define DFSDM_FLT3AWHTR_AWHT_0      (0x1U<<8U)

// FLT3AWLTR Configuration

#define DFSDM_FLT3AWLTR_BKAWL       (0xFU<<0U)
#define DFSDM_FLT3AWLTR_BKAWL_0     (0x1U<<0U)
#define DFSDM_FLT3AWLTR_AWLT        (0xFFFFFFU<<8U)
#define DFSDM_FLT3AWLTR_AWLT_0      (0x1U<<8U)

// FLT3AWSR Configuration

#define DFSDM_FLT3AWSR_AWLTF        (0xFFU<<0U)
#define DFSDM_FLT3AWSR_AWLTF_0      (0x1U<<0U)
#define DFSDM_FLT3AWSR_AWHTF        (0xFFU<<8U)
#define DFSDM_FLT3AWSR_AWHTF_0      (0x1U<<8U)

// FLT3AWCFR Configuration

#define DFSDM_FLT3AWCFR_CLRAWLTF    (0xFFU<<0U)
#define DFSDM_FLT3AWCFR_CLRAWLTF_0  (0x1U<<0U)
#define DFSDM_FLT3AWCFR_CLRAWHTF    (0xFFU<<8U)
#define DFSDM_FLT3AWCFR_CLRAWHTF_0  (0x1U<<8U)

// FLT3EXMAX Configuration

#define DFSDM_FLT3EXMAX_EXMAXCH     (0x7U<<0U)
#define DFSDM_FLT3EXMAX_EXMAXCH_0   (0x1U<<0U)
#define DFSDM_FLT3EXMAX_EXMAX       (0xFFFFFFU<<8U)
#define DFSDM_FLT3EXMAX_EXMAX_0     (0x1U<<8U)

// FLT3EXMIN Configuration

#define DFSDM_FLT3EXMIN_EXMINCH     (0x7U<<0U)
#define DFSDM_FLT3EXMIN_EXMINCH_0   (0x1U<<0U)
#define DFSDM_FLT3EXMIN_EXMIN       (0xFFFFFFU<<8U)
#define DFSDM_FLT3EXMIN_EXMIN_0     (0x1U<<8U)

// FLT3CNVTIMR Configuration

#define DFSDM_FLT3CNVTIMR_CNVCNT    (0xFFFFFFFU<<4U)
#define DFSDM_FLT3CNVTIMR_CNVCNT_0  (0x1U<<4U)
