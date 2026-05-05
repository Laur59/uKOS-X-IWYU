/*
 * SPDX-License-Identifier: MIT
 *
 * Goal:     stm32V873_risaf equates.
 */
#pragma once

#include    <stdint.h>

// RISAF address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    IASR;
    volatile    uint32_t    IACR;
    volatile    uint32_t    RESERVED1[4];
    volatile    uint32_t    IAESR;
    volatile    uint32_t    IADDR;
    volatile    uint32_t    RESERVED2[6];
    volatile    uint32_t    REG1_CFGR;
    volatile    uint32_t    REG1_STARTR;
    volatile    uint32_t    REG1_ENDR;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    REG1_ACFGR;
    volatile    uint32_t    REG1_ASTARTR;
    volatile    uint32_t    REG1_AENDR;
    volatile    uint32_t    RESERVED4;
    volatile    uint32_t    REG1_BCFGR;
    volatile    uint32_t    REG1_BSTARTR;
    volatile    uint32_t    REG1_BENDR;
    volatile    uint32_t    RESERVED5[5];
    volatile    uint32_t    REG2_CFGR;
    volatile    uint32_t    REG2_STARTR;
    volatile    uint32_t    REG2_ENDR;
    volatile    uint32_t    RESERVED6;
    volatile    uint32_t    REG2_ACFGR;
    volatile    uint32_t    REG2_ASTARTR;
    volatile    uint32_t    REG2_AENDR;
    volatile    uint32_t    RESERVED7;
    volatile    uint32_t    REG2_BCFGR;
    volatile    uint32_t    REG2_BSTARTR;
    volatile    uint32_t    REG2_BENDR;
    volatile    uint32_t    RESERVED8[5];
    volatile    uint32_t    REG3_CFGR;
    volatile    uint32_t    REG3_STARTR;
    volatile    uint32_t    REG3_ENDR;
    volatile    uint32_t    RESERVED9;
    volatile    uint32_t    REG3_ACFGR;
    volatile    uint32_t    REG3_ASTARTR;
    volatile    uint32_t    REG3_AENDR;
    volatile    uint32_t    RESERVED10;
    volatile    uint32_t    REG3_BCFGR;
    volatile    uint32_t    REG3_BSTARTR;
    volatile    uint32_t    REG3_BENDR;
    volatile    uint32_t    RESERVED11[5];
    volatile    uint32_t    REG4_CFGR;
    volatile    uint32_t    REG4_STARTR;
    volatile    uint32_t    REG4_ENDR;
    volatile    uint32_t    RESERVED12;
    volatile    uint32_t    REG4_ACFGR;
    volatile    uint32_t    REG4_ASTARTR;
    volatile    uint32_t    REG4_AENDR;
    volatile    uint32_t    RESERVED13;
    volatile    uint32_t    REG4_BCFGR;
    volatile    uint32_t    REG4_BSTARTR;
    volatile    uint32_t    REG4_BENDR;
    volatile    uint32_t    RESERVED14[5];
    volatile    uint32_t    REG5_CFGR;
    volatile    uint32_t    REG5_STARTR;
    volatile    uint32_t    REG5_ENDR;
    volatile    uint32_t    RESERVED15;
    volatile    uint32_t    REG5_ACFGR;
    volatile    uint32_t    REG5_ASTARTR;
    volatile    uint32_t    REG5_AENDR;
    volatile    uint32_t    RESERVED16;
    volatile    uint32_t    REG5_BCFGR;
    volatile    uint32_t    REG5_BSTARTR;
    volatile    uint32_t    REG5_BENDR;
    volatile    uint32_t    RESERVED17[5];
    volatile    uint32_t    REG6_CFGR;
    volatile    uint32_t    REG6_STARTR;
    volatile    uint32_t    REG6_ENDR;
    volatile    uint32_t    RESERVED18;
    volatile    uint32_t    REG6_ACFGR;
    volatile    uint32_t    REG6_ASTARTR;
    volatile    uint32_t    REG6_AENDR;
    volatile    uint32_t    RESERVED19;
    volatile    uint32_t    REG6_BCFGR;
    volatile    uint32_t    REG6_BSTARTR;
    volatile    uint32_t    REG6_BENDR;
    volatile    uint32_t    RESERVED20[5];
    volatile    uint32_t    REG7_CFGR;
    volatile    uint32_t    REG7_STARTR;
    volatile    uint32_t    REG7_ENDR;
    volatile    uint32_t    RESERVED21;
    volatile    uint32_t    REG7_ACFGR;
    volatile    uint32_t    REG7_ASTARTR;
    volatile    uint32_t    REG7_AENDR;
    volatile    uint32_t    RESERVED22;
    volatile    uint32_t    REG7_BCFGR;
    volatile    uint32_t    REG7_BSTARTR;
    volatile    uint32_t    REG7_BENDR;
} RISAF_TypeDef;

#if (defined(__cplusplus))
#define RISAF_NS    reinterpret_cast<RISAF_TypeDef *>(0x480FE000u)
#define RISAF_S     reinterpret_cast<RISAF_TypeDef *>(0x580FE000u)

#else
#define RISAF_NS    ((RISAF_TypeDef *)0x480FE000u)
#define RISAF_S     ((RISAF_TypeDef *)0x580FE000u)
#endif

// CR Configuration

#define RISAF_CR_GLOCK                  (0x1u<<0)

