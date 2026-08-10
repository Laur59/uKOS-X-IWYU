/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_ramcfg equates.
 */

#pragma once

#include    <stdint.h>

// RAMCFG address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    AXISRAM1CR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    AXISRAM1ISR;
    volatile    uint32_t    RESERVED1[7];
    volatile    uint32_t    AXISRAM1ERKEYR;
    volatile    uint32_t    RESERVED2[21];
    volatile    uint32_t    AXISRAM2CR;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    AXISRAM2ISR;
    volatile    uint32_t    RESERVED4[7];
    volatile    uint32_t    AXISRAM2ERKEYR;
    volatile    uint32_t    RESERVED5[21];
    volatile    uint32_t    AXISRAM3CR;
    volatile    uint32_t    RESERVED6;
    volatile    uint32_t    AXISRAM3ISR;
    volatile    uint32_t    RESERVED7[7];
    volatile    uint32_t    AXISRAM3ERKEYR;
    volatile    uint32_t    RESERVED8[21];
    volatile    uint32_t    AXISRAM4CR;
    volatile    uint32_t    RESERVED9;
    volatile    uint32_t    AXISRAM4ISR;
    volatile    uint32_t    RESERVED10[7];
    volatile    uint32_t    AXISRAM4ERKEYR;
    volatile    uint32_t    RESERVED11[21];
    volatile    uint32_t    AXISRAM5CR;
    volatile    uint32_t    RESERVED12;
    volatile    uint32_t    AXISRAM5ISR;
    volatile    uint32_t    RESERVED13[7];
    volatile    uint32_t    AXISRAM5ERKEYR;
    volatile    uint32_t    RESERVED14[21];
    volatile    uint32_t    AXISRAM6CR;
    volatile    uint32_t    RESERVED15;
    volatile    uint32_t    AXISRAM6ISR;
    volatile    uint32_t    RESERVED16[7];
    volatile    uint32_t    AXISRAM6ERKEYR;
    volatile    uint32_t    RESERVED17[21];
    volatile    uint32_t    AHBSRAM1CR;
    volatile    uint32_t    RESERVED18;
    volatile    uint32_t    AHBSRAM1ISR;
    volatile    uint32_t    RESERVED19[7];
    volatile    uint32_t    AHBSRAM1ERKEYR;
    volatile    uint32_t    RESERVED20[21];
    volatile    uint32_t    AHBSRAM2CR;
    volatile    uint32_t    RESERVED21;
    volatile    uint32_t    AHBSRAM2ISR;
    volatile    uint32_t    RESERVED22[7];
    volatile    uint32_t    AHBSRAM2ERKEYR;
    volatile    uint32_t    RESERVED23[21];
    volatile    uint32_t    VENCRAMCR;
    volatile    uint32_t    RESERVED24;
    volatile    uint32_t    VENCRAMISR;
    volatile    uint32_t    RESERVED25[7];
    volatile    uint32_t    VENCRAMERKEYR;
    volatile    uint32_t    RESERVED26[21];
    volatile    uint32_t    BKPSRAMCR;
    volatile    uint32_t    BKPSRAMIER;
    volatile    uint32_t    BKPSRAMISR;
    volatile    uint32_t    BKPSRAMESEAR;
    volatile    uint32_t    BKPSRAMEDEAR;
    volatile    uint32_t    BKPSRAMICR;
    volatile    uint32_t    RESERVED27[3];
    volatile    uint32_t    BKPSRAMECCKEYR;
    volatile    uint32_t    BKPSRAMERKEYR;
    volatile    uint32_t    RESERVED28[21];
    volatile    uint32_t    FLEXRAMCR;
    volatile    uint32_t    RESERVED29;
    volatile    uint32_t    FLEXRAMISR;
    volatile    uint32_t    RESERVED30[7];
    volatile    uint32_t    FLEXRAMERKEYR;
} RAMCFG_TypeDef;

#ifdef __cplusplus
#define RAMCFG_NS   reinterpret_cast<RAMCFG_TypeDef *>(0x42023000U)
#define RAMCFG_S    reinterpret_cast<RAMCFG_TypeDef *>(0x52023000U)

