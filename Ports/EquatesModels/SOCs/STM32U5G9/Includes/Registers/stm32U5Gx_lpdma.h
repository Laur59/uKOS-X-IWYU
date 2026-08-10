/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_lpdma equates.
 */

#pragma once

#include    <stdint.h>

// LPDMA address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    SECCFGR;
    volatile    uint32_t    PRIVCFGR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    MISR;
    volatile    uint32_t    SMISR;
    volatile    uint32_t    RESERVED1[15];
    volatile    uint32_t    C0LBAR;
    volatile    uint32_t    RESERVED2[2];
    volatile    uint32_t    C0FCR;
    volatile    uint32_t    C0SR;
    volatile    uint32_t    C0CR;
    volatile    uint32_t    RESERVED3[10];
    volatile    uint32_t    C0TR1;
    volatile    uint32_t    C0TR2;
    volatile    uint32_t    C0BR1;
    volatile    uint32_t    C0SAR;
    volatile    uint32_t    C0DAR;
    volatile    uint32_t    RESERVED4[10];
    volatile    uint32_t    C0LLR;
    volatile    uint32_t    C1LBAR;
    volatile    uint32_t    RESERVED5[2];
    volatile    uint32_t    C1FCR;
    volatile    uint32_t    C1SR;
    volatile    uint32_t    C1CR;
    volatile    uint32_t    RESERVED6[10];
    volatile    uint32_t    C1TR1;
    volatile    uint32_t    C1TR2;
    volatile    uint32_t    C1BR1;
    volatile    uint32_t    C1SAR;
    volatile    uint32_t    C1DAR;
    volatile    uint32_t    RESERVED7[10];
    volatile    uint32_t    C1LLR;
    volatile    uint32_t    C2LBAR;
    volatile    uint32_t    RESERVED8[2];
    volatile    uint32_t    C2FCR;
    volatile    uint32_t    C2SR;
    volatile    uint32_t    C2CR;
    volatile    uint32_t    RESERVED9[10];
    volatile    uint32_t    C2TR1;
    volatile    uint32_t    C2TR2;
    volatile    uint32_t    C2BR1;
    volatile    uint32_t    C2SAR;
    volatile    uint32_t    C2DAR;
    volatile    uint32_t    RESERVED10[10];
    volatile    uint32_t    C2LLR;
    volatile    uint32_t    C3LBAR;
    volatile    uint32_t    RESERVED11[2];
    volatile    uint32_t    C3FCR;
    volatile    uint32_t    C3SR;
    volatile    uint32_t    C3CR;
    volatile    uint32_t    RESERVED12[10];
    volatile    uint32_t    C3TR1;
    volatile    uint32_t    C3TR2;
    volatile    uint32_t    C3BR1;
    volatile    uint32_t    C3SAR;
    volatile    uint32_t    C3DAR;
    volatile    uint32_t    RESERVED13[10];
    volatile    uint32_t    C3LLR;
} LPDMA_TypeDef;

#ifdef __cplusplus
#define LPDMA1_NS   reinterpret_cast<LPDMA_TypeDef *>(0x46025000U)
#define LPDMA1_S    reinterpret_cast<LPDMA_TypeDef *>(0x56025000U)

#else
#define LPDMA1_NS   ((LPDMA_TypeDef *)0x46025000U)
#define LPDMA1_S    ((LPDMA_TypeDef *)0x56025000U)
#endif

// SECCFGR Configuration

#define LPDMA_SECCFGR_SEC3      (0x1U<<3U)
#define LPDMA_SECCFGR_SEC2      (0x1U<<2U)
#define LPDMA_SECCFGR_SEC1      (0x1U<<1U)
#define LPDMA_SECCFGR_SEC0      (0x1U<<0U)

// PRIVCFGR Configuration

#define LPDMA_PRIVCFGR_PRIV3    (0x1U<<3U)
#define LPDMA_PRIVCFGR_PRIV2    (0x1U<<2U)
#define LPDMA_PRIVCFGR_PRIV1    (0x1U<<1U)
#define LPDMA_PRIVCFGR_PRIV0    (0x1U<<0U)

// MISR Configuration

