/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H747_CM4_axi equates.
 */

#pragma once

#include    <stdint.h>

// AXI address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    RESERVED0[2036];
    volatile    uint32_t    PERIPH_ID_4;
    volatile    uint32_t    RESERVED1[3];
    volatile    uint32_t    PERIPH_ID_0;
    volatile    uint32_t    PERIPH_ID_1;
    volatile    uint32_t    PERIPH_ID_2;
    volatile    uint32_t    PERIPH_ID_3;
    volatile    uint32_t    COMP_ID_0;
    volatile    uint32_t    COMP_ID_1;
    volatile    uint32_t    COMP_ID_2;
    volatile    uint32_t    COMP_ID_3;
    volatile    uint32_t    RESERVED2[2];
    volatile    uint32_t    TARG1_FN_MOD_ISS_BM;
    volatile    uint32_t    RESERVED3[6];
    volatile    uint32_t    TARG1_FN_MOD2;
    volatile    uint32_t    RESERVED4;
    volatile    uint32_t    TARG1_FN_MOD_LB;
    volatile    uint32_t    RESERVED5[54];
    volatile    uint32_t    TARG1_FN_MOD;
    volatile    uint32_t    RESERVED6[959];
    volatile    uint32_t    TARG2_FN_MOD_ISS_BM;
    volatile    uint32_t    RESERVED7[6];
    volatile    uint32_t    TARG2_FN_MOD2;
    volatile    uint32_t    RESERVED8;
    volatile    uint32_t    TARG2_FN_MOD_LB;
    volatile    uint32_t    RESERVED9[54];
    volatile    uint32_t    TARG2_FN_MOD;
    volatile    uint32_t    RESERVED10[959];
    volatile    uint32_t    TARG3_FN_MOD_ISS_BM;
    volatile    uint32_t    RESERVED11[1023];
    volatile    uint32_t    TARG4_FN_MOD_ISS_BM;
    volatile    uint32_t    RESERVED12[1023];
    volatile    uint32_t    TARG5_FN_MOD_ISS_BM;
    volatile    uint32_t    RESERVED13[1023];
    volatile    uint32_t    TARG6_FN_MOD_ISS_BM;
    volatile    uint32_t    RESERVED14[1024];
    volatile    uint32_t    TARG7_FN_MOD_ISS_BM;
    volatile    uint32_t    RESERVED15[5];
    volatile    uint32_t    TARG7_FN_MOD2;
    volatile    uint32_t    RESERVED16[56];
    volatile    uint32_t    TARG7_FN_MOD;
    volatile    uint32_t    RESERVED17[59334];
    volatile    uint32_t    INI1_FN_MOD2;
    volatile    uint32_t    INI1_FN_MOD_AHB;
    volatile    uint32_t    RESERVED18[53];
    volatile    uint32_t    INI1_READ_QOS;
    volatile    uint32_t    INI1_WRITE_QOS;
    volatile    uint32_t    INI1_FN_MOD;
    volatile    uint32_t    RESERVED19[1021];
    volatile    uint32_t    INI2_READ_QOS;
    volatile    uint32_t    INI2_WRITE_QOS;
    volatile    uint32_t    INI2_FN_MOD;
    volatile    uint32_t    RESERVED20[966];
    volatile    uint32_t    INI3_FN_MOD2;
    volatile    uint32_t    INI3_FN_MOD_AHB;
    volatile    uint32_t    RESERVED21[53];
    volatile    uint32_t    INI3_READ_QOS;
    volatile    uint32_t    INI3_WRITE_QOS;
    volatile    uint32_t    INI3_FN_MOD;
    volatile    uint32_t    RESERVED22[1021];
    volatile    uint32_t    INI4_READ_QOS;
    volatile    uint32_t    INI4_WRITE_QOS;
    volatile    uint32_t    INI4_FN_MOD;
    volatile    uint32_t    RESERVED23[1021];
    volatile    uint32_t    INI5_READ_QOS;
    volatile    uint32_t    INI5_WRITE_QOS;
    volatile    uint32_t    INI5_FN_MOD;
    volatile    uint32_t    RESERVED24[1021];
    volatile    uint32_t    INI6_READ_QOS;
    volatile    uint32_t    INI6_WRITE_QOS;
    volatile    uint32_t    INI6_FN_MOD;
} AXI_TypeDef;

