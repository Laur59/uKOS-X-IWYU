/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32N657_usart.
; ================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32N657_usart equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;                                              __ ______  _____
;   Edo. Franzi                         __  __/ //_/ __ \/ ___/
;   5-Route de Cheseaux                / / / / ,< / / / /\__ \
;   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
;                                     \__,_/_/ |_\____//____/
;   edo.franzi@ukos.ch
;
;   Description: Lightweight, real-time multitasking operating
;   system for embedded microcontroller and DSP-based systems.
;
;   Permission is hereby granted, free of charge, to any person
;   obtaining a copy of this software and associated documentation
;   files (the "Software"), to deal in the Software without restriction,
;   including without limitation the rights to use, copy, modify,
;   merge, publish, distribute, sublicense, and/or sell copies of the
;   Software, and to permit persons to whom the Software is furnished
;   to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be
;   included in all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
;   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
;   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
;   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
;   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;   SOFTWARE.
;
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// USART address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    CR1_FIFO;
    volatile    uint32_t    CR2;
    volatile    uint32_t    CR3;
    volatile    uint32_t    BRR;
    volatile    uint32_t    GTPR;
    volatile    uint32_t    RTOR;
    volatile    uint32_t    RQR;
    volatile    uint32_t    ISR_FIFO;
    volatile    uint32_t    ICR;
    volatile    uint32_t    RDR;
    volatile    uint32_t    TDR;
    volatile    uint32_t    PRESC;
} USART_TypeDef;

#ifdef __cplusplus
#define USART1_NS   reinterpret_cast<USART_TypeDef *>(0x42001000U)
#define USART1_S    reinterpret_cast<USART_TypeDef *>(0x52001000U)
#define USART2_NS   reinterpret_cast<USART_TypeDef *>(0x40004400U)
#define USART2_S    reinterpret_cast<USART_TypeDef *>(0x50004400U)
#define USART3_NS   reinterpret_cast<USART_TypeDef *>(0x40004800U)
#define USART3_S    reinterpret_cast<USART_TypeDef *>(0x50004800U)
#define UART4_NS    reinterpret_cast<USART_TypeDef *>(0x40004C00U)
#define UART4_S     reinterpret_cast<USART_TypeDef *>(0x50004C00U)
#define UART5_NS    reinterpret_cast<USART_TypeDef *>(0x40005000U)
#define UART5_S     reinterpret_cast<USART_TypeDef *>(0x50005000U)
#define USART6_NS   reinterpret_cast<USART_TypeDef *>(0x42001400U)
#define USART6_S    reinterpret_cast<USART_TypeDef *>(0x52001400U)
#define UART7_NS    reinterpret_cast<USART_TypeDef *>(0x40007800U)
#define UART7_S     reinterpret_cast<USART_TypeDef *>(0x50007800U)
#define UART8_NS    reinterpret_cast<USART_TypeDef *>(0x40007C00U)
#define UART8_S     reinterpret_cast<USART_TypeDef *>(0x50007C00U)
#define UART9_NS    reinterpret_cast<USART_TypeDef *>(0x42001800U)
#define UART9_S     reinterpret_cast<USART_TypeDef *>(0x52001800U)
#define USART10_NS  reinterpret_cast<USART_TypeDef *>(0x42001C00U)
#define USART10_S   reinterpret_cast<USART_TypeDef *>(0x52001C00U)

