/*
; stm32V873_pwr.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32V873_pwr equates.
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

// PWR address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CR1;
    volatile    uint32_t    SR1;
    volatile    uint32_t    BDCR1;
    volatile    uint32_t    BDCR2;
    volatile    uint32_t    DBPCR;
    volatile    uint32_t    CR2;
    volatile    uint32_t    CSR1;
    volatile    uint32_t    CSR2;
    volatile    uint32_t    WKUPSCR;
    volatile    uint32_t    WKUPSR;
    volatile    uint32_t    WKUPCR;
    volatile    uint32_t    UCPDR;
    volatile    uint32_t    USBCSR;
    volatile    uint32_t    XSPICSR;
    volatile    uint32_t    IORETR;
    volatile    uint32_t    RESERVED0[49];
    volatile    uint32_t    SECCFGR;
    volatile    uint32_t    PRIVCFGR;
    volatile    uint32_t    LOCKCFGR;
} PWR_TypeDef;

#if (defined(__cplusplus))
#define PWR_NS  reinterpret_cast<PWR_TypeDef *>(0x46024800u)
#define PWR_S   reinterpret_cast<PWR_TypeDef *>(0x56024800u)

#else
#define PWR_NS  ((PWR_TypeDef *)0x46024800u)
#define PWR_S   ((PWR_TypeDef *)0x56024800u)
#endif

// CR1 Configuration

#define PWR_CR1_ALS                     (0x3u<<14)
#define PWR_CR1_ALS_0                   (0x1u<<14)
#define PWR_CR1_AVDEN                   (0x1u<<13)
#define PWR_CR1_VDDASV                  (0x1u<<12)
#define PWR_CR1_BOOSTE                  (0x1u<<11)
#define PWR_CR1_BOOSTVDDSEL             (0x1u<<10)
#define PWR_CR1_PLS                     (0x7u<<5)
#define PWR_CR1_PLS_0                   (0x1u<<5)
#define PWR_CR1_PVDE                    (0x1u<<4)

#define PWR_CR1_ALS_B_0X0               (0x0u<<14)
#define PWR_CR1_ALS_B_0X1               (0x1u<<14)
#define PWR_CR1_ALS_B_0X2               (0x2u<<14)
#define PWR_CR1_ALS_B_0X3               (0x3u<<14)
#define PWR_CR1_AVDEN_B_0X0             (0x0u<<13)
#define PWR_CR1_AVDEN_B_0X1             (0x1u<<13)
#define PWR_CR1_VDDASV_B_0X0            (0x0u<<12)
#define PWR_CR1_VDDASV_B_0X1            (0x1u<<12)
#define PWR_CR1_BOOSTE_B_0X0            (0x0u<<11)
#define PWR_CR1_BOOSTE_B_0X1            (0x1u<<11)
#define PWR_CR1_PLS_B_0X0               (0x0u<<5)
#define PWR_CR1_PLS_B_0X1               (0x1u<<5)
#define PWR_CR1_PLS_B_0X2               (0x2u<<5)
#define PWR_CR1_PLS_B_0X3               (0x3u<<5)
#define PWR_CR1_PLS_B_0X4               (0x4u<<5)
#define PWR_CR1_PLS_B_0X5               (0x5u<<5)
#define PWR_CR1_PLS_B_0X6               (0x6u<<5)
#define PWR_CR1_PLS_B_0X7               (0x7u<<5)
#define PWR_CR1_PVDE_B_0X0              (0x0u<<4)
#define PWR_CR1_PVDE_B_0X1              (0x1u<<4)

// SR1 Configuration

#define PWR_SR1_AVDO                    (0x1u<<13)
#define PWR_SR1_PVDO                    (0x1u<<4)

#define PWR_SR1_AVDO_B_0X0              (0x0u<<13)
#define PWR_SR1_AVDO_B_0X1              (0x1u<<13)
#define PWR_SR1_PVDO_B_0X0              (0x0u<<4)
#define PWR_SR1_PVDO_B_0X1              (0x1u<<4)

// BDCR1 Configuration

#define PWR_BDCR1_TEMPH                 (0x1u<<23)
#define PWR_BDCR1_TEMPL                 (0x1u<<22)
#define PWR_BDCR1_VBATH                 (0x1u<<21)
#define PWR_BDCR1_VBATL                 (0x1u<<20)
#define PWR_BDCR1_BRRDY                 (0x1u<<16)
#define PWR_BDCR1_MONEN                 (0x1u<<4)
#define PWR_BDCR1_BREN                  (0x1u<<0)

#define PWR_BDCR1_TEMPH_B_0X0           (0x0u<<23)
#define PWR_BDCR1_TEMPH_B_0X1           (0x1u<<23)
#define PWR_BDCR1_TEMPL_B_0X0           (0x0u<<22)
#define PWR_BDCR1_TEMPL_B_0X1           (0x1u<<22)
#define PWR_BDCR1_VBATH_B_0X0           (0x0u<<21)
#define PWR_BDCR1_VBATH_B_0X1           (0x1u<<21)
#define PWR_BDCR1_VBATL_B_0X0           (0x0u<<20)
#define PWR_BDCR1_VBATL_B_0X1           (0x1u<<20)
#define PWR_BDCR1_BRRDY_B_0X0           (0x0u<<16)
#define PWR_BDCR1_BRRDY_B_0X1           (0x1u<<16)
#define PWR_BDCR1_MONEN_B_0X0           (0x0u<<4)
#define PWR_BDCR1_MONEN_B_0X1           (0x1u<<4)
#define PWR_BDCR1_BREN_B_0X0            (0x0u<<0)
#define PWR_BDCR1_BREN_B_0X1            (0x1u<<0)

// BDCR2 Configuration

#define PWR_BDCR2_VBRS                  (0x1u<<1)
#define PWR_BDCR2_VBE                   (0x1u<<0)

#define PWR_BDCR2_VBRS_B_0X0            (0x0u<<1)
#define PWR_BDCR2_VBRS_B_0X1            (0x1u<<1)
#define PWR_BDCR2_VBE_B_0X0             (0x0u<<0)
#define PWR_BDCR2_VBE_B_0X1             (0x1u<<0)

// DBPCR Configuration

#define PWR_DBPCR_DBP                   (0x1u<<0)

#define PWR_DBPCR_DBP_B_0X0             (0x0u<<0)
#define PWR_DBPCR_DBP_B_0X1             (0x1u<<0)

// CR2 Configuration

#define PWR_CR2_BYPASS                  (0x1u<<0)

#define PWR_CR2_BYPASS_B_0X0            (0x0u<<0)
#define PWR_CR2_BYPASS_B_0X1            (0x1u<<0)

// CSR1 Configuration

#define PWR_CSR1_SBF                    (0x1u<<9)
#define PWR_CSR1_STOPF                  (0x1u<<8)
#define PWR_CSR1_FLPS                   (0x1u<<6)
#define PWR_CSR1_LPMS                   (0x7u<<2)
#define PWR_CSR1_LPMS_0                 (0x1u<<2)
#define PWR_CSR1_CSSF                   (0x1u<<1)

#define PWR_CSR1_SBF_B_0X0              (0x0u<<9)
#define PWR_CSR1_SBF_B_0X1              (0x1u<<9)
#define PWR_CSR1_STOPF_B_0X0            (0x0u<<8)
#define PWR_CSR1_STOPF_B_0X1            (0x1u<<8)
#define PWR_CSR1_FLPS_B_0X0             (0x0u<<6)
#define PWR_CSR1_FLPS_B_0X1             (0x1u<<6)
#define PWR_CSR1_LPMS_B_0X0             (0x0u<<2)
#define PWR_CSR1_LPMS_B_0X1             (0x1u<<2)
#define PWR_CSR1_LPMS_B_0X2             (0x2u<<2)
#define PWR_CSR1_LPMS_B_0X3             (0x3u<<2)
#define PWR_CSR1_CSSF_B_0X0             (0x0u<<1)
#define PWR_CSR1_CSSF_B_0X1             (0x1u<<1)

// CSR2 Configuration

#define PWR_CSR2_OVDR2RDY               (0x1u<<25)
#define PWR_CSR2_OVDR1RDY               (0x1u<<24)
#define PWR_CSR2_R2RDY                  (0x1u<<18)
#define PWR_CSR2_R1RDY                  (0x1u<<17)
#define PWR_CSR2_R0RDY                  (0x1u<<16)
#define PWR_CSR2_OVDEN                  (0x1u<<8)
#define PWR_CSR2_R2EN                   (0x1u<<2)
#define PWR_CSR2_R1EN                   (0x1u<<1)
#define PWR_CSR2_R0EN                   (0x1u<<0)

#define PWR_CSR2_OVDR2RDY_B_0X0         (0x0u<<25)
#define PWR_CSR2_OVDR2RDY_B_0X1         (0x1u<<25)
#define PWR_CSR2_OVDR1RDY_B_0X0         (0x0u<<24)
#define PWR_CSR2_OVDR1RDY_B_0X1         (0x1u<<24)
#define PWR_CSR2_R2RDY_B_0X0            (0x0u<<18)
#define PWR_CSR2_R2RDY_B_0X1            (0x1u<<18)
#define PWR_CSR2_R1RDY_B_0X0            (0x0u<<17)
#define PWR_CSR2_R1RDY_B_0X1            (0x1u<<17)
#define PWR_CSR2_R0RDY_B_0X0            (0x0u<<16)
#define PWR_CSR2_R0RDY_B_0X1            (0x1u<<16)
#define PWR_CSR2_OVDEN_B_0X0            (0x0u<<8)
#define PWR_CSR2_OVDEN_B_0X1            (0x1u<<8)
#define PWR_CSR2_R2EN_B_0X0             (0x0u<<2)
#define PWR_CSR2_R2EN_B_0X1             (0x1u<<2)
#define PWR_CSR2_R1EN_B_0X0             (0x0u<<1)
#define PWR_CSR2_R1EN_B_0X1             (0x1u<<1)
#define PWR_CSR2_R0EN_B_0X0             (0x0u<<0)
#define PWR_CSR2_R0EN_B_0X1             (0x1u<<0)

// WKUPSCR Configuration

#define PWR_WKUPSCR_WKUPC6              (0x1u<<5)
#define PWR_WKUPSCR_WKUPC5              (0x1u<<4)
#define PWR_WKUPSCR_WKUPC4              (0x1u<<3)
#define PWR_WKUPSCR_WKUPC3              (0x1u<<2)
#define PWR_WKUPSCR_WKUPC2              (0x1u<<1)
#define PWR_WKUPSCR_WKUPC1              (0x1u<<0)

#define PWR_WKUPSCR_WKUPC6_B_0X0        (0x0u<<5)
#define PWR_WKUPSCR_WKUPC6_B_0X1        (0x1u<<5)
#define PWR_WKUPSCR_WKUPC5_B_0X0        (0x0u<<4)
#define PWR_WKUPSCR_WKUPC5_B_0X1        (0x1u<<4)
#define PWR_WKUPSCR_WKUPC4_B_0X0        (0x0u<<3)
#define PWR_WKUPSCR_WKUPC4_B_0X1        (0x1u<<3)
#define PWR_WKUPSCR_WKUPC3_B_0X0        (0x0u<<2)
#define PWR_WKUPSCR_WKUPC3_B_0X1        (0x1u<<2)
#define PWR_WKUPSCR_WKUPC2_B_0X0        (0x0u<<1)
#define PWR_WKUPSCR_WKUPC2_B_0X1        (0x1u<<1)
#define PWR_WKUPSCR_WKUPC1_B_0X0        (0x0u<<0)
#define PWR_WKUPSCR_WKUPC1_B_0X1        (0x1u<<0)

// WKUPSR Configuration

#define PWR_WKUPSR_WKUPF6               (0x1u<<5)
#define PWR_WKUPSR_WKUPF5               (0x1u<<4)
#define PWR_WKUPSR_WKUPF4               (0x1u<<3)
#define PWR_WKUPSR_WKUPF3               (0x1u<<2)
#define PWR_WKUPSR_WKUPF2               (0x1u<<1)
#define PWR_WKUPSR_WKUPF1               (0x1u<<0)

#define PWR_WKUPSR_WKUPF6_B_0X0         (0x0u<<5)
#define PWR_WKUPSR_WKUPF6_B_0X1         (0x1u<<5)
#define PWR_WKUPSR_WKUPF5_B_0X0         (0x0u<<4)
#define PWR_WKUPSR_WKUPF5_B_0X1         (0x1u<<4)
#define PWR_WKUPSR_WKUPF4_B_0X0         (0x0u<<3)
#define PWR_WKUPSR_WKUPF4_B_0X1         (0x1u<<3)
#define PWR_WKUPSR_WKUPF3_B_0X0         (0x0u<<2)
#define PWR_WKUPSR_WKUPF3_B_0X1         (0x1u<<2)
#define PWR_WKUPSR_WKUPF2_B_0X0         (0x0u<<1)
#define PWR_WKUPSR_WKUPF2_B_0X1         (0x1u<<1)
#define PWR_WKUPSR_WKUPF1_B_0X0         (0x0u<<0)
#define PWR_WKUPSR_WKUPF1_B_0X1         (0x1u<<0)

// WKUPCR Configuration

#define PWR_WKUPCR_WKUPPUPD6            (0x3u<<26)
#define PWR_WKUPCR_WKUPPUPD6_0          (0x1u<<26)
#define PWR_WKUPCR_WKUPPUPD5            (0x3u<<24)
#define PWR_WKUPCR_WKUPPUPD5_0          (0x1u<<24)
#define PWR_WKUPCR_WKUPPUPD4            (0x3u<<22)
#define PWR_WKUPCR_WKUPPUPD4_0          (0x1u<<22)
#define PWR_WKUPCR_WKUPPUPD3            (0x3u<<20)
#define PWR_WKUPCR_WKUPPUPD3_0          (0x1u<<20)
#define PWR_WKUPCR_WKUPPUPD2            (0x3u<<18)
#define PWR_WKUPCR_WKUPPUPD2_0          (0x1u<<18)
#define PWR_WKUPCR_WKUPPUPD1            (0x3u<<16)
#define PWR_WKUPCR_WKUPPUPD1_0          (0x1u<<16)
#define PWR_WKUPCR_WKUPP6               (0x1u<<13)
#define PWR_WKUPCR_WKUPP5               (0x1u<<12)
#define PWR_WKUPCR_WKUPP4               (0x1u<<11)
#define PWR_WKUPCR_WKUPP3               (0x1u<<10)
#define PWR_WKUPCR_WKUPP2               (0x1u<<9)
#define PWR_WKUPCR_WKUPP1               (0x1u<<8)
#define PWR_WKUPCR_WKUPEN6              (0x1u<<5)
#define PWR_WKUPCR_WKUPEN5              (0x1u<<4)
#define PWR_WKUPCR_WKUPEN4              (0x3u<<2)
#define PWR_WKUPCR_WKUPEN4_0            (0x1u<<2)
#define PWR_WKUPCR_WKUPEN2              (0x1u<<1)
#define PWR_WKUPCR_WKUPEN1              (0x1u<<0)

#define PWR_WKUPCR_WKUPPUPD6_B_0X0      (0x0u<<26)
#define PWR_WKUPCR_WKUPPUPD6_B_0X1      (0x1u<<26)
#define PWR_WKUPCR_WKUPPUPD6_B_0X2      (0x2u<<26)
#define PWR_WKUPCR_WKUPPUPD5_B_0X0      (0x0u<<24)
#define PWR_WKUPCR_WKUPPUPD5_B_0X1      (0x1u<<24)
#define PWR_WKUPCR_WKUPPUPD5_B_0X2      (0x2u<<24)
#define PWR_WKUPCR_WKUPPUPD4_B_0X0      (0x0u<<22)
#define PWR_WKUPCR_WKUPPUPD4_B_0X1      (0x1u<<22)
#define PWR_WKUPCR_WKUPPUPD4_B_0X2      (0x2u<<22)
#define PWR_WKUPCR_WKUPPUPD3_B_0X0      (0x0u<<20)
#define PWR_WKUPCR_WKUPPUPD3_B_0X1      (0x1u<<20)
#define PWR_WKUPCR_WKUPPUPD3_B_0X2      (0x2u<<20)
#define PWR_WKUPCR_WKUPPUPD2_B_0X0      (0x0u<<18)
#define PWR_WKUPCR_WKUPPUPD2_B_0X1      (0x1u<<18)
#define PWR_WKUPCR_WKUPPUPD2_B_0X2      (0x2u<<18)
#define PWR_WKUPCR_WKUPPUPD1_B_0X0      (0x0u<<16)
#define PWR_WKUPCR_WKUPPUPD1_B_0X1      (0x1u<<16)
#define PWR_WKUPCR_WKUPPUPD1_B_0X2      (0x2u<<16)
#define PWR_WKUPCR_WKUPP6_B_0X0         (0x0u<<13)
#define PWR_WKUPCR_WKUPP6_B_0X1         (0x1u<<13)
#define PWR_WKUPCR_WKUPP5_B_0X0         (0x0u<<12)
#define PWR_WKUPCR_WKUPP5_B_0X1         (0x1u<<12)
#define PWR_WKUPCR_WKUPP4_B_0X0         (0x0u<<11)
#define PWR_WKUPCR_WKUPP4_B_0X1         (0x1u<<11)
#define PWR_WKUPCR_WKUPP3_B_0X0         (0x0u<<10)
#define PWR_WKUPCR_WKUPP3_B_0X1         (0x1u<<10)
#define PWR_WKUPCR_WKUPP2_B_0X0         (0x0u<<9)
#define PWR_WKUPCR_WKUPP2_B_0X1         (0x1u<<9)
#define PWR_WKUPCR_WKUPP1_B_0X0         (0x0u<<8)
#define PWR_WKUPCR_WKUPP1_B_0X1         (0x1u<<8)
#define PWR_WKUPCR_WKUPEN6_B_0X0        (0x0u<<5)
#define PWR_WKUPCR_WKUPEN6_B_0X1        (0x1u<<5)
#define PWR_WKUPCR_WKUPEN5_B_0X0        (0x0u<<4)
#define PWR_WKUPCR_WKUPEN5_B_0X1        (0x1u<<4)
#define PWR_WKUPCR_WKUPEN4_B_0X0        (0x0u<<2)
#define PWR_WKUPCR_WKUPEN4_B_0X1        (0x1u<<2)
#define PWR_WKUPCR_WKUPEN2_B_0X0        (0x0u<<1)
#define PWR_WKUPCR_WKUPEN2_B_0X1        (0x1u<<1)
#define PWR_WKUPCR_WKUPEN1_B_0X0        (0x0u<<0)
#define PWR_WKUPCR_WKUPEN1_B_0X1        (0x1u<<0)

// UCPDR Configuration

#define PWR_UCPDR_UCPD1_STBY            (0x1u<<1)

// USBCSR Configuration

#define PWR_USBCSR_V33RDY               (0x1u<<18)
#define PWR_USBCSR_V18RDY               (0x1u<<17)
#define PWR_USBCSR_VPHYRDY              (0x1u<<16)
#define PWR_USBCSR_VPHYVOS              (0x3u<<14)
#define PWR_USBCSR_VPHYVOS_0            (0x1u<<14)
#define PWR_USBCSR_V33SV                (0x1u<<7)
#define PWR_USBCSR_V18SV                (0x1u<<6)
#define PWR_USBCSR_VPHYSV               (0x1u<<5)
#define PWR_USBCSR_V33DEN               (0x1u<<4)
#define PWR_USBCSR_V18BYPASS            (0x1u<<3)
#define PWR_USBCSR_VPHYBYPASS           (0x1u<<2)
#define PWR_USBCSR_V18EN                (0x1u<<1)
#define PWR_USBCSR_VPHYEN               (0x1u<<0)

#define PWR_USBCSR_V33RDY_B_0X0         (0x0u<<18)
#define PWR_USBCSR_V33RDY_B_0X1         (0x1u<<18)
#define PWR_USBCSR_V18RDY_B_0X0         (0x0u<<17)
#define PWR_USBCSR_V18RDY_B_0X1         (0x1u<<17)
#define PWR_USBCSR_VPHYRDY_B_0X0        (0x0u<<16)
#define PWR_USBCSR_VPHYRDY_B_0X1        (0x1u<<16)
#define PWR_USBCSR_VPHYVOS_B_0X0        (0x0u<<14)
#define PWR_USBCSR_VPHYVOS_B_0X1        (0x1u<<14)
#define PWR_USBCSR_VPHYVOS_B_0X2        (0x2u<<14)
#define PWR_USBCSR_VPHYVOS_B_0X3        (0x3u<<14)
#define PWR_USBCSR_V33SV_B_0X0          (0x0u<<7)
#define PWR_USBCSR_V33SV_B_0X1          (0x1u<<7)
#define PWR_USBCSR_V18SV_B_0X0          (0x0u<<6)
#define PWR_USBCSR_V18SV_B_0X1          (0x1u<<6)
#define PWR_USBCSR_VPHYSV_B_0X0         (0x0u<<5)
#define PWR_USBCSR_VPHYSV_B_0X1         (0x1u<<5)
#define PWR_USBCSR_V33DEN_B_0X0         (0x0u<<4)
#define PWR_USBCSR_V33DEN_B_0X1         (0x1u<<4)
#define PWR_USBCSR_V18BYPASS_B_0X0      (0x0u<<3)
#define PWR_USBCSR_V18BYPASS_B_0X1      (0x1u<<3)
#define PWR_USBCSR_VPHYBYPASS_B_0X0     (0x0u<<2)
#define PWR_USBCSR_VPHYBYPASS_B_0X1     (0x1u<<2)
#define PWR_USBCSR_V18EN_B_0X0          (0x0u<<1)
#define PWR_USBCSR_V18EN_B_0X1          (0x1u<<1)
#define PWR_USBCSR_VPHYEN_B_0X0         (0x0u<<0)
#define PWR_USBCSR_VPHYEN_B_0X1         (0x1u<<0)

// XSPICSR Configuration

#define PWR_XSPICSR_VDDXSPI2RDY         (0x1u<<24)
#define PWR_XSPICSR_IOXSPI2SV           (0x1u<<22)
#define PWR_XSPICSR_XSPI2CAP            (0x3u<<17)
#define PWR_XSPICSR_XSPI2CAP_0          (0x1u<<17)
#define PWR_XSPICSR_VDDXSPI2DEN         (0x1u<<16)
#define PWR_XSPICSR_VDDIO2RDY           (0x1u<<9)
#define PWR_XSPICSR_VDDXSPI1RDY         (0x1u<<8)
#define PWR_XSPICSR_IOXSPI1SV           (0x1u<<6)
#define PWR_XSPICSR_VDDIO2DEN           (0x1u<<5)
#define PWR_XSPICSR_XSPI1CAP            (0x3u<<1)
#define PWR_XSPICSR_XSPI1CAP_0          (0x1u<<1)
#define PWR_XSPICSR_VDDXSPI1DEN         (0x1u<<0)

#define PWR_XSPICSR_VDDXSPI2RDY_B_0X0   (0x0u<<24)
#define PWR_XSPICSR_VDDXSPI2RDY_B_0X1   (0x1u<<24)
#define PWR_XSPICSR_IOXSPI2SV_B_0X0     (0x0u<<22)
#define PWR_XSPICSR_IOXSPI2SV_B_0X1     (0x1u<<22)
#define PWR_XSPICSR_XSPI2CAP_B_0X0      (0x0u<<17)
#define PWR_XSPICSR_XSPI2CAP_B_0X1      (0x1u<<17)
#define PWR_XSPICSR_XSPI2CAP_B_0X2      (0x2u<<17)
#define PWR_XSPICSR_XSPI2CAP_B_0X3      (0x3u<<17)
#define PWR_XSPICSR_VDDXSPI2DEN_B_0X0   (0x0u<<16)
#define PWR_XSPICSR_VDDXSPI2DEN_B_0X1   (0x1u<<16)
#define PWR_XSPICSR_VDDIO2RDY_B_0X0     (0x0u<<9)
#define PWR_XSPICSR_VDDIO2RDY_B_0X1     (0x1u<<9)
#define PWR_XSPICSR_VDDXSPI1RDY_B_0X0   (0x0u<<8)
#define PWR_XSPICSR_VDDXSPI1RDY_B_0X1   (0x1u<<8)
#define PWR_XSPICSR_IOXSPI1SV_B_0X0     (0x0u<<6)
#define PWR_XSPICSR_IOXSPI1SV_B_0X1     (0x1u<<6)
#define PWR_XSPICSR_VDDIO2DEN_B_0X0     (0x0u<<5)
#define PWR_XSPICSR_VDDIO2DEN_B_0X1     (0x1u<<5)
#define PWR_XSPICSR_XSPI1CAP_B_0X0      (0x0u<<1)
#define PWR_XSPICSR_XSPI1CAP_B_0X1      (0x1u<<1)
#define PWR_XSPICSR_XSPI1CAP_B_0X2      (0x2u<<1)
#define PWR_XSPICSR_XSPI1CAP_B_0X3      (0x3u<<1)
#define PWR_XSPICSR_VDDXSPI1DEN_B_0X0   (0x0u<<0)
#define PWR_XSPICSR_VDDXSPI1DEN_B_0X1   (0x1u<<0)

// IORETR Configuration

#define PWR_IORETR_JTAGIORETEN          (0x1u<<16)
#define PWR_IORETR_IORETEN              (0x1u<<0)

#define PWR_IORETR_JTAGIORETEN_B_0X0    (0x0u<<16)
#define PWR_IORETR_JTAGIORETEN_B_0X1    (0x1u<<16)
#define PWR_IORETR_IORETEN_B_0X0        (0x0u<<0)
#define PWR_IORETR_IORETEN_B_0X1        (0x1u<<0)

// SECCFGR Configuration

#define PWR_SECCFGR_VXSPI2SEC           (0x1u<<17)
#define PWR_SECCFGR_VXSPI1SEC           (0x1u<<16)
#define PWR_SECCFGR_VUSBSEC             (0x1u<<15)
#define PWR_SECCFGR_VBSEC               (0x1u<<14)
#define PWR_SECCFGR_SCMSEC              (0x1u<<13)
#define PWR_SECCFGR_LPMSEC              (0x1u<<12)
#define PWR_SECCFGR_RETSEC              (0x1u<<11)
#define PWR_SECCFGR_WKUP6SEC            (0x1u<<5)
#define PWR_SECCFGR_WKUP5SEC            (0x1u<<4)
#define PWR_SECCFGR_WKUP4SEC            (0x1u<<3)
#define PWR_SECCFGR_WKUP3SEC            (0x1u<<2)
#define PWR_SECCFGR_WKUP2SEC            (0x1u<<1)
#define PWR_SECCFGR_WKUP1SEC            (0x1u<<0)

#define PWR_SECCFGR_VXSPI2SEC_B_0X0     (0x0u<<17)
#define PWR_SECCFGR_VXSPI2SEC_B_0X1     (0x1u<<17)
#define PWR_SECCFGR_VXSPI1SEC_B_0X0     (0x0u<<16)
#define PWR_SECCFGR_VXSPI1SEC_B_0X1     (0x1u<<16)
#define PWR_SECCFGR_VUSBSEC_B_0X0       (0x0u<<15)
#define PWR_SECCFGR_VUSBSEC_B_0X1       (0x1u<<15)
#define PWR_SECCFGR_VBSEC_B_0X0         (0x0u<<14)
#define PWR_SECCFGR_VBSEC_B_0X1         (0x1u<<14)
#define PWR_SECCFGR_SCMSEC_B_0X0        (0x0u<<13)
#define PWR_SECCFGR_SCMSEC_B_0X1        (0x1u<<13)
#define PWR_SECCFGR_LPMSEC_B_0X0        (0x0u<<12)
#define PWR_SECCFGR_LPMSEC_B_0X1        (0x1u<<12)
#define PWR_SECCFGR_RETSEC_B_0X0        (0x0u<<11)
#define PWR_SECCFGR_RETSEC_B_0X1        (0x1u<<11)
#define PWR_SECCFGR_WKUP6SEC_B_0X0      (0x0u<<5)
#define PWR_SECCFGR_WKUP6SEC_B_0X1      (0x1u<<5)
#define PWR_SECCFGR_WKUP5SEC_B_0X0      (0x0u<<4)
#define PWR_SECCFGR_WKUP5SEC_B_0X1      (0x1u<<4)
#define PWR_SECCFGR_WKUP4SEC_B_0X0      (0x0u<<3)
#define PWR_SECCFGR_WKUP4SEC_B_0X1      (0x1u<<3)
#define PWR_SECCFGR_WKUP3SEC_B_0X0      (0x0u<<2)
#define PWR_SECCFGR_WKUP3SEC_B_0X1      (0x1u<<2)
#define PWR_SECCFGR_WKUP2SEC_B_0X0      (0x0u<<1)
#define PWR_SECCFGR_WKUP2SEC_B_0X1      (0x1u<<1)
#define PWR_SECCFGR_WKUP1SEC_B_0X0      (0x0u<<0)
#define PWR_SECCFGR_WKUP1SEC_B_0X1      (0x1u<<0)

// PRIVCFGR Configuration

#define PWR_PRIVCFGR_VXSPI2PRIV         (0x1u<<17)
#define PWR_PRIVCFGR_VXSPI1PRIV         (0x1u<<16)
#define PWR_PRIVCFGR_VUSBPRIV           (0x1u<<15)
#define PWR_PRIVCFGR_VBPRIV             (0x1u<<14)
#define PWR_PRIVCFGR_SCMPRIV            (0x1u<<13)
#define PWR_PRIVCFGR_LPMPRIV            (0x1u<<12)
#define PWR_PRIVCFGR_RETPRIV            (0x1u<<11)
#define PWR_PRIVCFGR_WKUP6PRIV          (0x1u<<5)
#define PWR_PRIVCFGR_WKUP5PRIV          (0x1u<<4)
#define PWR_PRIVCFGR_WKUP4PRIV          (0x1u<<3)
#define PWR_PRIVCFGR_WKUP3PRIV          (0x1u<<2)
#define PWR_PRIVCFGR_WKUP2PRIV          (0x1u<<1)
#define PWR_PRIVCFGR_WKUP1PRIV          (0x1u<<0)

#define PWR_PRIVCFGR_VXSPI2PRIV_B_0X0   (0x0u<<17)
#define PWR_PRIVCFGR_VXSPI2PRIV_B_0X1   (0x1u<<17)
#define PWR_PRIVCFGR_VXSPI1PRIV_B_0X0   (0x0u<<16)
#define PWR_PRIVCFGR_VXSPI1PRIV_B_0X1   (0x1u<<16)
#define PWR_PRIVCFGR_VUSBPRIV_B_0X0     (0x0u<<15)
#define PWR_PRIVCFGR_VUSBPRIV_B_0X1     (0x1u<<15)
#define PWR_PRIVCFGR_VBPRIV_B_0X0       (0x0u<<14)
#define PWR_PRIVCFGR_VBPRIV_B_0X1       (0x1u<<14)
#define PWR_PRIVCFGR_SCMPRIV_B_0X0      (0x0u<<13)
#define PWR_PRIVCFGR_SCMPRIV_B_0X1      (0x1u<<13)
#define PWR_PRIVCFGR_LPMPRIV_B_0X0      (0x0u<<12)
#define PWR_PRIVCFGR_LPMPRIV_B_0X1      (0x1u<<12)
#define PWR_PRIVCFGR_RETPRIV_B_0X0      (0x0u<<11)
#define PWR_PRIVCFGR_RETPRIV_B_0X1      (0x1u<<11)
#define PWR_PRIVCFGR_WKUP6PRIV_B_0X0    (0x0u<<5)
#define PWR_PRIVCFGR_WKUP6PRIV_B_0X1    (0x1u<<5)
#define PWR_PRIVCFGR_WKUP5PRIV_B_0X0    (0x0u<<4)
#define PWR_PRIVCFGR_WKUP5PRIV_B_0X1    (0x1u<<4)
#define PWR_PRIVCFGR_WKUP4PRIV_B_0X0    (0x0u<<3)
#define PWR_PRIVCFGR_WKUP4PRIV_B_0X1    (0x1u<<3)
#define PWR_PRIVCFGR_WKUP3PRIV_B_0X0    (0x0u<<2)
#define PWR_PRIVCFGR_WKUP3PRIV_B_0X1    (0x1u<<2)
#define PWR_PRIVCFGR_WKUP2PRIV_B_0X0    (0x0u<<1)
#define PWR_PRIVCFGR_WKUP2PRIV_B_0X1    (0x1u<<1)
#define PWR_PRIVCFGR_WKUP1PRIV_B_0X0    (0x0u<<0)
#define PWR_PRIVCFGR_WKUP1PRIV_B_0X1    (0x1u<<0)

// LOCKCFGR Configuration

#define PWR_LOCKCFGR_VXSPI2LOCK         (0x1u<<17)
#define PWR_LOCKCFGR_VXSPI1LOCK         (0x1u<<16)
#define PWR_LOCKCFGR_VUSBLOCK           (0x1u<<15)
#define PWR_LOCKCFGR_VBLOCK             (0x1u<<14)
#define PWR_LOCKCFGR_SCMLOCK            (0x1u<<13)
#define PWR_LOCKCFGR_LPMLOCK            (0x1u<<12)
#define PWR_LOCKCFGR_RETLOCK            (0x1u<<11)
#define PWR_LOCKCFGR_WKUP6LOCK          (0x1u<<5)
#define PWR_LOCKCFGR_WKUP5LOCK          (0x1u<<4)
#define PWR_LOCKCFGR_WKUP4LOCK          (0x1u<<3)
#define PWR_LOCKCFGR_WKUP3LOCK          (0x1u<<2)
#define PWR_LOCKCFGR_WKUP2LOCK          (0x1u<<1)
#define PWR_LOCKCFGR_WKUP1LOCK          (0x1u<<0)

#define PWR_LOCKCFGR_VXSPI2LOCK_B_0X0   (0x0u<<17)
#define PWR_LOCKCFGR_VXSPI2LOCK_B_0X1   (0x1u<<17)
#define PWR_LOCKCFGR_VXSPI1LOCK_B_0X0   (0x0u<<16)
#define PWR_LOCKCFGR_VXSPI1LOCK_B_0X1   (0x1u<<16)
#define PWR_LOCKCFGR_VUSBLOCK_B_0X0     (0x0u<<15)
#define PWR_LOCKCFGR_VUSBLOCK_B_0X1     (0x1u<<15)
#define PWR_LOCKCFGR_VBLOCK_B_0X0       (0x0u<<14)
#define PWR_LOCKCFGR_VBLOCK_B_0X1       (0x1u<<14)
#define PWR_LOCKCFGR_SCMLOCK_B_0X0      (0x0u<<13)
#define PWR_LOCKCFGR_SCMLOCK_B_0X1      (0x1u<<13)
#define PWR_LOCKCFGR_LPMLOCK_B_0X0      (0x0u<<12)
#define PWR_LOCKCFGR_LPMLOCK_B_0X1      (0x1u<<12)
#define PWR_LOCKCFGR_RETLOCK_B_0X0      (0x0u<<11)
#define PWR_LOCKCFGR_RETLOCK_B_0X1      (0x1u<<11)
#define PWR_LOCKCFGR_WKUP6LOCK_B_0X0    (0x0u<<5)
#define PWR_LOCKCFGR_WKUP6LOCK_B_0X1    (0x1u<<5)
#define PWR_LOCKCFGR_WKUP5LOCK_B_0X0    (0x0u<<4)
#define PWR_LOCKCFGR_WKUP5LOCK_B_0X1    (0x1u<<4)
#define PWR_LOCKCFGR_WKUP4LOCK_B_0X0    (0x0u<<3)
#define PWR_LOCKCFGR_WKUP4LOCK_B_0X1    (0x1u<<3)
#define PWR_LOCKCFGR_WKUP3LOCK_B_0X0    (0x0u<<2)
#define PWR_LOCKCFGR_WKUP3LOCK_B_0X1    (0x1u<<2)
#define PWR_LOCKCFGR_WKUP2LOCK_B_0X0    (0x0u<<1)
#define PWR_LOCKCFGR_WKUP2LOCK_B_0X1    (0x1u<<1)
#define PWR_LOCKCFGR_WKUP1LOCK_B_0X0    (0x0u<<0)
#define PWR_LOCKCFGR_WKUP1LOCK_B_0X1    (0x1u<<0)
