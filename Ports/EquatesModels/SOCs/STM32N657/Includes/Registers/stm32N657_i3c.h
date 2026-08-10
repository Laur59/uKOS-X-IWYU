/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_i3c equates.
 */

#pragma once

#include    <stdint.h>

// I3C address definitions
// -----------------------

typedef struct {
        union {
    volatile    uint32_t    CR;
    volatile    uint32_t    CR_ALTERNATE;
        };
    volatile    uint32_t    CFGR;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    RDR;
    volatile    uint32_t    RDWR;
    volatile    uint32_t    TDR;
    volatile    uint32_t    TDWR;
    volatile    uint32_t    IBIDR;
    volatile    uint32_t    TGTTDR;
    volatile    uint32_t    RESERVED1[2];
    volatile    uint32_t    SR;
    volatile    uint32_t    SER;
    volatile    uint32_t    RESERVED2[2];
    volatile    uint32_t    RMR;
    volatile    uint32_t    RESERVED3[3];
    volatile    uint32_t    EVR;
    volatile    uint32_t    IER;
    volatile    uint32_t    CEVR;
    volatile    uint32_t    RESERVED4;
    volatile    uint32_t    DEVR0;
    volatile    uint32_t    DEVR1;
    volatile    uint32_t    DEVR2;
    volatile    uint32_t    DEVR3;
    volatile    uint32_t    DEVR4;
    volatile    uint32_t    RESERVED5[7];
    volatile    uint32_t    MAXRLR;
    volatile    uint32_t    MAXWLR;
    volatile    uint32_t    RESERVED6[2];
    volatile    uint32_t    TIMINGR0;
    volatile    uint32_t    TIMINGR1;
    volatile    uint32_t    TIMINGR2;
    volatile    uint32_t    RESERVED7[5];
    volatile    uint32_t    BCR;
    volatile    uint32_t    DCR;
    volatile    uint32_t    GETCAPR;
    volatile    uint32_t    CRCAPR;
    volatile    uint32_t    GETMXDSR;
    volatile    uint32_t    EPIDR;
} I3C_TypeDef;

#ifdef __cplusplus
#define I3C1_NS reinterpret_cast<I3C_TypeDef *>(0x40006000U)
#define I3C1_S  reinterpret_cast<I3C_TypeDef *>(0x50006000U)
#define I3C2_NS reinterpret_cast<I3C_TypeDef *>(0x40006400U)
#define I3C2_S  reinterpret_cast<I3C_TypeDef *>(0x50006400U)

#else
#define I3C1_NS ((I3C_TypeDef *)0x40006000U)
#define I3C1_S  ((I3C_TypeDef *)0x50006000U)
#define I3C2_NS ((I3C_TypeDef *)0x40006400U)
#define I3C2_S  ((I3C_TypeDef *)0x50006400U)
#endif

// CR Configuration

#define I3C_CR_MEND                                                     (0x1U<<31U)
#define I3C_CR_MTYPE                                                    (0xFU<<27U)
#define I3C_CR_MTYPE_0                                                  (0x1U<<27U)
#define I3C_CR_ADD                                                      (0x7FU<<17U)
#define I3C_CR_ADD_0                                                    (0x1U<<17U)
#define I3C_CR_RNW                                                      (0x1U<<16U)
#define I3C_CR_DCNT                                                     (0xFFFFU<<0U)
#define I3C_CR_DCNT_0                                                   (0x1U<<0U)

#define I3C_CR_MEND_B_0X0                                               (0x0U<<31U)
#define I3C_CR_MEND_B_0X1                                               (0x1U<<31U)
#define I3C_CR_MTYPE_B_0X0_WHEN_I3C_ACTS_AS_I3C_CONTROLLER              (0x0U<<27U)
#define I3C_CR_MTYPE_B_0X1_WHEN_I3C_ACTS_AS_I3C_CONTROLLER              (0x1U<<27U)
#define I3C_CR_MTYPE_B_0X2_WHEN_I3C_ACTS_AS_I3C_CONTROLLER              (0x2U<<27U)
#define I3C_CR_MTYPE_B_0X3_WHEN_I3C_ACTS_AS_I3C_CONTROLLER              (0x3U<<27U)
#define I3C_CR_MTYPE_B_0X4_WHEN_I3C_ACTS_AS_I3C_CONTROLLER              (0x4U<<27U)
#define I3C_CR_MTYPE_B_0X8_WHEN_I3C_ACTS_AS_I3C_TARGET                  (0x8U<<27U)
#define I3C_CR_MTYPE_B_0X9_WHEN_I3C_ACTS_AS_I3C_TARGET                  (0x9U<<27U)
#define I3C_CR_MTYPE_B_0XA_WHEN_I3C_ACTS_AS_I3C_TARGET                  (0xAU<<27U)
#define I3C_CR_RNW_B_0X0                                                (0x0U<<16U)
#define I3C_CR_RNW_B_0X1                                                (0x1U<<16U)
#define I3C_CR_DCNT_B_0X0000                                            (0x0U<<0U)
#define I3C_CR_DCNT_B_0X0001                                            (0x1U<<0U)
#define I3C_CR_DCNT_B_0X0002                                            (0x2U<<0U)
#define I3C_CR_DCNT_B_0XFFFF                                            (0xFFFFU<<0U)

// CR_ALTERNATE Configuration

#define I3C_CR_ALTERNATE_MEND                                           (0x1U<<31U)
#define I3C_CR_ALTERNATE_MTYPE                                          (0xFU<<27U)
#define I3C_CR_ALTERNATE_MTYPE_0                                        (0x1U<<27U)
#define I3C_CR_ALTERNATE_CCC                                            (0xFFU<<16U)
#define I3C_CR_ALTERNATE_CCC_0                                          (0x1U<<16U)
#define I3C_CR_ALTERNATE_DCNT                                           (0xFFFFU<<0U)
#define I3C_CR_ALTERNATE_DCNT_0                                         (0x1U<<0U)