#else
#define USART1_NS   ((USART_TypeDef *)0x42001000U)
#define USART1_S    ((USART_TypeDef *)0x52001000U)
#define USART2_NS   ((USART_TypeDef *)0x40004400U)
#define USART2_S    ((USART_TypeDef *)0x50004400U)
#define USART3_NS   ((USART_TypeDef *)0x40004800U)
#define USART3_S    ((USART_TypeDef *)0x50004800U)
#define UART4_NS    ((USART_TypeDef *)0x40004C00U)
#define UART4_S     ((USART_TypeDef *)0x50004C00U)
#define UART5_NS    ((USART_TypeDef *)0x40005000U)
#define UART5_S     ((USART_TypeDef *)0x50005000U)
#define USART6_NS   ((USART_TypeDef *)0x42001400U)
#define USART6_S    ((USART_TypeDef *)0x52001400U)
#define UART7_NS    ((USART_TypeDef *)0x40007800U)
#define UART7_S     ((USART_TypeDef *)0x50007800U)
#define UART8_NS    ((USART_TypeDef *)0x40007C00U)
#define UART8_S     ((USART_TypeDef *)0x50007C00U)
#define UART9_NS    ((USART_TypeDef *)0x42001800U)
#define UART9_S     ((USART_TypeDef *)0x52001800U)
#define USART10_NS  ((USART_TypeDef *)0x42001C00U)
#define USART10_S   ((USART_TypeDef *)0x52001C00U)
#endif

// CR1_FIFO Configuration

#define USART_CR1_FIFO_RXFFIE                                       (0x1U<<31)
#define USART_CR1_FIFO_TXFEIE                                       (0x1U<<30)
#define USART_CR1_FIFO_FIFOEN                                       (0x1U<<29)
#define USART_CR1_FIFO_M1                                           (0x1U<<28)
#define USART_CR1_FIFO_EOBIE                                        (0x1U<<27)
#define USART_CR1_FIFO_RTOIE                                        (0x1U<<26)
#define USART_CR1_FIFO_DEAT                                         (0x1FU<<21)
#define USART_CR1_FIFO_DEAT_0                                       (0x1U<<21)
#define USART_CR1_FIFO_DEDT                                         (0x1FU<<16)
#define USART_CR1_FIFO_DEDT_0                                       (0x1U<<16)
#define USART_CR1_FIFO_OVER8                                        (0x1U<<15)
#define USART_CR1_FIFO_CMIE                                         (0x1U<<14)
#define USART_CR1_FIFO_MME                                          (0x1U<<13)
#define USART_CR1_FIFO_M0                                           (0x1U<<12)
#define USART_CR1_FIFO_WAKE                                         (0x1U<<11)
#define USART_CR1_FIFO_PCE                                          (0x1U<<10)
#define USART_CR1_FIFO_PS                                           (0x1U<<9)
#define USART_CR1_FIFO_PEIE                                         (0x1U<<8)
#define USART_CR1_FIFO_TXFNFIE                                      (0x1U<<7)
#define USART_CR1_FIFO_TCIE                                         (0x1U<<6)
#define USART_CR1_FIFO_RXFNEIE                                      (0x1U<<5)
#define USART_CR1_FIFO_IDLEIE                                       (0x1U<<4)
#define USART_CR1_FIFO_TE                                           (0x1U<<3)
#define USART_CR1_FIFO_RE                                           (0x1U<<2)
#define USART_CR1_FIFO_UESM                                         (0x1U<<1)
#define USART_CR1_FIFO_UE                                           (0x1U<<0)