#else
#define RAMCFG_NS   ((RAMCFG_TypeDef *)0x42023000U)
#define RAMCFG_S    ((RAMCFG_TypeDef *)0x52023000U)
#endif

// AXISRAM1CR Configuration

#define RAMCFG_AXISRAM1CR_SRAMER            (0x1U<<8U)

#define RAMCFG_AXISRAM1CR_SRAMER_B_0X0      (0x0U<<8U)
#define RAMCFG_AXISRAM1CR_SRAMER_B_0X1      (0x1U<<8U)

// AXISRAM1ISR Configuration

#define RAMCFG_AXISRAM1ISR_SRAMBUSY         (0x1U<<8U)

#define RAMCFG_AXISRAM1ISR_SRAMBUSY_B_0X0   (0x0U<<8U)
#define RAMCFG_AXISRAM1ISR_SRAMBUSY_B_0X1   (0x1U<<8U)

// AXISRAM1ERKEYR Configuration

#define RAMCFG_AXISRAM1ERKEYR_ERASEKEY      (0xFFU<<0U)
#define RAMCFG_AXISRAM1ERKEYR_ERASEKEY_0    (0x1U<<0U)

// AXISRAM2CR Configuration

#define RAMCFG_AXISRAM2CR_SRAMSD            (0x1U<<20U)
#define RAMCFG_AXISRAM2CR_SRAMER            (0x1U<<8U)

#define RAMCFG_AXISRAM2CR_SRAMSD_B_0X0      (0x0U<<20U)
#define RAMCFG_AXISRAM2CR_SRAMSD_B_0X1      (0x1U<<20U)
#define RAMCFG_AXISRAM2CR_SRAMER_B_0X0      (0x0U<<8U)
#define RAMCFG_AXISRAM2CR_SRAMER_B_0X1      (0x1U<<8U)

// AXISRAM2ISR Configuration

#define RAMCFG_AXISRAM2ISR_SRAMBUSY         (0x1U<<8U)

#define RAMCFG_AXISRAM2ISR_SRAMBUSY_B_0X0   (0x0U<<8U)
#define RAMCFG_AXISRAM2ISR_SRAMBUSY_B_0X1   (0x1U<<8U)

// AXISRAM2ERKEYR Configuration

#define RAMCFG_AXISRAM2ERKEYR_ERASEKEY      (0xFFU<<0U)
#define RAMCFG_AXISRAM2ERKEYR_ERASEKEY_0    (0x1U<<0U)

// AXISRAM3CR Configuration

#define RAMCFG_AXISRAM3CR_SRAMSD            (0x1U<<20U)
#define RAMCFG_AXISRAM3CR_SRAMER            (0x1U<<8U)

#define RAMCFG_AXISRAM3CR_SRAMSD_B_0X0      (0x0U<<20U)
#define RAMCFG_AXISRAM3CR_SRAMSD_B_0X1      (0x1U<<20U)
#define RAMCFG_AXISRAM3CR_SRAMER_B_0X0      (0x0U<<8U)
#define RAMCFG_AXISRAM3CR_SRAMER_B_0X1      (0x1U<<8U)

// AXISRAM3ISR Configuration

#define RAMCFG_AXISRAM3ISR_SRAMBUSY         (0x1U<<8U)

#define RAMCFG_AXISRAM3ISR_SRAMBUSY_B_0X0   (0x0U<<8U)
#define RAMCFG_AXISRAM3ISR_SRAMBUSY_B_0X1   (0x1U<<8U)

// AXISRAM3ERKEYR Configuration

#define RAMCFG_AXISRAM3ERKEYR_ERASEKEY      (0xFFU<<0U)
#define RAMCFG_AXISRAM3ERKEYR_ERASEKEY_0    (0x1U<<0U)

// AXISRAM4CR Configuration

#define RAMCFG_AXISRAM4CR_SRAMSD            (0x1U<<20U)
#define RAMCFG_AXISRAM4CR_SRAMER            (0x1U<<8U)