#define I3C_CR_ALTERNATE_MEND_B_0X0                                     (0x0U<<31U)
#define I3C_CR_ALTERNATE_MEND_B_0X1                                     (0x1U<<31U)
#define I3C_CR_ALTERNATE_MTYPE_B_0X6_WHEN_I3C_ACTS_AS_I3C_CONTROLLER    (0x6U<<27U)
#define I3C_CR_ALTERNATE_DCNT_B_0X0000                                  (0x0U<<0U)
#define I3C_CR_ALTERNATE_DCNT_B_0X0001                                  (0x1U<<0U)
#define I3C_CR_ALTERNATE_DCNT_B_0X0002                                  (0x2U<<0U)
#define I3C_CR_ALTERNATE_DCNT_B_0XFFFF                                  (0xFFFFU<<0U)

// CFGR Configuration

#define I3C_CFGR_TSFSET                                                 (0x1U<<30U)
#define I3C_CFGR_CFLUSH                                                 (0x1U<<21U)
#define I3C_CFGR_CDMAEN                                                 (0x1U<<20U)
#define I3C_CFGR_TMODE                                                  (0x1U<<19U)
#define I3C_CFGR_SMODE                                                  (0x1U<<18U)
#define I3C_CFGR_SFLUSH                                                 (0x1U<<17U)
#define I3C_CFGR_SDMAEN                                                 (0x1U<<16U)
#define I3C_CFGR_TXTHRES                                                (0x1U<<14U)
#define I3C_CFGR_TXFLUSH                                                (0x1U<<13U)
#define I3C_CFGR_TXDMAEN                                                (0x1U<<12U)
#define I3C_CFGR_RXTHRES                                                (0x1U<<10U)
#define I3C_CFGR_RXFLUSH                                                (0x1U<<9U)
#define I3C_CFGR_RXDMAEN                                                (0x1U<<8U)
#define I3C_CFGR_HJACK                                                  (0x1U<<7U)
#define I3C_CFGR_HKSDAEN                                                (0x1U<<5U)
#define I3C_CFGR_EXITPTRN                                               (0x1U<<4U)
#define I3C_CFGR_RSTPTRN                                                (0x1U<<3U)
#define I3C_CFGR_NOARBH                                                 (0x1U<<2U)
#define I3C_CFGR_CRINIT                                                 (0x1U<<1U)
#define I3C_CFGR_EN                                                     (0x1U<<0U)

#define I3C_CFGR_TSFSET_B_0X0                                           (0x0U<<30U)
#define I3C_CFGR_TSFSET_B_0X1                                           (0x1U<<30U)
#define I3C_CFGR_CFLUSH_B_0X0                                           (0x0U<<21U)
#define I3C_CFGR_CFLUSH_B_0X1                                           (0x1U<<21U)
#define I3C_CFGR_CDMAEN_B_0X0                                           (0x0U<<20U)
#define I3C_CFGR_CDMAEN_B_0X1                                           (0x1U<<20U)
#define I3C_CFGR_TMODE_B_0X0                                            (0x0U<<19U)
#define I3C_CFGR_TMODE_B_0X1                                            (0x1U<<19U)
#define I3C_CFGR_SMODE_B_0X0                                            (0x0U<<18U)
#define I3C_CFGR_SMODE_B_0X1                                            (0x1U<<18U)
#define I3C_CFGR_SFLUSH_B_0X0                                           (0x0U<<17U)
#define I3C_CFGR_SFLUSH_B_0X1                                           (0x1U<<17U)
#define I3C_CFGR_SDMAEN_B_0X0                                           (0x0U<<16U)
#define I3C_CFGR_SDMAEN_B_0X1                                           (0x1U<<16U)
#define I3C_CFGR_TXTHRES_B_0X0                                          (0x0U<<14U)
#define I3C_CFGR_TXTHRES_B_0X1                                          (0x1U<<14U)
#define I3C_CFGR_TXFLUSH_B_0X0                                          (0x0U<<13U)
#define I3C_CFGR_TXFLUSH_B_0X1                                          (0x1U<<13U)
#define I3C_CFGR_TXDMAEN_B_0X0                                          (0x0U<<12U)
#define I3C_CFGR_TXDMAEN_B_0X1                                          (0x1U<<12U)
#define I3C_CFGR_RXTHRES_B_0X0                                          (0x0U<<10U)
#define I3C_CFGR_RXTHRES_B_0X1                                          (0x1U<<10U)
#define I3C_CFGR_RXFLUSH_B_0X0                                          (0x0U<<9U)
#define I3C_CFGR_RXFLUSH_B_0X1                                          (0x1U<<9U)
#define I3C_CFGR_RXDMAEN_B_0X0                                          (0x0U<<8U)
#define I3C_CFGR_RXDMAEN_B_0X1                                          (0x1U<<8U)
#define I3C_CFGR_HJACK_B_0X0                                            (0x0U<<7U)
#define I3C_CFGR_HJACK_B_0X1                                            (0x1U<<7U)
#define I3C_CFGR_HKSDAEN_B_0X0                                          (0x0U<<5U)
#define I3C_CFGR_HKSDAEN_B_0X1                                          (0x1U<<5U)
#define I3C_CFGR_EXITPTRN_B_0X0                                         (0x0U<<4U)
#define I3C_CFGR_EXITPTRN_B_0X1                                         (0x1U<<4U)
#define I3C_CFGR_RSTPTRN_B_0X0                                          (0x0U<<3U)
#define I3C_CFGR_RSTPTRN_B_0X1                                          (0x1U<<3U)
#define I3C_CFGR_NOARBH_B_0X0                                           (0x0U<<2U)
#define I3C_CFGR_NOARBH_B_0X1                                           (0x1U<<2U)
#define I3C_CFGR_CRINIT_B_0X0                                           (0x0U<<1U)
#define I3C_CFGR_CRINIT_B_0X1                                           (0x1U<<1U)
#define I3C_CFGR_EN_B_0X0                                               (0x0U<<0U)
#define I3C_CFGR_EN_B_0X1                                               (0x1U<<0U)