#define RISAF_CR_GLOCK_B_0X0            (0x0u<<0)
#define RISAF_CR_GLOCK_B_0X1            (0x1u<<0)

// IASR Configuration

#define RISAF_IASR_IAEF                 (0x1u<<1)
#define RISAF_IASR_CAEF                 (0x1u<<0)

// IACR Configuration

#define RISAF_IACR_IAEF                 (0x1u<<1)
#define RISAF_IACR_CAEF                 (0x1u<<0)

// IAESR Configuration

#define RISAF_IAESR_IANRW               (0x1u<<7)
#define RISAF_IAESR_IASEC               (0x1u<<5)
#define RISAF_IAESR_IAPRIV              (0x1u<<4)

#define RISAF_IAESR_IANRW_B_0X0         (0x0u<<7)
#define RISAF_IAESR_IANRW_B_0X1         (0x1u<<7)
#define RISAF_IAESR_IASEC_B_0X0         (0x0u<<5)
#define RISAF_IAESR_IASEC_B_0X1         (0x1u<<5)
#define RISAF_IAESR_IAPRIV_B_0X0        (0x0u<<4)
#define RISAF_IAESR_IAPRIV_B_0X1        (0x1u<<4)

// IADDR Configuration

#define RISAF_IADDR_IADD                (0xFFFFFFFFu<<0)
#define RISAF_IADDR_IADD_0              (0x1u<<0)

// REG1_CFGR Configuration

#define RISAF_REG1_CFGR_SEC             (0x1u<<8)
#define RISAF_REG1_CFGR_BREN            (0x1u<<0)

#define RISAF_REG1_CFGR_SEC_B_0X0       (0x0u<<8)
#define RISAF_REG1_CFGR_SEC_B_0X1       (0x1u<<8)
#define RISAF_REG1_CFGR_BREN_B_0X0      (0x0u<<0)
#define RISAF_REG1_CFGR_BREN_B_0X1      (0x1u<<0)

// REG1_STARTR Configuration

#define RISAF_REG1_STARTR_BADDSTART     (0xFFFFFFFFu<<0)
#define RISAF_REG1_STARTR_BADDSTART_0   (0x1u<<0)

// REG1_ENDR Configuration

#define RISAF_REG1_ENDR_BADDEND         (0xFFFFFFFFu<<0)
#define RISAF_REG1_ENDR_BADDEND_0       (0x1u<<0)

// REG1_ACFGR Configuration

#define RISAF_REG1_ACFGR_WREN           (0x1u<<13)
#define RISAF_REG1_ACFGR_RDEN           (0x1u<<12)
#define RISAF_REG1_ACFGR_PRIV           (0x1u<<9)
#define RISAF_REG1_ACFGR_SEC            (0x1u<<8)
#define RISAF_REG1_ACFGR_RLOCK          (0x1u<<1)
#define RISAF_REG1_ACFGR_SREN           (0x1u<<0)

#define RISAF_REG1_ACFGR_WREN_B_0X0     (0x0u<<13)
#define RISAF_REG1_ACFGR_WREN_B_0X1     (0x1u<<13)
#define RISAF_REG1_ACFGR_RDEN_B_0X0     (0x0u<<12)
#define RISAF_REG1_ACFGR_RDEN_B_0X1     (0x1u<<12)
#define RISAF_REG1_ACFGR_PRIV_B_0X0     (0x0u<<9)
#define RISAF_REG1_ACFGR_PRIV_B_0X1     (0x1u<<9)
#define RISAF_REG1_ACFGR_SEC_B_0X0      (0x0u<<8)
#define RISAF_REG1_ACFGR_SEC_B_0X1      (0x1u<<8)
#define RISAF_REG1_ACFGR_RLOCK_B_0X0    (0x0u<<1)
#define RISAF_REG1_ACFGR_RLOCK_B_0X1    (0x1u<<1)
#define RISAF_REG1_ACFGR_SREN_B_0X0     (0x0u<<0)
#define RISAF_REG1_ACFGR_SREN_B_0X1     (0x1u<<0)

// REG1_ASTARTR Configuration

#define RISAF_REG1_ASTARTR_SADDSTART    (0xFFFFFFFFu<<0)
#define RISAF_REG1_ASTARTR_SADDSTART_0  (0x1u<<0)

// REG1_AENDR Configuration

#define RISAF_REG1_AENDR_SADDEND        (0xFFFFFFFFu<<0)
#define RISAF_REG1_AENDR_SADDEND_0      (0x1u<<0)

// REG1_BCFGR Configuration

#define RISAF_REG1_BCFGR_WREN           (0x1u<<13)
#define RISAF_REG1_BCFGR_RDEN           (0x1u<<12)
#define RISAF_REG1_BCFGR_PRIV           (0x1u<<9)
#define RISAF_REG1_BCFGR_SEC            (0x1u<<8)
#define RISAF_REG1_BCFGR_RLOCK          (0x1u<<1)
#define RISAF_REG1_BCFGR_SREN           (0x1u<<0)

