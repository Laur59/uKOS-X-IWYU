/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_eth equates.
 */

#pragma once

#include    <stdint.h>

// ETH address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    MACCR;
    volatile    uint32_t    MACECR;
    volatile    uint32_t    MACPFR;
    volatile    uint32_t    MACWTR;
    volatile    uint32_t    MACHT0R;
    volatile    uint32_t    MACHT1R;
    volatile    uint32_t    RESERVED0[14];
    volatile    uint32_t    MACVTCR;
    volatile    uint32_t    MACVTDR;
    volatile    uint32_t    MACVHTR;
    volatile    uint32_t    RESERVED1;
        union {
    volatile    uint32_t    MACVIR;
    volatile    uint32_t    MACVIR_ALTERNATE;
        };
    volatile    uint32_t    MACIVIR;
    volatile    uint32_t    RESERVED2[2];
    volatile    uint32_t    MACQ0TXFCR;
    volatile    uint32_t    RESERVED3[7];
    volatile    uint32_t    MACRXFCR;
    volatile    uint32_t    MACRXQCR;
    volatile    uint32_t    RESERVED4[2];
    volatile    uint32_t    MACRXQC0R;
    volatile    uint32_t    MACRXQC1R;
    volatile    uint32_t    MACRXQC2R;
    volatile    uint32_t    RESERVED5;
    volatile    uint32_t    MACISR;
    volatile    uint32_t    MACIER;
    volatile    uint32_t    MACRXTXSR;
    volatile    uint32_t    RESERVED6;
    volatile    uint32_t    MACPCSR;
    volatile    uint32_t    MACRWKPFR;
    volatile    uint32_t    RESERVED7[2];
    volatile    uint32_t    MACLCSR;
    volatile    uint32_t    MACLTCR;
    volatile    uint32_t    MACLETR;
    volatile    uint32_t    MAC1USTCR;
    volatile    uint32_t    RESERVED8[6];
    volatile    uint32_t    MACPHYCSR;
    volatile    uint32_t    RESERVED9[5];
    volatile    uint32_t    MACVR;
    volatile    uint32_t    MACDR;
    volatile    uint32_t    RESERVED10;
    volatile    uint32_t    MACHWF0R;
    volatile    uint32_t    MACHWF1R;
    volatile    uint32_t    MACHWF2R;
    volatile    uint32_t    MACHWF3R;
    volatile    uint32_t    RESERVED11[53];
    volatile    uint32_t    MACMDIOAR;
    volatile    uint32_t    MACMDIODR;
    volatile    uint32_t    RESERVED12[2];
    volatile    uint32_t    MACARPAR;
    volatile    uint32_t    RESERVED13[7];
    volatile    uint32_t    MACCSRSWCR;
    volatile    uint32_t    MACFPECSR;
    volatile    uint32_t    RESERVED14[2];
    volatile    uint32_t    MACPRSTIMR;
    volatile    uint32_t    MACPRSTIMUR;
    volatile    uint32_t    RESERVED15[46];
    volatile    uint32_t    MACA0HR;
    volatile    uint32_t    MACA0LR;
    volatile    uint32_t    MACA1HR;
    volatile    uint32_t    MACA1LR;
    volatile    uint32_t    MACA2HR;
    volatile    uint32_t    MACA2LR;
    volatile    uint32_t    MACA3HR;
    volatile    uint32_t    MACA3LR;
    volatile    uint32_t    RESERVED16[248];
    volatile    uint32_t    MMC_CONTROL;
    volatile    uint32_t    MMC_RX_INTERRUPT;
    volatile    uint32_t    MMC_TX_INTERRUPT;
    volatile    uint32_t    MMC_RX_INTERRUPT_MASK;
    volatile    uint32_t    MMC_TX_INTERRUPT_MASK;
    volatile    uint32_t    RESERVED17[14];
    volatile    uint32_t    TX_SINGLE_COLLISION_GOOD_PACKETS;
    volatile    uint32_t    TX_MULTIPLE_COLLISION_GOOD_PACKETS;
    volatile    uint32_t    RESERVED18[5];
    volatile    uint32_t    TX_PACKET_COUNT_GOOD;
    volatile    uint32_t    RESERVED19[10];
    volatile    uint32_t    RX_CRC_ERROR_PACKETS;
    volatile    uint32_t    RX_ALIGNMENT_ERROR_PACKETS;
    volatile    uint32_t    RESERVED20[10];
    volatile    uint32_t    RX_UNICAST_PACKETS_GOOD;
    volatile    uint32_t    RESERVED21[9];
    volatile    uint32_t    TX_LPI_USEC_CNTR;
    volatile    uint32_t    TX_LPI_TRAN_CNTR;
    volatile    uint32_t    RX_LPI_USEC_CNTR;
    volatile    uint32_t    RX_LPI_TRAN_CNTR;
    volatile    uint32_t    RESERVED22[41];
    volatile    uint32_t    MMC_FPE_TX_ISR;
    volatile    uint32_t    MMC_FPE_TX_IMR;
    volatile    uint32_t    MMC_FPE_TX_FCR;
    volatile    uint32_t    MMC_TX_HRCR;
    volatile    uint32_t    RESERVED23[4];
    volatile    uint32_t    MMC_FPE_RX_ISR;
    volatile    uint32_t    MMC_FPE_RX_IMR;
    volatile    uint32_t    RX_PACKET_ASM_ERR;
    volatile    uint32_t    RX_PACKET_SMD_ERR;
    volatile    uint32_t    RX_PACKET_ASM_OKR;
    volatile    uint32_t    RX_FPE_FRAG_CR;
    volatile    uint32_t    RESERVED24[10];
    volatile    uint32_t    MACL3L4C0R;
    volatile    uint32_t    MACL4A0R;
    volatile    uint32_t    RESERVED25[2];
    volatile    uint32_t    MACL3A00R;
    volatile    uint32_t    MACL3A10R;
    volatile    uint32_t    MACL3A20R;
    volatile    uint32_t    MACL3A30R;
    volatile    uint32_t    RESERVED26[4];
    volatile    uint32_t    MACL3L4C1R;
    volatile    uint32_t    MACL4A1R;
    volatile    uint32_t    RESERVED27[2];
    volatile    uint32_t    MACL3A01R;
    volatile    uint32_t    MACL3A11R;
    volatile    uint32_t    MACL3A21R;
    volatile    uint32_t    MACL3A31R;
    volatile    uint32_t    RESERVED28[72];
    volatile    uint32_t    MAC_IACR;
    volatile    uint32_t    MAC_TMRQR;
    volatile    uint32_t    RESERVED29[34];
    volatile    uint32_t    MACTSCR;
    volatile    uint32_t    MACSSIR;
    volatile    uint32_t    MACSTSR;
    volatile    uint32_t    MACSTNR;
    volatile    uint32_t    MACSTSUR;
    volatile    uint32_t    MACSTNUR;
    volatile    uint32_t    MACTSAR;
    volatile    uint32_t    RESERVED30;
    volatile    uint32_t    MACTSSR;
    volatile    uint32_t    RESERVED31[3];
    volatile    uint32_t    MACTXTSSNR;
    volatile    uint32_t    MACTXTSSSR;
    volatile    uint32_t    RESERVED32[2];
    volatile    uint32_t    MACACR;
    volatile    uint32_t    RESERVED33;
    volatile    uint32_t    MACATSNR;
    volatile    uint32_t    MACATSSR;
    volatile    uint32_t    MACTSIACR;
    volatile    uint32_t    MACTSEACR;
    volatile    uint32_t    MACTSICNR;
    volatile    uint32_t    MACTSECNR;
    volatile    uint32_t    RESERVED34[2];
    volatile    uint32_t    MACTSILR;
    volatile    uint32_t    MACTSELR;
        union {
    volatile    uint32_t    MACPPSCR;
    volatile    uint32_t    MACPPSCR_ALTERNATE;
        };
    volatile    uint32_t    RESERVED35[3];
    volatile    uint32_t    MACPPSTTS0R;
    volatile    uint32_t    MACPPSTTN0R;
    volatile    uint32_t    MACPPSI0R;
    volatile    uint32_t    MACPPSW0R;
    volatile    uint32_t    MACPPSTTS1R;
    volatile    uint32_t    MACPPSTTN1R;
    volatile    uint32_t    MACPPSI1R;
    volatile    uint32_t    MACPPSW1R;
    volatile    uint32_t    RESERVED36[8];
    volatile    uint32_t    MACPOCR;
    volatile    uint32_t    MACSPI0R;
    volatile    uint32_t    MACSPI1R;
    volatile    uint32_t    MACSPI2R;
    volatile    uint32_t    MACLMIR;
    volatile    uint32_t    RESERVED37[11];
    volatile    uint32_t    MTLOMR;
    volatile    uint32_t    RESERVED38[7];
    volatile    uint32_t    MTLISR;
    volatile    uint32_t    RESERVED39[3];
    volatile    uint32_t    MTLRXQDMAMR;
    volatile    uint32_t    RESERVED40[3];
    volatile    uint32_t    MTLTBSCR;
    volatile    uint32_t    RESERVED41[3];
    volatile    uint32_t    MTLESTCR;
    volatile    uint32_t    MTLESTECR;
    volatile    uint32_t    MTLESTSR;
    volatile    uint32_t    RESERVED42;
    volatile    uint32_t    MTLESTSCHER;
    volatile    uint32_t    MTLESTFSER;
    volatile    uint32_t    MTLESTFSCR;
    volatile    uint32_t    RESERVED43;
    volatile    uint32_t    MTLESTIER;
    volatile    uint32_t    RESERVED44[3];
    volatile    uint32_t    MTLESTGCLCR;
    volatile    uint32_t    MTLESTGCLDR;
    volatile    uint32_t    RESERVED45[2];
    volatile    uint32_t    MTLFPECSR;
    volatile    uint32_t    MTLFPEAR;
    volatile    uint32_t    RESERVED46[26];
    volatile    uint32_t    MTLTXQ0OMR;
    volatile    uint32_t    MTLTXQ0UR;
    volatile    uint32_t    MTLTXQ0DR;
    volatile    uint32_t    RESERVED47[2];
    volatile    uint32_t    MTLTXQ0ESR;
    volatile    uint32_t    MTLTXQ0QWR;
    volatile    uint32_t    RESERVED48[4];
    volatile    uint32_t    MTLQ0ICSR;
    volatile    uint32_t    MTLRXQ0OMR;
    volatile    uint32_t    MTLRXQ0MPOCR;
    volatile    uint32_t    MTLRXQ0DR;
    volatile    uint32_t    MTLRXQ0CR;
    volatile    uint32_t    MTLTXQ1OMR;
    volatile    uint32_t    MTLTXQ1UR;
    volatile    uint32_t    MTLTXQ1DR;
    volatile    uint32_t    RESERVED49;
    volatile    uint32_t    MTLTXQ1ECR;
    volatile    uint32_t    MTLTXQ1ESR;
    volatile    uint32_t    MTLTXQ1QWR;
    volatile    uint32_t    MTLTXQ1SSCR;
    volatile    uint32_t    MTLTXQ1HCR;
    volatile    uint32_t    MTLTXQ1LCR;
    volatile    uint32_t    RESERVED50;
    volatile    uint32_t    MTLQ1ICSR;
    volatile    uint32_t    MTLRXQ1OMR;
    volatile    uint32_t    MTLRXQ1MPOCR;
    volatile    uint32_t    MTLRXQ1DR;
    volatile    uint32_t    MTLRXQ1CR;
    volatile    uint32_t    RESERVED51[160];
    volatile    uint32_t    DMAMR;
    volatile    uint32_t    DMASBMR;
    volatile    uint32_t    DMAISR;
    volatile    uint32_t    DMADSR;
    volatile    uint32_t    RESERVED52[4];
    volatile    uint32_t    DMAA4TXACR;
    volatile    uint32_t    DMAA4RXACR;
    volatile    uint32_t    DMAA4DACR;
    volatile    uint32_t    RESERVED53[5];
    volatile    uint32_t    DMALPIEI;
    volatile    uint32_t    RESERVED54[3];
    volatile    uint32_t    DMATBSCTRL0R;
    volatile    uint32_t    RESERVED55[43];
    volatile    uint32_t    DMAC0CR;
    volatile    uint32_t    DMAC0TXCR;
    volatile    uint32_t    DMAC0RXCR;
    volatile    uint32_t    RESERVED56[2];
    volatile    uint32_t    DMAC0TXDLAR;
    volatile    uint32_t    RESERVED57;
    volatile    uint32_t    DMAC0RXDLAR;
    volatile    uint32_t    DMAC0TXDTPR;
    volatile    uint32_t    RESERVED58;
    volatile    uint32_t    DMAC0RXDTPR;
    volatile    uint32_t    DMAC0TXRLR;
    volatile    uint32_t    DMAC0RXRLR;
    volatile    uint32_t    DMAC0IER;
    volatile    uint32_t    DMAC0RXIWTR;
    volatile    uint32_t    DMAC0SFCSR;
    volatile    uint32_t    RESERVED59;
    volatile    uint32_t    DMAC0CATXDR;
    volatile    uint32_t    RESERVED60;
    volatile    uint32_t    DMAC0CARXDR;
    volatile    uint32_t    RESERVED61;
    volatile    uint32_t    DMAC0CATXBR;
    volatile    uint32_t    RESERVED62;
    volatile    uint32_t    DMAC0CARXBR;
    volatile    uint32_t    DMAC0SR;
    volatile    uint32_t    DMAC0MFCR;
    volatile    uint32_t    RESERVED63[6];
    volatile    uint32_t    DMAC1CR;
    volatile    uint32_t    DMAC1TXCR;
    volatile    uint32_t    DMAC1RXCR;
    volatile    uint32_t    RESERVED64[2];
    volatile    uint32_t    DMAC1TXDLAR;
    volatile    uint32_t    RESERVED65[2];
    volatile    uint32_t    DMAC1TXDTPR;
    volatile    uint32_t    RESERVED66;
    volatile    uint32_t    DMAC1RXDTPR;
    volatile    uint32_t    DMAC1TXRLR;
    volatile    uint32_t    DMAC1RXRLR;
    volatile    uint32_t    DMAC1IER;
    volatile    uint32_t    DMAC1RXIWTR;
    volatile    uint32_t    DMAC1SFCSR;
    volatile    uint32_t    RESERVED67;
    volatile    uint32_t    DMAC1CATXDR;
    volatile    uint32_t    RESERVED68;
    volatile    uint32_t    DMAC1CARXDR;
    volatile    uint32_t    RESERVED69;
    volatile    uint32_t    DMAC1CATXBR;
    volatile    uint32_t    RESERVED70;
    volatile    uint32_t    DMAC1CARXBR;
    volatile    uint32_t    DMAC1SR;
    volatile    uint32_t    DMAC1MFCR;
} ETH_TypeDef;

#ifdef __cplusplus
#define ETH_NS  reinterpret_cast<ETH_TypeDef *>(0x48036000U)
#define ETH_S   reinterpret_cast<ETH_TypeDef *>(0x58036000U)

#else
#define ETH_NS  ((ETH_TypeDef *)0x48036000U)
#define ETH_S   ((ETH_TypeDef *)0x58036000U)
#endif

// MACCR Configuration

#define ETH_MACCR_ARPEN                                     (0x1U<<31U)
#define ETH_MACCR_SARC                                      (0x7U<<28U)
#define ETH_MACCR_SARC_0                                    (0x1U<<28U)
#define ETH_MACCR_IPC                                       (0x1U<<27U)
#define ETH_MACCR_IPG                                       (0x7U<<24U)
#define ETH_MACCR_IPG_0                                     (0x1U<<24U)
#define ETH_MACCR_GPSLCE                                    (0x1U<<23U)
#define ETH_MACCR_S2KP                                      (0x1U<<22U)
#define ETH_MACCR_CST                                       (0x1U<<21U)
#define ETH_MACCR_ACS                                       (0x1U<<20U)
#define ETH_MACCR_WD                                        (0x1U<<19U)
#define ETH_MACCR_BE                                        (0x1U<<18U)
#define ETH_MACCR_JD                                        (0x1U<<17U)
#define ETH_MACCR_JE                                        (0x1U<<16U)
#define ETH_MACCR_PS                                        (0x1U<<15U)
#define ETH_MACCR_FES                                       (0x1U<<14U)
#define ETH_MACCR_DM                                        (0x1U<<13U)
#define ETH_MACCR_LM                                        (0x1U<<12U)
#define ETH_MACCR_ECRSFD                                    (0x1U<<11U)
#define ETH_MACCR_DO                                        (0x1U<<10U)
#define ETH_MACCR_DCRS                                      (0x1U<<9U)
#define ETH_MACCR_DR                                        (0x1U<<8U)
#define ETH_MACCR_BL                                        (0x3U<<5U)
#define ETH_MACCR_BL_0                                      (0x1U<<5U)
#define ETH_MACCR_DC                                        (0x1U<<4U)
#define ETH_MACCR_PRELEN                                    (0x3U<<2U)
#define ETH_MACCR_PRELEN_0                                  (0x1U<<2U)
#define ETH_MACCR_TE                                        (0x1U<<1U)
#define ETH_MACCR_RE                                        (0x1U<<0U)

#define ETH_MACCR_SARC_B_0X2                                (0x2U<<28U)
#define ETH_MACCR_SARC_B_0X3                                (0x3U<<28U)
#define ETH_MACCR_SARC_B_0X6                                (0x6U<<28U)
#define ETH_MACCR_SARC_B_0X7                                (0x7U<<28U)
#define ETH_MACCR_IPG_B_0X0                                 (0x0U<<24U)
#define ETH_MACCR_IPG_B_0X1                                 (0x1U<<24U)
#define ETH_MACCR_IPG_B_0X2                                 (0x2U<<24U)
#define ETH_MACCR_IPG_B_0X7                                 (0x7U<<24U)
#define ETH_MACCR_PS_B_0X0                                  (0x0U<<15U)
#define ETH_MACCR_PS_B_0X1                                  (0x1U<<15U)
#define ETH_MACCR_FES_B_0X0                                 (0x0U<<14U)
#define ETH_MACCR_FES_B_0X1                                 (0x1U<<14U)
#define ETH_MACCR_BL_B_0X0                                  (0x0U<<5U)
#define ETH_MACCR_BL_B_0X1                                  (0x1U<<5U)
#define ETH_MACCR_BL_B_0X2                                  (0x2U<<5U)
#define ETH_MACCR_BL_B_0X3                                  (0x3U<<5U)
#define ETH_MACCR_PRELEN_B_0X0                              (0x0U<<2U)
#define ETH_MACCR_PRELEN_B_0X1                              (0x1U<<2U)
#define ETH_MACCR_PRELEN_B_0X2                              (0x2U<<2U)

// MACECR Configuration

#define ETH_MACECR_APDIM                                    (0x1U<<30U)
#define ETH_MACECR_EIPG                                     (0x1FU<<25U)
#define ETH_MACECR_EIPG_0                                   (0x1U<<25U)
#define ETH_MACECR_EIPGEN                                   (0x1U<<24U)
#define ETH_MACECR_USP                                      (0x1U<<18U)
#define ETH_MACECR_SPEN                                     (0x1U<<17U)
#define ETH_MACECR_DCRCC                                    (0x1U<<16U)
#define ETH_MACECR_GPSL                                     (0x3FFFU<<0U)
#define ETH_MACECR_GPSL_0                                   (0x1U<<0U)

// MACPFR Configuration

