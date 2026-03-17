/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32N657_ramcfg.
; =================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32N657_ramcfg equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
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

#define RAMCFG_AXISRAM1CR_SRAMER            (0x1U<<8)

#define RAMCFG_AXISRAM1CR_SRAMER_B_0X0      (0x0U<<8)
#define RAMCFG_AXISRAM1CR_SRAMER_B_0X1      (0x1U<<8)

// AXISRAM1ISR Configuration

#define RAMCFG_AXISRAM1ISR_SRAMBUSY         (0x1U<<8)

#define RAMCFG_AXISRAM1ISR_SRAMBUSY_B_0X0   (0x0U<<8)
#define RAMCFG_AXISRAM1ISR_SRAMBUSY_B_0X1   (0x1U<<8)

// AXISRAM1ERKEYR Configuration

#define RAMCFG_AXISRAM1ERKEYR_ERASEKEY      (0xFFU<<0)
#define RAMCFG_AXISRAM1ERKEYR_ERASEKEY_0    (0x1U<<0)

// AXISRAM2CR Configuration

#define RAMCFG_AXISRAM2CR_SRAMSD            (0x1U<<20)
#define RAMCFG_AXISRAM2CR_SRAMER            (0x1U<<8)

#define RAMCFG_AXISRAM2CR_SRAMSD_B_0X0      (0x0U<<20)
#define RAMCFG_AXISRAM2CR_SRAMSD_B_0X1      (0x1U<<20)
#define RAMCFG_AXISRAM2CR_SRAMER_B_0X0      (0x0U<<8)
#define RAMCFG_AXISRAM2CR_SRAMER_B_0X1      (0x1U<<8)

// AXISRAM2ISR Configuration

#define RAMCFG_AXISRAM2ISR_SRAMBUSY         (0x1U<<8)

#define RAMCFG_AXISRAM2ISR_SRAMBUSY_B_0X0   (0x0U<<8)
#define RAMCFG_AXISRAM2ISR_SRAMBUSY_B_0X1   (0x1U<<8)

// AXISRAM2ERKEYR Configuration

#define RAMCFG_AXISRAM2ERKEYR_ERASEKEY      (0xFFU<<0)
#define RAMCFG_AXISRAM2ERKEYR_ERASEKEY_0    (0x1U<<0)

// AXISRAM3CR Configuration

#define RAMCFG_AXISRAM3CR_SRAMSD            (0x1U<<20)
#define RAMCFG_AXISRAM3CR_SRAMER            (0x1U<<8)

#define RAMCFG_AXISRAM3CR_SRAMSD_B_0X0      (0x0U<<20)
#define RAMCFG_AXISRAM3CR_SRAMSD_B_0X1      (0x1U<<20)
#define RAMCFG_AXISRAM3CR_SRAMER_B_0X0      (0x0U<<8)
#define RAMCFG_AXISRAM3CR_SRAMER_B_0X1      (0x1U<<8)

// AXISRAM3ISR Configuration

#define RAMCFG_AXISRAM3ISR_SRAMBUSY         (0x1U<<8)

#define RAMCFG_AXISRAM3ISR_SRAMBUSY_B_0X0   (0x0U<<8)
#define RAMCFG_AXISRAM3ISR_SRAMBUSY_B_0X1   (0x1U<<8)

// AXISRAM3ERKEYR Configuration

#define RAMCFG_AXISRAM3ERKEYR_ERASEKEY      (0xFFU<<0)
#define RAMCFG_AXISRAM3ERKEYR_ERASEKEY_0    (0x1U<<0)

// AXISRAM4CR Configuration

#define RAMCFG_AXISRAM4CR_SRAMSD            (0x1U<<20)
#define RAMCFG_AXISRAM4CR_SRAMER            (0x1U<<8)

#define RAMCFG_AXISRAM4CR_SRAMSD_B_0X0      (0x0U<<20)
#define RAMCFG_AXISRAM4CR_SRAMSD_B_0X1      (0x1U<<20)
#define RAMCFG_AXISRAM4CR_SRAMER_B_0X0      (0x0U<<8)
#define RAMCFG_AXISRAM4CR_SRAMER_B_0X1      (0x1U<<8)