#define RISAF_REG1_BCFGR_WREN_B_0X0     (0x0u<<13)
#define RISAF_REG1_BCFGR_WREN_B_0X1     (0x1u<<13)
#define RISAF_REG1_BCFGR_RDEN_B_0X0     (0x0u<<12)
#define RISAF_REG1_BCFGR_RDEN_B_0X1     (0x1u<<12)
#define RISAF_REG1_BCFGR_PRIV_B_0X0     (0x0u<<9)
#define RISAF_REG1_BCFGR_PRIV_B_0X1     (0x1u<<9)
#define RISAF_REG1_BCFGR_SEC_B_0X0      (0x0u<<8)
#define RISAF_REG1_BCFGR_SEC_B_0X1      (0x1u<<8)
#define RISAF_REG1_BCFGR_RLOCK_B_0X0    (0x0u<<1)
#define RISAF_REG1_BCFGR_RLOCK_B_0X1    (0x1u<<1)
#define RISAF_REG1_BCFGR_SREN_B_0X0     (0x0u<<0)
#define RISAF_REG1_BCFGR_SREN_B_0X1     (0x1u<<0)

// REG1_BSTARTR Configuration

#define RISAF_REG1_BSTARTR_SADDSTART    (0xFFFFFFFFu<<0)
#define RISAF_REG1_BSTARTR_SADDSTART_0  (0x1u<<0)

// REG1_BENDR Configuration

#define RISAF_REG1_BENDR_SADDEND        (0xFFFFFFFFu<<0)
#define RISAF_REG1_BENDR_SADDEND_0      (0x1u<<0)

// REG2_CFGR Configuration

#define RISAF_REG2_CFGR_SEC             (0x1u<<8)
#define RISAF_REG2_CFGR_BREN            (0x1u<<0)

#define RISAF_REG2_CFGR_SEC_B_0X0       (0x0u<<8)
#define RISAF_REG2_CFGR_SEC_B_0X1       (0x1u<<8)
#define RISAF_REG2_CFGR_BREN_B_0X0      (0x0u<<0)
#define RISAF_REG2_CFGR_BREN_B_0X1      (0x1u<<0)

// REG2_STARTR Configuration

#define RISAF_REG2_STARTR_BADDSTART     (0xFFFFFFFFu<<0)
#define RISAF_REG2_STARTR_BADDSTART_0   (0x1u<<0)

// REG2_ENDR Configuration

#define RISAF_REG2_ENDR_BADDEND         (0xFFFFFFFFu<<0)
#define RISAF_REG2_ENDR_BADDEND_0       (0x1u<<0)

// REG2_ACFGR Configuration

#define RISAF_REG2_ACFGR_WREN           (0x1u<<13)
#define RISAF_REG2_ACFGR_RDEN           (0x1u<<12)
#define RISAF_REG2_ACFGR_PRIV           (0x1u<<9)
#define RISAF_REG2_ACFGR_SEC            (0x1u<<8)
#define RISAF_REG2_ACFGR_RLOCK          (0x1u<<1)
#define RISAF_REG2_ACFGR_SREN           (0x1u<<0)

#define RISAF_REG2_ACFGR_WREN_B_0X0     (0x0u<<13)
#define RISAF_REG2_ACFGR_WREN_B_0X1     (0x1u<<13)
#define RISAF_REG2_ACFGR_RDEN_B_0X0     (0x0u<<12)
#define RISAF_REG2_ACFGR_RDEN_B_0X1     (0x1u<<12)
#define RISAF_REG2_ACFGR_PRIV_B_0X0     (0x0u<<9)
#define RISAF_REG2_ACFGR_PRIV_B_0X1     (0x1u<<9)
#define RISAF_REG2_ACFGR_SEC_B_0X0      (0x0u<<8)
#define RISAF_REG2_ACFGR_SEC_B_0X1      (0x1u<<8)
#define RISAF_REG2_ACFGR_RLOCK_B_0X0    (0x0u<<1)
#define RISAF_REG2_ACFGR_RLOCK_B_0X1    (0x1u<<1)
#define RISAF_REG2_ACFGR_SREN_B_0X0     (0x0u<<0)
#define RISAF_REG2_ACFGR_SREN_B_0X1     (0x1u<<0)

// REG2_ASTARTR Configuration

#define RISAF_REG2_ASTARTR_SADDSTART    (0xFFFFFFFFu<<0)
#define RISAF_REG2_ASTARTR_SADDSTART_0  (0x1u<<0)

// REG2_AENDR Configuration

#define RISAF_REG2_AENDR_SADDEND        (0xFFFFFFFFu<<0)
#define RISAF_REG2_AENDR_SADDEND_0      (0x1u<<0)

// REG2_BCFGR Configuration

#define RISAF_REG2_BCFGR_WREN           (0x1u<<13)
#define RISAF_REG2_BCFGR_RDEN           (0x1u<<12)
#define RISAF_REG2_BCFGR_PRIV           (0x1u<<9)
#define RISAF_REG2_BCFGR_SEC            (0x1u<<8)
#define RISAF_REG2_BCFGR_RLOCK          (0x1u<<1)
#define RISAF_REG2_BCFGR_SREN           (0x1u<<0)

#define RISAF_REG2_BCFGR_WREN_B_0X0     (0x0u<<13)
#define RISAF_REG2_BCFGR_WREN_B_0X1     (0x1u<<13)
#define RISAF_REG2_BCFGR_RDEN_B_0X0     (0x0u<<12)
#define RISAF_REG2_BCFGR_RDEN_B_0X1     (0x1u<<12)
#define RISAF_REG2_BCFGR_PRIV_B_0X0     (0x0u<<9)
#define RISAF_REG2_BCFGR_PRIV_B_0X1     (0x1u<<9)
#define RISAF_REG2_BCFGR_SEC_B_0X0      (0x0u<<8)
#define RISAF_REG2_BCFGR_SEC_B_0X1      (0x1u<<8)
#define RISAF_REG2_BCFGR_RLOCK_B_0X0    (0x0u<<1)
#define RISAF_REG2_BCFGR_RLOCK_B_0X1    (0x1u<<1)
#define RISAF_REG2_BCFGR_SREN_B_0X0     (0x0u<<0)
#define RISAF_REG2_BCFGR_SREN_B_0X1     (0x1u<<0)

