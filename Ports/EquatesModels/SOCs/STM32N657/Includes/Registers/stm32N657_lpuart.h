/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_lpuart equates.
 */

#pragma once

#include    <stdint.h>

// LPUART address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    CR1;
    volatile    uint32_t    CR2;
    volatile    uint32_t    CR3;
    volatile    uint32_t    BRR;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    RQR;
    volatile    uint32_t    ISR;
    volatile    uint32_t    ICR;
    volatile    uint32_t    RDR;
    volatile    uint32_t    TDR;
    volatile    uint32_t    PRESC;
} LPUART_TypeDef;

#ifdef __cplusplus
#define LPUART1_NS  reinterpret_cast<LPUART_TypeDef *>(0x46000C00U)
#define LPUART1_S   reinterpret_cast<LPUART_TypeDef *>(0x56000C00U)

#else
#define LPUART1_NS  ((LPUART_TypeDef *)0x46000C00U)
#define LPUART1_S   ((LPUART_TypeDef *)0x56000C00U)
#endif

// CR1 Configuration

#define LPUART_CR1_RXFFIE               (0x1U<<31U)
#define LPUART_CR1_TXFEIE               (0x1U<<30U)
#define LPUART_CR1_FIFOEN               (0x1U<<29U)
#define LPUART_CR1_M1                   (0x1U<<28U)
#define LPUART_CR1_DEAT                 (0x1FU<<21U)
#define LPUART_CR1_DEAT_0               (0x1U<<21U)
#define LPUART_CR1_DEDT                 (0x1FU<<16U)
#define LPUART_CR1_DEDT_0               (0x1U<<16U)
#define LPUART_CR1_CMIE                 (0x1U<<14U)
#define LPUART_CR1_MME                  (0x1U<<13U)
#define LPUART_CR1_M0                   (0x1U<<12U)
#define LPUART_CR1_WAKE                 (0x1U<<11U)
#define LPUART_CR1_PCE                  (0x1U<<10U)
#define LPUART_CR1_PS                   (0x1U<<9U)
#define LPUART_CR1_PEIE                 (0x1U<<8U)
#define LPUART_CR1_TXFNFIE              (0x1U<<7U)
#define LPUART_CR1_TCIE                 (0x1U<<6U)
#define LPUART_CR1_RXFNEIE              (0x1U<<5U)
#define LPUART_CR1_IDLEIE               (0x1U<<4U)
#define LPUART_CR1_TE                   (0x1U<<3U)
#define LPUART_CR1_RE                   (0x1U<<2U)
#define LPUART_CR1_UESM                 (0x1U<<1U)
#define LPUART_CR1_UE                   (0x1U<<0U)

