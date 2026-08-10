/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     RP2350_sio equates.
 */

#pragma once

#include    <stdint.h>

// SIO address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CPUID;
    volatile    uint32_t    GPIO_IN;
    volatile    uint32_t    GPIO_HI_IN;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    GPIO_OUT;
    volatile    uint32_t    GPIO_HI_OUT;
    volatile    uint32_t    GPIO_OUT_SET;
    volatile    uint32_t    GPIO_HI_OUT_SET;
    volatile    uint32_t    GPIO_OUT_CLR;
    volatile    uint32_t    GPIO_HI_OUT_CLR;
    volatile    uint32_t    GPIO_OUT_XOR;
    volatile    uint32_t    GPIO_HI_OUT_XOR;
    volatile    uint32_t    GPIO_OE;
    volatile    uint32_t    GPIO_HI_OE;
    volatile    uint32_t    GPIO_OE_SET;
    volatile    uint32_t    GPIO_HI_OE_SET;
    volatile    uint32_t    GPIO_OE_CLR;
    volatile    uint32_t    GPIO_HI_OE_CLR;
    volatile    uint32_t    GPIO_OE_XOR;
    volatile    uint32_t    GPIO_HI_OE_XOR;
    volatile    uint32_t    FIFO_ST;
    volatile    uint32_t    FIFO_WR;
    volatile    uint32_t    FIFO_RD;
    volatile    uint32_t    SPINLOCK_ST;
    volatile    uint32_t    RESERVED1[8];
    volatile    uint32_t    INTERP0_ACCUM0;
    volatile    uint32_t    INTERP0_ACCUM1;
    volatile    uint32_t    INTERP0_BASE0;
    volatile    uint32_t    INTERP0_BASE1;
    volatile    uint32_t    INTERP0_BASE2;
    volatile    uint32_t    INTERP0_POP_LANE0;
    volatile    uint32_t    INTERP0_POP_LANE1;
    volatile    uint32_t    INTERP0_POP_FULL;
    volatile    uint32_t    INTERP0_PEEK_LANE0;
    volatile    uint32_t    INTERP0_PEEK_LANE1;
    volatile    uint32_t    INTERP0_PEEK_FULL;
    volatile    uint32_t    INTERP0_CTRL_LANE0;
    volatile    uint32_t    INTERP0_CTRL_LANE1;
    volatile    uint32_t    INTERP0_ACCUM0_ADD;
    volatile    uint32_t    INTERP0_ACCUM1_ADD;
    volatile    uint32_t    INTERP0_BASE_1AND0;
    volatile    uint32_t    INTERP1_ACCUM0;
    volatile    uint32_t    INTERP1_ACCUM1;
    volatile    uint32_t    INTERP1_BASE0;
    volatile    uint32_t    INTERP1_BASE1;
    volatile    uint32_t    INTERP1_BASE2;
    volatile    uint32_t    INTERP1_POP_LANE0;
    volatile    uint32_t    INTERP1_POP_LANE1;
    volatile    uint32_t    INTERP1_POP_FULL;
    volatile    uint32_t    INTERP1_PEEK_LANE0;
    volatile    uint32_t    INTERP1_PEEK_LANE1;
    volatile    uint32_t    INTERP1_PEEK_FULL;
    volatile    uint32_t    INTERP1_CTRL_LANE0;
    volatile    uint32_t    INTERP1_CTRL_LANE1;
    volatile    uint32_t    INTERP1_ACCUM0_ADD;
    volatile    uint32_t    INTERP1_ACCUM1_ADD;
    volatile    uint32_t    INTERP1_BASE_1AND0;
    volatile    uint32_t    SPINLOCK0;
    volatile    uint32_t    SPINLOCK1;
    volatile    uint32_t    SPINLOCK2;
    volatile    uint32_t    SPINLOCK3;
    volatile    uint32_t    SPINLOCK4;
    volatile    uint32_t    SPINLOCK5;
    volatile    uint32_t    SPINLOCK6;
    volatile    uint32_t    SPINLOCK7;
    volatile    uint32_t    SPINLOCK8;
    volatile    uint32_t    SPINLOCK9;
    volatile    uint32_t    SPINLOCK10;
    volatile    uint32_t    SPINLOCK11;
    volatile    uint32_t    SPINLOCK12;
    volatile    uint32_t    SPINLOCK13;
    volatile    uint32_t    SPINLOCK14;
    volatile    uint32_t    SPINLOCK15;
    volatile    uint32_t    SPINLOCK16;
    volatile    uint32_t    SPINLOCK17;
    volatile    uint32_t    SPINLOCK18;
    volatile    uint32_t    SPINLOCK19;
    volatile    uint32_t    SPINLOCK20;
    volatile    uint32_t    SPINLOCK21;
    volatile    uint32_t    SPINLOCK22;
    volatile    uint32_t    SPINLOCK23;
    volatile    uint32_t    SPINLOCK24;
    volatile    uint32_t    SPINLOCK25;
    volatile    uint32_t    SPINLOCK26;
    volatile    uint32_t    SPINLOCK27;
    volatile    uint32_t    SPINLOCK28;
    volatile    uint32_t    SPINLOCK29;
    volatile    uint32_t    SPINLOCK30;
    volatile    uint32_t    SPINLOCK31;
    volatile    uint32_t    DOORBELL_OUT_SET;
    volatile    uint32_t    DOORBELL_OUT_CLR;
    volatile    uint32_t    DOORBELL_IN_SET;
    volatile    uint32_t    DOORBELL_IN_CLR;
    volatile    uint32_t    PERI_NONSEC;
    volatile    uint32_t    RESERVED2[3];
    volatile    uint32_t    RISCV_SOFTIRQ;
    volatile    uint32_t    MTIME_CTRL;
    volatile    uint32_t    RESERVED3[2];
    volatile    uint32_t    MTIME;
    volatile    uint32_t    MTIMEH;
    volatile    uint32_t    MTIMECMP;
    volatile    uint32_t    MTIMECMPH;
    volatile    uint32_t    TMDS_CTRL;
    volatile    uint32_t    TMDS_WDATA;
    volatile    uint32_t    TMDS_PEEK_SINGLE;
    volatile    uint32_t    TMDS_POP_SINGLE;
    volatile    uint32_t    TMDS_PEEK_DOUBLE_L0;
    volatile    uint32_t    TMDS_POP_DOUBLE_L0;
    volatile    uint32_t    TMDS_PEEK_DOUBLE_L1;
    volatile    uint32_t    TMDS_POP_DOUBLE_L1;
    volatile    uint32_t    TMDS_PEEK_DOUBLE_L2;
    volatile    uint32_t    TMDS_POP_DOUBLE_L2;
} SIO_TypeDef;