// REG2_BSTARTR Configuration

#define RISAF_REG2_BSTARTR_SADDSTART    (0xFFFFFFFFu<<0)
#define RISAF_REG2_BSTARTR_SADDSTART_0  (0x1u<<0)

// REG2_BENDR Configuration

#define RISAF_REG2_BENDR_SADDEND        (0xFFFFFFFFu<<0)
#define RISAF_REG2_BENDR_SADDEND_0      (0x1u<<0)

// REG3_CFGR Configuration

#define RISAF_REG3_CFGR_SEC             (0x1u<<8)
#define RISAF_REG3_CFGR_BREN            (0x1u<<0)

#define RISAF_REG3_CFGR_SEC_B_0X0       (0x0u<<8)
#define RISAF_REG3_CFGR_SEC_B_0X1       (0x1u<<8)
#define RISAF_REG3_CFGR_BREN_B_0X0      (0x0u<<0)
#define RISAF_REG3_CFGR_BREN_B_0X1      (0x1u<<0)

// REG3_STARTR Configuration

#define RISAF_REG3_STARTR_BADDSTART     (0xFFFFFFFFu<<0)
#define RISAF_REG3_STARTR_BADDSTART_0   (0x1u<<0)

// REG3_ENDR Configuration

#define RISAF_REG3_ENDR_BADDEND         (0xFFFFFFFFu<<0)
#define RISAF_REG3_ENDR_BADDEND_0       (0x1u<<0)

// REG3_ACFGR Configuration

#define RISAF_REG3_ACFGR_WREN           (0x1u<<13)
#define RISAF_REG3_ACFGR_RDEN           (0x1u<<12)
#define RISAF_REG3_ACFGR_PRIV           (0x1u<<9)
#define RISAF_REG3_ACFGR_SEC            (0x1u<<8)
#define RISAF_REG3_ACFGR_RLOCK          (0x1u<<1)
#define RISAF_REG3_ACFGR_SREN           (0x1u<<0)

#define RISAF_REG3_ACFGR_WREN_B_0X0     (0x0u<<13)
#define RISAF_REG3_ACFGR_WREN_B_0X1     (0x1u<<13)
#define RISAF_REG3_ACFGR_RDEN_B_0X0     (0x0u<<12)
#define RISAF_REG3_ACFGR_RDEN_B_0X1     (0x1u<<12)
#define RISAF_REG3_ACFGR_PRIV_B_0X0     (0x0u<<9)
#define RISAF_REG3_ACFGR_PRIV_B_0X1     (0x1u<<9)
#define RISAF_REG3_ACFGR_SEC_B_0X0      (0x0u<<8)
#define RISAF_REG3_ACFGR_SEC_B_0X1      (0x1u<<8)
#define RISAF_REG3_ACFGR_RLOCK_B_0X0    (0x0u<<1)
#define RISAF_REG3_ACFGR_RLOCK_B_0X1    (0x1u<<1)
#define RISAF_REG3_ACFGR_SREN_B_0X0     (0x0u<<0)
#define RISAF_REG3_ACFGR_SREN_B_0X1     (0x1u<<0)

// REG3_ASTARTR Configuration

#define RISAF_REG3_ASTARTR_SADDSTART    (0xFFFFFFFFu<<0)
#define RISAF_REG3_ASTARTR_SADDSTART_0  (0x1u<<0)

// REG3_AENDR Configuration

#define RISAF_REG3_AENDR_SADDEND        (0xFFFFFFFFu<<0)
#define RISAF_REG3_AENDR_SADDEND_0      (0x1u<<0)

// REG3_BCFGR Configuration

#define RISAF_REG3_BCFGR_WREN           (0x1u<<13)
#define RISAF_REG3_BCFGR_RDEN           (0x1u<<12)
#define RISAF_REG3_BCFGR_PRIV           (0x1u<<9)
#define RISAF_REG3_BCFGR_SEC            (0x1u<<8)
#define RISAF_REG3_BCFGR_RLOCK          (0x1u<<1)
#define RISAF_REG3_BCFGR_SREN           (0x1u<<0)

#define RISAF_REG3_BCFGR_WREN_B_0X0     (0x0u<<13)
#define RISAF_REG3_BCFGR_WREN_B_0X1     (0x1u<<13)
#define RISAF_REG3_BCFGR_RDEN_B_0X0     (0x0u<<12)
#define RISAF_REG3_BCFGR_RDEN_B_0X1     (0x1u<<12)
#define RISAF_REG3_BCFGR_PRIV_B_0X0     (0x0u<<9)
#define RISAF_REG3_BCFGR_PRIV_B_0X1     (0x1u<<9)
#define RISAF_REG3_BCFGR_SEC_B_0X0      (0x0u<<8)
#define RISAF_REG3_BCFGR_SEC_B_0X1      (0x1u<<8)
#define RISAF_REG3_BCFGR_RLOCK_B_0X0    (0x0u<<1)
#define RISAF_REG3_BCFGR_RLOCK_B_0X1    (0x1u<<1)
#define RISAF_REG3_BCFGR_SREN_B_0X0     (0x0u<<0)
#define RISAF_REG3_BCFGR_SREN_B_0X1     (0x1u<<0)