#define LPUART_CR1_RXFFIE_B_0X0         (0x0U<<31U)
#define LPUART_CR1_RXFFIE_B_0X1         (0x1U<<31U)
#define LPUART_CR1_TXFEIE_B_0X0         (0x0U<<30U)
#define LPUART_CR1_TXFEIE_B_0X1         (0x1U<<30U)
#define LPUART_CR1_FIFOEN_B_0X0         (0x0U<<29U)
#define LPUART_CR1_FIFOEN_B_0X1         (0x1U<<29U)
#define LPUART_CR1_CMIE_B_0X0           (0x0U<<14U)
#define LPUART_CR1_CMIE_B_0X1           (0x1U<<14U)
#define LPUART_CR1_MME_B_0X0            (0x0U<<13U)
#define LPUART_CR1_MME_B_0X1            (0x1U<<13U)
#define LPUART_CR1_WAKE_B_0X0           (0x0U<<11U)
#define LPUART_CR1_WAKE_B_0X1           (0x1U<<11U)
#define LPUART_CR1_PCE_B_0X0            (0x0U<<10U)
#define LPUART_CR1_PCE_B_0X1            (0x1U<<10U)
#define LPUART_CR1_PS_B_0X0             (0x0U<<9U)
#define LPUART_CR1_PS_B_0X1             (0x1U<<9U)
#define LPUART_CR1_PEIE_B_0X0           (0x0U<<8U)
#define LPUART_CR1_PEIE_B_0X1           (0x1U<<8U)
#define LPUART_CR1_TXFNFIE_B_0X0        (0x0U<<7U)
#define LPUART_CR1_TXFNFIE_B_0X1        (0x1U<<7U)
#define LPUART_CR1_TCIE_B_0X0           (0x0U<<6U)
#define LPUART_CR1_TCIE_B_0X1           (0x1U<<6U)
#define LPUART_CR1_RXFNEIE_B_0X0        (0x0U<<5U)
#define LPUART_CR1_RXFNEIE_B_0X1        (0x1U<<5U)
#define LPUART_CR1_IDLEIE_B_0X0         (0x0U<<4U)
#define LPUART_CR1_IDLEIE_B_0X1         (0x1U<<4U)
#define LPUART_CR1_TE_B_0X0             (0x0U<<3U)
#define LPUART_CR1_TE_B_0X1             (0x1U<<3U)
#define LPUART_CR1_RE_B_0X0             (0x0U<<2U)
#define LPUART_CR1_RE_B_0X1             (0x1U<<2U)
#define LPUART_CR1_UESM_B_0X0           (0x0U<<1U)
#define LPUART_CR1_UESM_B_0X1           (0x1U<<1U)
#define LPUART_CR1_UE_B_0X0             (0x0U<<0U)
#define LPUART_CR1_UE_B_0X1             (0x1U<<0U)

// CR2 Configuration

#define LPUART_CR2_ADD                  (0xFFU<<24U)
#define LPUART_CR2_ADD_0                (0x1U<<24U)
#define LPUART_CR2_MSBFIRST             (0x1U<<19U)
#define LPUART_CR2_DATAINV              (0x1U<<18U)
#define LPUART_CR2_TXINV                (0x1U<<17U)
#define LPUART_CR2_RXINV                (0x1U<<16U)
#define LPUART_CR2_SWAP                 (0x1U<<15U)
#define LPUART_CR2_STOP                 (0x3U<<12U)
#define LPUART_CR2_STOP_0               (0x1U<<12U)
#define LPUART_CR2_ADDM7                (0x1U<<4U)

#define LPUART_CR2_MSBFIRST_B_0X0       (0x0U<<19U)
#define LPUART_CR2_MSBFIRST_B_0X1       (0x1U<<19U)
#define LPUART_CR2_DATAINV_B_0X0        (0x0U<<18U)
#define LPUART_CR2_DATAINV_B_0X1        (0x1U<<18U)
#define LPUART_CR2_TXINV_B_0X0          (0x0U<<17U)
#define LPUART_CR2_TXINV_B_0X1          (0x1U<<17U)
#define LPUART_CR2_RXINV_B_0X0          (0x0U<<16U)
#define LPUART_CR2_RXINV_B_0X1          (0x1U<<16U)
#define LPUART_CR2_SWAP_B_0X0           (0x0U<<15U)
#define LPUART_CR2_SWAP_B_0X1           (0x1U<<15U)
#define LPUART_CR2_STOP_B_0X0           (0x0U<<12U)
#define LPUART_CR2_STOP_B_0X2           (0x2U<<12U)
#define LPUART_CR2_ADDM7_B_0X0          (0x0U<<4U)
#define LPUART_CR2_ADDM7_B_0X1          (0x1U<<4U)

// CR3 Configuration