// AXISRAM4ISR Configuration

#define RAMCFG_AXISRAM4ISR_SRAMBUSY         (0x1U<<8)

#define RAMCFG_AXISRAM4ISR_SRAMBUSY_B_0X0   (0x0U<<8)
#define RAMCFG_AXISRAM4ISR_SRAMBUSY_B_0X1   (0x1U<<8)

// AXISRAM4ERKEYR Configuration

#define RAMCFG_AXISRAM4ERKEYR_ERASEKEY      (0xFFU<<0)
#define RAMCFG_AXISRAM4ERKEYR_ERASEKEY_0    (0x1U<<0)

// AXISRAM5CR Configuration

#define RAMCFG_AXISRAM5CR_SRAMSD            (0x1U<<20)
#define RAMCFG_AXISRAM5CR_SRAMER            (0x1U<<8)

#define RAMCFG_AXISRAM5CR_SRAMSD_B_0X0      (0x0U<<20)
#define RAMCFG_AXISRAM5CR_SRAMSD_B_0X1      (0x1U<<20)
#define RAMCFG_AXISRAM5CR_SRAMER_B_0X0      (0x0U<<8)
#define RAMCFG_AXISRAM5CR_SRAMER_B_0X1      (0x1U<<8)

// AXISRAM5ISR Configuration

#define RAMCFG_AXISRAM5ISR_SRAMBUSY         (0x1U<<8)

#define RAMCFG_AXISRAM5ISR_SRAMBUSY_B_0X0   (0x0U<<8)
#define RAMCFG_AXISRAM5ISR_SRAMBUSY_B_0X1   (0x1U<<8)

// AXISRAM5ERKEYR Configuration

#define RAMCFG_AXISRAM5ERKEYR_ERASEKEY      (0xFFU<<0)
#define RAMCFG_AXISRAM5ERKEYR_ERASEKEY_0    (0x1U<<0)

// AXISRAM6CR Configuration

#define RAMCFG_AXISRAM6CR_SRAMSD            (0x1U<<20)
#define RAMCFG_AXISRAM6CR_SRAMER            (0x1U<<8)

#define RAMCFG_AXISRAM6CR_SRAMSD_B_0X0      (0x0U<<20)
#define RAMCFG_AXISRAM6CR_SRAMSD_B_0X1      (0x1U<<20)
#define RAMCFG_AXISRAM6CR_SRAMER_B_0X0      (0x0U<<8)
#define RAMCFG_AXISRAM6CR_SRAMER_B_0X1      (0x1U<<8)

// AXISRAM6ISR Configuration

#define RAMCFG_AXISRAM6ISR_SRAMBUSY         (0x1U<<8)

#define RAMCFG_AXISRAM6ISR_SRAMBUSY_B_0X0   (0x0U<<8)
#define RAMCFG_AXISRAM6ISR_SRAMBUSY_B_0X1   (0x1U<<8)

// AXISRAM6ERKEYR Configuration

#define RAMCFG_AXISRAM6ERKEYR_ERASEKEY      (0xFFU<<0)
#define RAMCFG_AXISRAM6ERKEYR_ERASEKEY_0    (0x1U<<0)

// AHBSRAM1CR Configuration

#define RAMCFG_AHBSRAM1CR_SRAMER            (0x1U<<8)

#define RAMCFG_AHBSRAM1CR_SRAMER_B_0X0      (0x0U<<8)
#define RAMCFG_AHBSRAM1CR_SRAMER_B_0X1      (0x1U<<8)

// AHBSRAM1ISR Configuration

#define RAMCFG_AHBSRAM1ISR_SRAMBUSY         (0x1U<<8)

#define RAMCFG_AHBSRAM1ISR_SRAMBUSY_B_0X0   (0x0U<<8)
#define RAMCFG_AHBSRAM1ISR_SRAMBUSY_B_0X1   (0x1U<<8)