#ifdef __cplusplus
#define SIO_NS  reinterpret_cast<SIO_TypeDef *>(0xD0020000U)
#define SIO_S   reinterpret_cast<SIO_TypeDef *>(0xD0000000U)
#else
#define SIO_NS  ((SIO_TypeDef *)0xD0020000U)
#define SIO_S   ((SIO_TypeDef *)0xD0000000U)
#endif

// CPUID Configuration

#define SIO_CPUID_CPUID                                 (0xFFFFFFFFU<<0U)
#define SIO_CPUID_CPUID_0                               (0x1U<<0U)

// GPIO_IN Configuration

#define SIO_GPIO_IN_GPIO_IN                             (0xFFFFFFFFU<<0U)
#define SIO_GPIO_IN_GPIO_IN_0                           (0x1U<<0U)

// GPIO_HI_IN Configuration

#define SIO_GPIO_HI_IN_GPIO                             (0xFFFFU<<0U)
#define SIO_GPIO_HI_IN_GPIO_0                           (0x1U<<0U)
#define SIO_GPIO_HI_IN_USB_DP                           (0x1U<<24U)
#define SIO_GPIO_HI_IN_USB_DM                           (0x1U<<25U)
#define SIO_GPIO_HI_IN_QSPI_SCK                         (0x1U<<26U)
#define SIO_GPIO_HI_IN_QSPI_CSN                         (0x1U<<27U)
#define SIO_GPIO_HI_IN_QSPI_SD                          (0xFU<<28U)
#define SIO_GPIO_HI_IN_QSPI_SD_0                        (0x1U<<28U)

// GPIO_OUT Configuration

#define SIO_GPIO_OUT_GPIO_OUT                           (0xFFFFFFFFU<<0U)
#define SIO_GPIO_OUT_GPIO_OUT_0                         (0x1U<<0U)

// GPIO_HI_OUT Configuration

#define SIO_GPIO_HI_OUT_GPIO                            (0xFFFFU<<0U)
#define SIO_GPIO_HI_OUT_GPIO_0                          (0x1U<<0U)
#define SIO_GPIO_HI_OUT_USB_DP                          (0x1U<<24U)
#define SIO_GPIO_HI_OUT_USB_DM                          (0x1U<<25U)
#define SIO_GPIO_HI_OUT_QSPI_SCK                        (0x1U<<26U)
#define SIO_GPIO_HI_OUT_QSPI_CSN                        (0x1U<<27U)
#define SIO_GPIO_HI_OUT_QSPI_SD                         (0xFU<<28U)
#define SIO_GPIO_HI_OUT_QSPI_SD_0                       (0x1U<<28U)

// GPIO_OUT_SET Configuration

#define SIO_GPIO_OUT_SET_GPIO_OUT_SET                   (0xFFFFFFFFU<<0U)
#define SIO_GPIO_OUT_SET_GPIO_OUT_SET_0                 (0x1U<<0U)

// GPIO_HI_OUT_SET Configuration

#define SIO_GPIO_HI_OUT_SET_GPIO                        (0xFFFFU<<0U)
#define SIO_GPIO_HI_OUT_SET_GPIO_0                      (0x1U<<0U)
#define SIO_GPIO_HI_OUT_SET_USB_DP                      (0x1U<<24U)
#define SIO_GPIO_HI_OUT_SET_USB_DM                      (0x1U<<25U)
#define SIO_GPIO_HI_OUT_SET_QSPI_SCK                    (0x1U<<26U)
#define SIO_GPIO_HI_OUT_SET_QSPI_CSN                    (0x1U<<27U)
#define SIO_GPIO_HI_OUT_SET_QSPI_SD                     (0xFU<<28U)
#define SIO_GPIO_HI_OUT_SET_QSPI_SD_0                   (0x1U<<28U)

// GPIO_OUT_CLR Configuration

#define SIO_GPIO_OUT_CLR_GPIO_OUT_CLR                   (0xFFFFFFFFU<<0U)
#define SIO_GPIO_OUT_CLR_GPIO_OUT_CLR_0                 (0x1U<<0U)

// GPIO_HI_OUT_CLR Configuration

#define SIO_GPIO_HI_OUT_CLR_GPIO                        (0xFFFFU<<0U)
#define SIO_GPIO_HI_OUT_CLR_GPIO_0                      (0x1U<<0U)
#define SIO_GPIO_HI_OUT_CLR_USB_DP                      (0x1U<<24U)
#define SIO_GPIO_HI_OUT_CLR_USB_DM                      (0x1U<<25U)
#define SIO_GPIO_HI_OUT_CLR_QSPI_SCK                    (0x1U<<26U)
#define SIO_GPIO_HI_OUT_CLR_QSPI_CSN                    (0x1U<<27U)
#define SIO_GPIO_HI_OUT_CLR_QSPI_SD                     (0xFU<<28U)
#define SIO_GPIO_HI_OUT_CLR_QSPI_SD_0                   (0x1U<<28U)