#ifdef __cplusplus
#define AXI reinterpret_cast<AXI_TypeDef *>(0x51000000U)

#else
#define AXI ((AXI_TypeDef *)0x51000000U)
#endif

// PERIPH_ID_4 Configuration

#define AXI_PERIPH_ID_4_KCOUNT4                     (0xFU<<4)
#define AXI_PERIPH_ID_4_KCOUNT4_0                   (0x1U<<4)
#define AXI_PERIPH_ID_4_JEP106CON                   (0xFU<<0)
#define AXI_PERIPH_ID_4_JEP106CON_0                 (0x1U<<0)

// PERIPH_ID_0 Configuration

#define AXI_PERIPH_ID_0_PARTNUM                     (0xFFU<<0)
#define AXI_PERIPH_ID_0_PARTNUM_0                   (0x1U<<0)

// PERIPH_ID_1 Configuration

#define AXI_PERIPH_ID_1_JEP106I                     (0xFU<<4)
#define AXI_PERIPH_ID_1_JEP106I_0                   (0x1U<<4)
#define AXI_PERIPH_ID_1_PARTNUM                     (0xFU<<0)
#define AXI_PERIPH_ID_1_PARTNUM_0                   (0x1U<<0)

// PERIPH_ID_2 Configuration

#define AXI_PERIPH_ID_2_REVISION                    (0xFU<<4)
#define AXI_PERIPH_ID_2_REVISION_0                  (0x1U<<4)
#define AXI_PERIPH_ID_2_JEDEC                       (0x1U<<3)
#define AXI_PERIPH_ID_2_JEP106ID                    (0x7U<<0)
#define AXI_PERIPH_ID_2_JEP106ID_0                  (0x1U<<0)

// PERIPH_ID_3 Configuration

#define AXI_PERIPH_ID_3_REV_AND                     (0xFU<<4)
#define AXI_PERIPH_ID_3_REV_AND_0                   (0x1U<<4)
#define AXI_PERIPH_ID_3_CUST_MOD_NUM                (0xFU<<0)
#define AXI_PERIPH_ID_3_CUST_MOD_NUM_0              (0x1U<<0)

// COMP_ID_0 Configuration

#define AXI_COMP_ID_0_PREAMBLE                      (0xFFU<<0)
#define AXI_COMP_ID_0_PREAMBLE_0                    (0x1U<<0)

// COMP_ID_1 Configuration

#define AXI_COMP_ID_1_CLASS                         (0xFU<<4)
#define AXI_COMP_ID_1_CLASS_0                       (0x1U<<4)
#define AXI_COMP_ID_1_PREAMBLE                      (0xFU<<0)
#define AXI_COMP_ID_1_PREAMBLE_0                    (0x1U<<0)

// COMP_ID_2 Configuration

#define AXI_COMP_ID_2_PREAMBLE                      (0xFFU<<0)
#define AXI_COMP_ID_2_PREAMBLE_0                    (0x1U<<0)

// COMP_ID_3 Configuration

#define AXI_COMP_ID_3_PREAMBLE                      (0xFFU<<0)
#define AXI_COMP_ID_3_PREAMBLE_0                    (0x1U<<0)

// TARG1_FN_MOD_ISS_BM Configuration

#define AXI_TARG1_FN_MOD_ISS_BM_WRITE_ISS_OVERRIDE  (0x1U<<1)
#define AXI_TARG1_FN_MOD_ISS_BM_READ_ISS_OVERRIDE   (0x1U<<0)

// TARG1_FN_MOD2 Configuration

#define AXI_TARG1_FN_MOD2_BYPASS_MERGE              (0x1U<<0)

// TARG1_FN_MOD_LB Configuration

#define AXI_TARG1_FN_MOD_LB_FN_MOD_LB               (0x1U<<0)

// TARG1_FN_MOD Configuration

