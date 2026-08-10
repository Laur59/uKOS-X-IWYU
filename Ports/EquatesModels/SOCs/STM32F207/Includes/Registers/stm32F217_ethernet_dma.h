/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_ethernet_dma equates.
 */

#pragma once

#include    <stdint.h>

// ETHERNET_DMA address definitions
// --------------------------------

typedef struct {
    volatile    uint32_t    DMABMR;
    volatile    uint32_t    DMATPDR;
    volatile    uint32_t    DMARPDR;
    volatile    uint32_t    DMARDLAR;
    volatile    uint32_t    DMATDLAR;
    volatile    uint32_t    DMASR;
    volatile    uint32_t    DMAOMR;
    volatile    uint32_t    DMAIER;
    volatile    uint32_t    DMAMFBOCR;
    volatile    uint32_t    DMARSWTR;
    volatile    uint32_t    RESERVED0[8];
    volatile    uint32_t    DMACHTDR;
    volatile    uint32_t    DMACHRDR;
    volatile    uint32_t    DMACHTBAR;
    volatile    uint32_t    DMACHRBAR;
} ETHERNET_DMA_TypeDef;

#ifdef __cplusplus
#define ETHERNET_DMA    reinterpret_cast<ETHERNET_DMA_TypeDef *>(0x40029000U)

#else
#define ETHERNET_DMA    ((ETHERNET_DMA_TypeDef *)0x40029000U)
#endif

// DMABMR Configuration

#define ETHERNET_DMA_DMABMR_MB          (0x1U<<26U)
#define ETHERNET_DMA_DMABMR_AAB         (0x1U<<25U)
#define ETHERNET_DMA_DMABMR_FPM         (0x1U<<24U)
#define ETHERNET_DMA_DMABMR_USP         (0x1U<<23U)
#define ETHERNET_DMA_DMABMR_RDP         (0x3FU<<17U)
#define ETHERNET_DMA_DMABMR_RDP_0       (0x1U<<17U)
#define ETHERNET_DMA_DMABMR_FB          (0x1U<<16U)
#define ETHERNET_DMA_DMABMR_RTPR        (0x3U<<14U)
#define ETHERNET_DMA_DMABMR_RTPR_0      (0x1U<<14U)
#define ETHERNET_DMA_DMABMR_PBL         (0x3FU<<8U)
#define ETHERNET_DMA_DMABMR_PBL_0       (0x1U<<8U)
#define ETHERNET_DMA_DMABMR_EDFE        (0x1U<<7U)
#define ETHERNET_DMA_DMABMR_DSL         (0x1FU<<2U)
#define ETHERNET_DMA_DMABMR_DSL_0       (0x1U<<2U)
#define ETHERNET_DMA_DMABMR_DA          (0x1U<<1U)
#define ETHERNET_DMA_DMABMR_SR          (0x1U<<0U)

// DMATPDR Configuration

#define ETHERNET_DMA_DMATPDR_TPD        (0xFFFFFFFFU<<0U)
#define ETHERNET_DMA_DMATPDR_TPD_0      (0x1U<<0U)

// DMARPDR Configuration

#define ETHERNET_DMA_DMARPDR_RPD        (0xFFFFFFFFU<<0U)
#define ETHERNET_DMA_DMARPDR_RPD_0      (0x1U<<0U)

// DMARDLAR Configuration

#define ETHERNET_DMA_DMARDLAR_SRL       (0xFFFFFFFFU<<0U)
#define ETHERNET_DMA_DMARDLAR_SRL_0     (0x1U<<0U)

// DMATDLAR Configuration

#define ETHERNET_DMA_DMATDLAR_STL       (0xFFFFFFFFU<<0U)
#define ETHERNET_DMA_DMATDLAR_STL_0     (0x1U<<0U)

// DMASR Configuration

#define ETHERNET_DMA_DMASR_TSTS         (0x1U<<29U)
#define ETHERNET_DMA_DMASR_PMTS         (0x1U<<28U)
#define ETHERNET_DMA_DMASR_MMCS         (0x1U<<27U)
#define ETHERNET_DMA_DMASR_EBS          (0x7U<<23U)
#define ETHERNET_DMA_DMASR_EBS_0        (0x1U<<23U)
#define ETHERNET_DMA_DMASR_TPS          (0x7U<<20U)
#define ETHERNET_DMA_DMASR_TPS_0        (0x1U<<20U)
#define ETHERNET_DMA_DMASR_RPS          (0x7U<<17U)
#define ETHERNET_DMA_DMASR_RPS_0        (0x1U<<17U)
#define ETHERNET_DMA_DMASR_NIS          (0x1U<<16U)
#define ETHERNET_DMA_DMASR_AIS          (0x1U<<15U)
#define ETHERNET_DMA_DMASR_ERS          (0x1U<<14U)
#define ETHERNET_DMA_DMASR_FBES         (0x1U<<13U)
#define ETHERNET_DMA_DMASR_ETS          (0x1U<<10U)
#define ETHERNET_DMA_DMASR_PWTS         (0x1U<<9U)
#define ETHERNET_DMA_DMASR_RPSS         (0x1U<<8U)
#define ETHERNET_DMA_DMASR_RBUS         (0x1U<<7U)
#define ETHERNET_DMA_DMASR_RS           (0x1U<<6U)
#define ETHERNET_DMA_DMASR_TUS          (0x1U<<5U)
#define ETHERNET_DMA_DMASR_ROS          (0x1U<<4U)
#define ETHERNET_DMA_DMASR_TJTS         (0x1U<<3U)
#define ETHERNET_DMA_DMASR_TBUS         (0x1U<<2U)
#define ETHERNET_DMA_DMASR_TPSS         (0x1U<<1U)
#define ETHERNET_DMA_DMASR_TS           (0x1U<<0U)