#define LPDMA_MISR_MIS3         (0x1U<<3U)
#define LPDMA_MISR_MIS2         (0x1U<<2U)
#define LPDMA_MISR_MIS1         (0x1U<<1U)
#define LPDMA_MISR_MIS0         (0x1U<<0U)

// SMISR Configuration

#define LPDMA_SMISR_MIS3        (0x1U<<3U)
#define LPDMA_SMISR_MIS2        (0x1U<<2U)
#define LPDMA_SMISR_MIS1        (0x1U<<1U)
#define LPDMA_SMISR_MIS0        (0x1U<<0U)

// C0LBAR Configuration

#define LPDMA_C0LBAR_LBA        (0xFFFFU<<16U)
#define LPDMA_C0LBAR_LBA_0      (0x1U<<16U)

// C0FCR Configuration

#define LPDMA_C0FCR_SUSPF       (0x1U<<13U)
#define LPDMA_C0FCR_USEF        (0x1U<<12U)
#define LPDMA_C0FCR_ULEF        (0x1U<<11U)
#define LPDMA_C0FCR_DTEF        (0x1U<<10U)
#define LPDMA_C0FCR_HTF         (0x1U<<9U)
#define LPDMA_C0FCR_TCF         (0x1U<<8U)

// C0SR Configuration

#define LPDMA_C0SR_SUSPF        (0x1U<<13U)
#define LPDMA_C0SR_USEF         (0x1U<<12U)
#define LPDMA_C0SR_ULEF         (0x1U<<11U)
#define LPDMA_C0SR_DTEF         (0x1U<<10U)
#define LPDMA_C0SR_HTF          (0x1U<<9U)
#define LPDMA_C0SR_TCF          (0x1U<<8U)
#define LPDMA_C0SR_IDLEF        (0x1U<<0U)

// C0CR Configuration

#define LPDMA_C0CR_PRIO         (0x3U<<22U)
#define LPDMA_C0CR_PRIO_0       (0x1U<<22U)
#define LPDMA_C0CR_LSM          (0x1U<<16U)
#define LPDMA_C0CR_SUSPIE       (0x1U<<13U)
#define LPDMA_C0CR_USEIE        (0x1U<<12U)
#define LPDMA_C0CR_ULEIE        (0x1U<<11U)
#define LPDMA_C0CR_DTEIE        (0x1U<<10U)
#define LPDMA_C0CR_HTIE         (0x1U<<9U)
#define LPDMA_C0CR_TCIE         (0x1U<<8U)
#define LPDMA_C0CR_SUSP         (0x1U<<2U)
#define LPDMA_C0CR_RESET        (0x1U<<1U)
#define LPDMA_C0CR_EN           (0x1U<<0U)

// C0TR1 Configuration

#define LPDMA_C0TR1_DSEC        (0x1U<<31U)
#define LPDMA_C0TR1_DINC        (0x1U<<19U)
#define LPDMA_C0TR1_DDW_LOG2    (0x3U<<16U)
#define LPDMA_C0TR1_DDW_LOG2_0  (0x1U<<16U)
#define LPDMA_C0TR1_SSEC        (0x1U<<15U)
#define LPDMA_C0TR1_PAM         (0x3U<<11U)
#define LPDMA_C0TR1_PAM_0       (0x1U<<11U)
#define LPDMA_C0TR1_SINC        (0x1U<<3U)
#define LPDMA_C0TR1_SDW_LOG2    (0x3U<<0U)
#define LPDMA_C0TR1_SDW_LOG2_0  (0x1U<<0U)

// C0TR2 Configuration

#define LPDMA_C0TR2_TCEM        (0x3U<<30U)
#define LPDMA_C0TR2_TCEM_0      (0x1U<<30U)
#define LPDMA_C0TR2_TRIGPOL     (0x3U<<24U)
#define LPDMA_C0TR2_TRIGPOL_0   (0x1U<<24U)
#define LPDMA_C0TR2_TRIGSEL     (0x1FU<<16U)
#define LPDMA_C0TR2_TRIGSEL_0   (0x1U<<16U)
#define LPDMA_C0TR2_TRIGM       (0x3U<<14U)
#define LPDMA_C0TR2_TRIGM_0     (0x1U<<14U)
#define LPDMA_C0TR2_BREQ        (0x1U<<11U)
#define LPDMA_C0TR2_SWREQ       (0x1U<<9U)
#define LPDMA_C0TR2_REQSEL      (0x1FU<<0U)
#define LPDMA_C0TR2_REQSEL_0    (0x1U<<0U)