#define AXI_TARG1_FN_MOD_WRITE_ISS_OVERRIDE         (0x1U<<1)
#define AXI_TARG1_FN_MOD_READ_ISS_OVERRIDE          (0x1U<<0)

// TARG2_FN_MOD_ISS_BM Configuration

#define AXI_TARG2_FN_MOD_ISS_BM_WRITE_ISS_OVERRIDE  (0x1U<<1)
#define AXI_TARG2_FN_MOD_ISS_BM_READ_ISS_OVERRIDE   (0x1U<<0)

// TARG2_FN_MOD2 Configuration

#define AXI_TARG2_FN_MOD2_BYPASS_MERGE              (0x1U<<0)

// TARG2_FN_MOD_LB Configuration

#define AXI_TARG2_FN_MOD_LB_FN_MOD_LB               (0x1U<<0)

// TARG2_FN_MOD Configuration

#define AXI_TARG2_FN_MOD_WRITE_ISS_OVERRIDE         (0x1U<<1)
#define AXI_TARG2_FN_MOD_READ_ISS_OVERRIDE          (0x1U<<0)

// TARG3_FN_MOD_ISS_BM Configuration

#define AXI_TARG3_FN_MOD_ISS_BM_WRITE_ISS_OVERRIDE  (0x1U<<1)
#define AXI_TARG3_FN_MOD_ISS_BM_READ_ISS_OVERRIDE   (0x1U<<0)

// TARG4_FN_MOD_ISS_BM Configuration

#define AXI_TARG4_FN_MOD_ISS_BM_WRITE_ISS_OVERRIDE  (0x1U<<1)
#define AXI_TARG4_FN_MOD_ISS_BM_READ_ISS_OVERRIDE   (0x1U<<0)

// TARG5_FN_MOD_ISS_BM Configuration

#define AXI_TARG5_FN_MOD_ISS_BM_WRITE_ISS_OVERRIDE  (0x1U<<1)
#define AXI_TARG5_FN_MOD_ISS_BM_READ_ISS_OVERRIDE   (0x1U<<0)

// TARG6_FN_MOD_ISS_BM Configuration

#define AXI_TARG6_FN_MOD_ISS_BM_WRITE_ISS_OVERRIDE  (0x1U<<1)
#define AXI_TARG6_FN_MOD_ISS_BM_READ_ISS_OVERRIDE   (0x1U<<0)

// TARG7_FN_MOD_ISS_BM Configuration

#define AXI_TARG7_FN_MOD_ISS_BM_WRITE_ISS_OVERRIDE  (0x1U<<1)
#define AXI_TARG7_FN_MOD_ISS_BM_READ_ISS_OVERRIDE   (0x1U<<0)

// TARG7_FN_MOD2 Configuration

#define AXI_TARG7_FN_MOD2_BYPASS_MERGE              (0x1U<<0)

// TARG7_FN_MOD Configuration

#define AXI_TARG7_FN_MOD_WRITE_ISS_OVERRIDE         (0x1U<<1)
#define AXI_TARG7_FN_MOD_READ_ISS_OVERRIDE          (0x1U<<0)

// INI1_FN_MOD2 Configuration

#define AXI_INI1_FN_MOD2_BYPASS_MERGE               (0x1U<<0)

// INI1_FN_MOD_AHB Configuration

#define AXI_INI1_FN_MOD_AHB_WR_INC_OVERRIDE         (0x1U<<1)
#define AXI_INI1_FN_MOD_AHB_RD_INC_OVERRIDE         (0x1U<<0)

// INI1_READ_QOS Configuration

#define AXI_INI1_READ_QOS_AR_QOS                    (0xFU<<0)
#define AXI_INI1_READ_QOS_AR_QOS_0                  (0x1U<<0)

// INI1_WRITE_QOS Configuration

#define AXI_INI1_WRITE_QOS_AW_QOS                   (0xFU<<0)
#define AXI_INI1_WRITE_QOS_AW_QOS_0                 (0x1U<<0)

// INI1_FN_MOD Configuration

#define AXI_INI1_FN_MOD_WRITE_ISS_OVERRIDE          (0x1U<<1)
#define AXI_INI1_FN_MOD_READ_ISS_OVERRIDE           (0x1U<<0)