// RDR Configuration

#define I3C_RDR_RDB0                                                    (0xFFU<<0U)
#define I3C_RDR_RDB0_0                                                  (0x1U<<0U)

// RDWR Configuration

#define I3C_RDWR_RDB3                                                   (0xFFU<<24U)
#define I3C_RDWR_RDB3_0                                                 (0x1U<<24U)
#define I3C_RDWR_RDB2                                                   (0xFFU<<16U)
#define I3C_RDWR_RDB2_0                                                 (0x1U<<16U)
#define I3C_RDWR_RDB1                                                   (0xFFU<<8U)
#define I3C_RDWR_RDB1_0                                                 (0x1U<<8U)
#define I3C_RDWR_RDB0                                                   (0xFFU<<0U)
#define I3C_RDWR_RDB0_0                                                 (0x1U<<0U)

// TDR Configuration

#define I3C_TDR_TDB0                                                    (0xFFU<<0U)
#define I3C_TDR_TDB0_0                                                  (0x1U<<0U)

// TDWR Configuration

#define I3C_TDWR_TDB3                                                   (0xFFU<<24U)
#define I3C_TDWR_TDB3_0                                                 (0x1U<<24U)
#define I3C_TDWR_TDB2                                                   (0xFFU<<16U)
#define I3C_TDWR_TDB2_0                                                 (0x1U<<16U)
#define I3C_TDWR_TDB1                                                   (0xFFU<<8U)
#define I3C_TDWR_TDB1_0                                                 (0x1U<<8U)
#define I3C_TDWR_TDB0                                                   (0xFFU<<0U)
#define I3C_TDWR_TDB0_0                                                 (0x1U<<0U)

// IBIDR Configuration

#define I3C_IBIDR_IBIDB3                                                (0xFFU<<24U)
#define I3C_IBIDR_IBIDB3_0                                              (0x1U<<24U)
#define I3C_IBIDR_IBIDB2                                                (0xFFU<<16U)
#define I3C_IBIDR_IBIDB2_0                                              (0x1U<<16U)
#define I3C_IBIDR_IBIDB1                                                (0xFFU<<8U)
#define I3C_IBIDR_IBIDB1_0                                              (0x1U<<8U)
#define I3C_IBIDR_IBIDB0                                                (0xFFU<<0U)
#define I3C_IBIDR_IBIDB0_0                                              (0x1U<<0U)

// TGTTDR Configuration

#define I3C_TGTTDR_PRELOAD                                              (0x1U<<16U)
#define I3C_TGTTDR_TGTTDCNT                                             (0xFFFFU<<0U)
#define I3C_TGTTDR_TGTTDCNT_0                                           (0x1U<<0U)

#define I3C_TGTTDR_PRELOAD_B_0X0                                        (0x0U<<16U)
#define I3C_TGTTDR_PRELOAD_B_0X1                                        (0x1U<<16U)

// SR Configuration

#define I3C_SR_MID                                                      (0xFFU<<24U)
#define I3C_SR_MID_0                                                    (0x1U<<24U)
#define I3C_SR_DIR                                                      (0x1U<<18U)
#define I3C_SR_ABT                                                      (0x1U<<17U)
#define I3C_SR_XDCNT                                                    (0xFFFFU<<0U)
#define I3C_SR_XDCNT_0                                                  (0x1U<<0U)

#define I3C_SR_DIR_B_0X0                                                (0x0U<<18U)
#define I3C_SR_DIR_B_0X1                                                (0x1U<<18U)
#define I3C_SR_ABT_B_0X0                                                (0x0U<<17U)
#define I3C_SR_ABT_B_0X1                                                (0x1U<<17U)

// SER Configuration

#define I3C_SER_DERR                                                    (0x1U<<10U)
#define I3C_SER_DNACK                                                   (0x1U<<9U)
#define I3C_SER_ANACK                                                   (0x1U<<8U)
#define I3C_SER_COVR                                                    (0x1U<<7U)
#define I3C_SER_DOVR                                                    (0x1U<<6U)
#define I3C_SER_STALL                                                   (0x1U<<5U)
#define I3C_SER_PERR                                                    (0x1U<<4U)
#define I3C_SER_CODERR                                                  (0xFU<<0U)
#define I3C_SER_CODERR_0                                                (0x1U<<0U)

#define I3C_SER_DERR_B_0X0                                              (0x0U<<10U)
#define I3C_SER_DERR_B_0X1                                              (0x1U<<10U)
#define I3C_SER_DNACK_B_0X0                                             (0x0U<<9U)
#define I3C_SER_DNACK_B_0X1                                             (0x1U<<9U)
#define I3C_SER_ANACK_B_0X0                                             (0x0U<<8U)
#define I3C_SER_ANACK_B_0X1                                             (0x1U<<8U)
#define I3C_SER_COVR_B_0X0                                              (0x0U<<7U)
#define I3C_SER_COVR_B_0X1                                              (0x1U<<7U)
#define I3C_SER_DOVR_B_0X0                                              (0x0U<<6U)
#define I3C_SER_DOVR_B_0X1                                              (0x1U<<6U)
#define I3C_SER_STALL_B_0X0                                             (0x0U<<5U)
#define I3C_SER_STALL_B_0X1                                             (0x1U<<5U)
#define I3C_SER_PERR_B_0X0                                              (0x0U<<4U)
#define I3C_SER_PERR_B_0X1                                              (0x1U<<4U)
#define I3C_SER_CODERR_B_0X0                                            (0x0U<<0U)
#define I3C_SER_CODERR_B_0X1                                            (0x1U<<0U)
#define I3C_SER_CODERR_B_0X2                                            (0x2U<<0U)
#define I3C_SER_CODERR_B_0X3                                            (0x3U<<0U)
#define I3C_SER_CODERR_B_0X8                                            (0x8U<<0U)
#define I3C_SER_CODERR_B_0X9                                            (0x9U<<0U)
#define I3C_SER_CODERR_B_0XA                                            (0xAU<<0U)
#define I3C_SER_CODERR_B_0XB                                            (0xBU<<0U)
#define I3C_SER_CODERR_B_0XC                                            (0xCU<<0U)
#define I3C_SER_CODERR_B_0XD                                            (0xDU<<0U)
#define I3C_SER_CODERR_B_0XE                                            (0xEU<<0U)

