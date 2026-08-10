/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_ethernet_mac equates.
 */

#pragma once

#include    <stdint.h>

// ETHERNET_MAC address definitions
// --------------------------------

typedef struct {
    volatile    uint32_t    MACCR;
    volatile    uint32_t    MACFFR;
    volatile    uint32_t    MACHTHR;
    volatile    uint32_t    MACHTLR;
    volatile    uint32_t    MACMIIAR;
    volatile    uint32_t    MACMIIDR;
    volatile    uint32_t    MACFCR;
    volatile    uint32_t    MACVLANTR;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    MACRWUFFR;
    volatile    uint32_t    MACPMTCSR;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    MACDBGR;
    volatile    uint32_t    MACSR;
    volatile    uint32_t    MACIMR;
    volatile    uint32_t    MACA0HR;
    volatile    uint32_t    MACA0LR;
    volatile    uint32_t    MACA1HR;
    volatile    uint32_t    MACA1LR;
    volatile    uint32_t    MACA2HR;
    volatile    uint32_t    MACA2LR;
    volatile    uint32_t    MACA3HR;
    volatile    uint32_t    MACA3LR;
} ETHERNET_MAC_TypeDef;

#ifdef __cplusplus
#define ETHERNET_MAC    reinterpret_cast<ETHERNET_MAC_TypeDef *>(0x40028000U)

#else
#define ETHERNET_MAC    ((ETHERNET_MAC_TypeDef *)0x40028000U)
#endif

// MACCR Configuration

#define ETHERNET_MAC_MACCR_CSTF         (0x1U<<25U)
#define ETHERNET_MAC_MACCR_WD           (0x1U<<23U)
#define ETHERNET_MAC_MACCR_JD           (0x1U<<22U)
#define ETHERNET_MAC_MACCR_IFG          (0x7U<<17U)
#define ETHERNET_MAC_MACCR_IFG_0        (0x1U<<17U)
#define ETHERNET_MAC_MACCR_CSD          (0x1U<<16U)
#define ETHERNET_MAC_MACCR_FES          (0x1U<<14U)
#define ETHERNET_MAC_MACCR_ROD          (0x1U<<13U)
#define ETHERNET_MAC_MACCR_LM           (0x1U<<12U)
#define ETHERNET_MAC_MACCR_DM           (0x1U<<11U)
#define ETHERNET_MAC_MACCR_IPCO         (0x1U<<10U)
#define ETHERNET_MAC_MACCR_RD           (0x1U<<9U)
#define ETHERNET_MAC_MACCR_APCS         (0x1U<<7U)
#define ETHERNET_MAC_MACCR_BL           (0x3U<<5U)
#define ETHERNET_MAC_MACCR_BL_0         (0x1U<<5U)
#define ETHERNET_MAC_MACCR_DC           (0x1U<<4U)
#define ETHERNET_MAC_MACCR_TE           (0x1U<<3U)
#define ETHERNET_MAC_MACCR_RE           (0x1U<<2U)

// MACFFR Configuration

#define ETHERNET_MAC_MACFFR_RA          (0x1U<<31U)
#define ETHERNET_MAC_MACFFR_HPF         (0x1U<<10U)
#define ETHERNET_MAC_MACFFR_SAF         (0x1U<<9U)
#define ETHERNET_MAC_MACFFR_SAIF        (0x1U<<8U)
#define ETHERNET_MAC_MACFFR_PCF         (0x1U<<6U)
#define ETHERNET_MAC_MACFFR_BFD         (0x1U<<5U)
#define ETHERNET_MAC_MACFFR_PAM         (0x1U<<4U)
#define ETHERNET_MAC_MACFFR_DAIF        (0x1U<<3U)
#define ETHERNET_MAC_MACFFR_HM          (0x1U<<2U)
#define ETHERNET_MAC_MACFFR_HU          (0x1U<<1U)
#define ETHERNET_MAC_MACFFR_PM          (0x1U<<0U)

// MACHTHR Configuration

#define ETHERNET_MAC_MACHTHR_HTH        (0xFFFFFFFFU<<0U)
#define ETHERNET_MAC_MACHTHR_HTH_0      (0x1U<<0U)

