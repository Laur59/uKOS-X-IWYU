/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H747_CM4_bdma equates.
 */

#pragma once

#include    <stdint.h>

// BDMA address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    ISR;
    volatile    uint32_t    IFCR;
    volatile    uint32_t    CCR1;
    volatile    uint32_t    CNDTR1;
    volatile    uint32_t    CPAR1;
    volatile    uint32_t    CMAR1;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    CCR2;
    volatile    uint32_t    CNDTR2;
    volatile    uint32_t    CPAR2;
    volatile    uint32_t    CMAR2;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    CCR3;
    volatile    uint32_t    CNDTR3;
    volatile    uint32_t    CPAR3;
    volatile    uint32_t    CMAR3;
    volatile    uint32_t    RESERVED2;
    volatile    uint32_t    CCR4;
    volatile    uint32_t    CNDTR4;
    volatile    uint32_t    CPAR4;
    volatile    uint32_t    CMAR4;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    CCR5;
    volatile    uint32_t    CNDTR5;
    volatile    uint32_t    CPAR5;
    volatile    uint32_t    CMAR5;
    volatile    uint32_t    RESERVED4;
    volatile    uint32_t    CCR6;
    volatile    uint32_t    CNDTR6;
    volatile    uint32_t    CPAR6;
    volatile    uint32_t    CMAR6;
    volatile    uint32_t    RESERVED5;
    volatile    uint32_t    CCR7;
    volatile    uint32_t    CNDTR7;
    volatile    uint32_t    CPAR7;
    volatile    uint32_t    CMAR7;
    volatile    uint32_t    RESERVED6;
    volatile    uint32_t    CCR8;
    volatile    uint32_t    CNDTR8;
    volatile    uint32_t    CPAR8;
    volatile    uint32_t    CMAR8;
} BDMA_TypeDef;

#ifdef __cplusplus
#define BDMA    reinterpret_cast<BDMA_TypeDef *>(0x58025400U)

#else
#define BDMA    ((BDMA_TypeDef *)0x58025400U)
#endif

// ISR Configuration

#define BDMA_ISR_TEIF8      (0x1U<<31)
#define BDMA_ISR_HTIF8      (0x1U<<30)
#define BDMA_ISR_TCIF8      (0x1U<<29)
#define BDMA_ISR_GIF8       (0x1U<<28)
#define BDMA_ISR_TEIF7      (0x1U<<27)
#define BDMA_ISR_HTIF7      (0x1U<<26)
#define BDMA_ISR_TCIF7      (0x1U<<25)
#define BDMA_ISR_GIF7       (0x1U<<24)
#define BDMA_ISR_TEIF6      (0x1U<<23)
#define BDMA_ISR_HTIF6      (0x1U<<22)
#define BDMA_ISR_TCIF6      (0x1U<<21)
#define BDMA_ISR_GIF6       (0x1U<<20)
#define BDMA_ISR_TEIF5      (0x1U<<19)
#define BDMA_ISR_HTIF5      (0x1U<<18)
#define BDMA_ISR_TCIF5      (0x1U<<17)
#define BDMA_ISR_GIF5       (0x1U<<16)
#define BDMA_ISR_TEIF4      (0x1U<<15)
#define BDMA_ISR_HTIF4      (0x1U<<14)
#define BDMA_ISR_TCIF4      (0x1U<<13)
#define BDMA_ISR_GIF4       (0x1U<<12)
#define BDMA_ISR_TEIF3      (0x1U<<11)
#define BDMA_ISR_HTIF3      (0x1U<<10)
#define BDMA_ISR_TCIF3      (0x1U<<9)
#define BDMA_ISR_GIF3       (0x1U<<8)
#define BDMA_ISR_TEIF2      (0x1U<<7)
#define BDMA_ISR_HTIF2      (0x1U<<6)
#define BDMA_ISR_TCIF2      (0x1U<<5)
#define BDMA_ISR_GIF2       (0x1U<<4)
#define BDMA_ISR_TEIF1      (0x1U<<3)
#define BDMA_ISR_HTIF1      (0x1U<<2)
#define BDMA_ISR_TCIF1      (0x1U<<1)
#define BDMA_ISR_GIF1       (0x1U<<0)