#define ETH_MACPFR_RA                                       (0x1U<<31U)
#define ETH_MACPFR_DNTU                                     (0x1U<<21U)
#define ETH_MACPFR_IPFE                                     (0x1U<<20U)
#define ETH_MACPFR_VTFE                                     (0x1U<<16U)
#define ETH_MACPFR_HPF                                      (0x1U<<10U)
#define ETH_MACPFR_SAF                                      (0x1U<<9U)
#define ETH_MACPFR_SAIF                                     (0x1U<<8U)
#define ETH_MACPFR_PCF                                      (0x3U<<6U)
#define ETH_MACPFR_PCF_0                                    (0x1U<<6U)
#define ETH_MACPFR_DBF                                      (0x1U<<5U)
#define ETH_MACPFR_PM                                       (0x1U<<4U)
#define ETH_MACPFR_DAIF                                     (0x1U<<3U)
#define ETH_MACPFR_HMC                                      (0x1U<<2U)
#define ETH_MACPFR_HUC                                      (0x1U<<1U)
#define ETH_MACPFR_PR                                       (0x1U<<0U)

#define ETH_MACPFR_PCF_B_0X0                                (0x0U<<6U)
#define ETH_MACPFR_PCF_B_0X1                                (0x1U<<6U)
#define ETH_MACPFR_PCF_B_0X2                                (0x2U<<6U)
#define ETH_MACPFR_PCF_B_0X3                                (0x3U<<6U)

// MACWTR Configuration

#define ETH_MACWTR_PWE                                      (0x1U<<8U)
#define ETH_MACWTR_WTO                                      (0xFU<<0U)
#define ETH_MACWTR_WTO_0                                    (0x1U<<0U)

#define ETH_MACWTR_WTO_B_0X0                                (0x0U<<0U)
#define ETH_MACWTR_WTO_B_0X1                                (0x1U<<0U)
#define ETH_MACWTR_WTO_B_0X2                                (0x2U<<0U)
#define ETH_MACWTR_WTO_B_0X3                                (0x3U<<0U)
#define ETH_MACWTR_WTO_B_0XC                                (0xCU<<0U)
#define ETH_MACWTR_WTO_B_0XD                                (0xDU<<0U)
#define ETH_MACWTR_WTO_B_0XE                                (0xEU<<0U)

// MACHT0R Configuration

#define ETH_MACHT0R_HT31T0                                  (0xFFFFFFFFU<<0U)
#define ETH_MACHT0R_HT31T0_0                                (0x1U<<0U)

// MACHT1R Configuration

#define ETH_MACHT1R_HT63T32                                 (0xFFFFFFFFU<<0U)
#define ETH_MACHT1R_HT63T32_0                               (0x1U<<0U)

// MACVTCR Configuration

#define ETH_MACVTCR_EIVLRXS                                 (0x1U<<31U)
#define ETH_MACVTCR_EIVLS                                   (0x3U<<28U)
#define ETH_MACVTCR_EIVLS_0                                 (0x1U<<28U)
#define ETH_MACVTCR_ERIVLT                                  (0x1U<<27U)
#define ETH_MACVTCR_EDVLP                                   (0x1U<<26U)
#define ETH_MACVTCR_VTHM                                    (0x1U<<25U)
#define ETH_MACVTCR_EVLRXS                                  (0x1U<<24U)
#define ETH_MACVTCR_EVLS                                    (0x3U<<21U)
#define ETH_MACVTCR_EVLS_0                                  (0x1U<<21U)
#define ETH_MACVTCR_DOVLTC                                  (0x1U<<20U)
#define ETH_MACVTCR_ERSVLM                                  (0x1U<<19U)
#define ETH_MACVTCR_ESVL                                    (0x1U<<18U)
#define ETH_MACVTCR_VTIM                                    (0x1U<<17U)
#define ETH_MACVTCR_ETV                                     (0x1U<<16U)
#define ETH_MACVTCR_OFS                                     (0x3U<<2U)
#define ETH_MACVTCR_OFS_0                                   (0x1U<<2U)
#define ETH_MACVTCR_CT                                      (0x1U<<1U)
#define ETH_MACVTCR_OB                                      (0x1U<<0U)

#define ETH_MACVTCR_EIVLS_B_0X0                             (0x0U<<28U)
#define ETH_MACVTCR_EIVLS_B_0X1                             (0x1U<<28U)
#define ETH_MACVTCR_EIVLS_B_0X2                             (0x2U<<28U)
#define ETH_MACVTCR_EIVLS_B_0X3                             (0x3U<<28U)
#define ETH_MACVTCR_EVLS_B_0X0                              (0x0U<<21U)
#define ETH_MACVTCR_EVLS_B_0X1                              (0x1U<<21U)
#define ETH_MACVTCR_EVLS_B_0X2                              (0x2U<<21U)
#define ETH_MACVTCR_EVLS_B_0X3                              (0x3U<<21U)
#define ETH_MACVTCR_OFS_B_0X0                               (0x0U<<2U)
#define ETH_MACVTCR_OFS_B_0X1                               (0x1U<<2U)
#define ETH_MACVTCR_OFS_B_0X2                               (0x2U<<2U)
#define ETH_MACVTCR_OFS_B_0X3                               (0x3U<<2U)

// MACVTDR Configuration

#define ETH_MACVTDR_DMACHN                                  (0x1U<<25U)
#define ETH_MACVTDR_DMACHEN                                 (0x1U<<24U)
#define ETH_MACVTDR_ERIVLT                                  (0x1U<<20U)
#define ETH_MACVTDR_ERSVLM                                  (0x1U<<19U)
#define ETH_MACVTDR_DOVLTC                                  (0x1U<<18U)
#define ETH_MACVTDR_ETV                                     (0x1U<<17U)
#define ETH_MACVTDR_VEN                                     (0x1U<<16U)
#define ETH_MACVTDR_VID                                     (0xFFFFU<<0U)
#define ETH_MACVTDR_VID_0                                   (0x1U<<0U)

#define ETH_MACVTDR_ETV_B_0X0                               (0x0U<<17U)
#define ETH_MACVTDR_ETV_B_0X1                               (0x1U<<17U)

// MACVHTR Configuration

#define ETH_MACVHTR_VLHT                                    (0xFFFFU<<0U)
#define ETH_MACVHTR_VLHT_0                                  (0x1U<<0U)

// MACVIR Configuration

#define ETH_MACVIR_BUSY                                     (0x1U<<31U)
#define ETH_MACVIR_RDWR                                     (0x1U<<30U)
#define ETH_MACVIR_ADDR                                     (0x1U<<24U)
#define ETH_MACVIR_CBTI                                     (0x1U<<21U)
#define ETH_MACVIR_VLTI                                     (0x1U<<20U)
#define ETH_MACVIR_CSVL                                     (0x1U<<19U)
#define ETH_MACVIR_VLP                                      (0x1U<<18U)
#define ETH_MACVIR_VLC                                      (0x3U<<16U)
#define ETH_MACVIR_VLC_0                                    (0x1U<<16U)
#define ETH_MACVIR_VLT                                      (0xFFFFU<<0U)
#define ETH_MACVIR_VLT_0                                    (0x1U<<0U)

#define ETH_MACVIR_ADDR_B_0X0                               (0x0U<<24U)
#define ETH_MACVIR_ADDR_B_0X1                               (0x1U<<24U)
#define ETH_MACVIR_CSVL_B_0X0                               (0x0U<<19U)
#define ETH_MACVIR_CSVL_B_0X1                               (0x1U<<19U)
#define ETH_MACVIR_VLC_B_0X0                                (0x0U<<16U)
#define ETH_MACVIR_VLC_B_0X1                                (0x1U<<16U)
#define ETH_MACVIR_VLC_B_0X2                                (0x2U<<16U)
#define ETH_MACVIR_VLC_B_0X3                                (0x3U<<16U)

// MACVIR_ALTERNATE Configuration

#define ETH_MACVIR_ALTERNATE_CSVL                           (0x1U<<19U)
#define ETH_MACVIR_ALTERNATE_VLT                            (0xFFFFU<<0U)
#define ETH_MACVIR_ALTERNATE_VLT_0                          (0x1U<<0U)

#define ETH_MACVIR_ALTERNATE_CSVL_B_0X0                     (0x0U<<19U)
#define ETH_MACVIR_ALTERNATE_CSVL_B_0X1                     (0x1U<<19U)

// MACIVIR Configuration

#define ETH_MACIVIR_VLTI                                    (0x1U<<20U)
#define ETH_MACIVIR_CSVL                                    (0x1U<<19U)
#define ETH_MACIVIR_VLP                                     (0x1U<<18U)
#define ETH_MACIVIR_VLC                                     (0x3U<<16U)
#define ETH_MACIVIR_VLC_0                                   (0x1U<<16U)
#define ETH_MACIVIR_VLT                                     (0xFFFFU<<0U)
#define ETH_MACIVIR_VLT_0                                   (0x1U<<0U)

#define ETH_MACIVIR_CSVL_B_0X0                              (0x0U<<19U)
#define ETH_MACIVIR_CSVL_B_0X1                              (0x1U<<19U)
#define ETH_MACIVIR_VLC_B_0X0                               (0x0U<<16U)
#define ETH_MACIVIR_VLC_B_0X1                               (0x1U<<16U)
#define ETH_MACIVIR_VLC_B_0X2                               (0x2U<<16U)
#define ETH_MACIVIR_VLC_B_0X3                               (0x3U<<16U)

// MACQ0TXFCR Configuration

#define ETH_MACQ0TXFCR_PT                                   (0xFFFFU<<16U)
#define ETH_MACQ0TXFCR_PT_0                                 (0x1U<<16U)
#define ETH_MACQ0TXFCR_DZPQ                                 (0x1U<<7U)
#define ETH_MACQ0TXFCR_PLT                                  (0x7U<<4U)
#define ETH_MACQ0TXFCR_PLT_0                                (0x1U<<4U)
#define ETH_MACQ0TXFCR_TFE                                  (0x1U<<1U)
#define ETH_MACQ0TXFCR_FCB_BPA                              (0x1U<<0U)

#define ETH_MACQ0TXFCR_PLT_B_0X0                            (0x0U<<4U)
#define ETH_MACQ0TXFCR_PLT_B_0X1                            (0x1U<<4U)
#define ETH_MACQ0TXFCR_PLT_B_0X2                            (0x2U<<4U)
#define ETH_MACQ0TXFCR_PLT_B_0X3                            (0x3U<<4U)
#define ETH_MACQ0TXFCR_PLT_B_0X4                            (0x4U<<4U)
#define ETH_MACQ0TXFCR_PLT_B_0X5                            (0x5U<<4U)

// MACRXFCR Configuration

#define ETH_MACRXFCR_UP                                     (0x1U<<1U)
#define ETH_MACRXFCR_RFE                                    (0x1U<<0U)

// MACRXQCR Configuration

#define ETH_MACRXQCR_VFFQ                                   (0x1U<<17U)
#define ETH_MACRXQCR_VFFQE                                  (0x1U<<16U)
#define ETH_MACRXQCR_MFFQ                                   (0x1U<<9U)
#define ETH_MACRXQCR_MFFQE                                  (0x1U<<8U)
#define ETH_MACRXQCR_UFFQ                                   (0x1U<<1U)
#define ETH_MACRXQCR_UFFQE                                  (0x1U<<0U)

#define ETH_MACRXQCR_VFFQ_B_0X0                             (0x0U<<17U)
#define ETH_MACRXQCR_VFFQ_B_0X1                             (0x1U<<17U)
#define ETH_MACRXQCR_VFFQE_B_0X0                            (0x0U<<16U)
#define ETH_MACRXQCR_VFFQE_B_0X1                            (0x1U<<16U)
#define ETH_MACRXQCR_MFFQ_B_0X0                             (0x0U<<9U)
#define ETH_MACRXQCR_MFFQ_B_0X1                             (0x1U<<9U)
#define ETH_MACRXQCR_UFFQ_B_0X0                             (0x0U<<1U)
#define ETH_MACRXQCR_UFFQ_B_0X1                             (0x1U<<1U)

// MACRXQC0R Configuration

#define ETH_MACRXQC0R_RXQ1EN                                (0x3U<<2U)
#define ETH_MACRXQC0R_RXQ1EN_0                              (0x1U<<2U)
#define ETH_MACRXQC0R_RXQ0EN                                (0x3U<<0U)
#define ETH_MACRXQC0R_RXQ0EN_0                              (0x1U<<0U)

#define ETH_MACRXQC0R_RXQ1EN_B_0X0                          (0x0U<<2U)
#define ETH_MACRXQC0R_RXQ1EN_B_0X1                          (0x1U<<2U)
#define ETH_MACRXQC0R_RXQ1EN_B_0X2                          (0x2U<<2U)
#define ETH_MACRXQC0R_RXQ0EN_B_0X0                          (0x0U<<0U)
#define ETH_MACRXQC0R_RXQ0EN_B_0X1                          (0x1U<<0U)
#define ETH_MACRXQC0R_RXQ0EN_B_0X2                          (0x2U<<0U)

// MACRXQC1R Configuration

#define ETH_MACRXQC1R_TBRQE                                 (0x1U<<29U)
#define ETH_MACRXQC1R_OMCBCQ                                (0x1U<<28U)
#define ETH_MACRXQC1R_FPRQ2                                 (0x1U<<26U)
#define ETH_MACRXQC1R_FPRQ1                                 (0x1U<<25U)
#define ETH_MACRXQC1R_FPRQ0                                 (0x1U<<24U)
#define ETH_MACRXQC1R_TPQC                                  (0x3U<<22U)
#define ETH_MACRXQC1R_TPQC_0                                (0x1U<<22U)
#define ETH_MACRXQC1R_TACPQE                                (0x1U<<21U)
#define ETH_MACRXQC1R_MCBCQEN                               (0x1U<<20U)
#define ETH_MACRXQC1R_MCBCQ                                 (0x7U<<16U)
#define ETH_MACRXQC1R_MCBCQ_0                               (0x1U<<16U)
#define ETH_MACRXQC1R_UPQ                                   (0x7U<<12U)
#define ETH_MACRXQC1R_UPQ_0                                 (0x1U<<12U)
#define ETH_MACRXQC1R_PTPQ                                  (0x7U<<4U)
#define ETH_MACRXQC1R_PTPQ_0                                (0x1U<<4U)
#define ETH_MACRXQC1R_AVCPQ2                                (0x1U<<2U)
#define ETH_MACRXQC1R_AVCPQ1                                (0x1U<<1U)
#define ETH_MACRXQC1R_AVCPQ0                                (0x1U<<0U)

#define ETH_MACRXQC1R_OMCBCQ_B_0X1                          (0x1U<<28U)
#define ETH_MACRXQC1R_OMCBCQ_B_0X0                          (0x0U<<28U)
#define ETH_MACRXQC1R_FPRQ2_B_0X1                           (0x1U<<26U)
#define ETH_MACRXQC1R_FPRQ1_B_0X1                           (0x1U<<25U)
#define ETH_MACRXQC1R_FPRQ0_B_0X1                           (0x1U<<24U)
#define ETH_MACRXQC1R_TPQC_B_0X0                            (0x0U<<22U)
#define ETH_MACRXQC1R_TPQC_B_0X1                            (0x1U<<22U)
#define ETH_MACRXQC1R_TPQC_B_0X2                            (0x2U<<22U)
#define ETH_MACRXQC1R_MCBCQ_B_0X0                           (0x0U<<16U)
#define ETH_MACRXQC1R_MCBCQ_B_0X1                           (0x1U<<16U)
#define ETH_MACRXQC1R_UPQ_B_0X0                             (0x0U<<12U)
#define ETH_MACRXQC1R_UPQ_B_0X1                             (0x1U<<12U)
#define ETH_MACRXQC1R_PTPQ_B_0X0                            (0x0U<<4U)
#define ETH_MACRXQC1R_PTPQ_B_0X1                            (0x1U<<4U)
#define ETH_MACRXQC1R_AVCPQ2_B_0X0                          (0x0U<<2U)
#define ETH_MACRXQC1R_AVCPQ2_B_0X1                          (0x1U<<2U)
#define ETH_MACRXQC1R_AVCPQ1_B_0X0                          (0x0U<<1U)
#define ETH_MACRXQC1R_AVCPQ1_B_0X1                          (0x1U<<1U)
#define ETH_MACRXQC1R_AVCPQ0_B_0X0                          (0x0U<<0U)
#define ETH_MACRXQC1R_AVCPQ0_B_0X1                          (0x1U<<0U)

// MACRXQC2R Configuration

#define ETH_MACRXQC2R_PSRQ1                                 (0xFFU<<8U)
#define ETH_MACRXQC2R_PSRQ1_0                               (0x1U<<8U)
#define ETH_MACRXQC2R_PSRQ0                                 (0xFFU<<0U)
#define ETH_MACRXQC2R_PSRQ0_0                               (0x1U<<0U)

// MACISR Configuration

#define ETH_MACISR_MFRIS                                    (0x1U<<20U)
#define ETH_MACISR_MFTIS                                    (0x1U<<19U)
#define ETH_MACISR_MDIOIS                                   (0x1U<<18U)
#define ETH_MACISR_FPEIS                                    (0x1U<<17U)
#define ETH_MACISR_RXSTSIS                                  (0x1U<<14U)
#define ETH_MACISR_TXSTSIS                                  (0x1U<<13U)
#define ETH_MACISR_TSIS                                     (0x1U<<12U)
#define ETH_MACISR_MMCTXIS                                  (0x1U<<10U)
#define ETH_MACISR_MMCRXIS                                  (0x1U<<9U)
#define ETH_MACISR_MMCIS                                    (0x1U<<8U)
#define ETH_MACISR_LPIIS                                    (0x1U<<5U)
#define ETH_MACISR_PMTIS                                    (0x1U<<4U)
#define ETH_MACISR_PHYIS                                    (0x1U<<3U)
#define ETH_MACISR_RGSMIIIS                                 (0x1U<<0U)

// MACIER Configuration

#define ETH_MACIER_MDIOIE                                   (0x1U<<18U)
#define ETH_MACIER_FPEIE                                    (0x1U<<17U)
#define ETH_MACIER_RXSTSIE                                  (0x1U<<14U)
#define ETH_MACIER_TXSTSIE                                  (0x1U<<13U)
#define ETH_MACIER_TSIE                                     (0x1U<<12U)
#define ETH_MACIER_LPIIE                                    (0x1U<<5U)
#define ETH_MACIER_PMTIE                                    (0x1U<<4U)
#define ETH_MACIER_PHYIE                                    (0x1U<<3U)
#define ETH_MACIER_RGSMIIIE                                 (0x1U<<0U)

// MACRXTXSR Configuration

#define ETH_MACRXTXSR_RWT                                   (0x1U<<8U)
#define ETH_MACRXTXSR_EXCOL                                 (0x1U<<5U)
#define ETH_MACRXTXSR_LCOL                                  (0x1U<<4U)
#define ETH_MACRXTXSR_EXDEF                                 (0x1U<<3U)
#define ETH_MACRXTXSR_LCARR                                 (0x1U<<2U)
#define ETH_MACRXTXSR_NCARR                                 (0x1U<<1U)
#define ETH_MACRXTXSR_TJT                                   (0x1U<<0U)

// MACPCSR Configuration