// GPIO_OUT_XOR Configuration

#define SIO_GPIO_OUT_XOR_GPIO_OUT_XOR                   (0xFFFFFFFFU<<0U)
#define SIO_GPIO_OUT_XOR_GPIO_OUT_XOR_0                 (0x1U<<0U)

// GPIO_HI_OUT_XOR Configuration

#define SIO_GPIO_HI_OUT_XOR_GPIO                        (0xFFFFU<<0U)
#define SIO_GPIO_HI_OUT_XOR_GPIO_0                      (0x1U<<0U)
#define SIO_GPIO_HI_OUT_XOR_USB_DP                      (0x1U<<24U)
#define SIO_GPIO_HI_OUT_XOR_USB_DM                      (0x1U<<25U)
#define SIO_GPIO_HI_OUT_XOR_QSPI_SCK                    (0x1U<<26U)
#define SIO_GPIO_HI_OUT_XOR_QSPI_CSN                    (0x1U<<27U)
#define SIO_GPIO_HI_OUT_XOR_QSPI_SD                     (0xFU<<28U)
#define SIO_GPIO_HI_OUT_XOR_QSPI_SD_0                   (0x1U<<28U)

// GPIO_OE Configuration

#define SIO_GPIO_OE_GPIO_OE                             (0xFFFFFFFFU<<0U)
#define SIO_GPIO_OE_GPIO_OE_0                           (0x1U<<0U)

// GPIO_HI_OE Configuration

#define SIO_GPIO_HI_OE_GPIO                             (0xFFFFU<<0U)
#define SIO_GPIO_HI_OE_GPIO_0                           (0x1U<<0U)
#define SIO_GPIO_HI_OE_USB_DP                           (0x1U<<24U)
#define SIO_GPIO_HI_OE_USB_DM                           (0x1U<<25U)
#define SIO_GPIO_HI_OE_QSPI_SCK                         (0x1U<<26U)
#define SIO_GPIO_HI_OE_QSPI_CSN                         (0x1U<<27U)
#define SIO_GPIO_HI_OE_QSPI_SD                          (0xFU<<28U)
#define SIO_GPIO_HI_OE_QSPI_SD_0                        (0x1U<<28U)

// GPIO_OE_SET Configuration

#define SIO_GPIO_OE_SET_GPIO_OE_SET                     (0xFFFFFFFFU<<0U)
#define SIO_GPIO_OE_SET_GPIO_OE_SET_0                   (0x1U<<0U)

// GPIO_HI_OE_SET Configuration

#define SIO_GPIO_HI_OE_SET_GPIO                         (0xFFFFU<<0U)
#define SIO_GPIO_HI_OE_SET_GPIO_0                       (0x1U<<0U)
#define SIO_GPIO_HI_OE_SET_USB_DP                       (0x1U<<24U)
#define SIO_GPIO_HI_OE_SET_USB_DM                       (0x1U<<25U)
#define SIO_GPIO_HI_OE_SET_QSPI_SCK                     (0x1U<<26U)
#define SIO_GPIO_HI_OE_SET_QSPI_CSN                     (0x1U<<27U)
#define SIO_GPIO_HI_OE_SET_QSPI_SD                      (0xFU<<28U)
#define SIO_GPIO_HI_OE_SET_QSPI_SD_0                    (0x1U<<28U)

// GPIO_OE_CLR Configuration

#define SIO_GPIO_OE_CLR_GPIO_OE_CLR                     (0xFFFFFFFFU<<0U)
#define SIO_GPIO_OE_CLR_GPIO_OE_CLR_0                   (0x1U<<0U)

// GPIO_HI_OE_CLR Configuration

#define SIO_GPIO_HI_OE_CLR_GPIO                         (0xFFFFU<<0U)
#define SIO_GPIO_HI_OE_CLR_GPIO_0                       (0x1U<<0U)
#define SIO_GPIO_HI_OE_CLR_USB_DP                       (0x1U<<24U)
#define SIO_GPIO_HI_OE_CLR_USB_DM                       (0x1U<<25U)
#define SIO_GPIO_HI_OE_CLR_QSPI_SCK                     (0x1U<<26U)
#define SIO_GPIO_HI_OE_CLR_QSPI_CSN                     (0x1U<<27U)
#define SIO_GPIO_HI_OE_CLR_QSPI_SD                      (0xFU<<28U)
#define SIO_GPIO_HI_OE_CLR_QSPI_SD_0                    (0x1U<<28U)

// GPIO_OE_XOR Configuration

#define SIO_GPIO_OE_XOR_GPIO_OE_XOR                     (0xFFFFFFFFU<<0U)
#define SIO_GPIO_OE_XOR_GPIO_OE_XOR_0                   (0x1U<<0U)

// GPIO_HI_OE_XOR Configuration

#define SIO_GPIO_HI_OE_XOR_GPIO                         (0xFFFFU<<0U)
#define SIO_GPIO_HI_OE_XOR_GPIO_0                       (0x1U<<0U)
#define SIO_GPIO_HI_OE_XOR_USB_DP                       (0x1U<<24U)
#define SIO_GPIO_HI_OE_XOR_USB_DM                       (0x1U<<25U)
#define SIO_GPIO_HI_OE_XOR_QSPI_SCK                     (0x1U<<26U)
#define SIO_GPIO_HI_OE_XOR_QSPI_CSN                     (0x1U<<27U)
#define SIO_GPIO_HI_OE_XOR_QSPI_SD                      (0xFU<<28U)
#define SIO_GPIO_HI_OE_XOR_QSPI_SD_0                    (0x1U<<28U)

// FIFO_ST Configuration