// REG3_BSTARTR Configuration

#define RISAF_REG3_BSTARTR_SADDSTART    (0xFFFFFFFFu<<0)
#define RISAF_REG3_BSTARTR_SADDSTART_0  (0x1u<<0)

// REG3_BENDR Configuration

#define RISAF_REG3_BENDR_SADDEND        (0xFFFFFFFFu<<0)
#define RISAF_REG3_BENDR_SADDEND_0      (0x1u<<0)

// REG4_CFGR Configuration

#define RISAF_REG4_CFGR_SEC             (0x1u<<8)
#define RISAF_REG4_CFGR_BREN            (0x1u<<0)

#define RISAF_REG4_CFGR_SEC_B_0X0       (0x0u<<8)
#define RISAF_REG4_CFGR_SEC_B_0X1       (0x1u<<8)
#define RISAF_REG4_CFGR_BREN_B_0X0      (0x0u<<0)
#define RISAF_REG4_CFGR_BREN_B_0X1      (0x1u<<0)

// REG4_STARTR Configuration

#define RISAF_REG4_STARTR_BADDSTART     (0xFFFFFFFFu<<0)
#define RISAF_REG4_STARTR_BADDSTART_0   (0x1u<<0)

// REG4_ENDR Configuration

#define RISAF_REG4_ENDR_BADDEND         (0xFFFFFFFFu<<0)
#define RISAF_REG4_ENDR_BADDEND_0       (0x1u<<0)

// REG4_ACFGR Configuration

#define RISAF_REG4_ACFGR_WREN           (0x1u<<13)
#define RISAF_REG4_ACFGR_RDEN           (0x1u<<12)
#define RISAF_REG4_ACFGR_PRIV           (0x1u<<9)
#define RISAF_REG4_ACFGR_SEC            (0x1u<<8)
#define RISAF_REG4_ACFGR_RLOCK          (0x1u<<1)
#define RISAF_REG4_ACFGR_SREN           (0x1u<<0)

#define RISAF_REG4_ACFGR_WREN_B_0X0     (0x0u<<13)
#define RISAF_REG4_ACFGR_WREN_B_0X1     (0x1u<<13)
#define RISAF_REG4_ACFGR_RDEN_B_0X0     (0x0u<<12)
#define RISAF_REG4_ACFGR_RDEN_B_0X1     (0x1u<<12)
#define RISAF_REG4_ACFGR_PRIV_B_0X0     (0x0u<<9)
#define RISAF_REG4_ACFGR_PRIV_B_0X1     (0x1u<<9)
#define RISAF_REG4_ACFGR_SEC_B_0X0      (0x0u<<8)
#define RISAF_REG4_ACFGR_SEC_B_0X1      (0x1u<<8)
#define RISAF_REG4_ACFGR_RLOCK_B_0X0    (0x0u<<1)
#define RISAF_REG4_ACFGR_RLOCK_B_0X1    (0x1u<<1)
#define RISAF_REG4_ACFGR_SREN_B_0X0     (0x0u<<0)
#define RISAF_REG4_ACFGR_SREN_B_0X1     (0x1u<<0)

// REG4_ASTARTR Configuration

#define RISAF_REG4_ASTARTR_SADDSTART    (0xFFFFFFFFu<<0)
#define RISAF_REG4_ASTARTR_SADDSTART_0  (0x1u<<0)

// REG4_AENDR Configuration

#define RISAF_REG4_AENDR_SADDEND        (0xFFFFFFFFu<<0)
#define RISAF_REG4_AENDR_SADDEND_0      (0x1u<<0)

// REG4_BCFGR Configuration

#define RISAF_REG4_BCFGR_WREN           (0x1u<<13)
#define RISAF_REG4_BCFGR_RDEN           (0x1u<<12)
#define RISAF_REG4_BCFGR_PRIV           (0x1u<<9)
#define RISAF_REG4_BCFGR_SEC            (0x1u<<8)
#define RISAF_REG4_BCFGR_RLOCK          (0x1u<<1)
#define RISAF_REG4_BCFGR_SREN           (0x1u<<0)

#define RISAF_REG4_BCFGR_WREN_B_0X0     (0x0u<<13)
#define RISAF_REG4_BCFGR_WREN_B_0X1     (0x1u<<13)
#define RISAF_REG4_BCFGR_RDEN_B_0X0     (0x0u<<12)
#define RISAF_REG4_BCFGR_RDEN_B_0X1     (0x1u<<12)
#define RISAF_REG4_BCFGR_PRIV_B_0X0     (0x0u<<9)
#define RISAF_REG4_BCFGR_PRIV_B_0X1     (0x1u<<9)
#define RISAF_REG4_BCFGR_SEC_B_0X0      (0x0u<<8)
#define RISAF_REG4_BCFGR_SEC_B_0X1      (0x1u<<8)
#define RISAF_REG4_BCFGR_RLOCK_B_0X0    (0x0u<<1)
#define RISAF_REG4_BCFGR_RLOCK_B_0X1    (0x1u<<1)
#define RISAF_REG4_BCFGR_SREN_B_0X0     (0x0u<<0)
#define RISAF_REG4_BCFGR_SREN_B_0X1     (0x1u<<0)

