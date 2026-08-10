/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_ucpd equates.
 */

#pragma once

#include    <stdint.h>

// UCPD address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CFGR1;
    volatile    uint32_t    CFGR2;
    volatile    uint32_t    CFGR3;
    volatile    uint32_t    CR;
    volatile    uint32_t    IMR;
    volatile    uint32_t    SR;
    volatile    uint32_t    ICR;
    volatile    uint32_t    TX_ORDSET;
    volatile    uint32_t    TX_PAYSZ;
    volatile    uint32_t    TXDR;
    volatile    uint32_t    RX_ORDSET;
    volatile    uint32_t    RX_PAYSZ;
    volatile    uint32_t    RXDR;
    volatile    uint32_t    RX_ORDEXT1;
    volatile    uint32_t    RX_ORDEXT2;
} UCPD_TypeDef;

#ifdef __cplusplus
#define UCPD1_NS    reinterpret_cast<UCPD_TypeDef *>(0x4000DC00U)
#define UCPD1_S     reinterpret_cast<UCPD_TypeDef *>(0x5000DC00U)

#else
#define UCPD1_NS    ((UCPD_TypeDef *)0x4000DC00U)
#define UCPD1_S     ((UCPD_TypeDef *)0x5000DC00U)
#endif

// CFGR1 Configuration

#define UCPD_CFGR1_UCPDEN               (0x1U<<31U)
#define UCPD_CFGR1_RXDMAEN              (0x1U<<30U)
#define UCPD_CFGR1_TXDMAEN              (0x1U<<29U)
#define UCPD_CFGR1_RXORDSETEN           (0x1FFU<<20U)
#define UCPD_CFGR1_RXORDSETEN_0         (0x1U<<20U)
#define UCPD_CFGR1_PSC_USBPDCLK         (0x7U<<17U)
#define UCPD_CFGR1_PSC_USBPDCLK_0       (0x1U<<17U)
#define UCPD_CFGR1_TRANSWIN             (0x1FU<<11U)
#define UCPD_CFGR1_TRANSWIN_0           (0x1U<<11U)
#define UCPD_CFGR1_IFRGAP               (0x1FU<<6U)
#define UCPD_CFGR1_IFRGAP_0             (0x1U<<6U)
#define UCPD_CFGR1_HBITCLKDIV           (0x3FU<<0U)
#define UCPD_CFGR1_HBITCLKDIV_0         (0x1U<<0U)

// CFGR2 Configuration

#define UCPD_CFGR2_WUPEN                (0x1U<<3U)
#define UCPD_CFGR2_FORCECLK             (0x1U<<2U)
#define UCPD_CFGR2_RXFILT2N3            (0x1U<<1U)
#define UCPD_CFGR2_RXFILTDIS            (0x1U<<0U)

// CFGR3 Configuration

#define UCPD_CFGR3_TRIM2_NG_CC3A0       (0xFU<<25U)
#define UCPD_CFGR3_TRIM2_NG_CC3A0_0     (0x1U<<25U)
#define UCPD_CFGR3_TRIM2_NG_CCRPD       (0xFU<<16U)
#define UCPD_CFGR3_TRIM2_NG_CCRPD_0     (0x1U<<16U)
#define UCPD_CFGR3_TRIM1_NG_CC3A0       (0xFU<<9U)
#define UCPD_CFGR3_TRIM1_NG_CC3A0_0     (0x1U<<9U)
#define UCPD_CFGR3_TRIM1_NG_CCRPD       (0xFU<<0U)
#define UCPD_CFGR3_TRIM1_NG_CCRPD_0     (0x1U<<0U)

// CR Configuration

#define UCPD_CR_CC2TCDIS                (0x1U<<21U)
#define UCPD_CR_CC1TCDIS                (0x1U<<20U)
#define UCPD_CR_RDCH                    (0x1U<<18U)
#define UCPD_CR_FRSTX                   (0x1U<<17U)
#define UCPD_CR_FRSRXEN                 (0x1U<<16U)
#define UCPD_CR_CCENABLE                (0x3U<<10U)
#define UCPD_CR_CCENABLE_0              (0x1U<<10U)
#define UCPD_CR_ANAMODE                 (0x1U<<9U)
#define UCPD_CR_ANASUBMODE              (0x3U<<7U)
#define UCPD_CR_ANASUBMODE_0            (0x1U<<7U)
#define UCPD_CR_PHYCCSEL                (0x1U<<6U)
#define UCPD_CR_PHYRXEN                 (0x1U<<5U)
#define UCPD_CR_RXMODE                  (0x1U<<4U)
#define UCPD_CR_TXHRST                  (0x1U<<3U)
#define UCPD_CR_TXSEND                  (0x1U<<2U)
#define UCPD_CR_TXMODE                  (0x3U<<0U)
#define UCPD_CR_TXMODE_0                (0x1U<<0U)

// IMR Configuration