#define USART_CR1_FIFO_RXFFIE_B_0X0                                 (0x0U<<31)
#define USART_CR1_FIFO_RXFFIE_B_0X1                                 (0x1U<<31)
#define USART_CR1_FIFO_TXFEIE_B_0X0                                 (0x0U<<30)
#define USART_CR1_FIFO_TXFEIE_B_0X1                                 (0x1U<<30)
#define USART_CR1_FIFO_FIFOEN_B_0X0                                 (0x0U<<29)
#define USART_CR1_FIFO_FIFOEN_B_0X1                                 (0x1U<<29)
#define USART_CR1_FIFO_EOBIE_B_0X0                                  (0x0U<<27)
#define USART_CR1_FIFO_EOBIE_B_0X1                                  (0x1U<<27)
#define USART_CR1_FIFO_RTOIE_B_0X0                                  (0x0U<<26)
#define USART_CR1_FIFO_RTOIE_B_0X1                                  (0x1U<<26)
#define USART_CR1_FIFO_OVER8_B_0X0                                  (0x0U<<15)
#define USART_CR1_FIFO_OVER8_B_0X1                                  (0x1U<<15)
#define USART_CR1_FIFO_CMIE_B_0X0                                   (0x0U<<14)
#define USART_CR1_FIFO_CMIE_B_0X1                                   (0x1U<<14)
#define USART_CR1_FIFO_MME_B_0X0                                    (0x0U<<13)
#define USART_CR1_FIFO_MME_B_0X1                                    (0x1U<<13)
#define USART_CR1_FIFO_WAKE_B_0X0                                   (0x0U<<11)
#define USART_CR1_FIFO_WAKE_B_0X1                                   (0x1U<<11)
#define USART_CR1_FIFO_PCE_B_0X0                                    (0x0U<<10)
#define USART_CR1_FIFO_PCE_B_0X1                                    (0x1U<<10)
#define USART_CR1_FIFO_PS_B_0X0                                     (0x0U<<9)
#define USART_CR1_FIFO_PS_B_0X1                                     (0x1U<<9)
#define USART_CR1_FIFO_PEIE_B_0X0                                   (0x0U<<8)
#define USART_CR1_FIFO_PEIE_B_0X1                                   (0x1U<<8)
#define USART_CR1_FIFO_TXFNFIE_B_0X0                                (0x0U<<7)
#define USART_CR1_FIFO_TXFNFIE_B_0X1                                (0x1U<<7)
#define USART_CR1_FIFO_TCIE_B_0X0                                   (0x0U<<6)
#define USART_CR1_FIFO_TCIE_B_0X1                                   (0x1U<<6)
#define USART_CR1_FIFO_RXFNEIE_B_0X0                                (0x0U<<5)
#define USART_CR1_FIFO_RXFNEIE_B_0X1                                (0x1U<<5)
#define USART_CR1_FIFO_IDLEIE_B_0X0                                 (0x0U<<4)
#define USART_CR1_FIFO_IDLEIE_B_0X1                                 (0x1U<<4)
#define USART_CR1_FIFO_TE_B_0X0                                     (0x0U<<3)
#define USART_CR1_FIFO_TE_B_0X1                                     (0x1U<<3)
#define USART_CR1_FIFO_RE_B_0X0                                     (0x0U<<2)
#define USART_CR1_FIFO_RE_B_0X1                                     (0x1U<<2)
#define USART_CR1_FIFO_UESM_B_0X0                                   (0x0U<<1)
#define USART_CR1_FIFO_UESM_B_0X1                                   (0x1U<<1)
#define USART_CR1_FIFO_UE_B_0X0                                     (0x0U<<0)
#define USART_CR1_FIFO_UE_B_0X1                                     (0x1U<<0)

// CR2 Configuration

#define USART_CR2_ADD                                               (0xFFU<<24)
#define USART_CR2_ADD_0                                             (0x1U<<24)
#define USART_CR2_RTOEN                                             (0x1U<<23)
#define USART_CR2_ABRMOD                                            (0x3U<<21)
#define USART_CR2_ABRMOD_0                                          (0x1U<<21)
#define USART_CR2_ABREN                                             (0x1U<<20)
#define USART_CR2_MSBFIRST                                          (0x1U<<19)
#define USART_CR2_DATAINV                                           (0x1U<<18)
#define USART_CR2_TXINV                                             (0x1U<<17)
#define USART_CR2_RXINV                                             (0x1U<<16)
#define USART_CR2_SWAP                                              (0x1U<<15)
#define USART_CR2_LINEN                                             (0x1U<<14)
#define USART_CR2_STOP                                              (0x3U<<12)
#define USART_CR2_STOP_0                                            (0x1U<<12)
#define USART_CR2_CLKEN                                             (0x1U<<11)
#define USART_CR2_CPOL                                              (0x1U<<10)
#define USART_CR2_CPHA                                              (0x1U<<9)
#define USART_CR2_LBCL                                              (0x1U<<8)
#define USART_CR2_LBDIE                                             (0x1U<<6)
#define USART_CR2_LBDL                                              (0x1U<<5)
#define USART_CR2_ADDM7                                             (0x1U<<4)
#define USART_CR2_DIS_NSS                                           (0x1U<<3)
#define USART_CR2_SLVEN                                             (0x1U<<0)