#define RAMCFG_AXISRAM4CR_SRAMSD_B_0X0      (0x0U<<20U)
#define RAMCFG_AXISRAM4CR_SRAMSD_B_0X1      (0x1U<<20U)
#define RAMCFG_AXISRAM4CR_SRAMER_B_0X0      (0x0U<<8U)
#define RAMCFG_AXISRAM4CR_SRAMER_B_0X1      (0x1U<<8U)

// AXISRAM4ISR Configuration

#define RAMCFG_AXISRAM4ISR_SRAMBUSY         (0x1U<<8U)

#define RAMCFG_AXISRAM4ISR_SRAMBUSY_B_0X0   (0x0U<<8U)
#define RAMCFG_AXISRAM4ISR_SRAMBUSY_B_0X1   (0x1U<<8U)

// AXISRAM4ERKEYR Configuration

#define RAMCFG_AXISRAM4ERKEYR_ERASEKEY      (0xFFU<<0U)
#define RAMCFG_AXISRAM4ERKEYR_ERASEKEY_0    (0x1U<<0U)

// AXISRAM5CR Configuration

#define RAMCFG_AXISRAM5CR_SRAMSD            (0x1U<<20U)
#define RAMCFG_AXISRAM5CR_SRAMER            (0x1U<<8U)

#define RAMCFG_AXISRAM5CR_SRAMSD_B_0X0      (0x0U<<20U)
#define RAMCFG_AXISRAM5CR_SRAMSD_B_0X1      (0x1U<<20U)
#define RAMCFG_AXISRAM5CR_SRAMER_B_0X0      (0x0U<<8U)
#define RAMCFG_AXISRAM5CR_SRAMER_B_0X1      (0x1U<<8U)

// AXISRAM5ISR Configuration

#define RAMCFG_AXISRAM5ISR_SRAMBUSY         (0x1U<<8U)

#define RAMCFG_AXISRAM5ISR_SRAMBUSY_B_0X0   (0x0U<<8U)
#define RAMCFG_AXISRAM5ISR_SRAMBUSY_B_0X1   (0x1U<<8U)

// AXISRAM5ERKEYR Configuration

#define RAMCFG_AXISRAM5ERKEYR_ERASEKEY      (0xFFU<<0U)
#define RAMCFG_AXISRAM5ERKEYR_ERASEKEY_0    (0x1U<<0U)

// AXISRAM6CR Configuration

#define RAMCFG_AXISRAM6CR_SRAMSD            (0x1U<<20U)
#define RAMCFG_AXISRAM6CR_SRAMER            (0x1U<<8U)

#define RAMCFG_AXISRAM6CR_SRAMSD_B_0X0      (0x0U<<20U)
#define RAMCFG_AXISRAM6CR_SRAMSD_B_0X1      (0x1U<<20U)
#define RAMCFG_AXISRAM6CR_SRAMER_B_0X0      (0x0U<<8U)
#define RAMCFG_AXISRAM6CR_SRAMER_B_0X1      (0x1U<<8U)

// AXISRAM6ISR Configuration

#define RAMCFG_AXISRAM6ISR_SRAMBUSY         (0x1U<<8U)

#define RAMCFG_AXISRAM6ISR_SRAMBUSY_B_0X0   (0x0U<<8U)
#define RAMCFG_AXISRAM6ISR_SRAMBUSY_B_0X1   (0x1U<<8U)

// AXISRAM6ERKEYR Configuration

#define RAMCFG_AXISRAM6ERKEYR_ERASEKEY      (0xFFU<<0U)
#define RAMCFG_AXISRAM6ERKEYR_ERASEKEY_0    (0x1U<<0U)

// AHBSRAM1CR Configuration

#define RAMCFG_AHBSRAM1CR_SRAMER            (0x1U<<8U)

#define RAMCFG_AHBSRAM1CR_SRAMER_B_0X0      (0x0U<<8U)
#define RAMCFG_AHBSRAM1CR_SRAMER_B_0X1      (0x1U<<8U)

// AHBSRAM1ISR Configuration

#define RAMCFG_AHBSRAM1ISR_SRAMBUSY         (0x1U<<8U)