#define UCPD_IMR_FRSEVTIE               (0x1U<<20U)
#define UCPD_IMR_TYPECEVT2IE            (0x1U<<15U)
#define UCPD_IMR_TYPECEVT1IE            (0x1U<<14U)
#define UCPD_IMR_RXMSGENDIE             (0x1U<<12U)
#define UCPD_IMR_RXOVRIE                (0x1U<<11U)
#define UCPD_IMR_RXHRSTDETIE            (0x1U<<10U)
#define UCPD_IMR_RXORDDETIE             (0x1U<<9U)
#define UCPD_IMR_RXNEIE                 (0x1U<<8U)
#define UCPD_IMR_TXUNDIE                (0x1U<<6U)
#define UCPD_IMR_HRSTSENTIE             (0x1U<<5U)
#define UCPD_IMR_HRSTDISCIE             (0x1U<<4U)
#define UCPD_IMR_TXMSGABTIE             (0x1U<<3U)
#define UCPD_IMR_TXMSGSENTIE            (0x1U<<2U)
#define UCPD_IMR_TXMSGDISCIE            (0x1U<<1U)
#define UCPD_IMR_TXISIE                 (0x1U<<0U)

// SR Configuration

#define UCPD_SR_FRSEVT                  (0x1U<<20U)
#define UCPD_SR_TYPEC_VSTATE_CC2        (0x3U<<18U)
#define UCPD_SR_TYPEC_VSTATE_CC2_0      (0x1U<<18U)
#define UCPD_SR_TYPEC_VSTATE_CC1        (0x3U<<16U)
#define UCPD_SR_TYPEC_VSTATE_CC1_0      (0x1U<<16U)
#define UCPD_SR_TYPECEVT2               (0x1U<<15U)
#define UCPD_SR_TYPECEVT1               (0x1U<<14U)
#define UCPD_SR_RXERR                   (0x1U<<13U)
#define UCPD_SR_RXMSGEND                (0x1U<<12U)
#define UCPD_SR_RXOVR                   (0x1U<<11U)
#define UCPD_SR_RXHRSTDET               (0x1U<<10U)
#define UCPD_SR_RXORDDET                (0x1U<<9U)
#define UCPD_SR_RXNE                    (0x1U<<8U)
#define UCPD_SR_TXUND                   (0x1U<<6U)
#define UCPD_SR_HRSTSENT                (0x1U<<5U)
#define UCPD_SR_HRSTDISC                (0x1U<<4U)
#define UCPD_SR_TXMSGABT                (0x1U<<3U)
#define UCPD_SR_TXMSGSENT               (0x1U<<2U)
#define UCPD_SR_TXMSGDISC               (0x1U<<1U)
#define UCPD_SR_TXIS                    (0x1U<<0U)

// ICR Configuration

#define UCPD_ICR_FRSEVTCF               (0x1U<<20U)
#define UCPD_ICR_TYPECEVT2CF            (0x1U<<15U)
#define UCPD_ICR_TYPECEVT1CF            (0x1U<<14U)
#define UCPD_ICR_RXMSGENDCF             (0x1U<<12U)
#define UCPD_ICR_RXOVRCF                (0x1U<<11U)
#define UCPD_ICR_RXHRSTDETCF            (0x1U<<10U)
#define UCPD_ICR_RXORDDETCF             (0x1U<<9U)
#define UCPD_ICR_TXUNDCF                (0x1U<<6U)
#define UCPD_ICR_HRSTSENTCF             (0x1U<<5U)
#define UCPD_ICR_HRSTDISCCF             (0x1U<<4U)
#define UCPD_ICR_TXMSGABTCF             (0x1U<<3U)
#define UCPD_ICR_TXMSGSENTCF            (0x1U<<2U)
#define UCPD_ICR_TXMSGDISCCF            (0x1U<<1U)

// TX_ORDSET Configuration

#define UCPD_TX_ORDSET_TXORDSET         (0xFFFFFU<<0U)
#define UCPD_TX_ORDSET_TXORDSET_0       (0x1U<<0U)

// TX_PAYSZ Configuration

#define UCPD_TX_PAYSZ_TXPAYSZ           (0x3FFU<<0U)
#define UCPD_TX_PAYSZ_TXPAYSZ_0         (0x1U<<0U)

// TXDR Configuration

#define UCPD_TXDR_TXDATA                (0xFFU<<0U)
#define UCPD_TXDR_TXDATA_0              (0x1U<<0U)

// RX_ORDSET Configuration

#define UCPD_RX_ORDSET_RXSOPKINVALID    (0x7U<<4U)
#define UCPD_RX_ORDSET_RXSOPKINVALID_0  (0x1U<<4U)
#define UCPD_RX_ORDSET_RXSOP3OF4        (0x1U<<3U)
#define UCPD_RX_ORDSET_RXORDSET         (0x7U<<0U)
#define UCPD_RX_ORDSET_RXORDSET_0       (0x1U<<0U)

// RX_PAYSZ Configuration

#define UCPD_RX_PAYSZ_RXPAYSZ           (0x3FFU<<0U)
#define UCPD_RX_PAYSZ_RXPAYSZ_0         (0x1U<<0U)

// RXDR Configuration

#define UCPD_RXDR_RXDATA                (0xFFU<<0U)
#define UCPD_RXDR_RXDATA_0              (0x1U<<0U)

// RX_ORDEXT1 Configuration

#define UCPD_RX_ORDEXT1_RXSOPX1         (0xFFFFFU<<0U)
#define UCPD_RX_ORDEXT1_RXSOPX1_0       (0x1U<<0U)

// RX_ORDEXT2 Configuration

#define UCPD_RX_ORDEXT2_RXSOPX2         (0xFFFFFU<<0U)
#define UCPD_RX_ORDEXT2_RXSOPX2_0       (0x1U<<0U)