#define USART_CR2_RTOEN_B_0X0                                       (0x0U<<23)
#define USART_CR2_RTOEN_B_0X1                                       (0x1U<<23)
#define USART_CR2_ABRMOD_B_0X0                                      (0x0U<<21)
#define USART_CR2_ABRMOD_B_0X1                                      (0x1U<<21)
#define USART_CR2_ABRMOD_B_0X2                                      (0x2U<<21)
#define USART_CR2_ABRMOD_B_0X3                                      (0x3U<<21)
#define USART_CR2_ABREN_B_0X0                                       (0x0U<<20)
#define USART_CR2_ABREN_B_0X1                                       (0x1U<<20)
#define USART_CR2_MSBFIRST_B_0X0                                    (0x0U<<19)
#define USART_CR2_MSBFIRST_B_0X1                                    (0x1U<<19)
#define USART_CR2_DATAINV_B_0X0                                     (0x0U<<18)
#define USART_CR2_DATAINV_B_0X1                                     (0x1U<<18)
#define USART_CR2_TXINV_B_0X0                                       (0x0U<<17)
#define USART_CR2_TXINV_B_0X1                                       (0x1U<<17)
#define USART_CR2_RXINV_B_0X0                                       (0x0U<<16)
#define USART_CR2_RXINV_B_0X1                                       (0x1U<<16)
#define USART_CR2_SWAP_B_0X0                                        (0x0U<<15)
#define USART_CR2_SWAP_B_0X1                                        (0x1U<<15)
#define USART_CR2_LINEN_B_0X0                                       (0x0U<<14)
#define USART_CR2_LINEN_B_0X1                                       (0x1U<<14)
#define USART_CR2_STOP_B_0X0                                        (0x0U<<12)
#define USART_CR2_STOP_B_0X1                                        (0x1U<<12)
#define USART_CR2_STOP_B_0X2                                        (0x2U<<12)
#define USART_CR2_STOP_B_0X3                                        (0x3U<<12)
#define USART_CR2_CLKEN_B_0X0                                       (0x0U<<11)
#define USART_CR2_CLKEN_B_0X1                                       (0x1U<<11)
#define USART_CR2_CPOL_B_0X0                                        (0x0U<<10)
#define USART_CR2_CPOL_B_0X1                                        (0x1U<<10)
#define USART_CR2_CPHA_B_0X0                                        (0x0U<<9)
#define USART_CR2_CPHA_B_0X1                                        (0x1U<<9)
#define USART_CR2_LBCL_B_0X0                                        (0x0U<<8)
#define USART_CR2_LBCL_B_0X1                                        (0x1U<<8)
#define USART_CR2_LBDIE_B_0X0                                       (0x0U<<6)
#define USART_CR2_LBDIE_B_0X1                                       (0x1U<<6)
#define USART_CR2_LBDL_B_0X0                                        (0x0U<<5)
#define USART_CR2_LBDL_B_0X1                                        (0x1U<<5)
#define USART_CR2_ADDM7_B_0X0                                       (0x0U<<4)
#define USART_CR2_ADDM7_B_0X1                                       (0x1U<<4)
#define USART_CR2_DIS_NSS_B_0X0                                     (0x0U<<3)
#define USART_CR2_DIS_NSS_B_0X1                                     (0x1U<<3)
#define USART_CR2_SLVEN_B_0X0                                       (0x0U<<0)
#define USART_CR2_SLVEN_B_0X1                                       (0x1U<<0)

// CR3 Configuration