// AHBSRAM1ERKEYR Configuration

#define RAMCFG_AHBSRAM1ERKEYR_ERASEKEY      (0xFFU<<0)
#define RAMCFG_AHBSRAM1ERKEYR_ERASEKEY_0    (0x1U<<0)

// AHBSRAM2CR Configuration

#define RAMCFG_AHBSRAM2CR_SRAMER            (0x1U<<8)

#define RAMCFG_AHBSRAM2CR_SRAMER_B_0X0      (0x0U<<8)
#define RAMCFG_AHBSRAM2CR_SRAMER_B_0X1      (0x1U<<8)

// AHBSRAM2ISR Configuration

#define RAMCFG_AHBSRAM2ISR_SRAMBUSY         (0x1U<<8)

#define RAMCFG_AHBSRAM2ISR_SRAMBUSY_B_0X0   (0x0U<<8)
#define RAMCFG_AHBSRAM2ISR_SRAMBUSY_B_0X1   (0x1U<<8)

// AHBSRAM2ERKEYR Configuration

#define RAMCFG_AHBSRAM2ERKEYR_ERASEKEY      (0xFFU<<0)
#define RAMCFG_AHBSRAM2ERKEYR_ERASEKEY_0    (0x1U<<0)

// VENCRAMCR Configuration

#define RAMCFG_VENCRAMCR_SRAMER             (0x1U<<8)

#define RAMCFG_VENCRAMCR_SRAMER_B_0X0       (0x0U<<8)
#define RAMCFG_VENCRAMCR_SRAMER_B_0X1       (0x1U<<8)

// VENCRAMISR Configuration

#define RAMCFG_VENCRAMISR_SRAMBUSY          (0x1U<<8)

#define RAMCFG_VENCRAMISR_SRAMBUSY_B_0X0    (0x0U<<8)
#define RAMCFG_VENCRAMISR_SRAMBUSY_B_0X1    (0x1U<<8)

// VENCRAMERKEYR Configuration

#define RAMCFG_VENCRAMERKEYR_ERASEKEY       (0xFFU<<0)
#define RAMCFG_VENCRAMERKEYR_ERASEKEY_0     (0x1U<<0)

// BKPSRAMCR Configuration

#define RAMCFG_BKPSRAMCR_SRAMER             (0x1U<<8)
#define RAMCFG_BKPSRAMCR_ALE                (0x1U<<4)
#define RAMCFG_BKPSRAMCR_ECCE               (0x1U<<0)

#define RAMCFG_BKPSRAMCR_SRAMER_B_0X0       (0x0U<<8)
#define RAMCFG_BKPSRAMCR_SRAMER_B_0X1       (0x1U<<8)
#define RAMCFG_BKPSRAMCR_ALE_B_0X0          (0x0U<<4)
#define RAMCFG_BKPSRAMCR_ALE_B_0X1          (0x1U<<4)
#define RAMCFG_BKPSRAMCR_ECCE_B_0X0         (0x0U<<0)
#define RAMCFG_BKPSRAMCR_ECCE_B_0X1         (0x1U<<0)

// BKPSRAMIER Configuration

#define RAMCFG_BKPSRAMIER_DEIE              (0x1U<<1)
#define RAMCFG_BKPSRAMIER_SEIE              (0x1U<<0)

#define RAMCFG_BKPSRAMIER_DEIE_B_0X0        (0x0U<<1)
#define RAMCFG_BKPSRAMIER_DEIE_B_0X1        (0x1U<<1)
#define RAMCFG_BKPSRAMIER_SEIE_B_0X0        (0x0U<<0)
#define RAMCFG_BKPSRAMIER_SEIE_B_0X1        (0x1U<<0)

// BKPSRAMISR Configuration

#define RAMCFG_BKPSRAMISR_SRAMBUSY          (0x1U<<8)
#define RAMCFG_BKPSRAMISR_DED               (0x1U<<1)
#define RAMCFG_BKPSRAMISR_SEC               (0x1U<<0)

