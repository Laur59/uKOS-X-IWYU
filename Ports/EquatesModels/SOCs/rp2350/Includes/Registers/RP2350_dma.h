/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     RP2350_dma equates.
 */

#pragma once

#include    <stdint.h>

// DMA address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CH0_READ_ADDR;
    volatile    uint32_t    CH0_WRITE_ADDR;
    volatile    uint32_t    CH0_TRANS_COUNT;
    volatile    uint32_t    CH0_CTRL_TRIG;
    volatile    uint32_t    CH0_AL1_CTRL;
    volatile    uint32_t    CH0_AL1_READ_ADDR;
    volatile    uint32_t    CH0_AL1_WRITE_ADDR;
    volatile    uint32_t    CH0_AL1_TRANS_COUNT_TRIG;
    volatile    uint32_t    CH0_AL2_CTRL;
    volatile    uint32_t    CH0_AL2_TRANS_COUNT;
    volatile    uint32_t    CH0_AL2_READ_ADDR;
    volatile    uint32_t    CH0_AL2_WRITE_ADDR_TRIG;
    volatile    uint32_t    CH0_AL3_CTRL;
    volatile    uint32_t    CH0_AL3_WRITE_ADDR;
    volatile    uint32_t    CH0_AL3_TRANS_COUNT;
    volatile    uint32_t    CH0_AL3_READ_ADDR_TRIG;
    volatile    uint32_t    CH1_READ_ADDR;
    volatile    uint32_t    CH1_WRITE_ADDR;
    volatile    uint32_t    CH1_TRANS_COUNT;
    volatile    uint32_t    CH1_CTRL_TRIG;
    volatile    uint32_t    CH1_AL1_CTRL;
    volatile    uint32_t    CH1_AL1_READ_ADDR;
    volatile    uint32_t    CH1_AL1_WRITE_ADDR;
    volatile    uint32_t    CH1_AL1_TRANS_COUNT_TRIG;
    volatile    uint32_t    CH1_AL2_CTRL;
    volatile    uint32_t    CH1_AL2_TRANS_COUNT;
    volatile    uint32_t    CH1_AL2_READ_ADDR;
    volatile    uint32_t    CH1_AL2_WRITE_ADDR_TRIG;
    volatile    uint32_t    CH1_AL3_CTRL;
    volatile    uint32_t    CH1_AL3_WRITE_ADDR;
    volatile    uint32_t    CH1_AL3_TRANS_COUNT;
    volatile    uint32_t    CH1_AL3_READ_ADDR_TRIG;
    volatile    uint32_t    CH2_READ_ADDR;
    volatile    uint32_t    CH2_WRITE_ADDR;
    volatile    uint32_t    CH2_TRANS_COUNT;
    volatile    uint32_t    CH2_CTRL_TRIG;
    volatile    uint32_t    CH2_AL1_CTRL;
    volatile    uint32_t    CH2_AL1_READ_ADDR;
    volatile    uint32_t    CH2_AL1_WRITE_ADDR;
    volatile    uint32_t    CH2_AL1_TRANS_COUNT_TRIG;
    volatile    uint32_t    CH2_AL2_CTRL;
    volatile    uint32_t    CH2_AL2_TRANS_COUNT;
    volatile    uint32_t    CH2_AL2_READ_ADDR;
    volatile    uint32_t    CH2_AL2_WRITE_ADDR_TRIG;
    volatile    uint32_t    CH2_AL3_CTRL;
    volatile    uint32_t    CH2_AL3_WRITE_ADDR;
    volatile    uint32_t    CH2_AL3_TRANS_COUNT;
    volatile    uint32_t    CH2_AL3_READ_ADDR_TRIG;
    volatile    uint32_t    CH3_READ_ADDR;
    volatile    uint32_t    CH3_WRITE_ADDR;
    volatile    uint32_t    CH3_TRANS_COUNT;
    volatile    uint32_t    CH3_CTRL_TRIG;
    volatile    uint32_t    CH3_AL1_CTRL;
    volatile    uint32_t    CH3_AL1_READ_ADDR;
    volatile    uint32_t    CH3_AL1_WRITE_ADDR;
    volatile    uint32_t    CH3_AL1_TRANS_COUNT_TRIG;
    volatile    uint32_t    CH3_AL2_CTRL;
    volatile    uint32_t    CH3_AL2_TRANS_COUNT;
    volatile    uint32_t    CH3_AL2_READ_ADDR;
    volatile    uint32_t    CH3_AL2_WRITE_ADDR_TRIG;
    volatile    uint32_t    CH3_AL3_CTRL;
    volatile    uint32_t    CH3_AL3_WRITE_ADDR;
    volatile    uint32_t    CH3_AL3_TRANS_COUNT;
    volatile    uint32_t    CH3_AL3_READ_ADDR_TRIG;
    volatile    uint32_t    CH4_READ_ADDR;
    volatile    uint32_t    CH4_WRITE_ADDR;
    volatile    uint32_t    CH4_TRANS_COUNT;
    volatile    uint32_t    CH4_CTRL_TRIG;
    volatile    uint32_t    CH4_AL1_CTRL;
    volatile    uint32_t    CH4_AL1_READ_ADDR;
    volatile    uint32_t    CH4_AL1_WRITE_ADDR;
    volatile    uint32_t    CH4_AL1_TRANS_COUNT_TRIG;
    volatile    uint32_t    CH4_AL2_CTRL;
    volatile    uint32_t    CH4_AL2_TRANS_COUNT;
    volatile    uint32_t    CH4_AL2_READ_ADDR;
    volatile    uint32_t    CH4_AL2_WRITE_ADDR_TRIG;
    volatile    uint32_t    CH4_AL3_CTRL;
    volatile    uint32_t    CH4_AL3_WRITE_ADDR;
    volatile    uint32_t    CH4_AL3_TRANS_COUNT;
    volatile    uint32_t    CH4_AL3_READ_ADDR_TRIG;
    volatile    uint32_t    CH5_READ_ADDR;
    volatile    uint32_t    CH5_WRITE_ADDR;
    volatile    uint32_t    CH5_TRANS_COUNT;
    volatile    uint32_t    CH5_CTRL_TRIG;
    volatile    uint32_t    CH5_AL1_CTRL;
    volatile    uint32_t    CH5_AL1_READ_ADDR;
    volatile    uint32_t    CH5_AL1_WRITE_ADDR;
    volatile    uint32_t    CH5_AL1_TRANS_COUNT_TRIG;
    volatile    uint32_t    CH5_AL2_CTRL;
    volatile    uint32_t    CH5_AL2_TRANS_COUNT;
    volatile    uint32_t    CH5_AL2_READ_ADDR;
    volatile    uint32_t    CH5_AL2_WRITE_ADDR_TRIG;
    volatile    uint32_t    CH5_AL3_CTRL;
    volatile    uint32_t    CH5_AL3_WRITE_ADDR;
    volatile    uint32_t    CH5_AL3_TRANS_COUNT;
    volatile    uint32_t    CH5_AL3_READ_ADDR_TRIG;
    volatile    uint32_t    CH6_READ_ADDR;
    volatile    uint32_t    CH6_WRITE_ADDR;
    volatile    uint32_t    CH6_TRANS_COUNT;
    volatile    uint32_t    CH6_CTRL_TRIG;
    volatile    uint32_t    CH6_AL1_CTRL;
    volatile    uint32_t    CH6_AL1_READ_ADDR;
    volatile    uint32_t    CH6_AL1_WRITE_ADDR;
    volatile    uint32_t    CH6_AL1_TRANS_COUNT_TRIG;
    volatile    uint32_t    CH6_AL2_CTRL;
    volatile    uint32_t    CH6_AL2_TRANS_COUNT;
    volatile    uint32_t    CH6_AL2_READ_ADDR;
    volatile    uint32_t    CH6_AL2_WRITE_ADDR_TRIG;
    volatile    uint32_t    CH6_AL3_CTRL;
    volatile    uint32_t    CH6_AL3_WRITE_ADDR;
    volatile    uint32_t    CH6_AL3_TRANS_COUNT;
    volatile    uint32_t    CH6_AL3_READ_ADDR_TRIG;
    volatile    uint32_t    CH7_READ_ADDR;
    volatile    uint32_t    CH7_WRITE_ADDR;
    volatile    uint32_t    CH7_TRANS_COUNT;
    volatile    uint32_t    CH7_CTRL_TRIG;
    volatile    uint32_t    CH7_AL1_CTRL;
    volatile    uint32_t    CH7_AL1_READ_ADDR;
    volatile    uint32_t    CH7_AL1_WRITE_ADDR;
    volatile    uint32_t    CH7_AL1_TRANS_COUNT_TRIG;
    volatile    uint32_t    CH7_AL2_CTRL;
    volatile    uint32_t    CH7_AL2_TRANS_COUNT;
    volatile    uint32_t    CH7_AL2_READ_ADDR;
    volatile    uint32_t    CH7_AL2_WRITE_ADDR_TRIG;
    volatile    uint32_t    CH7_AL3_CTRL;
    volatile    uint32_t    CH7_AL3_WRITE_ADDR;
    volatile    uint32_t    CH7_AL3_TRANS_COUNT;
    volatile    uint32_t    CH7_AL3_READ_ADDR_TRIG;
    volatile    uint32_t    CH8_READ_ADDR;
    volatile    uint32_t    CH8_WRITE_ADDR;
    volatile    uint32_t    CH8_TRANS_COUNT;
    volatile    uint32_t    CH8_CTRL_TRIG;
    volatile    uint32_t    CH8_AL1_CTRL;
    volatile    uint32_t    CH8_AL1_READ_ADDR;
    volatile    uint32_t    CH8_AL1_WRITE_ADDR;
    volatile    uint32_t    CH8_AL1_TRANS_COUNT_TRIG;
    volatile    uint32_t    CH8_AL2_CTRL;
    volatile    uint32_t    CH8_AL2_TRANS_COUNT;
    volatile    uint32_t    CH8_AL2_READ_ADDR;
    volatile    uint32_t    CH8_AL2_WRITE_ADDR_TRIG;
    volatile    uint32_t    CH8_AL3_CTRL;
    volatile    uint32_t    CH8_AL3_WRITE_ADDR;
    volatile    uint32_t    CH8_AL3_TRANS_COUNT;
    volatile    uint32_t    CH8_AL3_READ_ADDR_TRIG;
    volatile    uint32_t    CH9_READ_ADDR;
    volatile    uint32_t    CH9_WRITE_ADDR;
    volatile    uint32_t    CH9_TRANS_COUNT;
    volatile    uint32_t    CH9_CTRL_TRIG;
    volatile    uint32_t    CH9_AL1_CTRL;
    volatile    uint32_t    CH9_AL1_READ_ADDR;
    volatile    uint32_t    CH9_AL1_WRITE_ADDR;
    volatile    uint32_t    CH9_AL1_TRANS_COUNT_TRIG;
    volatile    uint32_t    CH9_AL2_CTRL;
    volatile    uint32_t    CH9_AL2_TRANS_COUNT;
    volatile    uint32_t    CH9_AL2_READ_ADDR;
    volatile    uint32_t    CH9_AL2_WRITE_ADDR_TRIG;
    volatile    uint32_t    CH9_AL3_CTRL;
    volatile    uint32_t    CH9_AL3_WRITE_ADDR;
    volatile    uint32_t    CH9_AL3_TRANS_COUNT;
    volatile    uint32_t    CH9_AL3_READ_ADDR_TRIG;
    volatile    uint32_t    CH10_READ_ADDR;
    volatile    uint32_t    CH10_WRITE_ADDR;
    volatile    uint32_t    CH10_TRANS_COUNT;
    volatile    uint32_t    CH10_CTRL_TRIG;
    volatile    uint32_t    CH10_AL1_CTRL;
    volatile    uint32_t    CH10_AL1_READ_ADDR;
    volatile    uint32_t    CH10_AL1_WRITE_ADDR;
    volatile    uint32_t    CH10_AL1_TRANS_COUNT_TRIG;
    volatile    uint32_t    CH10_AL2_CTRL;
    volatile    uint32_t    CH10_AL2_TRANS_COUNT;
    volatile    uint32_t    CH10_AL2_READ_ADDR;
    volatile    uint32_t    CH10_AL2_WRITE_ADDR_TRIG;
    volatile    uint32_t    CH10_AL3_CTRL;
    volatile    uint32_t    CH10_AL3_WRITE_ADDR;
    volatile    uint32_t    CH10_AL3_TRANS_COUNT;
    volatile    uint32_t    CH10_AL3_READ_ADDR_TRIG;
    volatile    uint32_t    CH11_READ_ADDR;
    volatile    uint32_t    CH11_WRITE_ADDR;
    volatile    uint32_t    CH11_TRANS_COUNT;
    volatile    uint32_t    CH11_CTRL_TRIG;
    volatile    uint32_t    CH11_AL1_CTRL;
    volatile    uint32_t    CH11_AL1_READ_ADDR;
    volatile    uint32_t    CH11_AL1_WRITE_ADDR;
    volatile    uint32_t    CH11_AL1_TRANS_COUNT_TRIG;
    volatile    uint32_t    CH11_AL2_CTRL;
    volatile    uint32_t    CH11_AL2_TRANS_COUNT;
    volatile    uint32_t    CH11_AL2_READ_ADDR;
    volatile    uint32_t    CH11_AL2_WRITE_ADDR_TRIG;
    volatile    uint32_t    CH11_AL3_CTRL;
    volatile    uint32_t    CH11_AL3_WRITE_ADDR;
    volatile    uint32_t    CH11_AL3_TRANS_COUNT;
    volatile    uint32_t    CH11_AL3_READ_ADDR_TRIG;
    volatile    uint32_t    CH12_READ_ADDR;
    volatile    uint32_t    CH12_WRITE_ADDR;
    volatile    uint32_t    CH12_TRANS_COUNT;
    volatile    uint32_t    CH12_CTRL_TRIG;
    volatile    uint32_t    CH12_AL1_CTRL;
    volatile    uint32_t    CH12_AL1_READ_ADDR;
    volatile    uint32_t    CH12_AL1_WRITE_ADDR;
    volatile    uint32_t    CH12_AL1_TRANS_COUNT_TRIG;
    volatile    uint32_t    CH12_AL2_CTRL;
    volatile    uint32_t    CH12_AL2_TRANS_COUNT;
    volatile    uint32_t    CH12_AL2_READ_ADDR;
    volatile    uint32_t    CH12_AL2_WRITE_ADDR_TRIG;
    volatile    uint32_t    CH12_AL3_CTRL;
    volatile    uint32_t    CH12_AL3_WRITE_ADDR;
    volatile    uint32_t    CH12_AL3_TRANS_COUNT;
    volatile    uint32_t    CH12_AL3_READ_ADDR_TRIG;
    volatile    uint32_t    CH13_READ_ADDR;
    volatile    uint32_t    CH13_WRITE_ADDR;
    volatile    uint32_t    CH13_TRANS_COUNT;
    volatile    uint32_t    CH13_CTRL_TRIG;
    volatile    uint32_t    CH13_AL1_CTRL;
    volatile    uint32_t    CH13_AL1_READ_ADDR;
    volatile    uint32_t    CH13_AL1_WRITE_ADDR;
    volatile    uint32_t    CH13_AL1_TRANS_COUNT_TRIG;
    volatile    uint32_t    CH13_AL2_CTRL;
    volatile    uint32_t    CH13_AL2_TRANS_COUNT;
    volatile    uint32_t    CH13_AL2_READ_ADDR;
    volatile    uint32_t    CH13_AL2_WRITE_ADDR_TRIG;
    volatile    uint32_t    CH13_AL3_CTRL;
    volatile    uint32_t    CH13_AL3_WRITE_ADDR;
    volatile    uint32_t    CH13_AL3_TRANS_COUNT;
    volatile    uint32_t    CH13_AL3_READ_ADDR_TRIG;
    volatile    uint32_t    CH14_READ_ADDR;
    volatile    uint32_t    CH14_WRITE_ADDR;
    volatile    uint32_t    CH14_TRANS_COUNT;
    volatile    uint32_t    CH14_CTRL_TRIG;
    volatile    uint32_t    CH14_AL1_CTRL;
    volatile    uint32_t    CH14_AL1_READ_ADDR;
    volatile    uint32_t    CH14_AL1_WRITE_ADDR;
    volatile    uint32_t    CH14_AL1_TRANS_COUNT_TRIG;
    volatile    uint32_t    CH14_AL2_CTRL;
    volatile    uint32_t    CH14_AL2_TRANS_COUNT;
    volatile    uint32_t    CH14_AL2_READ_ADDR;
    volatile    uint32_t    CH14_AL2_WRITE_ADDR_TRIG;
    volatile    uint32_t    CH14_AL3_CTRL;
    volatile    uint32_t    CH14_AL3_WRITE_ADDR;
    volatile    uint32_t    CH14_AL3_TRANS_COUNT;
    volatile    uint32_t    CH14_AL3_READ_ADDR_TRIG;
    volatile    uint32_t    CH15_READ_ADDR;
    volatile    uint32_t    CH15_WRITE_ADDR;
    volatile    uint32_t    CH15_TRANS_COUNT;
    volatile    uint32_t    CH15_CTRL_TRIG;
    volatile    uint32_t    CH15_AL1_CTRL;
    volatile    uint32_t    CH15_AL1_READ_ADDR;
    volatile    uint32_t    CH15_AL1_WRITE_ADDR;
    volatile    uint32_t    CH15_AL1_TRANS_COUNT_TRIG;
    volatile    uint32_t    CH15_AL2_CTRL;
    volatile    uint32_t    CH15_AL2_TRANS_COUNT;
    volatile    uint32_t    CH15_AL2_READ_ADDR;
    volatile    uint32_t    CH15_AL2_WRITE_ADDR_TRIG;
    volatile    uint32_t    CH15_AL3_CTRL;
    volatile    uint32_t    CH15_AL3_WRITE_ADDR;
    volatile    uint32_t    CH15_AL3_TRANS_COUNT;
    volatile    uint32_t    CH15_AL3_READ_ADDR_TRIG;
    volatile    uint32_t    INTR;
    volatile    uint32_t    INTE0;
    volatile    uint32_t    INTF0;
    volatile    uint32_t    INTS0;
    volatile    uint32_t    INTR1;
    volatile    uint32_t    INTE1;
    volatile    uint32_t    INTF1;
    volatile    uint32_t    INTS1;
    volatile    uint32_t    INTR2;
    volatile    uint32_t    INTE2;
    volatile    uint32_t    INTF2;
    volatile    uint32_t    INTS2;
    volatile    uint32_t    INTR3;
    volatile    uint32_t    INTE3;
    volatile    uint32_t    INTF3;
    volatile    uint32_t    INTS3;
    volatile    uint32_t    TIMER0;
    volatile    uint32_t    TIMER1;
    volatile    uint32_t    TIMER2;
    volatile    uint32_t    TIMER3;
    volatile    uint32_t    MULTI_CHAN_TRIGGER;
    volatile    uint32_t    SNIFF_CTRL;
    volatile    uint32_t    SNIFF_DATA;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    FIFO_LEVELS;
    volatile    uint32_t    CHAN_ABORT;
    volatile    uint32_t    N_CHANNELS;
    volatile    uint32_t    RESERVED1[5];
    volatile    uint32_t    SECCFG_CH0;
    volatile    uint32_t    SECCFG_CH1;
    volatile    uint32_t    SECCFG_CH2;
    volatile    uint32_t    SECCFG_CH3;
    volatile    uint32_t    SECCFG_CH4;
    volatile    uint32_t    SECCFG_CH5;
    volatile    uint32_t    SECCFG_CH6;
    volatile    uint32_t    SECCFG_CH7;
    volatile    uint32_t    SECCFG_CH8;
    volatile    uint32_t    SECCFG_CH9;
    volatile    uint32_t    SECCFG_CH10;
    volatile    uint32_t    SECCFG_CH11;
    volatile    uint32_t    SECCFG_CH12;
    volatile    uint32_t    SECCFG_CH13;
    volatile    uint32_t    SECCFG_CH14;
    volatile    uint32_t    SECCFG_CH15;
    volatile    uint32_t    SECCFG_IRQ0;
    volatile    uint32_t    SECCFG_IRQ1;
    volatile    uint32_t    SECCFG_IRQ2;
    volatile    uint32_t    SECCFG_IRQ3;
    volatile    uint32_t    SECCFG_MISC;
    volatile    uint32_t    RESERVED2[11];
    volatile    uint32_t    MPU_CTRL;
    volatile    uint32_t    MPU_BAR0;
    volatile    uint32_t    MPU_LAR0;
    volatile    uint32_t    MPU_BAR1;
    volatile    uint32_t    MPU_LAR1;
    volatile    uint32_t    MPU_BAR2;
    volatile    uint32_t    MPU_LAR2;
    volatile    uint32_t    MPU_BAR3;
    volatile    uint32_t    MPU_LAR3;
    volatile    uint32_t    MPU_BAR4;
    volatile    uint32_t    MPU_LAR4;
    volatile    uint32_t    MPU_BAR5;
    volatile    uint32_t    MPU_LAR5;
    volatile    uint32_t    MPU_BAR6;
    volatile    uint32_t    MPU_LAR6;
    volatile    uint32_t    MPU_BAR7;
    volatile    uint32_t    MPU_LAR7;
    volatile    uint32_t    RESERVED3[175];
    volatile    uint32_t    CH0_DBG_CTDREQ;
    volatile    uint32_t    CH0_DBG_TCR;
    volatile    uint32_t    RESERVED4[14];
    volatile    uint32_t    CH1_DBG_CTDREQ;
    volatile    uint32_t    CH1_DBG_TCR;
    volatile    uint32_t    RESERVED5[14];
    volatile    uint32_t    CH2_DBG_CTDREQ;
    volatile    uint32_t    CH2_DBG_TCR;
    volatile    uint32_t    RESERVED6[14];
    volatile    uint32_t    CH3_DBG_CTDREQ;
    volatile    uint32_t    CH3_DBG_TCR;
    volatile    uint32_t    RESERVED7[14];
    volatile    uint32_t    CH4_DBG_CTDREQ;
    volatile    uint32_t    CH4_DBG_TCR;
    volatile    uint32_t    RESERVED8[14];
    volatile    uint32_t    CH5_DBG_CTDREQ;
    volatile    uint32_t    CH5_DBG_TCR;
    volatile    uint32_t    RESERVED9[14];
    volatile    uint32_t    CH6_DBG_CTDREQ;
    volatile    uint32_t    CH6_DBG_TCR;
    volatile    uint32_t    RESERVED10[14];
    volatile    uint32_t    CH7_DBG_CTDREQ;
    volatile    uint32_t    CH7_DBG_TCR;
    volatile    uint32_t    RESERVED11[14];
    volatile    uint32_t    CH8_DBG_CTDREQ;
    volatile    uint32_t    CH8_DBG_TCR;
    volatile    uint32_t    RESERVED12[14];
    volatile    uint32_t    CH9_DBG_CTDREQ;
    volatile    uint32_t    CH9_DBG_TCR;
    volatile    uint32_t    RESERVED13[14];
    volatile    uint32_t    CH10_DBG_CTDREQ;
    volatile    uint32_t    CH10_DBG_TCR;
    volatile    uint32_t    RESERVED14[14];
    volatile    uint32_t    CH11_DBG_CTDREQ;
    volatile    uint32_t    CH11_DBG_TCR;
    volatile    uint32_t    RESERVED15[14];
    volatile    uint32_t    CH12_DBG_CTDREQ;
    volatile    uint32_t    CH12_DBG_TCR;
    volatile    uint32_t    RESERVED16[14];
    volatile    uint32_t    CH13_DBG_CTDREQ;
    volatile    uint32_t    CH13_DBG_TCR;
    volatile    uint32_t    RESERVED17[14];
    volatile    uint32_t    CH14_DBG_CTDREQ;
    volatile    uint32_t    CH14_DBG_TCR;
    volatile    uint32_t    RESERVED18[14];
    volatile    uint32_t    CH15_DBG_CTDREQ;
    volatile    uint32_t    CH15_DBG_TCR;
} DMA_TypeDef;

#ifdef __cplusplus
#define DMA_NS  reinterpret_cast<DMA_TypeDef *>(0x50000000U)
#define DMA_S   reinterpret_cast<DMA_TypeDef *>(0x50000000U)
#else
#define DMA_NS  ((DMA_TypeDef *)0x50000000U)
#define DMA_S   ((DMA_TypeDef *)0x50000000U)
#endif

// CH0_READ_ADDR Configuration

#define DMA_CH0_READ_ADDR_CH0_READ_ADDR                             (0xFFFFFFFFU<<0U)
#define DMA_CH0_READ_ADDR_CH0_READ_ADDR_0                           (0x1U<<0U)

// CH0_WRITE_ADDR Configuration

#define DMA_CH0_WRITE_ADDR_CH0_WRITE_ADDR                           (0xFFFFFFFFU<<0U)
#define DMA_CH0_WRITE_ADDR_CH0_WRITE_ADDR_0                         (0x1U<<0U)

// CH0_TRANS_COUNT Configuration

#define DMA_CH0_TRANS_COUNT_COUNT                                   (0xFFFFFFFU<<0U)
#define DMA_CH0_TRANS_COUNT_COUNT_0                                 (0x1U<<0U)
#define DMA_CH0_TRANS_COUNT_MODE                                    (0xFU<<28U)
#define DMA_CH0_TRANS_COUNT_MODE_0                                  (0x1U<<28U)
#define DMA_CH0_TRANS_COUNT_MODE_NORMAL                             (0x0U<<28U)
#define DMA_CH0_TRANS_COUNT_MODE_TRIGGER_SELF                       (0x1U<<28U)
#define DMA_CH0_TRANS_COUNT_MODE_ENDLESS                            (0xFU<<28U)

// CH0_CTRL_TRIG Configuration