// C0BR1 Configuration

#define LPDMA_C0BR1_BNDT        (0xFFFFU<<0U)
#define LPDMA_C0BR1_BNDT_0      (0x1U<<0U)

// C0SAR Configuration

#define LPDMA_C0SAR_SA          (0xFFFFFFFFU<<0U)
#define LPDMA_C0SAR_SA_0        (0x1U<<0U)

// C0DAR Configuration

#define LPDMA_C0DAR_DA          (0xFFFFFFFFU<<0U)
#define LPDMA_C0DAR_DA_0        (0x1U<<0U)

// C0LLR Configuration

#define LPDMA_C0LLR_UT1         (0x1U<<31U)
#define LPDMA_C0LLR_UT2         (0x1U<<30U)
#define LPDMA_C0LLR_UB1         (0x1U<<29U)
#define LPDMA_C0LLR_USA         (0x1U<<28U)
#define LPDMA_C0LLR_UDA         (0x1U<<27U)
#define LPDMA_C0LLR_ULL         (0x1U<<16U)
#define LPDMA_C0LLR_LA          (0x3FFFU<<2U)
#define LPDMA_C0LLR_LA_0        (0x1U<<2U)

// C1LBAR Configuration

#define LPDMA_C1LBAR_LBA        (0xFFFFU<<16U)
#define LPDMA_C1LBAR_LBA_0      (0x1U<<16U)

// C1FCR Configuration

#define LPDMA_C1FCR_SUSPF       (0x1U<<13U)
#define LPDMA_C1FCR_USEF        (0x1U<<12U)
#define LPDMA_C1FCR_ULEF        (0x1U<<11U)
#define LPDMA_C1FCR_DTEF        (0x1U<<10U)
#define LPDMA_C1FCR_HTF         (0x1U<<9U)
#define LPDMA_C1FCR_TCF         (0x1U<<8U)

// C1SR Configuration

#define LPDMA_C1SR_SUSPF        (0x1U<<13U)
#define LPDMA_C1SR_USEF         (0x1U<<12U)
#define LPDMA_C1SR_ULEF         (0x1U<<11U)
#define LPDMA_C1SR_DTEF         (0x1U<<10U)
#define LPDMA_C1SR_HTF          (0x1U<<9U)
#define LPDMA_C1SR_TCF          (0x1U<<8U)
#define LPDMA_C1SR_IDLEF        (0x1U<<0U)

// C1CR Configuration

#define LPDMA_C1CR_PRIO         (0x3U<<22U)
#define LPDMA_C1CR_PRIO_0       (0x1U<<22U)
#define LPDMA_C1CR_LSM          (0x1U<<16U)
#define LPDMA_C1CR_SUSPIE       (0x1U<<13U)
#define LPDMA_C1CR_USEIE        (0x1U<<12U)
#define LPDMA_C1CR_ULEIE        (0x1U<<11U)
#define LPDMA_C1CR_DTEIE        (0x1U<<10U)
#define LPDMA_C1CR_HTIE         (0x1U<<9U)
#define LPDMA_C1CR_TCIE         (0x1U<<8U)
#define LPDMA_C1CR_SUSP         (0x1U<<2U)
#define LPDMA_C1CR_RESET        (0x1U<<1U)
#define LPDMA_C1CR_EN           (0x1U<<0U)

// C1TR1 Configuration

#define LPDMA_C1TR1_DSEC        (0x1U<<31U)
#define LPDMA_C1TR1_DINC        (0x1U<<19U)
#define LPDMA_C1TR1_DDW_LOG2    (0x3U<<16U)
#define LPDMA_C1TR1_DDW_LOG2_0  (0x1U<<16U)
#define LPDMA_C1TR1_SSEC        (0x1U<<15U)
#define LPDMA_C1TR1_PAM         (0x3U<<11U)
#define LPDMA_C1TR1_PAM_0       (0x1U<<11U)
#define LPDMA_C1TR1_SINC        (0x1U<<3U)
#define LPDMA_C1TR1_SDW_LOG2    (0x3U<<0U)
#define LPDMA_C1TR1_SDW_LOG2_0  (0x1U<<0U)