#define LPUART_CR3_TXFTCFG              (0x7U<<29U)
#define LPUART_CR3_TXFTCFG_0            (0x1U<<29U)
#define LPUART_CR3_RXFTIE               (0x1U<<28U)
#define LPUART_CR3_RXFTCFG              (0x7U<<25U)
#define LPUART_CR3_RXFTCFG_0            (0x1U<<25U)
#define LPUART_CR3_TXFTIE               (0x1U<<23U)
#define LPUART_CR3_WUFIE                (0x1U<<22U)
#define LPUART_CR3_WUS1                 (0x1U<<21U)
#define LPUART_CR3_WUS0                 (0x1U<<20U)
#define LPUART_CR3_DEP                  (0x1U<<15U)
#define LPUART_CR3_DEM                  (0x1U<<14U)
#define LPUART_CR3_DDRE                 (0x1U<<13U)
#define LPUART_CR3_OVRDIS               (0x1U<<12U)
#define LPUART_CR3_CTSIE                (0x1U<<10U)
#define LPUART_CR3_CTSE                 (0x1U<<9U)
#define LPUART_CR3_RTSE                 (0x1U<<8U)
#define LPUART_CR3_DMAT                 (0x1U<<7U)
#define LPUART_CR3_DMAR                 (0x1U<<6U)
#define LPUART_CR3_HDSEL                (0x1U<<3U)
#define LPUART_CR3_EIE                  (0x1U<<0U)

#define LPUART_CR3_TXFTCFG_B_0X0        (0x0U<<29U)
#define LPUART_CR3_TXFTCFG_B_0X1        (0x1U<<29U)
#define LPUART_CR3_TXFTCFG_B_0X6        (0x6U<<29U)
#define LPUART_CR3_TXFTCFG_B_0X3        (0x3U<<29U)
#define LPUART_CR3_TXFTCFG_B_0X4        (0x4U<<29U)
#define LPUART_CR3_TXFTCFG_B_0X5        (0x5U<<29U)
#define LPUART_CR3_RXFTIE_B_0X0         (0x0U<<28U)
#define LPUART_CR3_RXFTIE_B_0X1         (0x1U<<28U)
#define LPUART_CR3_RXFTCFG_B_0X0        (0x0U<<25U)
#define LPUART_CR3_RXFTCFG_B_0X1        (0x1U<<25U)
#define LPUART_CR3_RXFTCFG_B_0X6        (0x6U<<25U)
#define LPUART_CR3_RXFTCFG_B_0X3        (0x3U<<25U)
#define LPUART_CR3_RXFTCFG_B_0X4        (0x4U<<25U)
#define LPUART_CR3_RXFTCFG_B_0X5        (0x5U<<25U)
#define LPUART_CR3_TXFTIE_B_0X0         (0x0U<<23U)
#define LPUART_CR3_TXFTIE_B_0X1         (0x1U<<23U)
#define LPUART_CR3_WUFIE_B_0X0          (0x0U<<22U)
#define LPUART_CR3_WUFIE_B_0X1          (0x1U<<22U)
#define LPUART_CR3_WUS1_B_0X0           (0x0U<<21U)
#define LPUART_CR3_WUS0_B_0X0           (0x0U<<20U)
#define LPUART_CR3_DEP_B_0X0            (0x0U<<15U)
#define LPUART_CR3_DEP_B_0X1            (0x1U<<15U)
#define LPUART_CR3_DEM_B_0X0            (0x0U<<14U)
#define LPUART_CR3_DEM_B_0X1            (0x1U<<14U)
#define LPUART_CR3_DDRE_B_0X0           (0x0U<<13U)
#define LPUART_CR3_DDRE_B_0X1           (0x1U<<13U)
#define LPUART_CR3_OVRDIS_B_0X0         (0x0U<<12U)
#define LPUART_CR3_OVRDIS_B_0X1         (0x1U<<12U)
#define LPUART_CR3_CTSIE_B_0X0          (0x0U<<10U)
#define LPUART_CR3_CTSIE_B_0X1          (0x1U<<10U)
#define LPUART_CR3_CTSE_B_0X0           (0x0U<<9U)
#define LPUART_CR3_CTSE_B_0X1           (0x1U<<9U)
#define LPUART_CR3_RTSE_B_0X0           (0x0U<<8U)
#define LPUART_CR3_RTSE_B_0X1           (0x1U<<8U)
#define LPUART_CR3_DMAT_B_0X1           (0x1U<<7U)
#define LPUART_CR3_DMAT_B_0X0           (0x0U<<7U)
#define LPUART_CR3_DMAR_B_0X1           (0x1U<<6U)
#define LPUART_CR3_DMAR_B_0X0           (0x0U<<6U)
#define LPUART_CR3_HDSEL_B_0X0          (0x0U<<3U)
#define LPUART_CR3_HDSEL_B_0X1          (0x1U<<3U)
#define LPUART_CR3_EIE_B_0X0            (0x0U<<0U)
#define LPUART_CR3_EIE_B_0X1            (0x1U<<0U)