#define DMA_CH0_CTRL_TRIG_EN                                        (0x1U<<0U)
#define DMA_CH0_CTRL_TRIG_HIGH_PRIORITY                             (0x1U<<1U)
#define DMA_CH0_CTRL_TRIG_DATA_SIZE                                 (0x3U<<2U)
#define DMA_CH0_CTRL_TRIG_DATA_SIZE_0                               (0x1U<<2U)
#define DMA_CH0_CTRL_TRIG_INCR_READ                                 (0x1U<<4U)
#define DMA_CH0_CTRL_TRIG_INCR_READ_REV                             (0x1U<<5U)
#define DMA_CH0_CTRL_TRIG_INCR_WRITE                                (0x1U<<6U)
#define DMA_CH0_CTRL_TRIG_INCR_WRITE_REV                            (0x1U<<7U)
#define DMA_CH0_CTRL_TRIG_RING_SIZE                                 (0xFU<<8U)
#define DMA_CH0_CTRL_TRIG_RING_SIZE_0                               (0x1U<<8U)
#define DMA_CH0_CTRL_TRIG_RING_SEL                                  (0x1U<<12U)
#define DMA_CH0_CTRL_TRIG_CHAIN_TO                                  (0xFU<<13U)
#define DMA_CH0_CTRL_TRIG_CHAIN_TO_0                                (0x1U<<13U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL                                  (0x3FU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_0                                (0x1U<<17U)
#define DMA_CH0_CTRL_TRIG_IRQ_QUIET                                 (0x1U<<23U)
#define DMA_CH0_CTRL_TRIG_BSWAP                                     (0x1U<<24U)
#define DMA_CH0_CTRL_TRIG_SNIFF_EN                                  (0x1U<<25U)
#define DMA_CH0_CTRL_TRIG_BUSY                                      (0x1U<<26U)
#define DMA_CH0_CTRL_TRIG_WRITE_ERROR                               (0x1U<<29U)
#define DMA_CH0_CTRL_TRIG_READ_ERROR                                (0x1U<<30U)
#define DMA_CH0_CTRL_TRIG_AHB_ERROR                                 (0x1U<<31U)
#define DMA_CH0_CTRL_TRIG_DATA_SIZE_SIZE_BYTE                       (0x0U<<2U)
#define DMA_CH0_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD                   (0x1U<<2U)
#define DMA_CH0_CTRL_TRIG_DATA_SIZE_SIZE_WORD                       (0x2U<<2U)
#define DMA_CH0_CTRL_TRIG_RING_SIZE_RING_NONE                       (0x0U<<8U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO0_TX0                         (0x0U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO0_TX1                         (0x1U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO0_TX2                         (0x2U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO0_TX3                         (0x3U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO0_RX0                         (0x4U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO0_RX1                         (0x5U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO0_RX2                         (0x6U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO0_RX3                         (0x7U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO1_TX0                         (0x8U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO1_TX1                         (0x9U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO1_TX2                         (0xAU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO1_TX3                         (0xBU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO1_RX0                         (0xCU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO1_RX1                         (0xDU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO1_RX2                         (0xEU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO1_RX3                         (0xFU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO2_TX0                         (0x10U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO2_TX1                         (0x11U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO2_TX2                         (0x12U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO2_TX3                         (0x13U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO2_RX0                         (0x14U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO2_RX1                         (0x15U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO2_RX2                         (0x16U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PIO2_RX3                         (0x17U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_SPI0_TX                          (0x18U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_SPI0_RX                          (0x19U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_SPI1_TX                          (0x1AU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_SPI1_RX                          (0x1BU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_UART0_TX                         (0x1CU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_UART0_RX                         (0x1DU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_UART1_TX                         (0x1EU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_UART1_RX                         (0x1FU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PWM_WRAP0                        (0x20U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PWM_WRAP1                        (0x21U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PWM_WRAP2                        (0x22U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PWM_WRAP3                        (0x23U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PWM_WRAP4                        (0x24U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PWM_WRAP5                        (0x25U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PWM_WRAP6                        (0x26U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PWM_WRAP7                        (0x27U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PWM_WRAP8                        (0x28U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PWM_WRAP9                        (0x29U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PWM_WRAP10                       (0x2AU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PWM_WRAP11                       (0x2BU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_I2C0_TX                          (0x2CU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_I2C0_RX                          (0x2DU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_I2C1_TX                          (0x2EU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_I2C1_RX                          (0x2FU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_ADC                              (0x30U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_XIP_STREAM                       (0x31U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_XIP_QMITX                        (0x32U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_XIP_QMIRX                        (0x33U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_HSTX                             (0x34U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_CORESIGHT                        (0x35U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_SHA256                           (0x36U<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_TIMER0                           (0x3BU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_TIMER1                           (0x3CU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_TIMER2                           (0x3DU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_TIMER3                           (0x3EU<<17U)
#define DMA_CH0_CTRL_TRIG_TREQ_SEL_PERMANENT                        (0x3FU<<17U)

// CH0_AL1_CTRL Configuration

#define DMA_CH0_AL1_CTRL_CH0_AL1_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH0_AL1_CTRL_CH0_AL1_CTRL_0                             (0x1U<<0U)

// CH0_AL1_READ_ADDR Configuration

#define DMA_CH0_AL1_READ_ADDR_CH0_AL1_READ_ADDR                     (0xFFFFFFFFU<<0U)
#define DMA_CH0_AL1_READ_ADDR_CH0_AL1_READ_ADDR_0                   (0x1U<<0U)

// CH0_AL1_WRITE_ADDR Configuration

#define DMA_CH0_AL1_WRITE_ADDR_CH0_AL1_WRITE_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH0_AL1_WRITE_ADDR_CH0_AL1_WRITE_ADDR_0                 (0x1U<<0U)

// CH0_AL1_TRANS_COUNT_TRIG Configuration

#define DMA_CH0_AL1_TRANS_COUNT_TRIG_CH0_AL1_TRANS_COUNT_TRIG       (0xFFFFFFFFU<<0U)
#define DMA_CH0_AL1_TRANS_COUNT_TRIG_CH0_AL1_TRANS_COUNT_TRIG_0     (0x1U<<0U)

// CH0_AL2_CTRL Configuration

#define DMA_CH0_AL2_CTRL_CH0_AL2_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH0_AL2_CTRL_CH0_AL2_CTRL_0                             (0x1U<<0U)

// CH0_AL2_TRANS_COUNT Configuration

#define DMA_CH0_AL2_TRANS_COUNT_CH0_AL2_TRANS_COUNT                 (0xFFFFFFFFU<<0U)
#define DMA_CH0_AL2_TRANS_COUNT_CH0_AL2_TRANS_COUNT_0               (0x1U<<0U)

// CH0_AL2_READ_ADDR Configuration

#define DMA_CH0_AL2_READ_ADDR_CH0_AL2_READ_ADDR                     (0xFFFFFFFFU<<0U)
#define DMA_CH0_AL2_READ_ADDR_CH0_AL2_READ_ADDR_0                   (0x1U<<0U)

// CH0_AL2_WRITE_ADDR_TRIG Configuration

#define DMA_CH0_AL2_WRITE_ADDR_TRIG_CH0_AL2_WRITE_ADDR_TRIG         (0xFFFFFFFFU<<0U)
#define DMA_CH0_AL2_WRITE_ADDR_TRIG_CH0_AL2_WRITE_ADDR_TRIG_0       (0x1U<<0U)

// CH0_AL3_CTRL Configuration

#define DMA_CH0_AL3_CTRL_CH0_AL3_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH0_AL3_CTRL_CH0_AL3_CTRL_0                             (0x1U<<0U)

// CH0_AL3_WRITE_ADDR Configuration

#define DMA_CH0_AL3_WRITE_ADDR_CH0_AL3_WRITE_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH0_AL3_WRITE_ADDR_CH0_AL3_WRITE_ADDR_0                 (0x1U<<0U)

// CH0_AL3_TRANS_COUNT Configuration

#define DMA_CH0_AL3_TRANS_COUNT_CH0_AL3_TRANS_COUNT                 (0xFFFFFFFFU<<0U)
#define DMA_CH0_AL3_TRANS_COUNT_CH0_AL3_TRANS_COUNT_0               (0x1U<<0U)

// CH0_AL3_READ_ADDR_TRIG Configuration

#define DMA_CH0_AL3_READ_ADDR_TRIG_CH0_AL3_READ_ADDR_TRIG           (0xFFFFFFFFU<<0U)
#define DMA_CH0_AL3_READ_ADDR_TRIG_CH0_AL3_READ_ADDR_TRIG_0         (0x1U<<0U)

// CH1_READ_ADDR Configuration

#define DMA_CH1_READ_ADDR_CH1_READ_ADDR                             (0xFFFFFFFFU<<0U)
#define DMA_CH1_READ_ADDR_CH1_READ_ADDR_0                           (0x1U<<0U)

// CH1_WRITE_ADDR Configuration

#define DMA_CH1_WRITE_ADDR_CH1_WRITE_ADDR                           (0xFFFFFFFFU<<0U)
#define DMA_CH1_WRITE_ADDR_CH1_WRITE_ADDR_0                         (0x1U<<0U)

// CH1_TRANS_COUNT Configuration

#define DMA_CH1_TRANS_COUNT_COUNT                                   (0xFFFFFFFU<<0U)
#define DMA_CH1_TRANS_COUNT_COUNT_0                                 (0x1U<<0U)
#define DMA_CH1_TRANS_COUNT_MODE                                    (0xFU<<28U)
#define DMA_CH1_TRANS_COUNT_MODE_0                                  (0x1U<<28U)
#define DMA_CH1_TRANS_COUNT_MODE_NORMAL                             (0x0U<<28U)
#define DMA_CH1_TRANS_COUNT_MODE_TRIGGER_SELF                       (0x1U<<28U)
#define DMA_CH1_TRANS_COUNT_MODE_ENDLESS                            (0xFU<<28U)

// CH1_CTRL_TRIG Configuration

#define DMA_CH1_CTRL_TRIG_EN                                        (0x1U<<0U)
#define DMA_CH1_CTRL_TRIG_HIGH_PRIORITY                             (0x1U<<1U)
#define DMA_CH1_CTRL_TRIG_DATA_SIZE                                 (0x3U<<2U)
#define DMA_CH1_CTRL_TRIG_DATA_SIZE_0                               (0x1U<<2U)
#define DMA_CH1_CTRL_TRIG_INCR_READ                                 (0x1U<<4U)
#define DMA_CH1_CTRL_TRIG_INCR_READ_REV                             (0x1U<<5U)
#define DMA_CH1_CTRL_TRIG_INCR_WRITE                                (0x1U<<6U)
#define DMA_CH1_CTRL_TRIG_INCR_WRITE_REV                            (0x1U<<7U)
#define DMA_CH1_CTRL_TRIG_RING_SIZE                                 (0xFU<<8U)
#define DMA_CH1_CTRL_TRIG_RING_SIZE_0                               (0x1U<<8U)
#define DMA_CH1_CTRL_TRIG_RING_SEL                                  (0x1U<<12U)
#define DMA_CH1_CTRL_TRIG_CHAIN_TO                                  (0xFU<<13U)
#define DMA_CH1_CTRL_TRIG_CHAIN_TO_0                                (0x1U<<13U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL                                  (0x3FU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_0                                (0x1U<<17U)
#define DMA_CH1_CTRL_TRIG_IRQ_QUIET                                 (0x1U<<23U)
#define DMA_CH1_CTRL_TRIG_BSWAP                                     (0x1U<<24U)
#define DMA_CH1_CTRL_TRIG_SNIFF_EN                                  (0x1U<<25U)
#define DMA_CH1_CTRL_TRIG_BUSY                                      (0x1U<<26U)
#define DMA_CH1_CTRL_TRIG_WRITE_ERROR                               (0x1U<<29U)
#define DMA_CH1_CTRL_TRIG_READ_ERROR                                (0x1U<<30U)
#define DMA_CH1_CTRL_TRIG_AHB_ERROR                                 (0x1U<<31U)
#define DMA_CH1_CTRL_TRIG_DATA_SIZE_SIZE_BYTE                       (0x0U<<2U)
#define DMA_CH1_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD                   (0x1U<<2U)
#define DMA_CH1_CTRL_TRIG_DATA_SIZE_SIZE_WORD                       (0x2U<<2U)
#define DMA_CH1_CTRL_TRIG_RING_SIZE_RING_NONE                       (0x0U<<8U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO0_TX0                         (0x0U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO0_TX1                         (0x1U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO0_TX2                         (0x2U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO0_TX3                         (0x3U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO0_RX0                         (0x4U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO0_RX1                         (0x5U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO0_RX2                         (0x6U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO0_RX3                         (0x7U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO1_TX0                         (0x8U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO1_TX1                         (0x9U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO1_TX2                         (0xAU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO1_TX3                         (0xBU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO1_RX0                         (0xCU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO1_RX1                         (0xDU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO1_RX2                         (0xEU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO1_RX3                         (0xFU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO2_TX0                         (0x10U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO2_TX1                         (0x11U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO2_TX2                         (0x12U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO2_TX3                         (0x13U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO2_RX0                         (0x14U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO2_RX1                         (0x15U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO2_RX2                         (0x16U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PIO2_RX3                         (0x17U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_SPI0_TX                          (0x18U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_SPI0_RX                          (0x19U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_SPI1_TX                          (0x1AU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_SPI1_RX                          (0x1BU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_UART0_TX                         (0x1CU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_UART0_RX                         (0x1DU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_UART1_TX                         (0x1EU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_UART1_RX                         (0x1FU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PWM_WRAP0                        (0x20U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PWM_WRAP1                        (0x21U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PWM_WRAP2                        (0x22U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PWM_WRAP3                        (0x23U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PWM_WRAP4                        (0x24U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PWM_WRAP5                        (0x25U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PWM_WRAP6                        (0x26U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PWM_WRAP7                        (0x27U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PWM_WRAP8                        (0x28U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PWM_WRAP9                        (0x29U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PWM_WRAP10                       (0x2AU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PWM_WRAP11                       (0x2BU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_I2C0_TX                          (0x2CU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_I2C0_RX                          (0x2DU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_I2C1_TX                          (0x2EU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_I2C1_RX                          (0x2FU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_ADC                              (0x30U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_XIP_STREAM                       (0x31U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_XIP_QMITX                        (0x32U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_XIP_QMIRX                        (0x33U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_HSTX                             (0x34U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_CORESIGHT                        (0x35U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_SHA256                           (0x36U<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_TIMER0                           (0x3BU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_TIMER1                           (0x3CU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_TIMER2                           (0x3DU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_TIMER3                           (0x3EU<<17U)
#define DMA_CH1_CTRL_TRIG_TREQ_SEL_PERMANENT                        (0x3FU<<17U)

// CH1_AL1_CTRL Configuration

#define DMA_CH1_AL1_CTRL_CH1_AL1_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH1_AL1_CTRL_CH1_AL1_CTRL_0                             (0x1U<<0U)

// CH1_AL1_READ_ADDR Configuration

#define DMA_CH1_AL1_READ_ADDR_CH1_AL1_READ_ADDR                     (0xFFFFFFFFU<<0U)
#define DMA_CH1_AL1_READ_ADDR_CH1_AL1_READ_ADDR_0                   (0x1U<<0U)

// CH1_AL1_WRITE_ADDR Configuration

#define DMA_CH1_AL1_WRITE_ADDR_CH1_AL1_WRITE_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH1_AL1_WRITE_ADDR_CH1_AL1_WRITE_ADDR_0                 (0x1U<<0U)

// CH1_AL1_TRANS_COUNT_TRIG Configuration

#define DMA_CH1_AL1_TRANS_COUNT_TRIG_CH1_AL1_TRANS_COUNT_TRIG       (0xFFFFFFFFU<<0U)
#define DMA_CH1_AL1_TRANS_COUNT_TRIG_CH1_AL1_TRANS_COUNT_TRIG_0     (0x1U<<0U)

// CH1_AL2_CTRL Configuration

#define DMA_CH1_AL2_CTRL_CH1_AL2_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH1_AL2_CTRL_CH1_AL2_CTRL_0                             (0x1U<<0U)

// CH1_AL2_TRANS_COUNT Configuration

#define DMA_CH1_AL2_TRANS_COUNT_CH1_AL2_TRANS_COUNT                 (0xFFFFFFFFU<<0U)
#define DMA_CH1_AL2_TRANS_COUNT_CH1_AL2_TRANS_COUNT_0               (0x1U<<0U)

// CH1_AL2_READ_ADDR Configuration

#define DMA_CH1_AL2_READ_ADDR_CH1_AL2_READ_ADDR                     (0xFFFFFFFFU<<0U)
#define DMA_CH1_AL2_READ_ADDR_CH1_AL2_READ_ADDR_0                   (0x1U<<0U)

// CH1_AL2_WRITE_ADDR_TRIG Configuration

#define DMA_CH1_AL2_WRITE_ADDR_TRIG_CH1_AL2_WRITE_ADDR_TRIG         (0xFFFFFFFFU<<0U)
#define DMA_CH1_AL2_WRITE_ADDR_TRIG_CH1_AL2_WRITE_ADDR_TRIG_0       (0x1U<<0U)

// CH1_AL3_CTRL Configuration

#define DMA_CH1_AL3_CTRL_CH1_AL3_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH1_AL3_CTRL_CH1_AL3_CTRL_0                             (0x1U<<0U)

// CH1_AL3_WRITE_ADDR Configuration

#define DMA_CH1_AL3_WRITE_ADDR_CH1_AL3_WRITE_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH1_AL3_WRITE_ADDR_CH1_AL3_WRITE_ADDR_0                 (0x1U<<0U)

// CH1_AL3_TRANS_COUNT Configuration

#define DMA_CH1_AL3_TRANS_COUNT_CH1_AL3_TRANS_COUNT                 (0xFFFFFFFFU<<0U)
#define DMA_CH1_AL3_TRANS_COUNT_CH1_AL3_TRANS_COUNT_0               (0x1U<<0U)

// CH1_AL3_READ_ADDR_TRIG Configuration

#define DMA_CH1_AL3_READ_ADDR_TRIG_CH1_AL3_READ_ADDR_TRIG           (0xFFFFFFFFU<<0U)
#define DMA_CH1_AL3_READ_ADDR_TRIG_CH1_AL3_READ_ADDR_TRIG_0         (0x1U<<0U)

// CH2_READ_ADDR Configuration

#define DMA_CH2_READ_ADDR_CH2_READ_ADDR                             (0xFFFFFFFFU<<0U)
#define DMA_CH2_READ_ADDR_CH2_READ_ADDR_0                           (0x1U<<0U)

// CH2_WRITE_ADDR Configuration

#define DMA_CH2_WRITE_ADDR_CH2_WRITE_ADDR                           (0xFFFFFFFFU<<0U)
#define DMA_CH2_WRITE_ADDR_CH2_WRITE_ADDR_0                         (0x1U<<0U)

// CH2_TRANS_COUNT Configuration

#define DMA_CH2_TRANS_COUNT_COUNT                                   (0xFFFFFFFU<<0U)
#define DMA_CH2_TRANS_COUNT_COUNT_0                                 (0x1U<<0U)
#define DMA_CH2_TRANS_COUNT_MODE                                    (0xFU<<28U)
#define DMA_CH2_TRANS_COUNT_MODE_0                                  (0x1U<<28U)
#define DMA_CH2_TRANS_COUNT_MODE_NORMAL                             (0x0U<<28U)
#define DMA_CH2_TRANS_COUNT_MODE_TRIGGER_SELF                       (0x1U<<28U)
#define DMA_CH2_TRANS_COUNT_MODE_ENDLESS                            (0xFU<<28U)

// CH2_CTRL_TRIG Configuration

#define DMA_CH2_CTRL_TRIG_EN                                        (0x1U<<0U)
#define DMA_CH2_CTRL_TRIG_HIGH_PRIORITY                             (0x1U<<1U)
#define DMA_CH2_CTRL_TRIG_DATA_SIZE                                 (0x3U<<2U)
#define DMA_CH2_CTRL_TRIG_DATA_SIZE_0                               (0x1U<<2U)
#define DMA_CH2_CTRL_TRIG_INCR_READ                                 (0x1U<<4U)
#define DMA_CH2_CTRL_TRIG_INCR_READ_REV                             (0x1U<<5U)
#define DMA_CH2_CTRL_TRIG_INCR_WRITE                                (0x1U<<6U)
#define DMA_CH2_CTRL_TRIG_INCR_WRITE_REV                            (0x1U<<7U)
#define DMA_CH2_CTRL_TRIG_RING_SIZE                                 (0xFU<<8U)
#define DMA_CH2_CTRL_TRIG_RING_SIZE_0                               (0x1U<<8U)
#define DMA_CH2_CTRL_TRIG_RING_SEL                                  (0x1U<<12U)
#define DMA_CH2_CTRL_TRIG_CHAIN_TO                                  (0xFU<<13U)
#define DMA_CH2_CTRL_TRIG_CHAIN_TO_0                                (0x1U<<13U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL                                  (0x3FU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_0                                (0x1U<<17U)
#define DMA_CH2_CTRL_TRIG_IRQ_QUIET                                 (0x1U<<23U)
#define DMA_CH2_CTRL_TRIG_BSWAP                                     (0x1U<<24U)
#define DMA_CH2_CTRL_TRIG_SNIFF_EN                                  (0x1U<<25U)
#define DMA_CH2_CTRL_TRIG_BUSY                                      (0x1U<<26U)
#define DMA_CH2_CTRL_TRIG_WRITE_ERROR                               (0x1U<<29U)
#define DMA_CH2_CTRL_TRIG_READ_ERROR                                (0x1U<<30U)
#define DMA_CH2_CTRL_TRIG_AHB_ERROR                                 (0x1U<<31U)
#define DMA_CH2_CTRL_TRIG_DATA_SIZE_SIZE_BYTE                       (0x0U<<2U)
#define DMA_CH2_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD                   (0x1U<<2U)
#define DMA_CH2_CTRL_TRIG_DATA_SIZE_SIZE_WORD                       (0x2U<<2U)
#define DMA_CH2_CTRL_TRIG_RING_SIZE_RING_NONE                       (0x0U<<8U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO0_TX0                         (0x0U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO0_TX1                         (0x1U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO0_TX2                         (0x2U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO0_TX3                         (0x3U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO0_RX0                         (0x4U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO0_RX1                         (0x5U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO0_RX2                         (0x6U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO0_RX3                         (0x7U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO1_TX0                         (0x8U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO1_TX1                         (0x9U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO1_TX2                         (0xAU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO1_TX3                         (0xBU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO1_RX0                         (0xCU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO1_RX1                         (0xDU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO1_RX2                         (0xEU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO1_RX3                         (0xFU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO2_TX0                         (0x10U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO2_TX1                         (0x11U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO2_TX2                         (0x12U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO2_TX3                         (0x13U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO2_RX0                         (0x14U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO2_RX1                         (0x15U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO2_RX2                         (0x16U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PIO2_RX3                         (0x17U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_SPI0_TX                          (0x18U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_SPI0_RX                          (0x19U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_SPI1_TX                          (0x1AU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_SPI1_RX                          (0x1BU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_UART0_TX                         (0x1CU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_UART0_RX                         (0x1DU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_UART1_TX                         (0x1EU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_UART1_RX                         (0x1FU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PWM_WRAP0                        (0x20U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PWM_WRAP1                        (0x21U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PWM_WRAP2                        (0x22U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PWM_WRAP3                        (0x23U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PWM_WRAP4                        (0x24U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PWM_WRAP5                        (0x25U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PWM_WRAP6                        (0x26U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PWM_WRAP7                        (0x27U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PWM_WRAP8                        (0x28U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PWM_WRAP9                        (0x29U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PWM_WRAP10                       (0x2AU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PWM_WRAP11                       (0x2BU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_I2C0_TX                          (0x2CU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_I2C0_RX                          (0x2DU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_I2C1_TX                          (0x2EU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_I2C1_RX                          (0x2FU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_ADC                              (0x30U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_XIP_STREAM                       (0x31U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_XIP_QMITX                        (0x32U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_XIP_QMIRX                        (0x33U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_HSTX                             (0x34U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_CORESIGHT                        (0x35U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_SHA256                           (0x36U<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_TIMER0                           (0x3BU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_TIMER1                           (0x3CU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_TIMER2                           (0x3DU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_TIMER3                           (0x3EU<<17U)
#define DMA_CH2_CTRL_TRIG_TREQ_SEL_PERMANENT                        (0x3FU<<17U)

// CH2_AL1_CTRL Configuration

#define DMA_CH2_AL1_CTRL_CH2_AL1_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH2_AL1_CTRL_CH2_AL1_CTRL_0                             (0x1U<<0U)

// CH2_AL1_READ_ADDR Configuration

#define DMA_CH2_AL1_READ_ADDR_CH2_AL1_READ_ADDR                     (0xFFFFFFFFU<<0U)
#define DMA_CH2_AL1_READ_ADDR_CH2_AL1_READ_ADDR_0                   (0x1U<<0U)

// CH2_AL1_WRITE_ADDR Configuration

#define DMA_CH2_AL1_WRITE_ADDR_CH2_AL1_WRITE_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH2_AL1_WRITE_ADDR_CH2_AL1_WRITE_ADDR_0                 (0x1U<<0U)

// CH2_AL1_TRANS_COUNT_TRIG Configuration

#define DMA_CH2_AL1_TRANS_COUNT_TRIG_CH2_AL1_TRANS_COUNT_TRIG       (0xFFFFFFFFU<<0U)
#define DMA_CH2_AL1_TRANS_COUNT_TRIG_CH2_AL1_TRANS_COUNT_TRIG_0     (0x1U<<0U)

// CH2_AL2_CTRL Configuration

#define DMA_CH2_AL2_CTRL_CH2_AL2_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH2_AL2_CTRL_CH2_AL2_CTRL_0                             (0x1U<<0U)

// CH2_AL2_TRANS_COUNT Configuration

#define DMA_CH2_AL2_TRANS_COUNT_CH2_AL2_TRANS_COUNT                 (0xFFFFFFFFU<<0U)
#define DMA_CH2_AL2_TRANS_COUNT_CH2_AL2_TRANS_COUNT_0               (0x1U<<0U)

// CH2_AL2_READ_ADDR Configuration

#define DMA_CH2_AL2_READ_ADDR_CH2_AL2_READ_ADDR                     (0xFFFFFFFFU<<0U)
#define DMA_CH2_AL2_READ_ADDR_CH2_AL2_READ_ADDR_0                   (0x1U<<0U)

// CH2_AL2_WRITE_ADDR_TRIG Configuration

#define DMA_CH2_AL2_WRITE_ADDR_TRIG_CH2_AL2_WRITE_ADDR_TRIG         (0xFFFFFFFFU<<0U)
#define DMA_CH2_AL2_WRITE_ADDR_TRIG_CH2_AL2_WRITE_ADDR_TRIG_0       (0x1U<<0U)