// IFCR Configuration

#define BDMA_IFCR_CTEIF8    (0x1U<<31)
#define BDMA_IFCR_CHTIF8    (0x1U<<30)
#define BDMA_IFCR_CTCIF8    (0x1U<<29)
#define BDMA_IFCR_CGIF8     (0x1U<<28)
#define BDMA_IFCR_CTEIF7    (0x1U<<27)
#define BDMA_IFCR_CHTIF7    (0x1U<<26)
#define BDMA_IFCR_CTCIF7    (0x1U<<25)
#define BDMA_IFCR_CGIF7     (0x1U<<24)
#define BDMA_IFCR_CTEIF6    (0x1U<<23)
#define BDMA_IFCR_CHTIF6    (0x1U<<22)
#define BDMA_IFCR_CTCIF6    (0x1U<<21)
#define BDMA_IFCR_CGIF6     (0x1U<<20)
#define BDMA_IFCR_CTEIF5    (0x1U<<19)
#define BDMA_IFCR_CHTIF5    (0x1U<<18)
#define BDMA_IFCR_CTCIF5    (0x1U<<17)
#define BDMA_IFCR_CGIF5     (0x1U<<16)
#define BDMA_IFCR_CTEIF4    (0x1U<<15)
#define BDMA_IFCR_CHTIF4    (0x1U<<14)
#define BDMA_IFCR_CTCIF4    (0x1U<<13)
#define BDMA_IFCR_CGIF4     (0x1U<<12)
#define BDMA_IFCR_CTEIF3    (0x1U<<11)
#define BDMA_IFCR_CHTIF3    (0x1U<<10)
#define BDMA_IFCR_CTCIF3    (0x1U<<9)
#define BDMA_IFCR_CGIF3     (0x1U<<8)
#define BDMA_IFCR_CTEIF2    (0x1U<<7)
#define BDMA_IFCR_CHTIF2    (0x1U<<6)
#define BDMA_IFCR_CTCIF2    (0x1U<<5)
#define BDMA_IFCR_CGIF2     (0x1U<<4)
#define BDMA_IFCR_CTEIF1    (0x1U<<3)
#define BDMA_IFCR_CHTIF1    (0x1U<<2)
#define BDMA_IFCR_CTCIF1    (0x1U<<1)
#define BDMA_IFCR_CGIF1     (0x1U<<0)

// CCR1 Configuration

#define BDMA_CCR1_MEM2MEM   (0x1U<<14)
#define BDMA_CCR1_PL        (0x3U<<12)
#define BDMA_CCR1_PL_0      (0x1U<<12)
#define BDMA_CCR1_MSIZE     (0x3U<<10)
#define BDMA_CCR1_MSIZE_0   (0x1U<<10)
#define BDMA_CCR1_PSIZE     (0x3U<<8)
#define BDMA_CCR1_PSIZE_0   (0x1U<<8)
#define BDMA_CCR1_MINC      (0x1U<<7)
#define BDMA_CCR1_PINC      (0x1U<<6)
#define BDMA_CCR1_CIRC      (0x1U<<5)
#define BDMA_CCR1_DIR       (0x1U<<4)
#define BDMA_CCR1_TEIE      (0x1U<<3)
#define BDMA_CCR1_HTIE      (0x1U<<2)
#define BDMA_CCR1_TCIE      (0x1U<<1)
#define BDMA_CCR1_EN        (0x1U<<0)

// CNDTR1 Configuration

#define BDMA_CNDTR1_NDT     (0xFFFFU<<0)
#define BDMA_CNDTR1_NDT_0   (0x1U<<0)