#define ETH_MACPCSR_RWKFILTRST                              (0x1U<<31U)
#define ETH_MACPCSR_RWKPTR                                  (0x1FU<<24U)
#define ETH_MACPCSR_RWKPTR_0                                (0x1U<<24U)
#define ETH_MACPCSR_RWKPFE                                  (0x1U<<10U)
#define ETH_MACPCSR_GLBLUCAST                               (0x1U<<9U)
#define ETH_MACPCSR_RWKPRCVD                                (0x1U<<6U)
#define ETH_MACPCSR_MGKPRCVD                                (0x1U<<5U)
#define ETH_MACPCSR_RWKPKTEN                                (0x1U<<2U)
#define ETH_MACPCSR_MGKPKTEN                                (0x1U<<1U)
#define ETH_MACPCSR_PWRDWN                                  (0x1U<<0U)

// MACRWKPFR Configuration

#define ETH_MACRWKPFR_MACRWKPFR                             (0xFFFFFFFFU<<0U)
#define ETH_MACRWKPFR_MACRWKPFR_0                           (0x1U<<0U)

// MACLCSR Configuration

#define ETH_MACLCSR_LPITCSE                                 (0x1U<<21U)
#define ETH_MACLCSR_LPITE                                   (0x1U<<20U)
#define ETH_MACLCSR_LPITXA                                  (0x1U<<19U)
#define ETH_MACLCSR_PLSEN                                   (0x1U<<18U)
#define ETH_MACLCSR_PLS                                     (0x1U<<17U)
#define ETH_MACLCSR_LPIEN                                   (0x1U<<16U)
#define ETH_MACLCSR_RLPIST                                  (0x1U<<9U)
#define ETH_MACLCSR_TLPIST                                  (0x1U<<8U)
#define ETH_MACLCSR_RLPIEX                                  (0x1U<<3U)
#define ETH_MACLCSR_RLPIEN                                  (0x1U<<2U)
#define ETH_MACLCSR_TLPIEX                                  (0x1U<<1U)
#define ETH_MACLCSR_TLPIEN                                  (0x1U<<0U)

// MACLTCR Configuration

#define ETH_MACLTCR_LST                                     (0x3FFU<<16U)
#define ETH_MACLTCR_LST_0                                   (0x1U<<16U)
#define ETH_MACLTCR_TWT                                     (0xFFFFU<<0U)
#define ETH_MACLTCR_TWT_0                                   (0x1U<<0U)

// MACLETR Configuration

#define ETH_MACLETR_LPIET                                   (0xFFFFFU<<0U)
#define ETH_MACLETR_LPIET_0                                 (0x1U<<0U)

// MAC1USTCR Configuration

#define ETH_MAC1USTCR_TIC_1US_CNTR                          (0xFFFU<<0U)
#define ETH_MAC1USTCR_TIC_1US_CNTR_0                        (0x1U<<0U)

// MACPHYCSR Configuration

#define ETH_MACPHYCSR_LNKSTS                                (0x1U<<19U)
#define ETH_MACPHYCSR_LNKSPEED                              (0x3U<<17U)
#define ETH_MACPHYCSR_LNKSPEED_0                            (0x1U<<17U)
#define ETH_MACPHYCSR_LNKMOD                                (0x1U<<16U)
#define ETH_MACPHYCSR_LUD                                   (0x1U<<1U)
#define ETH_MACPHYCSR_TC                                    (0x1U<<0U)

#define ETH_MACPHYCSR_LNKSTS_B_0X0                          (0x0U<<19U)
#define ETH_MACPHYCSR_LNKSTS_B_0X1                          (0x1U<<19U)
#define ETH_MACPHYCSR_LNKSPEED_B_0X0                        (0x0U<<17U)
#define ETH_MACPHYCSR_LNKSPEED_B_0X1                        (0x1U<<17U)
#define ETH_MACPHYCSR_LNKSPEED_B_0X2                        (0x2U<<17U)
#define ETH_MACPHYCSR_LNKMOD_B_0X0                          (0x0U<<16U)
#define ETH_MACPHYCSR_LNKMOD_B_0X1                          (0x1U<<16U)
#define ETH_MACPHYCSR_LUD_B_0X0                             (0x0U<<1U)
#define ETH_MACPHYCSR_LUD_B_0X1                             (0x1U<<1U)

// MACVR Configuration

#define ETH_MACVR_USERVER                                   (0xFFU<<8U)
#define ETH_MACVR_USERVER_0                                 (0x1U<<8U)
#define ETH_MACVR_SNPSVER                                   (0xFFU<<0U)
#define ETH_MACVR_SNPSVER_0                                 (0x1U<<0U)

// MACDR Configuration

#define ETH_MACDR_TFCSTS                                    (0x3U<<17U)
#define ETH_MACDR_TFCSTS_0                                  (0x1U<<17U)
#define ETH_MACDR_TPESTS                                    (0x1U<<16U)
#define ETH_MACDR_RFCFCSTS                                  (0x3U<<1U)
#define ETH_MACDR_RFCFCSTS_0                                (0x1U<<1U)
#define ETH_MACDR_RPESTS                                    (0x1U<<0U)

#define ETH_MACDR_TFCSTS_B_0X0                              (0x0U<<17U)
#define ETH_MACDR_TFCSTS_B_0X1                              (0x1U<<17U)
#define ETH_MACDR_TFCSTS_B_0X2                              (0x2U<<17U)
#define ETH_MACDR_TFCSTS_B_0X3                              (0x3U<<17U)

// MACHWF0R Configuration

#define ETH_MACHWF0R_ACTPHYSEL                              (0x7U<<28U)
#define ETH_MACHWF0R_ACTPHYSEL_0                            (0x1U<<28U)
#define ETH_MACHWF0R_SAVLANINS                              (0x1U<<27U)
#define ETH_MACHWF0R_TSSTSSEL                               (0x3U<<25U)
#define ETH_MACHWF0R_TSSTSSEL_0                             (0x1U<<25U)
#define ETH_MACHWF0R_MACADR64SEL                            (0x1U<<24U)
#define ETH_MACHWF0R_MACADR32SEL                            (0x1U<<23U)
#define ETH_MACHWF0R_ADDMACADRSEL                           (0x1FU<<18U)
#define ETH_MACHWF0R_ADDMACADRSEL_0                         (0x1U<<18U)
#define ETH_MACHWF0R_RXCOESEL                               (0x1U<<16U)
#define ETH_MACHWF0R_TXCOESEL                               (0x1U<<14U)
#define ETH_MACHWF0R_EEESEL                                 (0x1U<<13U)
#define ETH_MACHWF0R_TSSEL                                  (0x1U<<12U)
#define ETH_MACHWF0R_ARPOFFSEL                              (0x1U<<9U)
#define ETH_MACHWF0R_MMCSEL                                 (0x1U<<8U)
#define ETH_MACHWF0R_MGKSEL                                 (0x1U<<7U)
#define ETH_MACHWF0R_RWKSEL                                 (0x1U<<6U)
#define ETH_MACHWF0R_SMASEL                                 (0x1U<<5U)
#define ETH_MACHWF0R_VLHASH                                 (0x1U<<4U)
#define ETH_MACHWF0R_PCSSEL                                 (0x1U<<3U)
#define ETH_MACHWF0R_HDSEL                                  (0x1U<<2U)
#define ETH_MACHWF0R_GMIISEL                                (0x1U<<1U)
#define ETH_MACHWF0R_MIISEL                                 (0x1U<<0U)

#define ETH_MACHWF0R_ACTPHYSEL_B_0X0                        (0x0U<<28U)
#define ETH_MACHWF0R_ACTPHYSEL_B_0X1                        (0x1U<<28U)
#define ETH_MACHWF0R_ACTPHYSEL_B_0X2                        (0x2U<<28U)
#define ETH_MACHWF0R_ACTPHYSEL_B_0X3                        (0x3U<<28U)
#define ETH_MACHWF0R_ACTPHYSEL_B_0X4                        (0x4U<<28U)
#define ETH_MACHWF0R_ACTPHYSEL_B_0X5                        (0x5U<<28U)
#define ETH_MACHWF0R_ACTPHYSEL_B_0X6                        (0x6U<<28U)
#define ETH_MACHWF0R_TSSTSSEL_B_0X1                         (0x1U<<25U)
#define ETH_MACHWF0R_TSSTSSEL_B_0X2                         (0x2U<<25U)
#define ETH_MACHWF0R_TSSTSSEL_B_0X3                         (0x3U<<25U)

// MACHWF1R Configuration

#define ETH_MACHWF1R_L3L4FNUM                               (0xFU<<27U)
#define ETH_MACHWF1R_L3L4FNUM_0                             (0x1U<<27U)
#define ETH_MACHWF1R_HASHTBLSZ                              (0x3U<<24U)
#define ETH_MACHWF1R_HASHTBLSZ_0                            (0x1U<<24U)
#define ETH_MACHWF1R_POUOST                                 (0x1U<<23U)
#define ETH_MACHWF1R_RAVSEL                                 (0x1U<<21U)
#define ETH_MACHWF1R_AVSEL                                  (0x1U<<20U)
#define ETH_MACHWF1R_DBGMEMA                                (0x1U<<19U)
#define ETH_MACHWF1R_TSOEN                                  (0x1U<<18U)
#define ETH_MACHWF1R_SPHEN                                  (0x1U<<17U)
#define ETH_MACHWF1R_DCBEN                                  (0x1U<<16U)
#define ETH_MACHWF1R_ADDR64                                 (0x3U<<14U)
#define ETH_MACHWF1R_ADDR64_0                               (0x1U<<14U)
#define ETH_MACHWF1R_ADVTHWORD                              (0x1U<<13U)
#define ETH_MACHWF1R_PTOEN                                  (0x1U<<12U)
#define ETH_MACHWF1R_OSTEN                                  (0x1U<<11U)
#define ETH_MACHWF1R_TXFIFOSIZE                             (0x1FU<<6U)
#define ETH_MACHWF1R_TXFIFOSIZE_0                           (0x1U<<6U)
#define ETH_MACHWF1R_SPRAM                                  (0x1U<<5U)
#define ETH_MACHWF1R_RXFIFOSIZE                             (0x1FU<<0U)
#define ETH_MACHWF1R_RXFIFOSIZE_0                           (0x1U<<0U)

#define ETH_MACHWF1R_L3L4FNUM_B_0X0                         (0x0U<<27U)
#define ETH_MACHWF1R_L3L4FNUM_B_0X1                         (0x1U<<27U)
#define ETH_MACHWF1R_L3L4FNUM_B_0X2                         (0x2U<<27U)
#define ETH_MACHWF1R_L3L4FNUM_B_0X8                         (0x8U<<27U)
#define ETH_MACHWF1R_HASHTBLSZ_B_0X0                        (0x0U<<24U)
#define ETH_MACHWF1R_HASHTBLSZ_B_0X1                        (0x1U<<24U)
#define ETH_MACHWF1R_HASHTBLSZ_B_0X2                        (0x2U<<24U)
#define ETH_MACHWF1R_HASHTBLSZ_B_0X3                        (0x3U<<24U)
#define ETH_MACHWF1R_ADDR64_B_0X0                           (0x0U<<14U)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0X0                       (0x0U<<6U)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0X1                       (0x1U<<6U)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0X2                       (0x2U<<6U)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0X3                       (0x3U<<6U)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0X4                       (0x4U<<6U)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0X5                       (0x5U<<6U)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0X6                       (0x6U<<6U)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0X7                       (0x7U<<6U)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0X8                       (0x8U<<6U)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0X9                       (0x9U<<6U)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0XA                       (0xAU<<6U)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0X0                       (0x0U<<0U)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0X1                       (0x1U<<0U)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0X2                       (0x2U<<0U)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0X3                       (0x3U<<0U)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0X4                       (0x4U<<0U)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0X5                       (0x5U<<0U)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0X6                       (0x6U<<0U)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0X7                       (0x7U<<0U)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0X8                       (0x8U<<0U)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0X9                       (0x9U<<0U)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0XA                       (0xAU<<0U)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0XB                       (0xBU<<0U)

// MACHWF2R Configuration

#define ETH_MACHWF2R_AUXSNAPNUM                             (0x7U<<28U)
#define ETH_MACHWF2R_AUXSNAPNUM_0                           (0x1U<<28U)
#define ETH_MACHWF2R_PPSOUTNUM                              (0x7U<<24U)
#define ETH_MACHWF2R_PPSOUTNUM_0                            (0x1U<<24U)
#define ETH_MACHWF2R_TDCSZ                                  (0x3U<<22U)
#define ETH_MACHWF2R_TDCSZ_0                                (0x1U<<22U)
#define ETH_MACHWF2R_TXCHCNT                                (0xFU<<18U)
#define ETH_MACHWF2R_TXCHCNT_0                              (0x1U<<18U)
#define ETH_MACHWF2R_RDCSZ                                  (0x3U<<16U)
#define ETH_MACHWF2R_RDCSZ_0                                (0x1U<<16U)
#define ETH_MACHWF2R_RXCHCNT                                (0xFU<<12U)
#define ETH_MACHWF2R_RXCHCNT_0                              (0x1U<<12U)
#define ETH_MACHWF2R_TXQCNT                                 (0xFU<<6U)
#define ETH_MACHWF2R_TXQCNT_0                               (0x1U<<6U)
#define ETH_MACHWF2R_RXQCNT                                 (0xFU<<0U)
#define ETH_MACHWF2R_RXQCNT_0                               (0x1U<<0U)

#define ETH_MACHWF2R_AUXSNAPNUM_B_0X0                       (0x0U<<28U)
#define ETH_MACHWF2R_AUXSNAPNUM_B_0X1                       (0x1U<<28U)
#define ETH_MACHWF2R_AUXSNAPNUM_B_0X2                       (0x2U<<28U)
#define ETH_MACHWF2R_AUXSNAPNUM_B_0X3                       (0x3U<<28U)
#define ETH_MACHWF2R_AUXSNAPNUM_B_0X4                       (0x4U<<28U)
#define ETH_MACHWF2R_PPSOUTNUM_B_0X0                        (0x0U<<24U)
#define ETH_MACHWF2R_PPSOUTNUM_B_0X1                        (0x1U<<24U)
#define ETH_MACHWF2R_PPSOUTNUM_B_0X2                        (0x2U<<24U)
#define ETH_MACHWF2R_PPSOUTNUM_B_0X3                        (0x3U<<24U)
#define ETH_MACHWF2R_PPSOUTNUM_B_0X4                        (0x4U<<24U)
#define ETH_MACHWF2R_TDCSZ_B_0X0                            (0x0U<<22U)
#define ETH_MACHWF2R_TDCSZ_B_0X1                            (0x1U<<22U)
#define ETH_MACHWF2R_TDCSZ_B_0X2                            (0x2U<<22U)
#define ETH_MACHWF2R_TDCSZ_B_0X3                            (0x3U<<22U)
#define ETH_MACHWF2R_TXCHCNT_B_0X0                          (0x0U<<18U)
#define ETH_MACHWF2R_TXCHCNT_B_0X1                          (0x1U<<18U)
#define ETH_MACHWF2R_TXCHCNT_B_0X7                          (0x7U<<18U)
#define ETH_MACHWF2R_RDCSZ_B_0X0                            (0x0U<<16U)
#define ETH_MACHWF2R_RDCSZ_B_0X1                            (0x1U<<16U)
#define ETH_MACHWF2R_RDCSZ_B_0X2                            (0x2U<<16U)
#define ETH_MACHWF2R_RDCSZ_B_0X3                            (0x3U<<16U)
#define ETH_MACHWF2R_RXCHCNT_B_0X0                          (0x0U<<12U)
#define ETH_MACHWF2R_RXCHCNT_B_0X1                          (0x1U<<12U)
#define ETH_MACHWF2R_RXCHCNT_B_0X7                          (0x7U<<12U)
#define ETH_MACHWF2R_TXQCNT_B_0X0                           (0x0U<<6U)
#define ETH_MACHWF2R_TXQCNT_B_0X1                           (0x1U<<6U)
#define ETH_MACHWF2R_TXQCNT_B_0X7                           (0x7U<<6U)
#define ETH_MACHWF2R_RXQCNT_B_0X0                           (0x0U<<0U)
#define ETH_MACHWF2R_RXQCNT_B_0X1                           (0x1U<<0U)
#define ETH_MACHWF2R_RXQCNT_B_0X7                           (0x7U<<0U)

// MACHWF3R Configuration

#define ETH_MACHWF3R_ASP                                    (0x3U<<28U)
#define ETH_MACHWF3R_ASP_0                                  (0x1U<<28U)
#define ETH_MACHWF3R_TBSSEL                                 (0x1U<<27U)
#define ETH_MACHWF3R_FPESEL                                 (0x1U<<26U)
#define ETH_MACHWF3R_ESTWID                                 (0x3U<<20U)
#define ETH_MACHWF3R_ESTWID_0                               (0x1U<<20U)
#define ETH_MACHWF3R_ESTDEP                                 (0x7U<<17U)
#define ETH_MACHWF3R_ESTDEP_0                               (0x1U<<17U)
#define ETH_MACHWF3R_ESTSEL                                 (0x1U<<16U)
#define ETH_MACHWF3R_FRPES                                  (0x3U<<13U)
#define ETH_MACHWF3R_FRPES_0                                (0x1U<<13U)
#define ETH_MACHWF3R_FRPBS                                  (0x3U<<11U)
#define ETH_MACHWF3R_FRPBS_0                                (0x1U<<11U)
#define ETH_MACHWF3R_FRPSEL                                 (0x1U<<10U)
#define ETH_MACHWF3R_PDUPSEL                                (0x1U<<9U)
#define ETH_MACHWF3R_DVLAN                                  (0x1U<<5U)
#define ETH_MACHWF3R_CBTISEL                                (0x1U<<4U)
#define ETH_MACHWF3R_NRVF                                   (0x7U<<0U)
#define ETH_MACHWF3R_NRVF_0                                 (0x1U<<0U)

#define ETH_MACHWF3R_ASP_B_0X0                              (0x0U<<28U)
#define ETH_MACHWF3R_ASP_B_0X1                              (0x1U<<28U)
#define ETH_MACHWF3R_ASP_B_0X2                              (0x2U<<28U)
#define ETH_MACHWF3R_ASP_B_0X3                              (0x3U<<28U)
#define ETH_MACHWF3R_ESTWID_B_0X0                           (0x0U<<20U)
#define ETH_MACHWF3R_ESTWID_B_0X1                           (0x1U<<20U)
#define ETH_MACHWF3R_ESTWID_B_0X2                           (0x2U<<20U)
#define ETH_MACHWF3R_ESTWID_B_0X3                           (0x3U<<20U)
#define ETH_MACHWF3R_ESTDEP_B_0X0                           (0x0U<<17U)
#define ETH_MACHWF3R_ESTDEP_B_0X1                           (0x1U<<17U)
#define ETH_MACHWF3R_ESTDEP_B_0X2                           (0x2U<<17U)
#define ETH_MACHWF3R_ESTDEP_B_0X3                           (0x3U<<17U)
#define ETH_MACHWF3R_ESTDEP_B_0X4                           (0x4U<<17U)
#define ETH_MACHWF3R_ESTDEP_B_0X5                           (0x5U<<17U)
#define ETH_MACHWF3R_FRPES_B_0X0                            (0x0U<<13U)
#define ETH_MACHWF3R_FRPES_B_0X1                            (0x1U<<13U)
#define ETH_MACHWF3R_FRPES_B_0X2                            (0x2U<<13U)
#define ETH_MACHWF3R_FRPBS_B_0X0                            (0x0U<<11U)
#define ETH_MACHWF3R_FRPBS_B_0X1                            (0x1U<<11U)
#define ETH_MACHWF3R_FRPBS_B_0X2                            (0x2U<<11U)
#define ETH_MACHWF3R_NRVF_B_0X0                             (0x0U<<0U)
#define ETH_MACHWF3R_NRVF_B_0X1                             (0x1U<<0U)
#define ETH_MACHWF3R_NRVF_B_0X2                             (0x2U<<0U)
#define ETH_MACHWF3R_NRVF_B_0X3                             (0x3U<<0U)
#define ETH_MACHWF3R_NRVF_B_0X4                             (0x4U<<0U)
#define ETH_MACHWF3R_NRVF_B_0X5                             (0x5U<<0U)