// CH2_AL3_CTRL Configuration

#define DMA_CH2_AL3_CTRL_CH2_AL3_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH2_AL3_CTRL_CH2_AL3_CTRL_0                             (0x1U<<0U)

// CH2_AL3_WRITE_ADDR Configuration

#define DMA_CH2_AL3_WRITE_ADDR_CH2_AL3_WRITE_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH2_AL3_WRITE_ADDR_CH2_AL3_WRITE_ADDR_0                 (0x1U<<0U)

// CH2_AL3_TRANS_COUNT Configuration

#define DMA_CH2_AL3_TRANS_COUNT_CH2_AL3_TRANS_COUNT                 (0xFFFFFFFFU<<0U)
#define DMA_CH2_AL3_TRANS_COUNT_CH2_AL3_TRANS_COUNT_0               (0x1U<<0U)

// CH2_AL3_READ_ADDR_TRIG Configuration

#define DMA_CH2_AL3_READ_ADDR_TRIG_CH2_AL3_READ_ADDR_TRIG           (0xFFFFFFFFU<<0U)
#define DMA_CH2_AL3_READ_ADDR_TRIG_CH2_AL3_READ_ADDR_TRIG_0         (0x1U<<0U)

// CH3_READ_ADDR Configuration

#define DMA_CH3_READ_ADDR_CH3_READ_ADDR                             (0xFFFFFFFFU<<0U)
#define DMA_CH3_READ_ADDR_CH3_READ_ADDR_0                           (0x1U<<0U)

// CH3_WRITE_ADDR Configuration

#define DMA_CH3_WRITE_ADDR_CH3_WRITE_ADDR                           (0xFFFFFFFFU<<0U)
#define DMA_CH3_WRITE_ADDR_CH3_WRITE_ADDR_0                         (0x1U<<0U)

// CH3_TRANS_COUNT Configuration

#define DMA_CH3_TRANS_COUNT_COUNT                                   (0xFFFFFFFU<<0U)
#define DMA_CH3_TRANS_COUNT_COUNT_0                                 (0x1U<<0U)
#define DMA_CH3_TRANS_COUNT_MODE                                    (0xFU<<28U)
#define DMA_CH3_TRANS_COUNT_MODE_0                                  (0x1U<<28U)
#define DMA_CH3_TRANS_COUNT_MODE_NORMAL                             (0x0U<<28U)
#define DMA_CH3_TRANS_COUNT_MODE_TRIGGER_SELF                       (0x1U<<28U)
#define DMA_CH3_TRANS_COUNT_MODE_ENDLESS                            (0xFU<<28U)

// CH3_CTRL_TRIG Configuration

#define DMA_CH3_CTRL_TRIG_EN                                        (0x1U<<0U)
#define DMA_CH3_CTRL_TRIG_HIGH_PRIORITY                             (0x1U<<1U)
#define DMA_CH3_CTRL_TRIG_DATA_SIZE                                 (0x3U<<2U)
#define DMA_CH3_CTRL_TRIG_DATA_SIZE_0                               (0x1U<<2U)
#define DMA_CH3_CTRL_TRIG_INCR_READ                                 (0x1U<<4U)
#define DMA_CH3_CTRL_TRIG_INCR_READ_REV                             (0x1U<<5U)
#define DMA_CH3_CTRL_TRIG_INCR_WRITE                                (0x1U<<6U)
#define DMA_CH3_CTRL_TRIG_INCR_WRITE_REV                            (0x1U<<7U)
#define DMA_CH3_CTRL_TRIG_RING_SIZE                                 (0xFU<<8U)
#define DMA_CH3_CTRL_TRIG_RING_SIZE_0                               (0x1U<<8U)
#define DMA_CH3_CTRL_TRIG_RING_SEL                                  (0x1U<<12U)
#define DMA_CH3_CTRL_TRIG_CHAIN_TO                                  (0xFU<<13U)
#define DMA_CH3_CTRL_TRIG_CHAIN_TO_0                                (0x1U<<13U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL                                  (0x3FU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_0                                (0x1U<<17U)
#define DMA_CH3_CTRL_TRIG_IRQ_QUIET                                 (0x1U<<23U)
#define DMA_CH3_CTRL_TRIG_BSWAP                                     (0x1U<<24U)
#define DMA_CH3_CTRL_TRIG_SNIFF_EN                                  (0x1U<<25U)
#define DMA_CH3_CTRL_TRIG_BUSY                                      (0x1U<<26U)
#define DMA_CH3_CTRL_TRIG_WRITE_ERROR                               (0x1U<<29U)
#define DMA_CH3_CTRL_TRIG_READ_ERROR                                (0x1U<<30U)
#define DMA_CH3_CTRL_TRIG_AHB_ERROR                                 (0x1U<<31U)
#define DMA_CH3_CTRL_TRIG_DATA_SIZE_SIZE_BYTE                       (0x0U<<2U)
#define DMA_CH3_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD                   (0x1U<<2U)
#define DMA_CH3_CTRL_TRIG_DATA_SIZE_SIZE_WORD                       (0x2U<<2U)
#define DMA_CH3_CTRL_TRIG_RING_SIZE_RING_NONE                       (0x0U<<8U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO0_TX0                         (0x0U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO0_TX1                         (0x1U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO0_TX2                         (0x2U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO0_TX3                         (0x3U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO0_RX0                         (0x4U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO0_RX1                         (0x5U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO0_RX2                         (0x6U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO0_RX3                         (0x7U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO1_TX0                         (0x8U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO1_TX1                         (0x9U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO1_TX2                         (0xAU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO1_TX3                         (0xBU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO1_RX0                         (0xCU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO1_RX1                         (0xDU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO1_RX2                         (0xEU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO1_RX3                         (0xFU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO2_TX0                         (0x10U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO2_TX1                         (0x11U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO2_TX2                         (0x12U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO2_TX3                         (0x13U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO2_RX0                         (0x14U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO2_RX1                         (0x15U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO2_RX2                         (0x16U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PIO2_RX3                         (0x17U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_SPI0_TX                          (0x18U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_SPI0_RX                          (0x19U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_SPI1_TX                          (0x1AU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_SPI1_RX                          (0x1BU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_UART0_TX                         (0x1CU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_UART0_RX                         (0x1DU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_UART1_TX                         (0x1EU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_UART1_RX                         (0x1FU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PWM_WRAP0                        (0x20U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PWM_WRAP1                        (0x21U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PWM_WRAP2                        (0x22U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PWM_WRAP3                        (0x23U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PWM_WRAP4                        (0x24U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PWM_WRAP5                        (0x25U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PWM_WRAP6                        (0x26U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PWM_WRAP7                        (0x27U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PWM_WRAP8                        (0x28U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PWM_WRAP9                        (0x29U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PWM_WRAP10                       (0x2AU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PWM_WRAP11                       (0x2BU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_I2C0_TX                          (0x2CU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_I2C0_RX                          (0x2DU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_I2C1_TX                          (0x2EU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_I2C1_RX                          (0x2FU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_ADC                              (0x30U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_XIP_STREAM                       (0x31U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_XIP_QMITX                        (0x32U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_XIP_QMIRX                        (0x33U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_HSTX                             (0x34U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_CORESIGHT                        (0x35U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_SHA256                           (0x36U<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_TIMER0                           (0x3BU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_TIMER1                           (0x3CU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_TIMER2                           (0x3DU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_TIMER3                           (0x3EU<<17U)
#define DMA_CH3_CTRL_TRIG_TREQ_SEL_PERMANENT                        (0x3FU<<17U)

// CH3_AL1_CTRL Configuration

#define DMA_CH3_AL1_CTRL_CH3_AL1_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH3_AL1_CTRL_CH3_AL1_CTRL_0                             (0x1U<<0U)

// CH3_AL1_READ_ADDR Configuration

#define DMA_CH3_AL1_READ_ADDR_CH3_AL1_READ_ADDR                     (0xFFFFFFFFU<<0U)
#define DMA_CH3_AL1_READ_ADDR_CH3_AL1_READ_ADDR_0                   (0x1U<<0U)

// CH3_AL1_WRITE_ADDR Configuration

#define DMA_CH3_AL1_WRITE_ADDR_CH3_AL1_WRITE_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH3_AL1_WRITE_ADDR_CH3_AL1_WRITE_ADDR_0                 (0x1U<<0U)

// CH3_AL1_TRANS_COUNT_TRIG Configuration

#define DMA_CH3_AL1_TRANS_COUNT_TRIG_CH3_AL1_TRANS_COUNT_TRIG       (0xFFFFFFFFU<<0U)
#define DMA_CH3_AL1_TRANS_COUNT_TRIG_CH3_AL1_TRANS_COUNT_TRIG_0     (0x1U<<0U)

// CH3_AL2_CTRL Configuration

#define DMA_CH3_AL2_CTRL_CH3_AL2_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH3_AL2_CTRL_CH3_AL2_CTRL_0                             (0x1U<<0U)

// CH3_AL2_TRANS_COUNT Configuration

#define DMA_CH3_AL2_TRANS_COUNT_CH3_AL2_TRANS_COUNT                 (0xFFFFFFFFU<<0U)
#define DMA_CH3_AL2_TRANS_COUNT_CH3_AL2_TRANS_COUNT_0               (0x1U<<0U)

// CH3_AL2_READ_ADDR Configuration

#define DMA_CH3_AL2_READ_ADDR_CH3_AL2_READ_ADDR                     (0xFFFFFFFFU<<0U)
#define DMA_CH3_AL2_READ_ADDR_CH3_AL2_READ_ADDR_0                   (0x1U<<0U)

// CH3_AL2_WRITE_ADDR_TRIG Configuration

#define DMA_CH3_AL2_WRITE_ADDR_TRIG_CH3_AL2_WRITE_ADDR_TRIG         (0xFFFFFFFFU<<0U)
#define DMA_CH3_AL2_WRITE_ADDR_TRIG_CH3_AL2_WRITE_ADDR_TRIG_0       (0x1U<<0U)

// CH3_AL3_CTRL Configuration

#define DMA_CH3_AL3_CTRL_CH3_AL3_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH3_AL3_CTRL_CH3_AL3_CTRL_0                             (0x1U<<0U)

// CH3_AL3_WRITE_ADDR Configuration

#define DMA_CH3_AL3_WRITE_ADDR_CH3_AL3_WRITE_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH3_AL3_WRITE_ADDR_CH3_AL3_WRITE_ADDR_0                 (0x1U<<0U)

// CH3_AL3_TRANS_COUNT Configuration

#define DMA_CH3_AL3_TRANS_COUNT_CH3_AL3_TRANS_COUNT                 (0xFFFFFFFFU<<0U)
#define DMA_CH3_AL3_TRANS_COUNT_CH3_AL3_TRANS_COUNT_0               (0x1U<<0U)

// CH3_AL3_READ_ADDR_TRIG Configuration

#define DMA_CH3_AL3_READ_ADDR_TRIG_CH3_AL3_READ_ADDR_TRIG           (0xFFFFFFFFU<<0U)
#define DMA_CH3_AL3_READ_ADDR_TRIG_CH3_AL3_READ_ADDR_TRIG_0         (0x1U<<0U)

// CH4_READ_ADDR Configuration

#define DMA_CH4_READ_ADDR_CH4_READ_ADDR                             (0xFFFFFFFFU<<0U)
#define DMA_CH4_READ_ADDR_CH4_READ_ADDR_0                           (0x1U<<0U)

// CH4_WRITE_ADDR Configuration

#define DMA_CH4_WRITE_ADDR_CH4_WRITE_ADDR                           (0xFFFFFFFFU<<0U)
#define DMA_CH4_WRITE_ADDR_CH4_WRITE_ADDR_0                         (0x1U<<0U)

// CH4_TRANS_COUNT Configuration

#define DMA_CH4_TRANS_COUNT_COUNT                                   (0xFFFFFFFU<<0U)
#define DMA_CH4_TRANS_COUNT_COUNT_0                                 (0x1U<<0U)
#define DMA_CH4_TRANS_COUNT_MODE                                    (0xFU<<28U)
#define DMA_CH4_TRANS_COUNT_MODE_0                                  (0x1U<<28U)
#define DMA_CH4_TRANS_COUNT_MODE_NORMAL                             (0x0U<<28U)
#define DMA_CH4_TRANS_COUNT_MODE_TRIGGER_SELF                       (0x1U<<28U)
#define DMA_CH4_TRANS_COUNT_MODE_ENDLESS                            (0xFU<<28U)

// CH4_CTRL_TRIG Configuration

#define DMA_CH4_CTRL_TRIG_EN                                        (0x1U<<0U)
#define DMA_CH4_CTRL_TRIG_HIGH_PRIORITY                             (0x1U<<1U)
#define DMA_CH4_CTRL_TRIG_DATA_SIZE                                 (0x3U<<2U)
#define DMA_CH4_CTRL_TRIG_DATA_SIZE_0                               (0x1U<<2U)
#define DMA_CH4_CTRL_TRIG_INCR_READ                                 (0x1U<<4U)
#define DMA_CH4_CTRL_TRIG_INCR_READ_REV                             (0x1U<<5U)
#define DMA_CH4_CTRL_TRIG_INCR_WRITE                                (0x1U<<6U)
#define DMA_CH4_CTRL_TRIG_INCR_WRITE_REV                            (0x1U<<7U)
#define DMA_CH4_CTRL_TRIG_RING_SIZE                                 (0xFU<<8U)
#define DMA_CH4_CTRL_TRIG_RING_SIZE_0                               (0x1U<<8U)
#define DMA_CH4_CTRL_TRIG_RING_SEL                                  (0x1U<<12U)
#define DMA_CH4_CTRL_TRIG_CHAIN_TO                                  (0xFU<<13U)
#define DMA_CH4_CTRL_TRIG_CHAIN_TO_0                                (0x1U<<13U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL                                  (0x3FU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_0                                (0x1U<<17U)
#define DMA_CH4_CTRL_TRIG_IRQ_QUIET                                 (0x1U<<23U)
#define DMA_CH4_CTRL_TRIG_BSWAP                                     (0x1U<<24U)
#define DMA_CH4_CTRL_TRIG_SNIFF_EN                                  (0x1U<<25U)
#define DMA_CH4_CTRL_TRIG_BUSY                                      (0x1U<<26U)
#define DMA_CH4_CTRL_TRIG_WRITE_ERROR                               (0x1U<<29U)
#define DMA_CH4_CTRL_TRIG_READ_ERROR                                (0x1U<<30U)
#define DMA_CH4_CTRL_TRIG_AHB_ERROR                                 (0x1U<<31U)
#define DMA_CH4_CTRL_TRIG_DATA_SIZE_SIZE_BYTE                       (0x0U<<2U)
#define DMA_CH4_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD                   (0x1U<<2U)
#define DMA_CH4_CTRL_TRIG_DATA_SIZE_SIZE_WORD                       (0x2U<<2U)
#define DMA_CH4_CTRL_TRIG_RING_SIZE_RING_NONE                       (0x0U<<8U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO0_TX0                         (0x0U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO0_TX1                         (0x1U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO0_TX2                         (0x2U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO0_TX3                         (0x3U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO0_RX0                         (0x4U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO0_RX1                         (0x5U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO0_RX2                         (0x6U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO0_RX3                         (0x7U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO1_TX0                         (0x8U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO1_TX1                         (0x9U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO1_TX2                         (0xAU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO1_TX3                         (0xBU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO1_RX0                         (0xCU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO1_RX1                         (0xDU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO1_RX2                         (0xEU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO1_RX3                         (0xFU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO2_TX0                         (0x10U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO2_TX1                         (0x11U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO2_TX2                         (0x12U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO2_TX3                         (0x13U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO2_RX0                         (0x14U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO2_RX1                         (0x15U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO2_RX2                         (0x16U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PIO2_RX3                         (0x17U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_SPI0_TX                          (0x18U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_SPI0_RX                          (0x19U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_SPI1_TX                          (0x1AU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_SPI1_RX                          (0x1BU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_UART0_TX                         (0x1CU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_UART0_RX                         (0x1DU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_UART1_TX                         (0x1EU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_UART1_RX                         (0x1FU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PWM_WRAP0                        (0x20U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PWM_WRAP1                        (0x21U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PWM_WRAP2                        (0x22U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PWM_WRAP3                        (0x23U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PWM_WRAP4                        (0x24U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PWM_WRAP5                        (0x25U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PWM_WRAP6                        (0x26U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PWM_WRAP7                        (0x27U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PWM_WRAP8                        (0x28U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PWM_WRAP9                        (0x29U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PWM_WRAP10                       (0x2AU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PWM_WRAP11                       (0x2BU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_I2C0_TX                          (0x2CU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_I2C0_RX                          (0x2DU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_I2C1_TX                          (0x2EU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_I2C1_RX                          (0x2FU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_ADC                              (0x30U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_XIP_STREAM                       (0x31U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_XIP_QMITX                        (0x32U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_XIP_QMIRX                        (0x33U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_HSTX                             (0x34U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_CORESIGHT                        (0x35U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_SHA256                           (0x36U<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_TIMER0                           (0x3BU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_TIMER1                           (0x3CU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_TIMER2                           (0x3DU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_TIMER3                           (0x3EU<<17U)
#define DMA_CH4_CTRL_TRIG_TREQ_SEL_PERMANENT                        (0x3FU<<17U)

// CH4_AL1_CTRL Configuration

#define DMA_CH4_AL1_CTRL_CH4_AL1_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH4_AL1_CTRL_CH4_AL1_CTRL_0                             (0x1U<<0U)

// CH4_AL1_READ_ADDR Configuration

#define DMA_CH4_AL1_READ_ADDR_CH4_AL1_READ_ADDR                     (0xFFFFFFFFU<<0U)
#define DMA_CH4_AL1_READ_ADDR_CH4_AL1_READ_ADDR_0                   (0x1U<<0U)

// CH4_AL1_WRITE_ADDR Configuration

#define DMA_CH4_AL1_WRITE_ADDR_CH4_AL1_WRITE_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH4_AL1_WRITE_ADDR_CH4_AL1_WRITE_ADDR_0                 (0x1U<<0U)

// CH4_AL1_TRANS_COUNT_TRIG Configuration

#define DMA_CH4_AL1_TRANS_COUNT_TRIG_CH4_AL1_TRANS_COUNT_TRIG       (0xFFFFFFFFU<<0U)
#define DMA_CH4_AL1_TRANS_COUNT_TRIG_CH4_AL1_TRANS_COUNT_TRIG_0     (0x1U<<0U)

// CH4_AL2_CTRL Configuration

#define DMA_CH4_AL2_CTRL_CH4_AL2_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH4_AL2_CTRL_CH4_AL2_CTRL_0                             (0x1U<<0U)

// CH4_AL2_TRANS_COUNT Configuration

#define DMA_CH4_AL2_TRANS_COUNT_CH4_AL2_TRANS_COUNT                 (0xFFFFFFFFU<<0U)
#define DMA_CH4_AL2_TRANS_COUNT_CH4_AL2_TRANS_COUNT_0               (0x1U<<0U)

// CH4_AL2_READ_ADDR Configuration

#define DMA_CH4_AL2_READ_ADDR_CH4_AL2_READ_ADDR                     (0xFFFFFFFFU<<0U)
#define DMA_CH4_AL2_READ_ADDR_CH4_AL2_READ_ADDR_0                   (0x1U<<0U)

// CH4_AL2_WRITE_ADDR_TRIG Configuration

#define DMA_CH4_AL2_WRITE_ADDR_TRIG_CH4_AL2_WRITE_ADDR_TRIG         (0xFFFFFFFFU<<0U)
#define DMA_CH4_AL2_WRITE_ADDR_TRIG_CH4_AL2_WRITE_ADDR_TRIG_0       (0x1U<<0U)

// CH4_AL3_CTRL Configuration

#define DMA_CH4_AL3_CTRL_CH4_AL3_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH4_AL3_CTRL_CH4_AL3_CTRL_0                             (0x1U<<0U)

// CH4_AL3_WRITE_ADDR Configuration

#define DMA_CH4_AL3_WRITE_ADDR_CH4_AL3_WRITE_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH4_AL3_WRITE_ADDR_CH4_AL3_WRITE_ADDR_0                 (0x1U<<0U)

// CH4_AL3_TRANS_COUNT Configuration

#define DMA_CH4_AL3_TRANS_COUNT_CH4_AL3_TRANS_COUNT                 (0xFFFFFFFFU<<0U)
#define DMA_CH4_AL3_TRANS_COUNT_CH4_AL3_TRANS_COUNT_0               (0x1U<<0U)

// CH4_AL3_READ_ADDR_TRIG Configuration

#define DMA_CH4_AL3_READ_ADDR_TRIG_CH4_AL3_READ_ADDR_TRIG           (0xFFFFFFFFU<<0U)
#define DMA_CH4_AL3_READ_ADDR_TRIG_CH4_AL3_READ_ADDR_TRIG_0         (0x1U<<0U)

// CH5_READ_ADDR Configuration

#define DMA_CH5_READ_ADDR_CH5_READ_ADDR                             (0xFFFFFFFFU<<0U)
#define DMA_CH5_READ_ADDR_CH5_READ_ADDR_0                           (0x1U<<0U)

// CH5_WRITE_ADDR Configuration

#define DMA_CH5_WRITE_ADDR_CH5_WRITE_ADDR                           (0xFFFFFFFFU<<0U)
#define DMA_CH5_WRITE_ADDR_CH5_WRITE_ADDR_0                         (0x1U<<0U)

// CH5_TRANS_COUNT Configuration

#define DMA_CH5_TRANS_COUNT_COUNT                                   (0xFFFFFFFU<<0U)
#define DMA_CH5_TRANS_COUNT_COUNT_0                                 (0x1U<<0U)
#define DMA_CH5_TRANS_COUNT_MODE                                    (0xFU<<28U)
#define DMA_CH5_TRANS_COUNT_MODE_0                                  (0x1U<<28U)
#define DMA_CH5_TRANS_COUNT_MODE_NORMAL                             (0x0U<<28U)
#define DMA_CH5_TRANS_COUNT_MODE_TRIGGER_SELF                       (0x1U<<28U)
#define DMA_CH5_TRANS_COUNT_MODE_ENDLESS                            (0xFU<<28U)

// CH5_CTRL_TRIG Configuration

#define DMA_CH5_CTRL_TRIG_EN                                        (0x1U<<0U)
#define DMA_CH5_CTRL_TRIG_HIGH_PRIORITY                             (0x1U<<1U)
#define DMA_CH5_CTRL_TRIG_DATA_SIZE                                 (0x3U<<2U)
#define DMA_CH5_CTRL_TRIG_DATA_SIZE_0                               (0x1U<<2U)
#define DMA_CH5_CTRL_TRIG_INCR_READ                                 (0x1U<<4U)
#define DMA_CH5_CTRL_TRIG_INCR_READ_REV                             (0x1U<<5U)
#define DMA_CH5_CTRL_TRIG_INCR_WRITE                                (0x1U<<6U)
#define DMA_CH5_CTRL_TRIG_INCR_WRITE_REV                            (0x1U<<7U)
#define DMA_CH5_CTRL_TRIG_RING_SIZE                                 (0xFU<<8U)
#define DMA_CH5_CTRL_TRIG_RING_SIZE_0                               (0x1U<<8U)
#define DMA_CH5_CTRL_TRIG_RING_SEL                                  (0x1U<<12U)
#define DMA_CH5_CTRL_TRIG_CHAIN_TO                                  (0xFU<<13U)
#define DMA_CH5_CTRL_TRIG_CHAIN_TO_0                                (0x1U<<13U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL                                  (0x3FU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_0                                (0x1U<<17U)
#define DMA_CH5_CTRL_TRIG_IRQ_QUIET                                 (0x1U<<23U)
#define DMA_CH5_CTRL_TRIG_BSWAP                                     (0x1U<<24U)
#define DMA_CH5_CTRL_TRIG_SNIFF_EN                                  (0x1U<<25U)
#define DMA_CH5_CTRL_TRIG_BUSY                                      (0x1U<<26U)
#define DMA_CH5_CTRL_TRIG_WRITE_ERROR                               (0x1U<<29U)
#define DMA_CH5_CTRL_TRIG_READ_ERROR                                (0x1U<<30U)
#define DMA_CH5_CTRL_TRIG_AHB_ERROR                                 (0x1U<<31U)
#define DMA_CH5_CTRL_TRIG_DATA_SIZE_SIZE_BYTE                       (0x0U<<2U)
#define DMA_CH5_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD                   (0x1U<<2U)
#define DMA_CH5_CTRL_TRIG_DATA_SIZE_SIZE_WORD                       (0x2U<<2U)
#define DMA_CH5_CTRL_TRIG_RING_SIZE_RING_NONE                       (0x0U<<8U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO0_TX0                         (0x0U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO0_TX1                         (0x1U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO0_TX2                         (0x2U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO0_TX3                         (0x3U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO0_RX0                         (0x4U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO0_RX1                         (0x5U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO0_RX2                         (0x6U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO0_RX3                         (0x7U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO1_TX0                         (0x8U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO1_TX1                         (0x9U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO1_TX2                         (0xAU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO1_TX3                         (0xBU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO1_RX0                         (0xCU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO1_RX1                         (0xDU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO1_RX2                         (0xEU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO1_RX3                         (0xFU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO2_TX0                         (0x10U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO2_TX1                         (0x11U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO2_TX2                         (0x12U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO2_TX3                         (0x13U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO2_RX0                         (0x14U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO2_RX1                         (0x15U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO2_RX2                         (0x16U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PIO2_RX3                         (0x17U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_SPI0_TX                          (0x18U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_SPI0_RX                          (0x19U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_SPI1_TX                          (0x1AU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_SPI1_RX                          (0x1BU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_UART0_TX                         (0x1CU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_UART0_RX                         (0x1DU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_UART1_TX                         (0x1EU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_UART1_RX                         (0x1FU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PWM_WRAP0                        (0x20U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PWM_WRAP1                        (0x21U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PWM_WRAP2                        (0x22U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PWM_WRAP3                        (0x23U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PWM_WRAP4                        (0x24U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PWM_WRAP5                        (0x25U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PWM_WRAP6                        (0x26U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PWM_WRAP7                        (0x27U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PWM_WRAP8                        (0x28U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PWM_WRAP9                        (0x29U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PWM_WRAP10                       (0x2AU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PWM_WRAP11                       (0x2BU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_I2C0_TX                          (0x2CU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_I2C0_RX                          (0x2DU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_I2C1_TX                          (0x2EU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_I2C1_RX                          (0x2FU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_ADC                              (0x30U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_XIP_STREAM                       (0x31U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_XIP_QMITX                        (0x32U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_XIP_QMIRX                        (0x33U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_HSTX                             (0x34U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_CORESIGHT                        (0x35U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_SHA256                           (0x36U<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_TIMER0                           (0x3BU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_TIMER1                           (0x3CU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_TIMER2                           (0x3DU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_TIMER3                           (0x3EU<<17U)
#define DMA_CH5_CTRL_TRIG_TREQ_SEL_PERMANENT                        (0x3FU<<17U)

