/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_ethernet_ptp equates.
 */

#pragma once

#include    <stdint.h>

// ETHERNET_PTP address definitions
// --------------------------------

typedef struct {
    volatile    uint32_t    PTPTSCR;
    volatile    uint32_t    PTPSSIR;
    volatile    uint32_t    PTPTSHR;
    volatile    uint32_t    PTPTSLR;
    volatile    uint32_t    PTPTSHUR;
    volatile    uint32_t    PTPTSLUR;
    volatile    uint32_t    PTPTSAR;
    volatile    uint32_t    PTPTTHR;
    volatile    uint32_t    PTPTTLR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    PTPTSSR;
    volatile    uint32_t    PTPPPSCR;
} ETHERNET_PTP_TypeDef;

#ifdef __cplusplus
#define ETHERNET_PTP    reinterpret_cast<ETHERNET_PTP_TypeDef *>(0x40028700U)

#else
#define ETHERNET_PTP    ((ETHERNET_PTP_TypeDef *)0x40028700U)
#endif

// PTPTSCR Configuration

#define ETHERNET_PTP_PTPTSCR_TSPFFMAE   (0x1U<<18U)
#define ETHERNET_PTP_PTPTSCR_TSCNT      (0x3U<<16U)
#define ETHERNET_PTP_PTPTSCR_TSCNT_0    (0x1U<<16U)
#define ETHERNET_PTP_PTPTSCR_TSSMRME    (0x1U<<15U)
#define ETHERNET_PTP_PTPTSCR_TSSEME     (0x1U<<14U)
#define ETHERNET_PTP_PTPTSCR_TSSIPV4FE  (0x1U<<13U)
#define ETHERNET_PTP_PTPTSCR_TSSIPV6FE  (0x1U<<12U)
#define ETHERNET_PTP_PTPTSCR_TSSPTPOEFE (0x1U<<11U)
#define ETHERNET_PTP_PTPTSCR_TSPTPPSV2E (0x1U<<10U)
#define ETHERNET_PTP_PTPTSCR_TSSSR      (0x1U<<9U)
#define ETHERNET_PTP_PTPTSCR_TSSARFE    (0x1U<<8U)
#define ETHERNET_PTP_PTPTSCR_TTSARU     (0x1U<<5U)
#define ETHERNET_PTP_PTPTSCR_TSITE      (0x1U<<4U)
#define ETHERNET_PTP_PTPTSCR_TSSTU      (0x1U<<3U)
#define ETHERNET_PTP_PTPTSCR_TSSTI      (0x1U<<2U)
#define ETHERNET_PTP_PTPTSCR_TSFCU      (0x1U<<1U)
#define ETHERNET_PTP_PTPTSCR_TSE        (0x1U<<0U)

// PTPSSIR Configuration

#define ETHERNET_PTP_PTPSSIR_STSSI      (0xFFU<<0U)
#define ETHERNET_PTP_PTPSSIR_STSSI_0    (0x1U<<0U)

// PTPTSHR Configuration

#define ETHERNET_PTP_PTPTSHR_STS        (0xFFFFFFFFU<<0U)
#define ETHERNET_PTP_PTPTSHR_STS_0      (0x1U<<0U)

// PTPTSLR Configuration

#define ETHERNET_PTP_PTPTSLR_STPNS      (0x1U<<31U)
#define ETHERNET_PTP_PTPTSLR_STSS       (0x7FFFFFFFU<<0U)
#define ETHERNET_PTP_PTPTSLR_STSS_0     (0x1U<<0U)

// PTPTSHUR Configuration

#define ETHERNET_PTP_PTPTSHUR_TSUS      (0xFFFFFFFFU<<0U)
#define ETHERNET_PTP_PTPTSHUR_TSUS_0    (0x1U<<0U)

// PTPTSLUR Configuration

#define ETHERNET_PTP_PTPTSLUR_TSUPNS    (0x1U<<31U)
#define ETHERNET_PTP_PTPTSLUR_TSUSS     (0x7FFFFFFFU<<0U)
#define ETHERNET_PTP_PTPTSLUR_TSUSS_0   (0x1U<<0U)

// PTPTSAR Configuration

#define ETHERNET_PTP_PTPTSAR_TSA        (0xFFFFFFFFU<<0U)
#define ETHERNET_PTP_PTPTSAR_TSA_0      (0x1U<<0U)

// PTPTTHR Configuration

#define ETHERNET_PTP_PTPTTHR_TTSH       (0xFFFFFFFFU<<0U)
#define ETHERNET_PTP_PTPTTHR_TTSH_0     (0x1U<<0U)

// PTPTTLR Configuration

#define ETHERNET_PTP_PTPTTLR_TTSL       (0xFFFFFFFFU<<0U)
#define ETHERNET_PTP_PTPTTLR_TTSL_0     (0x1U<<0U)

// PTPTSSR Configuration

#define ETHERNET_PTP_PTPTSSR_TSTTR      (0x1U<<1U)
#define ETHERNET_PTP_PTPTSSR_TSSO       (0x1U<<0U)

// PTPPPSCR Configuration

#define ETHERNET_PTP_PTPPPSCR_PPSFREQ   (0xFU<<0U)
#define ETHERNET_PTP_PTPPPSCR_PPSFREQ_0 (0x1U<<0U)