// RMR Configuration

#define I3C_RMR_RADD                                                    (0x7FU<<17U)
#define I3C_RMR_RADD_0                                                  (0x1U<<17U)
#define I3C_RMR_RCODE                                                   (0xFFU<<8U)
#define I3C_RMR_RCODE_0                                                 (0x1U<<8U)
#define I3C_RMR_IBIRDCNT                                                (0x7U<<0U)
#define I3C_RMR_IBIRDCNT_0                                              (0x1U<<0U)

// EVR Configuration

#define I3C_EVR_GRPF                                                    (0x1U<<31U)
#define I3C_EVR_DEFF                                                    (0x1U<<30U)
#define I3C_EVR_INTUPDF                                                 (0x1U<<29U)
#define I3C_EVR_ASUPDF                                                  (0x1U<<28U)
#define I3C_EVR_RSTF                                                    (0x1U<<27U)
#define I3C_EVR_MRLUPDF                                                 (0x1U<<26U)
#define I3C_EVR_MWLUPDF                                                 (0x1U<<25U)
#define I3C_EVR_DAUPDF                                                  (0x1U<<24U)
#define I3C_EVR_STAF                                                    (0x1U<<23U)
#define I3C_EVR_GETF                                                    (0x1U<<22U)
#define I3C_EVR_WKPF                                                    (0x1U<<21U)
#define I3C_EVR_HJF                                                     (0x1U<<19U)
#define I3C_EVR_CRUPDF                                                  (0x1U<<18U)
#define I3C_EVR_CRF                                                     (0x1U<<17U)
#define I3C_EVR_IBIENDF                                                 (0x1U<<16U)
#define I3C_EVR_IBIF                                                    (0x1U<<15U)
#define I3C_EVR_ERRF                                                    (0x1U<<11U)
#define I3C_EVR_RXTGTENDF                                               (0x1U<<10U)
#define I3C_EVR_FCF                                                     (0x1U<<9U)
#define I3C_EVR_RXLASTF                                                 (0x1U<<7U)
#define I3C_EVR_TXLASTF                                                 (0x1U<<6U)
#define I3C_EVR_RXFNEF                                                  (0x1U<<5U)
#define I3C_EVR_TXFNFF                                                  (0x1U<<4U)
#define I3C_EVR_SFNEF                                                   (0x1U<<3U)
#define I3C_EVR_CFNFF                                                   (0x1U<<2U)
#define I3C_EVR_TXFEF                                                   (0x1U<<1U)
#define I3C_EVR_CFEF                                                    (0x1U<<0U)

// IER Configuration

#define I3C_IER_GRPIE                                                   (0x1U<<31U)
#define I3C_IER_DEFIE                                                   (0x1U<<30U)
#define I3C_IER_INTUPDIE                                                (0x1U<<29U)
#define I3C_IER_ASUPDIE                                                 (0x1U<<28U)
#define I3C_IER_RSTIE                                                   (0x1U<<27U)
#define I3C_IER_MRLUPDIE                                                (0x1U<<26U)
#define I3C_IER_MWLUPDIE                                                (0x1U<<25U)
#define I3C_IER_DAUPDIE                                                 (0x1U<<24U)
#define I3C_IER_STAIE                                                   (0x1U<<23U)
#define I3C_IER_GETIE                                                   (0x1U<<22U)
#define I3C_IER_WKPIE                                                   (0x1U<<21U)
#define I3C_IER_HJIE                                                    (0x1U<<19U)
#define I3C_IER_CRUPDIE                                                 (0x1U<<18U)
#define I3C_IER_CRIE                                                    (0x1U<<17U)
#define I3C_IER_IBIENDIE                                                (0x1U<<16U)
#define I3C_IER_IBIIE                                                   (0x1U<<15U)
#define I3C_IER_ERRIE                                                   (0x1U<<11U)
#define I3C_IER_RXTGTENDIE                                              (0x1U<<10U)
#define I3C_IER_FCIE                                                    (0x1U<<9U)
#define I3C_IER_RXFNEIE                                                 (0x1U<<5U)
#define I3C_IER_TXFNFIE                                                 (0x1U<<4U)
#define I3C_IER_SFNEIE                                                  (0x1U<<3U)
#define I3C_IER_CFNFIE                                                  (0x1U<<2U)