// BRR Configuration

#define LPUART_BRR_BRR                  (0xFFFFFU<<0U)
#define LPUART_BRR_BRR_0                (0x1U<<0U)

// RQR Configuration

#define LPUART_RQR_TXFRQ                (0x1U<<4U)
#define LPUART_RQR_RXFRQ                (0x1U<<3U)
#define LPUART_RQR_MMRQ                 (0x1U<<2U)
#define LPUART_RQR_SBKRQ                (0x1U<<1U)

// ISR Configuration

#define LPUART_ISR_TXFT                 (0x1U<<27U)
#define LPUART_ISR_RXFT                 (0x1U<<26U)
#define LPUART_ISR_RXFF                 (0x1U<<24U)
#define LPUART_ISR_TXFE                 (0x1U<<23U)
#define LPUART_ISR_REACK                (0x1U<<22U)
#define LPUART_ISR_TEACK                (0x1U<<21U)
#define LPUART_ISR_WUF                  (0x1U<<20U)
#define LPUART_ISR_RWU                  (0x1U<<19U)
#define LPUART_ISR_SBKF                 (0x1U<<18U)
#define LPUART_ISR_CMF                  (0x1U<<17U)
#define LPUART_ISR_BUSY                 (0x1U<<16U)
#define LPUART_ISR_CTS                  (0x1U<<10U)
#define LPUART_ISR_CTSIF                (0x1U<<9U)
#define LPUART_ISR_TXFNF                (0x1U<<7U)
#define LPUART_ISR_TC                   (0x1U<<6U)
#define LPUART_ISR_RXFNE                (0x1U<<5U)
#define LPUART_ISR_IDLE                 (0x1U<<4U)
#define LPUART_ISR_ORE                  (0x1U<<3U)
#define LPUART_ISR_NE                   (0x1U<<2U)
#define LPUART_ISR_FE                   (0x1U<<1U)
#define LPUART_ISR_PE                   (0x1U<<0U)

