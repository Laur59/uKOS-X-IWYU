/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32N657_rtc.
; ==============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32N657_rtc equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
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
    volatile    uint32_t    PRIVCFGR;
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
#define RTC_NS  reinterpret_cast<RTC_TypeDef *>(0x46004000U)
#define RTC_S   reinterpret_cast<RTC_TypeDef *>(0x56004000U)

#else
#define RTC_NS  ((RTC_TypeDef *)0x46004000U)
#define RTC_S   ((RTC_TypeDef *)0x56004000U)
#endif

// TR Configuration

#define RTC_TR_PM                   (0x1U<<22)
#define RTC_TR_HT                   (0x3U<<20)
#define RTC_TR_HT_0                 (0x1U<<20)
#define RTC_TR_HU                   (0xFU<<16)
#define RTC_TR_HU_0                 (0x1U<<16)
#define RTC_TR_MNT                  (0x7U<<12)
#define RTC_TR_MNT_0                (0x1U<<12)
#define RTC_TR_MNU                  (0xFU<<8)
#define RTC_TR_MNU_0                (0x1U<<8)
#define RTC_TR_ST                   (0x7U<<4)
#define RTC_TR_ST_0                 (0x1U<<4)
#define RTC_TR_SU                   (0xFU<<0)
#define RTC_TR_SU_0                 (0x1U<<0)

#define RTC_TR_PM_B_0X0             (0x0U<<22)
#define RTC_TR_PM_B_0X1             (0x1U<<22)

// DR Configuration

#define RTC_DR_YT                   (0xFU<<20)
#define RTC_DR_YT_0                 (0x1U<<20)
#define RTC_DR_YU                   (0xFU<<16)
#define RTC_DR_YU_0                 (0x1U<<16)
#define RTC_DR_WDU                  (0x7U<<13)
#define RTC_DR_WDU_0                (0x1U<<13)
#define RTC_DR_MT                   (0x1U<<12)
#define RTC_DR_MU                   (0xFU<<8)
#define RTC_DR_MU_0                 (0x1U<<8)
#define RTC_DR_DT                   (0x3U<<4)
#define RTC_DR_DT_0                 (0x1U<<4)
#define RTC_DR_DU                   (0xFU<<0)
#define RTC_DR_DU_0                 (0x1U<<0)

#define RTC_DR_WDU_B_0X0            (0x0U<<13)
#define RTC_DR_WDU_B_0X1            (0x1U<<13)
#define RTC_DR_WDU_B_0X7            (0x7U<<13)

// SSR Configuration

#define RTC_SSR_SS                  (0xFFFFFFFFU<<0)
#define RTC_SSR_SS_0                (0x1U<<0)

// ICSR Configuration

#define RTC_ICSR_RECALPF            (0x1U<<16)
#define RTC_ICSR_BCDU               (0x7U<<10)
#define RTC_ICSR_BCDU_0             (0x1U<<10)
#define RTC_ICSR_BIN                (0x3U<<8)
#define RTC_ICSR_BIN_0              (0x1U<<8)
#define RTC_ICSR_INIT               (0x1U<<7)
#define RTC_ICSR_INITF              (0x1U<<6)
#define RTC_ICSR_RSF                (0x1U<<5)
#define RTC_ICSR_INITS              (0x1U<<4)
#define RTC_ICSR_SHPF               (0x1U<<3)
#define RTC_ICSR_WUTWF              (0x1U<<2)