// CPAR1 Configuration

#define BDMA_CPAR1_PA       (0xFFFFFFFFU<<0)
#define BDMA_CPAR1_PA_0     (0x1U<<0)

// CMAR1 Configuration

#define BDMA_CMAR1_MA       (0xFFFFFFFFU<<0)
#define BDMA_CMAR1_MA_0     (0x1U<<0)

// CCR2 Configuration

#define BDMA_CCR2_MEM2MEM   (0x1U<<14)
#define BDMA_CCR2_PL        (0x3U<<12)
#define BDMA_CCR2_PL_0      (0x1U<<12)
#define BDMA_CCR2_MSIZE     (0x3U<<10)
#define BDMA_CCR2_MSIZE_0   (0x1U<<10)
#define BDMA_CCR2_PSIZE     (0x3U<<8)
#define BDMA_CCR2_PSIZE_0   (0x1U<<8)
#define BDMA_CCR2_MINC      (0x1U<<7)
#define BDMA_CCR2_PINC      (0x1U<<6)
#define BDMA_CCR2_CIRC      (0x1U<<5)
#define BDMA_CCR2_DIR       (0x1U<<4)
#define BDMA_CCR2_TEIE      (0x1U<<3)
#define BDMA_CCR2_HTIE      (0x1U<<2)
#define BDMA_CCR2_TCIE      (0x1U<<1)
#define BDMA_CCR2_EN        (0x1U<<0)

// CNDTR2 Configuration

#define BDMA_CNDTR2_NDT     (0xFFFFU<<0)
#define BDMA_CNDTR2_NDT_0   (0x1U<<0)

// CPAR2 Configuration

#define BDMA_CPAR2_PA       (0xFFFFFFFFU<<0)
#define BDMA_CPAR2_PA_0     (0x1U<<0)

// CMAR2 Configuration

#define BDMA_CMAR2_MA       (0xFFFFFFFFU<<0)
#define BDMA_CMAR2_MA_0     (0x1U<<0)

// CCR3 Configuration

#define BDMA_CCR3_MEM2MEM   (0x1U<<14)
#define BDMA_CCR3_PL        (0x3U<<12)
#define BDMA_CCR3_PL_0      (0x1U<<12)
#define BDMA_CCR3_MSIZE     (0x3U<<10)
#define BDMA_CCR3_MSIZE_0   (0x1U<<10)
#define BDMA_CCR3_PSIZE     (0x3U<<8)
#define BDMA_CCR3_PSIZE_0   (0x1U<<8)
#define BDMA_CCR3_MINC      (0x1U<<7)
#define BDMA_CCR3_PINC      (0x1U<<6)
#define BDMA_CCR3_CIRC      (0x1U<<5)
#define BDMA_CCR3_DIR       (0x1U<<4)
#define BDMA_CCR3_TEIE      (0x1U<<3)
#define BDMA_CCR3_HTIE      (0x1U<<2)
#define BDMA_CCR3_TCIE      (0x1U<<1)
#define BDMA_CCR3_EN        (0x1U<<0)

// CNDTR3 Configuration

#define BDMA_CNDTR3_NDT     (0xFFFFU<<0)
#define BDMA_CNDTR3_NDT_0   (0x1U<<0)

// CPAR3 Configuration

#define BDMA_CPAR3_PA       (0xFFFFFFFFU<<0)
#define BDMA_CPAR3_PA_0     (0x1U<<0)

// CMAR3 Configuration

#define BDMA_CMAR3_MA       (0xFFFFFFFFU<<0)
#define BDMA_CMAR3_MA_0     (0x1U<<0)

// CCR4 Configuration