// REG4_BSTARTR Configuration

#define RISAF_REG4_BSTARTR_SADDSTART    (0xFFFFFFFFu<<0)
#define RISAF_REG4_BSTARTR_SADDSTART_0  (0x1u<<0)

// REG4_BENDR Configuration

#define RISAF_REG4_BENDR_SADDEND        (0xFFFFFFFFu<<0)
#define RISAF_REG4_BENDR_SADDEND_0      (0x1u<<0)

// REG5_CFGR Configuration

#define RISAF_REG5_CFGR_SEC             (0x1u<<8)
#define RISAF_REG5_CFGR_BREN            (0x1u<<0)

#define RISAF_REG5_CFGR_SEC_B_0X0       (0x0u<<8)
#define RISAF_REG5_CFGR_SEC_B_0X1       (0x1u<<8)
#define RISAF_REG5_CFGR_BREN_B_0X0      (0x0u<<0)
#define RISAF_REG5_CFGR_BREN_B_0X1      (0x1u<<0)

// REG5_STARTR Configuration

#define RISAF_REG5_STARTR_BADDSTART     (0xFFFFFFFFu<<0)
#define RISAF_REG5_STARTR_BADDSTART_0   (0x1u<<0)

// REG5_ENDR Configuration

#define RISAF_REG5_ENDR_BADDEND         (0xFFFFFFFFu<<0)
#define RISAF_REG5_ENDR_BADDEND_0       (0x1u<<0)

// REG5_ACFGR Configuration

#define RISAF_REG5_ACFGR_WREN           (0x1u<<13)
#define RISAF_REG5_ACFGR_RDEN           (0x1u<<12)
#define RISAF_REG5_ACFGR_PRIV           (0x1u<<9)
#define RISAF_REG5_ACFGR_SEC            (0x1u<<8)
#define RISAF_REG5_ACFGR_RLOCK          (0x1u<<1)
#define RISAF_REG5_ACFGR_SREN           (0x1u<<0)

#define RISAF_REG5_ACFGR_WREN_B_0X0     (0x0u<<13)
#define RISAF_REG5_ACFGR_WREN_B_0X1     (0x1u<<13)
#define RISAF_REG5_ACFGR_RDEN_B_0X0     (0x0u<<12)
#define RISAF_REG5_ACFGR_RDEN_B_0X1     (0x1u<<12)
#define RISAF_REG5_ACFGR_PRIV_B_0X0     (0x0u<<9)
#define RISAF_REG5_ACFGR_PRIV_B_0X1     (0x1u<<9)
#define RISAF_REG5_ACFGR_SEC_B_0X0      (0x0u<<8)
#define RISAF_REG5_ACFGR_SEC_B_0X1      (0x1u<<8)
#define RISAF_REG5_ACFGR_RLOCK_B_0X0    (0x0u<<1)
#define RISAF_REG5_ACFGR_RLOCK_B_0X1    (0x1u<<1)
#define RISAF_REG5_ACFGR_SREN_B_0X0     (0x0u<<0)
#define RISAF_REG5_ACFGR_SREN_B_0X1     (0x1u<<0)

// REG5_ASTARTR Configuration

#define RISAF_REG5_ASTARTR_SADDSTART    (0xFFFFFFFFu<<0)
#define RISAF_REG5_ASTARTR_SADDSTART_0  (0x1u<<0)

// REG5_AENDR Configuration

#define RISAF_REG5_AENDR_SADDEND        (0xFFFFFFFFu<<0)
#define RISAF_REG5_AENDR_SADDEND_0      (0x1u<<0)

// REG5_BCFGR Configuration

#define RISAF_REG5_BCFGR_WREN           (0x1u<<13)
#define RISAF_REG5_BCFGR_RDEN           (0x1u<<12)
#define RISAF_REG5_BCFGR_PRIV           (0x1u<<9)
#define RISAF_REG5_BCFGR_SEC            (0x1u<<8)
#define RISAF_REG5_BCFGR_RLOCK          (0x1u<<1)
#define RISAF_REG5_BCFGR_SREN           (0x1u<<0)

#define RISAF_REG5_BCFGR_WREN_B_0X0     (0x0u<<13)
#define RISAF_REG5_BCFGR_WREN_B_0X1     (0x1u<<13)
#define RISAF_REG5_BCFGR_RDEN_B_0X0     (0x0u<<12)
#define RISAF_REG5_BCFGR_RDEN_B_0X1     (0x1u<<12)
#define RISAF_REG5_BCFGR_PRIV_B_0X0     (0x0u<<9)
#define RISAF_REG5_BCFGR_PRIV_B_0X1     (0x1u<<9)
#define RISAF_REG5_BCFGR_SEC_B_0X0      (0x0u<<8)
#define RISAF_REG5_BCFGR_SEC_B_0X1      (0x1u<<8)
#define RISAF_REG5_BCFGR_RLOCK_B_0X0    (0x0u<<1)
#define RISAF_REG5_BCFGR_RLOCK_B_0X1    (0x1u<<1)
#define RISAF_REG5_BCFGR_SREN_B_0X0     (0x0u<<0)
#define RISAF_REG5_BCFGR_SREN_B_0X1     (0x1u<<0)

// REG5_BSTARTR Configuration