// CH5_AL1_CTRL Configuration

#define DMA_CH5_AL1_CTRL_CH5_AL1_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH5_AL1_CTRL_CH5_AL1_CTRL_0                             (0x1U<<0U)

// CH5_AL1_READ_ADDR Configuration

#define DMA_CH5_AL1_READ_ADDR_CH5_AL1_READ_ADDR                     (0xFFFFFFFFU<<0U)
#define DMA_CH5_AL1_READ_ADDR_CH5_AL1_READ_ADDR_0                   (0x1U<<0U)

// CH5_AL1_WRITE_ADDR Configuration

#define DMA_CH5_AL1_WRITE_ADDR_CH5_AL1_WRITE_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH5_AL1_WRITE_ADDR_CH5_AL1_WRITE_ADDR_0                 (0x1U<<0U)

// CH5_AL1_TRANS_COUNT_TRIG Configuration

#define DMA_CH5_AL1_TRANS_COUNT_TRIG_CH5_AL1_TRANS_COUNT_TRIG       (0xFFFFFFFFU<<0U)
#define DMA_CH5_AL1_TRANS_COUNT_TRIG_CH5_AL1_TRANS_COUNT_TRIG_0     (0x1U<<0U)

// CH5_AL2_CTRL Configuration

#define DMA_CH5_AL2_CTRL_CH5_AL2_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH5_AL2_CTRL_CH5_AL2_CTRL_0                             (0x1U<<0U)

// CH5_AL2_TRANS_COUNT Configuration

#define DMA_CH5_AL2_TRANS_COUNT_CH5_AL2_TRANS_COUNT                 (0xFFFFFFFFU<<0U)
#define DMA_CH5_AL2_TRANS_COUNT_CH5_AL2_TRANS_COUNT_0               (0x1U<<0U)

// CH5_AL2_READ_ADDR Configuration

#define DMA_CH5_AL2_READ_ADDR_CH5_AL2_READ_ADDR                     (0xFFFFFFFFU<<0U)
#define DMA_CH5_AL2_READ_ADDR_CH5_AL2_READ_ADDR_0                   (0x1U<<0U)

// CH5_AL2_WRITE_ADDR_TRIG Configuration

#define DMA_CH5_AL2_WRITE_ADDR_TRIG_CH5_AL2_WRITE_ADDR_TRIG         (0xFFFFFFFFU<<0U)
#define DMA_CH5_AL2_WRITE_ADDR_TRIG_CH5_AL2_WRITE_ADDR_TRIG_0       (0x1U<<0U)

// CH5_AL3_CTRL Configuration

#define DMA_CH5_AL3_CTRL_CH5_AL3_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH5_AL3_CTRL_CH5_AL3_CTRL_0                             (0x1U<<0U)

// CH5_AL3_WRITE_ADDR Configuration

#define DMA_CH5_AL3_WRITE_ADDR_CH5_AL3_WRITE_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH5_AL3_WRITE_ADDR_CH5_AL3_WRITE_ADDR_0                 (0x1U<<0U)

// CH5_AL3_TRANS_COUNT Configuration

#define DMA_CH5_AL3_TRANS_COUNT_CH5_AL3_TRANS_COUNT                 (0xFFFFFFFFU<<0U)
#define DMA_CH5_AL3_TRANS_COUNT_CH5_AL3_TRANS_COUNT_0               (0x1U<<0U)

// CH5_AL3_READ_ADDR_TRIG Configuration

#define DMA_CH5_AL3_READ_ADDR_TRIG_CH5_AL3_READ_ADDR_TRIG           (0xFFFFFFFFU<<0U)
#define DMA_CH5_AL3_READ_ADDR_TRIG_CH5_AL3_READ_ADDR_TRIG_0         (0x1U<<0U)

// CH6_READ_ADDR Configuration

#define DMA_CH6_READ_ADDR_CH6_READ_ADDR                             (0xFFFFFFFFU<<0U)
#define DMA_CH6_READ_ADDR_CH6_READ_ADDR_0                           (0x1U<<0U)

// CH6_WRITE_ADDR Configuration

#define DMA_CH6_WRITE_ADDR_CH6_WRITE_ADDR                           (0xFFFFFFFFU<<0U)
#define DMA_CH6_WRITE_ADDR_CH6_WRITE_ADDR_0                         (0x1U<<0U)

// CH6_TRANS_COUNT Configuration

#define DMA_CH6_TRANS_COUNT_COUNT                                   (0xFFFFFFFU<<0U)
#define DMA_CH6_TRANS_COUNT_COUNT_0                                 (0x1U<<0U)
#define DMA_CH6_TRANS_COUNT_MODE                                    (0xFU<<28U)
#define DMA_CH6_TRANS_COUNT_MODE_0                                  (0x1U<<28U)
#define DMA_CH6_TRANS_COUNT_MODE_NORMAL                             (0x0U<<28U)
#define DMA_CH6_TRANS_COUNT_MODE_TRIGGER_SELF                       (0x1U<<28U)
#define DMA_CH6_TRANS_COUNT_MODE_ENDLESS                            (0xFU<<28U)

// CH6_CTRL_TRIG Configuration

#define DMA_CH6_CTRL_TRIG_EN                                        (0x1U<<0U)
#define DMA_CH6_CTRL_TRIG_HIGH_PRIORITY                             (0x1U<<1U)
#define DMA_CH6_CTRL_TRIG_DATA_SIZE                                 (0x3U<<2U)
#define DMA_CH6_CTRL_TRIG_DATA_SIZE_0                               (0x1U<<2U)
#define DMA_CH6_CTRL_TRIG_INCR_READ                                 (0x1U<<4U)
#define DMA_CH6_CTRL_TRIG_INCR_READ_REV                             (0x1U<<5U)
#define DMA_CH6_CTRL_TRIG_INCR_WRITE                                (0x1U<<6U)
#define DMA_CH6_CTRL_TRIG_INCR_WRITE_REV                            (0x1U<<7U)
#define DMA_CH6_CTRL_TRIG_RING_SIZE                                 (0xFU<<8U)
#define DMA_CH6_CTRL_TRIG_RING_SIZE_0                               (0x1U<<8U)
#define DMA_CH6_CTRL_TRIG_RING_SEL                                  (0x1U<<12U)
#define DMA_CH6_CTRL_TRIG_CHAIN_TO                                  (0xFU<<13U)
#define DMA_CH6_CTRL_TRIG_CHAIN_TO_0                                (0x1U<<13U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL                                  (0x3FU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_0                                (0x1U<<17U)
#define DMA_CH6_CTRL_TRIG_IRQ_QUIET                                 (0x1U<<23U)
#define DMA_CH6_CTRL_TRIG_BSWAP                                     (0x1U<<24U)
#define DMA_CH6_CTRL_TRIG_SNIFF_EN                                  (0x1U<<25U)
#define DMA_CH6_CTRL_TRIG_BUSY                                      (0x1U<<26U)
#define DMA_CH6_CTRL_TRIG_WRITE_ERROR                               (0x1U<<29U)
#define DMA_CH6_CTRL_TRIG_READ_ERROR                                (0x1U<<30U)
#define DMA_CH6_CTRL_TRIG_AHB_ERROR                                 (0x1U<<31U)
#define DMA_CH6_CTRL_TRIG_DATA_SIZE_SIZE_BYTE                       (0x0U<<2U)
#define DMA_CH6_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD                   (0x1U<<2U)
#define DMA_CH6_CTRL_TRIG_DATA_SIZE_SIZE_WORD                       (0x2U<<2U)
#define DMA_CH6_CTRL_TRIG_RING_SIZE_RING_NONE                       (0x0U<<8U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO0_TX0                         (0x0U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO0_TX1                         (0x1U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO0_TX2                         (0x2U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO0_TX3                         (0x3U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO0_RX0                         (0x4U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO0_RX1                         (0x5U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO0_RX2                         (0x6U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO0_RX3                         (0x7U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO1_TX0                         (0x8U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO1_TX1                         (0x9U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO1_TX2                         (0xAU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO1_TX3                         (0xBU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO1_RX0                         (0xCU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO1_RX1                         (0xDU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO1_RX2                         (0xEU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO1_RX3                         (0xFU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO2_TX0                         (0x10U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO2_TX1                         (0x11U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO2_TX2                         (0x12U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO2_TX3                         (0x13U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO2_RX0                         (0x14U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO2_RX1                         (0x15U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO2_RX2                         (0x16U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PIO2_RX3                         (0x17U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_SPI0_TX                          (0x18U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_SPI0_RX                          (0x19U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_SPI1_TX                          (0x1AU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_SPI1_RX                          (0x1BU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_UART0_TX                         (0x1CU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_UART0_RX                         (0x1DU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_UART1_TX                         (0x1EU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_UART1_RX                         (0x1FU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PWM_WRAP0                        (0x20U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PWM_WRAP1                        (0x21U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PWM_WRAP2                        (0x22U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PWM_WRAP3                        (0x23U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PWM_WRAP4                        (0x24U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PWM_WRAP5                        (0x25U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PWM_WRAP6                        (0x26U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PWM_WRAP7                        (0x27U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PWM_WRAP8                        (0x28U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PWM_WRAP9                        (0x29U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PWM_WRAP10                       (0x2AU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PWM_WRAP11                       (0x2BU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_I2C0_TX                          (0x2CU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_I2C0_RX                          (0x2DU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_I2C1_TX                          (0x2EU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_I2C1_RX                          (0x2FU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_ADC                              (0x30U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_XIP_STREAM                       (0x31U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_XIP_QMITX                        (0x32U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_XIP_QMIRX                        (0x33U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_HSTX                             (0x34U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_CORESIGHT                        (0x35U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_SHA256                           (0x36U<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_TIMER0                           (0x3BU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_TIMER1                           (0x3CU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_TIMER2                           (0x3DU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_TIMER3                           (0x3EU<<17U)
#define DMA_CH6_CTRL_TRIG_TREQ_SEL_PERMANENT                        (0x3FU<<17U)

// CH6_AL1_CTRL Configuration

#define DMA_CH6_AL1_CTRL_CH6_AL1_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH6_AL1_CTRL_CH6_AL1_CTRL_0                             (0x1U<<0U)

// CH6_AL1_READ_ADDR Configuration

#define DMA_CH6_AL1_READ_ADDR_CH6_AL1_READ_ADDR                     (0xFFFFFFFFU<<0U)
#define DMA_CH6_AL1_READ_ADDR_CH6_AL1_READ_ADDR_0                   (0x1U<<0U)

// CH6_AL1_WRITE_ADDR Configuration

#define DMA_CH6_AL1_WRITE_ADDR_CH6_AL1_WRITE_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH6_AL1_WRITE_ADDR_CH6_AL1_WRITE_ADDR_0                 (0x1U<<0U)

// CH6_AL1_TRANS_COUNT_TRIG Configuration

#define DMA_CH6_AL1_TRANS_COUNT_TRIG_CH6_AL1_TRANS_COUNT_TRIG       (0xFFFFFFFFU<<0U)
#define DMA_CH6_AL1_TRANS_COUNT_TRIG_CH6_AL1_TRANS_COUNT_TRIG_0     (0x1U<<0U)

// CH6_AL2_CTRL Configuration

#define DMA_CH6_AL2_CTRL_CH6_AL2_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH6_AL2_CTRL_CH6_AL2_CTRL_0                             (0x1U<<0U)

// CH6_AL2_TRANS_COUNT Configuration

#define DMA_CH6_AL2_TRANS_COUNT_CH6_AL2_TRANS_COUNT                 (0xFFFFFFFFU<<0U)
#define DMA_CH6_AL2_TRANS_COUNT_CH6_AL2_TRANS_COUNT_0               (0x1U<<0U)

// CH6_AL2_READ_ADDR Configuration

#define DMA_CH6_AL2_READ_ADDR_CH6_AL2_READ_ADDR                     (0xFFFFFFFFU<<0U)
#define DMA_CH6_AL2_READ_ADDR_CH6_AL2_READ_ADDR_0                   (0x1U<<0U)

// CH6_AL2_WRITE_ADDR_TRIG Configuration

#define DMA_CH6_AL2_WRITE_ADDR_TRIG_CH6_AL2_WRITE_ADDR_TRIG         (0xFFFFFFFFU<<0U)
#define DMA_CH6_AL2_WRITE_ADDR_TRIG_CH6_AL2_WRITE_ADDR_TRIG_0       (0x1U<<0U)

// CH6_AL3_CTRL Configuration

#define DMA_CH6_AL3_CTRL_CH6_AL3_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH6_AL3_CTRL_CH6_AL3_CTRL_0                             (0x1U<<0U)

// CH6_AL3_WRITE_ADDR Configuration

#define DMA_CH6_AL3_WRITE_ADDR_CH6_AL3_WRITE_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH6_AL3_WRITE_ADDR_CH6_AL3_WRITE_ADDR_0                 (0x1U<<0U)

// CH6_AL3_TRANS_COUNT Configuration

#define DMA_CH6_AL3_TRANS_COUNT_CH6_AL3_TRANS_COUNT                 (0xFFFFFFFFU<<0U)
#define DMA_CH6_AL3_TRANS_COUNT_CH6_AL3_TRANS_COUNT_0               (0x1U<<0U)

// CH6_AL3_READ_ADDR_TRIG Configuration

#define DMA_CH6_AL3_READ_ADDR_TRIG_CH6_AL3_READ_ADDR_TRIG           (0xFFFFFFFFU<<0U)
#define DMA_CH6_AL3_READ_ADDR_TRIG_CH6_AL3_READ_ADDR_TRIG_0         (0x1U<<0U)

// CH7_READ_ADDR Configuration

#define DMA_CH7_READ_ADDR_CH7_READ_ADDR                             (0xFFFFFFFFU<<0U)
#define DMA_CH7_READ_ADDR_CH7_READ_ADDR_0                           (0x1U<<0U)

// CH7_WRITE_ADDR Configuration

#define DMA_CH7_WRITE_ADDR_CH7_WRITE_ADDR                           (0xFFFFFFFFU<<0U)
#define DMA_CH7_WRITE_ADDR_CH7_WRITE_ADDR_0                         (0x1U<<0U)

// CH7_TRANS_COUNT Configuration

#define DMA_CH7_TRANS_COUNT_COUNT                                   (0xFFFFFFFU<<0U)
#define DMA_CH7_TRANS_COUNT_COUNT_0                                 (0x1U<<0U)
#define DMA_CH7_TRANS_COUNT_MODE                                    (0xFU<<28U)
#define DMA_CH7_TRANS_COUNT_MODE_0                                  (0x1U<<28U)
#define DMA_CH7_TRANS_COUNT_MODE_NORMAL                             (0x0U<<28U)
#define DMA_CH7_TRANS_COUNT_MODE_TRIGGER_SELF                       (0x1U<<28U)
#define DMA_CH7_TRANS_COUNT_MODE_ENDLESS                            (0xFU<<28U)

// CH7_CTRL_TRIG Configuration

#define DMA_CH7_CTRL_TRIG_EN                                        (0x1U<<0U)
#define DMA_CH7_CTRL_TRIG_HIGH_PRIORITY                             (0x1U<<1U)
#define DMA_CH7_CTRL_TRIG_DATA_SIZE                                 (0x3U<<2U)
#define DMA_CH7_CTRL_TRIG_DATA_SIZE_0                               (0x1U<<2U)
#define DMA_CH7_CTRL_TRIG_INCR_READ                                 (0x1U<<4U)
#define DMA_CH7_CTRL_TRIG_INCR_READ_REV                             (0x1U<<5U)
#define DMA_CH7_CTRL_TRIG_INCR_WRITE                                (0x1U<<6U)
#define DMA_CH7_CTRL_TRIG_INCR_WRITE_REV                            (0x1U<<7U)
#define DMA_CH7_CTRL_TRIG_RING_SIZE                                 (0xFU<<8U)
#define DMA_CH7_CTRL_TRIG_RING_SIZE_0                               (0x1U<<8U)
#define DMA_CH7_CTRL_TRIG_RING_SEL                                  (0x1U<<12U)
#define DMA_CH7_CTRL_TRIG_CHAIN_TO                                  (0xFU<<13U)
#define DMA_CH7_CTRL_TRIG_CHAIN_TO_0                                (0x1U<<13U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL                                  (0x3FU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_0                                (0x1U<<17U)
#define DMA_CH7_CTRL_TRIG_IRQ_QUIET                                 (0x1U<<23U)
#define DMA_CH7_CTRL_TRIG_BSWAP                                     (0x1U<<24U)
#define DMA_CH7_CTRL_TRIG_SNIFF_EN                                  (0x1U<<25U)
#define DMA_CH7_CTRL_TRIG_BUSY                                      (0x1U<<26U)
#define DMA_CH7_CTRL_TRIG_WRITE_ERROR                               (0x1U<<29U)
#define DMA_CH7_CTRL_TRIG_READ_ERROR                                (0x1U<<30U)
#define DMA_CH7_CTRL_TRIG_AHB_ERROR                                 (0x1U<<31U)
#define DMA_CH7_CTRL_TRIG_DATA_SIZE_SIZE_BYTE                       (0x0U<<2U)
#define DMA_CH7_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD                   (0x1U<<2U)
#define DMA_CH7_CTRL_TRIG_DATA_SIZE_SIZE_WORD                       (0x2U<<2U)
#define DMA_CH7_CTRL_TRIG_RING_SIZE_RING_NONE                       (0x0U<<8U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO0_TX0                         (0x0U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO0_TX1                         (0x1U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO0_TX2                         (0x2U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO0_TX3                         (0x3U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO0_RX0                         (0x4U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO0_RX1                         (0x5U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO0_RX2                         (0x6U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO0_RX3                         (0x7U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO1_TX0                         (0x8U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO1_TX1                         (0x9U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO1_TX2                         (0xAU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO1_TX3                         (0xBU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO1_RX0                         (0xCU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO1_RX1                         (0xDU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO1_RX2                         (0xEU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO1_RX3                         (0xFU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO2_TX0                         (0x10U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO2_TX1                         (0x11U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO2_TX2                         (0x12U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO2_TX3                         (0x13U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO2_RX0                         (0x14U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO2_RX1                         (0x15U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO2_RX2                         (0x16U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PIO2_RX3                         (0x17U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_SPI0_TX                          (0x18U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_SPI0_RX                          (0x19U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_SPI1_TX                          (0x1AU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_SPI1_RX                          (0x1BU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_UART0_TX                         (0x1CU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_UART0_RX                         (0x1DU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_UART1_TX                         (0x1EU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_UART1_RX                         (0x1FU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PWM_WRAP0                        (0x20U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PWM_WRAP1                        (0x21U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PWM_WRAP2                        (0x22U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PWM_WRAP3                        (0x23U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PWM_WRAP4                        (0x24U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PWM_WRAP5                        (0x25U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PWM_WRAP6                        (0x26U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PWM_WRAP7                        (0x27U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PWM_WRAP8                        (0x28U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PWM_WRAP9                        (0x29U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PWM_WRAP10                       (0x2AU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PWM_WRAP11                       (0x2BU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_I2C0_TX                          (0x2CU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_I2C0_RX                          (0x2DU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_I2C1_TX                          (0x2EU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_I2C1_RX                          (0x2FU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_ADC                              (0x30U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_XIP_STREAM                       (0x31U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_XIP_QMITX                        (0x32U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_XIP_QMIRX                        (0x33U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_HSTX                             (0x34U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_CORESIGHT                        (0x35U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_SHA256                           (0x36U<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_TIMER0                           (0x3BU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_TIMER1                           (0x3CU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_TIMER2                           (0x3DU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_TIMER3                           (0x3EU<<17U)
#define DMA_CH7_CTRL_TRIG_TREQ_SEL_PERMANENT                        (0x3FU<<17U)

// CH7_AL1_CTRL Configuration

#define DMA_CH7_AL1_CTRL_CH7_AL1_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH7_AL1_CTRL_CH7_AL1_CTRL_0                             (0x1U<<0U)

// CH7_AL1_READ_ADDR Configuration

#define DMA_CH7_AL1_READ_ADDR_CH7_AL1_READ_ADDR                     (0xFFFFFFFFU<<0U)
#define DMA_CH7_AL1_READ_ADDR_CH7_AL1_READ_ADDR_0                   (0x1U<<0U)

// CH7_AL1_WRITE_ADDR Configuration

#define DMA_CH7_AL1_WRITE_ADDR_CH7_AL1_WRITE_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH7_AL1_WRITE_ADDR_CH7_AL1_WRITE_ADDR_0                 (0x1U<<0U)

// CH7_AL1_TRANS_COUNT_TRIG Configuration

#define DMA_CH7_AL1_TRANS_COUNT_TRIG_CH7_AL1_TRANS_COUNT_TRIG       (0xFFFFFFFFU<<0U)
#define DMA_CH7_AL1_TRANS_COUNT_TRIG_CH7_AL1_TRANS_COUNT_TRIG_0     (0x1U<<0U)

// CH7_AL2_CTRL Configuration

#define DMA_CH7_AL2_CTRL_CH7_AL2_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH7_AL2_CTRL_CH7_AL2_CTRL_0                             (0x1U<<0U)

// CH7_AL2_TRANS_COUNT Configuration

#define DMA_CH7_AL2_TRANS_COUNT_CH7_AL2_TRANS_COUNT                 (0xFFFFFFFFU<<0U)
#define DMA_CH7_AL2_TRANS_COUNT_CH7_AL2_TRANS_COUNT_0               (0x1U<<0U)

// CH7_AL2_READ_ADDR Configuration

#define DMA_CH7_AL2_READ_ADDR_CH7_AL2_READ_ADDR                     (0xFFFFFFFFU<<0U)
#define DMA_CH7_AL2_READ_ADDR_CH7_AL2_READ_ADDR_0                   (0x1U<<0U)

// CH7_AL2_WRITE_ADDR_TRIG Configuration

#define DMA_CH7_AL2_WRITE_ADDR_TRIG_CH7_AL2_WRITE_ADDR_TRIG         (0xFFFFFFFFU<<0U)
#define DMA_CH7_AL2_WRITE_ADDR_TRIG_CH7_AL2_WRITE_ADDR_TRIG_0       (0x1U<<0U)

// CH7_AL3_CTRL Configuration

#define DMA_CH7_AL3_CTRL_CH7_AL3_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH7_AL3_CTRL_CH7_AL3_CTRL_0                             (0x1U<<0U)

// CH7_AL3_WRITE_ADDR Configuration

#define DMA_CH7_AL3_WRITE_ADDR_CH7_AL3_WRITE_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH7_AL3_WRITE_ADDR_CH7_AL3_WRITE_ADDR_0                 (0x1U<<0U)

// CH7_AL3_TRANS_COUNT Configuration

#define DMA_CH7_AL3_TRANS_COUNT_CH7_AL3_TRANS_COUNT                 (0xFFFFFFFFU<<0U)
#define DMA_CH7_AL3_TRANS_COUNT_CH7_AL3_TRANS_COUNT_0               (0x1U<<0U)

// CH7_AL3_READ_ADDR_TRIG Configuration

#define DMA_CH7_AL3_READ_ADDR_TRIG_CH7_AL3_READ_ADDR_TRIG           (0xFFFFFFFFU<<0U)
#define DMA_CH7_AL3_READ_ADDR_TRIG_CH7_AL3_READ_ADDR_TRIG_0         (0x1U<<0U)

// CH8_READ_ADDR Configuration

#define DMA_CH8_READ_ADDR_CH8_READ_ADDR                             (0xFFFFFFFFU<<0U)
#define DMA_CH8_READ_ADDR_CH8_READ_ADDR_0                           (0x1U<<0U)

// CH8_WRITE_ADDR Configuration

#define DMA_CH8_WRITE_ADDR_CH8_WRITE_ADDR                           (0xFFFFFFFFU<<0U)
#define DMA_CH8_WRITE_ADDR_CH8_WRITE_ADDR_0                         (0x1U<<0U)

// CH8_TRANS_COUNT Configuration

#define DMA_CH8_TRANS_COUNT_COUNT                                   (0xFFFFFFFU<<0U)
#define DMA_CH8_TRANS_COUNT_COUNT_0                                 (0x1U<<0U)
#define DMA_CH8_TRANS_COUNT_MODE                                    (0xFU<<28U)
#define DMA_CH8_TRANS_COUNT_MODE_0                                  (0x1U<<28U)
#define DMA_CH8_TRANS_COUNT_MODE_NORMAL                             (0x0U<<28U)
#define DMA_CH8_TRANS_COUNT_MODE_TRIGGER_SELF                       (0x1U<<28U)
#define DMA_CH8_TRANS_COUNT_MODE_ENDLESS                            (0xFU<<28U)

// CH8_CTRL_TRIG Configuration