#define SIO_FIFO_ST_VLD                                 (0x1U<<0U)
#define SIO_FIFO_ST_RDY                                 (0x1U<<1U)
#define SIO_FIFO_ST_WOF                                 (0x1U<<2U)
#define SIO_FIFO_ST_ROE                                 (0x1U<<3U)

// FIFO_WR Configuration

#define SIO_FIFO_WR_FIFO_WR                             (0xFFFFFFFFU<<0U)
#define SIO_FIFO_WR_FIFO_WR_0                           (0x1U<<0U)

// FIFO_RD Configuration

#define SIO_FIFO_RD_FIFO_RD                             (0xFFFFFFFFU<<0U)
#define SIO_FIFO_RD_FIFO_RD_0                           (0x1U<<0U)

// SPINLOCK_ST Configuration

#define SIO_SPINLOCK_ST_SPINLOCK_ST                     (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK_ST_SPINLOCK_ST_0                   (0x1U<<0U)

// INTERP0_ACCUM0 Configuration

#define SIO_INTERP0_ACCUM0_INTERP0_ACCUM0               (0xFFFFFFFFU<<0U)
#define SIO_INTERP0_ACCUM0_INTERP0_ACCUM0_0             (0x1U<<0U)

// INTERP0_ACCUM1 Configuration

#define SIO_INTERP0_ACCUM1_INTERP0_ACCUM1               (0xFFFFFFFFU<<0U)
#define SIO_INTERP0_ACCUM1_INTERP0_ACCUM1_0             (0x1U<<0U)

// INTERP0_BASE0 Configuration

#define SIO_INTERP0_BASE0_INTERP0_BASE0                 (0xFFFFFFFFU<<0U)
#define SIO_INTERP0_BASE0_INTERP0_BASE0_0               (0x1U<<0U)

// INTERP0_BASE1 Configuration

#define SIO_INTERP0_BASE1_INTERP0_BASE1                 (0xFFFFFFFFU<<0U)
#define SIO_INTERP0_BASE1_INTERP0_BASE1_0               (0x1U<<0U)

// INTERP0_BASE2 Configuration

#define SIO_INTERP0_BASE2_INTERP0_BASE2                 (0xFFFFFFFFU<<0U)
#define SIO_INTERP0_BASE2_INTERP0_BASE2_0               (0x1U<<0U)

// INTERP0_POP_LANE0 Configuration

#define SIO_INTERP0_POP_LANE0_INTERP0_POP_LANE0         (0xFFFFFFFFU<<0U)
#define SIO_INTERP0_POP_LANE0_INTERP0_POP_LANE0_0       (0x1U<<0U)

// INTERP0_POP_LANE1 Configuration

#define SIO_INTERP0_POP_LANE1_INTERP0_POP_LANE1         (0xFFFFFFFFU<<0U)
#define SIO_INTERP0_POP_LANE1_INTERP0_POP_LANE1_0       (0x1U<<0U)

// INTERP0_POP_FULL Configuration

#define SIO_INTERP0_POP_FULL_INTERP0_POP_FULL           (0xFFFFFFFFU<<0U)
#define SIO_INTERP0_POP_FULL_INTERP0_POP_FULL_0         (0x1U<<0U)

// INTERP0_PEEK_LANE0 Configuration

#define SIO_INTERP0_PEEK_LANE0_INTERP0_PEEK_LANE0       (0xFFFFFFFFU<<0U)
#define SIO_INTERP0_PEEK_LANE0_INTERP0_PEEK_LANE0_0     (0x1U<<0U)

// INTERP0_PEEK_LANE1 Configuration

#define SIO_INTERP0_PEEK_LANE1_INTERP0_PEEK_LANE1       (0xFFFFFFFFU<<0U)
#define SIO_INTERP0_PEEK_LANE1_INTERP0_PEEK_LANE1_0     (0x1U<<0U)

// INTERP0_PEEK_FULL Configuration

#define SIO_INTERP0_PEEK_FULL_INTERP0_PEEK_FULL         (0xFFFFFFFFU<<0U)
#define SIO_INTERP0_PEEK_FULL_INTERP0_PEEK_FULL_0       (0x1U<<0U)

// INTERP0_CTRL_LANE0 Configuration

#define SIO_INTERP0_CTRL_LANE0_SHIFT                    (0x1FU<<0U)
#define SIO_INTERP0_CTRL_LANE0_SHIFT_0                  (0x1U<<0U)
#define SIO_INTERP0_CTRL_LANE0_MASK_LSB                 (0x1FU<<5U)
#define SIO_INTERP0_CTRL_LANE0_MASK_LSB_0               (0x1U<<5U)
#define SIO_INTERP0_CTRL_LANE0_MASK_MSB                 (0x1FU<<10U)
#define SIO_INTERP0_CTRL_LANE0_MASK_MSB_0               (0x1U<<10U)
#define SIO_INTERP0_CTRL_LANE0_SIGNED                   (0x1U<<15U)
#define SIO_INTERP0_CTRL_LANE0_CROSS_INPUT              (0x1U<<16U)
#define SIO_INTERP0_CTRL_LANE0_CROSS_RESULT             (0x1U<<17U)
#define SIO_INTERP0_CTRL_LANE0_ADD_RAW                  (0x1U<<18U)
#define SIO_INTERP0_CTRL_LANE0_FORCE_MSB                (0x3U<<19U)
#define SIO_INTERP0_CTRL_LANE0_FORCE_MSB_0              (0x1U<<19U)
#define SIO_INTERP0_CTRL_LANE0_BLEND                    (0x1U<<21U)
#define SIO_INTERP0_CTRL_LANE0_OVERF0                   (0x1U<<23U)
#define SIO_INTERP0_CTRL_LANE0_OVERF1                   (0x1U<<24U)
#define SIO_INTERP0_CTRL_LANE0_OVERF                    (0x1U<<25U)

// INTERP0_CTRL_LANE1 Configuration

