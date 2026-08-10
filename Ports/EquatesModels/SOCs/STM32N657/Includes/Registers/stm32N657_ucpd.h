/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_ucpd equates.
 */

#pragma once

#include    <stdint.h>

// UCPD address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CFGR1;
    volatile    uint32_t    CFGR2;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    CR;
    volatile    uint32_t    IMR;
    volatile    uint32_t    SR;
    volatile    uint32_t    ICR;
    volatile    uint32_t    TX_ORDSETR;
    volatile    uint32_t    TX_PAYSZR;
    volatile    uint32_t    TXDR;
    volatile    uint32_t    RX_ORDSETR;
    volatile    uint32_t    RX_PAYSZR;
    volatile    uint32_t    RXDR;
    volatile    uint32_t    RX_ORDEXTR1;
    volatile    uint32_t    RX_ORDEXTR2;
} UCPD_TypeDef;

#ifdef __cplusplus
#define UCPD_NS reinterpret_cast<UCPD_TypeDef *>(0x4000FC00U)
#define UCPD_S  reinterpret_cast<UCPD_TypeDef *>(0x5000FC00U)

#else
#define UCPD_NS ((UCPD_TypeDef *)0x4000FC00U)
#define UCPD_S  ((UCPD_TypeDef *)0x5000FC00U)
#endif

// CFGR1 Configuration

#define UCPD_CFGR1_UCPDEN                       (0x1U<<31U)
#define UCPD_CFGR1_RXDMAEN                      (0x1U<<30U)
#define UCPD_CFGR1_TXDMAEN                      (0x1U<<29U)
#define UCPD_CFGR1_RXORDSETEN                   (0x1FFU<<20U)
#define UCPD_CFGR1_RXORDSETEN_0                 (0x1U<<20U)
#define UCPD_CFGR1_PSC_USBPDCLK                 (0x7U<<17U)
#define UCPD_CFGR1_PSC_USBPDCLK_0               (0x1U<<17U)
#define UCPD_CFGR1_TRANSWIN                     (0x1FU<<11U)
#define UCPD_CFGR1_TRANSWIN_0                   (0x1U<<11U)
#define UCPD_CFGR1_IFRGAP                       (0x1FU<<6U)
#define UCPD_CFGR1_IFRGAP_0                     (0x1U<<6U)
#define UCPD_CFGR1_HBITCLKDIV                   (0x3FU<<0U)
#define UCPD_CFGR1_HBITCLKDIV_0                 (0x1U<<0U)

#define UCPD_CFGR1_UCPDEN_B_0X0                 (0x0U<<31U)
#define UCPD_CFGR1_UCPDEN_B_0X1                 (0x1U<<31U)
#define UCPD_CFGR1_RXDMAEN_B_0X0                (0x0U<<30U)
#define UCPD_CFGR1_RXDMAEN_B_0X1                (0x1U<<30U)
#define UCPD_CFGR1_TXDMAEN_B_0X0                (0x0U<<29U)
#define UCPD_CFGR1_TXDMAEN_B_0X1                (0x1U<<29U)
#define UCPD_CFGR1_PSC_USBPDCLK_B_0X0           (0x0U<<17U)
#define UCPD_CFGR1_PSC_USBPDCLK_B_0X1           (0x1U<<17U)
#define UCPD_CFGR1_PSC_USBPDCLK_B_0X2           (0x2U<<17U)
#define UCPD_CFGR1_PSC_USBPDCLK_B_0X3           (0x3U<<17U)
#define UCPD_CFGR1_PSC_USBPDCLK_B_0X4           (0x4U<<17U)
#define UCPD_CFGR1_TRANSWIN_B_0X00              (0x0U<<11U)
#define UCPD_CFGR1_TRANSWIN_B_0X01              (0x1U<<11U)
#define UCPD_CFGR1_TRANSWIN_B_0X09              (0x9U<<11U)
#define UCPD_CFGR1_TRANSWIN_B_0X1F              (0x1FU<<11U)
#define UCPD_CFGR1_IFRGAP_B_0X00                (0x0U<<6U)
#define UCPD_CFGR1_IFRGAP_B_0X01                (0x1U<<6U)
#define UCPD_CFGR1_IFRGAP_B_0X0D                (0xDU<<6U)
#define UCPD_CFGR1_IFRGAP_B_0X0E                (0xEU<<6U)
#define UCPD_CFGR1_IFRGAP_B_0X0F                (0xFU<<6U)
#define UCPD_CFGR1_IFRGAP_B_0X1F                (0x1FU<<6U)
#define UCPD_CFGR1_HBITCLKDIV_B_0X00            (0x0U<<0U)
#define UCPD_CFGR1_HBITCLKDIV_B_0X1A            (0x1AU<<0U)
#define UCPD_CFGR1_HBITCLKDIV_B_0X3F            (0x3FU<<0U)