#define DMA_CH8_CTRL_TRIG_EN                                        (0x1U<<0U)
#define DMA_CH8_CTRL_TRIG_HIGH_PRIORITY                             (0x1U<<1U)
#define DMA_CH8_CTRL_TRIG_DATA_SIZE                                 (0x3U<<2U)
#define DMA_CH8_CTRL_TRIG_DATA_SIZE_0                               (0x1U<<2U)
#define DMA_CH8_CTRL_TRIG_INCR_READ                                 (0x1U<<4U)
#define DMA_CH8_CTRL_TRIG_INCR_READ_REV                             (0x1U<<5U)
#define DMA_CH8_CTRL_TRIG_INCR_WRITE                                (0x1U<<6U)
#define DMA_CH8_CTRL_TRIG_INCR_WRITE_REV                            (0x1U<<7U)
#define DMA_CH8_CTRL_TRIG_RING_SIZE                                 (0xFU<<8U)
#define DMA_CH8_CTRL_TRIG_RING_SIZE_0                               (0x1U<<8U)
#define DMA_CH8_CTRL_TRIG_RING_SEL                                  (0x1U<<12U)
#define DMA_CH8_CTRL_TRIG_CHAIN_TO                                  (0xFU<<13U)
#define DMA_CH8_CTRL_TRIG_CHAIN_TO_0                                (0x1U<<13U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL                                  (0x3FU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_0                                (0x1U<<17U)
#define DMA_CH8_CTRL_TRIG_IRQ_QUIET                                 (0x1U<<23U)
#define DMA_CH8_CTRL_TRIG_BSWAP                                     (0x1U<<24U)
#define DMA_CH8_CTRL_TRIG_SNIFF_EN                                  (0x1U<<25U)
#define DMA_CH8_CTRL_TRIG_BUSY                                      (0x1U<<26U)
#define DMA_CH8_CTRL_TRIG_WRITE_ERROR                               (0x1U<<29U)
#define DMA_CH8_CTRL_TRIG_READ_ERROR                                (0x1U<<30U)
#define DMA_CH8_CTRL_TRIG_AHB_ERROR                                 (0x1U<<31U)
#define DMA_CH8_CTRL_TRIG_DATA_SIZE_SIZE_BYTE                       (0x0U<<2U)
#define DMA_CH8_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD                   (0x1U<<2U)
#define DMA_CH8_CTRL_TRIG_DATA_SIZE_SIZE_WORD                       (0x2U<<2U)
#define DMA_CH8_CTRL_TRIG_RING_SIZE_RING_NONE                       (0x0U<<8U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO0_TX0                         (0x0U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO0_TX1                         (0x1U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO0_TX2                         (0x2U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO0_TX3                         (0x3U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO0_RX0                         (0x4U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO0_RX1                         (0x5U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO0_RX2                         (0x6U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO0_RX3                         (0x7U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO1_TX0                         (0x8U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO1_TX1                         (0x9U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO1_TX2                         (0xAU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO1_TX3                         (0xBU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO1_RX0                         (0xCU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO1_RX1                         (0xDU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO1_RX2                         (0xEU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO1_RX3                         (0xFU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO2_TX0                         (0x10U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO2_TX1                         (0x11U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO2_TX2                         (0x12U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO2_TX3                         (0x13U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO2_RX0                         (0x14U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO2_RX1                         (0x15U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO2_RX2                         (0x16U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PIO2_RX3                         (0x17U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_SPI0_TX                          (0x18U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_SPI0_RX                          (0x19U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_SPI1_TX                          (0x1AU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_SPI1_RX                          (0x1BU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_UART0_TX                         (0x1CU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_UART0_RX                         (0x1DU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_UART1_TX                         (0x1EU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_UART1_RX                         (0x1FU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PWM_WRAP0                        (0x20U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PWM_WRAP1                        (0x21U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PWM_WRAP2                        (0x22U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PWM_WRAP3                        (0x23U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PWM_WRAP4                        (0x24U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PWM_WRAP5                        (0x25U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PWM_WRAP6                        (0x26U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PWM_WRAP7                        (0x27U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PWM_WRAP8                        (0x28U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PWM_WRAP9                        (0x29U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PWM_WRAP10                       (0x2AU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PWM_WRAP11                       (0x2BU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_I2C0_TX                          (0x2CU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_I2C0_RX                          (0x2DU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_I2C1_TX                          (0x2EU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_I2C1_RX                          (0x2FU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_ADC                              (0x30U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_XIP_STREAM                       (0x31U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_XIP_QMITX                        (0x32U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_XIP_QMIRX                        (0x33U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_HSTX                             (0x34U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_CORESIGHT                        (0x35U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_SHA256                           (0x36U<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_TIMER0                           (0x3BU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_TIMER1                           (0x3CU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_TIMER2                           (0x3DU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_TIMER3                           (0x3EU<<17U)
#define DMA_CH8_CTRL_TRIG_TREQ_SEL_PERMANENT                        (0x3FU<<17U)

// CH8_AL1_CTRL Configuration

#define DMA_CH8_AL1_CTRL_CH8_AL1_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH8_AL1_CTRL_CH8_AL1_CTRL_0                             (0x1U<<0U)

// CH8_AL1_READ_ADDR Configuration

#define DMA_CH8_AL1_READ_ADDR_CH8_AL1_READ_ADDR                     (0xFFFFFFFFU<<0U)
#define DMA_CH8_AL1_READ_ADDR_CH8_AL1_READ_ADDR_0                   (0x1U<<0U)

// CH8_AL1_WRITE_ADDR Configuration

#define DMA_CH8_AL1_WRITE_ADDR_CH8_AL1_WRITE_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH8_AL1_WRITE_ADDR_CH8_AL1_WRITE_ADDR_0                 (0x1U<<0U)

// CH8_AL1_TRANS_COUNT_TRIG Configuration

#define DMA_CH8_AL1_TRANS_COUNT_TRIG_CH8_AL1_TRANS_COUNT_TRIG       (0xFFFFFFFFU<<0U)
#define DMA_CH8_AL1_TRANS_COUNT_TRIG_CH8_AL1_TRANS_COUNT_TRIG_0     (0x1U<<0U)

// CH8_AL2_CTRL Configuration

#define DMA_CH8_AL2_CTRL_CH8_AL2_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH8_AL2_CTRL_CH8_AL2_CTRL_0                             (0x1U<<0U)

// CH8_AL2_TRANS_COUNT Configuration

#define DMA_CH8_AL2_TRANS_COUNT_CH8_AL2_TRANS_COUNT                 (0xFFFFFFFFU<<0U)
#define DMA_CH8_AL2_TRANS_COUNT_CH8_AL2_TRANS_COUNT_0               (0x1U<<0U)

// CH8_AL2_READ_ADDR Configuration

#define DMA_CH8_AL2_READ_ADDR_CH8_AL2_READ_ADDR                     (0xFFFFFFFFU<<0U)
#define DMA_CH8_AL2_READ_ADDR_CH8_AL2_READ_ADDR_0                   (0x1U<<0U)

// CH8_AL2_WRITE_ADDR_TRIG Configuration

#define DMA_CH8_AL2_WRITE_ADDR_TRIG_CH8_AL2_WRITE_ADDR_TRIG         (0xFFFFFFFFU<<0U)
#define DMA_CH8_AL2_WRITE_ADDR_TRIG_CH8_AL2_WRITE_ADDR_TRIG_0       (0x1U<<0U)

// CH8_AL3_CTRL Configuration

#define DMA_CH8_AL3_CTRL_CH8_AL3_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH8_AL3_CTRL_CH8_AL3_CTRL_0                             (0x1U<<0U)

// CH8_AL3_WRITE_ADDR Configuration

#define DMA_CH8_AL3_WRITE_ADDR_CH8_AL3_WRITE_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH8_AL3_WRITE_ADDR_CH8_AL3_WRITE_ADDR_0                 (0x1U<<0U)

// CH8_AL3_TRANS_COUNT Configuration

#define DMA_CH8_AL3_TRANS_COUNT_CH8_AL3_TRANS_COUNT                 (0xFFFFFFFFU<<0U)
#define DMA_CH8_AL3_TRANS_COUNT_CH8_AL3_TRANS_COUNT_0               (0x1U<<0U)

// CH8_AL3_READ_ADDR_TRIG Configuration

#define DMA_CH8_AL3_READ_ADDR_TRIG_CH8_AL3_READ_ADDR_TRIG           (0xFFFFFFFFU<<0U)
#define DMA_CH8_AL3_READ_ADDR_TRIG_CH8_AL3_READ_ADDR_TRIG_0         (0x1U<<0U)

// CH9_READ_ADDR Configuration

#define DMA_CH9_READ_ADDR_CH9_READ_ADDR                             (0xFFFFFFFFU<<0U)
#define DMA_CH9_READ_ADDR_CH9_READ_ADDR_0                           (0x1U<<0U)

// CH9_WRITE_ADDR Configuration

#define DMA_CH9_WRITE_ADDR_CH9_WRITE_ADDR                           (0xFFFFFFFFU<<0U)
#define DMA_CH9_WRITE_ADDR_CH9_WRITE_ADDR_0                         (0x1U<<0U)

// CH9_TRANS_COUNT Configuration

#define DMA_CH9_TRANS_COUNT_COUNT                                   (0xFFFFFFFU<<0U)
#define DMA_CH9_TRANS_COUNT_COUNT_0                                 (0x1U<<0U)
#define DMA_CH9_TRANS_COUNT_MODE                                    (0xFU<<28U)
#define DMA_CH9_TRANS_COUNT_MODE_0                                  (0x1U<<28U)
#define DMA_CH9_TRANS_COUNT_MODE_NORMAL                             (0x0U<<28U)
#define DMA_CH9_TRANS_COUNT_MODE_TRIGGER_SELF                       (0x1U<<28U)
#define DMA_CH9_TRANS_COUNT_MODE_ENDLESS                            (0xFU<<28U)

// CH9_CTRL_TRIG Configuration

#define DMA_CH9_CTRL_TRIG_EN                                        (0x1U<<0U)
#define DMA_CH9_CTRL_TRIG_HIGH_PRIORITY                             (0x1U<<1U)
#define DMA_CH9_CTRL_TRIG_DATA_SIZE                                 (0x3U<<2U)
#define DMA_CH9_CTRL_TRIG_DATA_SIZE_0                               (0x1U<<2U)
#define DMA_CH9_CTRL_TRIG_INCR_READ                                 (0x1U<<4U)
#define DMA_CH9_CTRL_TRIG_INCR_READ_REV                             (0x1U<<5U)
#define DMA_CH9_CTRL_TRIG_INCR_WRITE                                (0x1U<<6U)
#define DMA_CH9_CTRL_TRIG_INCR_WRITE_REV                            (0x1U<<7U)
#define DMA_CH9_CTRL_TRIG_RING_SIZE                                 (0xFU<<8U)
#define DMA_CH9_CTRL_TRIG_RING_SIZE_0                               (0x1U<<8U)
#define DMA_CH9_CTRL_TRIG_RING_SEL                                  (0x1U<<12U)
#define DMA_CH9_CTRL_TRIG_CHAIN_TO                                  (0xFU<<13U)
#define DMA_CH9_CTRL_TRIG_CHAIN_TO_0                                (0x1U<<13U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL                                  (0x3FU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_0                                (0x1U<<17U)
#define DMA_CH9_CTRL_TRIG_IRQ_QUIET                                 (0x1U<<23U)
#define DMA_CH9_CTRL_TRIG_BSWAP                                     (0x1U<<24U)
#define DMA_CH9_CTRL_TRIG_SNIFF_EN                                  (0x1U<<25U)
#define DMA_CH9_CTRL_TRIG_BUSY                                      (0x1U<<26U)
#define DMA_CH9_CTRL_TRIG_WRITE_ERROR                               (0x1U<<29U)
#define DMA_CH9_CTRL_TRIG_READ_ERROR                                (0x1U<<30U)
#define DMA_CH9_CTRL_TRIG_AHB_ERROR                                 (0x1U<<31U)
#define DMA_CH9_CTRL_TRIG_DATA_SIZE_SIZE_BYTE                       (0x0U<<2U)
#define DMA_CH9_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD                   (0x1U<<2U)
#define DMA_CH9_CTRL_TRIG_DATA_SIZE_SIZE_WORD                       (0x2U<<2U)
#define DMA_CH9_CTRL_TRIG_RING_SIZE_RING_NONE                       (0x0U<<8U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO0_TX0                         (0x0U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO0_TX1                         (0x1U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO0_TX2                         (0x2U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO0_TX3                         (0x3U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO0_RX0                         (0x4U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO0_RX1                         (0x5U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO0_RX2                         (0x6U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO0_RX3                         (0x7U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO1_TX0                         (0x8U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO1_TX1                         (0x9U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO1_TX2                         (0xAU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO1_TX3                         (0xBU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO1_RX0                         (0xCU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO1_RX1                         (0xDU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO1_RX2                         (0xEU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO1_RX3                         (0xFU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO2_TX0                         (0x10U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO2_TX1                         (0x11U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO2_TX2                         (0x12U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO2_TX3                         (0x13U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO2_RX0                         (0x14U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO2_RX1                         (0x15U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO2_RX2                         (0x16U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PIO2_RX3                         (0x17U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_SPI0_TX                          (0x18U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_SPI0_RX                          (0x19U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_SPI1_TX                          (0x1AU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_SPI1_RX                          (0x1BU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_UART0_TX                         (0x1CU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_UART0_RX                         (0x1DU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_UART1_TX                         (0x1EU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_UART1_RX                         (0x1FU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PWM_WRAP0                        (0x20U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PWM_WRAP1                        (0x21U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PWM_WRAP2                        (0x22U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PWM_WRAP3                        (0x23U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PWM_WRAP4                        (0x24U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PWM_WRAP5                        (0x25U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PWM_WRAP6                        (0x26U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PWM_WRAP7                        (0x27U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PWM_WRAP8                        (0x28U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PWM_WRAP9                        (0x29U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PWM_WRAP10                       (0x2AU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PWM_WRAP11                       (0x2BU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_I2C0_TX                          (0x2CU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_I2C0_RX                          (0x2DU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_I2C1_TX                          (0x2EU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_I2C1_RX                          (0x2FU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_ADC                              (0x30U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_XIP_STREAM                       (0x31U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_XIP_QMITX                        (0x32U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_XIP_QMIRX                        (0x33U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_HSTX                             (0x34U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_CORESIGHT                        (0x35U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_SHA256                           (0x36U<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_TIMER0                           (0x3BU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_TIMER1                           (0x3CU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_TIMER2                           (0x3DU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_TIMER3                           (0x3EU<<17U)
#define DMA_CH9_CTRL_TRIG_TREQ_SEL_PERMANENT                        (0x3FU<<17U)

// CH9_AL1_CTRL Configuration

#define DMA_CH9_AL1_CTRL_CH9_AL1_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH9_AL1_CTRL_CH9_AL1_CTRL_0                             (0x1U<<0U)

// CH9_AL1_READ_ADDR Configuration

#define DMA_CH9_AL1_READ_ADDR_CH9_AL1_READ_ADDR                     (0xFFFFFFFFU<<0U)
#define DMA_CH9_AL1_READ_ADDR_CH9_AL1_READ_ADDR_0                   (0x1U<<0U)

// CH9_AL1_WRITE_ADDR Configuration

#define DMA_CH9_AL1_WRITE_ADDR_CH9_AL1_WRITE_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH9_AL1_WRITE_ADDR_CH9_AL1_WRITE_ADDR_0                 (0x1U<<0U)

// CH9_AL1_TRANS_COUNT_TRIG Configuration

#define DMA_CH9_AL1_TRANS_COUNT_TRIG_CH9_AL1_TRANS_COUNT_TRIG       (0xFFFFFFFFU<<0U)
#define DMA_CH9_AL1_TRANS_COUNT_TRIG_CH9_AL1_TRANS_COUNT_TRIG_0     (0x1U<<0U)

// CH9_AL2_CTRL Configuration

#define DMA_CH9_AL2_CTRL_CH9_AL2_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH9_AL2_CTRL_CH9_AL2_CTRL_0                             (0x1U<<0U)

// CH9_AL2_TRANS_COUNT Configuration

#define DMA_CH9_AL2_TRANS_COUNT_CH9_AL2_TRANS_COUNT                 (0xFFFFFFFFU<<0U)
#define DMA_CH9_AL2_TRANS_COUNT_CH9_AL2_TRANS_COUNT_0               (0x1U<<0U)

// CH9_AL2_READ_ADDR Configuration

#define DMA_CH9_AL2_READ_ADDR_CH9_AL2_READ_ADDR                     (0xFFFFFFFFU<<0U)
#define DMA_CH9_AL2_READ_ADDR_CH9_AL2_READ_ADDR_0                   (0x1U<<0U)

// CH9_AL2_WRITE_ADDR_TRIG Configuration

#define DMA_CH9_AL2_WRITE_ADDR_TRIG_CH9_AL2_WRITE_ADDR_TRIG         (0xFFFFFFFFU<<0U)
#define DMA_CH9_AL2_WRITE_ADDR_TRIG_CH9_AL2_WRITE_ADDR_TRIG_0       (0x1U<<0U)

// CH9_AL3_CTRL Configuration

#define DMA_CH9_AL3_CTRL_CH9_AL3_CTRL                               (0xFFFFFFFFU<<0U)
#define DMA_CH9_AL3_CTRL_CH9_AL3_CTRL_0                             (0x1U<<0U)

// CH9_AL3_WRITE_ADDR Configuration

#define DMA_CH9_AL3_WRITE_ADDR_CH9_AL3_WRITE_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH9_AL3_WRITE_ADDR_CH9_AL3_WRITE_ADDR_0                 (0x1U<<0U)

// CH9_AL3_TRANS_COUNT Configuration

#define DMA_CH9_AL3_TRANS_COUNT_CH9_AL3_TRANS_COUNT                 (0xFFFFFFFFU<<0U)
#define DMA_CH9_AL3_TRANS_COUNT_CH9_AL3_TRANS_COUNT_0               (0x1U<<0U)

// CH9_AL3_READ_ADDR_TRIG Configuration

#define DMA_CH9_AL3_READ_ADDR_TRIG_CH9_AL3_READ_ADDR_TRIG           (0xFFFFFFFFU<<0U)
#define DMA_CH9_AL3_READ_ADDR_TRIG_CH9_AL3_READ_ADDR_TRIG_0         (0x1U<<0U)

// CH10_READ_ADDR Configuration

#define DMA_CH10_READ_ADDR_CH10_READ_ADDR                           (0xFFFFFFFFU<<0U)
#define DMA_CH10_READ_ADDR_CH10_READ_ADDR_0                         (0x1U<<0U)

// CH10_WRITE_ADDR Configuration

#define DMA_CH10_WRITE_ADDR_CH10_WRITE_ADDR                         (0xFFFFFFFFU<<0U)
#define DMA_CH10_WRITE_ADDR_CH10_WRITE_ADDR_0                       (0x1U<<0U)

// CH10_TRANS_COUNT Configuration

#define DMA_CH10_TRANS_COUNT_COUNT                                  (0xFFFFFFFU<<0U)
#define DMA_CH10_TRANS_COUNT_COUNT_0                                (0x1U<<0U)
#define DMA_CH10_TRANS_COUNT_MODE                                   (0xFU<<28U)
#define DMA_CH10_TRANS_COUNT_MODE_0                                 (0x1U<<28U)
#define DMA_CH10_TRANS_COUNT_MODE_NORMAL                            (0x0U<<28U)
#define DMA_CH10_TRANS_COUNT_MODE_TRIGGER_SELF                      (0x1U<<28U)
#define DMA_CH10_TRANS_COUNT_MODE_ENDLESS                           (0xFU<<28U)

// CH10_CTRL_TRIG Configuration

#define DMA_CH10_CTRL_TRIG_EN                                       (0x1U<<0U)
#define DMA_CH10_CTRL_TRIG_HIGH_PRIORITY                            (0x1U<<1U)
#define DMA_CH10_CTRL_TRIG_DATA_SIZE                                (0x3U<<2U)
#define DMA_CH10_CTRL_TRIG_DATA_SIZE_0                              (0x1U<<2U)
#define DMA_CH10_CTRL_TRIG_INCR_READ                                (0x1U<<4U)
#define DMA_CH10_CTRL_TRIG_INCR_READ_REV                            (0x1U<<5U)
#define DMA_CH10_CTRL_TRIG_INCR_WRITE                               (0x1U<<6U)
#define DMA_CH10_CTRL_TRIG_INCR_WRITE_REV                           (0x1U<<7U)
#define DMA_CH10_CTRL_TRIG_RING_SIZE                                (0xFU<<8U)
#define DMA_CH10_CTRL_TRIG_RING_SIZE_0                              (0x1U<<8U)
#define DMA_CH10_CTRL_TRIG_RING_SEL                                 (0x1U<<12U)
#define DMA_CH10_CTRL_TRIG_CHAIN_TO                                 (0xFU<<13U)
#define DMA_CH10_CTRL_TRIG_CHAIN_TO_0                               (0x1U<<13U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL                                 (0x3FU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_0                               (0x1U<<17U)
#define DMA_CH10_CTRL_TRIG_IRQ_QUIET                                (0x1U<<23U)
#define DMA_CH10_CTRL_TRIG_BSWAP                                    (0x1U<<24U)
#define DMA_CH10_CTRL_TRIG_SNIFF_EN                                 (0x1U<<25U)
#define DMA_CH10_CTRL_TRIG_BUSY                                     (0x1U<<26U)
#define DMA_CH10_CTRL_TRIG_WRITE_ERROR                              (0x1U<<29U)
#define DMA_CH10_CTRL_TRIG_READ_ERROR                               (0x1U<<30U)
#define DMA_CH10_CTRL_TRIG_AHB_ERROR                                (0x1U<<31U)
#define DMA_CH10_CTRL_TRIG_DATA_SIZE_SIZE_BYTE                      (0x0U<<2U)
#define DMA_CH10_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD                  (0x1U<<2U)
#define DMA_CH10_CTRL_TRIG_DATA_SIZE_SIZE_WORD                      (0x2U<<2U)
#define DMA_CH10_CTRL_TRIG_RING_SIZE_RING_NONE                      (0x0U<<8U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO0_TX0                        (0x0U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO0_TX1                        (0x1U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO0_TX2                        (0x2U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO0_TX3                        (0x3U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO0_RX0                        (0x4U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO0_RX1                        (0x5U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO0_RX2                        (0x6U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO0_RX3                        (0x7U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO1_TX0                        (0x8U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO1_TX1                        (0x9U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO1_TX2                        (0xAU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO1_TX3                        (0xBU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO1_RX0                        (0xCU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO1_RX1                        (0xDU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO1_RX2                        (0xEU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO1_RX3                        (0xFU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO2_TX0                        (0x10U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO2_TX1                        (0x11U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO2_TX2                        (0x12U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO2_TX3                        (0x13U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO2_RX0                        (0x14U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO2_RX1                        (0x15U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO2_RX2                        (0x16U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PIO2_RX3                        (0x17U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_SPI0_TX                         (0x18U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_SPI0_RX                         (0x19U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_SPI1_TX                         (0x1AU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_SPI1_RX                         (0x1BU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_UART0_TX                        (0x1CU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_UART0_RX                        (0x1DU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_UART1_TX                        (0x1EU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_UART1_RX                        (0x1FU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PWM_WRAP0                       (0x20U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PWM_WRAP1                       (0x21U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PWM_WRAP2                       (0x22U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PWM_WRAP3                       (0x23U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PWM_WRAP4                       (0x24U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PWM_WRAP5                       (0x25U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PWM_WRAP6                       (0x26U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PWM_WRAP7                       (0x27U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PWM_WRAP8                       (0x28U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PWM_WRAP9                       (0x29U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PWM_WRAP10                      (0x2AU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PWM_WRAP11                      (0x2BU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_I2C0_TX                         (0x2CU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_I2C0_RX                         (0x2DU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_I2C1_TX                         (0x2EU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_I2C1_RX                         (0x2FU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_ADC                             (0x30U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_XIP_STREAM                      (0x31U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_XIP_QMITX                       (0x32U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_XIP_QMIRX                       (0x33U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_HSTX                            (0x34U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_CORESIGHT                       (0x35U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_SHA256                          (0x36U<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_TIMER0                          (0x3BU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_TIMER1                          (0x3CU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_TIMER2                          (0x3DU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_TIMER3                          (0x3EU<<17U)
#define DMA_CH10_CTRL_TRIG_TREQ_SEL_PERMANENT                       (0x3FU<<17U)

// CH10_AL1_CTRL Configuration

#define DMA_CH10_AL1_CTRL_CH10_AL1_CTRL                             (0xFFFFFFFFU<<0U)
#define DMA_CH10_AL1_CTRL_CH10_AL1_CTRL_0                           (0x1U<<0U)

// CH10_AL1_READ_ADDR Configuration

#define DMA_CH10_AL1_READ_ADDR_CH10_AL1_READ_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH10_AL1_READ_ADDR_CH10_AL1_READ_ADDR_0                 (0x1U<<0U)

// CH10_AL1_WRITE_ADDR Configuration

#define DMA_CH10_AL1_WRITE_ADDR_CH10_AL1_WRITE_ADDR                 (0xFFFFFFFFU<<0U)
#define DMA_CH10_AL1_WRITE_ADDR_CH10_AL1_WRITE_ADDR_0               (0x1U<<0U)

// CH10_AL1_TRANS_COUNT_TRIG Configuration

#define DMA_CH10_AL1_TRANS_COUNT_TRIG_CH10_AL1_TRANS_COUNT_TRIG     (0xFFFFFFFFU<<0U)
#define DMA_CH10_AL1_TRANS_COUNT_TRIG_CH10_AL1_TRANS_COUNT_TRIG_0   (0x1U<<0U)

// CH10_AL2_CTRL Configuration

#define DMA_CH10_AL2_CTRL_CH10_AL2_CTRL                             (0xFFFFFFFFU<<0U)
#define DMA_CH10_AL2_CTRL_CH10_AL2_CTRL_0                           (0x1U<<0U)

// CH10_AL2_TRANS_COUNT Configuration

#define DMA_CH10_AL2_TRANS_COUNT_CH10_AL2_TRANS_COUNT               (0xFFFFFFFFU<<0U)
#define DMA_CH10_AL2_TRANS_COUNT_CH10_AL2_TRANS_COUNT_0             (0x1U<<0U)

// CH10_AL2_READ_ADDR Configuration

#define DMA_CH10_AL2_READ_ADDR_CH10_AL2_READ_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH10_AL2_READ_ADDR_CH10_AL2_READ_ADDR_0                 (0x1U<<0U)

// CH10_AL2_WRITE_ADDR_TRIG Configuration

#define DMA_CH10_AL2_WRITE_ADDR_TRIG_CH10_AL2_WRITE_ADDR_TRIG       (0xFFFFFFFFU<<0U)
#define DMA_CH10_AL2_WRITE_ADDR_TRIG_CH10_AL2_WRITE_ADDR_TRIG_0     (0x1U<<0U)

// CH10_AL3_CTRL Configuration

#define DMA_CH10_AL3_CTRL_CH10_AL3_CTRL                             (0xFFFFFFFFU<<0U)
#define DMA_CH10_AL3_CTRL_CH10_AL3_CTRL_0                           (0x1U<<0U)