#define USART_CR3_TXFTCFG                                           (0x7U<<29)
#define USART_CR3_TXFTCFG_0                                         (0x1U<<29)
#define USART_CR3_RXFTIE                                            (0x1U<<28)
#define USART_CR3_RXFTCFG                                           (0x7U<<25)
#define USART_CR3_RXFTCFG_0                                         (0x1U<<25)
#define USART_CR3_TCBGTIE                                           (0x1U<<24)
#define USART_CR3_TXFTIE                                            (0x1U<<23)
#define USART_CR3_WUFIE                                             (0x1U<<22)
#define USART_CR3_WUS1                                              (0x1U<<21)
#define USART_CR3_WUS0                                              (0x1U<<20)
#define USART_CR3_SCARCNT                                           (0x7U<<17)
#define USART_CR3_SCARCNT_0                                         (0x1U<<17)
#define USART_CR3_DEP                                               (0x1U<<15)
#define USART_CR3_DEM                                               (0x1U<<14)
#define USART_CR3_DDRE                                              (0x1U<<13)
#define USART_CR3_OVRDIS                                            (0x1U<<12)
#define USART_CR3_ONEBIT                                            (0x1U<<11)
#define USART_CR3_CTSIE                                             (0x1U<<10)
#define USART_CR3_CTSE                                              (0x1U<<9)
#define USART_CR3_RTSE                                              (0x1U<<8)
#define USART_CR3_DMAT                                              (0x1U<<7)
#define USART_CR3_DMAR                                              (0x1U<<6)
#define USART_CR3_SCEN                                              (0x1U<<5)
#define USART_CR3_NACK                                              (0x1U<<4)
#define USART_CR3_HDSEL                                             (0x1U<<3)
#define USART_CR3_IRLP                                              (0x1U<<2)
#define USART_CR3_IREN                                              (0x1U<<1)
#define USART_CR3_EIE                                               (0x1U<<0)

#define USART_CR3_TXFTCFG_B_0X0                                     (0x0U<<29)
#define USART_CR3_TXFTCFG_B_0X1                                     (0x1U<<29)
#define USART_CR3_TXFTCFG_B_0X2                                     (0x2U<<29)
#define USART_CR3_TXFTCFG_B_0X3                                     (0x3U<<29)
#define USART_CR3_TXFTCFG_B_0X4                                     (0x4U<<29)
#define USART_CR3_TXFTCFG_B_0X5                                     (0x5U<<29)
#define USART_CR3_RXFTIE_B_0X0                                      (0x0U<<28)
#define USART_CR3_RXFTIE_B_0X1                                      (0x1U<<28)
#define USART_CR3_RXFTCFG_B_0X0                                     (0x0U<<25)
#define USART_CR3_RXFTCFG_B_0X1                                     (0x1U<<25)
#define USART_CR3_RXFTCFG_B_0X2                                     (0x2U<<25)
#define USART_CR3_RXFTCFG_B_0X3                                     (0x3U<<25)
#define USART_CR3_RXFTCFG_B_0X4                                     (0x4U<<25)
#define USART_CR3_RXFTCFG_B_0X5                                     (0x5U<<25)
#define USART_CR3_TCBGTIE_B_0X0                                     (0x0U<<24)
#define USART_CR3_TCBGTIE_B_0X1                                     (0x1U<<24)
#define USART_CR3_TXFTIE_B_0X0                                      (0x0U<<23)
#define USART_CR3_TXFTIE_B_0X1                                      (0x1U<<23)
#define USART_CR3_WUFIE_B_0X0                                       (0x0U<<22)
#define USART_CR3_WUFIE_B_0X1                                       (0x1U<<22)
#define USART_CR3_WUS1_B_0X0                                        (0x0U<<21)
#define USART_CR3_WUS0_B_0X0                                        (0x0U<<20)
#define USART_CR3_SCARCNT_B_0X0                                     (0x0U<<17)
#define USART_CR3_DEP_B_0X0                                         (0x0U<<15)
#define USART_CR3_DEP_B_0X1                                         (0x1U<<15)
#define USART_CR3_DEM_B_0X0                                         (0x0U<<14)
#define USART_CR3_DEM_B_0X1                                         (0x1U<<14)
#define USART_CR3_DDRE_B_0X0                                        (0x0U<<13)
#define USART_CR3_DDRE_B_0X1                                        (0x1U<<13)
#define USART_CR3_OVRDIS_B_0X0                                      (0x0U<<12)
#define USART_CR3_OVRDIS_B_0X1                                      (0x1U<<12)
#define USART_CR3_ONEBIT_B_0X0                                      (0x0U<<11)
#define USART_CR3_ONEBIT_B_0X1                                      (0x1U<<11)
#define USART_CR3_CTSIE_B_0X0                                       (0x0U<<10)
#define USART_CR3_CTSIE_B_0X1                                       (0x1U<<10)
#define USART_CR3_CTSE_B_0X0                                        (0x0U<<9)
#define USART_CR3_CTSE_B_0X1                                        (0x1U<<9)
#define USART_CR3_RTSE_B_0X0                                        (0x0U<<8)
#define USART_CR3_RTSE_B_0X1                                        (0x1U<<8)
#define USART_CR3_DMAT_B_0X1                                        (0x1U<<7)
#define USART_CR3_DMAT_B_0X0                                        (0x0U<<7)
#define USART_CR3_DMAR_B_0X1                                        (0x1U<<6)
#define USART_CR3_DMAR_B_0X0                                        (0x0U<<6)
#define USART_CR3_SCEN_B_0X0                                        (0x0U<<5)
#define USART_CR3_SCEN_B_0X1                                        (0x1U<<5)
#define USART_CR3_NACK_B_0X0                                        (0x0U<<4)
#define USART_CR3_NACK_B_0X1                                        (0x1U<<4)
#define USART_CR3_HDSEL_B_0X0                                       (0x0U<<3)
#define USART_CR3_HDSEL_B_0X1                                       (0x1U<<3)
#define USART_CR3_IRLP_B_0X0                                        (0x0U<<2)
#define USART_CR3_IRLP_B_0X1                                        (0x1U<<2)
#define USART_CR3_IREN_B_0X0                                        (0x0U<<1)
#define USART_CR3_IREN_B_0X1                                        (0x1U<<1)
#define USART_CR3_EIE_B_0X0                                         (0x0U<<0)
#define USART_CR3_EIE_B_0X1                                         (0x1U<<0)