#define SIO_INTERP0_CTRL_LANE1_SHIFT                    (0x1FU<<0U)
#define SIO_INTERP0_CTRL_LANE1_SHIFT_0                  (0x1U<<0U)
#define SIO_INTERP0_CTRL_LANE1_MASK_LSB                 (0x1FU<<5U)
#define SIO_INTERP0_CTRL_LANE1_MASK_LSB_0               (0x1U<<5U)
#define SIO_INTERP0_CTRL_LANE1_MASK_MSB                 (0x1FU<<10U)
#define SIO_INTERP0_CTRL_LANE1_MASK_MSB_0               (0x1U<<10U)
#define SIO_INTERP0_CTRL_LANE1_SIGNED                   (0x1U<<15U)
#define SIO_INTERP0_CTRL_LANE1_CROSS_INPUT              (0x1U<<16U)
#define SIO_INTERP0_CTRL_LANE1_CROSS_RESULT             (0x1U<<17U)
#define SIO_INTERP0_CTRL_LANE1_ADD_RAW                  (0x1U<<18U)
#define SIO_INTERP0_CTRL_LANE1_FORCE_MSB                (0x3U<<19U)
#define SIO_INTERP0_CTRL_LANE1_FORCE_MSB_0              (0x1U<<19U)

// INTERP0_ACCUM0_ADD Configuration

#define SIO_INTERP0_ACCUM0_ADD_INTERP0_ACCUM0_ADD       (0xFFFFFFU<<0U)
#define SIO_INTERP0_ACCUM0_ADD_INTERP0_ACCUM0_ADD_0     (0x1U<<0U)

// INTERP0_ACCUM1_ADD Configuration

#define SIO_INTERP0_ACCUM1_ADD_INTERP0_ACCUM1_ADD       (0xFFFFFFU<<0U)
#define SIO_INTERP0_ACCUM1_ADD_INTERP0_ACCUM1_ADD_0     (0x1U<<0U)

// INTERP0_BASE_1AND0 Configuration

#define SIO_INTERP0_BASE_1AND0_INTERP0_BASE_1AND0       (0xFFFFFFFFU<<0U)
#define SIO_INTERP0_BASE_1AND0_INTERP0_BASE_1AND0_0     (0x1U<<0U)

// INTERP1_ACCUM0 Configuration

#define SIO_INTERP1_ACCUM0_INTERP1_ACCUM0               (0xFFFFFFFFU<<0U)
#define SIO_INTERP1_ACCUM0_INTERP1_ACCUM0_0             (0x1U<<0U)

// INTERP1_ACCUM1 Configuration

#define SIO_INTERP1_ACCUM1_INTERP1_ACCUM1               (0xFFFFFFFFU<<0U)
#define SIO_INTERP1_ACCUM1_INTERP1_ACCUM1_0             (0x1U<<0U)

// INTERP1_BASE0 Configuration

#define SIO_INTERP1_BASE0_INTERP1_BASE0                 (0xFFFFFFFFU<<0U)
#define SIO_INTERP1_BASE0_INTERP1_BASE0_0               (0x1U<<0U)

// INTERP1_BASE1 Configuration

#define SIO_INTERP1_BASE1_INTERP1_BASE1                 (0xFFFFFFFFU<<0U)
#define SIO_INTERP1_BASE1_INTERP1_BASE1_0               (0x1U<<0U)

// INTERP1_BASE2 Configuration

#define SIO_INTERP1_BASE2_INTERP1_BASE2                 (0xFFFFFFFFU<<0U)
#define SIO_INTERP1_BASE2_INTERP1_BASE2_0               (0x1U<<0U)

// INTERP1_POP_LANE0 Configuration

#define SIO_INTERP1_POP_LANE0_INTERP1_POP_LANE0         (0xFFFFFFFFU<<0U)
#define SIO_INTERP1_POP_LANE0_INTERP1_POP_LANE0_0       (0x1U<<0U)

// INTERP1_POP_LANE1 Configuration

#define SIO_INTERP1_POP_LANE1_INTERP1_POP_LANE1         (0xFFFFFFFFU<<0U)
#define SIO_INTERP1_POP_LANE1_INTERP1_POP_LANE1_0       (0x1U<<0U)

// INTERP1_POP_FULL Configuration

#define SIO_INTERP1_POP_FULL_INTERP1_POP_FULL           (0xFFFFFFFFU<<0U)
#define SIO_INTERP1_POP_FULL_INTERP1_POP_FULL_0         (0x1U<<0U)

// INTERP1_PEEK_LANE0 Configuration

#define SIO_INTERP1_PEEK_LANE0_INTERP1_PEEK_LANE0       (0xFFFFFFFFU<<0U)
#define SIO_INTERP1_PEEK_LANE0_INTERP1_PEEK_LANE0_0     (0x1U<<0U)

// INTERP1_PEEK_LANE1 Configuration

#define SIO_INTERP1_PEEK_LANE1_INTERP1_PEEK_LANE1       (0xFFFFFFFFU<<0U)
#define SIO_INTERP1_PEEK_LANE1_INTERP1_PEEK_LANE1_0     (0x1U<<0U)

// INTERP1_PEEK_FULL Configuration

#define SIO_INTERP1_PEEK_FULL_INTERP1_PEEK_FULL         (0xFFFFFFFFU<<0U)
#define SIO_INTERP1_PEEK_FULL_INTERP1_PEEK_FULL_0       (0x1U<<0U)

// INTERP1_CTRL_LANE0 Configuration