// CFGR2 Configuration

#define UCPD_CFGR2_WUPEN                        (0x1U<<3U)
#define UCPD_CFGR2_FORCECLK                     (0x1U<<2U)
#define UCPD_CFGR2_RXFILT2N3                    (0x1U<<1U)
#define UCPD_CFGR2_RXFILTDIS                    (0x1U<<0U)

#define UCPD_CFGR2_WUPEN_B_0X0                  (0x0U<<3U)
#define UCPD_CFGR2_WUPEN_B_0X1                  (0x1U<<3U)
#define UCPD_CFGR2_FORCECLK_B_0X0               (0x0U<<2U)
#define UCPD_CFGR2_FORCECLK_B_0X1               (0x1U<<2U)
#define UCPD_CFGR2_RXFILT2N3_B_0X0              (0x0U<<1U)
#define UCPD_CFGR2_RXFILT2N3_B_0X1              (0x1U<<1U)
#define UCPD_CFGR2_RXFILTDIS_B_0X0              (0x0U<<0U)
#define UCPD_CFGR2_RXFILTDIS_B_0X1              (0x1U<<0U)

// CR Configuration

#define UCPD_CR_CC2TCDIS                        (0x1U<<21U)
#define UCPD_CR_CC1TCDIS                        (0x1U<<20U)
#define UCPD_CR_RDCH                            (0x1U<<18U)
#define UCPD_CR_FRSTX                           (0x1U<<17U)
#define UCPD_CR_FRSRXEN                         (0x1U<<16U)
#define UCPD_CR_CCENABLE                        (0x3U<<10U)
#define UCPD_CR_CCENABLE_0                      (0x1U<<10U)
#define UCPD_CR_ANAMODE                         (0x1U<<9U)
#define UCPD_CR_ANASUBMODE                      (0x3U<<7U)
#define UCPD_CR_ANASUBMODE_0                    (0x1U<<7U)
#define UCPD_CR_PHYCCSEL                        (0x1U<<6U)
#define UCPD_CR_PHYRXEN                         (0x1U<<5U)
#define UCPD_CR_RXMODE                          (0x1U<<4U)
#define UCPD_CR_TXHRST                          (0x1U<<3U)
#define UCPD_CR_TXSEND                          (0x1U<<2U)
#define UCPD_CR_TXMODE                          (0x3U<<0U)
#define UCPD_CR_TXMODE_0                        (0x1U<<0U)