// BRR Configuration

#define USART_BRR_BRR                                               (0xFFFFU<<0)
#define USART_BRR_BRR_0                                             (0x1U<<0)

// GTPR Configuration

#define USART_GTPR_GT                                               (0xFFU<<8)
#define USART_GTPR_GT_0                                             (0x1U<<8)
#define USART_GTPR_PSC                                              (0xFFU<<0)
#define USART_GTPR_PSC_0                                            (0x1U<<0)

#define USART_GTPR_PSC_B_0X1_IRDA_LOW_POWER_AND_NORMAL_IRDA_MODE    (0x1U<<0)
#define USART_GTPR_PSC_B_0X2_IRDA_LOW_POWER_AND_NORMAL_IRDA_MODE    (0x2U<<0)
#define USART_GTPR_PSC_B_0X3_SMARTCARD_MODE                         (0x3U<<0)

// RTOR Configuration

#define USART_RTOR_BLEN                                             (0xFFU<<24)
#define USART_RTOR_BLEN_0                                           (0x1U<<24)
#define USART_RTOR_RTO                                              (0xFFFFFFU<<0)
#define USART_RTOR_RTO_0                                            (0x1U<<0)

// RQR Configuration

#define USART_RQR_TXFRQ                                             (0x1U<<4)
#define USART_RQR_RXFRQ                                             (0x1U<<3)
#define USART_RQR_MMRQ                                              (0x1U<<2)
#define USART_RQR_SBKRQ                                             (0x1U<<1)
#define USART_RQR_ABRRQ                                             (0x1U<<0)

// ISR_FIFO Configuration