#define SIO_INTERP1_CTRL_LANE0_SHIFT                    (0x1FU<<0U)
#define SIO_INTERP1_CTRL_LANE0_SHIFT_0                  (0x1U<<0U)
#define SIO_INTERP1_CTRL_LANE0_MASK_LSB                 (0x1FU<<5U)
#define SIO_INTERP1_CTRL_LANE0_MASK_LSB_0               (0x1U<<5U)
#define SIO_INTERP1_CTRL_LANE0_MASK_MSB                 (0x1FU<<10U)
#define SIO_INTERP1_CTRL_LANE0_MASK_MSB_0               (0x1U<<10U)
#define SIO_INTERP1_CTRL_LANE0_SIGNED                   (0x1U<<15U)
#define SIO_INTERP1_CTRL_LANE0_CROSS_INPUT              (0x1U<<16U)
#define SIO_INTERP1_CTRL_LANE0_CROSS_RESULT             (0x1U<<17U)
#define SIO_INTERP1_CTRL_LANE0_ADD_RAW                  (0x1U<<18U)
#define SIO_INTERP1_CTRL_LANE0_FORCE_MSB                (0x3U<<19U)
#define SIO_INTERP1_CTRL_LANE0_FORCE_MSB_0              (0x1U<<19U)
#define SIO_INTERP1_CTRL_LANE0_CLAMP                    (0x1U<<22U)
#define SIO_INTERP1_CTRL_LANE0_OVERF0                   (0x1U<<23U)
#define SIO_INTERP1_CTRL_LANE0_OVERF1                   (0x1U<<24U)
#define SIO_INTERP1_CTRL_LANE0_OVERF                    (0x1U<<25U)

// INTERP1_CTRL_LANE1 Configuration

#define SIO_INTERP1_CTRL_LANE1_SHIFT                    (0x1FU<<0U)
#define SIO_INTERP1_CTRL_LANE1_SHIFT_0                  (0x1U<<0U)
#define SIO_INTERP1_CTRL_LANE1_MASK_LSB                 (0x1FU<<5U)
#define SIO_INTERP1_CTRL_LANE1_MASK_LSB_0               (0x1U<<5U)
#define SIO_INTERP1_CTRL_LANE1_MASK_MSB                 (0x1FU<<10U)
#define SIO_INTERP1_CTRL_LANE1_MASK_MSB_0               (0x1U<<10U)
#define SIO_INTERP1_CTRL_LANE1_SIGNED                   (0x1U<<15U)
#define SIO_INTERP1_CTRL_LANE1_CROSS_INPUT              (0x1U<<16U)
#define SIO_INTERP1_CTRL_LANE1_CROSS_RESULT             (0x1U<<17U)
#define SIO_INTERP1_CTRL_LANE1_ADD_RAW                  (0x1U<<18U)
#define SIO_INTERP1_CTRL_LANE1_FORCE_MSB                (0x3U<<19U)
#define SIO_INTERP1_CTRL_LANE1_FORCE_MSB_0              (0x1U<<19U)

// INTERP1_ACCUM0_ADD Configuration

#define SIO_INTERP1_ACCUM0_ADD_INTERP1_ACCUM0_ADD       (0xFFFFFFU<<0U)
#define SIO_INTERP1_ACCUM0_ADD_INTERP1_ACCUM0_ADD_0     (0x1U<<0U)

// INTERP1_ACCUM1_ADD Configuration

#define SIO_INTERP1_ACCUM1_ADD_INTERP1_ACCUM1_ADD       (0xFFFFFFU<<0U)
#define SIO_INTERP1_ACCUM1_ADD_INTERP1_ACCUM1_ADD_0     (0x1U<<0U)

// INTERP1_BASE_1AND0 Configuration

#define SIO_INTERP1_BASE_1AND0_INTERP1_BASE_1AND0       (0xFFFFFFFFU<<0U)
#define SIO_INTERP1_BASE_1AND0_INTERP1_BASE_1AND0_0     (0x1U<<0U)

// SPINLOCK0 Configuration

#define SIO_SPINLOCK0_SPINLOCK0                         (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK0_SPINLOCK0_0                       (0x1U<<0U)

// SPINLOCK1 Configuration

#define SIO_SPINLOCK1_SPINLOCK1                         (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK1_SPINLOCK1_0                       (0x1U<<0U)

// SPINLOCK2 Configuration

#define SIO_SPINLOCK2_SPINLOCK2                         (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK2_SPINLOCK2_0                       (0x1U<<0U)

// SPINLOCK3 Configuration

#define SIO_SPINLOCK3_SPINLOCK3                         (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK3_SPINLOCK3_0                       (0x1U<<0U)

// SPINLOCK4 Configuration

#define SIO_SPINLOCK4_SPINLOCK4                         (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK4_SPINLOCK4_0                       (0x1U<<0U)

// SPINLOCK5 Configuration

#define SIO_SPINLOCK5_SPINLOCK5                         (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK5_SPINLOCK5_0                       (0x1U<<0U)

// SPINLOCK6 Configuration

#define SIO_SPINLOCK6_SPINLOCK6                         (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK6_SPINLOCK6_0                       (0x1U<<0U)

// SPINLOCK7 Configuration

#define SIO_SPINLOCK7_SPINLOCK7                         (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK7_SPINLOCK7_0                       (0x1U<<0U)

// SPINLOCK8 Configuration

#define SIO_SPINLOCK8_SPINLOCK8                         (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK8_SPINLOCK8_0                       (0x1U<<0U)

// SPINLOCK9 Configuration

#define SIO_SPINLOCK9_SPINLOCK9                         (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK9_SPINLOCK9_0                       (0x1U<<0U)

// SPINLOCK10 Configuration

#define SIO_SPINLOCK10_SPINLOCK10                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK10_SPINLOCK10_0                     (0x1U<<0U)

// SPINLOCK11 Configuration

#define SIO_SPINLOCK11_SPINLOCK11                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK11_SPINLOCK11_0                     (0x1U<<0U)

// SPINLOCK12 Configuration