// MACHTLR Configuration

#define ETHERNET_MAC_MACHTLR_HTL        (0xFFFFFFFFU<<0U)
#define ETHERNET_MAC_MACHTLR_HTL_0      (0x1U<<0U)

// MACMIIAR Configuration

#define ETHERNET_MAC_MACMIIAR_PA        (0x1FU<<11U)
#define ETHERNET_MAC_MACMIIAR_PA_0      (0x1U<<11U)
#define ETHERNET_MAC_MACMIIAR_MR        (0x1FU<<6U)
#define ETHERNET_MAC_MACMIIAR_MR_0      (0x1U<<6U)
#define ETHERNET_MAC_MACMIIAR_CR        (0x7U<<2U)
#define ETHERNET_MAC_MACMIIAR_CR_0      (0x1U<<2U)
#define ETHERNET_MAC_MACMIIAR_MW        (0x1U<<1U)
#define ETHERNET_MAC_MACMIIAR_MB        (0x1U<<0U)

// MACMIIDR Configuration

#define ETHERNET_MAC_MACMIIDR_MD        (0xFFFFU<<0U)
#define ETHERNET_MAC_MACMIIDR_MD_0      (0x1U<<0U)

// MACFCR Configuration

#define ETHERNET_MAC_MACFCR_PT          (0xFFFFU<<16U)
#define ETHERNET_MAC_MACFCR_PT_0        (0x1U<<16U)
#define ETHERNET_MAC_MACFCR_ZQPD        (0x1U<<7U)
#define ETHERNET_MAC_MACFCR_PLT         (0x3U<<4U)
#define ETHERNET_MAC_MACFCR_PLT_0       (0x1U<<4U)
#define ETHERNET_MAC_MACFCR_UPFD        (0x1U<<3U)
#define ETHERNET_MAC_MACFCR_RFCE        (0x1U<<2U)
#define ETHERNET_MAC_MACFCR_TFCE        (0x1U<<1U)
#define ETHERNET_MAC_MACFCR_FCB         (0x1U<<0U)

// MACVLANTR Configuration

#define ETHERNET_MAC_MACVLANTR_VLANTC   (0x1U<<16U)
#define ETHERNET_MAC_MACVLANTR_VLANTI   (0xFFFFU<<0U)
#define ETHERNET_MAC_MACVLANTR_VLANTI_0 (0x1U<<0U)

// MACPMTCSR Configuration

#define ETHERNET_MAC_MACPMTCSR_WFFRPR   (0x1U<<31U)
#define ETHERNET_MAC_MACPMTCSR_GU       (0x1U<<9U)
#define ETHERNET_MAC_MACPMTCSR_WFR      (0x1U<<6U)
#define ETHERNET_MAC_MACPMTCSR_MPR      (0x1U<<5U)
#define ETHERNET_MAC_MACPMTCSR_WFE      (0x1U<<2U)
#define ETHERNET_MAC_MACPMTCSR_MPE      (0x1U<<1U)
#define ETHERNET_MAC_MACPMTCSR_PD       (0x1U<<0U)

// MACDBGR Configuration

#define ETHERNET_MAC_MACDBGR_TFF        (0x1U<<25U)
#define ETHERNET_MAC_MACDBGR_TFNE       (0x1U<<24U)
#define ETHERNET_MAC_MACDBGR_TFWA       (0x1U<<22U)
#define ETHERNET_MAC_MACDBGR_TFRS       (0x3U<<20U)
#define ETHERNET_MAC_MACDBGR_TFRS_0     (0x1U<<20U)
#define ETHERNET_MAC_MACDBGR_MTP        (0x1U<<19U)
#define ETHERNET_MAC_MACDBGR_MTFCS      (0x3U<<17U)
#define ETHERNET_MAC_MACDBGR_MTFCS_0    (0x1U<<17U)
#define ETHERNET_MAC_MACDBGR_MMTEA      (0x1U<<16U)
#define ETHERNET_MAC_MACDBGR_RFFL       (0x1U<<8U)
#define ETHERNET_MAC_MACDBGR_RFRCS      (0x1U<<5U)
#define ETHERNET_MAC_MACDBGR_RFWRA      (0x1U<<4U)
#define ETHERNET_MAC_MACDBGR_MSFRWCS    (0x1U<<1U)
#define ETHERNET_MAC_MACDBGR_MMRPEA     (0x1U<<0U)