#define I3C_IER_GRPIE_B_0X0                                             (0x0U<<31U)
#define I3C_IER_GRPIE_B_0X1                                             (0x1U<<31U)
#define I3C_IER_DEFIE_B_0X0                                             (0x0U<<30U)
#define I3C_IER_DEFIE_B_0X1                                             (0x1U<<30U)
#define I3C_IER_INTUPDIE_B_0X0                                          (0x0U<<29U)
#define I3C_IER_INTUPDIE_B_0X1                                          (0x1U<<29U)
#define I3C_IER_ASUPDIE_B_0X0                                           (0x0U<<28U)
#define I3C_IER_ASUPDIE_B_0X1                                           (0x1U<<28U)
#define I3C_IER_RSTIE_B_0X0                                             (0x0U<<27U)
#define I3C_IER_RSTIE_B_0X1                                             (0x1U<<27U)
#define I3C_IER_MRLUPDIE_B_0X0                                          (0x0U<<26U)
#define I3C_IER_MRLUPDIE_B_0X1                                          (0x1U<<26U)
#define I3C_IER_MWLUPDIE_B_0X0                                          (0x0U<<25U)
#define I3C_IER_MWLUPDIE_B_0X1                                          (0x1U<<25U)
#define I3C_IER_DAUPDIE_B_0X0                                           (0x0U<<24U)
#define I3C_IER_DAUPDIE_B_0X1                                           (0x1U<<24U)
#define I3C_IER_STAIE_B_0X0                                             (0x0U<<23U)
#define I3C_IER_STAIE_B_0X1                                             (0x1U<<23U)
#define I3C_IER_GETIE_B_0X0                                             (0x0U<<22U)
#define I3C_IER_GETIE_B_0X1                                             (0x1U<<22U)
#define I3C_IER_WKPIE_B_0X0                                             (0x0U<<21U)
#define I3C_IER_WKPIE_B_0X1                                             (0x1U<<21U)
#define I3C_IER_HJIE_B_0X0                                              (0x0U<<19U)
#define I3C_IER_HJIE_B_0X1                                              (0x1U<<19U)
#define I3C_IER_CRUPDIE_B_0X0                                           (0x0U<<18U)
#define I3C_IER_CRUPDIE_B_0X1                                           (0x1U<<18U)
#define I3C_IER_CRIE_B_0X0                                              (0x0U<<17U)
#define I3C_IER_CRIE_B_0X1                                              (0x1U<<17U)
#define I3C_IER_IBIENDIE_B_0X0                                          (0x0U<<16U)
#define I3C_IER_IBIENDIE_B_0X1                                          (0x1U<<16U)
#define I3C_IER_IBIIE_B_0X0                                             (0x0U<<15U)
#define I3C_IER_IBIIE_B_0X1                                             (0x1U<<15U)
#define I3C_IER_ERRIE_B_0X0                                             (0x0U<<11U)
#define I3C_IER_ERRIE_B_0X1                                             (0x1U<<11U)
#define I3C_IER_RXTGTENDIE_B_0X0                                        (0x0U<<10U)
#define I3C_IER_RXTGTENDIE_B_0X1                                        (0x1U<<10U)
#define I3C_IER_FCIE_B_0X0                                              (0x0U<<9U)
#define I3C_IER_FCIE_B_0X1                                              (0x1U<<9U)
#define I3C_IER_RXFNEIE_B_0X0                                           (0x0U<<5U)
#define I3C_IER_RXFNEIE_B_0X1                                           (0x1U<<5U)
#define I3C_IER_TXFNFIE_B_0X0                                           (0x0U<<4U)
#define I3C_IER_TXFNFIE_B_0X1                                           (0x1U<<4U)
#define I3C_IER_SFNEIE_B_0X0                                            (0x0U<<3U)
#define I3C_IER_SFNEIE_B_0X1                                            (0x1U<<3U)
#define I3C_IER_CFNFIE_B_0X0                                            (0x0U<<2U)
#define I3C_IER_CFNFIE_B_0X1                                            (0x1U<<2U)

// CEVR Configuration

#define I3C_CEVR_CGRPF                                                  (0x1U<<31U)
#define I3C_CEVR_CDEFF                                                  (0x1U<<30U)
#define I3C_CEVR_CINTUPDF                                               (0x1U<<29U)
#define I3C_CEVR_CASUPDF                                                (0x1U<<28U)
#define I3C_CEVR_CRSTF                                                  (0x1U<<27U)
#define I3C_CEVR_CMRLUPDF                                               (0x1U<<26U)
#define I3C_CEVR_CMWLUPDF                                               (0x1U<<25U)
#define I3C_CEVR_CDAUPDF                                                (0x1U<<24U)
#define I3C_CEVR_CSTAF                                                  (0x1U<<23U)
#define I3C_CEVR_CGETF                                                  (0x1U<<22U)
#define I3C_CEVR_CWKPF                                                  (0x1U<<21U)
#define I3C_CEVR_CHJF                                                   (0x1U<<19U)
#define I3C_CEVR_CCRUPDF                                                (0x1U<<18U)
#define I3C_CEVR_CCRF                                                   (0x1U<<17U)
#define I3C_CEVR_CIBIENDF                                               (0x1U<<16U)
#define I3C_CEVR_CIBIF                                                  (0x1U<<15U)
#define I3C_CEVR_CERRF                                                  (0x1U<<11U)
#define I3C_CEVR_CRXTGTENDF                                             (0x1U<<10U)
#define I3C_CEVR_CFCF                                                   (0x1U<<9U)