#define SIO_SPINLOCK12_SPINLOCK12                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK12_SPINLOCK12_0                     (0x1U<<0U)

// SPINLOCK13 Configuration

#define SIO_SPINLOCK13_SPINLOCK13                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK13_SPINLOCK13_0                     (0x1U<<0U)

// SPINLOCK14 Configuration

#define SIO_SPINLOCK14_SPINLOCK14                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK14_SPINLOCK14_0                     (0x1U<<0U)

// SPINLOCK15 Configuration

#define SIO_SPINLOCK15_SPINLOCK15                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK15_SPINLOCK15_0                     (0x1U<<0U)

// SPINLOCK16 Configuration

#define SIO_SPINLOCK16_SPINLOCK16                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK16_SPINLOCK16_0                     (0x1U<<0U)

// SPINLOCK17 Configuration

#define SIO_SPINLOCK17_SPINLOCK17                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK17_SPINLOCK17_0                     (0x1U<<0U)

// SPINLOCK18 Configuration

#define SIO_SPINLOCK18_SPINLOCK18                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK18_SPINLOCK18_0                     (0x1U<<0U)

// SPINLOCK19 Configuration

#define SIO_SPINLOCK19_SPINLOCK19                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK19_SPINLOCK19_0                     (0x1U<<0U)

// SPINLOCK20 Configuration

#define SIO_SPINLOCK20_SPINLOCK20                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK20_SPINLOCK20_0                     (0x1U<<0U)

// SPINLOCK21 Configuration

#define SIO_SPINLOCK21_SPINLOCK21                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK21_SPINLOCK21_0                     (0x1U<<0U)

// SPINLOCK22 Configuration

#define SIO_SPINLOCK22_SPINLOCK22                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK22_SPINLOCK22_0                     (0x1U<<0U)

// SPINLOCK23 Configuration

#define SIO_SPINLOCK23_SPINLOCK23                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK23_SPINLOCK23_0                     (0x1U<<0U)

// SPINLOCK24 Configuration

#define SIO_SPINLOCK24_SPINLOCK24                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK24_SPINLOCK24_0                     (0x1U<<0U)

// SPINLOCK25 Configuration

#define SIO_SPINLOCK25_SPINLOCK25                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK25_SPINLOCK25_0                     (0x1U<<0U)

// SPINLOCK26 Configuration

#define SIO_SPINLOCK26_SPINLOCK26                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK26_SPINLOCK26_0                     (0x1U<<0U)

// SPINLOCK27 Configuration

#define SIO_SPINLOCK27_SPINLOCK27                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK27_SPINLOCK27_0                     (0x1U<<0U)

// SPINLOCK28 Configuration

#define SIO_SPINLOCK28_SPINLOCK28                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK28_SPINLOCK28_0                     (0x1U<<0U)

// SPINLOCK29 Configuration

#define SIO_SPINLOCK29_SPINLOCK29                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK29_SPINLOCK29_0                     (0x1U<<0U)

// SPINLOCK30 Configuration

#define SIO_SPINLOCK30_SPINLOCK30                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK30_SPINLOCK30_0                     (0x1U<<0U)

// SPINLOCK31 Configuration

#define SIO_SPINLOCK31_SPINLOCK31                       (0xFFFFFFFFU<<0U)
#define SIO_SPINLOCK31_SPINLOCK31_0                     (0x1U<<0U)

// DOORBELL_OUT_SET Configuration

#define SIO_DOORBELL_OUT_SET_DOORBELL_OUT_SET           (0xFFU<<0U)
#define SIO_DOORBELL_OUT_SET_DOORBELL_OUT_SET_0         (0x1U<<0U)

// DOORBELL_OUT_CLR Configuration

#define SIO_DOORBELL_OUT_CLR_DOORBELL_OUT_CLR           (0xFFU<<0U)
#define SIO_DOORBELL_OUT_CLR_DOORBELL_OUT_CLR_0         (0x1U<<0U)

// DOORBELL_IN_SET Configuration

#define SIO_DOORBELL_IN_SET_DOORBELL_IN_SET             (0xFFU<<0U)
#define SIO_DOORBELL_IN_SET_DOORBELL_IN_SET_0           (0x1U<<0U)

// DOORBELL_IN_CLR Configuration

#define SIO_DOORBELL_IN_CLR_DOORBELL_IN_CLR             (0xFFU<<0U)
#define SIO_DOORBELL_IN_CLR_DOORBELL_IN_CLR_0           (0x1U<<0U)

// PERI_NONSEC Configuration

#define SIO_PERI_NONSEC_INTERP0                         (0x1U<<0U)
#define SIO_PERI_NONSEC_INTERP1                         (0x1U<<1U)
#define SIO_PERI_NONSEC_TMDS                            (0x1U<<5U)

// RISCV_SOFTIRQ Configuration

#define SIO_RISCV_SOFTIRQ_CORE0_SET                     (0x1U<<0U)
#define SIO_RISCV_SOFTIRQ_CORE1_SET                     (0x1U<<1U)
#define SIO_RISCV_SOFTIRQ_CORE0_CLR                     (0x1U<<8U)
#define SIO_RISCV_SOFTIRQ_CORE1_CLR                     (0x1U<<9U)

// MTIME_CTRL Configuration

#define SIO_MTIME_CTRL_EN                               (0x1U<<0U)
#define SIO_MTIME_CTRL_FULLSPEED                        (0x1U<<1U)
#define SIO_MTIME_CTRL_DBGPAUSE_CORE0                   (0x1U<<2U)
#define SIO_MTIME_CTRL_DBGPAUSE_CORE1                   (0x1U<<3U)

// MTIME Configuration

#define SIO_MTIME_MTIME                                 (0xFFFFFFFFU<<0U)
#define SIO_MTIME_MTIME_0                               (0x1U<<0U)

// MTIMEH Configuration