// MACSR Configuration

#define ETHERNET_MAC_MACSR_TSTS         (0x1U<<9U)
#define ETHERNET_MAC_MACSR_MMCTS        (0x1U<<6U)
#define ETHERNET_MAC_MACSR_MMCRS        (0x1U<<5U)
#define ETHERNET_MAC_MACSR_MMCS         (0x1U<<4U)
#define ETHERNET_MAC_MACSR_PMTS         (0x1U<<3U)

// MACIMR Configuration

#define ETHERNET_MAC_MACIMR_TSTIM       (0x1U<<9U)
#define ETHERNET_MAC_MACIMR_PMTIM       (0x1U<<3U)

// MACA0HR Configuration

#define ETHERNET_MAC_MACA0HR_MO         (0x1U<<31U)
#define ETHERNET_MAC_MACA0HR_MACA0H     (0xFFFFU<<0U)
#define ETHERNET_MAC_MACA0HR_MACA0H_0   (0x1U<<0U)

// MACA0LR Configuration

#define ETHERNET_MAC_MACA0LR_MACA0L     (0xFFFFFFFFU<<0U)
#define ETHERNET_MAC_MACA0LR_MACA0L_0   (0x1U<<0U)

// MACA1HR Configuration

#define ETHERNET_MAC_MACA1HR_AE         (0x1U<<31U)
#define ETHERNET_MAC_MACA1HR_SA         (0x1U<<30U)
#define ETHERNET_MAC_MACA1HR_MBC        (0x3FU<<24U)
#define ETHERNET_MAC_MACA1HR_MBC_0      (0x1U<<24U)
#define ETHERNET_MAC_MACA1HR_MACA1H     (0xFFFFU<<0U)
#define ETHERNET_MAC_MACA1HR_MACA1H_0   (0x1U<<0U)

// MACA1LR Configuration

#define ETHERNET_MAC_MACA1LR_MACA1LR    (0xFFFFFFFFU<<0U)
#define ETHERNET_MAC_MACA1LR_MACA1LR_0  (0x1U<<0U)

// MACA2HR Configuration

#define ETHERNET_MAC_MACA2HR_AE         (0x1U<<31U)
#define ETHERNET_MAC_MACA2HR_SA         (0x1U<<30U)
#define ETHERNET_MAC_MACA2HR_MBC        (0x3FU<<24U)
#define ETHERNET_MAC_MACA2HR_MBC_0      (0x1U<<24U)
#define ETHERNET_MAC_MACA2HR_MAC2AH     (0xFFFFU<<0U)
#define ETHERNET_MAC_MACA2HR_MAC2AH_0   (0x1U<<0U)

// MACA2LR Configuration

#define ETHERNET_MAC_MACA2LR_MACA2L     (0x7FFFFFFFU<<0U)
#define ETHERNET_MAC_MACA2LR_MACA2L_0   (0x1U<<0U)

// MACA3HR Configuration

#define ETHERNET_MAC_MACA3HR_AE         (0x1U<<31U)
#define ETHERNET_MAC_MACA3HR_SA         (0x1U<<30U)
#define ETHERNET_MAC_MACA3HR_MBC        (0x3FU<<24U)
#define ETHERNET_MAC_MACA3HR_MBC_0      (0x1U<<24U)
#define ETHERNET_MAC_MACA3HR_MACA3H     (0xFFFFU<<0U)
#define ETHERNET_MAC_MACA3HR_MACA3H_0   (0x1U<<0U)

// MACA3LR Configuration

#define ETHERNET_MAC_MACA3LR_MBCA3L     (0xFFFFFFFFU<<0U)
#define ETHERNET_MAC_MACA3LR_MBCA3L_0   (0x1U<<0U)