#define RISAF_REG5_BSTARTR_SADDSTART    (0xFFFFFFFFu<<0)
#define RISAF_REG5_BSTARTR_SADDSTART_0  (0x1u<<0)

// REG5_BENDR Configuration

#define RISAF_REG5_BENDR_SADDEND        (0xFFFFFFFFu<<0)
#define RISAF_REG5_BENDR_SADDEND_0      (0x1u<<0)

// REG6_CFGR Configuration

#define RISAF_REG6_CFGR_SEC             (0x1u<<8)
#define RISAF_REG6_CFGR_BREN            (0x1u<<0)

#define RISAF_REG6_CFGR_SEC_B_0X0       (0x0u<<8)
#define RISAF_REG6_CFGR_SEC_B_0X1       (0x1u<<8)
#define RISAF_REG6_CFGR_BREN_B_0X0      (0x0u<<0)
#define RISAF_REG6_CFGR_BREN_B_0X1      (0x1u<<0)

// REG6_STARTR Configuration

#define RISAF_REG6_STARTR_BADDSTART     (0xFFFFFFFFu<<0)
#define RISAF_REG6_STARTR_BADDSTART_0   (0x1u<<0)

// REG6_ENDR Configuration

#define RISAF_REG6_ENDR_BADDEND         (0xFFFFFFFFu<<0)
#define RISAF_REG6_ENDR_BADDEND_0       (0x1u<<0)

// REG6_ACFGR Configuration

#define RISAF_REG6_ACFGR_WREN           (0x1u<<13)
#define RISAF_REG6_ACFGR_RDEN           (0x1u<<12)
#define RISAF_REG6_ACFGR_PRIV           (0x1u<<9)
#define RISAF_REG6_ACFGR_SEC            (0x1u<<8)
#define RISAF_REG6_ACFGR_RLOCK          (0x1u<<1)
#define RISAF_REG6_ACFGR_SREN           (0x1u<<0)

#define RISAF_REG6_ACFGR_WREN_B_0X0     (0x0u<<13)
#define RISAF_REG6_ACFGR_WREN_B_0X1     (0x1u<<13)
#define RISAF_REG6_ACFGR_RDEN_B_0X0     (0x0u<<12)
#define RISAF_REG6_ACFGR_RDEN_B_0X1     (0x1u<<12)
#define RISAF_REG6_ACFGR_PRIV_B_0X0     (0x0u<<9)
#define RISAF_REG6_ACFGR_PRIV_B_0X1     (0x1u<<9)
#define RISAF_REG6_ACFGR_SEC_B_0X0      (0x0u<<8)
#define RISAF_REG6_ACFGR_SEC_B_0X1      (0x1u<<8)
#define RISAF_REG6_ACFGR_RLOCK_B_0X0    (0x0u<<1)
#define RISAF_REG6_ACFGR_RLOCK_B_0X1    (0x1u<<1)
#define RISAF_REG6_ACFGR_SREN_B_0X0     (0x0u<<0)
#define RISAF_REG6_ACFGR_SREN_B_0X1     (0x1u<<0)

// REG6_ASTARTR Configuration

#define RISAF_REG6_ASTARTR_SADDSTART    (0xFFFFFFFFu<<0)
#define RISAF_REG6_ASTARTR_SADDSTART_0  (0x1u<<0)

// REG6_AENDR Configuration

#define RISAF_REG6_AENDR_SADDEND        (0xFFFFFFFFu<<0)
#define RISAF_REG6_AENDR_SADDEND_0      (0x1u<<0)

// REG6_BCFGR Configuration

#define RISAF_REG6_BCFGR_WREN           (0x1u<<13)
#define RISAF_REG6_BCFGR_RDEN           (0x1u<<12)
#define RISAF_REG6_BCFGR_PRIV           (0x1u<<9)
#define RISAF_REG6_BCFGR_SEC            (0x1u<<8)
#define RISAF_REG6_BCFGR_RLOCK          (0x1u<<1)
#define RISAF_REG6_BCFGR_SREN           (0x1u<<0)

#define RISAF_REG6_BCFGR_WREN_B_0X0     (0x0u<<13)
#define RISAF_REG6_BCFGR_WREN_B_0X1     (0x1u<<13)
#define RISAF_REG6_BCFGR_RDEN_B_0X0     (0x0u<<12)
#define RISAF_REG6_BCFGR_RDEN_B_0X1     (0x1u<<12)
#define RISAF_REG6_BCFGR_PRIV_B_0X0     (0x0u<<9)
#define RISAF_REG6_BCFGR_PRIV_B_0X1     (0x1u<<9)
#define RISAF_REG6_BCFGR_SEC_B_0X0      (0x0u<<8)
#define RISAF_REG6_BCFGR_SEC_B_0X1      (0x1u<<8)
#define RISAF_REG6_BCFGR_RLOCK_B_0X0    (0x0u<<1)
#define RISAF_REG6_BCFGR_RLOCK_B_0X1    (0x1u<<1)
#define RISAF_REG6_BCFGR_SREN_B_0X0     (0x0u<<0)
#define RISAF_REG6_BCFGR_SREN_B_0X1     (0x1u<<0)

// REG6_BSTARTR Configuration

#define RISAF_REG6_BSTARTR_SADDSTART    (0xFFFFFFFFu<<0)
#define RISAF_REG6_BSTARTR_SADDSTART_0  (0x1u<<0)

// REG6_BENDR Configuration