// MACMDIOAR Configuration

#define ETH_MACMDIOAR_PSE                                   (0x1U<<27U)
#define ETH_MACMDIOAR_BTB                                   (0x1U<<26U)
#define ETH_MACMDIOAR_PA                                    (0x1FU<<21U)
#define ETH_MACMDIOAR_PA_0                                  (0x1U<<21U)
#define ETH_MACMDIOAR_RDA                                   (0x1FU<<16U)
#define ETH_MACMDIOAR_RDA_0                                 (0x1U<<16U)
#define ETH_MACMDIOAR_NTC                                   (0x7U<<12U)
#define ETH_MACMDIOAR_NTC_0                                 (0x1U<<12U)
#define ETH_MACMDIOAR_CR                                    (0xFU<<8U)
#define ETH_MACMDIOAR_CR_0                                  (0x1U<<8U)
#define ETH_MACMDIOAR_SKAP                                  (0x1U<<4U)
#define ETH_MACMDIOAR_GOC                                   (0x3U<<2U)
#define ETH_MACMDIOAR_GOC_0                                 (0x1U<<2U)
#define ETH_MACMDIOAR_C45E                                  (0x1U<<1U)
#define ETH_MACMDIOAR_GB                                    (0x1U<<0U)

#define ETH_MACMDIOAR_CR_B_0X0                              (0x0U<<8U)
#define ETH_MACMDIOAR_CR_B_0X1                              (0x1U<<8U)
#define ETH_MACMDIOAR_CR_B_0X2                              (0x2U<<8U)
#define ETH_MACMDIOAR_CR_B_0X3                              (0x3U<<8U)
#define ETH_MACMDIOAR_CR_B_0X4                              (0x4U<<8U)
#define ETH_MACMDIOAR_CR_B_0X5                              (0x5U<<8U)
#define ETH_MACMDIOAR_CR_B_0X6                              (0x6U<<8U)
#define ETH_MACMDIOAR_CR_B_0X7                              (0x7U<<8U)
#define ETH_MACMDIOAR_CR_B_0X8                              (0x8U<<8U)
#define ETH_MACMDIOAR_CR_B_0X9                              (0x9U<<8U)
#define ETH_MACMDIOAR_CR_B_0XA                              (0xAU<<8U)
#define ETH_MACMDIOAR_CR_B_0XB                              (0xBU<<8U)
#define ETH_MACMDIOAR_CR_B_0XC                              (0xCU<<8U)
#define ETH_MACMDIOAR_CR_B_0XD                              (0xDU<<8U)
#define ETH_MACMDIOAR_CR_B_0XE                              (0xEU<<8U)
#define ETH_MACMDIOAR_CR_B_0XF                              (0xFU<<8U)
#define ETH_MACMDIOAR_GOC_B_0X1                             (0x1U<<2U)
#define ETH_MACMDIOAR_GOC_B_0X2                             (0x2U<<2U)
#define ETH_MACMDIOAR_GOC_B_0X3                             (0x3U<<2U)

// MACMDIODR Configuration

#define ETH_MACMDIODR_RA                                    (0xFFFFU<<16U)
#define ETH_MACMDIODR_RA_0                                  (0x1U<<16U)
#define ETH_MACMDIODR_GD                                    (0xFFFFU<<0U)
#define ETH_MACMDIODR_GD_0                                  (0x1U<<0U)

// MACARPAR Configuration

#define ETH_MACARPAR_ARPPA                                  (0xFFFFFFFFU<<0U)
#define ETH_MACARPAR_ARPPA_0                                (0x1U<<0U)

// MACCSRSWCR Configuration

#define ETH_MACCSRSWCR_SEEN                                 (0x1U<<8U)
#define ETH_MACCSRSWCR_RCWE                                 (0x1U<<0U)

// MACFPECSR Configuration

#define ETH_MACFPECSR_TRSP                                  (0x1U<<19U)
#define ETH_MACFPECSR_TVER                                  (0x1U<<18U)
#define ETH_MACFPECSR_RRSP                                  (0x1U<<17U)
#define ETH_MACFPECSR_RVER                                  (0x1U<<16U)
#define ETH_MACFPECSR_SRSP                                  (0x1U<<2U)
#define ETH_MACFPECSR_SVER                                  (0x1U<<1U)
#define ETH_MACFPECSR_EFPE                                  (0x1U<<0U)

// MACPRSTIMR Configuration

#define ETH_MACPRSTIMR_MPTN                                 (0xFFFFFFFFU<<0U)
#define ETH_MACPRSTIMR_MPTN_0                               (0x1U<<0U)

// MACPRSTIMUR Configuration

#define ETH_MACPRSTIMUR_MPTU                                (0xFFFFFFFFU<<0U)
#define ETH_MACPRSTIMUR_MPTU_0                              (0x1U<<0U)

// MACA0HR Configuration

#define ETH_MACA0HR_AE                                      (0x1U<<31U)
#define ETH_MACA0HR_DCS                                     (0x1U<<16U)
#define ETH_MACA0HR_ADDRHI                                  (0xFFFFU<<0U)
#define ETH_MACA0HR_ADDRHI_0                                (0x1U<<0U)

#define ETH_MACA0HR_DCS_B_0X0                               (0x0U<<16U)
#define ETH_MACA0HR_DCS_B_0X1                               (0x1U<<16U)

// MACA0LR Configuration

#define ETH_MACA0LR_ADDRLO                                  (0xFFFFFFFFU<<0U)
#define ETH_MACA0LR_ADDRLO_0                                (0x1U<<0U)

// MACA1HR Configuration

#define ETH_MACA1HR_AE                                      (0x1U<<31U)
#define ETH_MACA1HR_SA                                      (0x1U<<30U)
#define ETH_MACA1HR_MBC                                     (0x3FU<<24U)
#define ETH_MACA1HR_MBC_0                                   (0x1U<<24U)
#define ETH_MACA1HR_DCS                                     (0x1U<<16U)
#define ETH_MACA1HR_ADDRHI                                  (0xFFFFU<<0U)
#define ETH_MACA1HR_ADDRHI_0                                (0x1U<<0U)

#define ETH_MACA1HR_SA_B_0X0                                (0x0U<<30U)
#define ETH_MACA1HR_SA_B_0X1                                (0x1U<<30U)
#define ETH_MACA1HR_DCS_B_0X0                               (0x0U<<16U)
#define ETH_MACA1HR_DCS_B_0X1                               (0x1U<<16U)

// MACA1LR Configuration

#define ETH_MACA1LR_ADDRLO                                  (0xFFFFFFFFU<<0U)
#define ETH_MACA1LR_ADDRLO_0                                (0x1U<<0U)

// MACA2HR Configuration

#define ETH_MACA2HR_AE                                      (0x1U<<31U)
#define ETH_MACA2HR_SA                                      (0x1U<<30U)
#define ETH_MACA2HR_MBC                                     (0x3FU<<24U)
#define ETH_MACA2HR_MBC_0                                   (0x1U<<24U)
#define ETH_MACA2HR_DCS                                     (0x1U<<16U)
#define ETH_MACA2HR_ADDRHI                                  (0xFFFFU<<0U)
#define ETH_MACA2HR_ADDRHI_0                                (0x1U<<0U)

#define ETH_MACA2HR_SA_B_0X0                                (0x0U<<30U)
#define ETH_MACA2HR_SA_B_0X1                                (0x1U<<30U)
#define ETH_MACA2HR_DCS_B_0X0                               (0x0U<<16U)
#define ETH_MACA2HR_DCS_B_0X1                               (0x1U<<16U)

// MACA2LR Configuration

#define ETH_MACA2LR_ADDRLO                                  (0xFFFFFFFFU<<0U)
#define ETH_MACA2LR_ADDRLO_0                                (0x1U<<0U)

// MACA3HR Configuration

#define ETH_MACA3HR_AE                                      (0x1U<<31U)
#define ETH_MACA3HR_SA                                      (0x1U<<30U)
#define ETH_MACA3HR_MBC                                     (0x3FU<<24U)
#define ETH_MACA3HR_MBC_0                                   (0x1U<<24U)
#define ETH_MACA3HR_DCS                                     (0x1U<<16U)
#define ETH_MACA3HR_ADDRHI                                  (0xFFFFU<<0U)
#define ETH_MACA3HR_ADDRHI_0                                (0x1U<<0U)

#define ETH_MACA3HR_SA_B_0X0                                (0x0U<<30U)
#define ETH_MACA3HR_SA_B_0X1                                (0x1U<<30U)
#define ETH_MACA3HR_DCS_B_0X0                               (0x0U<<16U)
#define ETH_MACA3HR_DCS_B_0X1                               (0x1U<<16U)

// MACA3LR Configuration

#define ETH_MACA3LR_ADDRLO                                  (0xFFFFFFFFU<<0U)
#define ETH_MACA3LR_ADDRLO_0                                (0x1U<<0U)

// MMC_CONTROL Configuration

#define ETH_MMC_CONTROL_UCDBC                               (0x1U<<8U)
#define ETH_MMC_CONTROL_CNTPRSTLVL                          (0x1U<<5U)
#define ETH_MMC_CONTROL_CNTPRST                             (0x1U<<4U)
#define ETH_MMC_CONTROL_CNTFREEZ                            (0x1U<<3U)
#define ETH_MMC_CONTROL_RSTONRD                             (0x1U<<2U)
#define ETH_MMC_CONTROL_CNTSTOPRO                           (0x1U<<1U)
#define ETH_MMC_CONTROL_CNTRST                              (0x1U<<0U)

// MMC_RX_INTERRUPT Configuration

#define ETH_MMC_RX_INTERRUPT_RXLPITRCIS                     (0x1U<<27U)
#define ETH_MMC_RX_INTERRUPT_RXLPIUSCIS                     (0x1U<<26U)
#define ETH_MMC_RX_INTERRUPT_RXUCGPIS                       (0x1U<<17U)
#define ETH_MMC_RX_INTERRUPT_RXALGNERPIS                    (0x1U<<6U)
#define ETH_MMC_RX_INTERRUPT_RXCRCERPIS                     (0x1U<<5U)

// MMC_TX_INTERRUPT Configuration

#define ETH_MMC_TX_INTERRUPT_TXLPITRCIS                     (0x1U<<27U)
#define ETH_MMC_TX_INTERRUPT_TXLPIUSCIS                     (0x1U<<26U)
#define ETH_MMC_TX_INTERRUPT_TXGPKTIS                       (0x1U<<21U)
#define ETH_MMC_TX_INTERRUPT_TXMCOLGPIS                     (0x1U<<15U)
#define ETH_MMC_TX_INTERRUPT_TXSCOLGPIS                     (0x1U<<14U)

// MMC_RX_INTERRUPT_MASK Configuration

#define ETH_MMC_RX_INTERRUPT_MASK_RXLPITRCIM                (0x1U<<27U)
#define ETH_MMC_RX_INTERRUPT_MASK_RXLPIUSCIM                (0x1U<<26U)
#define ETH_MMC_RX_INTERRUPT_MASK_RXUCGPIM                  (0x1U<<17U)
#define ETH_MMC_RX_INTERRUPT_MASK_RXALGNERPIM               (0x1U<<6U)
#define ETH_MMC_RX_INTERRUPT_MASK_RXCRCERPIM                (0x1U<<5U)

// MMC_TX_INTERRUPT_MASK Configuration

#define ETH_MMC_TX_INTERRUPT_MASK_TXLPITRCIM                (0x1U<<27U)
#define ETH_MMC_TX_INTERRUPT_MASK_TXLPIUSCIM                (0x1U<<26U)
#define ETH_MMC_TX_INTERRUPT_MASK_TXGPKTIM                  (0x1U<<21U)
#define ETH_MMC_TX_INTERRUPT_MASK_TXMCOLGPIM                (0x1U<<15U)
#define ETH_MMC_TX_INTERRUPT_MASK_TXSCOLGPIM                (0x1U<<14U)

// TX_SINGLE_COLLISION_GOOD_PACKETS Configuration

#define ETH_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG     (0xFFFFFFFFU<<0U)
#define ETH_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG_0   (0x1U<<0U)

// TX_MULTIPLE_COLLISION_GOOD_PACKETS Configuration

#define ETH_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG   (0xFFFFFFFFU<<0U)
#define ETH_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG_0 (0x1U<<0U)

// TX_PACKET_COUNT_GOOD Configuration

#define ETH_TX_PACKET_COUNT_GOOD_TXPKTG                     (0xFFFFFFFFU<<0U)
#define ETH_TX_PACKET_COUNT_GOOD_TXPKTG_0                   (0x1U<<0U)

// RX_CRC_ERROR_PACKETS Configuration

#define ETH_RX_CRC_ERROR_PACKETS_RXCRCERR                   (0xFFFFFFFFU<<0U)
#define ETH_RX_CRC_ERROR_PACKETS_RXCRCERR_0                 (0x1U<<0U)

// RX_ALIGNMENT_ERROR_PACKETS Configuration

#define ETH_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR            (0xFFFFFFFFU<<0U)
#define ETH_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR_0          (0x1U<<0U)

// RX_UNICAST_PACKETS_GOOD Configuration

#define ETH_RX_UNICAST_PACKETS_GOOD_RXUCASTG                (0xFFFFFFFFU<<0U)
#define ETH_RX_UNICAST_PACKETS_GOOD_RXUCASTG_0              (0x1U<<0U)

// TX_LPI_USEC_CNTR Configuration

#define ETH_TX_LPI_USEC_CNTR_TXLPIUSC                       (0xFFFFFFFFU<<0U)
#define ETH_TX_LPI_USEC_CNTR_TXLPIUSC_0                     (0x1U<<0U)

// TX_LPI_TRAN_CNTR Configuration

#define ETH_TX_LPI_TRAN_CNTR_TXLPITRC                       (0xFFFFFFFFU<<0U)
#define ETH_TX_LPI_TRAN_CNTR_TXLPITRC_0                     (0x1U<<0U)

// RX_LPI_USEC_CNTR Configuration

#define ETH_RX_LPI_USEC_CNTR_RXLPIUSC                       (0xFFFFFFFFU<<0U)
#define ETH_RX_LPI_USEC_CNTR_RXLPIUSC_0                     (0x1U<<0U)

// RX_LPI_TRAN_CNTR Configuration

#define ETH_RX_LPI_TRAN_CNTR_RXLPITRC                       (0xFFFFFFFFU<<0U)
#define ETH_RX_LPI_TRAN_CNTR_RXLPITRC_0                     (0x1U<<0U)

// MMC_FPE_TX_ISR Configuration

#define ETH_MMC_FPE_TX_ISR_HRCIS                            (0x1U<<1U)
#define ETH_MMC_FPE_TX_ISR_FCIS                             (0x1U<<0U)

// MMC_FPE_TX_IMR Configuration

#define ETH_MMC_FPE_TX_IMR_HRCIM                            (0x1U<<1U)
#define ETH_MMC_FPE_TX_IMR_FCIM                             (0x1U<<0U)

// MMC_FPE_TX_FCR Configuration

#define ETH_MMC_FPE_TX_FCR_TXFFC                            (0xFFFFFFFFU<<0U)
#define ETH_MMC_FPE_TX_FCR_TXFFC_0                          (0x1U<<0U)

// MMC_TX_HRCR Configuration

#define ETH_MMC_TX_HRCR_TXHRC                               (0xFFFFFFFFU<<0U)
#define ETH_MMC_TX_HRCR_TXHRC_0                             (0x1U<<0U)

// MMC_FPE_RX_ISR Configuration

#define ETH_MMC_FPE_RX_ISR_FCIS                             (0x1U<<3U)
#define ETH_MMC_FPE_RX_ISR_PAOCIS                           (0x1U<<2U)
#define ETH_MMC_FPE_RX_ISR_PSECIS                           (0x1U<<1U)
#define ETH_MMC_FPE_RX_ISR_PAECIS                           (0x1U<<0U)

// MMC_FPE_RX_IMR Configuration

#define ETH_MMC_FPE_RX_IMR_FCIM                             (0x1U<<3U)
#define ETH_MMC_FPE_RX_IMR_PAOCIM                           (0x1U<<2U)
#define ETH_MMC_FPE_RX_IMR_PSECIM                           (0x1U<<1U)
#define ETH_MMC_FPE_RX_IMR_PAECIM                           (0x1U<<0U)

// RX_PACKET_ASM_ERR Configuration

#define ETH_RX_PACKET_ASM_ERR_PAEC                          (0xFFFFFFFFU<<0U)
#define ETH_RX_PACKET_ASM_ERR_PAEC_0                        (0x1U<<0U)

// RX_PACKET_SMD_ERR Configuration

#define ETH_RX_PACKET_SMD_ERR_PSEC                          (0xFFFFFFFFU<<0U)
#define ETH_RX_PACKET_SMD_ERR_PSEC_0                        (0x1U<<0U)

// RX_PACKET_ASM_OKR Configuration

#define ETH_RX_PACKET_ASM_OKR_PAOC                          (0xFFFFFFFFU<<0U)
#define ETH_RX_PACKET_ASM_OKR_PAOC_0                        (0x1U<<0U)

// RX_FPE_FRAG_CR Configuration

#define ETH_RX_FPE_FRAG_CR_FFC                              (0xFFFFFFFFU<<0U)
#define ETH_RX_FPE_FRAG_CR_FFC_0                            (0x1U<<0U)

// MACL3L4C0R Configuration

#define ETH_MACL3L4C0R_DMCHEN0                              (0x1U<<28U)
#define ETH_MACL3L4C0R_DMCHN0                               (0x1U<<24U)
#define ETH_MACL3L4C0R_L4DPIM0                              (0x1U<<21U)
#define ETH_MACL3L4C0R_L4DPM0                               (0x1U<<20U)
#define ETH_MACL3L4C0R_L4SPIM0                              (0x1U<<19U)
#define ETH_MACL3L4C0R_L4SPM0                               (0x1U<<18U)
#define ETH_MACL3L4C0R_L4PEN0                               (0x1U<<16U)
#define ETH_MACL3L4C0R_L3HDBM0                              (0x1FU<<11U)
#define ETH_MACL3L4C0R_L3HDBM0_0                            (0x1U<<11U)
#define ETH_MACL3L4C0R_L3HSBM0                              (0x1FU<<6U)
#define ETH_MACL3L4C0R_L3HSBM0_0                            (0x1U<<6U)
#define ETH_MACL3L4C0R_L3DAIM0                              (0x1U<<5U)
#define ETH_MACL3L4C0R_L3DAM0                               (0x1U<<4U)
#define ETH_MACL3L4C0R_L3SAIM0                              (0x1U<<3U)
#define ETH_MACL3L4C0R_L3SAM0                               (0x1U<<2U)
#define ETH_MACL3L4C0R_L3PEN0                               (0x1U<<0U)