#define UCPD_CR_CC2TCDIS_B_0X0                  (0x0U<<21U)
#define UCPD_CR_CC2TCDIS_B_0X1                  (0x1U<<21U)
#define UCPD_CR_CC1TCDIS_B_0X0                  (0x0U<<20U)
#define UCPD_CR_CC1TCDIS_B_0X1                  (0x1U<<20U)
#define UCPD_CR_RDCH_B_0X0                      (0x0U<<18U)
#define UCPD_CR_RDCH_B_0X1                      (0x1U<<18U)
#define UCPD_CR_FRSTX_B_0X0                     (0x0U<<17U)
#define UCPD_CR_FRSTX_B_0X1                     (0x1U<<17U)
#define UCPD_CR_FRSRXEN_B_0X1                   (0x1U<<16U)
#define UCPD_CR_CCENABLE_B_0X0                  (0x0U<<10U)
#define UCPD_CR_CCENABLE_B_0X1                  (0x1U<<10U)
#define UCPD_CR_CCENABLE_B_0X2                  (0x2U<<10U)
#define UCPD_CR_CCENABLE_B_0X3                  (0x3U<<10U)
#define UCPD_CR_ANAMODE_B_0X0                   (0x0U<<9U)
#define UCPD_CR_ANAMODE_B_0X1                   (0x1U<<9U)
#define UCPD_CR_PHYCCSEL_B_0X0                  (0x0U<<6U)
#define UCPD_CR_PHYCCSEL_B_0X1                  (0x1U<<6U)
#define UCPD_CR_PHYRXEN_B_0X0                   (0x0U<<5U)
#define UCPD_CR_PHYRXEN_B_0X1                   (0x1U<<5U)
#define UCPD_CR_RXMODE_B_0X0                    (0x0U<<4U)
#define UCPD_CR_RXMODE_B_0X1                    (0x1U<<4U)
#define UCPD_CR_TXHRST_B_0X0                    (0x0U<<3U)
#define UCPD_CR_TXHRST_B_0X1                    (0x1U<<3U)
#define UCPD_CR_TXSEND_B_0X0                    (0x0U<<2U)
#define UCPD_CR_TXSEND_B_0X1                    (0x1U<<2U)
#define UCPD_CR_TXMODE_B_0X0                    (0x0U<<0U)
#define UCPD_CR_TXMODE_B_0X1                    (0x1U<<0U)
#define UCPD_CR_TXMODE_B_0X2                    (0x2U<<0U)

// IMR Configuration

#define UCPD_IMR_FRSEVTIE                       (0x1U<<20U)
#define UCPD_IMR_TYPECEVT2IE                    (0x1U<<15U)
#define UCPD_IMR_TYPECEVT1IE                    (0x1U<<14U)
#define UCPD_IMR_RXMSGENDIE                     (0x1U<<12U)
#define UCPD_IMR_RXOVRIE                        (0x1U<<11U)
#define UCPD_IMR_RXHRSTDETIE                    (0x1U<<10U)
#define UCPD_IMR_RXORDDETIE                     (0x1U<<9U)
#define UCPD_IMR_RXNEIE                         (0x1U<<8U)
#define UCPD_IMR_TXUNDIE                        (0x1U<<6U)
#define UCPD_IMR_HRSTSENTIE                     (0x1U<<5U)
#define UCPD_IMR_HRSTDISCIE                     (0x1U<<4U)
#define UCPD_IMR_TXMSGABTIE                     (0x1U<<3U)
#define UCPD_IMR_TXMSGSENTIE                    (0x1U<<2U)
#define UCPD_IMR_TXMSGDISCIE                    (0x1U<<1U)
#define UCPD_IMR_TXISIE                         (0x1U<<0U)

#define UCPD_IMR_FRSEVTIE_B_0X0                 (0x0U<<20U)
#define UCPD_IMR_FRSEVTIE_B_0X1                 (0x1U<<20U)
#define UCPD_IMR_TYPECEVT2IE_B_0X0              (0x0U<<15U)
#define UCPD_IMR_TYPECEVT2IE_B_0X1              (0x1U<<15U)
#define UCPD_IMR_RXMSGENDIE_B_0X0               (0x0U<<12U)
#define UCPD_IMR_RXMSGENDIE_B_0X1               (0x1U<<12U)
#define UCPD_IMR_RXOVRIE_B_0X0                  (0x0U<<11U)
#define UCPD_IMR_RXOVRIE_B_0X1                  (0x1U<<11U)
#define UCPD_IMR_RXHRSTDETIE_B_0X0              (0x0U<<10U)
#define UCPD_IMR_RXHRSTDETIE_B_0X1              (0x1U<<10U)
#define UCPD_IMR_RXORDDETIE_B_0X0               (0x0U<<9U)
#define UCPD_IMR_RXORDDETIE_B_0X1               (0x1U<<9U)
#define UCPD_IMR_RXNEIE_B_0X0                   (0x0U<<8U)
#define UCPD_IMR_RXNEIE_B_0X1                   (0x1U<<8U)
#define UCPD_IMR_TXUNDIE_B_0X0                  (0x0U<<6U)
#define UCPD_IMR_TXUNDIE_B_0X1                  (0x1U<<6U)
#define UCPD_IMR_HRSTSENTIE_B_0X0               (0x0U<<5U)
#define UCPD_IMR_HRSTSENTIE_B_0X1               (0x1U<<5U)
#define UCPD_IMR_HRSTDISCIE_B_0X0               (0x0U<<4U)
#define UCPD_IMR_HRSTDISCIE_B_0X1               (0x1U<<4U)
#define UCPD_IMR_TXMSGABTIE_B_0X0               (0x0U<<3U)
#define UCPD_IMR_TXMSGABTIE_B_0X1               (0x1U<<3U)
#define UCPD_IMR_TXMSGSENTIE_B_0X0              (0x0U<<2U)
#define UCPD_IMR_TXMSGSENTIE_B_0X1              (0x1U<<2U)
#define UCPD_IMR_TXMSGDISCIE_B_0X0              (0x0U<<1U)
#define UCPD_IMR_TXMSGDISCIE_B_0X1              (0x1U<<1U)
#define UCPD_IMR_TXISIE_B_0X0                   (0x0U<<0U)
#define UCPD_IMR_TXISIE_B_0X1                   (0x1U<<0U)

