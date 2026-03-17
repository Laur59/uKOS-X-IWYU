/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; fpe.
; ====

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     FPE equates.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

// FPE address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    FPCCR;
    volatile    uint32_t    FPCAR;
    volatile    uint32_t    FPDSCR;
    volatile    uint32_t    MVFR0;
    volatile    uint32_t    MVFR1;
    volatile    uint32_t    MVFR2;
} FPE_TypeDef;

#ifdef __cplusplus
#define FPE_S   reinterpret_cast<FPE_TypeDef *>(0xE000EF30U)
#define FPE_NS  reinterpret_cast<FPE_TypeDef *>(0xE002EF30U)

#else
#define FPE_S   ((FPE_TypeDef *)0xE000EF30U)
#define FPE_NS  ((FPE_TypeDef *)0xE002EF30U)
#endif

// FPCCR Configuration

#define FPE_FPCCR_LSPACT        (0x1U<<0)
#define FPE_FPCCR_USER          (0x1U<<1)
#define FPE_FPCCR_S             (0x1U<<2)
#define FPE_FPCCR_THREAD        (0x1U<<3)
#define FPE_FPCCR_HFRDY         (0x1U<<4)
#define FPE_FPCCR_MMRDY         (0x1U<<5)
#define FPE_FPCCR_BFRDY         (0x1U<<6)
#define FPE_FPCCR_SFRDY         (0x1U<<7)
#define FPE_FPCCR_MONRDY        (0x1U<<8)
#define FPE_FPCCR_SPLIMVIOL     (0x1U<<9)
#define FPE_FPCCR_UFRDY         (0x1U<<10)
#define FPE_FPCCR_TS            (0x1U<<26)
#define FPE_FPCCR_CLRONRETS     (0x1U<<27)
#define FPE_FPCCR_CLRONRET      (0x1U<<28)
#define FPE_FPCCR_LSPENS        (0x1U<<29)
#define FPE_FPCCR_LSPEN         (0x1U<<30)
#define FPE_FPCCR_ASPEN         (0x1U<<31)

// FPCAR Configuration

#define FPE_FPCAR_ADDRESS       (0x1FFFFFFFU<<3)
#define FPE_FPCAR_ADDRESS_0     (0x1U<<3)

// FPDSCR Configuration

#define FPE_FPDSCR_RMODE        (0x3U<<22)
#define FPE_FPDSCR_RMODE_0      (0x1U<<22)
#define FPE_FPDSCR_FZ           (0x1U<<24)
#define FPE_FPDSCR_DN           (0x1U<<25)
#define FPE_FPDSCR_AHP          (0x1U<<26)

// MVFR0 Configuration

#define FPE_MVFR0_SIMDREG       (0xFU<<0)
#define FPE_MVFR0_SIMDREG_0     (0x1U<<0)
#define FPE_MVFR0_FPSP          (0xFU<<4)
#define FPE_MVFR0_FPSP_0        (0x1U<<4)
#define FPE_MVFR0_FPDP          (0xFU<<8)
#define FPE_MVFR0_FPDP_0        (0x1U<<8)
#define FPE_MVFR0_FPDIVIDE      (0xFU<<16)
#define FPE_MVFR0_FPDIVIDE_0    (0x1U<<16)
#define FPE_MVFR0_FPSQRT        (0xFU<<20)
#define FPE_MVFR0_FPSQRT_0      (0x1U<<20)
#define FPE_MVFR0_FPROUND       (0xFU<<28)
#define FPE_MVFR0_FPROUND_0     (0x1U<<28)

// MVFR1 Configuration

#define FPE_MVFR1_FPFTZ         (0xFU<<0)
#define FPE_MVFR1_FPFTZ_0       (0x1U<<0)
#define FPE_MVFR1_FPDNAN        (0xFU<<4)
#define FPE_MVFR1_FPDNAN_0      (0x1U<<4)
#define FPE_MVFR1_FPHP          (0xFU<<24)
#define FPE_MVFR1_FPHP_0        (0x1U<<24)
#define FPE_MVFR1_FMAC          (0xFU<<28)
#define FPE_MVFR1_FMAC_0        (0x1U<<28)

// MVFR2 Configuration

#define FPE_MVFR2_FPMISC        (0xFU<<4)
#define FPE_MVFR2_FPMISC_0      (0x1U<<4)