// C1TR2 Configuration

#define LPDMA_C1TR2_TCEM        (0x3U<<30U)
#define LPDMA_C1TR2_TCEM_0      (0x1U<<30U)
#define LPDMA_C1TR2_TRIGPOL     (0x3U<<24U)
#define LPDMA_C1TR2_TRIGPOL_0   (0x1U<<24U)
#define LPDMA_C1TR2_TRIGSEL     (0x1FU<<16U)
#define LPDMA_C1TR2_TRIGSEL_0   (0x1U<<16U)
#define LPDMA_C1TR2_TRIGM       (0x3U<<14U)
#define LPDMA_C1TR2_TRIGM_0     (0x1U<<14U)
#define LPDMA_C1TR2_BREQ        (0x1U<<11U)
#define LPDMA_C1TR2_SWREQ       (0x1U<<9U)
#define LPDMA_C1TR2_REQSEL      (0x1FU<<0U)
#define LPDMA_C1TR2_REQSEL_0    (0x1U<<0U)

// C1BR1 Configuration

#define LPDMA_C1BR1_BNDT        (0xFFFFU<<0U)
#define LPDMA_C1BR1_BNDT_0      (0x1U<<0U)

// C1SAR Configuration

#define LPDMA_C1SAR_SA          (0xFFFFFFFFU<<0U)
#define LPDMA_C1SAR_SA_0        (0x1U<<0U)

// C1DAR Configuration

#define LPDMA_C1DAR_DA          (0xFFFFFFFFU<<0U)
#define LPDMA_C1DAR_DA_0        (0x1U<<0U)

// C1LLR Configuration

#define LPDMA_C1LLR_UT1         (0x1U<<31U)
#define LPDMA_C1LLR_UT2         (0x1U<<30U)
#define LPDMA_C1LLR_UB1         (0x1U<<29U)
#define LPDMA_C1LLR_USA         (0x1U<<28U)
#define LPDMA_C1LLR_UDA         (0x1U<<27U)
#define LPDMA_C1LLR_ULL         (0x1U<<16U)
#define LPDMA_C1LLR_LA          (0x3FFFU<<2U)
#define LPDMA_C1LLR_LA_0        (0x1U<<2U)

// C2LBAR Configuration

#define LPDMA_C2LBAR_LBA        (0xFFFFU<<16U)
#define LPDMA_C2LBAR_LBA_0      (0x1U<<16U)

// C2FCR Configuration

#define LPDMA_C2FCR_SUSPF       (0x1U<<13U)
#define LPDMA_C2FCR_USEF        (0x1U<<12U)
#define LPDMA_C2FCR_ULEF        (0x1U<<11U)
#define LPDMA_C2FCR_DTEF        (0x1U<<10U)
#define LPDMA_C2FCR_HTF         (0x1U<<9U)
#define LPDMA_C2FCR_TCF         (0x1U<<8U)

// C2SR Configuration

#define LPDMA_C2SR_SUSPF        (0x1U<<13U)
#define LPDMA_C2SR_USEF         (0x1U<<12U)
#define LPDMA_C2SR_ULEF         (0x1U<<11U)
#define LPDMA_C2SR_DTEF         (0x1U<<10U)
#define LPDMA_C2SR_HTF          (0x1U<<9U)
#define LPDMA_C2SR_TCF          (0x1U<<8U)
#define LPDMA_C2SR_IDLEF        (0x1U<<0U)

// C2CR Configuration

#define LPDMA_C2CR_PRIO         (0x3U<<22U)
#define LPDMA_C2CR_PRIO_0       (0x1U<<22U)
#define LPDMA_C2CR_LSM          (0x1U<<16U)
#define LPDMA_C2CR_SUSPIE       (0x1U<<13U)
#define LPDMA_C2CR_USEIE        (0x1U<<12U)
#define LPDMA_C2CR_ULEIE        (0x1U<<11U)
#define LPDMA_C2CR_DTEIE        (0x1U<<10U)
#define LPDMA_C2CR_HTIE         (0x1U<<9U)
#define LPDMA_C2CR_TCIE         (0x1U<<8U)
#define LPDMA_C2CR_SUSP         (0x1U<<2U)
#define LPDMA_C2CR_RESET        (0x1U<<1U)
#define LPDMA_C2CR_EN           (0x1U<<0U)