// INI2_READ_QOS Configuration

#define AXI_INI2_READ_QOS_AR_QOS                    (0xFU<<0)
#define AXI_INI2_READ_QOS_AR_QOS_0                  (0x1U<<0)

// INI2_WRITE_QOS Configuration

#define AXI_INI2_WRITE_QOS_AW_QOS                   (0xFU<<0)
#define AXI_INI2_WRITE_QOS_AW_QOS_0                 (0x1U<<0)

// INI2_FN_MOD Configuration

#define AXI_INI2_FN_MOD_WRITE_ISS_OVERRIDE          (0x1U<<1)
#define AXI_INI2_FN_MOD_READ_ISS_OVERRIDE           (0x1U<<0)

// INI3_FN_MOD2 Configuration

#define AXI_INI3_FN_MOD2_BYPASS_MERGE               (0x1U<<0)

// INI3_FN_MOD_AHB Configuration

#define AXI_INI3_FN_MOD_AHB_WR_INC_OVERRIDE         (0x1U<<1)
#define AXI_INI3_FN_MOD_AHB_RD_INC_OVERRIDE         (0x1U<<0)

// INI3_READ_QOS Configuration

#define AXI_INI3_READ_QOS_AR_QOS                    (0xFU<<0)
#define AXI_INI3_READ_QOS_AR_QOS_0                  (0x1U<<0)

// INI3_WRITE_QOS Configuration

#define AXI_INI3_WRITE_QOS_AW_QOS                   (0xFU<<0)
#define AXI_INI3_WRITE_QOS_AW_QOS_0                 (0x1U<<0)

// INI3_FN_MOD Configuration

#define AXI_INI3_FN_MOD_WRITE_ISS_OVERRIDE          (0x1U<<1)
#define AXI_INI3_FN_MOD_READ_ISS_OVERRIDE           (0x1U<<0)

// INI4_READ_QOS Configuration

#define AXI_INI4_READ_QOS_AR_QOS                    (0xFU<<0)
#define AXI_INI4_READ_QOS_AR_QOS_0                  (0x1U<<0)

// INI4_WRITE_QOS Configuration

#define AXI_INI4_WRITE_QOS_AW_QOS                   (0xFU<<0)
#define AXI_INI4_WRITE_QOS_AW_QOS_0                 (0x1U<<0)

// INI4_FN_MOD Configuration

#define AXI_INI4_FN_MOD_WRITE_ISS_OVERRIDE          (0x1U<<1)
#define AXI_INI4_FN_MOD_READ_ISS_OVERRIDE           (0x1U<<0)

// INI5_READ_QOS Configuration

#define AXI_INI5_READ_QOS_AR_QOS                    (0xFU<<0)
#define AXI_INI5_READ_QOS_AR_QOS_0                  (0x1U<<0)

// INI5_WRITE_QOS Configuration

#define AXI_INI5_WRITE_QOS_AW_QOS                   (0xFU<<0)
#define AXI_INI5_WRITE_QOS_AW_QOS_0                 (0x1U<<0)

// INI5_FN_MOD Configuration

#define AXI_INI5_FN_MOD_WRITE_ISS_OVERRIDE          (0x1U<<1)
#define AXI_INI5_FN_MOD_READ_ISS_OVERRIDE           (0x1U<<0)

// INI6_READ_QOS Configuration

#define AXI_INI6_READ_QOS_AR_QOS                    (0xFU<<0)
#define AXI_INI6_READ_QOS_AR_QOS_0                  (0x1U<<0)

// INI6_WRITE_QOS Configuration

#define AXI_INI6_WRITE_QOS_AW_QOS                   (0xFU<<0)
#define AXI_INI6_WRITE_QOS_AW_QOS_0                 (0x1U<<0)

// INI6_FN_MOD Configuration

#define AXI_INI6_FN_MOD_WRITE_ISS_OVERRIDE          (0x1U<<1)
#define AXI_INI6_FN_MOD_READ_ISS_OVERRIDE           (0x1U<<0)