#define I3C_CEVR_CGRPF_B_0X0                                            (0x0U<<31U)
#define I3C_CEVR_CGRPF_B_0X1                                            (0x1U<<31U)
#define I3C_CEVR_CDEFF_B_0X0                                            (0x0U<<30U)
#define I3C_CEVR_CDEFF_B_0X1                                            (0x1U<<30U)
#define I3C_CEVR_CINTUPDF_B_0X0                                         (0x0U<<29U)
#define I3C_CEVR_CINTUPDF_B_0X1                                         (0x1U<<29U)
#define I3C_CEVR_CASUPDF_B_0X0                                          (0x0U<<28U)
#define I3C_CEVR_CASUPDF_B_0X1                                          (0x1U<<28U)
#define I3C_CEVR_CRSTF_B_0X0                                            (0x0U<<27U)
#define I3C_CEVR_CRSTF_B_0X1                                            (0x1U<<27U)
#define I3C_CEVR_CMRLUPDF_B_0X0                                         (0x0U<<26U)
#define I3C_CEVR_CMRLUPDF_B_0X1                                         (0x1U<<26U)
#define I3C_CEVR_CMWLUPDF_B_0X0                                         (0x0U<<25U)
#define I3C_CEVR_CMWLUPDF_B_0X1                                         (0x1U<<25U)
#define I3C_CEVR_CDAUPDF_B_0X0                                          (0x0U<<24U)
#define I3C_CEVR_CDAUPDF_B_0X1                                          (0x1U<<24U)
#define I3C_CEVR_CSTAF_B_0X0                                            (0x0U<<23U)
#define I3C_CEVR_CSTAF_B_0X1                                            (0x1U<<23U)
#define I3C_CEVR_CGETF_B_0X0                                            (0x0U<<22U)
#define I3C_CEVR_CGETF_B_0X1                                            (0x1U<<22U)
#define I3C_CEVR_CWKPF_B_0X0                                            (0x0U<<21U)
#define I3C_CEVR_CWKPF_B_0X1                                            (0x1U<<21U)
#define I3C_CEVR_CHJF_B_0X0                                             (0x0U<<19U)
#define I3C_CEVR_CHJF_B_0X1                                             (0x1U<<19U)
#define I3C_CEVR_CCRUPDF_B_0X0                                          (0x0U<<18U)
#define I3C_CEVR_CCRUPDF_B_0X1                                          (0x1U<<18U)
#define I3C_CEVR_CCRF_B_0X0                                             (0x0U<<17U)
#define I3C_CEVR_CCRF_B_0X1                                             (0x1U<<17U)
#define I3C_CEVR_CIBIENDF_B_0X0                                         (0x0U<<16U)
#define I3C_CEVR_CIBIENDF_B_0X1                                         (0x1U<<16U)
#define I3C_CEVR_CIBIF_B_0X0                                            (0x0U<<15U)
#define I3C_CEVR_CIBIF_B_0X1                                            (0x1U<<15U)
#define I3C_CEVR_CERRF_B_0X0                                            (0x0U<<11U)
#define I3C_CEVR_CERRF_B_0X1                                            (0x1U<<11U)
#define I3C_CEVR_CRXTGTENDF_B_0X0                                       (0x0U<<10U)
#define I3C_CEVR_CRXTGTENDF_B_0X1                                       (0x1U<<10U)
#define I3C_CEVR_CFCF_B_0X0                                             (0x0U<<9U)
#define I3C_CEVR_CFCF_B_0X1                                             (0x1U<<9U)

// DEVR0 Configuration

#define I3C_DEVR0_RSTVAL                                                (0x1U<<24U)
#define I3C_DEVR0_RSTACT                                                (0x3U<<22U)
#define I3C_DEVR0_RSTACT_0                                              (0x1U<<22U)
#define I3C_DEVR0_AS                                                    (0x3U<<20U)
#define I3C_DEVR0_AS_0                                                  (0x1U<<20U)
#define I3C_DEVR0_HJEN                                                  (0x1U<<19U)
#define I3C_DEVR0_CREN                                                  (0x1U<<17U)
#define I3C_DEVR0_IBIEN                                                 (0x1U<<16U)
#define I3C_DEVR0_DA                                                    (0x7FU<<1U)
#define I3C_DEVR0_DA_0                                                  (0x1U<<1U)
#define I3C_DEVR0_DAVAL                                                 (0x1U<<0U)

#define I3C_DEVR0_RSTACT_B_0X0                                          (0x0U<<22U)
#define I3C_DEVR0_RSTACT_B_0X1                                          (0x1U<<22U)
#define I3C_DEVR0_RSTACT_B_0X2                                          (0x2U<<22U)
#define I3C_DEVR0_RSTACT_B_0X3                                          (0x3U<<22U)
#define I3C_DEVR0_AS_B_0X0                                              (0x0U<<20U)
#define I3C_DEVR0_AS_B_0X1                                              (0x1U<<20U)
#define I3C_DEVR0_AS_B_0X2                                              (0x2U<<20U)
#define I3C_DEVR0_AS_B_0X3                                              (0x3U<<20U)
#define I3C_DEVR0_HJEN_B_0X0                                            (0x0U<<19U)
#define I3C_DEVR0_HJEN_B_0X1                                            (0x1U<<19U)
#define I3C_DEVR0_CREN_B_0X0                                            (0x0U<<17U)
#define I3C_DEVR0_CREN_B_0X1                                            (0x1U<<17U)
#define I3C_DEVR0_IBIEN_B_0X0                                           (0x0U<<16U)
#define I3C_DEVR0_IBIEN_B_0X1                                           (0x1U<<16U)

// DEVR1 Configuration

#define I3C_DEVR1_DIS                                                   (0x1U<<31U)
#define I3C_DEVR1_SUSP                                                  (0x1U<<19U)
#define I3C_DEVR1_IBIDEN                                                (0x1U<<18U)
#define I3C_DEVR1_CRACK                                                 (0x1U<<17U)
#define I3C_DEVR1_IBIACK                                                (0x1U<<16U)
#define I3C_DEVR1_DA                                                    (0x7FU<<1U)
#define I3C_DEVR1_DA_0                                                  (0x1U<<1U)

#define I3C_DEVR1_DIS_B_0X0                                             (0x0U<<31U)
#define I3C_DEVR1_DIS_B_0X1                                             (0x1U<<31U)
#define I3C_DEVR1_SUSP_B_0X0                                            (0x0U<<19U)
#define I3C_DEVR1_SUSP_B_0X1                                            (0x1U<<19U)
#define I3C_DEVR1_IBIDEN_B_0X0                                          (0x0U<<18U)
#define I3C_DEVR1_IBIDEN_B_0X1                                          (0x1U<<18U)
#define I3C_DEVR1_CRACK_B_0X0                                           (0x0U<<17U)
#define I3C_DEVR1_CRACK_B_0X1                                           (0x1U<<17U)
#define I3C_DEVR1_IBIACK_B_0X0                                          (0x0U<<16U)
#define I3C_DEVR1_IBIACK_B_0X1                                          (0x1U<<16U)

// DEVR2 Configuration