#define RAMCFG_BKPSRAMISR_SRAMBUSY_B_0X0    (0x0U<<8)
#define RAMCFG_BKPSRAMISR_SRAMBUSY_B_0X1    (0x1U<<8)
#define RAMCFG_BKPSRAMISR_DED_B_0X0         (0x0U<<1)
#define RAMCFG_BKPSRAMISR_DED_B_0X1         (0x1U<<1)
#define RAMCFG_BKPSRAMISR_SEC_B_0X0         (0x0U<<0)
#define RAMCFG_BKPSRAMISR_SEC_B_0X1         (0x1U<<0)

// BKPSRAMESEAR Configuration

#define RAMCFG_BKPSRAMESEAR_ESEA            (0x7FFU<<0)
#define RAMCFG_BKPSRAMESEAR_ESEA_0          (0x1U<<0)

// BKPSRAMEDEAR Configuration

#define RAMCFG_BKPSRAMEDEAR_EDEA            (0x7FFU<<0)
#define RAMCFG_BKPSRAMEDEAR_EDEA_0          (0x1U<<0)

// BKPSRAMICR Configuration

#define RAMCFG_BKPSRAMICR_CDED              (0x1U<<1)
#define RAMCFG_BKPSRAMICR_CSED              (0x1U<<0)

// BKPSRAMECCKEYR Configuration

#define RAMCFG_BKPSRAMECCKEYR_ECCKEY        (0xFFU<<0)
#define RAMCFG_BKPSRAMECCKEYR_ECCKEY_0      (0x1U<<0)

// BKPSRAMERKEYR Configuration

#define RAMCFG_BKPSRAMERKEYR_ERASEKEY       (0xFFU<<0)
#define RAMCFG_BKPSRAMERKEYR_ERASEKEY_0     (0x1U<<0)

// FLEXRAMCR Configuration

#define RAMCFG_FLEXRAMCR_DTCMCFG            (0x1U<<24)
#define RAMCFG_FLEXRAMCR_ITCMCFG            (0x3U<<16)
#define RAMCFG_FLEXRAMCR_ITCMCFG_0          (0x1U<<16)
#define RAMCFG_FLEXRAMCR_SRAMHWERDIS        (0x1U<<12)
#define RAMCFG_FLEXRAMCR_SRAMER             (0x1U<<8)

#define RAMCFG_FLEXRAMCR_DTCMCFG_B_0X0      (0x0U<<24)
#define RAMCFG_FLEXRAMCR_DTCMCFG_B_0X1      (0x1U<<24)
#define RAMCFG_FLEXRAMCR_ITCMCFG_B_0X0      (0x0U<<16)
#define RAMCFG_FLEXRAMCR_ITCMCFG_B_0X1      (0x1U<<16)
#define RAMCFG_FLEXRAMCR_ITCMCFG_B_0X2      (0x2U<<16)
#define RAMCFG_FLEXRAMCR_SRAMHWERDIS_B_0X0  (0x0U<<12)
#define RAMCFG_FLEXRAMCR_SRAMHWERDIS_B_0X1  (0x1U<<12)
#define RAMCFG_FLEXRAMCR_SRAMER_B_0X0       (0x0U<<8)
#define RAMCFG_FLEXRAMCR_SRAMER_B_0X1       (0x1U<<8)

// FLEXRAMISR Configuration

#define RAMCFG_FLEXRAMISR_SRAMBUSY          (0x1U<<8)

#define RAMCFG_FLEXRAMISR_SRAMBUSY_B_0X0    (0x0U<<8)
#define RAMCFG_FLEXRAMISR_SRAMBUSY_B_0X1    (0x1U<<8)

// FLEXRAMERKEYR Configuration

#define RAMCFG_FLEXRAMERKEYR_ERASEKEY       (0xFFU<<0)
#define RAMCFG_FLEXRAMERKEYR_ERASEKEY_0     (0x1U<<0)