#define RAMCFG_AHBSRAM1ISR_SRAMBUSY_B_0X0   (0x0U<<8U)
#define RAMCFG_AHBSRAM1ISR_SRAMBUSY_B_0X1   (0x1U<<8U)

// AHBSRAM1ERKEYR Configuration

#define RAMCFG_AHBSRAM1ERKEYR_ERASEKEY      (0xFFU<<0U)
#define RAMCFG_AHBSRAM1ERKEYR_ERASEKEY_0    (0x1U<<0U)

// AHBSRAM2CR Configuration

#define RAMCFG_AHBSRAM2CR_SRAMER            (0x1U<<8U)

#define RAMCFG_AHBSRAM2CR_SRAMER_B_0X0      (0x0U<<8U)
#define RAMCFG_AHBSRAM2CR_SRAMER_B_0X1      (0x1U<<8U)

// AHBSRAM2ISR Configuration

#define RAMCFG_AHBSRAM2ISR_SRAMBUSY         (0x1U<<8U)

#define RAMCFG_AHBSRAM2ISR_SRAMBUSY_B_0X0   (0x0U<<8U)
#define RAMCFG_AHBSRAM2ISR_SRAMBUSY_B_0X1   (0x1U<<8U)

// AHBSRAM2ERKEYR Configuration

#define RAMCFG_AHBSRAM2ERKEYR_ERASEKEY      (0xFFU<<0U)
#define RAMCFG_AHBSRAM2ERKEYR_ERASEKEY_0    (0x1U<<0U)

// VENCRAMCR Configuration

#define RAMCFG_VENCRAMCR_SRAMER             (0x1U<<8U)

#define RAMCFG_VENCRAMCR_SRAMER_B_0X0       (0x0U<<8U)
#define RAMCFG_VENCRAMCR_SRAMER_B_0X1       (0x1U<<8U)

// VENCRAMISR Configuration

#define RAMCFG_VENCRAMISR_SRAMBUSY          (0x1U<<8U)

#define RAMCFG_VENCRAMISR_SRAMBUSY_B_0X0    (0x0U<<8U)
#define RAMCFG_VENCRAMISR_SRAMBUSY_B_0X1    (0x1U<<8U)

// VENCRAMERKEYR Configuration

#define RAMCFG_VENCRAMERKEYR_ERASEKEY       (0xFFU<<0U)
#define RAMCFG_VENCRAMERKEYR_ERASEKEY_0     (0x1U<<0U)

// BKPSRAMCR Configuration

#define RAMCFG_BKPSRAMCR_SRAMER             (0x1U<<8U)
#define RAMCFG_BKPSRAMCR_ALE                (0x1U<<4U)
#define RAMCFG_BKPSRAMCR_ECCE               (0x1U<<0U)

#define RAMCFG_BKPSRAMCR_SRAMER_B_0X0       (0x0U<<8U)
#define RAMCFG_BKPSRAMCR_SRAMER_B_0X1       (0x1U<<8U)
#define RAMCFG_BKPSRAMCR_ALE_B_0X0          (0x0U<<4U)
#define RAMCFG_BKPSRAMCR_ALE_B_0X1          (0x1U<<4U)
#define RAMCFG_BKPSRAMCR_ECCE_B_0X0         (0x0U<<0U)
#define RAMCFG_BKPSRAMCR_ECCE_B_0X1         (0x1U<<0U)

// BKPSRAMIER Configuration

#define RAMCFG_BKPSRAMIER_DEIE              (0x1U<<1U)
#define RAMCFG_BKPSRAMIER_SEIE              (0x1U<<0U)

#define RAMCFG_BKPSRAMIER_DEIE_B_0X0        (0x0U<<1U)
#define RAMCFG_BKPSRAMIER_DEIE_B_0X1        (0x1U<<1U)
#define RAMCFG_BKPSRAMIER_SEIE_B_0X0        (0x0U<<0U)
#define RAMCFG_BKPSRAMIER_SEIE_B_0X1        (0x1U<<0U)

// BKPSRAMISR Configuration

#define RAMCFG_BKPSRAMISR_SRAMBUSY          (0x1U<<8U)
#define RAMCFG_BKPSRAMISR_DED               (0x1U<<1U)
#define RAMCFG_BKPSRAMISR_SEC               (0x1U<<0U)