#define LPUART_ISR_TXFT_B_0X0           (0x0U<<27U)
#define LPUART_ISR_TXFT_B_0X1           (0x1U<<27U)
#define LPUART_ISR_RXFT_B_0X0           (0x0U<<26U)
#define LPUART_ISR_RXFT_B_0X1           (0x1U<<26U)
#define LPUART_ISR_RXFF_B_0X0           (0x0U<<24U)
#define LPUART_ISR_RXFF_B_0X1           (0x1U<<24U)
#define LPUART_ISR_TXFE_B_0X0           (0x0U<<23U)
#define LPUART_ISR_TXFE_B_0X1           (0x1U<<23U)
#define LPUART_ISR_RWU_B_0X0            (0x0U<<19U)
#define LPUART_ISR_RWU_B_0X1            (0x1U<<19U)
#define LPUART_ISR_SBKF_B_0X0           (0x0U<<18U)
#define LPUART_ISR_SBKF_B_0X1           (0x1U<<18U)
#define LPUART_ISR_CMF_B_0X0            (0x0U<<17U)
#define LPUART_ISR_CMF_B_0X1            (0x1U<<17U)
#define LPUART_ISR_BUSY_B_0X0           (0x0U<<16U)
#define LPUART_ISR_BUSY_B_0X1           (0x1U<<16U)
#define LPUART_ISR_CTS_B_0X0            (0x0U<<10U)
#define LPUART_ISR_CTS_B_0X1            (0x1U<<10U)
#define LPUART_ISR_CTSIF_B_0X0          (0x0U<<9U)
#define LPUART_ISR_CTSIF_B_0X1          (0x1U<<9U)
#define LPUART_ISR_TXFNF_B_0X0          (0x0U<<7U)
#define LPUART_ISR_TXFNF_B_0X1          (0x1U<<7U)
#define LPUART_ISR_RXFNE_B_0X0          (0x0U<<5U)
#define LPUART_ISR_RXFNE_B_0X1          (0x1U<<5U)
#define LPUART_ISR_IDLE_B_0X0           (0x0U<<4U)
#define LPUART_ISR_IDLE_B_0X1           (0x1U<<4U)
#define LPUART_ISR_ORE_B_0X1            (0x1U<<3U)
#define LPUART_ISR_NE_B_0X0             (0x0U<<2U)
#define LPUART_ISR_NE_B_0X1             (0x1U<<2U)
#define LPUART_ISR_FE_B_0X0             (0x0U<<1U)
#define LPUART_ISR_FE_B_0X1             (0x1U<<1U)
#define LPUART_ISR_PE_B_0X0             (0x0U<<0U)
#define LPUART_ISR_PE_B_0X1             (0x1U<<0U)

// ICR Configuration

#define LPUART_ICR_WUCF                 (0x1U<<20U)
#define LPUART_ICR_CMCF                 (0x1U<<17U)
#define LPUART_ICR_CTSCF                (0x1U<<9U)
#define LPUART_ICR_TCCF                 (0x1U<<6U)
#define LPUART_ICR_IDLECF               (0x1U<<4U)
#define LPUART_ICR_ORECF                (0x1U<<3U)
#define LPUART_ICR_NECF                 (0x1U<<2U)
#define LPUART_ICR_FECF                 (0x1U<<1U)
#define LPUART_ICR_PECF                 (0x1U<<0U)

// RDR Configuration

#define LPUART_RDR_RDR                  (0x1FFU<<0U)
#define LPUART_RDR_RDR_0                (0x1U<<0U)

// TDR Configuration

#define LPUART_TDR_TDR                  (0x1FFU<<0U)
#define LPUART_TDR_TDR_0                (0x1U<<0U)

// PRESC Configuration

#define LPUART_PRESC_PRESCALER          (0xFU<<0U)
#define LPUART_PRESC_PRESCALER_0        (0x1U<<0U)

#define LPUART_PRESC_PRESCALER_B_0X0    (0x0U<<0U)
#define LPUART_PRESC_PRESCALER_B_0X1    (0x1U<<0U)
#define LPUART_PRESC_PRESCALER_B_0X2    (0x2U<<0U)
#define LPUART_PRESC_PRESCALER_B_0X3    (0x3U<<0U)
#define LPUART_PRESC_PRESCALER_B_0X4    (0x4U<<0U)
#define LPUART_PRESC_PRESCALER_B_0X5    (0x5U<<0U)
#define LPUART_PRESC_PRESCALER_B_0X6    (0x6U<<0U)
#define LPUART_PRESC_PRESCALER_B_0X7    (0x7U<<0U)
#define LPUART_PRESC_PRESCALER_B_0X8    (0x8U<<0U)
#define LPUART_PRESC_PRESCALER_B_0X9    (0x9U<<0U)
#define LPUART_PRESC_PRESCALER_B_0XA    (0xAU<<0U)
#define LPUART_PRESC_PRESCALER_B_0XB    (0xBU<<0U)