#define RTC_ICSR_BCDU_B_0X0         (0x0U<<10)
#define RTC_ICSR_BCDU_B_0X1         (0x1U<<10)
#define RTC_ICSR_BCDU_B_0X2         (0x2U<<10)
#define RTC_ICSR_BCDU_B_0X3         (0x3U<<10)
#define RTC_ICSR_BCDU_B_0X4         (0x4U<<10)
#define RTC_ICSR_BCDU_B_0X5         (0x5U<<10)
#define RTC_ICSR_BCDU_B_0X6         (0x6U<<10)
#define RTC_ICSR_BCDU_B_0X7         (0x7U<<10)
#define RTC_ICSR_BIN_B_0X0          (0x0U<<8)
#define RTC_ICSR_BIN_B_0X1          (0x1U<<8)
#define RTC_ICSR_BIN_B_0X2          (0x2U<<8)
#define RTC_ICSR_BIN_B_0X3          (0x3U<<8)
#define RTC_ICSR_INIT_B_0X0         (0x0U<<7)
#define RTC_ICSR_INIT_B_0X1         (0x1U<<7)
#define RTC_ICSR_INITF_B_0X0        (0x0U<<6)
#define RTC_ICSR_INITF_B_0X1        (0x1U<<6)
#define RTC_ICSR_RSF_B_0X0          (0x0U<<5)
#define RTC_ICSR_RSF_B_0X1          (0x1U<<5)
#define RTC_ICSR_INITS_B_0X0        (0x0U<<4)
#define RTC_ICSR_INITS_B_0X1        (0x1U<<4)
#define RTC_ICSR_SHPF_B_0X0         (0x0U<<3)
#define RTC_ICSR_SHPF_B_0X1         (0x1U<<3)
#define RTC_ICSR_WUTWF_B_0X0        (0x0U<<2)
#define RTC_ICSR_WUTWF_B_0X1        (0x1U<<2)

// PRER Configuration

#define RTC_PRER_PREDIV_A           (0x7FU<<16)
#define RTC_PRER_PREDIV_A_0         (0x1U<<16)
#define RTC_PRER_PREDIV_S           (0x7FFFU<<0)
#define RTC_PRER_PREDIV_S_0         (0x1U<<0)

// WUTR Configuration

#define RTC_WUTR_WUTOCLR            (0xFFFFU<<16)
#define RTC_WUTR_WUTOCLR_0          (0x1U<<16)
#define RTC_WUTR_WUT                (0xFFFFU<<0)
#define RTC_WUTR_WUT_0              (0x1U<<0)

// CR Configuration

#define RTC_CR_OUT2EN               (0x1U<<31)
#define RTC_CR_TAMPALRM_TYPE        (0x1U<<30)
#define RTC_CR_TAMPALRM_PU          (0x1U<<29)
#define RTC_CR_ALRBFCLR             (0x1U<<28)
#define RTC_CR_ALRAFCLR             (0x1U<<27)
#define RTC_CR_TAMPOE               (0x1U<<26)
#define RTC_CR_TAMPTS               (0x1U<<25)
#define RTC_CR_ITSE                 (0x1U<<24)
#define RTC_CR_COE                  (0x1U<<23)
#define RTC_CR_OSEL                 (0x3U<<21)
#define RTC_CR_OSEL_0               (0x1U<<21)
#define RTC_CR_POL                  (0x1U<<20)
#define RTC_CR_COSEL                (0x1U<<19)
#define RTC_CR_BKP                  (0x1U<<18)
#define RTC_CR_SUB1H                (0x1U<<17)
#define RTC_CR_ADD1H                (0x1U<<16)
#define RTC_CR_TSIE                 (0x1U<<15)
#define RTC_CR_WUTIE                (0x1U<<14)
#define RTC_CR_ALRBIE               (0x1U<<13)
#define RTC_CR_ALRAIE               (0x1U<<12)
#define RTC_CR_TSE                  (0x1U<<11)
#define RTC_CR_WUTE                 (0x1U<<10)
#define RTC_CR_ALRBE                (0x1U<<9)
#define RTC_CR_ALRAE                (0x1U<<8)
#define RTC_CR_SSRUIE               (0x1U<<7)
#define RTC_CR_FMT                  (0x1U<<6)
#define RTC_CR_BYPSHAD              (0x1U<<5)
#define RTC_CR_REFCKON              (0x1U<<4)
#define RTC_CR_TSEDGE               (0x1U<<3)
#define RTC_CR_WUCKSEL              (0x7U<<0)
#define RTC_CR_WUCKSEL_0            (0x1U<<0)