#define USART_ISR_FIFO_TXFT                                         (0x1U<<27)
#define USART_ISR_FIFO_RXFT                                         (0x1U<<26)
#define USART_ISR_FIFO_TCBGT                                        (0x1U<<25)
#define USART_ISR_FIFO_RXFF                                         (0x1U<<24)
#define USART_ISR_FIFO_TXFE                                         (0x1U<<23)
#define USART_ISR_FIFO_REACK                                        (0x1U<<22)
#define USART_ISR_FIFO_TEACK                                        (0x1U<<21)
#define USART_ISR_FIFO_WUF                                          (0x1U<<20)
#define USART_ISR_FIFO_RWU                                          (0x1U<<19)
#define USART_ISR_FIFO_SBKF                                         (0x1U<<18)
#define USART_ISR_FIFO_CMF                                          (0x1U<<17)
#define USART_ISR_FIFO_BUSY                                         (0x1U<<16)
#define USART_ISR_FIFO_ABRF                                         (0x1U<<15)
#define USART_ISR_FIFO_ABRE                                         (0x1U<<14)
#define USART_ISR_FIFO_UDR                                          (0x1U<<13)
#define USART_ISR_FIFO_EOBF                                         (0x1U<<12)
#define USART_ISR_FIFO_RTOF                                         (0x1U<<11)
#define USART_ISR_FIFO_CTS                                          (0x1U<<10)
#define USART_ISR_FIFO_CTSIF                                        (0x1U<<9)
#define USART_ISR_FIFO_LBDF                                         (0x1U<<8)
#define USART_ISR_FIFO_TXFNF                                        (0x1U<<7)
#define USART_ISR_FIFO_TC                                           (0x1U<<6)
#define USART_ISR_FIFO_RXFNE                                        (0x1U<<5)
#define USART_ISR_FIFO_IDLE                                         (0x1U<<4)
#define USART_ISR_FIFO_ORE                                          (0x1U<<3)
#define USART_ISR_FIFO_NE                                           (0x1U<<2)
#define USART_ISR_FIFO_FE                                           (0x1U<<1)
#define USART_ISR_FIFO_PE                                           (0x1U<<0)

#define USART_ISR_FIFO_TXFT_B_0X0                                   (0x0U<<27)
#define USART_ISR_FIFO_TXFT_B_0X1                                   (0x1U<<27)
#define USART_ISR_FIFO_RXFT_B_0X0                                   (0x0U<<26)
#define USART_ISR_FIFO_RXFT_B_0X1                                   (0x1U<<26)
#define USART_ISR_FIFO_TCBGT_B_0X0                                  (0x0U<<25)
#define USART_ISR_FIFO_TCBGT_B_0X1                                  (0x1U<<25)
#define USART_ISR_FIFO_RXFF_B_0X0                                   (0x0U<<24)
#define USART_ISR_FIFO_RXFF_B_0X1                                   (0x1U<<24)
#define USART_ISR_FIFO_TXFE_B_0X0                                   (0x0U<<23)
#define USART_ISR_FIFO_TXFE_B_0X1                                   (0x1U<<23)
#define USART_ISR_FIFO_RWU_B_0X0                                    (0x0U<<19)
#define USART_ISR_FIFO_RWU_B_0X1                                    (0x1U<<19)
#define USART_ISR_FIFO_SBKF_B_0X0                                   (0x0U<<18)
#define USART_ISR_FIFO_SBKF_B_0X1                                   (0x1U<<18)
#define USART_ISR_FIFO_CMF_B_0X0                                    (0x0U<<17)
#define USART_ISR_FIFO_CMF_B_0X1                                    (0x1U<<17)
#define USART_ISR_FIFO_BUSY_B_0X0                                   (0x0U<<16)
#define USART_ISR_FIFO_BUSY_B_0X1                                   (0x1U<<16)
#define USART_ISR_FIFO_UDR_B_0X0                                    (0x0U<<13)
#define USART_ISR_FIFO_UDR_B_0X1                                    (0x1U<<13)
#define USART_ISR_FIFO_EOBF_B_0X0                                   (0x0U<<12)
#define USART_ISR_FIFO_EOBF_B_0X1                                   (0x1U<<12)
#define USART_ISR_FIFO_RTOF_B_0X0                                   (0x0U<<11)
#define USART_ISR_FIFO_RTOF_B_0X1                                   (0x1U<<11)
#define USART_ISR_FIFO_CTS_B_0X0                                    (0x0U<<10)
#define USART_ISR_FIFO_CTS_B_0X1                                    (0x1U<<10)
#define USART_ISR_FIFO_CTSIF_B_0X0                                  (0x0U<<9)
#define USART_ISR_FIFO_CTSIF_B_0X1                                  (0x1U<<9)
#define USART_ISR_FIFO_LBDF_B_0X0                                   (0x0U<<8)
#define USART_ISR_FIFO_LBDF_B_0X1                                   (0x1U<<8)
#define USART_ISR_FIFO_TXFNF_B_0X0                                  (0x0U<<7)
#define USART_ISR_FIFO_TXFNF_B_0X1                                  (0x1U<<7)
#define USART_ISR_FIFO_RXFNE_B_0X0                                  (0x0U<<5)
#define USART_ISR_FIFO_RXFNE_B_0X1                                  (0x1U<<5)
#define USART_ISR_FIFO_IDLE_B_0X0                                   (0x0U<<4)
#define USART_ISR_FIFO_IDLE_B_0X1                                   (0x1U<<4)
#define USART_ISR_FIFO_ORE_B_0X0                                    (0x0U<<3)
#define USART_ISR_FIFO_ORE_B_0X1                                    (0x1U<<3)
#define USART_ISR_FIFO_NE_B_0X0                                     (0x0U<<2)
#define USART_ISR_FIFO_NE_B_0X1                                     (0x1U<<2)
#define USART_ISR_FIFO_FE_B_0X0                                     (0x0U<<1)
#define USART_ISR_FIFO_FE_B_0X1                                     (0x1U<<1)
#define USART_ISR_FIFO_PE_B_0X0                                     (0x0U<<0)
#define USART_ISR_FIFO_PE_B_0X1                                     (0x1U<<0)