#define BDMA_CCR4_MEM2MEM   (0x1U<<14)
#define BDMA_CCR4_PL        (0x3U<<12)
#define BDMA_CCR4_PL_0      (0x1U<<12)
#define BDMA_CCR4_MSIZE     (0x3U<<10)
#define BDMA_CCR4_MSIZE_0   (0x1U<<10)
#define BDMA_CCR4_PSIZE     (0x3U<<8)
#define BDMA_CCR4_PSIZE_0   (0x1U<<8)
#define BDMA_CCR4_MINC      (0x1U<<7)
#define BDMA_CCR4_PINC      (0x1U<<6)
#define BDMA_CCR4_CIRC      (0x1U<<5)
#define BDMA_CCR4_DIR       (0x1U<<4)
#define BDMA_CCR4_TEIE      (0x1U<<3)
#define BDMA_CCR4_HTIE      (0x1U<<2)
#define BDMA_CCR4_TCIE      (0x1U<<1)
#define BDMA_CCR4_EN        (0x1U<<0)

// CNDTR4 Configuration

#define BDMA_CNDTR4_NDT     (0xFFFFU<<0)
#define BDMA_CNDTR4_NDT_0   (0x1U<<0)

// CPAR4 Configuration

#define BDMA_CPAR4_PA       (0xFFFFFFFFU<<0)
#define BDMA_CPAR4_PA_0     (0x1U<<0)

// CMAR4 Configuration

#define BDMA_CMAR4_MA       (0xFFFFFFFFU<<0)
#define BDMA_CMAR4_MA_0     (0x1U<<0)

// CCR5 Configuration

#define BDMA_CCR5_MEM2MEM   (0x1U<<14)
#define BDMA_CCR5_PL        (0x3U<<12)
#define BDMA_CCR5_PL_0      (0x1U<<12)
#define BDMA_CCR5_MSIZE     (0x3U<<10)
#define BDMA_CCR5_MSIZE_0   (0x1U<<10)
#define BDMA_CCR5_PSIZE     (0x3U<<8)
#define BDMA_CCR5_PSIZE_0   (0x1U<<8)
#define BDMA_CCR5_MINC      (0x1U<<7)
#define BDMA_CCR5_PINC      (0x1U<<6)
#define BDMA_CCR5_CIRC      (0x1U<<5)
#define BDMA_CCR5_DIR       (0x1U<<4)
#define BDMA_CCR5_TEIE      (0x1U<<3)
#define BDMA_CCR5_HTIE      (0x1U<<2)
#define BDMA_CCR5_TCIE      (0x1U<<1)
#define BDMA_CCR5_EN        (0x1U<<0)

// CNDTR5 Configuration

#define BDMA_CNDTR5_NDT     (0xFFFFU<<0)
#define BDMA_CNDTR5_NDT_0   (0x1U<<0)

// CPAR5 Configuration

#define BDMA_CPAR5_PA       (0xFFFFFFFFU<<0)
#define BDMA_CPAR5_PA_0     (0x1U<<0)

// CMAR5 Configuration

#define BDMA_CMAR5_MA       (0xFFFFFFFFU<<0)
#define BDMA_CMAR5_MA_0     (0x1U<<0)

// CCR6 Configuration

#define BDMA_CCR6_MEM2MEM   (0x1U<<14)
#define BDMA_CCR6_PL        (0x3U<<12)
#define BDMA_CCR6_PL_0      (0x1U<<12)
#define BDMA_CCR6_MSIZE     (0x3U<<10)
#define BDMA_CCR6_MSIZE_0   (0x1U<<10)
#define BDMA_CCR6_PSIZE     (0x3U<<8)
#define BDMA_CCR6_PSIZE_0   (0x1U<<8)
#define BDMA_CCR6_MINC      (0x1U<<7)
#define BDMA_CCR6_PINC      (0x1U<<6)
#define BDMA_CCR6_CIRC      (0x1U<<5)
#define BDMA_CCR6_DIR       (0x1U<<4)
#define BDMA_CCR6_TEIE      (0x1U<<3)
#define BDMA_CCR6_HTIE      (0x1U<<2)
#define BDMA_CCR6_TCIE      (0x1U<<1)
#define BDMA_CCR6_EN        (0x1U<<0)