#define RTC_CR_TAMPALRM_TYPE_B_0X0  (0x0U<<30)
#define RTC_CR_TAMPALRM_TYPE_B_0X1  (0x1U<<30)
#define RTC_CR_TAMPALRM_PU_B_0X0    (0x0U<<29)
#define RTC_CR_TAMPALRM_PU_B_0X1    (0x1U<<29)
#define RTC_CR_ALRBFCLR_B_0X0       (0x0U<<28)
#define RTC_CR_ALRBFCLR_B_0X1       (0x1U<<28)
#define RTC_CR_ALRAFCLR_B_0X0       (0x0U<<27)
#define RTC_CR_ALRAFCLR_B_0X1       (0x1U<<27)
#define RTC_CR_TAMPOE_B_0X0         (0x0U<<26)
#define RTC_CR_TAMPOE_B_0X1         (0x1U<<26)
#define RTC_CR_TAMPTS_B_0X0         (0x0U<<25)
#define RTC_CR_TAMPTS_B_0X1         (0x1U<<25)
#define RTC_CR_ITSE_B_0X0           (0x0U<<24)
#define RTC_CR_ITSE_B_0X1           (0x1U<<24)
#define RTC_CR_COE_B_0X0            (0x0U<<23)
#define RTC_CR_COE_B_0X1            (0x1U<<23)
#define RTC_CR_OSEL_B_0X0           (0x0U<<21)
#define RTC_CR_OSEL_B_0X1           (0x1U<<21)
#define RTC_CR_OSEL_B_0X2           (0x2U<<21)
#define RTC_CR_OSEL_B_0X3           (0x3U<<21)
#define RTC_CR_POL_B_0X0            (0x0U<<20)
#define RTC_CR_POL_B_0X1            (0x1U<<20)
#define RTC_CR_COSEL_B_0X0          (0x0U<<19)
#define RTC_CR_COSEL_B_0X1          (0x1U<<19)
#define RTC_CR_SUB1H_B_0X0          (0x0U<<17)
#define RTC_CR_SUB1H_B_0X1          (0x1U<<17)
#define RTC_CR_ADD1H_B_0X0          (0x0U<<16)
#define RTC_CR_ADD1H_B_0X1          (0x1U<<16)
#define RTC_CR_TSIE_B_0X0           (0x0U<<15)
#define RTC_CR_TSIE_B_0X1           (0x1U<<15)
#define RTC_CR_WUTIE_B_0X0          (0x0U<<14)
#define RTC_CR_WUTIE_B_0X1          (0x1U<<14)
#define RTC_CR_ALRBIE_B_0X0         (0x0U<<13)
#define RTC_CR_ALRBIE_B_0X1         (0x1U<<13)
#define RTC_CR_ALRAIE_B_0X0         (0x0U<<12)
#define RTC_CR_ALRAIE_B_0X1         (0x1U<<12)
#define RTC_CR_TSE_B_0X0            (0x0U<<11)
#define RTC_CR_TSE_B_0X1            (0x1U<<11)
#define RTC_CR_WUTE_B_0X0           (0x0U<<10)
#define RTC_CR_WUTE_B_0X1           (0x1U<<10)
#define RTC_CR_ALRBE_B_0X0          (0x0U<<9)
#define RTC_CR_ALRBE_B_0X1          (0x1U<<9)
#define RTC_CR_ALRAE_B_0X0          (0x0U<<8)
#define RTC_CR_ALRAE_B_0X1          (0x1U<<8)
#define RTC_CR_SSRUIE_B_0X0         (0x0U<<7)
#define RTC_CR_SSRUIE_B_0X1         (0x1U<<7)
#define RTC_CR_FMT_B_0X0            (0x0U<<6)
#define RTC_CR_FMT_B_0X1            (0x1U<<6)
#define RTC_CR_BYPSHAD_B_0X0        (0x0U<<5)
#define RTC_CR_BYPSHAD_B_0X1        (0x1U<<5)
#define RTC_CR_REFCKON_B_0X0        (0x0U<<4)
#define RTC_CR_REFCKON_B_0X1        (0x1U<<4)
#define RTC_CR_TSEDGE_B_0X0         (0x0U<<3)
#define RTC_CR_TSEDGE_B_0X1         (0x1U<<3)
#define RTC_CR_WUCKSEL_B_0X0        (0x0U<<0)
#define RTC_CR_WUCKSEL_B_0X1        (0x1U<<0)
#define RTC_CR_WUCKSEL_B_0X2        (0x2U<<0)
#define RTC_CR_WUCKSEL_B_0X3        (0x3U<<0)