#define ETH_MACL3L4C0R_DMCHN0_B_0X0                         (0x0U<<24U)
#define ETH_MACL3L4C0R_DMCHN0_B_0X1                         (0x1U<<24U)
#define ETH_MACL3L4C0R_L3HDBM0_B_0X0_IPV4_PACKETS           (0x0U<<11U)
#define ETH_MACL3L4C0R_L3HDBM0_B_0X1_IPV4_PACKETS           (0x1U<<11U)
#define ETH_MACL3L4C0R_L3HSBM0_B_0X0_IPV4_PACKETS           (0x0U<<6U)
#define ETH_MACL3L4C0R_L3HSBM0_B_0X1_IPV4_PACKETS           (0x1U<<6U)

// MACL4A0R Configuration

#define ETH_MACL4A0R_L4DP0                                  (0xFFFFU<<16U)
#define ETH_MACL4A0R_L4DP0_0                                (0x1U<<16U)
#define ETH_MACL4A0R_L4SP0                                  (0xFFFFU<<0U)
#define ETH_MACL4A0R_L4SP0_0                                (0x1U<<0U)

// MACL3A00R Configuration

#define ETH_MACL3A00R_L3A00                                 (0xFFFFFFFFU<<0U)
#define ETH_MACL3A00R_L3A00_0                               (0x1U<<0U)

// MACL3A10R Configuration

#define ETH_MACL3A10R_L3A10                                 (0xFFFFFFFFU<<0U)
#define ETH_MACL3A10R_L3A10_0                               (0x1U<<0U)

// MACL3A20R Configuration

#define ETH_MACL3A20R_L3A20                                 (0xFFFFFFFFU<<0U)
#define ETH_MACL3A20R_L3A20_0                               (0x1U<<0U)

// MACL3A30R Configuration

#define ETH_MACL3A30R_L3A30                                 (0xFFFFFFFFU<<0U)
#define ETH_MACL3A30R_L3A30_0                               (0x1U<<0U)

// MACL3L4C1R Configuration

#define ETH_MACL3L4C1R_DMCHEN1                              (0x1U<<28U)
#define ETH_MACL3L4C1R_DMCHN1                               (0x1U<<24U)
#define ETH_MACL3L4C1R_L4DPIM1                              (0x1U<<21U)
#define ETH_MACL3L4C1R_L4DPM1                               (0x1U<<20U)
#define ETH_MACL3L4C1R_L4SPIM1                              (0x1U<<19U)
#define ETH_MACL3L4C1R_L4SPM1                               (0x1U<<18U)
#define ETH_MACL3L4C1R_L4PEN1                               (0x1U<<16U)
#define ETH_MACL3L4C1R_L3HDBM1                              (0x1FU<<11U)
#define ETH_MACL3L4C1R_L3HDBM1_0                            (0x1U<<11U)
#define ETH_MACL3L4C1R_L3HSBM1                              (0x1FU<<6U)
#define ETH_MACL3L4C1R_L3HSBM1_0                            (0x1U<<6U)
#define ETH_MACL3L4C1R_L3DAIM1                              (0x1U<<5U)
#define ETH_MACL3L4C1R_L3DAM1                               (0x1U<<4U)
#define ETH_MACL3L4C1R_L3SAIM1                              (0x1U<<3U)
#define ETH_MACL3L4C1R_L3SAM1                               (0x1U<<2U)
#define ETH_MACL3L4C1R_L3PEN1                               (0x1U<<0U)

#define ETH_MACL3L4C1R_L3HDBM1_B_0X0_IPV4_PACKETS           (0x0U<<11U)
#define ETH_MACL3L4C1R_L3HDBM1_B_0X1_IPV4_PACKETS           (0x1U<<11U)
#define ETH_MACL3L4C1R_L3HSBM1_B_0X0_IPV4_PACKETS           (0x0U<<6U)
#define ETH_MACL3L4C1R_L3HSBM1_B_0X1_IPV4_PACKETS           (0x1U<<6U)

// MACL4A1R Configuration

#define ETH_MACL4A1R_L4DP1                                  (0xFFFFU<<16U)
#define ETH_MACL4A1R_L4DP1_0                                (0x1U<<16U)
#define ETH_MACL4A1R_L4SP1                                  (0xFFFFU<<0U)
#define ETH_MACL4A1R_L4SP1_0                                (0x1U<<0U)

// MACL3A01R Configuration

#define ETH_MACL3A01R_L3A01                                 (0xFFFFFFFFU<<0U)
#define ETH_MACL3A01R_L3A01_0                               (0x1U<<0U)

// MACL3A11R Configuration

#define ETH_MACL3A11R_L3A11                                 (0xFFFFFFFFU<<0U)
#define ETH_MACL3A11R_L3A11_0                               (0x1U<<0U)

// MACL3A21R Configuration

#define ETH_MACL3A21R_L3A21                                 (0xFFFFFFFFU<<0U)
#define ETH_MACL3A21R_L3A21_0                               (0x1U<<0U)

// MACL3A31R Configuration

#define ETH_MACL3A31R_L3A31                                 (0xFFFFFFFFU<<0U)
#define ETH_MACL3A31R_L3A31_0                               (0x1U<<0U)

// MAC_IACR Configuration

#define ETH_MAC_IACR_MSEL                                   (0xFU<<16U)
#define ETH_MAC_IACR_MSEL_0                                 (0x1U<<16U)
#define ETH_MAC_IACR_AOFF                                   (0xFFU<<8U)
#define ETH_MAC_IACR_AOFF_0                                 (0x1U<<8U)
#define ETH_MAC_IACR_AUTO                                   (0x1U<<5U)
#define ETH_MAC_IACR_COM                                    (0x1U<<1U)
#define ETH_MAC_IACR_OB                                     (0x1U<<0U)

#define ETH_MAC_IACR_MSEL_B_0X0                             (0x0U<<16U)
#define ETH_MAC_IACR_AOFF_B_0X0                             (0x0U<<8U)
#define ETH_MAC_IACR_AOFF_B_0X1                             (0x1U<<8U)
#define ETH_MAC_IACR_AOFF_B_0X7                             (0x7U<<8U)
#define ETH_MAC_IACR_AUTO_B_0X1                             (0x1U<<5U)
#define ETH_MAC_IACR_AUTO_B_0X0                             (0x0U<<5U)
#define ETH_MAC_IACR_COM_B_0X1                              (0x1U<<1U)
#define ETH_MAC_IACR_COM_B_0X0                              (0x0U<<1U)

// MAC_TMRQR Configuration

#define ETH_MAC_TMRQR_PFEX                                  (0x1U<<20U)
#define ETH_MAC_TMRQR_TMRQ                                  (0x7U<<16U)
#define ETH_MAC_TMRQR_TMRQ_0                                (0x1U<<16U)
#define ETH_MAC_TMRQR_TYP                                   (0xFFFFU<<0U)
#define ETH_MAC_TMRQR_TYP_0                                 (0x1U<<0U)

#define ETH_MAC_TMRQR_PFEX_B_0X0                            (0x0U<<20U)
#define ETH_MAC_TMRQR_PFEX_B_0X1                            (0x1U<<20U)

// MACTSCR Configuration

#define ETH_MACTSCR_AV8021ASMEN                             (0x1U<<28U)
#define ETH_MACTSCR_TXTSSTSM                                (0x1U<<24U)
#define ETH_MACTSCR_ESTI                                    (0x1U<<20U)
#define ETH_MACTSCR_TSENMACADDR                             (0x1U<<18U)
#define ETH_MACTSCR_SNAPTYPSEL                              (0x3U<<16U)
#define ETH_MACTSCR_SNAPTYPSEL_0                            (0x1U<<16U)
#define ETH_MACTSCR_TSMSTRENA                               (0x1U<<15U)
#define ETH_MACTSCR_TSEVNTENA                               (0x1U<<14U)
#define ETH_MACTSCR_TSIPV4ENA                               (0x1U<<13U)
#define ETH_MACTSCR_TSIPV6ENA                               (0x1U<<12U)
#define ETH_MACTSCR_TSIPENA                                 (0x1U<<11U)
#define ETH_MACTSCR_TSVER2ENA                               (0x1U<<10U)
#define ETH_MACTSCR_TSCTRLSSR                               (0x1U<<9U)
#define ETH_MACTSCR_TSENALL                                 (0x1U<<8U)
#define ETH_MACTSCR_PTGE                                    (0x1U<<6U)
#define ETH_MACTSCR_TSADDREG                                (0x1U<<5U)
#define ETH_MACTSCR_TSUPDT                                  (0x1U<<3U)
#define ETH_MACTSCR_TSINIT                                  (0x1U<<2U)
#define ETH_MACTSCR_TSCFUPDT                                (0x1U<<1U)
#define ETH_MACTSCR_TSENA                                   (0x1U<<0U)

// MACSSIR Configuration

#define ETH_MACSSIR_SSINC                                   (0xFFU<<16U)
#define ETH_MACSSIR_SSINC_0                                 (0x1U<<16U)

// MACSTSR Configuration

#define ETH_MACSTSR_TSS                                     (0xFFFFFFFFU<<0U)
#define ETH_MACSTSR_TSS_0                                   (0x1U<<0U)

// MACSTNR Configuration

#define ETH_MACSTNR_TSSS                                    (0x7FFFFFFFU<<0U)
#define ETH_MACSTNR_TSSS_0                                  (0x1U<<0U)

// MACSTSUR Configuration

#define ETH_MACSTSUR_TSS                                    (0xFFFFFFFFU<<0U)
#define ETH_MACSTSUR_TSS_0                                  (0x1U<<0U)

// MACSTNUR Configuration

#define ETH_MACSTNUR_ADDSUB                                 (0x1U<<31U)
#define ETH_MACSTNUR_TSSS                                   (0x7FFFFFFFU<<0U)
#define ETH_MACSTNUR_TSSS_0                                 (0x1U<<0U)

// MACTSAR Configuration

#define ETH_MACTSAR_TSAR                                    (0xFFFFFFFFU<<0U)
#define ETH_MACTSAR_TSAR_0                                  (0x1U<<0U)

// MACTSSR Configuration

#define ETH_MACTSSR_ATSNS                                   (0x1FU<<25U)
#define ETH_MACTSSR_ATSNS_0                                 (0x1U<<25U)
#define ETH_MACTSSR_ATSSTM                                  (0x1U<<24U)
#define ETH_MACTSSR_ATSSTN                                  (0xFU<<16U)
#define ETH_MACTSSR_ATSSTN_0                                (0x1U<<16U)
#define ETH_MACTSSR_TXTSSIS                                 (0x1U<<15U)
#define ETH_MACTSSR_TSTRGTERR1                              (0x1U<<5U)
#define ETH_MACTSSR_TSTARGT1                                (0x1U<<4U)
#define ETH_MACTSSR_TSTRGTERR0                              (0x1U<<3U)
#define ETH_MACTSSR_AUXTSTRIG                               (0x1U<<2U)
#define ETH_MACTSSR_TSTARGT0                                (0x1U<<1U)
#define ETH_MACTSSR_TSSOVF                                  (0x1U<<0U)

// MACTXTSSNR Configuration

#define ETH_MACTXTSSNR_TXTSSMIS                             (0x1U<<31U)
#define ETH_MACTXTSSNR_TXTSSLO                              (0x7FFFFFFFU<<0U)
#define ETH_MACTXTSSNR_TXTSSLO_0                            (0x1U<<0U)

// MACTXTSSSR Configuration

#define ETH_MACTXTSSSR_TXTSSHI                              (0xFFFFFFFFU<<0U)
#define ETH_MACTXTSSSR_TXTSSHI_0                            (0x1U<<0U)

// MACACR Configuration

#define ETH_MACACR_ATSEN3                                   (0x1U<<7U)
#define ETH_MACACR_ATSEN2                                   (0x1U<<6U)
#define ETH_MACACR_ATSEN1                                   (0x1U<<5U)
#define ETH_MACACR_ATSEN0                                   (0x1U<<4U)
#define ETH_MACACR_ATSFC                                    (0x1U<<0U)

// MACATSNR Configuration

#define ETH_MACATSNR_AUXTSLO                                (0x7FFFFFFFU<<0U)
#define ETH_MACATSNR_AUXTSLO_0                              (0x1U<<0U)

// MACATSSR Configuration

#define ETH_MACATSSR_AUXTSHI                                (0xFFFFFFFFU<<0U)
#define ETH_MACATSSR_AUXTSHI_0                              (0x1U<<0U)

// MACTSIACR Configuration

#define ETH_MACTSIACR_OSTIAC                                (0xFFFFFFFFU<<0U)
#define ETH_MACTSIACR_OSTIAC_0                              (0x1U<<0U)

// MACTSEACR Configuration

#define ETH_MACTSEACR_OSTEAC                                (0xFFFFFFFFU<<0U)
#define ETH_MACTSEACR_OSTEAC_0                              (0x1U<<0U)

// MACTSICNR Configuration

#define ETH_MACTSICNR_TSIC                                  (0xFFFFFFFFU<<0U)
#define ETH_MACTSICNR_TSIC_0                                (0x1U<<0U)

// MACTSECNR Configuration

#define ETH_MACTSECNR_TSEC                                  (0xFFFFFFFFU<<0U)
#define ETH_MACTSECNR_TSEC_0                                (0x1U<<0U)

// MACTSILR Configuration

#define ETH_MACTSILR_ITLNS                                  (0xFFFU<<16U)
#define ETH_MACTSILR_ITLNS_0                                (0x1U<<16U)
#define ETH_MACTSILR_ITLSNS                                 (0xFFU<<8U)
#define ETH_MACTSILR_ITLSNS_0                               (0x1U<<8U)

// MACTSELR Configuration

#define ETH_MACTSELR_ETLNS                                  (0xFFFU<<16U)
#define ETH_MACTSELR_ETLNS_0                                (0x1U<<16U)
#define ETH_MACTSELR_ETLSNS                                 (0xFFU<<8U)
#define ETH_MACTSELR_ETLSNS_0                               (0x1U<<8U)

// MACPPSCR Configuration

#define ETH_MACPPSCR_TIMESEL                                (0x1U<<28U)
#define ETH_MACPPSCR_MCGREN0                                (0x1U<<7U)
#define ETH_MACPPSCR_TRGTMODSEL0                            (0x3U<<5U)
#define ETH_MACPPSCR_TRGTMODSEL0_0                          (0x1U<<5U)
#define ETH_MACPPSCR_PPSEN0                                 (0x1U<<4U)
#define ETH_MACPPSCR_PPSCTRL                                (0xFU<<0U)
#define ETH_MACPPSCR_PPSCTRL_0                              (0x1U<<0U)

#define ETH_MACPPSCR_MCGREN0_B_0X0                          (0x0U<<7U)
#define ETH_MACPPSCR_MCGREN0_B_0X1                          (0x1U<<7U)
#define ETH_MACPPSCR_TRGTMODSEL0_B_0X0                      (0x0U<<5U)
#define ETH_MACPPSCR_TRGTMODSEL0_B_0X1                      (0x1U<<5U)
#define ETH_MACPPSCR_TRGTMODSEL0_B_0X2                      (0x2U<<5U)
#define ETH_MACPPSCR_TRGTMODSEL0_B_0X3                      (0x3U<<5U)
#define ETH_MACPPSCR_PPSCTRL_B_0X1                          (0x1U<<0U)
#define ETH_MACPPSCR_PPSCTRL_B_0X2                          (0x2U<<0U)
#define ETH_MACPPSCR_PPSCTRL_B_0X3                          (0x3U<<0U)
#define ETH_MACPPSCR_PPSCTRL_B_0X4                          (0x4U<<0U)
#define ETH_MACPPSCR_PPSCTRL_B_0XF                          (0xFU<<0U)

// MACPPSCR_ALTERNATE Configuration

#define ETH_MACPPSCR_ALTERNATE_TIMESEL                      (0x1U<<28U)
#define ETH_MACPPSCR_ALTERNATE_MCGREN1                      (0x1U<<15U)
#define ETH_MACPPSCR_ALTERNATE_TRGTMODSEL1                  (0x3U<<13U)
#define ETH_MACPPSCR_ALTERNATE_TRGTMODSEL1_0                (0x1U<<13U)
#define ETH_MACPPSCR_ALTERNATE_PPSCMD1                      (0xFU<<8U)
#define ETH_MACPPSCR_ALTERNATE_PPSCMD1_0                    (0x1U<<8U)
#define ETH_MACPPSCR_ALTERNATE_MCGREN0                      (0x1U<<7U)
#define ETH_MACPPSCR_ALTERNATE_TRGTMODSEL0                  (0x3U<<5U)
#define ETH_MACPPSCR_ALTERNATE_TRGTMODSEL0_0                (0x1U<<5U)
#define ETH_MACPPSCR_ALTERNATE_PPSEN0                       (0x1U<<4U)
#define ETH_MACPPSCR_ALTERNATE_PPSCMD                       (0xFU<<0U)
#define ETH_MACPPSCR_ALTERNATE_PPSCMD_0                     (0x1U<<0U)

#define ETH_MACPPSCR_ALTERNATE_MCGREN1_B_0X0                (0x0U<<15U)
#define ETH_MACPPSCR_ALTERNATE_MCGREN1_B_0X1                (0x1U<<15U)
#define ETH_MACPPSCR_ALTERNATE_TRGTMODSEL1_B_0X0            (0x0U<<13U)
#define ETH_MACPPSCR_ALTERNATE_TRGTMODSEL1_B_0X1            (0x1U<<13U)
#define ETH_MACPPSCR_ALTERNATE_TRGTMODSEL1_B_0X2            (0x2U<<13U)
#define ETH_MACPPSCR_ALTERNATE_TRGTMODSEL1_B_0X3            (0x3U<<13U)
#define ETH_MACPPSCR_ALTERNATE_MCGREN0_B_0X0                (0x0U<<7U)
#define ETH_MACPPSCR_ALTERNATE_MCGREN0_B_0X1                (0x1U<<7U)
#define ETH_MACPPSCR_ALTERNATE_TRGTMODSEL0_B_0X0            (0x0U<<5U)
#define ETH_MACPPSCR_ALTERNATE_TRGTMODSEL0_B_0X1            (0x1U<<5U)
#define ETH_MACPPSCR_ALTERNATE_TRGTMODSEL0_B_0X2            (0x2U<<5U)
#define ETH_MACPPSCR_ALTERNATE_TRGTMODSEL0_B_0X3            (0x3U<<5U)
#define ETH_MACPPSCR_ALTERNATE_PPSCMD_B_0X0                 (0x0U<<0U)
#define ETH_MACPPSCR_ALTERNATE_PPSCMD_B_0X1                 (0x1U<<0U)
#define ETH_MACPPSCR_ALTERNATE_PPSCMD_B_0X2                 (0x2U<<0U)
#define ETH_MACPPSCR_ALTERNATE_PPSCMD_B_0X3                 (0x3U<<0U)
#define ETH_MACPPSCR_ALTERNATE_PPSCMD_B_0X4                 (0x4U<<0U)
#define ETH_MACPPSCR_ALTERNATE_PPSCMD_B_0X5                 (0x5U<<0U)
#define ETH_MACPPSCR_ALTERNATE_PPSCMD_B_0X6                 (0x6U<<0U)

// MACPPSTTS0R Configuration

#define ETH_MACPPSTTS0R_TSTRH0                              (0xFFFFFFFFU<<0U)
#define ETH_MACPPSTTS0R_TSTRH0_0                            (0x1U<<0U)

// MACPPSTTN0R Configuration

#define ETH_MACPPSTTN0R_TRGTBUSY0                           (0x1U<<31U)
#define ETH_MACPPSTTN0R_TTSL0                               (0x7FFFFFFFU<<0U)
#define ETH_MACPPSTTN0R_TTSL0_0                             (0x1U<<0U)