#define SIO_MTIMEH_MTIMEH                               (0xFFFFFFFFU<<0U)
#define SIO_MTIMEH_MTIMEH_0                             (0x1U<<0U)

// MTIMECMP Configuration

#define SIO_MTIMECMP_MTIMECMP                           (0xFFFFFFFFU<<0U)
#define SIO_MTIMECMP_MTIMECMP_0                         (0x1U<<0U)

// MTIMECMPH Configuration

#define SIO_MTIMECMPH_MTIMECMPH                         (0xFFFFFFFFU<<0U)
#define SIO_MTIMECMPH_MTIMECMPH_0                       (0x1U<<0U)

// TMDS_CTRL Configuration

#define SIO_TMDS_CTRL_L0_ROT                            (0xFU<<0U)
#define SIO_TMDS_CTRL_L0_ROT_0                          (0x1U<<0U)
#define SIO_TMDS_CTRL_L1_ROT                            (0xFU<<4U)
#define SIO_TMDS_CTRL_L1_ROT_0                          (0x1U<<4U)
#define SIO_TMDS_CTRL_L2_ROT                            (0xFU<<8U)
#define SIO_TMDS_CTRL_L2_ROT_0                          (0x1U<<8U)
#define SIO_TMDS_CTRL_L0_NBITS                          (0x7U<<12U)
#define SIO_TMDS_CTRL_L0_NBITS_0                        (0x1U<<12U)
#define SIO_TMDS_CTRL_L1_NBITS                          (0x7U<<15U)
#define SIO_TMDS_CTRL_L1_NBITS_0                        (0x1U<<15U)
#define SIO_TMDS_CTRL_L2_NBITS                          (0x7U<<18U)
#define SIO_TMDS_CTRL_L2_NBITS_0                        (0x1U<<18U)
#define SIO_TMDS_CTRL_INTERLEAVE                        (0x1U<<23U)
#define SIO_TMDS_CTRL_PIX_SHIFT                         (0x7U<<24U)
#define SIO_TMDS_CTRL_PIX2_NOSHIFT                      (0x1U<<27U)
#define SIO_TMDS_CTRL_CLEAR_BALANCE                     (0x1U<<28U)
#define SIO_TMDS_CTRL_PIX_SHIFT_0                       (0x0U<<24U)
#define SIO_TMDS_CTRL_PIX_SHIFT_1                       (0x1U<<24U)
#define SIO_TMDS_CTRL_PIX_SHIFT_2                       (0x2U<<24U)
#define SIO_TMDS_CTRL_PIX_SHIFT_4                       (0x3U<<24U)
#define SIO_TMDS_CTRL_PIX_SHIFT_8                       (0x4U<<24U)
#define SIO_TMDS_CTRL_PIX_SHIFT_16                      (0x5U<<24U)

// TMDS_WDATA Configuration

#define SIO_TMDS_WDATA_TMDS_WDATA                       (0xFFFFFFFFU<<0U)
#define SIO_TMDS_WDATA_TMDS_WDATA_0                     (0x1U<<0U)

// TMDS_PEEK_SINGLE Configuration

#define SIO_TMDS_PEEK_SINGLE_TMDS_PEEK_SINGLE           (0xFFFFFFFFU<<0U)
#define SIO_TMDS_PEEK_SINGLE_TMDS_PEEK_SINGLE_0         (0x1U<<0U)

// TMDS_POP_SINGLE Configuration

#define SIO_TMDS_POP_SINGLE_TMDS_POP_SINGLE             (0xFFFFFFFFU<<0U)
#define SIO_TMDS_POP_SINGLE_TMDS_POP_SINGLE_0           (0x1U<<0U)

// TMDS_PEEK_DOUBLE_L0 Configuration

#define SIO_TMDS_PEEK_DOUBLE_L0_TMDS_PEEK_DOUBLE_L0     (0xFFFFFFFFU<<0U)
#define SIO_TMDS_PEEK_DOUBLE_L0_TMDS_PEEK_DOUBLE_L0_0   (0x1U<<0U)

// TMDS_POP_DOUBLE_L0 Configuration

#define SIO_TMDS_POP_DOUBLE_L0_TMDS_POP_DOUBLE_L0       (0xFFFFFFFFU<<0U)
#define SIO_TMDS_POP_DOUBLE_L0_TMDS_POP_DOUBLE_L0_0     (0x1U<<0U)

// TMDS_PEEK_DOUBLE_L1 Configuration

#define SIO_TMDS_PEEK_DOUBLE_L1_TMDS_PEEK_DOUBLE_L1     (0xFFFFFFFFU<<0U)
#define SIO_TMDS_PEEK_DOUBLE_L1_TMDS_PEEK_DOUBLE_L1_0   (0x1U<<0U)

// TMDS_POP_DOUBLE_L1 Configuration

#define SIO_TMDS_POP_DOUBLE_L1_TMDS_POP_DOUBLE_L1       (0xFFFFFFFFU<<0U)
#define SIO_TMDS_POP_DOUBLE_L1_TMDS_POP_DOUBLE_L1_0     (0x1U<<0U)

// TMDS_PEEK_DOUBLE_L2 Configuration

#define SIO_TMDS_PEEK_DOUBLE_L2_TMDS_PEEK_DOUBLE_L2     (0xFFFFFFFFU<<0U)
#define SIO_TMDS_PEEK_DOUBLE_L2_TMDS_PEEK_DOUBLE_L2_0   (0x1U<<0U)

// TMDS_POP_DOUBLE_L2 Configuration

#define SIO_TMDS_POP_DOUBLE_L2_TMDS_POP_DOUBLE_L2       (0xFFFFFFFFU<<0U)
#define SIO_TMDS_POP_DOUBLE_L2_TMDS_POP_DOUBLE_L2_0     (0x1U<<0U)