// PRIVCFGR Configuration

#define RTC_PRIVCFGR_PRIV           (0x1U<<15)
#define RTC_PRIVCFGR_INITPRIV       (0x1U<<14)
#define RTC_PRIVCFGR_CALPRIV        (0x1U<<13)
#define RTC_PRIVCFGR_TSPRIV         (0x1U<<3)
#define RTC_PRIVCFGR_WUTPRIV        (0x1U<<2)
#define RTC_PRIVCFGR_ALRBPRIV       (0x1U<<1)
#define RTC_PRIVCFGR_ALRAPRIV       (0x1U<<0)

#define RTC_PRIVCFGR_PRIV_B_0X0     (0x0U<<15)
#define RTC_PRIVCFGR_PRIV_B_0X1     (0x1U<<15)
#define RTC_PRIVCFGR_INITPRIV_B_0X0 (0x0U<<14)
#define RTC_PRIVCFGR_INITPRIV_B_0X1 (0x1U<<14)
#define RTC_PRIVCFGR_CALPRIV_B_0X0  (0x0U<<13)
#define RTC_PRIVCFGR_CALPRIV_B_0X1  (0x1U<<13)
#define RTC_PRIVCFGR_TSPRIV_B_0X0   (0x0U<<3)
#define RTC_PRIVCFGR_TSPRIV_B_0X1   (0x1U<<3)
#define RTC_PRIVCFGR_WUTPRIV_B_0X0  (0x0U<<2)
#define RTC_PRIVCFGR_WUTPRIV_B_0X1  (0x1U<<2)
#define RTC_PRIVCFGR_ALRBPRIV_B_0X0 (0x0U<<1)
#define RTC_PRIVCFGR_ALRBPRIV_B_0X1 (0x1U<<1)
#define RTC_PRIVCFGR_ALRAPRIV_B_0X0 (0x0U<<0)
#define RTC_PRIVCFGR_ALRAPRIV_B_0X1 (0x1U<<0)

// SECCFGR Configuration

#define RTC_SECCFGR_SEC             (0x1U<<15)
#define RTC_SECCFGR_INITSEC         (0x1U<<14)
#define RTC_SECCFGR_CALSEC          (0x1U<<13)
#define RTC_SECCFGR_TSSEC           (0x1U<<3)
#define RTC_SECCFGR_WUTSEC          (0x1U<<2)
#define RTC_SECCFGR_ALRBSEC         (0x1U<<1)
#define RTC_SECCFGR_ALRASEC         (0x1U<<0)

#define RTC_SECCFGR_SEC_B_0X0       (0x0U<<15)
#define RTC_SECCFGR_SEC_B_0X1       (0x1U<<15)
#define RTC_SECCFGR_INITSEC_B_0X0   (0x0U<<14)
#define RTC_SECCFGR_INITSEC_B_0X1   (0x1U<<14)
#define RTC_SECCFGR_CALSEC_B_0X0    (0x0U<<13)
#define RTC_SECCFGR_CALSEC_B_0X1    (0x1U<<13)
#define RTC_SECCFGR_TSSEC_B_0X0     (0x0U<<3)
#define RTC_SECCFGR_TSSEC_B_0X1     (0x1U<<3)
#define RTC_SECCFGR_WUTSEC_B_0X0    (0x0U<<2)
#define RTC_SECCFGR_WUTSEC_B_0X1    (0x1U<<2)
#define RTC_SECCFGR_ALRBSEC_B_0X0   (0x0U<<1)
#define RTC_SECCFGR_ALRBSEC_B_0X1   (0x1U<<1)
#define RTC_SECCFGR_ALRASEC_B_0X0   (0x0U<<0)
#define RTC_SECCFGR_ALRASEC_B_0X1   (0x1U<<0)