// SR Configuration

#define UCPD_SR_FRSEVT                          (0x1U<<20U)
#define UCPD_SR_TYPEC_VSTATE_CC2                (0x3U<<18U)
#define UCPD_SR_TYPEC_VSTATE_CC2_0              (0x1U<<18U)
#define UCPD_SR_TYPEC_VSTATE_CC1                (0x3U<<16U)
#define UCPD_SR_TYPEC_VSTATE_CC1_0              (0x1U<<16U)
#define UCPD_SR_TYPECEVT2                       (0x1U<<15U)
#define UCPD_SR_TYPECEVT1                       (0x1U<<14U)
#define UCPD_SR_RXERR                           (0x1U<<13U)
#define UCPD_SR_RXMSGEND                        (0x1U<<12U)
#define UCPD_SR_RXOVR                           (0x1U<<11U)
#define UCPD_SR_RXHRSTDET                       (0x1U<<10U)
#define UCPD_SR_RXORDDET                        (0x1U<<9U)
#define UCPD_SR_RXNE                            (0x1U<<8U)
#define UCPD_SR_TXUND                           (0x1U<<6U)
#define UCPD_SR_HRSTSENT                        (0x1U<<5U)
#define UCPD_SR_HRSTDISC                        (0x1U<<4U)
#define UCPD_SR_TXMSGABT                        (0x1U<<3U)
#define UCPD_SR_TXMSGSENT                       (0x1U<<2U)
#define UCPD_SR_TXMSGDISC                       (0x1U<<1U)
#define UCPD_SR_TXIS                            (0x1U<<0U)