// CH10_AL3_WRITE_ADDR Configuration

#define DMA_CH10_AL3_WRITE_ADDR_CH10_AL3_WRITE_ADDR                 (0xFFFFFFFFU<<0U)
#define DMA_CH10_AL3_WRITE_ADDR_CH10_AL3_WRITE_ADDR_0               (0x1U<<0U)

// CH10_AL3_TRANS_COUNT Configuration

#define DMA_CH10_AL3_TRANS_COUNT_CH10_AL3_TRANS_COUNT               (0xFFFFFFFFU<<0U)
#define DMA_CH10_AL3_TRANS_COUNT_CH10_AL3_TRANS_COUNT_0             (0x1U<<0U)

// CH10_AL3_READ_ADDR_TRIG Configuration

#define DMA_CH10_AL3_READ_ADDR_TRIG_CH10_AL3_READ_ADDR_TRIG         (0xFFFFFFFFU<<0U)
#define DMA_CH10_AL3_READ_ADDR_TRIG_CH10_AL3_READ_ADDR_TRIG_0       (0x1U<<0U)

// CH11_READ_ADDR Configuration

#define DMA_CH11_READ_ADDR_CH11_READ_ADDR                           (0xFFFFFFFFU<<0U)
#define DMA_CH11_READ_ADDR_CH11_READ_ADDR_0                         (0x1U<<0U)

// CH11_WRITE_ADDR Configuration

#define DMA_CH11_WRITE_ADDR_CH11_WRITE_ADDR                         (0xFFFFFFFFU<<0U)
#define DMA_CH11_WRITE_ADDR_CH11_WRITE_ADDR_0                       (0x1U<<0U)

// CH11_TRANS_COUNT Configuration

#define DMA_CH11_TRANS_COUNT_COUNT                                  (0xFFFFFFFU<<0U)
#define DMA_CH11_TRANS_COUNT_COUNT_0                                (0x1U<<0U)
#define DMA_CH11_TRANS_COUNT_MODE                                   (0xFU<<28U)
#define DMA_CH11_TRANS_COUNT_MODE_0                                 (0x1U<<28U)
#define DMA_CH11_TRANS_COUNT_MODE_NORMAL                            (0x0U<<28U)
#define DMA_CH11_TRANS_COUNT_MODE_TRIGGER_SELF                      (0x1U<<28U)
#define DMA_CH11_TRANS_COUNT_MODE_ENDLESS                           (0xFU<<28U)

// CH11_CTRL_TRIG Configuration

#define DMA_CH11_CTRL_TRIG_EN                                       (0x1U<<0U)
#define DMA_CH11_CTRL_TRIG_HIGH_PRIORITY                            (0x1U<<1U)
#define DMA_CH11_CTRL_TRIG_DATA_SIZE                                (0x3U<<2U)
#define DMA_CH11_CTRL_TRIG_DATA_SIZE_0                              (0x1U<<2U)
#define DMA_CH11_CTRL_TRIG_INCR_READ                                (0x1U<<4U)
#define DMA_CH11_CTRL_TRIG_INCR_READ_REV                            (0x1U<<5U)
#define DMA_CH11_CTRL_TRIG_INCR_WRITE                               (0x1U<<6U)
#define DMA_CH11_CTRL_TRIG_INCR_WRITE_REV                           (0x1U<<7U)
#define DMA_CH11_CTRL_TRIG_RING_SIZE                                (0xFU<<8U)
#define DMA_CH11_CTRL_TRIG_RING_SIZE_0                              (0x1U<<8U)
#define DMA_CH11_CTRL_TRIG_RING_SEL                                 (0x1U<<12U)
#define DMA_CH11_CTRL_TRIG_CHAIN_TO                                 (0xFU<<13U)
#define DMA_CH11_CTRL_TRIG_CHAIN_TO_0                               (0x1U<<13U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL                                 (0x3FU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_0                               (0x1U<<17U)
#define DMA_CH11_CTRL_TRIG_IRQ_QUIET                                (0x1U<<23U)
#define DMA_CH11_CTRL_TRIG_BSWAP                                    (0x1U<<24U)
#define DMA_CH11_CTRL_TRIG_SNIFF_EN                                 (0x1U<<25U)
#define DMA_CH11_CTRL_TRIG_BUSY                                     (0x1U<<26U)
#define DMA_CH11_CTRL_TRIG_WRITE_ERROR                              (0x1U<<29U)
#define DMA_CH11_CTRL_TRIG_READ_ERROR                               (0x1U<<30U)
#define DMA_CH11_CTRL_TRIG_AHB_ERROR                                (0x1U<<31U)
#define DMA_CH11_CTRL_TRIG_DATA_SIZE_SIZE_BYTE                      (0x0U<<2U)
#define DMA_CH11_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD                  (0x1U<<2U)
#define DMA_CH11_CTRL_TRIG_DATA_SIZE_SIZE_WORD                      (0x2U<<2U)
#define DMA_CH11_CTRL_TRIG_RING_SIZE_RING_NONE                      (0x0U<<8U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO0_TX0                        (0x0U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO0_TX1                        (0x1U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO0_TX2                        (0x2U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO0_TX3                        (0x3U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO0_RX0                        (0x4U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO0_RX1                        (0x5U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO0_RX2                        (0x6U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO0_RX3                        (0x7U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO1_TX0                        (0x8U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO1_TX1                        (0x9U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO1_TX2                        (0xAU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO1_TX3                        (0xBU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO1_RX0                        (0xCU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO1_RX1                        (0xDU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO1_RX2                        (0xEU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO1_RX3                        (0xFU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO2_TX0                        (0x10U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO2_TX1                        (0x11U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO2_TX2                        (0x12U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO2_TX3                        (0x13U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO2_RX0                        (0x14U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO2_RX1                        (0x15U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO2_RX2                        (0x16U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PIO2_RX3                        (0x17U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_SPI0_TX                         (0x18U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_SPI0_RX                         (0x19U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_SPI1_TX                         (0x1AU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_SPI1_RX                         (0x1BU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_UART0_TX                        (0x1CU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_UART0_RX                        (0x1DU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_UART1_TX                        (0x1EU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_UART1_RX                        (0x1FU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PWM_WRAP0                       (0x20U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PWM_WRAP1                       (0x21U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PWM_WRAP2                       (0x22U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PWM_WRAP3                       (0x23U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PWM_WRAP4                       (0x24U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PWM_WRAP5                       (0x25U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PWM_WRAP6                       (0x26U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PWM_WRAP7                       (0x27U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PWM_WRAP8                       (0x28U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PWM_WRAP9                       (0x29U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PWM_WRAP10                      (0x2AU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PWM_WRAP11                      (0x2BU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_I2C0_TX                         (0x2CU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_I2C0_RX                         (0x2DU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_I2C1_TX                         (0x2EU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_I2C1_RX                         (0x2FU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_ADC                             (0x30U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_XIP_STREAM                      (0x31U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_XIP_QMITX                       (0x32U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_XIP_QMIRX                       (0x33U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_HSTX                            (0x34U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_CORESIGHT                       (0x35U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_SHA256                          (0x36U<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_TIMER0                          (0x3BU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_TIMER1                          (0x3CU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_TIMER2                          (0x3DU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_TIMER3                          (0x3EU<<17U)
#define DMA_CH11_CTRL_TRIG_TREQ_SEL_PERMANENT                       (0x3FU<<17U)

// CH11_AL1_CTRL Configuration

#define DMA_CH11_AL1_CTRL_CH11_AL1_CTRL                             (0xFFFFFFFFU<<0U)
#define DMA_CH11_AL1_CTRL_CH11_AL1_CTRL_0                           (0x1U<<0U)

// CH11_AL1_READ_ADDR Configuration

#define DMA_CH11_AL1_READ_ADDR_CH11_AL1_READ_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH11_AL1_READ_ADDR_CH11_AL1_READ_ADDR_0                 (0x1U<<0U)

// CH11_AL1_WRITE_ADDR Configuration

#define DMA_CH11_AL1_WRITE_ADDR_CH11_AL1_WRITE_ADDR                 (0xFFFFFFFFU<<0U)
#define DMA_CH11_AL1_WRITE_ADDR_CH11_AL1_WRITE_ADDR_0               (0x1U<<0U)

// CH11_AL1_TRANS_COUNT_TRIG Configuration

#define DMA_CH11_AL1_TRANS_COUNT_TRIG_CH11_AL1_TRANS_COUNT_TRIG     (0xFFFFFFFFU<<0U)
#define DMA_CH11_AL1_TRANS_COUNT_TRIG_CH11_AL1_TRANS_COUNT_TRIG_0   (0x1U<<0U)

// CH11_AL2_CTRL Configuration

#define DMA_CH11_AL2_CTRL_CH11_AL2_CTRL                             (0xFFFFFFFFU<<0U)
#define DMA_CH11_AL2_CTRL_CH11_AL2_CTRL_0                           (0x1U<<0U)

// CH11_AL2_TRANS_COUNT Configuration

#define DMA_CH11_AL2_TRANS_COUNT_CH11_AL2_TRANS_COUNT               (0xFFFFFFFFU<<0U)
#define DMA_CH11_AL2_TRANS_COUNT_CH11_AL2_TRANS_COUNT_0             (0x1U<<0U)

// CH11_AL2_READ_ADDR Configuration

#define DMA_CH11_AL2_READ_ADDR_CH11_AL2_READ_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH11_AL2_READ_ADDR_CH11_AL2_READ_ADDR_0                 (0x1U<<0U)

// CH11_AL2_WRITE_ADDR_TRIG Configuration

#define DMA_CH11_AL2_WRITE_ADDR_TRIG_CH11_AL2_WRITE_ADDR_TRIG       (0xFFFFFFFFU<<0U)
#define DMA_CH11_AL2_WRITE_ADDR_TRIG_CH11_AL2_WRITE_ADDR_TRIG_0     (0x1U<<0U)

// CH11_AL3_CTRL Configuration

#define DMA_CH11_AL3_CTRL_CH11_AL3_CTRL                             (0xFFFFFFFFU<<0U)
#define DMA_CH11_AL3_CTRL_CH11_AL3_CTRL_0                           (0x1U<<0U)

// CH11_AL3_WRITE_ADDR Configuration

#define DMA_CH11_AL3_WRITE_ADDR_CH11_AL3_WRITE_ADDR                 (0xFFFFFFFFU<<0U)
#define DMA_CH11_AL3_WRITE_ADDR_CH11_AL3_WRITE_ADDR_0               (0x1U<<0U)

// CH11_AL3_TRANS_COUNT Configuration

#define DMA_CH11_AL3_TRANS_COUNT_CH11_AL3_TRANS_COUNT               (0xFFFFFFFFU<<0U)
#define DMA_CH11_AL3_TRANS_COUNT_CH11_AL3_TRANS_COUNT_0             (0x1U<<0U)

// CH11_AL3_READ_ADDR_TRIG Configuration

#define DMA_CH11_AL3_READ_ADDR_TRIG_CH11_AL3_READ_ADDR_TRIG         (0xFFFFFFFFU<<0U)
#define DMA_CH11_AL3_READ_ADDR_TRIG_CH11_AL3_READ_ADDR_TRIG_0       (0x1U<<0U)

// CH12_READ_ADDR Configuration

#define DMA_CH12_READ_ADDR_CH12_READ_ADDR                           (0xFFFFFFFFU<<0U)
#define DMA_CH12_READ_ADDR_CH12_READ_ADDR_0                         (0x1U<<0U)

// CH12_WRITE_ADDR Configuration

#define DMA_CH12_WRITE_ADDR_CH12_WRITE_ADDR                         (0xFFFFFFFFU<<0U)
#define DMA_CH12_WRITE_ADDR_CH12_WRITE_ADDR_0                       (0x1U<<0U)

// CH12_TRANS_COUNT Configuration

#define DMA_CH12_TRANS_COUNT_COUNT                                  (0xFFFFFFFU<<0U)
#define DMA_CH12_TRANS_COUNT_COUNT_0                                (0x1U<<0U)
#define DMA_CH12_TRANS_COUNT_MODE                                   (0xFU<<28U)
#define DMA_CH12_TRANS_COUNT_MODE_0                                 (0x1U<<28U)
#define DMA_CH12_TRANS_COUNT_MODE_NORMAL                            (0x0U<<28U)
#define DMA_CH12_TRANS_COUNT_MODE_TRIGGER_SELF                      (0x1U<<28U)
#define DMA_CH12_TRANS_COUNT_MODE_ENDLESS                           (0xFU<<28U)

// CH12_CTRL_TRIG Configuration

#define DMA_CH12_CTRL_TRIG_EN                                       (0x1U<<0U)
#define DMA_CH12_CTRL_TRIG_HIGH_PRIORITY                            (0x1U<<1U)
#define DMA_CH12_CTRL_TRIG_DATA_SIZE                                (0x3U<<2U)
#define DMA_CH12_CTRL_TRIG_DATA_SIZE_0                              (0x1U<<2U)
#define DMA_CH12_CTRL_TRIG_INCR_READ                                (0x1U<<4U)
#define DMA_CH12_CTRL_TRIG_INCR_READ_REV                            (0x1U<<5U)
#define DMA_CH12_CTRL_TRIG_INCR_WRITE                               (0x1U<<6U)
#define DMA_CH12_CTRL_TRIG_INCR_WRITE_REV                           (0x1U<<7U)
#define DMA_CH12_CTRL_TRIG_RING_SIZE                                (0xFU<<8U)
#define DMA_CH12_CTRL_TRIG_RING_SIZE_0                              (0x1U<<8U)
#define DMA_CH12_CTRL_TRIG_RING_SEL                                 (0x1U<<12U)
#define DMA_CH12_CTRL_TRIG_CHAIN_TO                                 (0xFU<<13U)
#define DMA_CH12_CTRL_TRIG_CHAIN_TO_0                               (0x1U<<13U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL                                 (0x3FU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_0                               (0x1U<<17U)
#define DMA_CH12_CTRL_TRIG_IRQ_QUIET                                (0x1U<<23U)
#define DMA_CH12_CTRL_TRIG_BSWAP                                    (0x1U<<24U)
#define DMA_CH12_CTRL_TRIG_SNIFF_EN                                 (0x1U<<25U)
#define DMA_CH12_CTRL_TRIG_BUSY                                     (0x1U<<26U)
#define DMA_CH12_CTRL_TRIG_WRITE_ERROR                              (0x1U<<29U)
#define DMA_CH12_CTRL_TRIG_READ_ERROR                               (0x1U<<30U)
#define DMA_CH12_CTRL_TRIG_AHB_ERROR                                (0x1U<<31U)
#define DMA_CH12_CTRL_TRIG_DATA_SIZE_SIZE_BYTE                      (0x0U<<2U)
#define DMA_CH12_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD                  (0x1U<<2U)
#define DMA_CH12_CTRL_TRIG_DATA_SIZE_SIZE_WORD                      (0x2U<<2U)
#define DMA_CH12_CTRL_TRIG_RING_SIZE_RING_NONE                      (0x0U<<8U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO0_TX0                        (0x0U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO0_TX1                        (0x1U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO0_TX2                        (0x2U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO0_TX3                        (0x3U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO0_RX0                        (0x4U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO0_RX1                        (0x5U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO0_RX2                        (0x6U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO0_RX3                        (0x7U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO1_TX0                        (0x8U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO1_TX1                        (0x9U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO1_TX2                        (0xAU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO1_TX3                        (0xBU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO1_RX0                        (0xCU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO1_RX1                        (0xDU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO1_RX2                        (0xEU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO1_RX3                        (0xFU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO2_TX0                        (0x10U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO2_TX1                        (0x11U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO2_TX2                        (0x12U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO2_TX3                        (0x13U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO2_RX0                        (0x14U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO2_RX1                        (0x15U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO2_RX2                        (0x16U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PIO2_RX3                        (0x17U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_SPI0_TX                         (0x18U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_SPI0_RX                         (0x19U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_SPI1_TX                         (0x1AU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_SPI1_RX                         (0x1BU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_UART0_TX                        (0x1CU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_UART0_RX                        (0x1DU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_UART1_TX                        (0x1EU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_UART1_RX                        (0x1FU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PWM_WRAP0                       (0x20U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PWM_WRAP1                       (0x21U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PWM_WRAP2                       (0x22U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PWM_WRAP3                       (0x23U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PWM_WRAP4                       (0x24U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PWM_WRAP5                       (0x25U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PWM_WRAP6                       (0x26U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PWM_WRAP7                       (0x27U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PWM_WRAP8                       (0x28U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PWM_WRAP9                       (0x29U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PWM_WRAP10                      (0x2AU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PWM_WRAP11                      (0x2BU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_I2C0_TX                         (0x2CU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_I2C0_RX                         (0x2DU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_I2C1_TX                         (0x2EU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_I2C1_RX                         (0x2FU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_ADC                             (0x30U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_XIP_STREAM                      (0x31U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_XIP_QMITX                       (0x32U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_XIP_QMIRX                       (0x33U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_HSTX                            (0x34U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_CORESIGHT                       (0x35U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_SHA256                          (0x36U<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_TIMER0                          (0x3BU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_TIMER1                          (0x3CU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_TIMER2                          (0x3DU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_TIMER3                          (0x3EU<<17U)
#define DMA_CH12_CTRL_TRIG_TREQ_SEL_PERMANENT                       (0x3FU<<17U)

// CH12_AL1_CTRL Configuration

#define DMA_CH12_AL1_CTRL_CH12_AL1_CTRL                             (0xFFFFFFFFU<<0U)
#define DMA_CH12_AL1_CTRL_CH12_AL1_CTRL_0                           (0x1U<<0U)

// CH12_AL1_READ_ADDR Configuration

#define DMA_CH12_AL1_READ_ADDR_CH12_AL1_READ_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH12_AL1_READ_ADDR_CH12_AL1_READ_ADDR_0                 (0x1U<<0U)

// CH12_AL1_WRITE_ADDR Configuration

#define DMA_CH12_AL1_WRITE_ADDR_CH12_AL1_WRITE_ADDR                 (0xFFFFFFFFU<<0U)
#define DMA_CH12_AL1_WRITE_ADDR_CH12_AL1_WRITE_ADDR_0               (0x1U<<0U)

// CH12_AL1_TRANS_COUNT_TRIG Configuration

#define DMA_CH12_AL1_TRANS_COUNT_TRIG_CH12_AL1_TRANS_COUNT_TRIG     (0xFFFFFFFFU<<0U)
#define DMA_CH12_AL1_TRANS_COUNT_TRIG_CH12_AL1_TRANS_COUNT_TRIG_0   (0x1U<<0U)

// CH12_AL2_CTRL Configuration

#define DMA_CH12_AL2_CTRL_CH12_AL2_CTRL                             (0xFFFFFFFFU<<0U)
#define DMA_CH12_AL2_CTRL_CH12_AL2_CTRL_0                           (0x1U<<0U)

// CH12_AL2_TRANS_COUNT Configuration

#define DMA_CH12_AL2_TRANS_COUNT_CH12_AL2_TRANS_COUNT               (0xFFFFFFFFU<<0U)
#define DMA_CH12_AL2_TRANS_COUNT_CH12_AL2_TRANS_COUNT_0             (0x1U<<0U)

// CH12_AL2_READ_ADDR Configuration

#define DMA_CH12_AL2_READ_ADDR_CH12_AL2_READ_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH12_AL2_READ_ADDR_CH12_AL2_READ_ADDR_0                 (0x1U<<0U)

// CH12_AL2_WRITE_ADDR_TRIG Configuration

#define DMA_CH12_AL2_WRITE_ADDR_TRIG_CH12_AL2_WRITE_ADDR_TRIG       (0xFFFFFFFFU<<0U)
#define DMA_CH12_AL2_WRITE_ADDR_TRIG_CH12_AL2_WRITE_ADDR_TRIG_0     (0x1U<<0U)

// CH12_AL3_CTRL Configuration

#define DMA_CH12_AL3_CTRL_CH12_AL3_CTRL                             (0xFFFFFFFFU<<0U)
#define DMA_CH12_AL3_CTRL_CH12_AL3_CTRL_0                           (0x1U<<0U)

// CH12_AL3_WRITE_ADDR Configuration

#define DMA_CH12_AL3_WRITE_ADDR_CH12_AL3_WRITE_ADDR                 (0xFFFFFFFFU<<0U)
#define DMA_CH12_AL3_WRITE_ADDR_CH12_AL3_WRITE_ADDR_0               (0x1U<<0U)

// CH12_AL3_TRANS_COUNT Configuration

#define DMA_CH12_AL3_TRANS_COUNT_CH12_AL3_TRANS_COUNT               (0xFFFFFFFFU<<0U)
#define DMA_CH12_AL3_TRANS_COUNT_CH12_AL3_TRANS_COUNT_0             (0x1U<<0U)

// CH12_AL3_READ_ADDR_TRIG Configuration

#define DMA_CH12_AL3_READ_ADDR_TRIG_CH12_AL3_READ_ADDR_TRIG         (0xFFFFFFFFU<<0U)
#define DMA_CH12_AL3_READ_ADDR_TRIG_CH12_AL3_READ_ADDR_TRIG_0       (0x1U<<0U)

// CH13_READ_ADDR Configuration

#define DMA_CH13_READ_ADDR_CH13_READ_ADDR                           (0xFFFFFFFFU<<0U)
#define DMA_CH13_READ_ADDR_CH13_READ_ADDR_0                         (0x1U<<0U)

// CH13_WRITE_ADDR Configuration

#define DMA_CH13_WRITE_ADDR_CH13_WRITE_ADDR                         (0xFFFFFFFFU<<0U)
#define DMA_CH13_WRITE_ADDR_CH13_WRITE_ADDR_0                       (0x1U<<0U)

// CH13_TRANS_COUNT Configuration

#define DMA_CH13_TRANS_COUNT_COUNT                                  (0xFFFFFFFU<<0U)
#define DMA_CH13_TRANS_COUNT_COUNT_0                                (0x1U<<0U)
#define DMA_CH13_TRANS_COUNT_MODE                                   (0xFU<<28U)
#define DMA_CH13_TRANS_COUNT_MODE_0                                 (0x1U<<28U)
#define DMA_CH13_TRANS_COUNT_MODE_NORMAL                            (0x0U<<28U)
#define DMA_CH13_TRANS_COUNT_MODE_TRIGGER_SELF                      (0x1U<<28U)
#define DMA_CH13_TRANS_COUNT_MODE_ENDLESS                           (0xFU<<28U)

// CH13_CTRL_TRIG Configuration

#define DMA_CH13_CTRL_TRIG_EN                                       (0x1U<<0U)
#define DMA_CH13_CTRL_TRIG_HIGH_PRIORITY                            (0x1U<<1U)
#define DMA_CH13_CTRL_TRIG_DATA_SIZE                                (0x3U<<2U)
#define DMA_CH13_CTRL_TRIG_DATA_SIZE_0                              (0x1U<<2U)
#define DMA_CH13_CTRL_TRIG_INCR_READ                                (0x1U<<4U)
#define DMA_CH13_CTRL_TRIG_INCR_READ_REV                            (0x1U<<5U)
#define DMA_CH13_CTRL_TRIG_INCR_WRITE                               (0x1U<<6U)
#define DMA_CH13_CTRL_TRIG_INCR_WRITE_REV                           (0x1U<<7U)
#define DMA_CH13_CTRL_TRIG_RING_SIZE                                (0xFU<<8U)
#define DMA_CH13_CTRL_TRIG_RING_SIZE_0                              (0x1U<<8U)
#define DMA_CH13_CTRL_TRIG_RING_SEL                                 (0x1U<<12U)
#define DMA_CH13_CTRL_TRIG_CHAIN_TO                                 (0xFU<<13U)
#define DMA_CH13_CTRL_TRIG_CHAIN_TO_0                               (0x1U<<13U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL                                 (0x3FU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_0                               (0x1U<<17U)
#define DMA_CH13_CTRL_TRIG_IRQ_QUIET                                (0x1U<<23U)
#define DMA_CH13_CTRL_TRIG_BSWAP                                    (0x1U<<24U)
#define DMA_CH13_CTRL_TRIG_SNIFF_EN                                 (0x1U<<25U)
#define DMA_CH13_CTRL_TRIG_BUSY                                     (0x1U<<26U)
#define DMA_CH13_CTRL_TRIG_WRITE_ERROR                              (0x1U<<29U)
#define DMA_CH13_CTRL_TRIG_READ_ERROR                               (0x1U<<30U)
#define DMA_CH13_CTRL_TRIG_AHB_ERROR                                (0x1U<<31U)
#define DMA_CH13_CTRL_TRIG_DATA_SIZE_SIZE_BYTE                      (0x0U<<2U)
#define DMA_CH13_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD                  (0x1U<<2U)
#define DMA_CH13_CTRL_TRIG_DATA_SIZE_SIZE_WORD                      (0x2U<<2U)
#define DMA_CH13_CTRL_TRIG_RING_SIZE_RING_NONE                      (0x0U<<8U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO0_TX0                        (0x0U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO0_TX1                        (0x1U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO0_TX2                        (0x2U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO0_TX3                        (0x3U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO0_RX0                        (0x4U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO0_RX1                        (0x5U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO0_RX2                        (0x6U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO0_RX3                        (0x7U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO1_TX0                        (0x8U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO1_TX1                        (0x9U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO1_TX2                        (0xAU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO1_TX3                        (0xBU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO1_RX0                        (0xCU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO1_RX1                        (0xDU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO1_RX2                        (0xEU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO1_RX3                        (0xFU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO2_TX0                        (0x10U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO2_TX1                        (0x11U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO2_TX2                        (0x12U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO2_TX3                        (0x13U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO2_RX0                        (0x14U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO2_RX1                        (0x15U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO2_RX2                        (0x16U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PIO2_RX3                        (0x17U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_SPI0_TX                         (0x18U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_SPI0_RX                         (0x19U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_SPI1_TX                         (0x1AU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_SPI1_RX                         (0x1BU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_UART0_TX                        (0x1CU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_UART0_RX                        (0x1DU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_UART1_TX                        (0x1EU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_UART1_RX                        (0x1FU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PWM_WRAP0                       (0x20U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PWM_WRAP1                       (0x21U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PWM_WRAP2                       (0x22U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PWM_WRAP3                       (0x23U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PWM_WRAP4                       (0x24U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PWM_WRAP5                       (0x25U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PWM_WRAP6                       (0x26U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PWM_WRAP7                       (0x27U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PWM_WRAP8                       (0x28U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PWM_WRAP9                       (0x29U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PWM_WRAP10                      (0x2AU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PWM_WRAP11                      (0x2BU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_I2C0_TX                         (0x2CU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_I2C0_RX                         (0x2DU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_I2C1_TX                         (0x2EU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_I2C1_RX                         (0x2FU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_ADC                             (0x30U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_XIP_STREAM                      (0x31U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_XIP_QMITX                       (0x32U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_XIP_QMIRX                       (0x33U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_HSTX                            (0x34U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_CORESIGHT                       (0x35U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_SHA256                          (0x36U<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_TIMER0                          (0x3BU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_TIMER1                          (0x3CU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_TIMER2                          (0x3DU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_TIMER3                          (0x3EU<<17U)
#define DMA_CH13_CTRL_TRIG_TREQ_SEL_PERMANENT                       (0x3FU<<17U)