// WPR Configuration

#define RTC_WPR_KEY                 (0xFFU<<0)
#define RTC_WPR_KEY_0               (0x1U<<0)

// CALR Configuration

#define RTC_CALR_CALP               (0x1U<<15)
#define RTC_CALR_CALW8              (0x1U<<14)
#define RTC_CALR_CALW16             (0x1U<<13)
#define RTC_CALR_LPCAL              (0x1U<<12)
#define RTC_CALR_CALM               (0x1FFU<<0)
#define RTC_CALR_CALM_0             (0x1U<<0)

#define RTC_CALR_CALP_B_0X0         (0x0U<<15)
#define RTC_CALR_CALP_B_0X1         (0x1U<<15)
#define RTC_CALR_LPCAL_B_0X0        (0x0U<<12)
#define RTC_CALR_LPCAL_B_0X1        (0x1U<<12)

// SHIFTR Configuration

#define RTC_SHIFTR_ADD1S            (0x1U<<31)
#define RTC_SHIFTR_SUBFS            (0x7FFFU<<0)
#define RTC_SHIFTR_SUBFS_0          (0x1U<<0)

#define RTC_SHIFTR_ADD1S_B_0X0      (0x0U<<31)
#define RTC_SHIFTR_ADD1S_B_0X1      (0x1U<<31)

// TSTR Configuration

#define RTC_TSTR_PM                 (0x1U<<22)
#define RTC_TSTR_HT                 (0x3U<<20)
#define RTC_TSTR_HT_0               (0x1U<<20)
#define RTC_TSTR_HU                 (0xFU<<16)
#define RTC_TSTR_HU_0               (0x1U<<16)
#define RTC_TSTR_MNT                (0x7U<<12)
#define RTC_TSTR_MNT_0              (0x1U<<12)
#define RTC_TSTR_MNU                (0xFU<<8)
#define RTC_TSTR_MNU_0              (0x1U<<8)
#define RTC_TSTR_ST                 (0x7U<<4)
#define RTC_TSTR_ST_0               (0x1U<<4)
#define RTC_TSTR_SU                 (0xFU<<0)
#define RTC_TSTR_SU_0               (0x1U<<0)

#define RTC_TSTR_PM_B_0X0           (0x0U<<22)
#define RTC_TSTR_PM_B_0X1           (0x1U<<22)

// TSDR Configuration

#define RTC_TSDR_WDU                (0x7U<<13)
#define RTC_TSDR_WDU_0              (0x1U<<13)
#define RTC_TSDR_MT                 (0x1U<<12)
#define RTC_TSDR_MU                 (0xFU<<8)
#define RTC_TSDR_MU_0               (0x1U<<8)
#define RTC_TSDR_DT                 (0x3U<<4)
#define RTC_TSDR_DT_0               (0x1U<<4)
#define RTC_TSDR_DU                 (0xFU<<0)
#define RTC_TSDR_DU_0               (0x1U<<0)

// TSSSR Configuration

#define RTC_TSSSR_SS                (0xFFFFFFFFU<<0)
#define RTC_TSSSR_SS_0              (0x1U<<0)

// ALRMAR Configuration

#define RTC_ALRMAR_MSK4             (0x1U<<31)
#define RTC_ALRMAR_WDSEL            (0x1U<<30)
#define RTC_ALRMAR_DT               (0x3U<<28)
#define RTC_ALRMAR_DT_0             (0x1U<<28)
#define RTC_ALRMAR_DU               (0xFU<<24)
#define RTC_ALRMAR_DU_0             (0x1U<<24)
#define RTC_ALRMAR_MSK3             (0x1U<<23)
#define RTC_ALRMAR_PM               (0x1U<<22)
#define RTC_ALRMAR_HT               (0x3U<<20)
#define RTC_ALRMAR_HT_0             (0x1U<<20)
#define RTC_ALRMAR_HU               (0xFU<<16)
#define RTC_ALRMAR_HU_0             (0x1U<<16)
#define RTC_ALRMAR_MSK2             (0x1U<<15)
#define RTC_ALRMAR_MNT              (0x7U<<12)
#define RTC_ALRMAR_MNT_0            (0x1U<<12)
#define RTC_ALRMAR_MNU              (0xFU<<8)
#define RTC_ALRMAR_MNU_0            (0x1U<<8)
#define RTC_ALRMAR_MSK1             (0x1U<<7)
#define RTC_ALRMAR_ST               (0x7U<<4)
#define RTC_ALRMAR_ST_0             (0x1U<<4)
#define RTC_ALRMAR_SU               (0xFU<<0)
#define RTC_ALRMAR_SU_0             (0x1U<<0)