// MACPPSI0R Configuration

#define ETH_MACPPSI0R_PPSINT0                               (0xFFFFFFFFU<<0U)
#define ETH_MACPPSI0R_PPSINT0_0                             (0x1U<<0U)

// MACPPSW0R Configuration

#define ETH_MACPPSW0R_PPSWIDTH0                             (0xFFFFFFFFU<<0U)
#define ETH_MACPPSW0R_PPSWIDTH0_0                           (0x1U<<0U)

// MACPPSTTS1R Configuration

#define ETH_MACPPSTTS1R_TSTRH0                              (0xFFFFFFFFU<<0U)
#define ETH_MACPPSTTS1R_TSTRH0_0                            (0x1U<<0U)

// MACPPSTTN1R Configuration

#define ETH_MACPPSTTN1R_TRGTBUSY0                           (0x1U<<31U)
#define ETH_MACPPSTTN1R_TTSL0                               (0x7FFFFFFFU<<0U)
#define ETH_MACPPSTTN1R_TTSL0_0                             (0x1U<<0U)

// MACPPSI1R Configuration

#define ETH_MACPPSI1R_PPSINT0                               (0xFFFFFFFFU<<0U)
#define ETH_MACPPSI1R_PPSINT0_0                             (0x1U<<0U)

// MACPPSW1R Configuration

#define ETH_MACPPSW1R_PPSWIDTH0                             (0xFFFFFFFFU<<0U)
#define ETH_MACPPSW1R_PPSWIDTH0_0                           (0x1U<<0U)

// MACPOCR Configuration

#define ETH_MACPOCR_DN                                      (0xFFU<<8U)
#define ETH_MACPOCR_DN_0                                    (0x1U<<8U)
#define ETH_MACPOCR_PDRDIS                                  (0x1U<<7U)
#define ETH_MACPOCR_DRRDIS                                  (0x1U<<6U)
#define ETH_MACPOCR_APDREQTRIG                              (0x1U<<5U)
#define ETH_MACPOCR_ASYNCTRIG                               (0x1U<<4U)
#define ETH_MACPOCR_APDREQEN                                (0x1U<<2U)
#define ETH_MACPOCR_ASYNCEN                                 (0x1U<<1U)
#define ETH_MACPOCR_PTOEN                                   (0x1U<<0U)

// MACSPI0R Configuration

#define ETH_MACSPI0R_SPI0                                   (0xFFFFFFFFU<<0U)
#define ETH_MACSPI0R_SPI0_0                                 (0x1U<<0U)

// MACSPI1R Configuration

#define ETH_MACSPI1R_SPI1                                   (0xFFFFFFFFU<<0U)
#define ETH_MACSPI1R_SPI1_0                                 (0x1U<<0U)

// MACSPI2R Configuration

#define ETH_MACSPI2R_SPI2                                   (0xFFFFU<<0U)
#define ETH_MACSPI2R_SPI2_0                                 (0x1U<<0U)

// MACLMIR Configuration

#define ETH_MACLMIR_LMPDRI                                  (0xFFU<<24U)
#define ETH_MACLMIR_LMPDRI_0                                (0x1U<<24U)
#define ETH_MACLMIR_DRSYNCR                                 (0x7U<<8U)
#define ETH_MACLMIR_DRSYNCR_0                               (0x1U<<8U)
#define ETH_MACLMIR_LSI                                     (0xFFU<<0U)
#define ETH_MACLMIR_LSI_0                                   (0x1U<<0U)

#define ETH_MACLMIR_DRSYNCR_B_0X0                           (0x0U<<8U)
#define ETH_MACLMIR_DRSYNCR_B_0X1                           (0x1U<<8U)

// MTLOMR Configuration

#define ETH_MTLOMR_CNTCLR                                   (0x1U<<9U)
#define ETH_MTLOMR_CNTPRST                                  (0x1U<<8U)
#define ETH_MTLOMR_SCHALG                                   (0x3U<<5U)
#define ETH_MTLOMR_SCHALG_0                                 (0x1U<<5U)
#define ETH_MTLOMR_RAA                                      (0x1U<<2U)
#define ETH_MTLOMR_DTXSTS                                   (0x1U<<1U)

#define ETH_MTLOMR_SCHALG_B_0X0                             (0x0U<<5U)
#define ETH_MTLOMR_SCHALG_B_0X3                             (0x3U<<5U)
#define ETH_MTLOMR_RAA_B_0X0                                (0x0U<<2U)
#define ETH_MTLOMR_RAA_B_0X1                                (0x1U<<2U)

// MTLISR Configuration

#define ETH_MTLISR_ESTIS                                    (0x1U<<18U)
#define ETH_MTLISR_Q1IS                                     (0x1U<<1U)
#define ETH_MTLISR_Q0IS                                     (0x1U<<0U)

// MTLRXQDMAMR Configuration

#define ETH_MTLRXQDMAMR_Q1DDMACH                            (0x1U<<12U)
#define ETH_MTLRXQDMAMR_Q1MDMACH                            (0x1U<<8U)
#define ETH_MTLRXQDMAMR_Q0DDMACH                            (0x1U<<4U)
#define ETH_MTLRXQDMAMR_Q0MDMACH                            (0x1U<<0U)

#define ETH_MTLRXQDMAMR_Q1MDMACH_B_0X0                      (0x0U<<8U)
#define ETH_MTLRXQDMAMR_Q1MDMACH_B_0X1                      (0x1U<<8U)
#define ETH_MTLRXQDMAMR_Q0MDMACH_B_0X0                      (0x0U<<0U)
#define ETH_MTLRXQDMAMR_Q0MDMACH_B_0X1                      (0x1U<<0U)

// MTLTBSCR Configuration

#define ETH_MTLTBSCR_LEOS                                   (0xFFFFFFU<<8U)
#define ETH_MTLTBSCR_LEOS_0                                 (0x1U<<8U)
#define ETH_MTLTBSCR_LEGOS                                  (0x7U<<4U)
#define ETH_MTLTBSCR_LEGOS_0                                (0x1U<<4U)
#define ETH_MTLTBSCR_LEOV                                   (0x1U<<1U)
#define ETH_MTLTBSCR_ESTM                                   (0x1U<<0U)

#define ETH_MTLTBSCR_LEOV_B_0X0                             (0x0U<<1U)
#define ETH_MTLTBSCR_LEOV_B_0X1                             (0x1U<<1U)
#define ETH_MTLTBSCR_ESTM_B_0X0                             (0x0U<<0U)
#define ETH_MTLTBSCR_ESTM_B_0X1                             (0x1U<<0U)

// MTLESTCR Configuration

#define ETH_MTLESTCR_PTOV                                   (0xFFU<<24U)
#define ETH_MTLESTCR_PTOV_0                                 (0x1U<<24U)
#define ETH_MTLESTCR_CTOV                                   (0xFFFU<<12U)
#define ETH_MTLESTCR_CTOV_0                                 (0x1U<<12U)
#define ETH_MTLESTCR_TILS                                   (0x7U<<8U)
#define ETH_MTLESTCR_TILS_0                                 (0x1U<<8U)
#define ETH_MTLESTCR_LCSE                                   (0x3U<<6U)
#define ETH_MTLESTCR_LCSE_0                                 (0x1U<<6U)
#define ETH_MTLESTCR_DFBS                                   (0x1U<<5U)
#define ETH_MTLESTCR_DDBF                                   (0x1U<<4U)
#define ETH_MTLESTCR_SSWL                                   (0x1U<<1U)
#define ETH_MTLESTCR_EEST                                   (0x1U<<0U)

#define ETH_MTLESTCR_TILS_B_0X0                             (0x0U<<8U)
#define ETH_MTLESTCR_TILS_B_0X1                             (0x1U<<8U)
#define ETH_MTLESTCR_TILS_B_0X2                             (0x2U<<8U)
#define ETH_MTLESTCR_TILS_B_0X4                             (0x4U<<8U)
#define ETH_MTLESTCR_LCSE_B_0X0                             (0x0U<<6U)
#define ETH_MTLESTCR_LCSE_B_0X1                             (0x1U<<6U)
#define ETH_MTLESTCR_LCSE_B_0X2                             (0x2U<<6U)
#define ETH_MTLESTCR_LCSE_B_0X3                             (0x3U<<6U)
#define ETH_MTLESTCR_DFBS_B_0X0                             (0x0U<<5U)
#define ETH_MTLESTCR_DFBS_B_0X1                             (0x1U<<5U)
#define ETH_MTLESTCR_DDBF_B_0X0                             (0x0U<<4U)
#define ETH_MTLESTCR_DDBF_B_0X1                             (0x1U<<4U)
#define ETH_MTLESTCR_EEST_B_0X0                             (0x0U<<0U)
#define ETH_MTLESTCR_EEST_B_0X1                             (0x1U<<0U)

// MTLESTECR Configuration

#define ETH_MTLESTECR_OVHD                                  (0x3FU<<0U)
#define ETH_MTLESTECR_OVHD_0                                (0x1U<<0U)

// MTLESTSR Configuration

#define ETH_MTLESTSR_CGSN                                   (0xFU<<16U)
#define ETH_MTLESTSR_CGSN_0                                 (0x1U<<16U)
#define ETH_MTLESTSR_BTRL                                   (0xFFU<<8U)
#define ETH_MTLESTSR_BTRL_0                                 (0x1U<<8U)
#define ETH_MTLESTSR_SWOL                                   (0x1U<<7U)
#define ETH_MTLESTSR_CGCE                                   (0x1U<<4U)
#define ETH_MTLESTSR_HLBS                                   (0x1U<<3U)
#define ETH_MTLESTSR_HLBF                                   (0x1U<<2U)
#define ETH_MTLESTSR_BTRE                                   (0x1U<<1U)
#define ETH_MTLESTSR_SWLC                                   (0x1U<<0U)

#define ETH_MTLESTSR_SWOL_B_0X0                             (0x0U<<7U)
#define ETH_MTLESTSR_SWOL_B_0X1                             (0x1U<<7U)
#define ETH_MTLESTSR_CGCE_B_0X0                             (0x0U<<4U)
#define ETH_MTLESTSR_CGCE_B_0X1                             (0x1U<<4U)
#define ETH_MTLESTSR_HLBS_B_0X0                             (0x0U<<3U)
#define ETH_MTLESTSR_HLBS_B_0X1                             (0x1U<<3U)
#define ETH_MTLESTSR_BTRE_B_0X0                             (0x0U<<1U)
#define ETH_MTLESTSR_BTRE_B_0X1                             (0x1U<<1U)
#define ETH_MTLESTSR_SWLC_B_0X0                             (0x0U<<0U)
#define ETH_MTLESTSR_SWLC_B_0X1                             (0x1U<<0U)

// MTLESTSCHER Configuration

#define ETH_MTLESTSCHER_SEQN                                (0x3U<<0U)
#define ETH_MTLESTSCHER_SEQN_0                              (0x1U<<0U)

// MTLESTFSER Configuration

#define ETH_MTLESTFSER_FEQN                                 (0x3U<<0U)
#define ETH_MTLESTFSER_FEQN_0                               (0x1U<<0U)

// MTLESTFSCR Configuration

#define ETH_MTLESTFSCR_HBFQ                                 (0x1U<<16U)
#define ETH_MTLESTFSCR_HBFS                                 (0x7FFFU<<0U)
#define ETH_MTLESTFSCR_HBFS_0                               (0x1U<<0U)

// MTLESTIER Configuration

#define ETH_MTLESTIER_CGCE                                  (0x1U<<4U)
#define ETH_MTLESTIER_IEHS                                  (0x1U<<3U)
#define ETH_MTLESTIER_IEHF                                  (0x1U<<2U)
#define ETH_MTLESTIER_IEBE                                  (0x1U<<1U)
#define ETH_MTLESTIER_IECC                                  (0x1U<<0U)

// MTLESTGCLCR Configuration

#define ETH_MTLESTGCLCR_ADDR                                (0x3FU<<8U)
#define ETH_MTLESTGCLCR_ADDR_0                              (0x1U<<8U)
#define ETH_MTLESTGCLCR_DBGB                                (0x1U<<5U)
#define ETH_MTLESTGCLCR_DBGM                                (0x1U<<4U)
#define ETH_MTLESTGCLCR_GCRR                                (0x1U<<2U)
#define ETH_MTLESTGCLCR_R1W0                                (0x1U<<1U)
#define ETH_MTLESTGCLCR_SRWO                                (0x1U<<0U)

#define ETH_MTLESTGCLCR_ADDR_B_0X0_GCRR__EQUAL_1            (0x0U<<8U)
#define ETH_MTLESTGCLCR_ADDR_B_0X1_GCRR__EQUAL_1            (0x1U<<8U)
#define ETH_MTLESTGCLCR_ADDR_B_0X2_GCRR__EQUAL_1            (0x2U<<8U)
#define ETH_MTLESTGCLCR_ADDR_B_0X3_GCRR__EQUAL_1            (0x3U<<8U)
#define ETH_MTLESTGCLCR_ADDR_B_0X4_GCRR__EQUAL_1            (0x4U<<8U)
#define ETH_MTLESTGCLCR_ADDR_B_0X5_GCRR__EQUAL_1            (0x5U<<8U)
#define ETH_MTLESTGCLCR_DBGB_B_0X0                          (0x0U<<5U)
#define ETH_MTLESTGCLCR_DBGB_B_0X1                          (0x1U<<5U)
#define ETH_MTLESTGCLCR_R1W0_B_0X1                          (0x1U<<1U)
#define ETH_MTLESTGCLCR_R1W0_B_0X0                          (0x0U<<1U)
#define ETH_MTLESTGCLCR_SRWO_B_0X1                          (0x1U<<0U)

// MTLESTGCLDR Configuration

#define ETH_MTLESTGCLDR_GCD                                 (0xFFFFFFFFU<<0U)
#define ETH_MTLESTGCLDR_GCD_0                               (0x1U<<0U)

// MTLFPECSR Configuration

#define ETH_MTLFPECSR_HRS                                   (0x1U<<28U)
#define ETH_MTLFPECSR_PEC                                   (0x3U<<8U)
#define ETH_MTLFPECSR_PEC_0                                 (0x1U<<8U)
#define ETH_MTLFPECSR_AFSZ                                  (0x3U<<0U)
#define ETH_MTLFPECSR_AFSZ_0                                (0x1U<<0U)

#define ETH_MTLFPECSR_HRS_B_0X1                             (0x1U<<28U)
#define ETH_MTLFPECSR_HRS_B_0X0                             (0x0U<<28U)

// MTLFPEAR Configuration

#define ETH_MTLFPEAR_RADV                                   (0xFFFFU<<16U)
#define ETH_MTLFPEAR_RADV_0                                 (0x1U<<16U)
#define ETH_MTLFPEAR_HADV                                   (0xFFFFU<<0U)
#define ETH_MTLFPEAR_HADV_0                                 (0x1U<<0U)

// MTLTXQ0OMR Configuration

#define ETH_MTLTXQ0OMR_TQS                                  (0xFU<<16U)
#define ETH_MTLTXQ0OMR_TQS_0                                (0x1U<<16U)
#define ETH_MTLTXQ0OMR_TTC                                  (0x7U<<4U)
#define ETH_MTLTXQ0OMR_TTC_0                                (0x1U<<4U)
#define ETH_MTLTXQ0OMR_TXQEN                                (0x3U<<2U)
#define ETH_MTLTXQ0OMR_TXQEN_0                              (0x1U<<2U)
#define ETH_MTLTXQ0OMR_TSF                                  (0x1U<<1U)
#define ETH_MTLTXQ0OMR_FTQ                                  (0x1U<<0U)

#define ETH_MTLTXQ0OMR_TTC_B_0X0                            (0x0U<<4U)
#define ETH_MTLTXQ0OMR_TTC_B_0X1                            (0x1U<<4U)
#define ETH_MTLTXQ0OMR_TTC_B_0X2                            (0x2U<<4U)
#define ETH_MTLTXQ0OMR_TTC_B_0X3                            (0x3U<<4U)
#define ETH_MTLTXQ0OMR_TTC_B_0X4                            (0x4U<<4U)
#define ETH_MTLTXQ0OMR_TTC_B_0X5                            (0x5U<<4U)
#define ETH_MTLTXQ0OMR_TTC_B_0X6                            (0x6U<<4U)
#define ETH_MTLTXQ0OMR_TTC_B_0X7                            (0x7U<<4U)
#define ETH_MTLTXQ0OMR_TXQEN_B_0X0                          (0x0U<<2U)
#define ETH_MTLTXQ0OMR_TXQEN_B_0X1                          (0x1U<<2U)
#define ETH_MTLTXQ0OMR_TXQEN_B_0X2                          (0x2U<<2U)

// MTLTXQ0UR Configuration

#define ETH_MTLTXQ0UR_UFCNTOVF                              (0x1U<<11U)
#define ETH_MTLTXQ0UR_UFFRMCNT                              (0x7FFU<<0U)
#define ETH_MTLTXQ0UR_UFFRMCNT_0                            (0x1U<<0U)

// MTLTXQ0DR Configuration

#define ETH_MTLTXQ0DR_STXSTSF                               (0x7U<<20U)
#define ETH_MTLTXQ0DR_STXSTSF_0                             (0x1U<<20U)
#define ETH_MTLTXQ0DR_PTXQ                                  (0x7U<<16U)
#define ETH_MTLTXQ0DR_PTXQ_0                                (0x1U<<16U)
#define ETH_MTLTXQ0DR_TXSTSFSTS                             (0x1U<<5U)
#define ETH_MTLTXQ0DR_TXQSTS                                (0x1U<<4U)
#define ETH_MTLTXQ0DR_TWCSTS                                (0x1U<<3U)
#define ETH_MTLTXQ0DR_TRCSTS                                (0x3U<<1U)
#define ETH_MTLTXQ0DR_TRCSTS_0                              (0x1U<<1U)
#define ETH_MTLTXQ0DR_TXQPAUSED                             (0x1U<<0U)

#define ETH_MTLTXQ0DR_TRCSTS_B_0X0                          (0x0U<<1U)
#define ETH_MTLTXQ0DR_TRCSTS_B_0X1                          (0x1U<<1U)
#define ETH_MTLTXQ0DR_TRCSTS_B_0X2                          (0x2U<<1U)
#define ETH_MTLTXQ0DR_TRCSTS_B_0X3                          (0x3U<<1U)

// MTLTXQ0ESR Configuration

#define ETH_MTLTXQ0ESR_ABS                                  (0xFFFFFFU<<0U)
#define ETH_MTLTXQ0ESR_ABS_0                                (0x1U<<0U)

// MTLTXQ0QWR Configuration

#define ETH_MTLTXQ0QWR_ISCQW                                (0x7FU<<0U)
#define ETH_MTLTXQ0QWR_ISCQW_0                              (0x1U<<0U)

// MTLQ0ICSR Configuration

#define ETH_MTLQ0ICSR_RXOIE                                 (0x1U<<24U)
#define ETH_MTLQ0ICSR_RXOVFIS                               (0x1U<<16U)
#define ETH_MTLQ0ICSR_ABPSIE                                (0x1U<<9U)
#define ETH_MTLQ0ICSR_TXUIE                                 (0x1U<<8U)
#define ETH_MTLQ0ICSR_ABPSIS                                (0x1U<<1U)
#define ETH_MTLQ0ICSR_TXUNFIS                               (0x1U<<0U)

// MTLRXQ0OMR Configuration