// ICR Configuration

#define USART_ICR_WUCF                                              (0x1U<<20)
#define USART_ICR_CMCF                                              (0x1U<<17)
#define USART_ICR_UDRCF                                             (0x1U<<13)
#define USART_ICR_EOBCF                                             (0x1U<<12)
#define USART_ICR_RTOCF                                             (0x1U<<11)
#define USART_ICR_CTSCF                                             (0x1U<<9)
#define USART_ICR_LBDCF                                             (0x1U<<8)
#define USART_ICR_TCBGTCF                                           (0x1U<<7)
#define USART_ICR_TCCF                                              (0x1U<<6)
#define USART_ICR_TXFECF                                            (0x1U<<5)
#define USART_ICR_IDLECF                                            (0x1U<<4)
#define USART_ICR_ORECF                                             (0x1U<<3)
#define USART_ICR_NECF                                              (0x1U<<2)
#define USART_ICR_FECF                                              (0x1U<<1)
#define USART_ICR_PECF                                              (0x1U<<0)

// RDR Configuration

#define USART_RDR_RDR                                               (0x1FFU<<0)
#define USART_RDR_RDR_0                                             (0x1U<<0)

// TDR Configuration

#define USART_TDR_TDR                                               (0x1FFU<<0)
#define USART_TDR_TDR_0                                             (0x1U<<0)

// PRESC Configuration

#define USART_PRESC_PRESCALER                                       (0xFU<<0)
#define USART_PRESC_PRESCALER_0                                     (0x1U<<0)

#define USART_PRESC_PRESCALER_B_0X0                                 (0x0U<<0)
#define USART_PRESC_PRESCALER_B_0X1                                 (0x1U<<0)
#define USART_PRESC_PRESCALER_B_0X2                                 (0x2U<<0)
#define USART_PRESC_PRESCALER_B_0X3                                 (0x3U<<0)
#define USART_PRESC_PRESCALER_B_0X4                                 (0x4U<<0)
#define USART_PRESC_PRESCALER_B_0X5                                 (0x5U<<0)
#define USART_PRESC_PRESCALER_B_0X6                                 (0x6U<<0)
#define USART_PRESC_PRESCALER_B_0X7                                 (0x7U<<0)
#define USART_PRESC_PRESCALER_B_0X8                                 (0x8U<<0)
#define USART_PRESC_PRESCALER_B_0X9                                 (0x9U<<0)
#define USART_PRESC_PRESCALER_B_0XA                                 (0xAU<<0)
#define USART_PRESC_PRESCALER_B_0XB                                 (0xBU<<0)