#define RTC_ALRMAR_MSK4_B_0X0       (0x0U<<31)
#define RTC_ALRMAR_MSK4_B_0X1       (0x1U<<31)
#define RTC_ALRMAR_WDSEL_B_0X0      (0x0U<<30)
#define RTC_ALRMAR_WDSEL_B_0X1      (0x1U<<30)
#define RTC_ALRMAR_MSK3_B_0X0       (0x0U<<23)
#define RTC_ALRMAR_MSK3_B_0X1       (0x1U<<23)
#define RTC_ALRMAR_PM_B_0X0         (0x0U<<22)
#define RTC_ALRMAR_PM_B_0X1         (0x1U<<22)
#define RTC_ALRMAR_MSK2_B_0X0       (0x0U<<15)
#define RTC_ALRMAR_MSK2_B_0X1       (0x1U<<15)
#define RTC_ALRMAR_MSK1_B_0X0       (0x0U<<7)
#define RTC_ALRMAR_MSK1_B_0X1       (0x1U<<7)

// ALRMASSR Configuration

#define RTC_ALRMASSR_SSCLR          (0x1U<<31)
#define RTC_ALRMASSR_MASKSS         (0x3FU<<24)
#define RTC_ALRMASSR_MASKSS_0       (0x1U<<24)
#define RTC_ALRMASSR_SS             (0x7FFFU<<0)
#define RTC_ALRMASSR_SS_0           (0x1U<<0)

#define RTC_ALRMASSR_SSCLR_B_0X0    (0x0U<<31)
#define RTC_ALRMASSR_SSCLR_B_0X1    (0x1U<<31)
#define RTC_ALRMASSR_MASKSS_B_0X0   (0x0U<<24)
#define RTC_ALRMASSR_MASKSS_B_0X1   (0x1U<<24)

// ALRMBR Configuration

#define RTC_ALRMBR_MSK4             (0x1U<<31)
#define RTC_ALRMBR_WDSEL            (0x1U<<30)
#define RTC_ALRMBR_DT               (0x3U<<28)
#define RTC_ALRMBR_DT_0             (0x1U<<28)
#define RTC_ALRMBR_DU               (0xFU<<24)
#define RTC_ALRMBR_DU_0             (0x1U<<24)
#define RTC_ALRMBR_MSK3             (0x1U<<23)
#define RTC_ALRMBR_PM               (0x1U<<22)
#define RTC_ALRMBR_HT               (0x3U<<20)
#define RTC_ALRMBR_HT_0             (0x1U<<20)
#define RTC_ALRMBR_HU               (0xFU<<16)
#define RTC_ALRMBR_HU_0             (0x1U<<16)
#define RTC_ALRMBR_MSK2             (0x1U<<15)
#define RTC_ALRMBR_MNT              (0x7U<<12)
#define RTC_ALRMBR_MNT_0            (0x1U<<12)
#define RTC_ALRMBR_MNU              (0xFU<<8)
#define RTC_ALRMBR_MNU_0            (0x1U<<8)
#define RTC_ALRMBR_MSK1             (0x1U<<7)
#define RTC_ALRMBR_ST               (0x7U<<4)
#define RTC_ALRMBR_ST_0             (0x1U<<4)
#define RTC_ALRMBR_SU               (0xFU<<0)
#define RTC_ALRMBR_SU_0             (0x1U<<0)