// CH13_AL1_CTRL Configuration

#define DMA_CH13_AL1_CTRL_CH13_AL1_CTRL                             (0xFFFFFFFFU<<0U)
#define DMA_CH13_AL1_CTRL_CH13_AL1_CTRL_0                           (0x1U<<0U)

// CH13_AL1_READ_ADDR Configuration

#define DMA_CH13_AL1_READ_ADDR_CH13_AL1_READ_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH13_AL1_READ_ADDR_CH13_AL1_READ_ADDR_0                 (0x1U<<0U)

// CH13_AL1_WRITE_ADDR Configuration

#define DMA_CH13_AL1_WRITE_ADDR_CH13_AL1_WRITE_ADDR                 (0xFFFFFFFFU<<0U)
#define DMA_CH13_AL1_WRITE_ADDR_CH13_AL1_WRITE_ADDR_0               (0x1U<<0U)

// CH13_AL1_TRANS_COUNT_TRIG Configuration

#define DMA_CH13_AL1_TRANS_COUNT_TRIG_CH13_AL1_TRANS_COUNT_TRIG     (0xFFFFFFFFU<<0U)
#define DMA_CH13_AL1_TRANS_COUNT_TRIG_CH13_AL1_TRANS_COUNT_TRIG_0   (0x1U<<0U)

// CH13_AL2_CTRL Configuration

#define DMA_CH13_AL2_CTRL_CH13_AL2_CTRL                             (0xFFFFFFFFU<<0U)
#define DMA_CH13_AL2_CTRL_CH13_AL2_CTRL_0                           (0x1U<<0U)

// CH13_AL2_TRANS_COUNT Configuration

#define DMA_CH13_AL2_TRANS_COUNT_CH13_AL2_TRANS_COUNT               (0xFFFFFFFFU<<0U)
#define DMA_CH13_AL2_TRANS_COUNT_CH13_AL2_TRANS_COUNT_0             (0x1U<<0U)

// CH13_AL2_READ_ADDR Configuration

#define DMA_CH13_AL2_READ_ADDR_CH13_AL2_READ_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH13_AL2_READ_ADDR_CH13_AL2_READ_ADDR_0                 (0x1U<<0U)

// CH13_AL2_WRITE_ADDR_TRIG Configuration

#define DMA_CH13_AL2_WRITE_ADDR_TRIG_CH13_AL2_WRITE_ADDR_TRIG       (0xFFFFFFFFU<<0U)
#define DMA_CH13_AL2_WRITE_ADDR_TRIG_CH13_AL2_WRITE_ADDR_TRIG_0     (0x1U<<0U)

// CH13_AL3_CTRL Configuration

#define DMA_CH13_AL3_CTRL_CH13_AL3_CTRL                             (0xFFFFFFFFU<<0U)
#define DMA_CH13_AL3_CTRL_CH13_AL3_CTRL_0                           (0x1U<<0U)

// CH13_AL3_WRITE_ADDR Configuration

#define DMA_CH13_AL3_WRITE_ADDR_CH13_AL3_WRITE_ADDR                 (0xFFFFFFFFU<<0U)
#define DMA_CH13_AL3_WRITE_ADDR_CH13_AL3_WRITE_ADDR_0               (0x1U<<0U)

// CH13_AL3_TRANS_COUNT Configuration

#define DMA_CH13_AL3_TRANS_COUNT_CH13_AL3_TRANS_COUNT               (0xFFFFFFFFU<<0U)
#define DMA_CH13_AL3_TRANS_COUNT_CH13_AL3_TRANS_COUNT_0             (0x1U<<0U)

// CH13_AL3_READ_ADDR_TRIG Configuration

#define DMA_CH13_AL3_READ_ADDR_TRIG_CH13_AL3_READ_ADDR_TRIG         (0xFFFFFFFFU<<0U)
#define DMA_CH13_AL3_READ_ADDR_TRIG_CH13_AL3_READ_ADDR_TRIG_0       (0x1U<<0U)

// CH14_READ_ADDR Configuration

#define DMA_CH14_READ_ADDR_CH14_READ_ADDR                           (0xFFFFFFFFU<<0U)
#define DMA_CH14_READ_ADDR_CH14_READ_ADDR_0                         (0x1U<<0U)

// CH14_WRITE_ADDR Configuration

#define DMA_CH14_WRITE_ADDR_CH14_WRITE_ADDR                         (0xFFFFFFFFU<<0U)
#define DMA_CH14_WRITE_ADDR_CH14_WRITE_ADDR_0                       (0x1U<<0U)

// CH14_TRANS_COUNT Configuration

#define DMA_CH14_TRANS_COUNT_COUNT                                  (0xFFFFFFFU<<0U)
#define DMA_CH14_TRANS_COUNT_COUNT_0                                (0x1U<<0U)
#define DMA_CH14_TRANS_COUNT_MODE                                   (0xFU<<28U)
#define DMA_CH14_TRANS_COUNT_MODE_0                                 (0x1U<<28U)
#define DMA_CH14_TRANS_COUNT_MODE_NORMAL                            (0x0U<<28U)
#define DMA_CH14_TRANS_COUNT_MODE_TRIGGER_SELF                      (0x1U<<28U)
#define DMA_CH14_TRANS_COUNT_MODE_ENDLESS                           (0xFU<<28U)

// CH14_CTRL_TRIG Configuration

#define DMA_CH14_CTRL_TRIG_EN                                       (0x1U<<0U)
#define DMA_CH14_CTRL_TRIG_HIGH_PRIORITY                            (0x1U<<1U)
#define DMA_CH14_CTRL_TRIG_DATA_SIZE                                (0x3U<<2U)
#define DMA_CH14_CTRL_TRIG_DATA_SIZE_0                              (0x1U<<2U)
#define DMA_CH14_CTRL_TRIG_INCR_READ                                (0x1U<<4U)
#define DMA_CH14_CTRL_TRIG_INCR_READ_REV                            (0x1U<<5U)
#define DMA_CH14_CTRL_TRIG_INCR_WRITE                               (0x1U<<6U)
#define DMA_CH14_CTRL_TRIG_INCR_WRITE_REV                           (0x1U<<7U)
#define DMA_CH14_CTRL_TRIG_RING_SIZE                                (0xFU<<8U)
#define DMA_CH14_CTRL_TRIG_RING_SIZE_0                              (0x1U<<8U)
#define DMA_CH14_CTRL_TRIG_RING_SEL                                 (0x1U<<12U)
#define DMA_CH14_CTRL_TRIG_CHAIN_TO                                 (0xFU<<13U)
#define DMA_CH14_CTRL_TRIG_CHAIN_TO_0                               (0x1U<<13U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL                                 (0x3FU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_0                               (0x1U<<17U)
#define DMA_CH14_CTRL_TRIG_IRQ_QUIET                                (0x1U<<23U)
#define DMA_CH14_CTRL_TRIG_BSWAP                                    (0x1U<<24U)
#define DMA_CH14_CTRL_TRIG_SNIFF_EN                                 (0x1U<<25U)
#define DMA_CH14_CTRL_TRIG_BUSY                                     (0x1U<<26U)
#define DMA_CH14_CTRL_TRIG_WRITE_ERROR                              (0x1U<<29U)
#define DMA_CH14_CTRL_TRIG_READ_ERROR                               (0x1U<<30U)
#define DMA_CH14_CTRL_TRIG_AHB_ERROR                                (0x1U<<31U)
#define DMA_CH14_CTRL_TRIG_DATA_SIZE_SIZE_BYTE                      (0x0U<<2U)
#define DMA_CH14_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD                  (0x1U<<2U)
#define DMA_CH14_CTRL_TRIG_DATA_SIZE_SIZE_WORD                      (0x2U<<2U)
#define DMA_CH14_CTRL_TRIG_RING_SIZE_RING_NONE                      (0x0U<<8U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO0_TX0                        (0x0U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO0_TX1                        (0x1U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO0_TX2                        (0x2U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO0_TX3                        (0x3U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO0_RX0                        (0x4U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO0_RX1                        (0x5U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO0_RX2                        (0x6U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO0_RX3                        (0x7U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO1_TX0                        (0x8U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO1_TX1                        (0x9U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO1_TX2                        (0xAU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO1_TX3                        (0xBU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO1_RX0                        (0xCU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO1_RX1                        (0xDU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO1_RX2                        (0xEU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO1_RX3                        (0xFU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO2_TX0                        (0x10U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO2_TX1                        (0x11U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO2_TX2                        (0x12U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO2_TX3                        (0x13U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO2_RX0                        (0x14U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO2_RX1                        (0x15U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO2_RX2                        (0x16U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PIO2_RX3                        (0x17U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_SPI0_TX                         (0x18U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_SPI0_RX                         (0x19U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_SPI1_TX                         (0x1AU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_SPI1_RX                         (0x1BU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_UART0_TX                        (0x1CU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_UART0_RX                        (0x1DU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_UART1_TX                        (0x1EU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_UART1_RX                        (0x1FU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PWM_WRAP0                       (0x20U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PWM_WRAP1                       (0x21U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PWM_WRAP2                       (0x22U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PWM_WRAP3                       (0x23U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PWM_WRAP4                       (0x24U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PWM_WRAP5                       (0x25U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PWM_WRAP6                       (0x26U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PWM_WRAP7                       (0x27U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PWM_WRAP8                       (0x28U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PWM_WRAP9                       (0x29U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PWM_WRAP10                      (0x2AU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PWM_WRAP11                      (0x2BU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_I2C0_TX                         (0x2CU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_I2C0_RX                         (0x2DU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_I2C1_TX                         (0x2EU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_I2C1_RX                         (0x2FU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_ADC                             (0x30U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_XIP_STREAM                      (0x31U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_XIP_QMITX                       (0x32U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_XIP_QMIRX                       (0x33U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_HSTX                            (0x34U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_CORESIGHT                       (0x35U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_SHA256                          (0x36U<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_TIMER0                          (0x3BU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_TIMER1                          (0x3CU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_TIMER2                          (0x3DU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_TIMER3                          (0x3EU<<17U)
#define DMA_CH14_CTRL_TRIG_TREQ_SEL_PERMANENT                       (0x3FU<<17U)

// CH14_AL1_CTRL Configuration

#define DMA_CH14_AL1_CTRL_CH14_AL1_CTRL                             (0xFFFFFFFFU<<0U)
#define DMA_CH14_AL1_CTRL_CH14_AL1_CTRL_0                           (0x1U<<0U)

// CH14_AL1_READ_ADDR Configuration

#define DMA_CH14_AL1_READ_ADDR_CH14_AL1_READ_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH14_AL1_READ_ADDR_CH14_AL1_READ_ADDR_0                 (0x1U<<0U)

// CH14_AL1_WRITE_ADDR Configuration

#define DMA_CH14_AL1_WRITE_ADDR_CH14_AL1_WRITE_ADDR                 (0xFFFFFFFFU<<0U)
#define DMA_CH14_AL1_WRITE_ADDR_CH14_AL1_WRITE_ADDR_0               (0x1U<<0U)

// CH14_AL1_TRANS_COUNT_TRIG Configuration

#define DMA_CH14_AL1_TRANS_COUNT_TRIG_CH14_AL1_TRANS_COUNT_TRIG     (0xFFFFFFFFU<<0U)
#define DMA_CH14_AL1_TRANS_COUNT_TRIG_CH14_AL1_TRANS_COUNT_TRIG_0   (0x1U<<0U)

// CH14_AL2_CTRL Configuration

#define DMA_CH14_AL2_CTRL_CH14_AL2_CTRL                             (0xFFFFFFFFU<<0U)
#define DMA_CH14_AL2_CTRL_CH14_AL2_CTRL_0                           (0x1U<<0U)

// CH14_AL2_TRANS_COUNT Configuration

#define DMA_CH14_AL2_TRANS_COUNT_CH14_AL2_TRANS_COUNT               (0xFFFFFFFFU<<0U)
#define DMA_CH14_AL2_TRANS_COUNT_CH14_AL2_TRANS_COUNT_0             (0x1U<<0U)

// CH14_AL2_READ_ADDR Configuration

#define DMA_CH14_AL2_READ_ADDR_CH14_AL2_READ_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH14_AL2_READ_ADDR_CH14_AL2_READ_ADDR_0                 (0x1U<<0U)

// CH14_AL2_WRITE_ADDR_TRIG Configuration

#define DMA_CH14_AL2_WRITE_ADDR_TRIG_CH14_AL2_WRITE_ADDR_TRIG       (0xFFFFFFFFU<<0U)
#define DMA_CH14_AL2_WRITE_ADDR_TRIG_CH14_AL2_WRITE_ADDR_TRIG_0     (0x1U<<0U)

// CH14_AL3_CTRL Configuration

#define DMA_CH14_AL3_CTRL_CH14_AL3_CTRL                             (0xFFFFFFFFU<<0U)
#define DMA_CH14_AL3_CTRL_CH14_AL3_CTRL_0                           (0x1U<<0U)

// CH14_AL3_WRITE_ADDR Configuration

#define DMA_CH14_AL3_WRITE_ADDR_CH14_AL3_WRITE_ADDR                 (0xFFFFFFFFU<<0U)
#define DMA_CH14_AL3_WRITE_ADDR_CH14_AL3_WRITE_ADDR_0               (0x1U<<0U)

// CH14_AL3_TRANS_COUNT Configuration

#define DMA_CH14_AL3_TRANS_COUNT_CH14_AL3_TRANS_COUNT               (0xFFFFFFFFU<<0U)
#define DMA_CH14_AL3_TRANS_COUNT_CH14_AL3_TRANS_COUNT_0             (0x1U<<0U)

// CH14_AL3_READ_ADDR_TRIG Configuration

#define DMA_CH14_AL3_READ_ADDR_TRIG_CH14_AL3_READ_ADDR_TRIG         (0xFFFFFFFFU<<0U)
#define DMA_CH14_AL3_READ_ADDR_TRIG_CH14_AL3_READ_ADDR_TRIG_0       (0x1U<<0U)

// CH15_READ_ADDR Configuration

#define DMA_CH15_READ_ADDR_CH15_READ_ADDR                           (0xFFFFFFFFU<<0U)
#define DMA_CH15_READ_ADDR_CH15_READ_ADDR_0                         (0x1U<<0U)

// CH15_WRITE_ADDR Configuration

#define DMA_CH15_WRITE_ADDR_CH15_WRITE_ADDR                         (0xFFFFFFFFU<<0U)
#define DMA_CH15_WRITE_ADDR_CH15_WRITE_ADDR_0                       (0x1U<<0U)

// CH15_TRANS_COUNT Configuration

#define DMA_CH15_TRANS_COUNT_COUNT                                  (0xFFFFFFFU<<0U)
#define DMA_CH15_TRANS_COUNT_COUNT_0                                (0x1U<<0U)
#define DMA_CH15_TRANS_COUNT_MODE                                   (0xFU<<28U)
#define DMA_CH15_TRANS_COUNT_MODE_0                                 (0x1U<<28U)
#define DMA_CH15_TRANS_COUNT_MODE_NORMAL                            (0x0U<<28U)
#define DMA_CH15_TRANS_COUNT_MODE_TRIGGER_SELF                      (0x1U<<28U)
#define DMA_CH15_TRANS_COUNT_MODE_ENDLESS                           (0xFU<<28U)

// CH15_CTRL_TRIG Configuration

#define DMA_CH15_CTRL_TRIG_EN                                       (0x1U<<0U)
#define DMA_CH15_CTRL_TRIG_HIGH_PRIORITY                            (0x1U<<1U)
#define DMA_CH15_CTRL_TRIG_DATA_SIZE                                (0x3U<<2U)
#define DMA_CH15_CTRL_TRIG_DATA_SIZE_0                              (0x1U<<2U)
#define DMA_CH15_CTRL_TRIG_INCR_READ                                (0x1U<<4U)
#define DMA_CH15_CTRL_TRIG_INCR_READ_REV                            (0x1U<<5U)
#define DMA_CH15_CTRL_TRIG_INCR_WRITE                               (0x1U<<6U)
#define DMA_CH15_CTRL_TRIG_INCR_WRITE_REV                           (0x1U<<7U)
#define DMA_CH15_CTRL_TRIG_RING_SIZE                                (0xFU<<8U)
#define DMA_CH15_CTRL_TRIG_RING_SIZE_0                              (0x1U<<8U)
#define DMA_CH15_CTRL_TRIG_RING_SEL                                 (0x1U<<12U)
#define DMA_CH15_CTRL_TRIG_CHAIN_TO                                 (0xFU<<13U)
#define DMA_CH15_CTRL_TRIG_CHAIN_TO_0                               (0x1U<<13U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL                                 (0x3FU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_0                               (0x1U<<17U)
#define DMA_CH15_CTRL_TRIG_IRQ_QUIET                                (0x1U<<23U)
#define DMA_CH15_CTRL_TRIG_BSWAP                                    (0x1U<<24U)
#define DMA_CH15_CTRL_TRIG_SNIFF_EN                                 (0x1U<<25U)
#define DMA_CH15_CTRL_TRIG_BUSY                                     (0x1U<<26U)
#define DMA_CH15_CTRL_TRIG_WRITE_ERROR                              (0x1U<<29U)
#define DMA_CH15_CTRL_TRIG_READ_ERROR                               (0x1U<<30U)
#define DMA_CH15_CTRL_TRIG_AHB_ERROR                                (0x1U<<31U)
#define DMA_CH15_CTRL_TRIG_DATA_SIZE_SIZE_BYTE                      (0x0U<<2U)
#define DMA_CH15_CTRL_TRIG_DATA_SIZE_SIZE_HALFWORD                  (0x1U<<2U)
#define DMA_CH15_CTRL_TRIG_DATA_SIZE_SIZE_WORD                      (0x2U<<2U)
#define DMA_CH15_CTRL_TRIG_RING_SIZE_RING_NONE                      (0x0U<<8U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO0_TX0                        (0x0U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO0_TX1                        (0x1U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO0_TX2                        (0x2U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO0_TX3                        (0x3U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO0_RX0                        (0x4U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO0_RX1                        (0x5U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO0_RX2                        (0x6U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO0_RX3                        (0x7U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO1_TX0                        (0x8U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO1_TX1                        (0x9U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO1_TX2                        (0xAU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO1_TX3                        (0xBU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO1_RX0                        (0xCU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO1_RX1                        (0xDU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO1_RX2                        (0xEU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO1_RX3                        (0xFU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO2_TX0                        (0x10U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO2_TX1                        (0x11U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO2_TX2                        (0x12U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO2_TX3                        (0x13U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO2_RX0                        (0x14U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO2_RX1                        (0x15U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO2_RX2                        (0x16U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PIO2_RX3                        (0x17U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_SPI0_TX                         (0x18U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_SPI0_RX                         (0x19U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_SPI1_TX                         (0x1AU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_SPI1_RX                         (0x1BU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_UART0_TX                        (0x1CU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_UART0_RX                        (0x1DU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_UART1_TX                        (0x1EU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_UART1_RX                        (0x1FU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PWM_WRAP0                       (0x20U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PWM_WRAP1                       (0x21U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PWM_WRAP2                       (0x22U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PWM_WRAP3                       (0x23U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PWM_WRAP4                       (0x24U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PWM_WRAP5                       (0x25U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PWM_WRAP6                       (0x26U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PWM_WRAP7                       (0x27U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PWM_WRAP8                       (0x28U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PWM_WRAP9                       (0x29U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PWM_WRAP10                      (0x2AU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PWM_WRAP11                      (0x2BU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_I2C0_TX                         (0x2CU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_I2C0_RX                         (0x2DU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_I2C1_TX                         (0x2EU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_I2C1_RX                         (0x2FU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_ADC                             (0x30U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_XIP_STREAM                      (0x31U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_XIP_QMITX                       (0x32U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_XIP_QMIRX                       (0x33U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_HSTX                            (0x34U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_CORESIGHT                       (0x35U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_SHA256                          (0x36U<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_TIMER0                          (0x3BU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_TIMER1                          (0x3CU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_TIMER2                          (0x3DU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_TIMER3                          (0x3EU<<17U)
#define DMA_CH15_CTRL_TRIG_TREQ_SEL_PERMANENT                       (0x3FU<<17U)

// CH15_AL1_CTRL Configuration

#define DMA_CH15_AL1_CTRL_CH15_AL1_CTRL                             (0xFFFFFFFFU<<0U)
#define DMA_CH15_AL1_CTRL_CH15_AL1_CTRL_0                           (0x1U<<0U)

// CH15_AL1_READ_ADDR Configuration

#define DMA_CH15_AL1_READ_ADDR_CH15_AL1_READ_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH15_AL1_READ_ADDR_CH15_AL1_READ_ADDR_0                 (0x1U<<0U)

// CH15_AL1_WRITE_ADDR Configuration

#define DMA_CH15_AL1_WRITE_ADDR_CH15_AL1_WRITE_ADDR                 (0xFFFFFFFFU<<0U)
#define DMA_CH15_AL1_WRITE_ADDR_CH15_AL1_WRITE_ADDR_0               (0x1U<<0U)

// CH15_AL1_TRANS_COUNT_TRIG Configuration

#define DMA_CH15_AL1_TRANS_COUNT_TRIG_CH15_AL1_TRANS_COUNT_TRIG     (0xFFFFFFFFU<<0U)
#define DMA_CH15_AL1_TRANS_COUNT_TRIG_CH15_AL1_TRANS_COUNT_TRIG_0   (0x1U<<0U)

// CH15_AL2_CTRL Configuration

#define DMA_CH15_AL2_CTRL_CH15_AL2_CTRL                             (0xFFFFFFFFU<<0U)
#define DMA_CH15_AL2_CTRL_CH15_AL2_CTRL_0                           (0x1U<<0U)

// CH15_AL2_TRANS_COUNT Configuration

#define DMA_CH15_AL2_TRANS_COUNT_CH15_AL2_TRANS_COUNT               (0xFFFFFFFFU<<0U)
#define DMA_CH15_AL2_TRANS_COUNT_CH15_AL2_TRANS_COUNT_0             (0x1U<<0U)

// CH15_AL2_READ_ADDR Configuration

#define DMA_CH15_AL2_READ_ADDR_CH15_AL2_READ_ADDR                   (0xFFFFFFFFU<<0U)
#define DMA_CH15_AL2_READ_ADDR_CH15_AL2_READ_ADDR_0                 (0x1U<<0U)

// CH15_AL2_WRITE_ADDR_TRIG Configuration

#define DMA_CH15_AL2_WRITE_ADDR_TRIG_CH15_AL2_WRITE_ADDR_TRIG       (0xFFFFFFFFU<<0U)
#define DMA_CH15_AL2_WRITE_ADDR_TRIG_CH15_AL2_WRITE_ADDR_TRIG_0     (0x1U<<0U)

// CH15_AL3_CTRL Configuration

#define DMA_CH15_AL3_CTRL_CH15_AL3_CTRL                             (0xFFFFFFFFU<<0U)
#define DMA_CH15_AL3_CTRL_CH15_AL3_CTRL_0                           (0x1U<<0U)

// CH15_AL3_WRITE_ADDR Configuration

#define DMA_CH15_AL3_WRITE_ADDR_CH15_AL3_WRITE_ADDR                 (0xFFFFFFFFU<<0U)
#define DMA_CH15_AL3_WRITE_ADDR_CH15_AL3_WRITE_ADDR_0               (0x1U<<0U)

// CH15_AL3_TRANS_COUNT Configuration

#define DMA_CH15_AL3_TRANS_COUNT_CH15_AL3_TRANS_COUNT               (0xFFFFFFFFU<<0U)
#define DMA_CH15_AL3_TRANS_COUNT_CH15_AL3_TRANS_COUNT_0             (0x1U<<0U)

// CH15_AL3_READ_ADDR_TRIG Configuration

#define DMA_CH15_AL3_READ_ADDR_TRIG_CH15_AL3_READ_ADDR_TRIG         (0xFFFFFFFFU<<0U)
#define DMA_CH15_AL3_READ_ADDR_TRIG_CH15_AL3_READ_ADDR_TRIG_0       (0x1U<<0U)

// INTR Configuration

#define DMA_INTR_INTR                                               (0xFFFFU<<0U)
#define DMA_INTR_INTR_0                                             (0x1U<<0U)

// INTE0 Configuration

#define DMA_INTE0_INTE0                                             (0xFFFFU<<0U)
#define DMA_INTE0_INTE0_0                                           (0x1U<<0U)

// INTF0 Configuration

#define DMA_INTF0_INTF0                                             (0xFFFFU<<0U)
#define DMA_INTF0_INTF0_0                                           (0x1U<<0U)

// INTS0 Configuration

#define DMA_INTS0_INTS0                                             (0xFFFFU<<0U)
#define DMA_INTS0_INTS0_0                                           (0x1U<<0U)

// INTR1 Configuration

#define DMA_INTR1_INTR1                                             (0xFFFFU<<0U)
#define DMA_INTR1_INTR1_0                                           (0x1U<<0U)

// INTE1 Configuration

#define DMA_INTE1_INTE1                                             (0xFFFFU<<0U)
#define DMA_INTE1_INTE1_0                                           (0x1U<<0U)

// INTF1 Configuration

#define DMA_INTF1_INTF1                                             (0xFFFFU<<0U)
#define DMA_INTF1_INTF1_0                                           (0x1U<<0U)

// INTS1 Configuration