// CNDTR6 Configuration

#define BDMA_CNDTR6_NDT     (0xFFFFU<<0)
#define BDMA_CNDTR6_NDT_0   (0x1U<<0)

// CPAR6 Configuration

#define BDMA_CPAR6_PA       (0xFFFFFFFFU<<0)
#define BDMA_CPAR6_PA_0     (0x1U<<0)

// CMAR6 Configuration

#define BDMA_CMAR6_MA       (0xFFFFFFFFU<<0)
#define BDMA_CMAR6_MA_0     (0x1U<<0)

// CCR7 Configuration

#define BDMA_CCR7_MEM2MEM   (0x1U<<14)
#define BDMA_CCR7_PL        (0x3U<<12)
#define BDMA_CCR7_PL_0      (0x1U<<12)
#define BDMA_CCR7_MSIZE     (0x3U<<10)
#define BDMA_CCR7_MSIZE_0   (0x1U<<10)
#define BDMA_CCR7_PSIZE     (0x3U<<8)
#define BDMA_CCR7_PSIZE_0   (0x1U<<8)
#define BDMA_CCR7_MINC      (0x1U<<7)
#define BDMA_CCR7_PINC      (0x1U<<6)
#define BDMA_CCR7_CIRC      (0x1U<<5)
#define BDMA_CCR7_DIR       (0x1U<<4)
#define BDMA_CCR7_TEIE      (0x1U<<3)
#define BDMA_CCR7_HTIE      (0x1U<<2)
#define BDMA_CCR7_TCIE      (0x1U<<1)
#define BDMA_CCR7_EN        (0x1U<<0)

// CNDTR7 Configuration

#define BDMA_CNDTR7_NDT     (0xFFFFU<<0)
#define BDMA_CNDTR7_NDT_0   (0x1U<<0)

// CPAR7 Configuration

#define BDMA_CPAR7_PA       (0xFFFFFFFFU<<0)
#define BDMA_CPAR7_PA_0     (0x1U<<0)

// CMAR7 Configuration

#define BDMA_CMAR7_MA       (0xFFFFFFFFU<<0)
#define BDMA_CMAR7_MA_0     (0x1U<<0)

// CCR8 Configuration

#define BDMA_CCR8_MEM2MEM   (0x1U<<14)
#define BDMA_CCR8_PL        (0x3U<<12)
#define BDMA_CCR8_PL_0      (0x1U<<12)
#define BDMA_CCR8_MSIZE     (0x3U<<10)
#define BDMA_CCR8_MSIZE_0   (0x1U<<10)
#define BDMA_CCR8_PSIZE     (0x3U<<8)
#define BDMA_CCR8_PSIZE_0   (0x1U<<8)
#define BDMA_CCR8_MINC      (0x1U<<7)
#define BDMA_CCR8_PINC      (0x1U<<6)
#define BDMA_CCR8_CIRC      (0x1U<<5)
#define BDMA_CCR8_DIR       (0x1U<<4)
#define BDMA_CCR8_TEIE      (0x1U<<3)
#define BDMA_CCR8_HTIE      (0x1U<<2)
#define BDMA_CCR8_TCIE      (0x1U<<1)
#define BDMA_CCR8_EN        (0x1U<<0)

// CNDTR8 Configuration

#define BDMA_CNDTR8_NDT     (0xFFFFU<<0)
#define BDMA_CNDTR8_NDT_0   (0x1U<<0)

// CPAR8 Configuration

#define BDMA_CPAR8_PA       (0xFFFFFFFFU<<0)
#define BDMA_CPAR8_PA_0     (0x1U<<0)

// CMAR8 Configuration

#define BDMA_CMAR8_MA       (0xFFFFFFFFU<<0)
#define BDMA_CMAR8_MA_0     (0x1U<<0)