// C2TR1 Configuration

#define LPDMA_C2TR1_DSEC        (0x1U<<31U)
#define LPDMA_C2TR1_DINC        (0x1U<<19U)
#define LPDMA_C2TR1_DDW_LOG2    (0x3U<<16U)
#define LPDMA_C2TR1_DDW_LOG2_0  (0x1U<<16U)
#define LPDMA_C2TR1_SSEC        (0x1U<<15U)
#define LPDMA_C2TR1_PAM         (0x3U<<11U)
#define LPDMA_C2TR1_PAM_0       (0x1U<<11U)
#define LPDMA_C2TR1_SINC        (0x1U<<3U)
#define LPDMA_C2TR1_SDW_LOG2    (0x3U<<0U)
#define LPDMA_C2TR1_SDW_LOG2_0  (0x1U<<0U)

// C2TR2 Configuration

#define LPDMA_C2TR2_TCEM        (0x3U<<30U)
#define LPDMA_C2TR2_TCEM_0      (0x1U<<30U)
#define LPDMA_C2TR2_TRIGPOL     (0x3U<<24U)
#define LPDMA_C2TR2_TRIGPOL_0   (0x1U<<24U)
#define LPDMA_C2TR2_TRIGSEL     (0x1FU<<16U)
#define LPDMA_C2TR2_TRIGSEL_0   (0x1U<<16U)
#define LPDMA_C2TR2_TRIGM       (0x3U<<14U)
#define LPDMA_C2TR2_TRIGM_0     (0x1U<<14U)
#define LPDMA_C2TR2_BREQ        (0x1U<<11U)
#define LPDMA_C2TR2_SWREQ       (0x1U<<9U)
#define LPDMA_C2TR2_REQSEL      (0x1FU<<0U)
#define LPDMA_C2TR2_REQSEL_0    (0x1U<<0U)

// C2BR1 Configuration

#define LPDMA_C2BR1_BNDT        (0xFFFFU<<0U)
#define LPDMA_C2BR1_BNDT_0      (0x1U<<0U)

// C2SAR Configuration

#define LPDMA_C2SAR_SA          (0xFFFFFFFFU<<0U)
#define LPDMA_C2SAR_SA_0        (0x1U<<0U)

// C2DAR Configuration

#define LPDMA_C2DAR_DA          (0xFFFFFFFFU<<0U)
#define LPDMA_C2DAR_DA_0        (0x1U<<0U)

// C2LLR Configuration

#define LPDMA_C2LLR_UT1         (0x1U<<31U)
#define LPDMA_C2LLR_UT2         (0x1U<<30U)
#define LPDMA_C2LLR_UB1         (0x1U<<29U)
#define LPDMA_C2LLR_USA         (0x1U<<28U)
#define LPDMA_C2LLR_UDA         (0x1U<<27U)
#define LPDMA_C2LLR_ULL         (0x1U<<16U)
#define LPDMA_C2LLR_LA          (0x3FFFU<<2U)
#define LPDMA_C2LLR_LA_0        (0x1U<<2U)

// C3LBAR Configuration

#define LPDMA_C3LBAR_LBA        (0xFFFFU<<16U)
#define LPDMA_C3LBAR_LBA_0      (0x1U<<16U)

// C3FCR Configuration

#define LPDMA_C3FCR_SUSPF       (0x1U<<13U)
#define LPDMA_C3FCR_USEF        (0x1U<<12U)
#define LPDMA_C3FCR_ULEF        (0x1U<<11U)
#define LPDMA_C3FCR_DTEF        (0x1U<<10U)
#define LPDMA_C3FCR_HTF         (0x1U<<9U)
#define LPDMA_C3FCR_TCF         (0x1U<<8U)

// C3SR Configuration