#define UCPD_SR_FRSEVT_B_0X0                    (0x0U<<20U)
#define UCPD_SR_FRSEVT_B_0X1                    (0x1U<<20U)
#define UCPD_SR_TYPEC_VSTATE_CC2_B_0X0          (0x0U<<18U)
#define UCPD_SR_TYPEC_VSTATE_CC2_B_0X1          (0x1U<<18U)
#define UCPD_SR_TYPEC_VSTATE_CC2_B_0X2          (0x2U<<18U)
#define UCPD_SR_TYPEC_VSTATE_CC2_B_0X3          (0x3U<<18U)
#define UCPD_SR_TYPEC_VSTATE_CC1_B_0X0          (0x0U<<16U)
#define UCPD_SR_TYPEC_VSTATE_CC1_B_0X1          (0x1U<<16U)
#define UCPD_SR_TYPEC_VSTATE_CC1_B_0X2          (0x2U<<16U)
#define UCPD_SR_TYPEC_VSTATE_CC1_B_0X3          (0x3U<<16U)
#define UCPD_SR_TYPECEVT2_B_0X0                 (0x0U<<15U)
#define UCPD_SR_TYPECEVT2_B_0X1                 (0x1U<<15U)
#define UCPD_SR_TYPECEVT1_B_0X0                 (0x0U<<14U)
#define UCPD_SR_TYPECEVT1_B_0X1                 (0x1U<<14U)
#define UCPD_SR_RXERR_B_0X0                     (0x0U<<13U)
#define UCPD_SR_RXERR_B_0X1                     (0x1U<<13U)
#define UCPD_SR_RXMSGEND_B_0X0                  (0x0U<<12U)
#define UCPD_SR_RXMSGEND_B_0X1                  (0x1U<<12U)
#define UCPD_SR_RXOVR_B_0X0                     (0x0U<<11U)
#define UCPD_SR_RXOVR_B_0X1                     (0x1U<<11U)
#define UCPD_SR_RXHRSTDET_B_0X0                 (0x0U<<10U)
#define UCPD_SR_RXHRSTDET_B_0X1                 (0x1U<<10U)
#define UCPD_SR_RXORDDET_B_0X0                  (0x0U<<9U)
#define UCPD_SR_RXORDDET_B_0X1                  (0x1U<<9U)
#define UCPD_SR_RXNE_B_0X0                      (0x0U<<8U)
#define UCPD_SR_RXNE_B_0X1                      (0x1U<<8U)
#define UCPD_SR_TXUND_B_0X0                     (0x0U<<6U)
#define UCPD_SR_TXUND_B_0X1                     (0x1U<<6U)
#define UCPD_SR_HRSTSENT_B_0X0                  (0x0U<<5U)
#define UCPD_SR_HRSTSENT_B_0X1                  (0x1U<<5U)
#define UCPD_SR_HRSTDISC_B_0X0                  (0x0U<<4U)
#define UCPD_SR_HRSTDISC_B_0X1                  (0x1U<<4U)
#define UCPD_SR_TXMSGABT_B_0X0                  (0x0U<<3U)
#define UCPD_SR_TXMSGABT_B_0X1                  (0x1U<<3U)
#define UCPD_SR_TXMSGSENT_B_0X0                 (0x0U<<2U)
#define UCPD_SR_TXMSGSENT_B_0X1                 (0x1U<<2U)
#define UCPD_SR_TXMSGDISC_B_0X0                 (0x0U<<1U)
#define UCPD_SR_TXMSGDISC_B_0X1                 (0x1U<<1U)
#define UCPD_SR_TXIS_B_0X0                      (0x0U<<0U)
#define UCPD_SR_TXIS_B_0X1                      (0x1U<<0U)

// ICR Configuration

#define UCPD_ICR_FRSEVTCF                       (0x1U<<20U)
#define UCPD_ICR_TYPECEVT2CF                    (0x1U<<15U)
#define UCPD_ICR_TYPECEVT1CF                    (0x1U<<14U)
#define UCPD_ICR_RXMSGENDCF                     (0x1U<<12U)
#define UCPD_ICR_RXOVRCF                        (0x1U<<11U)
#define UCPD_ICR_RXHRSTDETCF                    (0x1U<<10U)
#define UCPD_ICR_RXORDDETCF                     (0x1U<<9U)
#define UCPD_ICR_TXUNDCF                        (0x1U<<6U)
#define UCPD_ICR_HRSTSENTCF                     (0x1U<<5U)
#define UCPD_ICR_HRSTDISCCF                     (0x1U<<4U)
#define UCPD_ICR_TXMSGABTCF                     (0x1U<<3U)
#define UCPD_ICR_TXMSGSENTCF                    (0x1U<<2U)
#define UCPD_ICR_TXMSGDISCCF                    (0x1U<<1U)

// TX_ORDSETR Configuration

#define UCPD_TX_ORDSETR_TXORDSET                (0xFFFFFU<<0U)
#define UCPD_TX_ORDSETR_TXORDSET_0              (0x1U<<0U)

// TX_PAYSZR Configuration

#define UCPD_TX_PAYSZR_TXPAYSZ                  (0x3FFU<<0U)
#define UCPD_TX_PAYSZR_TXPAYSZ_0                (0x1U<<0U)