#define DMA_INTS1_INTS1                                             (0xFFFFU<<0U)
#define DMA_INTS1_INTS1_0                                           (0x1U<<0U)

// INTR2 Configuration

#define DMA_INTR2_INTR2                                             (0xFFFFU<<0U)
#define DMA_INTR2_INTR2_0                                           (0x1U<<0U)

// INTE2 Configuration

#define DMA_INTE2_INTE2                                             (0xFFFFU<<0U)
#define DMA_INTE2_INTE2_0                                           (0x1U<<0U)

// INTF2 Configuration

#define DMA_INTF2_INTF2                                             (0xFFFFU<<0U)
#define DMA_INTF2_INTF2_0                                           (0x1U<<0U)

// INTS2 Configuration

#define DMA_INTS2_INTS2                                             (0xFFFFU<<0U)
#define DMA_INTS2_INTS2_0                                           (0x1U<<0U)

// INTR3 Configuration

#define DMA_INTR3_INTR3                                             (0xFFFFU<<0U)
#define DMA_INTR3_INTR3_0                                           (0x1U<<0U)

// INTE3 Configuration

#define DMA_INTE3_INTE3                                             (0xFFFFU<<0U)
#define DMA_INTE3_INTE3_0                                           (0x1U<<0U)

// INTF3 Configuration

#define DMA_INTF3_INTF3                                             (0xFFFFU<<0U)
#define DMA_INTF3_INTF3_0                                           (0x1U<<0U)

// INTS3 Configuration

#define DMA_INTS3_INTS3                                             (0xFFFFU<<0U)
#define DMA_INTS3_INTS3_0                                           (0x1U<<0U)

// TIMER0 Configuration

#define DMA_TIMER0_Y                                                (0xFFFFU<<0U)
#define DMA_TIMER0_Y_0                                              (0x1U<<0U)
#define DMA_TIMER0_X                                                (0xFFFFU<<16U)
#define DMA_TIMER0_X_0                                              (0x1U<<16U)

// TIMER1 Configuration

#define DMA_TIMER1_Y                                                (0xFFFFU<<0U)
#define DMA_TIMER1_Y_0                                              (0x1U<<0U)
#define DMA_TIMER1_X                                                (0xFFFFU<<16U)
#define DMA_TIMER1_X_0                                              (0x1U<<16U)

// TIMER2 Configuration

#define DMA_TIMER2_Y                                                (0xFFFFU<<0U)
#define DMA_TIMER2_Y_0                                              (0x1U<<0U)
#define DMA_TIMER2_X                                                (0xFFFFU<<16U)
#define DMA_TIMER2_X_0                                              (0x1U<<16U)

// TIMER3 Configuration

#define DMA_TIMER3_Y                                                (0xFFFFU<<0U)
#define DMA_TIMER3_Y_0                                              (0x1U<<0U)
#define DMA_TIMER3_X                                                (0xFFFFU<<16U)
#define DMA_TIMER3_X_0                                              (0x1U<<16U)

// MULTI_CHAN_TRIGGER Configuration

#define DMA_MULTI_CHAN_TRIGGER_MULTI_CHAN_TRIGGER                   (0xFFFFU<<0U)
#define DMA_MULTI_CHAN_TRIGGER_MULTI_CHAN_TRIGGER_0                 (0x1U<<0U)

// SNIFF_CTRL Configuration

#define DMA_SNIFF_CTRL_EN                                           (0x1U<<0U)
#define DMA_SNIFF_CTRL_DMACH                                        (0xFU<<1U)
#define DMA_SNIFF_CTRL_DMACH_0                                      (0x1U<<1U)
#define DMA_SNIFF_CTRL_CALC                                         (0xFU<<5U)
#define DMA_SNIFF_CTRL_CALC_0                                       (0x1U<<5U)
#define DMA_SNIFF_CTRL_BSWAP                                        (0x1U<<9U)
#define DMA_SNIFF_CTRL_OUT_REV                                      (0x1U<<10U)
#define DMA_SNIFF_CTRL_OUT_INV                                      (0x1U<<11U)
#define DMA_SNIFF_CTRL_CALC_CRC32                                   (0x0U<<5U)
#define DMA_SNIFF_CTRL_CALC_CRC32R                                  (0x1U<<5U)
#define DMA_SNIFF_CTRL_CALC_CRC16                                   (0x2U<<5U)
#define DMA_SNIFF_CTRL_CALC_CRC16R                                  (0x3U<<5U)
#define DMA_SNIFF_CTRL_CALC_EVEN                                    (0xEU<<5U)
#define DMA_SNIFF_CTRL_CALC_SUM                                     (0xFU<<5U)

// SNIFF_DATA Configuration

#define DMA_SNIFF_DATA_SNIFF_DATA                                   (0xFFFFFFFFU<<0U)
#define DMA_SNIFF_DATA_SNIFF_DATA_0                                 (0x1U<<0U)

// FIFO_LEVELS Configuration

#define DMA_FIFO_LEVELS_TDF_LVL                                     (0xFFU<<0U)
#define DMA_FIFO_LEVELS_TDF_LVL_0                                   (0x1U<<0U)
#define DMA_FIFO_LEVELS_WAF_LVL                                     (0xFFU<<8U)
#define DMA_FIFO_LEVELS_WAF_LVL_0                                   (0x1U<<8U)
#define DMA_FIFO_LEVELS_RAF_LVL                                     (0xFFU<<16U)
#define DMA_FIFO_LEVELS_RAF_LVL_0                                   (0x1U<<16U)

// CHAN_ABORT Configuration

#define DMA_CHAN_ABORT_CHAN_ABORT                                   (0xFFFFU<<0U)
#define DMA_CHAN_ABORT_CHAN_ABORT_0                                 (0x1U<<0U)

// N_CHANNELS Configuration

#define DMA_N_CHANNELS_N_CHANNELS                                   (0x1FU<<0U)
#define DMA_N_CHANNELS_N_CHANNELS_0                                 (0x1U<<0U)

// SECCFG_CH0 Configuration

#define DMA_SECCFG_CH0_P                                            (0x1U<<0U)
#define DMA_SECCFG_CH0_S                                            (0x1U<<1U)
#define DMA_SECCFG_CH0_LOCK                                         (0x1U<<2U)

// SECCFG_CH1 Configuration

#define DMA_SECCFG_CH1_P                                            (0x1U<<0U)
#define DMA_SECCFG_CH1_S                                            (0x1U<<1U)
#define DMA_SECCFG_CH1_LOCK                                         (0x1U<<2U)

// SECCFG_CH2 Configuration

#define DMA_SECCFG_CH2_P                                            (0x1U<<0U)
#define DMA_SECCFG_CH2_S                                            (0x1U<<1U)
#define DMA_SECCFG_CH2_LOCK                                         (0x1U<<2U)

// SECCFG_CH3 Configuration

#define DMA_SECCFG_CH3_P                                            (0x1U<<0U)
#define DMA_SECCFG_CH3_S                                            (0x1U<<1U)
#define DMA_SECCFG_CH3_LOCK                                         (0x1U<<2U)

// SECCFG_CH4 Configuration

#define DMA_SECCFG_CH4_P                                            (0x1U<<0U)
#define DMA_SECCFG_CH4_S                                            (0x1U<<1U)
#define DMA_SECCFG_CH4_LOCK                                         (0x1U<<2U)

// SECCFG_CH5 Configuration

#define DMA_SECCFG_CH5_P                                            (0x1U<<0U)
#define DMA_SECCFG_CH5_S                                            (0x1U<<1U)
#define DMA_SECCFG_CH5_LOCK                                         (0x1U<<2U)

// SECCFG_CH6 Configuration

#define DMA_SECCFG_CH6_P                                            (0x1U<<0U)
#define DMA_SECCFG_CH6_S                                            (0x1U<<1U)
#define DMA_SECCFG_CH6_LOCK                                         (0x1U<<2U)

// SECCFG_CH7 Configuration

#define DMA_SECCFG_CH7_P                                            (0x1U<<0U)
#define DMA_SECCFG_CH7_S                                            (0x1U<<1U)
#define DMA_SECCFG_CH7_LOCK                                         (0x1U<<2U)

// SECCFG_CH8 Configuration

#define DMA_SECCFG_CH8_P                                            (0x1U<<0U)
#define DMA_SECCFG_CH8_S                                            (0x1U<<1U)
#define DMA_SECCFG_CH8_LOCK                                         (0x1U<<2U)

// SECCFG_CH9 Configuration

#define DMA_SECCFG_CH9_P                                            (0x1U<<0U)
#define DMA_SECCFG_CH9_S                                            (0x1U<<1U)
#define DMA_SECCFG_CH9_LOCK                                         (0x1U<<2U)

// SECCFG_CH10 Configuration

#define DMA_SECCFG_CH10_P                                           (0x1U<<0U)
#define DMA_SECCFG_CH10_S                                           (0x1U<<1U)
#define DMA_SECCFG_CH10_LOCK                                        (0x1U<<2U)

// SECCFG_CH11 Configuration

#define DMA_SECCFG_CH11_P                                           (0x1U<<0U)
#define DMA_SECCFG_CH11_S                                           (0x1U<<1U)
#define DMA_SECCFG_CH11_LOCK                                        (0x1U<<2U)

// SECCFG_CH12 Configuration

#define DMA_SECCFG_CH12_P                                           (0x1U<<0U)
#define DMA_SECCFG_CH12_S                                           (0x1U<<1U)
#define DMA_SECCFG_CH12_LOCK                                        (0x1U<<2U)

// SECCFG_CH13 Configuration

#define DMA_SECCFG_CH13_P                                           (0x1U<<0U)
#define DMA_SECCFG_CH13_S                                           (0x1U<<1U)
#define DMA_SECCFG_CH13_LOCK                                        (0x1U<<2U)

// SECCFG_CH14 Configuration

#define DMA_SECCFG_CH14_P                                           (0x1U<<0U)
#define DMA_SECCFG_CH14_S                                           (0x1U<<1U)
#define DMA_SECCFG_CH14_LOCK                                        (0x1U<<2U)

// SECCFG_CH15 Configuration

#define DMA_SECCFG_CH15_P                                           (0x1U<<0U)
#define DMA_SECCFG_CH15_S                                           (0x1U<<1U)
#define DMA_SECCFG_CH15_LOCK                                        (0x1U<<2U)

// SECCFG_IRQ0 Configuration

#define DMA_SECCFG_IRQ0_P                                           (0x1U<<0U)
#define DMA_SECCFG_IRQ0_S                                           (0x1U<<1U)

// SECCFG_IRQ1 Configuration

#define DMA_SECCFG_IRQ1_P                                           (0x1U<<0U)
#define DMA_SECCFG_IRQ1_S                                           (0x1U<<1U)

// SECCFG_IRQ2 Configuration

#define DMA_SECCFG_IRQ2_P                                           (0x1U<<0U)
#define DMA_SECCFG_IRQ2_S                                           (0x1U<<1U)

// SECCFG_IRQ3 Configuration

#define DMA_SECCFG_IRQ3_P                                           (0x1U<<0U)
#define DMA_SECCFG_IRQ3_S                                           (0x1U<<1U)

// SECCFG_MISC Configuration

#define DMA_SECCFG_MISC_SNIFF_P                                     (0x1U<<0U)
#define DMA_SECCFG_MISC_SNIFF_S                                     (0x1U<<1U)
#define DMA_SECCFG_MISC_TIMER0_P                                    (0x1U<<2U)
#define DMA_SECCFG_MISC_TIMER0_S                                    (0x1U<<3U)
#define DMA_SECCFG_MISC_TIMER1_P                                    (0x1U<<4U)
#define DMA_SECCFG_MISC_TIMER1_S                                    (0x1U<<5U)
#define DMA_SECCFG_MISC_TIMER2_P                                    (0x1U<<6U)
#define DMA_SECCFG_MISC_TIMER2_S                                    (0x1U<<7U)
#define DMA_SECCFG_MISC_TIMER3_P                                    (0x1U<<8U)
#define DMA_SECCFG_MISC_TIMER3_S                                    (0x1U<<9U)

// MPU_CTRL Configuration

#define DMA_MPU_CTRL_P                                              (0x1U<<1U)
#define DMA_MPU_CTRL_S                                              (0x1U<<2U)
#define DMA_MPU_CTRL_NS_HIDE_ADDR                                   (0x1U<<3U)

// MPU_BAR0 Configuration

#define DMA_MPU_BAR0_ADDR                                           (0x7FFFFFFU<<5U)
#define DMA_MPU_BAR0_ADDR_0                                         (0x1U<<5U)

// MPU_LAR0 Configuration

#define DMA_MPU_LAR0_EN                                             (0x1U<<0U)
#define DMA_MPU_LAR0_P                                              (0x1U<<1U)
#define DMA_MPU_LAR0_S                                              (0x1U<<2U)
#define DMA_MPU_LAR0_ADDR                                           (0x7FFFFFFU<<5U)
#define DMA_MPU_LAR0_ADDR_0                                         (0x1U<<5U)

// MPU_BAR1 Configuration

#define DMA_MPU_BAR1_ADDR                                           (0x7FFFFFFU<<5U)
#define DMA_MPU_BAR1_ADDR_0                                         (0x1U<<5U)

// MPU_LAR1 Configuration

#define DMA_MPU_LAR1_EN                                             (0x1U<<0U)
#define DMA_MPU_LAR1_P                                              (0x1U<<1U)
#define DMA_MPU_LAR1_S                                              (0x1U<<2U)
#define DMA_MPU_LAR1_ADDR                                           (0x7FFFFFFU<<5U)
#define DMA_MPU_LAR1_ADDR_0                                         (0x1U<<5U)

// MPU_BAR2 Configuration

#define DMA_MPU_BAR2_ADDR                                           (0x7FFFFFFU<<5U)
#define DMA_MPU_BAR2_ADDR_0                                         (0x1U<<5U)

// MPU_LAR2 Configuration

#define DMA_MPU_LAR2_EN                                             (0x1U<<0U)
#define DMA_MPU_LAR2_P                                              (0x1U<<1U)
#define DMA_MPU_LAR2_S                                              (0x1U<<2U)
#define DMA_MPU_LAR2_ADDR                                           (0x7FFFFFFU<<5U)
#define DMA_MPU_LAR2_ADDR_0                                         (0x1U<<5U)

// MPU_BAR3 Configuration

#define DMA_MPU_BAR3_ADDR                                           (0x7FFFFFFU<<5U)
#define DMA_MPU_BAR3_ADDR_0                                         (0x1U<<5U)

// MPU_LAR3 Configuration

#define DMA_MPU_LAR3_EN                                             (0x1U<<0U)
#define DMA_MPU_LAR3_P                                              (0x1U<<1U)
#define DMA_MPU_LAR3_S                                              (0x1U<<2U)
#define DMA_MPU_LAR3_ADDR                                           (0x7FFFFFFU<<5U)
#define DMA_MPU_LAR3_ADDR_0                                         (0x1U<<5U)

// MPU_BAR4 Configuration

#define DMA_MPU_BAR4_ADDR                                           (0x7FFFFFFU<<5U)
#define DMA_MPU_BAR4_ADDR_0                                         (0x1U<<5U)

// MPU_LAR4 Configuration

#define DMA_MPU_LAR4_EN                                             (0x1U<<0U)
#define DMA_MPU_LAR4_P                                              (0x1U<<1U)
#define DMA_MPU_LAR4_S                                              (0x1U<<2U)
#define DMA_MPU_LAR4_ADDR                                           (0x7FFFFFFU<<5U)
#define DMA_MPU_LAR4_ADDR_0                                         (0x1U<<5U)

// MPU_BAR5 Configuration

#define DMA_MPU_BAR5_ADDR                                           (0x7FFFFFFU<<5U)
#define DMA_MPU_BAR5_ADDR_0                                         (0x1U<<5U)

// MPU_LAR5 Configuration

#define DMA_MPU_LAR5_EN                                             (0x1U<<0U)
#define DMA_MPU_LAR5_P                                              (0x1U<<1U)
#define DMA_MPU_LAR5_S                                              (0x1U<<2U)
#define DMA_MPU_LAR5_ADDR                                           (0x7FFFFFFU<<5U)
#define DMA_MPU_LAR5_ADDR_0                                         (0x1U<<5U)

// MPU_BAR6 Configuration

#define DMA_MPU_BAR6_ADDR                                           (0x7FFFFFFU<<5U)
#define DMA_MPU_BAR6_ADDR_0                                         (0x1U<<5U)

// MPU_LAR6 Configuration

#define DMA_MPU_LAR6_EN                                             (0x1U<<0U)
#define DMA_MPU_LAR6_P                                              (0x1U<<1U)
#define DMA_MPU_LAR6_S                                              (0x1U<<2U)
#define DMA_MPU_LAR6_ADDR                                           (0x7FFFFFFU<<5U)
#define DMA_MPU_LAR6_ADDR_0                                         (0x1U<<5U)

// MPU_BAR7 Configuration

#define DMA_MPU_BAR7_ADDR                                           (0x7FFFFFFU<<5U)
#define DMA_MPU_BAR7_ADDR_0                                         (0x1U<<5U)

// MPU_LAR7 Configuration

#define DMA_MPU_LAR7_EN                                             (0x1U<<0U)
#define DMA_MPU_LAR7_P                                              (0x1U<<1U)
#define DMA_MPU_LAR7_S                                              (0x1U<<2U)
#define DMA_MPU_LAR7_ADDR                                           (0x7FFFFFFU<<5U)
#define DMA_MPU_LAR7_ADDR_0                                         (0x1U<<5U)

// CH0_DBG_CTDREQ Configuration

#define DMA_CH0_DBG_CTDREQ_CH0_DBG_CTDREQ                           (0x3FU<<0U)
#define DMA_CH0_DBG_CTDREQ_CH0_DBG_CTDREQ_0                         (0x1U<<0U)

// CH0_DBG_TCR Configuration

#define DMA_CH0_DBG_TCR_CH0_DBG_TCR                                 (0xFFFFFFFFU<<0U)
#define DMA_CH0_DBG_TCR_CH0_DBG_TCR_0                               (0x1U<<0U)

// CH1_DBG_CTDREQ Configuration

#define DMA_CH1_DBG_CTDREQ_CH1_DBG_CTDREQ                           (0x3FU<<0U)
#define DMA_CH1_DBG_CTDREQ_CH1_DBG_CTDREQ_0                         (0x1U<<0U)

// CH1_DBG_TCR Configuration

#define DMA_CH1_DBG_TCR_CH1_DBG_TCR                                 (0xFFFFFFFFU<<0U)
#define DMA_CH1_DBG_TCR_CH1_DBG_TCR_0                               (0x1U<<0U)

// CH2_DBG_CTDREQ Configuration

#define DMA_CH2_DBG_CTDREQ_CH2_DBG_CTDREQ                           (0x3FU<<0U)
#define DMA_CH2_DBG_CTDREQ_CH2_DBG_CTDREQ_0                         (0x1U<<0U)

// CH2_DBG_TCR Configuration

#define DMA_CH2_DBG_TCR_CH2_DBG_TCR                                 (0xFFFFFFFFU<<0U)
#define DMA_CH2_DBG_TCR_CH2_DBG_TCR_0                               (0x1U<<0U)

// CH3_DBG_CTDREQ Configuration

#define DMA_CH3_DBG_CTDREQ_CH3_DBG_CTDREQ                           (0x3FU<<0U)
#define DMA_CH3_DBG_CTDREQ_CH3_DBG_CTDREQ_0                         (0x1U<<0U)

// CH3_DBG_TCR Configuration

#define DMA_CH3_DBG_TCR_CH3_DBG_TCR                                 (0xFFFFFFFFU<<0U)
#define DMA_CH3_DBG_TCR_CH3_DBG_TCR_0                               (0x1U<<0U)

// CH4_DBG_CTDREQ Configuration

#define DMA_CH4_DBG_CTDREQ_CH4_DBG_CTDREQ                           (0x3FU<<0U)
#define DMA_CH4_DBG_CTDREQ_CH4_DBG_CTDREQ_0                         (0x1U<<0U)

// CH4_DBG_TCR Configuration

#define DMA_CH4_DBG_TCR_CH4_DBG_TCR                                 (0xFFFFFFFFU<<0U)
#define DMA_CH4_DBG_TCR_CH4_DBG_TCR_0                               (0x1U<<0U)

// CH5_DBG_CTDREQ Configuration

#define DMA_CH5_DBG_CTDREQ_CH5_DBG_CTDREQ                           (0x3FU<<0U)
#define DMA_CH5_DBG_CTDREQ_CH5_DBG_CTDREQ_0                         (0x1U<<0U)

// CH5_DBG_TCR Configuration

#define DMA_CH5_DBG_TCR_CH5_DBG_TCR                                 (0xFFFFFFFFU<<0U)
#define DMA_CH5_DBG_TCR_CH5_DBG_TCR_0                               (0x1U<<0U)

// CH6_DBG_CTDREQ Configuration

#define DMA_CH6_DBG_CTDREQ_CH6_DBG_CTDREQ                           (0x3FU<<0U)
#define DMA_CH6_DBG_CTDREQ_CH6_DBG_CTDREQ_0                         (0x1U<<0U)

// CH6_DBG_TCR Configuration

#define DMA_CH6_DBG_TCR_CH6_DBG_TCR                                 (0xFFFFFFFFU<<0U)
#define DMA_CH6_DBG_TCR_CH6_DBG_TCR_0                               (0x1U<<0U)

// CH7_DBG_CTDREQ Configuration

#define DMA_CH7_DBG_CTDREQ_CH7_DBG_CTDREQ                           (0x3FU<<0U)
#define DMA_CH7_DBG_CTDREQ_CH7_DBG_CTDREQ_0                         (0x1U<<0U)

// CH7_DBG_TCR Configuration

#define DMA_CH7_DBG_TCR_CH7_DBG_TCR                                 (0xFFFFFFFFU<<0U)
#define DMA_CH7_DBG_TCR_CH7_DBG_TCR_0                               (0x1U<<0U)

// CH8_DBG_CTDREQ Configuration

#define DMA_CH8_DBG_CTDREQ_CH8_DBG_CTDREQ                           (0x3FU<<0U)
#define DMA_CH8_DBG_CTDREQ_CH8_DBG_CTDREQ_0                         (0x1U<<0U)

// CH8_DBG_TCR Configuration

#define DMA_CH8_DBG_TCR_CH8_DBG_TCR                                 (0xFFFFFFFFU<<0U)
#define DMA_CH8_DBG_TCR_CH8_DBG_TCR_0                               (0x1U<<0U)

// CH9_DBG_CTDREQ Configuration

#define DMA_CH9_DBG_CTDREQ_CH9_DBG_CTDREQ                           (0x3FU<<0U)
#define DMA_CH9_DBG_CTDREQ_CH9_DBG_CTDREQ_0                         (0x1U<<0U)

// CH9_DBG_TCR Configuration

#define DMA_CH9_DBG_TCR_CH9_DBG_TCR                                 (0xFFFFFFFFU<<0U)
#define DMA_CH9_DBG_TCR_CH9_DBG_TCR_0                               (0x1U<<0U)

// CH10_DBG_CTDREQ Configuration

#define DMA_CH10_DBG_CTDREQ_CH10_DBG_CTDREQ                         (0x3FU<<0U)
#define DMA_CH10_DBG_CTDREQ_CH10_DBG_CTDREQ_0                       (0x1U<<0U)

// CH10_DBG_TCR Configuration

#define DMA_CH10_DBG_TCR_CH10_DBG_TCR                               (0xFFFFFFFFU<<0U)
#define DMA_CH10_DBG_TCR_CH10_DBG_TCR_0                             (0x1U<<0U)

// CH11_DBG_CTDREQ Configuration

#define DMA_CH11_DBG_CTDREQ_CH11_DBG_CTDREQ                         (0x3FU<<0U)
#define DMA_CH11_DBG_CTDREQ_CH11_DBG_CTDREQ_0                       (0x1U<<0U)

// CH11_DBG_TCR Configuration

#define DMA_CH11_DBG_TCR_CH11_DBG_TCR                               (0xFFFFFFFFU<<0U)
#define DMA_CH11_DBG_TCR_CH11_DBG_TCR_0                             (0x1U<<0U)

// CH12_DBG_CTDREQ Configuration

#define DMA_CH12_DBG_CTDREQ_CH12_DBG_CTDREQ                         (0x3FU<<0U)
#define DMA_CH12_DBG_CTDREQ_CH12_DBG_CTDREQ_0                       (0x1U<<0U)

// CH12_DBG_TCR Configuration

#define DMA_CH12_DBG_TCR_CH12_DBG_TCR                               (0xFFFFFFFFU<<0U)
#define DMA_CH12_DBG_TCR_CH12_DBG_TCR_0                             (0x1U<<0U)

// CH13_DBG_CTDREQ Configuration

#define DMA_CH13_DBG_CTDREQ_CH13_DBG_CTDREQ                         (0x3FU<<0U)
#define DMA_CH13_DBG_CTDREQ_CH13_DBG_CTDREQ_0                       (0x1U<<0U)

// CH13_DBG_TCR Configuration

#define DMA_CH13_DBG_TCR_CH13_DBG_TCR                               (0xFFFFFFFFU<<0U)
#define DMA_CH13_DBG_TCR_CH13_DBG_TCR_0                             (0x1U<<0U)

// CH14_DBG_CTDREQ Configuration

#define DMA_CH14_DBG_CTDREQ_CH14_DBG_CTDREQ                         (0x3FU<<0U)
#define DMA_CH14_DBG_CTDREQ_CH14_DBG_CTDREQ_0                       (0x1U<<0U)

// CH14_DBG_TCR Configuration

#define DMA_CH14_DBG_TCR_CH14_DBG_TCR                               (0xFFFFFFFFU<<0U)
#define DMA_CH14_DBG_TCR_CH14_DBG_TCR_0                             (0x1U<<0U)

// CH15_DBG_CTDREQ Configuration

#define DMA_CH15_DBG_CTDREQ_CH15_DBG_CTDREQ                         (0x3FU<<0U)
#define DMA_CH15_DBG_CTDREQ_CH15_DBG_CTDREQ_0                       (0x1U<<0U)

// CH15_DBG_TCR Configuration

#define DMA_CH15_DBG_TCR_CH15_DBG_TCR                               (0xFFFFFFFFU<<0U)
#define DMA_CH15_DBG_TCR_CH15_DBG_TCR_0                             (0x1U<<0U)