#define ETH_MTLRXQ0OMR_RQS                                  (0xFU<<20U)
#define ETH_MTLRXQ0OMR_RQS_0                                (0x1U<<20U)
#define ETH_MTLRXQ0OMR_RFD                                  (0x7U<<14U)
#define ETH_MTLRXQ0OMR_RFD_0                                (0x1U<<14U)
#define ETH_MTLRXQ0OMR_RFA                                  (0x7U<<8U)
#define ETH_MTLRXQ0OMR_RFA_0                                (0x1U<<8U)
#define ETH_MTLRXQ0OMR_EHFC                                 (0x1U<<7U)
#define ETH_MTLRXQ0OMR_DIS_TCP_EF                           (0x1U<<6U)
#define ETH_MTLRXQ0OMR_RSF                                  (0x1U<<5U)
#define ETH_MTLRXQ0OMR_FEP                                  (0x1U<<4U)
#define ETH_MTLRXQ0OMR_FUP                                  (0x1U<<3U)
#define ETH_MTLRXQ0OMR_RTC                                  (0x3U<<0U)
#define ETH_MTLRXQ0OMR_RTC_0                                (0x1U<<0U)

#define ETH_MTLRXQ0OMR_RFD_B_0X0                            (0x0U<<14U)
#define ETH_MTLRXQ0OMR_RFD_B_0X1                            (0x1U<<14U)
#define ETH_MTLRXQ0OMR_RTC_B_0X0                            (0x0U<<0U)
#define ETH_MTLRXQ0OMR_RTC_B_0X1                            (0x1U<<0U)
#define ETH_MTLRXQ0OMR_RTC_B_0X2                            (0x2U<<0U)
#define ETH_MTLRXQ0OMR_RTC_B_0X3                            (0x3U<<0U)

// MTLRXQ0MPOCR Configuration

#define ETH_MTLRXQ0MPOCR_MISCNTOVF                          (0x1U<<27U)
#define ETH_MTLRXQ0MPOCR_MISPKTCNT                          (0x7FFU<<16U)
#define ETH_MTLRXQ0MPOCR_MISPKTCNT_0                        (0x1U<<16U)
#define ETH_MTLRXQ0MPOCR_OVFCNTOVF                          (0x1U<<11U)
#define ETH_MTLRXQ0MPOCR_OVFPKTCNT                          (0x7FFU<<0U)
#define ETH_MTLRXQ0MPOCR_OVFPKTCNT_0                        (0x1U<<0U)

// MTLRXQ0DR Configuration

#define ETH_MTLRXQ0DR_PRXQ                                  (0x3FFFU<<16U)
#define ETH_MTLRXQ0DR_PRXQ_0                                (0x1U<<16U)
#define ETH_MTLRXQ0DR_RXQSTS                                (0x3U<<4U)
#define ETH_MTLRXQ0DR_RXQSTS_0                              (0x1U<<4U)
#define ETH_MTLRXQ0DR_RRCSTS                                (0x3U<<1U)
#define ETH_MTLRXQ0DR_RRCSTS_0                              (0x1U<<1U)
#define ETH_MTLRXQ0DR_RWCSTS                                (0x1U<<0U)

#define ETH_MTLRXQ0DR_RXQSTS_B_0X0                          (0x0U<<4U)
#define ETH_MTLRXQ0DR_RXQSTS_B_0X1                          (0x1U<<4U)
#define ETH_MTLRXQ0DR_RXQSTS_B_0X2                          (0x2U<<4U)
#define ETH_MTLRXQ0DR_RXQSTS_B_0X3                          (0x3U<<4U)
#define ETH_MTLRXQ0DR_RRCSTS_B_0X0                          (0x0U<<1U)
#define ETH_MTLRXQ0DR_RRCSTS_B_0X1                          (0x1U<<1U)
#define ETH_MTLRXQ0DR_RRCSTS_B_0X2                          (0x2U<<1U)
#define ETH_MTLRXQ0DR_RRCSTS_B_0X3                          (0x3U<<1U)

// MTLRXQ0CR Configuration

#define ETH_MTLRXQ0CR_RXQ_FRM_ARBIT                         (0x1U<<3U)
#define ETH_MTLRXQ0CR_RXQ_WEGT                              (0x7U<<0U)
#define ETH_MTLRXQ0CR_RXQ_WEGT_0                            (0x1U<<0U)

// MTLTXQ1OMR Configuration

#define ETH_MTLTXQ1OMR_TQS                                  (0xFU<<16U)
#define ETH_MTLTXQ1OMR_TQS_0                                (0x1U<<16U)
#define ETH_MTLTXQ1OMR_TTC                                  (0x7U<<4U)
#define ETH_MTLTXQ1OMR_TTC_0                                (0x1U<<4U)
#define ETH_MTLTXQ1OMR_TXQEN                                (0x3U<<2U)
#define ETH_MTLTXQ1OMR_TXQEN_0                              (0x1U<<2U)
#define ETH_MTLTXQ1OMR_TSF                                  (0x1U<<1U)
#define ETH_MTLTXQ1OMR_FTQ                                  (0x1U<<0U)

#define ETH_MTLTXQ1OMR_TTC_B_0X0                            (0x0U<<4U)
#define ETH_MTLTXQ1OMR_TTC_B_0X1                            (0x1U<<4U)
#define ETH_MTLTXQ1OMR_TTC_B_0X2                            (0x2U<<4U)
#define ETH_MTLTXQ1OMR_TTC_B_0X3                            (0x3U<<4U)
#define ETH_MTLTXQ1OMR_TTC_B_0X4                            (0x4U<<4U)
#define ETH_MTLTXQ1OMR_TTC_B_0X5                            (0x5U<<4U)
#define ETH_MTLTXQ1OMR_TTC_B_0X6                            (0x6U<<4U)
#define ETH_MTLTXQ1OMR_TTC_B_0X7                            (0x7U<<4U)
#define ETH_MTLTXQ1OMR_TXQEN_B_0X0                          (0x0U<<2U)
#define ETH_MTLTXQ1OMR_TXQEN_B_0X1                          (0x1U<<2U)
#define ETH_MTLTXQ1OMR_TXQEN_B_0X2                          (0x2U<<2U)

// MTLTXQ1UR Configuration

#define ETH_MTLTXQ1UR_UFCNTOVF                              (0x1U<<11U)
#define ETH_MTLTXQ1UR_UFFRMCNT                              (0x7FFU<<0U)
#define ETH_MTLTXQ1UR_UFFRMCNT_0                            (0x1U<<0U)

// MTLTXQ1DR Configuration

#define ETH_MTLTXQ1DR_STXSTSF                               (0x7U<<20U)
#define ETH_MTLTXQ1DR_STXSTSF_0                             (0x1U<<20U)
#define ETH_MTLTXQ1DR_PTXQ                                  (0x7U<<16U)
#define ETH_MTLTXQ1DR_PTXQ_0                                (0x1U<<16U)
#define ETH_MTLTXQ1DR_TXSTSFSTS                             (0x1U<<5U)
#define ETH_MTLTXQ1DR_TXQSTS                                (0x1U<<4U)
#define ETH_MTLTXQ1DR_TWCSTS                                (0x1U<<3U)
#define ETH_MTLTXQ1DR_TRCSTS                                (0x3U<<1U)
#define ETH_MTLTXQ1DR_TRCSTS_0                              (0x1U<<1U)
#define ETH_MTLTXQ1DR_TXQPAUSED                             (0x1U<<0U)

#define ETH_MTLTXQ1DR_TRCSTS_B_0X0                          (0x0U<<1U)
#define ETH_MTLTXQ1DR_TRCSTS_B_0X1                          (0x1U<<1U)
#define ETH_MTLTXQ1DR_TRCSTS_B_0X2                          (0x2U<<1U)
#define ETH_MTLTXQ1DR_TRCSTS_B_0X3                          (0x3U<<1U)

// MTLTXQ1ECR Configuration

#define ETH_MTLTXQ1ECR_SLC                                  (0x7U<<4U)
#define ETH_MTLTXQ1ECR_SLC_0                                (0x1U<<4U)
#define ETH_MTLTXQ1ECR_CC                                   (0x1U<<3U)
#define ETH_MTLTXQ1ECR_AVALG                                (0x1U<<2U)

#define ETH_MTLTXQ1ECR_SLC_B_0X0                            (0x0U<<4U)
#define ETH_MTLTXQ1ECR_SLC_B_0X1                            (0x1U<<4U)
#define ETH_MTLTXQ1ECR_SLC_B_0X2                            (0x2U<<4U)
#define ETH_MTLTXQ1ECR_SLC_B_0X3                            (0x3U<<4U)
#define ETH_MTLTXQ1ECR_SLC_B_0X4                            (0x4U<<4U)

// MTLTXQ1ESR Configuration

#define ETH_MTLTXQ1ESR_ABS                                  (0xFFFFFFU<<0U)
#define ETH_MTLTXQ1ESR_ABS_0                                (0x1U<<0U)

// MTLTXQ1QWR Configuration

#define ETH_MTLTXQ1QWR_ISCQW                                (0x3FFFU<<0U)
#define ETH_MTLTXQ1QWR_ISCQW_0                              (0x1U<<0U)

// MTLTXQ1SSCR Configuration

#define ETH_MTLTXQ1SSCR_SSC                                 (0x3FFFU<<0U)
#define ETH_MTLTXQ1SSCR_SSC_0                               (0x1U<<0U)

// MTLTXQ1HCR Configuration

#define ETH_MTLTXQ1HCR_HC                                   (0x1FFFFFFFU<<0U)
#define ETH_MTLTXQ1HCR_HC_0                                 (0x1U<<0U)

// MTLTXQ1LCR Configuration

#define ETH_MTLTXQ1LCR_LC                                   (0x1FFFFFFFU<<0U)
#define ETH_MTLTXQ1LCR_LC_0                                 (0x1U<<0U)

// MTLQ1ICSR Configuration

#define ETH_MTLQ1ICSR_RXOIE                                 (0x1U<<24U)
#define ETH_MTLQ1ICSR_RXOVFIS                               (0x1U<<16U)
#define ETH_MTLQ1ICSR_ABPSIE                                (0x1U<<9U)
#define ETH_MTLQ1ICSR_TXUIE                                 (0x1U<<8U)
#define ETH_MTLQ1ICSR_ABPSIS                                (0x1U<<1U)
#define ETH_MTLQ1ICSR_TXUNFIS                               (0x1U<<0U)

// MTLRXQ1OMR Configuration

#define ETH_MTLRXQ1OMR_RQS                                  (0xFU<<20U)
#define ETH_MTLRXQ1OMR_RQS_0                                (0x1U<<20U)
#define ETH_MTLRXQ1OMR_RFD                                  (0x7U<<14U)
#define ETH_MTLRXQ1OMR_RFD_0                                (0x1U<<14U)
#define ETH_MTLRXQ1OMR_RFA                                  (0x7U<<8U)
#define ETH_MTLRXQ1OMR_RFA_0                                (0x1U<<8U)
#define ETH_MTLRXQ1OMR_EHFC                                 (0x1U<<7U)
#define ETH_MTLRXQ1OMR_DIS_TCP_EF                           (0x1U<<6U)
#define ETH_MTLRXQ1OMR_RSF                                  (0x1U<<5U)
#define ETH_MTLRXQ1OMR_FEP                                  (0x1U<<4U)
#define ETH_MTLRXQ1OMR_FUP                                  (0x1U<<3U)
#define ETH_MTLRXQ1OMR_RTC                                  (0x3U<<0U)
#define ETH_MTLRXQ1OMR_RTC_0                                (0x1U<<0U)

#define ETH_MTLRXQ1OMR_RFD_B_0X0                            (0x0U<<14U)
#define ETH_MTLRXQ1OMR_RFD_B_0X1                            (0x1U<<14U)
#define ETH_MTLRXQ1OMR_RTC_B_0X0                            (0x0U<<0U)
#define ETH_MTLRXQ1OMR_RTC_B_0X1                            (0x1U<<0U)
#define ETH_MTLRXQ1OMR_RTC_B_0X2                            (0x2U<<0U)
#define ETH_MTLRXQ1OMR_RTC_B_0X3                            (0x3U<<0U)

// MTLRXQ1MPOCR Configuration

#define ETH_MTLRXQ1MPOCR_MISCNTOVF                          (0x1U<<27U)
#define ETH_MTLRXQ1MPOCR_MISPKTCNT                          (0x7FFU<<16U)
#define ETH_MTLRXQ1MPOCR_MISPKTCNT_0                        (0x1U<<16U)
#define ETH_MTLRXQ1MPOCR_OVFCNTOVF                          (0x1U<<11U)
#define ETH_MTLRXQ1MPOCR_OVFPKTCNT                          (0x7FFU<<0U)
#define ETH_MTLRXQ1MPOCR_OVFPKTCNT_0                        (0x1U<<0U)

// MTLRXQ1DR Configuration

#define ETH_MTLRXQ1DR_PRXQ                                  (0x3FFFU<<16U)
#define ETH_MTLRXQ1DR_PRXQ_0                                (0x1U<<16U)
#define ETH_MTLRXQ1DR_RXQSTS                                (0x3U<<4U)
#define ETH_MTLRXQ1DR_RXQSTS_0                              (0x1U<<4U)
#define ETH_MTLRXQ1DR_RRCSTS                                (0x3U<<1U)
#define ETH_MTLRXQ1DR_RRCSTS_0                              (0x1U<<1U)
#define ETH_MTLRXQ1DR_RWCSTS                                (0x1U<<0U)

#define ETH_MTLRXQ1DR_RXQSTS_B_0X0                          (0x0U<<4U)
#define ETH_MTLRXQ1DR_RXQSTS_B_0X1                          (0x1U<<4U)
#define ETH_MTLRXQ1DR_RXQSTS_B_0X2                          (0x2U<<4U)
#define ETH_MTLRXQ1DR_RXQSTS_B_0X3                          (0x3U<<4U)
#define ETH_MTLRXQ1DR_RRCSTS_B_0X0                          (0x0U<<1U)
#define ETH_MTLRXQ1DR_RRCSTS_B_0X1                          (0x1U<<1U)
#define ETH_MTLRXQ1DR_RRCSTS_B_0X2                          (0x2U<<1U)
#define ETH_MTLRXQ1DR_RRCSTS_B_0X3                          (0x3U<<1U)

// MTLRXQ1CR Configuration

#define ETH_MTLRXQ1CR_RXQ_FRM_ARBIT                         (0x1U<<3U)
#define ETH_MTLRXQ1CR_RXQ_WEGT                              (0x7U<<0U)
#define ETH_MTLRXQ1CR_RXQ_WEGT_0                            (0x1U<<0U)

// DMAMR Configuration

#define ETH_DMAMR_INTM                                      (0x3U<<16U)
#define ETH_DMAMR_INTM_0                                    (0x1U<<16U)
#define ETH_DMAMR_TXPR                                      (0x1U<<11U)
#define ETH_DMAMR_DSPW                                      (0x1U<<8U)
#define ETH_DMAMR_TAA                                       (0x7U<<2U)
#define ETH_DMAMR_TAA_0                                     (0x1U<<2U)
#define ETH_DMAMR_SWR                                       (0x1U<<0U)

#define ETH_DMAMR_DSPW_B_0X0                                (0x0U<<8U)
#define ETH_DMAMR_DSPW_B_0X1                                (0x1U<<8U)
#define ETH_DMAMR_TAA_B_0X0                                 (0x0U<<2U)
#define ETH_DMAMR_TAA_B_0X1                                 (0x1U<<2U)
#define ETH_DMAMR_TAA_B_0X2                                 (0x2U<<2U)

// DMASBMR Configuration

#define ETH_DMASBMR_EN_LPI                                  (0x1U<<31U)
#define ETH_DMASBMR_LPI_XIT_PKT                             (0x1U<<30U)
#define ETH_DMASBMR_WR_OSR_LMT                              (0x3U<<24U)
#define ETH_DMASBMR_WR_OSR_LMT_0                            (0x1U<<24U)
#define ETH_DMASBMR_RD_OSR_LMT                              (0x3U<<16U)
#define ETH_DMASBMR_RD_OSR_LMT_0                            (0x1U<<16U)
#define ETH_DMASBMR_ONEKBBE                                 (0x1U<<13U)
#define ETH_DMASBMR_AAL                                     (0x1U<<12U)
#define ETH_DMASBMR_AALE                                    (0x1U<<10U)
#define ETH_DMASBMR_BLEN256                                 (0x1U<<7U)
#define ETH_DMASBMR_BLEN128                                 (0x1U<<6U)
#define ETH_DMASBMR_BLEN64                                  (0x1U<<5U)
#define ETH_DMASBMR_BLEN32                                  (0x1U<<4U)
#define ETH_DMASBMR_BLEN16                                  (0x1U<<3U)
#define ETH_DMASBMR_BLEN8                                   (0x1U<<2U)
#define ETH_DMASBMR_BLEN4                                   (0x1U<<1U)
#define ETH_DMASBMR_FB                                      (0x1U<<0U)

// DMAISR Configuration

#define ETH_DMAISR_MACIS                                    (0x1U<<17U)
#define ETH_DMAISR_MTLIS                                    (0x1U<<16U)
#define ETH_DMAISR_DC1IS                                    (0x1U<<1U)
#define ETH_DMAISR_DC0IS                                    (0x1U<<0U)

// DMADSR Configuration

#define ETH_DMADSR_TPS1                                     (0xFU<<20U)
#define ETH_DMADSR_TPS1_0                                   (0x1U<<20U)
#define ETH_DMADSR_RPS1                                     (0xFU<<16U)
#define ETH_DMADSR_RPS1_0                                   (0x1U<<16U)
#define ETH_DMADSR_TPS0                                     (0xFU<<12U)
#define ETH_DMADSR_TPS0_0                                   (0x1U<<12U)
#define ETH_DMADSR_RPS0                                     (0xFU<<8U)
#define ETH_DMADSR_RPS0_0                                   (0x1U<<8U)
#define ETH_DMADSR_AXRHSTS                                  (0x1U<<1U)
#define ETH_DMADSR_AXWHSTS                                  (0x1U<<0U)

#define ETH_DMADSR_TPS0_B_0X0                               (0x0U<<12U)
#define ETH_DMADSR_TPS0_B_0X1                               (0x1U<<12U)
#define ETH_DMADSR_TPS0_B_0X2                               (0x2U<<12U)
#define ETH_DMADSR_TPS0_B_0X3                               (0x3U<<12U)
#define ETH_DMADSR_TPS0_B_0X4                               (0x4U<<12U)
#define ETH_DMADSR_TPS0_B_0X6                               (0x6U<<12U)
#define ETH_DMADSR_TPS0_B_0X7                               (0x7U<<12U)
#define ETH_DMADSR_RPS0_B_0X0                               (0x0U<<8U)
#define ETH_DMADSR_RPS0_B_0X1                               (0x1U<<8U)
#define ETH_DMADSR_RPS0_B_0X3                               (0x3U<<8U)
#define ETH_DMADSR_RPS0_B_0X4                               (0x4U<<8U)
#define ETH_DMADSR_RPS0_B_0X5                               (0x5U<<8U)
#define ETH_DMADSR_RPS0_B_0X6                               (0x6U<<8U)
#define ETH_DMADSR_RPS0_B_0X7                               (0x7U<<8U)

// DMAA4TXACR Configuration

