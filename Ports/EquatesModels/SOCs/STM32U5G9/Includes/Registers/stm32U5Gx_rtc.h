/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_rtc equates.
 */

#pragma once

#include    <stdint.h>

// RTC address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    TR;
    volatile    uint32_t    DR;
    volatile    uint32_t    SSR;
    volatile    uint32_t    ICSR;
    volatile    uint32_t    PRER;
    volatile    uint32_t    WUTR;
    volatile    uint32_t    CR;
    volatile    uint32_t    PRIVCR;
    volatile    uint32_t    SECCFGR;
    volatile    uint32_t    WPR;
    volatile    uint32_t    CALR;
    volatile    uint32_t    SHIFTR;
    volatile    uint32_t    TSTR;
    volatile    uint32_t    TSDR;
    volatile    uint32_t    TSSSR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    ALRMAR;
    volatile    uint32_t    ALRMASSR;
    volatile    uint32_t    ALRMBR;
    volatile    uint32_t    ALRMBSSR;
    volatile    uint32_t    SR;
    volatile    uint32_t    MISR;
    volatile    uint32_t    SMISR;
    volatile    uint32_t    SCR;
    volatile    uint32_t    RESERVED1[4];
    volatile    uint32_t    ALRABINR;
    volatile    uint32_t    ALRBBINR;
} RTC_TypeDef;

#ifdef __cplusplus
#define RTC_NS  reinterpret_cast<RTC_TypeDef *>(0x46007800U)
#define RTC_S   reinterpret_cast<RTC_TypeDef *>(0x56007800U)

#else
#define RTC_NS  ((RTC_TypeDef *)0x46007800U)
#define RTC_S   ((RTC_TypeDef *)0x56007800U)
#endif

// TR Configuration

#define RTC_TR_SU               (0xFU<<0U)
#define RTC_TR_SU_0             (0x1U<<0U)
#define RTC_TR_ST               (0x7U<<4U)
#define RTC_TR_ST_0             (0x1U<<4U)
#define RTC_TR_MNU              (0xFU<<8U)
#define RTC_TR_MNU_0            (0x1U<<8U)
#define RTC_TR_MNT              (0x7U<<12U)
#define RTC_TR_MNT_0            (0x1U<<12U)
#define RTC_TR_HU               (0xFU<<16U)
#define RTC_TR_HU_0             (0x1U<<16U)
#define RTC_TR_HT               (0x3U<<20U)
#define RTC_TR_HT_0             (0x1U<<20U)
#define RTC_TR_PM               (0x1U<<22U)

// DR Configuration

#define RTC_DR_DU               (0xFU<<0U)
#define RTC_DR_DU_0             (0x1U<<0U)
#define RTC_DR_DT               (0x3U<<4U)
#define RTC_DR_DT_0             (0x1U<<4U)
#define RTC_DR_MU               (0xFU<<8U)
#define RTC_DR_MU_0             (0x1U<<8U)
#define RTC_DR_MT               (0x1U<<12U)
#define RTC_DR_WDU              (0x7U<<13U)
#define RTC_DR_WDU_0            (0x1U<<13U)
#define RTC_DR_YU               (0xFU<<16U)
#define RTC_DR_YU_0             (0x1U<<16U)
#define RTC_DR_YT               (0xFU<<20U)
#define RTC_DR_YT_0             (0x1U<<20U)

// SSR Configuration

#define RTC_SSR_SS              (0xFFFFFFFFU<<0U)
#define RTC_SSR_SS_0            (0x1U<<0U)

// ICSR Configuration

#define RTC_ICSR_RECALPF        (0x1U<<16U)
#define RTC_ICSR_BCDU           (0x7U<<10U)
#define RTC_ICSR_BCDU_0         (0x1U<<10U)
#define RTC_ICSR_BIN            (0x3U<<8U)
#define RTC_ICSR_BIN_0          (0x1U<<8U)
#define RTC_ICSR_INIT           (0x1U<<7U)
#define RTC_ICSR_INITF          (0x1U<<6U)
#define RTC_ICSR_RSF            (0x1U<<5U)
#define RTC_ICSR_INITS          (0x1U<<4U)
#define RTC_ICSR_SHPF           (0x1U<<3U)
#define RTC_ICSR_WUTWF          (0x1U<<2U)

