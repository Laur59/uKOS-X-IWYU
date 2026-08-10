/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H743_ethernet_dma equates.
 */

#pragma once

#include    <stdint.h>

// ETHERNET_DMA address definitions
// --------------------------------

typedef struct {
    volatile    uint32_t    DMAMR;
    volatile    uint32_t    DMASBMR;
    volatile    uint32_t    DMAISR;
    volatile    uint32_t    DMADSR;
    volatile    uint32_t    RESERVED0[60];
    volatile    uint32_t    DMACCR;
    volatile    uint32_t    DMACTXCR;
    volatile    uint32_t    DMACRXCR;
    volatile    uint32_t    RESERVED1[2];
    volatile    uint32_t    DMACTXDLAR;
    volatile    uint32_t    RESERVED2;
    volatile    uint32_t    DMACRXDLAR;
    volatile    uint32_t    DMACTXDTPR;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    DMACRXDTPR;
    volatile    uint32_t    DMACTXRLR;
    volatile    uint32_t    DMACRXRLR;
    volatile    uint32_t    DMACIER;
    volatile    uint32_t    DMACRXIWTR;
    volatile    uint32_t    RESERVED4[2];
    volatile    uint32_t    DMACCATXDR;
    volatile    uint32_t    RESERVED5;
    volatile    uint32_t    DMACCARXDR;
    volatile    uint32_t    RESERVED6;
    volatile    uint32_t    DMACCATXBR;
    volatile    uint32_t    RESERVED7;
    volatile    uint32_t    DMACCARXBR;
    volatile    uint32_t    DMACSR;
    volatile    uint32_t    RESERVED8[2];
    volatile    uint32_t    DMACMFCR;
} ETHERNET_DMA_TypeDef;

#ifdef __cplusplus
#define ETHERNET_DMA    reinterpret_cast<ETHERNET_DMA_TypeDef *>(0x40029000U)

#else
#define ETHERNET_DMA    ((ETHERNET_DMA_TypeDef *)0x40029000U)
#endif

// DMAMR Configuration

#define ETHERNET_DMA_DMAMR_INTM                 (0x1U<<16U)
#define ETHERNET_DMA_DMAMR_PR                   (0x7U<<12U)
#define ETHERNET_DMA_DMAMR_PR_0                 (0x1U<<12U)
#define ETHERNET_DMA_DMAMR_TXPR                 (0x1U<<11U)
#define ETHERNET_DMA_DMAMR_DA                   (0x1U<<1U)
#define ETHERNET_DMA_DMAMR_SWR                  (0x1U<<0U)

// DMASBMR Configuration

#define ETHERNET_DMA_DMASBMR_RB                 (0x1U<<15U)
#define ETHERNET_DMA_DMASBMR_MB                 (0x1U<<14U)
#define ETHERNET_DMA_DMASBMR_AAL                (0x1U<<12U)
#define ETHERNET_DMA_DMASBMR_FB                 (0x1U<<0U)

// DMAISR Configuration

#define ETHERNET_DMA_DMAISR_MACIS               (0x1U<<17U)
#define ETHERNET_DMA_DMAISR_MTLIS               (0x1U<<16U)
#define ETHERNET_DMA_DMAISR_DC0IS               (0x1U<<0U)

// DMADSR Configuration

#define ETHERNET_DMA_DMADSR_TPS0                (0xFU<<12U)
#define ETHERNET_DMA_DMADSR_TPS0_0              (0x1U<<12U)
#define ETHERNET_DMA_DMADSR_RPS0                (0xFU<<8U)
#define ETHERNET_DMA_DMADSR_RPS0_0              (0x1U<<8U)
#define ETHERNET_DMA_DMADSR_AXWHSTS             (0x1U<<0U)

// DMACCR Configuration

#define ETHERNET_DMA_DMACCR_DSL                 (0x7U<<18U)
#define ETHERNET_DMA_DMACCR_DSL_0               (0x1U<<18U)
#define ETHERNET_DMA_DMACCR_PBLX8               (0x1U<<16U)
#define ETHERNET_DMA_DMACCR_MSS                 (0x3FFFU<<0U)
#define ETHERNET_DMA_DMACCR_MSS_0               (0x1U<<0U)

// DMACTXCR Configuration

#define ETHERNET_DMA_DMACTXCR_TXPBL             (0x3FU<<16U)
#define ETHERNET_DMA_DMACTXCR_TXPBL_0           (0x1U<<16U)
#define ETHERNET_DMA_DMACTXCR_TSE               (0x1U<<12U)
#define ETHERNET_DMA_DMACTXCR_OSF               (0x1U<<4U)
#define ETHERNET_DMA_DMACTXCR_ST                (0x1U<<0U)

// DMACRXCR Configuration

#define ETHERNET_DMA_DMACRXCR_RPF               (0x1U<<31U)
#define ETHERNET_DMA_DMACRXCR_RXPBL             (0x3FU<<16U)
#define ETHERNET_DMA_DMACRXCR_RXPBL_0           (0x1U<<16U)
#define ETHERNET_DMA_DMACRXCR_RBSZ              (0x3FFFU<<1U)
#define ETHERNET_DMA_DMACRXCR_RBSZ_0            (0x1U<<1U)
#define ETHERNET_DMA_DMACRXCR_SR                (0x1U<<0U)

// DMACTXDLAR Configuration

#define ETHERNET_DMA_DMACTXDLAR_TDESLA          (0x3FFFFFFFU<<2U)
#define ETHERNET_DMA_DMACTXDLAR_TDESLA_0        (0x1U<<2U)