#define I3C_DEVR2_DIS                                                   (0x1U<<31U)
#define I3C_DEVR2_SUSP                                                  (0x1U<<19U)
#define I3C_DEVR2_IBIDEN                                                (0x1U<<18U)
#define I3C_DEVR2_CRACK                                                 (0x1U<<17U)
#define I3C_DEVR2_IBIACK                                                (0x1U<<16U)
#define I3C_DEVR2_DA                                                    (0x7FU<<1U)
#define I3C_DEVR2_DA_0                                                  (0x1U<<1U)

#define I3C_DEVR2_DIS_B_0X0                                             (0x0U<<31U)
#define I3C_DEVR2_DIS_B_0X1                                             (0x1U<<31U)
#define I3C_DEVR2_SUSP_B_0X0                                            (0x0U<<19U)
#define I3C_DEVR2_SUSP_B_0X1                                            (0x1U<<19U)
#define I3C_DEVR2_IBIDEN_B_0X0                                          (0x0U<<18U)
#define I3C_DEVR2_IBIDEN_B_0X1                                          (0x1U<<18U)
#define I3C_DEVR2_CRACK_B_0X0                                           (0x0U<<17U)
#define I3C_DEVR2_CRACK_B_0X1                                           (0x1U<<17U)
#define I3C_DEVR2_IBIACK_B_0X0                                          (0x0U<<16U)
#define I3C_DEVR2_IBIACK_B_0X1                                          (0x1U<<16U)

// DEVR3 Configuration

#define I3C_DEVR3_DIS                                                   (0x1U<<31U)
#define I3C_DEVR3_SUSP                                                  (0x1U<<19U)
#define I3C_DEVR3_IBIDEN                                                (0x1U<<18U)
#define I3C_DEVR3_CRACK                                                 (0x1U<<17U)
#define I3C_DEVR3_IBIACK                                                (0x1U<<16U)
#define I3C_DEVR3_DA                                                    (0x7FU<<1U)
#define I3C_DEVR3_DA_0                                                  (0x1U<<1U)

#define I3C_DEVR3_DIS_B_0X0                                             (0x0U<<31U)
#define I3C_DEVR3_DIS_B_0X1                                             (0x1U<<31U)
#define I3C_DEVR3_SUSP_B_0X0                                            (0x0U<<19U)
#define I3C_DEVR3_SUSP_B_0X1                                            (0x1U<<19U)
#define I3C_DEVR3_IBIDEN_B_0X0                                          (0x0U<<18U)
#define I3C_DEVR3_IBIDEN_B_0X1                                          (0x1U<<18U)
#define I3C_DEVR3_CRACK_B_0X0                                           (0x0U<<17U)
#define I3C_DEVR3_CRACK_B_0X1                                           (0x1U<<17U)
#define I3C_DEVR3_IBIACK_B_0X0                                          (0x0U<<16U)
#define I3C_DEVR3_IBIACK_B_0X1                                          (0x1U<<16U)

// DEVR4 Configuration

#define I3C_DEVR4_DIS                                                   (0x1U<<31U)
#define I3C_DEVR4_SUSP                                                  (0x1U<<19U)
#define I3C_DEVR4_IBIDEN                                                (0x1U<<18U)
#define I3C_DEVR4_CRACK                                                 (0x1U<<17U)
#define I3C_DEVR4_IBIACK                                                (0x1U<<16U)
#define I3C_DEVR4_DA                                                    (0x7FU<<1U)
#define I3C_DEVR4_DA_0                                                  (0x1U<<1U)

#define I3C_DEVR4_DIS_B_0X0                                             (0x0U<<31U)
#define I3C_DEVR4_DIS_B_0X1                                             (0x1U<<31U)
#define I3C_DEVR4_SUSP_B_0X0                                            (0x0U<<19U)
#define I3C_DEVR4_SUSP_B_0X1                                            (0x1U<<19U)
#define I3C_DEVR4_IBIDEN_B_0X0                                          (0x0U<<18U)
#define I3C_DEVR4_IBIDEN_B_0X1                                          (0x1U<<18U)
#define I3C_DEVR4_CRACK_B_0X0                                           (0x0U<<17U)
#define I3C_DEVR4_CRACK_B_0X1                                           (0x1U<<17U)
#define I3C_DEVR4_IBIACK_B_0X0                                          (0x0U<<16U)
#define I3C_DEVR4_IBIACK_B_0X1                                          (0x1U<<16U)

// MAXRLR Configuration

#define I3C_MAXRLR_IBIP                                                 (0x7U<<16U)
#define I3C_MAXRLR_IBIP_0                                               (0x1U<<16U)
#define I3C_MAXRLR_MRL                                                  (0xFFFFU<<0U)
#define I3C_MAXRLR_MRL_0                                                (0x1U<<0U)

#define I3C_MAXRLR_IBIP_B_0X0                                           (0x0U<<16U)
#define I3C_MAXRLR_IBIP_B_0X1                                           (0x1U<<16U)
#define I3C_MAXRLR_IBIP_B_0X2                                           (0x2U<<16U)
#define I3C_MAXRLR_IBIP_B_0X3                                           (0x3U<<16U)
#define I3C_MAXRLR_IBIP_B_0X4                                           (0x4U<<16U)

// MAXWLR Configuration

#define I3C_MAXWLR_MWL                                                  (0xFFFFU<<0U)
#define I3C_MAXWLR_MWL_0                                                (0x1U<<0U)

// TIMINGR0 Configuration

#define I3C_TIMINGR0_SCLH_I2C                                           (0xFFU<<24U)
#define I3C_TIMINGR0_SCLH_I2C_0                                         (0x1U<<24U)
#define I3C_TIMINGR0_SCLL_OD                                            (0xFFU<<16U)
#define I3C_TIMINGR0_SCLL_OD_0                                          (0x1U<<16U)
#define I3C_TIMINGR0_SCLH_I3C                                           (0xFFU<<8U)
#define I3C_TIMINGR0_SCLH_I3C_0                                         (0x1U<<8U)
#define I3C_TIMINGR0_SCLL_PP                                            (0xFFU<<0U)
#define I3C_TIMINGR0_SCLL_PP_0                                          (0x1U<<0U)