// PRER Configuration

#define RTC_PRER_PREDIV_S       (0x7FFFU<<0U)
#define RTC_PRER_PREDIV_S_0     (0x1U<<0U)
#define RTC_PRER_PREDIV_A       (0x7FU<<16U)
#define RTC_PRER_PREDIV_A_0     (0x1U<<16U)

// WUTR Configuration

#define RTC_WUTR_WUTOCLR        (0xFFFFU<<16U)
#define RTC_WUTR_WUTOCLR_0      (0x1U<<16U)
#define RTC_WUTR_WUT            (0xFFFFU<<0U)
#define RTC_WUTR_WUT_0          (0x1U<<0U)

// CR Configuration

#define RTC_CR_OUT2EN           (0x1U<<31U)
#define RTC_CR_TAMPALRM_TYPE    (0x1U<<30U)
#define RTC_CR_TAMPALRM_PU      (0x1U<<29U)
#define RTC_CR_ALRBFCLR         (0x1U<<28U)
#define RTC_CR_ALRAFCLR         (0x1U<<27U)
#define RTC_CR_TAMPOE           (0x1U<<26U)
#define RTC_CR_TAMPTS           (0x1U<<25U)
#define RTC_CR_ITSE             (0x1U<<24U)
#define RTC_CR_COE              (0x1U<<23U)
#define RTC_CR_OSEL             (0x3U<<21U)
#define RTC_CR_OSEL_0           (0x1U<<21U)
#define RTC_CR_POL              (0x1U<<20U)
#define RTC_CR_COSEL            (0x1U<<19U)
#define RTC_CR_BKP              (0x1U<<18U)
#define RTC_CR_SUB1H            (0x1U<<17U)
#define RTC_CR_ADD1H            (0x1U<<16U)
#define RTC_CR_TSIE             (0x1U<<15U)
#define RTC_CR_WUTIE            (0x1U<<14U)
#define RTC_CR_ALRBIE           (0x1U<<13U)
#define RTC_CR_ALRAIE           (0x1U<<12U)
#define RTC_CR_TSE              (0x1U<<11U)
#define RTC_CR_WUTE             (0x1U<<10U)
#define RTC_CR_ALRBE            (0x1U<<9U)
#define RTC_CR_ALRAE            (0x1U<<8U)
#define RTC_CR_SSRUIE           (0x1U<<7U)
#define RTC_CR_FMT              (0x1U<<6U)
#define RTC_CR_BYPSHAD          (0x1U<<5U)
#define RTC_CR_REFCKON          (0x1U<<4U)
#define RTC_CR_TSEDGE           (0x1U<<3U)
#define RTC_CR_WUCKSEL          (0x7U<<0U)
#define RTC_CR_WUCKSEL_0        (0x1U<<0U)

// PRIVCR Configuration

#define RTC_PRIVCR_ALRAPRIV     (0x1U<<0U)
#define RTC_PRIVCR_ALRBPRIV     (0x1U<<1U)
#define RTC_PRIVCR_WUTPRIV      (0x1U<<2U)
#define RTC_PRIVCR_TSPRIV       (0x1U<<3U)
#define RTC_PRIVCR_CALPRIV      (0x1U<<13U)
#define RTC_PRIVCR_INITPRIV     (0x1U<<14U)
#define RTC_PRIVCR_PRIV         (0x1U<<15U)

// SECCFGR Configuration

#define RTC_SECCFGR_ALRASEC     (0x1U<<0U)
#define RTC_SECCFGR_ALRBSEC     (0x1U<<1U)
#define RTC_SECCFGR_WUTSEC      (0x1U<<2U)
#define RTC_SECCFGR_TSSEC       (0x1U<<3U)
#define RTC_SECCFGR_CALSEC      (0x1U<<13U)
#define RTC_SECCFGR_INITSEC     (0x1U<<14U)
#define RTC_SECCFGR_SEC         (0x1U<<15U)

// WPR Configuration

#define RTC_WPR_KEY             (0xFFU<<0U)
#define RTC_WPR_KEY_0           (0x1U<<0U)

// CALR Configuration

#define RTC_CALR_CALM           (0x1FFU<<0U)
#define RTC_CALR_CALM_0         (0x1U<<0U)
#define RTC_CALR_LPCAL          (0x1U<<12U)
#define RTC_CALR_CALW16         (0x1U<<13U)
#define RTC_CALR_CALW8          (0x1U<<14U)
#define RTC_CALR_CALP           (0x1U<<15U)