// DMACRXDLAR Configuration

#define ETHERNET_DMA_DMACRXDLAR_RDESLA          (0x3FFFFFFFU<<2U)
#define ETHERNET_DMA_DMACRXDLAR_RDESLA_0        (0x1U<<2U)

// DMACTXDTPR Configuration

#define ETHERNET_DMA_DMACTXDTPR_TDT             (0x3FFFFFFFU<<2U)
#define ETHERNET_DMA_DMACTXDTPR_TDT_0           (0x1U<<2U)

// DMACRXDTPR Configuration

#define ETHERNET_DMA_DMACRXDTPR_RDT             (0x3FFFFFFFU<<2U)
#define ETHERNET_DMA_DMACRXDTPR_RDT_0           (0x1U<<2U)

// DMACTXRLR Configuration

#define ETHERNET_DMA_DMACTXRLR_TDRL             (0x3FFU<<0U)
#define ETHERNET_DMA_DMACTXRLR_TDRL_0           (0x1U<<0U)

// DMACRXRLR Configuration

#define ETHERNET_DMA_DMACRXRLR_RDRL             (0x3FFU<<0U)
#define ETHERNET_DMA_DMACRXRLR_RDRL_0           (0x1U<<0U)

// DMACIER Configuration

#define ETHERNET_DMA_DMACIER_NIE                (0x1U<<15U)
#define ETHERNET_DMA_DMACIER_AIE                (0x1U<<14U)
#define ETHERNET_DMA_DMACIER_CDEE               (0x1U<<13U)
#define ETHERNET_DMA_DMACIER_FBEE               (0x1U<<12U)
#define ETHERNET_DMA_DMACIER_ERIE               (0x1U<<11U)
#define ETHERNET_DMA_DMACIER_ETIE               (0x1U<<10U)
#define ETHERNET_DMA_DMACIER_RWTE               (0x1U<<9U)
#define ETHERNET_DMA_DMACIER_RSE                (0x1U<<8U)
#define ETHERNET_DMA_DMACIER_RBUE               (0x1U<<7U)
#define ETHERNET_DMA_DMACIER_RIE                (0x1U<<6U)
#define ETHERNET_DMA_DMACIER_TBUE               (0x1U<<2U)
#define ETHERNET_DMA_DMACIER_TXSE               (0x1U<<1U)
#define ETHERNET_DMA_DMACIER_TIE                (0x1U<<0U)

// DMACRXIWTR Configuration

#define ETHERNET_DMA_DMACRXIWTR_RWT             (0xFFU<<0U)
#define ETHERNET_DMA_DMACRXIWTR_RWT_0           (0x1U<<0U)

// DMACCATXDR Configuration

#define ETHERNET_DMA_DMACCATXDR_CURTDESAPTR     (0xFFFFFFFFU<<0U)
#define ETHERNET_DMA_DMACCATXDR_CURTDESAPTR_0   (0x1U<<0U)

// DMACCARXDR Configuration

#define ETHERNET_DMA_DMACCARXDR_CURRDESAPTR     (0xFFFFFFFFU<<0U)
#define ETHERNET_DMA_DMACCARXDR_CURRDESAPTR_0   (0x1U<<0U)

// DMACCATXBR Configuration

#define ETHERNET_DMA_DMACCATXBR_CURTBUFAPTR     (0xFFFFFFFFU<<0U)
#define ETHERNET_DMA_DMACCATXBR_CURTBUFAPTR_0   (0x1U<<0U)

// DMACCARXBR Configuration

#define ETHERNET_DMA_DMACCARXBR_CURRBUFAPTR     (0xFFFFFFFFU<<0U)
#define ETHERNET_DMA_DMACCARXBR_CURRBUFAPTR_0   (0x1U<<0U)

// DMACSR Configuration

#define ETHERNET_DMA_DMACSR_REB                 (0x7U<<19U)
#define ETHERNET_DMA_DMACSR_REB_0               (0x1U<<19U)
#define ETHERNET_DMA_DMACSR_TEB                 (0x7U<<16U)
#define ETHERNET_DMA_DMACSR_TEB_0               (0x1U<<16U)
#define ETHERNET_DMA_DMACSR_NIS                 (0x1U<<15U)
#define ETHERNET_DMA_DMACSR_AIS                 (0x1U<<14U)
#define ETHERNET_DMA_DMACSR_CDE                 (0x1U<<13U)
#define ETHERNET_DMA_DMACSR_FBE                 (0x1U<<12U)
#define ETHERNET_DMA_DMACSR_ER                  (0x1U<<11U)
#define ETHERNET_DMA_DMACSR_ET                  (0x1U<<10U)
#define ETHERNET_DMA_DMACSR_RWT                 (0x1U<<9U)
#define ETHERNET_DMA_DMACSR_RPS                 (0x1U<<8U)
#define ETHERNET_DMA_DMACSR_RBU                 (0x1U<<7U)
#define ETHERNET_DMA_DMACSR_RI                  (0x1U<<6U)
#define ETHERNET_DMA_DMACSR_TBU                 (0x1U<<2U)
#define ETHERNET_DMA_DMACSR_TPS                 (0x1U<<1U)
#define ETHERNET_DMA_DMACSR_TI                  (0x1U<<0U)

// DMACMFCR Configuration

#define ETHERNET_DMA_DMACMFCR_MFCO              (0x1U<<15U)
#define ETHERNET_DMA_DMACMFCR_MFC               (0x7FFU<<0U)
#define ETHERNET_DMA_DMACMFCR_MFC_0             (0x1U<<0U)