#define RTC_ALRMBR_MSK4_B_0X0       (0x0U<<31)
#define RTC_ALRMBR_MSK4_B_0X1       (0x1U<<31)
#define RTC_ALRMBR_WDSEL_B_0X0      (0x0U<<30)
#define RTC_ALRMBR_WDSEL_B_0X1      (0x1U<<30)
#define RTC_ALRMBR_MSK3_B_0X0       (0x0U<<23)
#define RTC_ALRMBR_MSK3_B_0X1       (0x1U<<23)
#define RTC_ALRMBR_PM_B_0X0         (0x0U<<22)
#define RTC_ALRMBR_PM_B_0X1         (0x1U<<22)
#define RTC_ALRMBR_MSK2_B_0X0       (0x0U<<15)
#define RTC_ALRMBR_MSK2_B_0X1       (0x1U<<15)
#define RTC_ALRMBR_MSK1_B_0X0       (0x0U<<7)
#define RTC_ALRMBR_MSK1_B_0X1       (0x1U<<7)

// ALRMBSSR Configuration

#define RTC_ALRMBSSR_SSCLR          (0x1U<<31)
#define RTC_ALRMBSSR_MASKSS         (0x3FU<<24)
#define RTC_ALRMBSSR_MASKSS_0       (0x1U<<24)
#define RTC_ALRMBSSR_SS             (0x7FFFU<<0)
#define RTC_ALRMBSSR_SS_0           (0x1U<<0)

#define RTC_ALRMBSSR_SSCLR_B_0X0    (0x0U<<31)
#define RTC_ALRMBSSR_SSCLR_B_0X1    (0x1U<<31)
#define RTC_ALRMBSSR_MASKSS_B_0X0   (0x0U<<24)
#define RTC_ALRMBSSR_MASKSS_B_0X1   (0x1U<<24)

// SR Configuration

#define RTC_SR_SSRUF                (0x1U<<6)
#define RTC_SR_ITSF                 (0x1U<<5)
#define RTC_SR_TSOVF                (0x1U<<4)
#define RTC_SR_TSF                  (0x1U<<3)
#define RTC_SR_WUTF                 (0x1U<<2)
#define RTC_SR_ALRBF                (0x1U<<1)
#define RTC_SR_ALRAF                (0x1U<<0)

// MISR Configuration

#define RTC_MISR_SSRUMF             (0x1U<<6)
#define RTC_MISR_ITSMF              (0x1U<<5)
#define RTC_MISR_TSOVMF             (0x1U<<4)
#define RTC_MISR_TSMF               (0x1U<<3)
#define RTC_MISR_WUTMF              (0x1U<<2)
#define RTC_MISR_ALRBMF             (0x1U<<1)
#define RTC_MISR_ALRAMF             (0x1U<<0)

// SMISR Configuration

#define RTC_SMISR_SSRUMF            (0x1U<<6)
#define RTC_SMISR_ITSMF             (0x1U<<5)
#define RTC_SMISR_TSOVMF            (0x1U<<4)
#define RTC_SMISR_TSMF              (0x1U<<3)
#define RTC_SMISR_WUTMF             (0x1U<<2)
#define RTC_SMISR_ALRBMF            (0x1U<<1)
#define RTC_SMISR_ALRAMF            (0x1U<<0)

// SCR Configuration

#define RTC_SCR_CSSRUF              (0x1U<<6)
#define RTC_SCR_CITSF               (0x1U<<5)
#define RTC_SCR_CTSOVF              (0x1U<<4)
#define RTC_SCR_CTSF                (0x1U<<3)
#define RTC_SCR_CWUTF               (0x1U<<2)
#define RTC_SCR_CALRBF              (0x1U<<1)
#define RTC_SCR_CALRAF              (0x1U<<0)

// ALRABINR Configuration

#define RTC_ALRABINR_SS             (0xFFFFFFFFU<<0)
#define RTC_ALRABINR_SS_0           (0x1U<<0)

// ALRBBINR Configuration

#define RTC_ALRBBINR_SS             (0xFFFFFFFFU<<0)
#define RTC_ALRBBINR_SS_0           (0x1U<<0)