#define RAMCFG_BKPSRAMISR_SRAMBUSY_B_0X0    (0x0U<<8U)
#define RAMCFG_BKPSRAMISR_SRAMBUSY_B_0X1    (0x1U<<8U)
#define RAMCFG_BKPSRAMISR_DED_B_0X0         (0x0U<<1U)
#define RAMCFG_BKPSRAMISR_DED_B_0X1         (0x1U<<1U)
#define RAMCFG_BKPSRAMISR_SEC_B_0X0         (0x0U<<0U)
#define RAMCFG_BKPSRAMISR_SEC_B_0X1         (0x1U<<0U)

// BKPSRAMESEAR Configuration

#define RAMCFG_BKPSRAMESEAR_ESEA            (0x7FFU<<0U)
#define RAMCFG_BKPSRAMESEAR_ESEA_0          (0x1U<<0U)

// BKPSRAMEDEAR Configuration

#define RAMCFG_BKPSRAMEDEAR_EDEA            (0x7FFU<<0U)
#define RAMCFG_BKPSRAMEDEAR_EDEA_0          (0x1U<<0U)

// BKPSRAMICR Configuration

#define RAMCFG_BKPSRAMICR_CDED              (0x1U<<1U)
#define RAMCFG_BKPSRAMICR_CSED              (0x1U<<0U)

// BKPSRAMECCKEYR Configuration

#define RAMCFG_BKPSRAMECCKEYR_ECCKEY        (0xFFU<<0U)
#define RAMCFG_BKPSRAMECCKEYR_ECCKEY_0      (0x1U<<0U)

// BKPSRAMERKEYR Configuration

#define RAMCFG_BKPSRAMERKEYR_ERASEKEY       (0xFFU<<0U)
#define RAMCFG_BKPSRAMERKEYR_ERASEKEY_0     (0x1U<<0U)

// FLEXRAMCR Configuration

#define RAMCFG_FLEXRAMCR_DTCMCFG            (0x1U<<24U)
#define RAMCFG_FLEXRAMCR_ITCMCFG            (0x3U<<16U)
#define RAMCFG_FLEXRAMCR_ITCMCFG_0          (0x1U<<16U)
#define RAMCFG_FLEXRAMCR_SRAMHWERDIS        (0x1U<<12U)
#define RAMCFG_FLEXRAMCR_SRAMER             (0x1U<<8U)

#define RAMCFG_FLEXRAMCR_DTCMCFG_B_0X0      (0x0U<<24U)
#define RAMCFG_FLEXRAMCR_DTCMCFG_B_0X1      (0x1U<<24U)
#define RAMCFG_FLEXRAMCR_ITCMCFG_B_0X0      (0x0U<<16U)
#define RAMCFG_FLEXRAMCR_ITCMCFG_B_0X1      (0x1U<<16U)
#define RAMCFG_FLEXRAMCR_ITCMCFG_B_0X2      (0x2U<<16U)
#define RAMCFG_FLEXRAMCR_SRAMHWERDIS_B_0X0  (0x0U<<12U)
#define RAMCFG_FLEXRAMCR_SRAMHWERDIS_B_0X1  (0x1U<<12U)
#define RAMCFG_FLEXRAMCR_SRAMER_B_0X0       (0x0U<<8U)
#define RAMCFG_FLEXRAMCR_SRAMER_B_0X1       (0x1U<<8U)

// FLEXRAMISR Configuration

#define RAMCFG_FLEXRAMISR_SRAMBUSY          (0x1U<<8U)

#define RAMCFG_FLEXRAMISR_SRAMBUSY_B_0X0    (0x0U<<8U)
#define RAMCFG_FLEXRAMISR_SRAMBUSY_B_0X1    (0x1U<<8U)

// FLEXRAMERKEYR Configuration

#define RAMCFG_FLEXRAMERKEYR_ERASEKEY       (0xFFU<<0U)
#define RAMCFG_FLEXRAMERKEYR_ERASEKEY_0     (0x1U<<0U)