// SHIFTR Configuration

#define RTC_SHIFTR_SUBFS        (0x7FFFU<<0U)
#define RTC_SHIFTR_SUBFS_0      (0x1U<<0U)
#define RTC_SHIFTR_ADD1S        (0x1U<<31U)

// TSTR Configuration

#define RTC_TSTR_PM             (0x1U<<22U)
#define RTC_TSTR_HT             (0x3U<<20U)
#define RTC_TSTR_HT_0           (0x1U<<20U)
#define RTC_TSTR_HU             (0xFU<<16U)
#define RTC_TSTR_HU_0           (0x1U<<16U)
#define RTC_TSTR_MNT            (0x7U<<12U)
#define RTC_TSTR_MNT_0          (0x1U<<12U)
#define RTC_TSTR_MNU            (0xFU<<8U)
#define RTC_TSTR_MNU_0          (0x1U<<8U)
#define RTC_TSTR_ST             (0x7U<<4U)
#define RTC_TSTR_ST_0           (0x1U<<4U)
#define RTC_TSTR_SU             (0xFU<<0U)
#define RTC_TSTR_SU_0           (0x1U<<0U)

// TSDR Configuration

#define RTC_TSDR_DU             (0xFU<<0U)
#define RTC_TSDR_DU_0           (0x1U<<0U)
#define RTC_TSDR_DT             (0x3U<<4U)
#define RTC_TSDR_DT_0           (0x1U<<4U)
#define RTC_TSDR_MU             (0xFU<<8U)
#define RTC_TSDR_MU_0           (0x1U<<8U)
#define RTC_TSDR_MT             (0x1U<<12U)
#define RTC_TSDR_WDU            (0x7U<<13U)
#define RTC_TSDR_WDU_0          (0x1U<<13U)

// TSSSR Configuration

#define RTC_TSSSR_SS            (0xFFFFFFFFU<<0U)
#define RTC_TSSSR_SS_0          (0x1U<<0U)

// ALRMAR Configuration

#define RTC_ALRMAR_SU           (0xFU<<0U)
#define RTC_ALRMAR_SU_0         (0x1U<<0U)
#define RTC_ALRMAR_ST           (0x7U<<4U)
#define RTC_ALRMAR_ST_0         (0x1U<<4U)
#define RTC_ALRMAR_MSK1         (0x1U<<7U)
#define RTC_ALRMAR_MNU          (0xFU<<8U)
#define RTC_ALRMAR_MNU_0        (0x1U<<8U)
#define RTC_ALRMAR_MNT          (0x7U<<12U)
#define RTC_ALRMAR_MNT_0        (0x1U<<12U)
#define RTC_ALRMAR_MSK2         (0x1U<<15U)
#define RTC_ALRMAR_HU           (0xFU<<16U)
#define RTC_ALRMAR_HU_0         (0x1U<<16U)
#define RTC_ALRMAR_HT           (0x3U<<20U)
#define RTC_ALRMAR_HT_0         (0x1U<<20U)
#define RTC_ALRMAR_PM           (0x1U<<22U)
#define RTC_ALRMAR_MSK3         (0x1U<<23U)
#define RTC_ALRMAR_DU           (0xFU<<24U)
#define RTC_ALRMAR_DU_0         (0x1U<<24U)
#define RTC_ALRMAR_DT           (0x3U<<28U)
#define RTC_ALRMAR_DT_0         (0x1U<<28U)
#define RTC_ALRMAR_WDSEL        (0x1U<<30U)
#define RTC_ALRMAR_MSK4         (0x1U<<31U)

// ALRMASSR Configuration

#define RTC_ALRMASSR_SS         (0x7FFFU<<0U)
#define RTC_ALRMASSR_SS_0       (0x1U<<0U)
#define RTC_ALRMASSR_MASKSS     (0x3FU<<24U)
#define RTC_ALRMASSR_MASKSS_0   (0x1U<<24U)
#define RTC_ALRMASSR_SSCLR      (0x1U<<31U)

// ALRMBR Configuration

