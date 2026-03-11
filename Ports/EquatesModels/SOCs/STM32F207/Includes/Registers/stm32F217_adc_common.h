/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32F217_adc_common.
; =====================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32F217_adc_common equates.
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

// ADC_COMMON address definitions
// ------------------------------

typedef struct {
    volatile    uint32_t    CSR;
    volatile    uint32_t    CCR;
    volatile    uint32_t    CDR;
} ADC_COMMON_TypeDef;

#ifdef __cplusplus
#define ADC_COMMON  reinterpret_cast<ADC_COMMON_TypeDef *>(0x40012300U)

#else
#define ADC_COMMON  ((ADC_COMMON_TypeDef *)0x40012300U)
#endif

// CSR Configuration

#define ADC_COMMON_CSR_AWD1     (0x1U<<0)
#define ADC_COMMON_CSR_EOC1     (0x1U<<1)
#define ADC_COMMON_CSR_JEOC1    (0x1U<<2)
#define ADC_COMMON_CSR_JSTRT1   (0x1U<<3)
#define ADC_COMMON_CSR_STRT1    (0x1U<<4)
#define ADC_COMMON_CSR_OVR1     (0x1U<<5)
#define ADC_COMMON_CSR_AWD2     (0x1U<<8)
#define ADC_COMMON_CSR_EOC2     (0x1U<<9)
#define ADC_COMMON_CSR_JEOC2    (0x1U<<10)
#define ADC_COMMON_CSR_JSTRT2   (0x1U<<11)
#define ADC_COMMON_CSR_STRT2    (0x1U<<12)
#define ADC_COMMON_CSR_OVR2     (0x1U<<13)
#define ADC_COMMON_CSR_AWD3     (0x1U<<16)
#define ADC_COMMON_CSR_EOC3     (0x1U<<17)
#define ADC_COMMON_CSR_JEOC3    (0x1U<<18)
#define ADC_COMMON_CSR_JSTRT3   (0x1U<<19)
#define ADC_COMMON_CSR_STRT3    (0x1U<<20)
#define ADC_COMMON_CSR_OVR3     (0x1U<<21)

// CCR Configuration

#define ADC_COMMON_CCR_MULT     (0x1FU<<0)
#define ADC_COMMON_CCR_MULT_0   (0x1U<<0)
#define ADC_COMMON_CCR_DELAY    (0xFU<<8)
#define ADC_COMMON_CCR_DELAY_0  (0x1U<<8)
#define ADC_COMMON_CCR_DDS      (0x1U<<13)
#define ADC_COMMON_CCR_DMA      (0x3U<<14)
#define ADC_COMMON_CCR_DMA_0    (0x1U<<14)
#define ADC_COMMON_CCR_ADCPRE   (0x3U<<16)
#define ADC_COMMON_CCR_ADCPRE_0 (0x1U<<16)
#define ADC_COMMON_CCR_VBATE    (0x1U<<22)
#define ADC_COMMON_CCR_TSVREFE  (0x1U<<23)

// CDR Configuration

#define ADC_COMMON_CDR_DATA1    (0xFFFFU<<0)
#define ADC_COMMON_CDR_DATA1_0  (0x1U<<0)
#define ADC_COMMON_CDR_DATA2    (0xFFFFU<<16)
#define ADC_COMMON_CDR_DATA2_0  (0x1U<<16)