#define UCPD_TX_PAYSZR_TXPAYSZ_B_0X2            (0x2U<<0U)
#define UCPD_TX_PAYSZR_TXPAYSZ_B_0X6            (0x6U<<0U)
#define UCPD_TX_PAYSZR_TXPAYSZ_B_0X1E           (0x1EU<<0U)
#define UCPD_TX_PAYSZR_TXPAYSZ_B_0X106          (0x106U<<0U)
#define UCPD_TX_PAYSZR_TXPAYSZ_B_0X3FF          (0x3FFU<<0U)

// TXDR Configuration

#define UCPD_TXDR_TXDATA                        (0xFFU<<0U)
#define UCPD_TXDR_TXDATA_0                      (0x1U<<0U)

// RX_ORDSETR Configuration

#define UCPD_RX_ORDSETR_RXSOPKINVALID           (0x7U<<4U)
#define UCPD_RX_ORDSETR_RXSOPKINVALID_0         (0x1U<<4U)
#define UCPD_RX_ORDSETR_RXSOP3OF4               (0x1U<<3U)
#define UCPD_RX_ORDSETR_RXORDSET                (0x7U<<0U)
#define UCPD_RX_ORDSETR_RXORDSET_0              (0x1U<<0U)

#define UCPD_RX_ORDSETR_RXSOPKINVALID_B_0X0     (0x0U<<4U)
#define UCPD_RX_ORDSETR_RXSOPKINVALID_B_0X1     (0x1U<<4U)
#define UCPD_RX_ORDSETR_RXSOPKINVALID_B_0X2     (0x2U<<4U)
#define UCPD_RX_ORDSETR_RXSOPKINVALID_B_0X3     (0x3U<<4U)
#define UCPD_RX_ORDSETR_RXSOPKINVALID_B_0X4     (0x4U<<4U)
#define UCPD_RX_ORDSETR_RXSOP3OF4_B_0X0         (0x0U<<3U)
#define UCPD_RX_ORDSETR_RXSOP3OF4_B_0X1         (0x1U<<3U)
#define UCPD_RX_ORDSETR_RXORDSET_B_0X0          (0x0U<<0U)
#define UCPD_RX_ORDSETR_RXORDSET_B_0X1          (0x1U<<0U)
#define UCPD_RX_ORDSETR_RXORDSET_B_0X2          (0x2U<<0U)
#define UCPD_RX_ORDSETR_RXORDSET_B_0X3          (0x3U<<0U)
#define UCPD_RX_ORDSETR_RXORDSET_B_0X4          (0x4U<<0U)
#define UCPD_RX_ORDSETR_RXORDSET_B_0X5          (0x5U<<0U)
#define UCPD_RX_ORDSETR_RXORDSET_B_0X6          (0x6U<<0U)
#define UCPD_RX_ORDSETR_RXORDSET_B_0X7          (0x7U<<0U)

// RX_PAYSZR Configuration

#define UCPD_RX_PAYSZR_RXPAYSZ                  (0x3FFU<<0U)
#define UCPD_RX_PAYSZR_RXPAYSZ_0                (0x1U<<0U)

#define UCPD_RX_PAYSZR_RXPAYSZ_B_0X2            (0x2U<<0U)
#define UCPD_RX_PAYSZR_RXPAYSZ_B_0X6            (0x6U<<0U)
#define UCPD_RX_PAYSZR_RXPAYSZ_B_0X1E           (0x1EU<<0U)
#define UCPD_RX_PAYSZR_RXPAYSZ_B_0X106          (0x106U<<0U)
#define UCPD_RX_PAYSZR_RXPAYSZ_B_0X3FF          (0x3FFU<<0U)

// RXDR Configuration

#define UCPD_RXDR_RXDATA                        (0xFFU<<0U)
#define UCPD_RXDR_RXDATA_0                      (0x1U<<0U)

// RX_ORDEXTR1 Configuration

#define UCPD_RX_ORDEXTR1_RXSOPX1                (0xFFFFFU<<0U)
#define UCPD_RX_ORDEXTR1_RXSOPX1_0              (0x1U<<0U)

// RX_ORDEXTR2 Configuration

#define UCPD_RX_ORDEXTR2_RXSOPX2                (0xFFFFFU<<0U)
#define UCPD_RX_ORDEXTR2_RXSOPX2_0              (0x1U<<0U)