#define RTC_ALRMBR_SU           (0xFU<<0U)
#define RTC_ALRMBR_SU_0         (0x1U<<0U)
#define RTC_ALRMBR_ST           (0x7U<<4U)
#define RTC_ALRMBR_ST_0         (0x1U<<4U)
#define RTC_ALRMBR_MSK1         (0x1U<<7U)
#define RTC_ALRMBR_MNU          (0xFU<<8U)
#define RTC_ALRMBR_MNU_0        (0x1U<<8U)
#define RTC_ALRMBR_MNT          (0x7U<<12U)
#define RTC_ALRMBR_MNT_0        (0x1U<<12U)
#define RTC_ALRMBR_MSK2         (0x1U<<15U)
#define RTC_ALRMBR_HU           (0xFU<<16U)
#define RTC_ALRMBR_HU_0         (0x1U<<16U)
#define RTC_ALRMBR_HT           (0x3U<<20U)
#define RTC_ALRMBR_HT_0         (0x1U<<20U)
#define RTC_ALRMBR_PM           (0x1U<<22U)
#define RTC_ALRMBR_MSK3         (0x1U<<23U)
#define RTC_ALRMBR_DU           (0xFU<<24U)
#define RTC_ALRMBR_DU_0         (0x1U<<24U)
#define RTC_ALRMBR_DT           (0x3U<<28U)
#define RTC_ALRMBR_DT_0         (0x1U<<28U)
#define RTC_ALRMBR_WDSEL        (0x1U<<30U)
#define RTC_ALRMBR_MSK4         (0x1U<<31U)

// ALRMBSSR Configuration

#define RTC_ALRMBSSR_SS         (0x7FFFU<<0U)
#define RTC_ALRMBSSR_SS_0       (0x1U<<0U)
#define RTC_ALRMBSSR_MASKSS     (0x3FU<<24U)
#define RTC_ALRMBSSR_MASKSS_0   (0x1U<<24U)
#define RTC_ALRMBSSR_SSCLR      (0x1U<<31U)

// SR Configuration

#define RTC_SR_SSRUF            (0x1U<<6U)
#define RTC_SR_ITSF             (0x1U<<5U)
#define RTC_SR_TSOVF            (0x1U<<4U)
#define RTC_SR_TSF              (0x1U<<3U)
#define RTC_SR_WUTF             (0x1U<<2U)
#define RTC_SR_ALRBF            (0x1U<<1U)
#define RTC_SR_ALRAF            (0x1U<<0U)

// MISR Configuration

#define RTC_MISR_SSRUMF         (0x1U<<6U)
#define RTC_MISR_ITSMF          (0x1U<<5U)
#define RTC_MISR_TSOVMF         (0x1U<<4U)
#define RTC_MISR_TSMF           (0x1U<<3U)
#define RTC_MISR_WUTMF          (0x1U<<2U)
#define RTC_MISR_ALRBMF         (0x1U<<1U)
#define RTC_MISR_ALRAMF         (0x1U<<0U)

// SMISR Configuration

#define RTC_SMISR_SSRUMF        (0x1U<<6U)
#define RTC_SMISR_ITSMF         (0x1U<<5U)
#define RTC_SMISR_TSOVMF        (0x1U<<4U)
#define RTC_SMISR_TSMF          (0x1U<<3U)
#define RTC_SMISR_WUTMF         (0x1U<<2U)
#define RTC_SMISR_ALRBMF        (0x1U<<1U)
#define RTC_SMISR_ALRAMF        (0x1U<<0U)

// SCR Configuration

#define RTC_SCR_CSSRUF          (0x1U<<6U)
#define RTC_SCR_CITSF           (0x1U<<5U)
#define RTC_SCR_CTSOVF          (0x1U<<4U)
#define RTC_SCR_CTSF            (0x1U<<3U)
#define RTC_SCR_CWUTF           (0x1U<<2U)
#define RTC_SCR_CALRBF          (0x1U<<1U)
#define RTC_SCR_CALRAF          (0x1U<<0U)

// ALRABINR Configuration

#define RTC_ALRABINR_SS         (0xFFFFFFFFU<<0U)
#define RTC_ALRABINR_SS_0       (0x1U<<0U)

// ALRBBINR Configuration

#define RTC_ALRBBINR_SS         (0xFFFFFFFFU<<0U)
#define RTC_ALRBBINR_SS_0       (0x1U<<0U)