#define LPDMA_C3SR_SUSPF        (0x1U<<13U)
#define LPDMA_C3SR_USEF         (0x1U<<12U)
#define LPDMA_C3SR_ULEF         (0x1U<<11U)
#define LPDMA_C3SR_DTEF         (0x1U<<10U)
#define LPDMA_C3SR_HTF          (0x1U<<9U)
#define LPDMA_C3SR_TCF          (0x1U<<8U)
#define LPDMA_C3SR_IDLEF        (0x1U<<0U)

// C3CR Configuration

#define LPDMA_C3CR_PRIO         (0x3U<<22U)
#define LPDMA_C3CR_PRIO_0       (0x1U<<22U)
#define LPDMA_C3CR_LSM          (0x1U<<16U)
#define LPDMA_C3CR_SUSPIE       (0x1U<<13U)
#define LPDMA_C3CR_USEIE        (0x1U<<12U)
#define LPDMA_C3CR_ULEIE        (0x1U<<11U)
#define LPDMA_C3CR_DTEIE        (0x1U<<10U)
#define LPDMA_C3CR_HTIE         (0x1U<<9U)
#define LPDMA_C3CR_TCIE         (0x1U<<8U)
#define LPDMA_C3CR_SUSP         (0x1U<<2U)
#define LPDMA_C3CR_RESET        (0x1U<<1U)
#define LPDMA_C3CR_EN           (0x1U<<0U)

// C3TR1 Configuration

#define LPDMA_C3TR1_DSEC        (0x1U<<31U)
#define LPDMA_C3TR1_DINC        (0x1U<<19U)
#define LPDMA_C3TR1_DDW_LOG2    (0x3U<<16U)
#define LPDMA_C3TR1_DDW_LOG2_0  (0x1U<<16U)
#define LPDMA_C3TR1_SSEC        (0x1U<<15U)
#define LPDMA_C3TR1_PAM         (0x3U<<11U)
#define LPDMA_C3TR1_PAM_0       (0x1U<<11U)
#define LPDMA_C3TR1_SINC        (0x1U<<3U)
#define LPDMA_C3TR1_SDW_LOG2    (0x3U<<0U)
#define LPDMA_C3TR1_SDW_LOG2_0  (0x1U<<0U)

// C3TR2 Configuration

#define LPDMA_C3TR2_TCEM        (0x3U<<30U)
#define LPDMA_C3TR2_TCEM_0      (0x1U<<30U)
#define LPDMA_C3TR2_TRIGPOL     (0x3U<<24U)
#define LPDMA_C3TR2_TRIGPOL_0   (0x1U<<24U)
#define LPDMA_C3TR2_TRIGSEL     (0x1FU<<16U)
#define LPDMA_C3TR2_TRIGSEL_0   (0x1U<<16U)
#define LPDMA_C3TR2_TRIGM       (0x3U<<14U)
#define LPDMA_C3TR2_TRIGM_0     (0x1U<<14U)
#define LPDMA_C3TR2_BREQ        (0x1U<<11U)
#define LPDMA_C3TR2_SWREQ       (0x1U<<9U)
#define LPDMA_C3TR2_REQSEL      (0x1FU<<0U)
#define LPDMA_C3TR2_REQSEL_0    (0x1U<<0U)

// C3BR1 Configuration

#define LPDMA_C3BR1_BNDT        (0xFFFFU<<0U)
#define LPDMA_C3BR1_BNDT_0      (0x1U<<0U)

// C3SAR Configuration

#define LPDMA_C3SAR_SA          (0xFFFFFFFFU<<0U)
#define LPDMA_C3SAR_SA_0        (0x1U<<0U)

// C3DAR Configuration

#define LPDMA_C3DAR_DA          (0xFFFFFFFFU<<0U)
#define LPDMA_C3DAR_DA_0        (0x1U<<0U)

// C3LLR Configuration

#define LPDMA_C3LLR_UT1         (0x1U<<31U)
#define LPDMA_C3LLR_UT2         (0x1U<<30U)
#define LPDMA_C3LLR_UB1         (0x1U<<29U)
#define LPDMA_C3LLR_USA         (0x1U<<28U)
#define LPDMA_C3LLR_UDA         (0x1U<<27U)
#define LPDMA_C3LLR_ULL         (0x1U<<16U)
#define LPDMA_C3LLR_LA          (0x3FFFU<<2U)
#define LPDMA_C3LLR_LA_0        (0x1U<<2U)