#define RISAF_REG6_BENDR_SADDEND        (0xFFFFFFFFu<<0)
#define RISAF_REG6_BENDR_SADDEND_0      (0x1u<<0)

// REG7_CFGR Configuration

#define RISAF_REG7_CFGR_SEC             (0x1u<<8)
#define RISAF_REG7_CFGR_BREN            (0x1u<<0)

#define RISAF_REG7_CFGR_SEC_B_0X0       (0x0u<<8)
#define RISAF_REG7_CFGR_SEC_B_0X1       (0x1u<<8)
#define RISAF_REG7_CFGR_BREN_B_0X0      (0x0u<<0)
#define RISAF_REG7_CFGR_BREN_B_0X1      (0x1u<<0)

// REG7_STARTR Configuration

#define RISAF_REG7_STARTR_BADDSTART     (0xFFFFFFFFu<<0)
#define RISAF_REG7_STARTR_BADDSTART_0   (0x1u<<0)

// REG7_ENDR Configuration

#define RISAF_REG7_ENDR_BADDEND         (0xFFFFFFFFu<<0)
#define RISAF_REG7_ENDR_BADDEND_0       (0x1u<<0)

// REG7_ACFGR Configuration

#define RISAF_REG7_ACFGR_WREN           (0x1u<<13)
#define RISAF_REG7_ACFGR_RDEN           (0x1u<<12)
#define RISAF_REG7_ACFGR_PRIV           (0x1u<<9)
#define RISAF_REG7_ACFGR_SEC            (0x1u<<8)
#define RISAF_REG7_ACFGR_RLOCK          (0x1u<<1)
#define RISAF_REG7_ACFGR_SREN           (0x1u<<0)

#define RISAF_REG7_ACFGR_WREN_B_0X0     (0x0u<<13)
#define RISAF_REG7_ACFGR_WREN_B_0X1     (0x1u<<13)
#define RISAF_REG7_ACFGR_RDEN_B_0X0     (0x0u<<12)
#define RISAF_REG7_ACFGR_RDEN_B_0X1     (0x1u<<12)
#define RISAF_REG7_ACFGR_PRIV_B_0X0     (0x0u<<9)
#define RISAF_REG7_ACFGR_PRIV_B_0X1     (0x1u<<9)
#define RISAF_REG7_ACFGR_SEC_B_0X0      (0x0u<<8)
#define RISAF_REG7_ACFGR_SEC_B_0X1      (0x1u<<8)
#define RISAF_REG7_ACFGR_RLOCK_B_0X0    (0x0u<<1)
#define RISAF_REG7_ACFGR_RLOCK_B_0X1    (0x1u<<1)
#define RISAF_REG7_ACFGR_SREN_B_0X0     (0x0u<<0)
#define RISAF_REG7_ACFGR_SREN_B_0X1     (0x1u<<0)

// REG7_ASTARTR Configuration

#define RISAF_REG7_ASTARTR_SADDSTART    (0xFFFFFFFFu<<0)
#define RISAF_REG7_ASTARTR_SADDSTART_0  (0x1u<<0)

// REG7_AENDR Configuration

#define RISAF_REG7_AENDR_SADDEND        (0xFFFFFFFFu<<0)
#define RISAF_REG7_AENDR_SADDEND_0      (0x1u<<0)

// REG7_BCFGR Configuration

#define RISAF_REG7_BCFGR_WREN           (0x1u<<13)
#define RISAF_REG7_BCFGR_RDEN           (0x1u<<12)
#define RISAF_REG7_BCFGR_PRIV           (0x1u<<9)
#define RISAF_REG7_BCFGR_SEC            (0x1u<<8)
#define RISAF_REG7_BCFGR_RLOCK          (0x1u<<1)
#define RISAF_REG7_BCFGR_SREN           (0x1u<<0)

#define RISAF_REG7_BCFGR_WREN_B_0X0     (0x0u<<13)
#define RISAF_REG7_BCFGR_WREN_B_0X1     (0x1u<<13)
#define RISAF_REG7_BCFGR_RDEN_B_0X0     (0x0u<<12)
#define RISAF_REG7_BCFGR_RDEN_B_0X1     (0x1u<<12)
#define RISAF_REG7_BCFGR_PRIV_B_0X0     (0x0u<<9)
#define RISAF_REG7_BCFGR_PRIV_B_0X1     (0x1u<<9)
#define RISAF_REG7_BCFGR_SEC_B_0X0      (0x0u<<8)
#define RISAF_REG7_BCFGR_SEC_B_0X1      (0x1u<<8)
#define RISAF_REG7_BCFGR_RLOCK_B_0X0    (0x0u<<1)
#define RISAF_REG7_BCFGR_RLOCK_B_0X1    (0x1u<<1)
#define RISAF_REG7_BCFGR_SREN_B_0X0     (0x0u<<0)
#define RISAF_REG7_BCFGR_SREN_B_0X1     (0x1u<<0)

// REG7_BSTARTR Configuration

#define RISAF_REG7_BSTARTR_SADDSTART    (0xFFFFFFFFu<<0)
#define RISAF_REG7_BSTARTR_SADDSTART_0  (0x1u<<0)

// REG7_BENDR Configuration

#define RISAF_REG7_BENDR_SADDEND        (0xFFFFFFFFu<<0)
#define RISAF_REG7_BENDR_SADDEND_0      (0x1u<<0)