// DMAOMR Configuration

#define ETHERNET_DMA_DMAOMR_DTCEFD      (0x1U<<26U)
#define ETHERNET_DMA_DMAOMR_RSF         (0x1U<<25U)
#define ETHERNET_DMA_DMAOMR_DFRF        (0x1U<<24U)
#define ETHERNET_DMA_DMAOMR_TSF         (0x1U<<21U)
#define ETHERNET_DMA_DMAOMR_FTF         (0x1U<<20U)
#define ETHERNET_DMA_DMAOMR_TTC         (0x7U<<14U)
#define ETHERNET_DMA_DMAOMR_TTC_0       (0x1U<<14U)
#define ETHERNET_DMA_DMAOMR_ST          (0x1U<<13U)
#define ETHERNET_DMA_DMAOMR_FEF         (0x1U<<7U)
#define ETHERNET_DMA_DMAOMR_FUGF        (0x1U<<6U)
#define ETHERNET_DMA_DMAOMR_RTC         (0x3U<<3U)
#define ETHERNET_DMA_DMAOMR_RTC_0       (0x1U<<3U)
#define ETHERNET_DMA_DMAOMR_OSF         (0x1U<<2U)
#define ETHERNET_DMA_DMAOMR_SR          (0x1U<<1U)

// DMAIER Configuration

#define ETHERNET_DMA_DMAIER_NISE        (0x1U<<16U)
#define ETHERNET_DMA_DMAIER_AISE        (0x1U<<15U)
#define ETHERNET_DMA_DMAIER_ERIE        (0x1U<<14U)
#define ETHERNET_DMA_DMAIER_FBEIE       (0x1U<<13U)
#define ETHERNET_DMA_DMAIER_ETIE        (0x1U<<10U)
#define ETHERNET_DMA_DMAIER_RWTIE       (0x1U<<9U)
#define ETHERNET_DMA_DMAIER_RPSIE       (0x1U<<8U)
#define ETHERNET_DMA_DMAIER_RBUIE       (0x1U<<7U)
#define ETHERNET_DMA_DMAIER_RIE         (0x1U<<6U)
#define ETHERNET_DMA_DMAIER_TUIE        (0x1U<<5U)
#define ETHERNET_DMA_DMAIER_ROIE        (0x1U<<4U)
#define ETHERNET_DMA_DMAIER_TJTIE       (0x1U<<3U)
#define ETHERNET_DMA_DMAIER_TBUIE       (0x1U<<2U)
#define ETHERNET_DMA_DMAIER_TPSIE       (0x1U<<1U)
#define ETHERNET_DMA_DMAIER_TIE         (0x1U<<0U)

// DMAMFBOCR Configuration

#define ETHERNET_DMA_DMAMFBOCR_OFOC     (0x1U<<28U)
#define ETHERNET_DMA_DMAMFBOCR_MFA      (0x7FFU<<17U)
#define ETHERNET_DMA_DMAMFBOCR_MFA_0    (0x1U<<17U)
#define ETHERNET_DMA_DMAMFBOCR_OMFC     (0x1U<<16U)
#define ETHERNET_DMA_DMAMFBOCR_MFC      (0xFFFFU<<0U)
#define ETHERNET_DMA_DMAMFBOCR_MFC_0    (0x1U<<0U)

// DMARSWTR Configuration

#define ETHERNET_DMA_DMARSWTR_RSWTC     (0xFFU<<0U)
#define ETHERNET_DMA_DMARSWTR_RSWTC_0   (0x1U<<0U)

// DMACHTDR Configuration

#define ETHERNET_DMA_DMACHTDR_HTDAP     (0xFFFFFFFFU<<0U)
#define ETHERNET_DMA_DMACHTDR_HTDAP_0   (0x1U<<0U)

// DMACHRDR Configuration

#define ETHERNET_DMA_DMACHRDR_HRDAP     (0xFFFFFFFFU<<0U)
#define ETHERNET_DMA_DMACHRDR_HRDAP_0   (0x1U<<0U)

// DMACHTBAR Configuration

#define ETHERNET_DMA_DMACHTBAR_HTBAP    (0xFFFFFFFFU<<0U)
#define ETHERNET_DMA_DMACHTBAR_HTBAP_0  (0x1U<<0U)

// DMACHRBAR Configuration

#define ETHERNET_DMA_DMACHRBAR_HRBAP    (0xFFFFFFFFU<<0U)
#define ETHERNET_DMA_DMACHRBAR_HRBAP_0  (0x1U<<0U)