// TIMINGR1 Configuration

#define I3C_TIMINGR1_SDA_HD                                             (0x1U<<28U)
#define I3C_TIMINGR1_FREE                                               (0x7FU<<16U)
#define I3C_TIMINGR1_FREE_0                                             (0x1U<<16U)
#define I3C_TIMINGR1_ASNCR                                              (0x3U<<8U)
#define I3C_TIMINGR1_ASNCR_0                                            (0x1U<<8U)
#define I3C_TIMINGR1_AVAL                                               (0xFFU<<0U)
#define I3C_TIMINGR1_AVAL_0                                             (0x1U<<0U)

// TIMINGR2 Configuration

#define I3C_TIMINGR2_STALL                                              (0xFFU<<8U)
#define I3C_TIMINGR2_STALL_0                                            (0x1U<<8U)
#define I3C_TIMINGR2_STALLA                                             (0x1U<<3U)
#define I3C_TIMINGR2_STALLC                                             (0x1U<<2U)
#define I3C_TIMINGR2_STALLD                                             (0x1U<<1U)
#define I3C_TIMINGR2_STALLT                                             (0x1U<<0U)

#define I3C_TIMINGR2_STALLA_B_0X0                                       (0x0U<<3U)
#define I3C_TIMINGR2_STALLA_B_0X1                                       (0x1U<<3U)
#define I3C_TIMINGR2_STALLC_B_0X0                                       (0x0U<<2U)
#define I3C_TIMINGR2_STALLC_B_0X1                                       (0x1U<<2U)
#define I3C_TIMINGR2_STALLD_B_0X0                                       (0x0U<<1U)
#define I3C_TIMINGR2_STALLD_B_0X1                                       (0x1U<<1U)
#define I3C_TIMINGR2_STALLT_B_0X0                                       (0x0U<<0U)
#define I3C_TIMINGR2_STALLT_B_0X1                                       (0x1U<<0U)

// BCR Configuration

#define I3C_BCR_BCR6                                                    (0x1U<<6U)
#define I3C_BCR_BCR2                                                    (0x1U<<2U)
#define I3C_BCR_BCR0                                                    (0x1U<<0U)

#define I3C_BCR_BCR6_B_0X0                                              (0x0U<<6U)
#define I3C_BCR_BCR6_B_0X1                                              (0x1U<<6U)
#define I3C_BCR_BCR2_B_0X0                                              (0x0U<<2U)
#define I3C_BCR_BCR2_B_0X1                                              (0x1U<<2U)
#define I3C_BCR_BCR0_B_0X0                                              (0x0U<<0U)
#define I3C_BCR_BCR0_B_0X1                                              (0x1U<<0U)

// DCR Configuration

#define I3C_DCR_DCR                                                     (0xFFU<<0U)
#define I3C_DCR_DCR_0                                                   (0x1U<<0U)

#define I3C_DCR_DCR_B_0X00                                              (0x0U<<0U)

// GETCAPR Configuration

#define I3C_GETCAPR_CAPPEND                                             (0x1U<<14U)

#define I3C_GETCAPR_CAPPEND_B_0X0                                       (0x0U<<14U)
#define I3C_GETCAPR_CAPPEND_B_0X1                                       (0x1U<<14U)

// CRCAPR Configuration

#define I3C_CRCAPR_CAPGRP                                               (0x1U<<9U)
#define I3C_CRCAPR_CAPDHOFF                                             (0x1U<<3U)

#define I3C_CRCAPR_CAPGRP_B_0X0                                         (0x0U<<9U)
#define I3C_CRCAPR_CAPGRP_B_0X1                                         (0x1U<<9U)
#define I3C_CRCAPR_CAPDHOFF_B_0X0                                       (0x0U<<3U)
#define I3C_CRCAPR_CAPDHOFF_B_0X1                                       (0x1U<<3U)

// GETMXDSR Configuration

#define I3C_GETMXDSR_TSCO                                               (0x1U<<24U)
#define I3C_GETMXDSR_RDTURN                                             (0xFFU<<16U)
#define I3C_GETMXDSR_RDTURN_0                                           (0x1U<<16U)
#define I3C_GETMXDSR_FMT                                                (0x3U<<8U)
#define I3C_GETMXDSR_FMT_0                                              (0x1U<<8U)
#define I3C_GETMXDSR_HOFFAS                                             (0x3U<<0U)
#define I3C_GETMXDSR_HOFFAS_0                                           (0x1U<<0U)

#define I3C_GETMXDSR_TSCO_B_0X0                                         (0x0U<<24U)
#define I3C_GETMXDSR_TSCO_B_0X1                                         (0x1U<<24U)
#define I3C_GETMXDSR_FMT_B_0X0                                          (0x0U<<8U)
#define I3C_GETMXDSR_FMT_B_0X1                                          (0x1U<<8U)
#define I3C_GETMXDSR_FMT_B_0X2                                          (0x2U<<8U)
#define I3C_GETMXDSR_FMT_B_0X3                                          (0x3U<<8U)
#define I3C_GETMXDSR_HOFFAS_B_0X0                                       (0x0U<<0U)
#define I3C_GETMXDSR_HOFFAS_B_0X1                                       (0x1U<<0U)
#define I3C_GETMXDSR_HOFFAS_B_0X2                                       (0x2U<<0U)
#define I3C_GETMXDSR_HOFFAS_B_0X3                                       (0x3U<<0U)

// EPIDR Configuration

#define I3C_EPIDR_MIPIMID                                               (0x7FFFU<<17U)
#define I3C_EPIDR_MIPIMID_0                                             (0x1U<<17U)
#define I3C_EPIDR_IDTSEL                                                (0x1U<<16U)
#define I3C_EPIDR_MIPIID                                                (0xFU<<12U)
#define I3C_EPIDR_MIPIID_0                                              (0x1U<<12U)