#define ETH_DMAA4TXACR_THC                                  (0xFU<<16U)
#define ETH_DMAA4TXACR_THC_0                                (0x1U<<16U)
#define ETH_DMAA4TXACR_TEC                                  (0xFU<<8U)
#define ETH_DMAA4TXACR_TEC_0                                (0x1U<<8U)
#define ETH_DMAA4TXACR_TDRC                                 (0xFU<<0U)
#define ETH_DMAA4TXACR_TDRC_0                               (0x1U<<0U)

// DMAA4RXACR Configuration

#define ETH_DMAA4RXACR_RDC                                  (0xFU<<24U)
#define ETH_DMAA4RXACR_RDC_0                                (0x1U<<24U)
#define ETH_DMAA4RXACR_RHC                                  (0xFU<<16U)
#define ETH_DMAA4RXACR_RHC_0                                (0x1U<<16U)
#define ETH_DMAA4RXACR_RPC                                  (0xFU<<8U)
#define ETH_DMAA4RXACR_RPC_0                                (0x1U<<8U)
#define ETH_DMAA4RXACR_RDWC                                 (0xFU<<0U)
#define ETH_DMAA4RXACR_RDWC_0                               (0x1U<<0U)

// DMAA4DACR Configuration

#define ETH_DMAA4DACR_RDRC                                  (0xFU<<8U)
#define ETH_DMAA4DACR_RDRC_0                                (0x1U<<8U)
#define ETH_DMAA4DACR_TDWD                                  (0x3U<<4U)
#define ETH_DMAA4DACR_TDWD_0                                (0x1U<<4U)
#define ETH_DMAA4DACR_TDWC                                  (0xFU<<0U)
#define ETH_DMAA4DACR_TDWC_0                                (0x1U<<0U)

// DMALPIEI Configuration

#define ETH_DMALPIEI_LPIEI                                  (0xFU<<0U)
#define ETH_DMALPIEI_LPIEI_0                                (0x1U<<0U)

// DMATBSCTRL0R Configuration

#define ETH_DMATBSCTRL0R_FTOS                               (0xFFFFFFU<<8U)
#define ETH_DMATBSCTRL0R_FTOS_0                             (0x1U<<8U)
#define ETH_DMATBSCTRL0R_FGOS                               (0x7U<<4U)
#define ETH_DMATBSCTRL0R_FGOS_0                             (0x1U<<4U)
#define ETH_DMATBSCTRL0R_FTOV                               (0x1U<<0U)

#define ETH_DMATBSCTRL0R_FTOV_B_0X0                         (0x0U<<0U)
#define ETH_DMATBSCTRL0R_FTOV_B_0X1                         (0x1U<<0U)

// DMAC0CR Configuration

#define ETH_DMAC0CR_DSL                                     (0x7U<<18U)
#define ETH_DMAC0CR_DSL_0                                   (0x1U<<18U)
#define ETH_DMAC0CR_PBLX8                                   (0x1U<<16U)
#define ETH_DMAC0CR_MSS                                     (0x3FFFU<<0U)
#define ETH_DMAC0CR_MSS_0                                   (0x1U<<0U)

// DMAC0TXCR Configuration

#define ETH_DMAC0TXCR_EDSE                                  (0x1U<<28U)
#define ETH_DMAC0TXCR_TQOS                                  (0xFU<<24U)
#define ETH_DMAC0TXCR_TQOS_0                                (0x1U<<24U)
#define ETH_DMAC0TXCR_TXPBL                                 (0x3FU<<16U)
#define ETH_DMAC0TXCR_TXPBL_0                               (0x1U<<16U)
#define ETH_DMAC0TXCR_IPBL                                  (0x1U<<15U)
#define ETH_DMAC0TXCR_TSE                                   (0x1U<<12U)
#define ETH_DMAC0TXCR_OSF                                   (0x1U<<4U)
#define ETH_DMAC0TXCR_TCW                                   (0x7U<<1U)
#define ETH_DMAC0TXCR_TCW_0                                 (0x1U<<1U)
#define ETH_DMAC0TXCR_ST                                    (0x1U<<0U)

// DMAC0RXCR Configuration

#define ETH_DMAC0RXCR_RPF                                   (0x1U<<31U)
#define ETH_DMAC0RXCR_RQOS                                  (0xFU<<24U)
#define ETH_DMAC0RXCR_RQOS_0                                (0x1U<<24U)
#define ETH_DMAC0RXCR_RXPBL                                 (0x3FU<<16U)
#define ETH_DMAC0RXCR_RXPBL_0                               (0x1U<<16U)
#define ETH_DMAC0RXCR_RBSZ                                  (0x3FFFU<<1U)
#define ETH_DMAC0RXCR_RBSZ_0                                (0x1U<<1U)
#define ETH_DMAC0RXCR_SR                                    (0x1U<<0U)

// DMAC0TXDLAR Configuration

#define ETH_DMAC0TXDLAR_TDESLA                              (0xFFFFFFFFU<<0U)
#define ETH_DMAC0TXDLAR_TDESLA_0                            (0x1U<<0U)

// DMAC0RXDLAR Configuration

#define ETH_DMAC0RXDLAR_RDESLA                              (0xFFFFFFFFU<<0U)
#define ETH_DMAC0RXDLAR_RDESLA_0                            (0x1U<<0U)

// DMAC0TXDTPR Configuration

#define ETH_DMAC0TXDTPR_TDT                                 (0xFFFFFFFFU<<0U)
#define ETH_DMAC0TXDTPR_TDT_0                               (0x1U<<0U)

// DMAC0RXDTPR Configuration

#define ETH_DMAC0RXDTPR_RDT                                 (0xFFFFFFFFU<<0U)
#define ETH_DMAC0RXDTPR_RDT_0                               (0x1U<<0U)

// DMAC0TXRLR Configuration

#define ETH_DMAC0TXRLR_TDRL                                 (0x3FFU<<0U)
#define ETH_DMAC0TXRLR_TDRL_0                               (0x1U<<0U)

// DMAC0RXRLR Configuration

#define ETH_DMAC0RXRLR_ARBS                                 (0x7FU<<17U)
#define ETH_DMAC0RXRLR_ARBS_0                               (0x1U<<17U)
#define ETH_DMAC0RXRLR_RDRL                                 (0x3FFU<<0U)
#define ETH_DMAC0RXRLR_RDRL_0                               (0x1U<<0U)

// DMAC0IER Configuration

#define ETH_DMAC0IER_NIE                                    (0x1U<<15U)
#define ETH_DMAC0IER_AIE                                    (0x1U<<14U)
#define ETH_DMAC0IER_CDEE                                   (0x1U<<13U)
#define ETH_DMAC0IER_FBEE                                   (0x1U<<12U)
#define ETH_DMAC0IER_ERIE                                   (0x1U<<11U)
#define ETH_DMAC0IER_ETIE                                   (0x1U<<10U)
#define ETH_DMAC0IER_RWTE                                   (0x1U<<9U)
#define ETH_DMAC0IER_RSE                                    (0x1U<<8U)
#define ETH_DMAC0IER_RBUE                                   (0x1U<<7U)
#define ETH_DMAC0IER_RIE                                    (0x1U<<6U)
#define ETH_DMAC0IER_TBUE                                   (0x1U<<2U)
#define ETH_DMAC0IER_TXSE                                   (0x1U<<1U)
#define ETH_DMAC0IER_TIE                                    (0x1U<<0U)

// DMAC0RXIWTR Configuration

#define ETH_DMAC0RXIWTR_RWTU                                (0x3U<<16U)
#define ETH_DMAC0RXIWTR_RWTU_0                              (0x1U<<16U)
#define ETH_DMAC0RXIWTR_RWT                                 (0xFFU<<0U)
#define ETH_DMAC0RXIWTR_RWT_0                               (0x1U<<0U)

#define ETH_DMAC0RXIWTR_RWTU_B_0X0                          (0x0U<<16U)
#define ETH_DMAC0RXIWTR_RWTU_B_0X1                          (0x1U<<16U)
#define ETH_DMAC0RXIWTR_RWTU_B_0X2                          (0x2U<<16U)
#define ETH_DMAC0RXIWTR_RWTU_B_0X3                          (0x3U<<16U)

// DMAC0SFCSR Configuration

#define ETH_DMAC0SFCSR_RSN                                  (0xFU<<16U)
#define ETH_DMAC0SFCSR_RSN_0                                (0x1U<<16U)
#define ETH_DMAC0SFCSR_SIV                                  (0xFFFU<<4U)
#define ETH_DMAC0SFCSR_SIV_0                                (0x1U<<4U)
#define ETH_DMAC0SFCSR_ASC                                  (0x1U<<1U)
#define ETH_DMAC0SFCSR_ESC                                  (0x1U<<0U)

// DMAC0CATXDR Configuration

#define ETH_DMAC0CATXDR_CURTDESAPTR                         (0xFFFFFFFFU<<0U)
#define ETH_DMAC0CATXDR_CURTDESAPTR_0                       (0x1U<<0U)

// DMAC0CARXDR Configuration

#define ETH_DMAC0CARXDR_CURRDESAPTR                         (0xFFFFFFFFU<<0U)
#define ETH_DMAC0CARXDR_CURRDESAPTR_0                       (0x1U<<0U)

// DMAC0CATXBR Configuration

#define ETH_DMAC0CATXBR_CURTBUFAPTR                         (0xFFFFFFFFU<<0U)
#define ETH_DMAC0CATXBR_CURTBUFAPTR_0                       (0x1U<<0U)

// DMAC0CARXBR Configuration

#define ETH_DMAC0CARXBR_CURRBUFAPTR                         (0xFFFFFFFFU<<0U)
#define ETH_DMAC0CARXBR_CURRBUFAPTR_0                       (0x1U<<0U)

// DMAC0SR Configuration

#define ETH_DMAC0SR_REB                                     (0x7U<<19U)
#define ETH_DMAC0SR_REB_0                                   (0x1U<<19U)
#define ETH_DMAC0SR_TEB                                     (0x7U<<16U)
#define ETH_DMAC0SR_TEB_0                                   (0x1U<<16U)
#define ETH_DMAC0SR_NIS                                     (0x1U<<15U)
#define ETH_DMAC0SR_AIS                                     (0x1U<<14U)
#define ETH_DMAC0SR_CDE                                     (0x1U<<13U)
#define ETH_DMAC0SR_FBE                                     (0x1U<<12U)
#define ETH_DMAC0SR_ERI                                     (0x1U<<11U)
#define ETH_DMAC0SR_ETI                                     (0x1U<<10U)
#define ETH_DMAC0SR_RWT                                     (0x1U<<9U)
#define ETH_DMAC0SR_RPS                                     (0x1U<<8U)
#define ETH_DMAC0SR_RBU                                     (0x1U<<7U)
#define ETH_DMAC0SR_RI                                      (0x1U<<6U)
#define ETH_DMAC0SR_TBU                                     (0x1U<<2U)
#define ETH_DMAC0SR_TPS                                     (0x1U<<1U)
#define ETH_DMAC0SR_TI                                      (0x1U<<0U)

// DMAC0MFCR Configuration

#define ETH_DMAC0MFCR_MFCO                                  (0x1U<<15U)
#define ETH_DMAC0MFCR_MFC                                   (0x7FFU<<0U)
#define ETH_DMAC0MFCR_MFC_0                                 (0x1U<<0U)

// DMAC1CR Configuration

#define ETH_DMAC1CR_DSL                                     (0x7U<<18U)
#define ETH_DMAC1CR_DSL_0                                   (0x1U<<18U)
#define ETH_DMAC1CR_PBLX8                                   (0x1U<<16U)
#define ETH_DMAC1CR_MSS                                     (0x3FFFU<<0U)
#define ETH_DMAC1CR_MSS_0                                   (0x1U<<0U)

// DMAC1TXCR Configuration

#define ETH_DMAC1TXCR_EDSE                                  (0x1U<<28U)
#define ETH_DMAC1TXCR_TQOS                                  (0xFU<<24U)
#define ETH_DMAC1TXCR_TQOS_0                                (0x1U<<24U)
#define ETH_DMAC1TXCR_TXPBL                                 (0x3FU<<16U)
#define ETH_DMAC1TXCR_TXPBL_0                               (0x1U<<16U)
#define ETH_DMAC1TXCR_IPBL                                  (0x1U<<15U)
#define ETH_DMAC1TXCR_TSE                                   (0x1U<<12U)
#define ETH_DMAC1TXCR_OSF                                   (0x1U<<4U)
#define ETH_DMAC1TXCR_TCW                                   (0x7U<<1U)
#define ETH_DMAC1TXCR_TCW_0                                 (0x1U<<1U)
#define ETH_DMAC1TXCR_ST                                    (0x1U<<0U)

// DMAC1RXCR Configuration

#define ETH_DMAC1RXCR_RPF                                   (0x1U<<31U)
#define ETH_DMAC1RXCR_RQOS                                  (0xFU<<24U)
#define ETH_DMAC1RXCR_RQOS_0                                (0x1U<<24U)
#define ETH_DMAC1RXCR_RXPBL                                 (0x3FU<<16U)
#define ETH_DMAC1RXCR_RXPBL_0                               (0x1U<<16U)
#define ETH_DMAC1RXCR_RBSZ                                  (0x3FFFU<<1U)
#define ETH_DMAC1RXCR_RBSZ_0                                (0x1U<<1U)
#define ETH_DMAC1RXCR_SR                                    (0x1U<<0U)

// DMAC1TXDLAR Configuration

#define ETH_DMAC1TXDLAR_TDESLA                              (0xFFFFFFFFU<<0U)
#define ETH_DMAC1TXDLAR_TDESLA_0                            (0x1U<<0U)

// DMAC1TXDTPR Configuration

#define ETH_DMAC1TXDTPR_TDT                                 (0xFFFFFFFFU<<0U)
#define ETH_DMAC1TXDTPR_TDT_0                               (0x1U<<0U)

// DMAC1RXDTPR Configuration

#define ETH_DMAC1RXDTPR_RDT                                 (0xFFFFFFFFU<<0U)
#define ETH_DMAC1RXDTPR_RDT_0                               (0x1U<<0U)

// DMAC1TXRLR Configuration

#define ETH_DMAC1TXRLR_TDRL                                 (0x3FFU<<0U)
#define ETH_DMAC1TXRLR_TDRL_0                               (0x1U<<0U)

// DMAC1RXRLR Configuration

#define ETH_DMAC1RXRLR_ARBS                                 (0x7FU<<17U)
#define ETH_DMAC1RXRLR_ARBS_0                               (0x1U<<17U)
#define ETH_DMAC1RXRLR_RDRL                                 (0x3FFU<<0U)
#define ETH_DMAC1RXRLR_RDRL_0                               (0x1U<<0U)

// DMAC1IER Configuration

#define ETH_DMAC1IER_NIE                                    (0x1U<<15U)
#define ETH_DMAC1IER_AIE                                    (0x1U<<14U)
#define ETH_DMAC1IER_CDEE                                   (0x1U<<13U)
#define ETH_DMAC1IER_FBEE                                   (0x1U<<12U)
#define ETH_DMAC1IER_ERIE                                   (0x1U<<11U)
#define ETH_DMAC1IER_ETIE                                   (0x1U<<10U)
#define ETH_DMAC1IER_RWTE                                   (0x1U<<9U)
#define ETH_DMAC1IER_RSE                                    (0x1U<<8U)
#define ETH_DMAC1IER_RBUE                                   (0x1U<<7U)
#define ETH_DMAC1IER_RIE                                    (0x1U<<6U)
#define ETH_DMAC1IER_TBUE                                   (0x1U<<2U)
#define ETH_DMAC1IER_TXSE                                   (0x1U<<1U)
#define ETH_DMAC1IER_TIE                                    (0x1U<<0U)

// DMAC1RXIWTR Configuration

#define ETH_DMAC1RXIWTR_RWTU                                (0x3U<<16U)
#define ETH_DMAC1RXIWTR_RWTU_0                              (0x1U<<16U)
#define ETH_DMAC1RXIWTR_RWT                                 (0xFFU<<0U)
#define ETH_DMAC1RXIWTR_RWT_0                               (0x1U<<0U)

#define ETH_DMAC1RXIWTR_RWTU_B_0X0                          (0x0U<<16U)
#define ETH_DMAC1RXIWTR_RWTU_B_0X1                          (0x1U<<16U)
#define ETH_DMAC1RXIWTR_RWTU_B_0X2                          (0x2U<<16U)
#define ETH_DMAC1RXIWTR_RWTU_B_0X3                          (0x3U<<16U)

// DMAC1SFCSR Configuration

#define ETH_DMAC1SFCSR_RSN                                  (0xFU<<16U)
#define ETH_DMAC1SFCSR_RSN_0                                (0x1U<<16U)
#define ETH_DMAC1SFCSR_SIV                                  (0xFFFU<<4U)
#define ETH_DMAC1SFCSR_SIV_0                                (0x1U<<4U)
#define ETH_DMAC1SFCSR_ASC                                  (0x1U<<1U)
#define ETH_DMAC1SFCSR_ESC                                  (0x1U<<0U)

// DMAC1CATXDR Configuration

#define ETH_DMAC1CATXDR_CURTDESAPTR                         (0xFFFFFFFFU<<0U)
#define ETH_DMAC1CATXDR_CURTDESAPTR_0                       (0x1U<<0U)

// DMAC1CARXDR Configuration

#define ETH_DMAC1CARXDR_CURRDESAPTR                         (0xFFFFFFFFU<<0U)
#define ETH_DMAC1CARXDR_CURRDESAPTR_0                       (0x1U<<0U)

// DMAC1CATXBR Configuration

#define ETH_DMAC1CATXBR_CURTBUFAPTR                         (0xFFFFFFFFU<<0U)
#define ETH_DMAC1CATXBR_CURTBUFAPTR_0                       (0x1U<<0U)

// DMAC1CARXBR Configuration

#define ETH_DMAC1CARXBR_CURRBUFAPTR                         (0xFFFFFFFFU<<0U)
#define ETH_DMAC1CARXBR_CURRBUFAPTR_0                       (0x1U<<0U)

// DMAC1SR Configuration

#define ETH_DMAC1SR_REB                                     (0x7U<<19U)
#define ETH_DMAC1SR_REB_0                                   (0x1U<<19U)
#define ETH_DMAC1SR_TEB                                     (0x7U<<16U)
#define ETH_DMAC1SR_TEB_0                                   (0x1U<<16U)
#define ETH_DMAC1SR_NIS                                     (0x1U<<15U)
#define ETH_DMAC1SR_AIS                                     (0x1U<<14U)
#define ETH_DMAC1SR_CDE                                     (0x1U<<13U)
#define ETH_DMAC1SR_FBE                                     (0x1U<<12U)
#define ETH_DMAC1SR_ERI                                     (0x1U<<11U)
#define ETH_DMAC1SR_ETI                                     (0x1U<<10U)
#define ETH_DMAC1SR_RWT                                     (0x1U<<9U)
#define ETH_DMAC1SR_RPS                                     (0x1U<<8U)
#define ETH_DMAC1SR_RBU                                     (0x1U<<7U)
#define ETH_DMAC1SR_RI                                      (0x1U<<6U)
#define ETH_DMAC1SR_TBU                                     (0x1U<<2U)
#define ETH_DMAC1SR_TPS                                     (0x1U<<1U)
#define ETH_DMAC1SR_TI                                      (0x1U<<0U)

// DMAC1MFCR Configuration

#define ETH_DMAC1MFCR_MFCO                                  (0x1U<<15U)
#define ETH_DMAC1MFCR_MFC                                   (0x7FFU<<0U)
#define ETH_DMAC1MFCR_MFC_0                                 (0x1U<<0U)
