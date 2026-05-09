/*
 * SPDX-License-Identifier: MIT
 * Generated using the .svd description The 2025-01-01
 *
 * Goal:        RP2350_hstx_ctrl equates.
 */

#pragma once

#include    <stdint.h>

// HSTX_CTRL address definitions
// -----------------------------

typedef struct {
    volatile    uint32_t    CSR;
    volatile    uint32_t    BIT0;
    volatile    uint32_t    BIT1;
    volatile    uint32_t    BIT2;
    volatile    uint32_t    BIT3;
    volatile    uint32_t    BIT4;
    volatile    uint32_t    BIT5;
    volatile    uint32_t    BIT6;
    volatile    uint32_t    BIT7;
    volatile    uint32_t    EXPAND_SHIFT;
    volatile    uint32_t    EXPAND_TMDS;
} HSTX_CTRL_TypeDef;

#ifdef __cplusplus
#define HSTX_CTRL_NS    reinterpret_cast<HSTX_CTRL_TypeDef *>(0x400C0000U)
#define HSTX_CTRL_S     reinterpret_cast<HSTX_CTRL_TypeDef *>(0x400C0000U)
#else
#define HSTX_CTRL_NS    ((HSTX_CTRL_TypeDef *)0x400C0000U)
#define HSTX_CTRL_S     ((HSTX_CTRL_TypeDef *)0x400C0000U)
#endif

// CSR Configuration

#define HSTX_CTRL_CSR_EN                        (0x1U<<0)
#define HSTX_CTRL_CSR_EXPAND_EN                 (0x1U<<1)
#define HSTX_CTRL_CSR_COUPLED_MODE              (0x1U<<4)
#define HSTX_CTRL_CSR_COUPLED_SEL               (0x3U<<5)
#define HSTX_CTRL_CSR_COUPLED_SEL_0             (0x1U<<5)
#define HSTX_CTRL_CSR_SHIFT                     (0x1FU<<8)
#define HSTX_CTRL_CSR_SHIFT_0                   (0x1U<<8)
#define HSTX_CTRL_CSR_N_SHIFTS                  (0x1FU<<16)
#define HSTX_CTRL_CSR_N_SHIFTS_0                (0x1U<<16)
#define HSTX_CTRL_CSR_CLKPHASE                  (0xFU<<24)
#define HSTX_CTRL_CSR_CLKPHASE_0                (0x1U<<24)
#define HSTX_CTRL_CSR_CLKDIV                    (0xFU<<28)
#define HSTX_CTRL_CSR_CLKDIV_0                  (0x1U<<28)

// BIT0 Configuration

#define HSTX_CTRL_BIT0_SEL_P                    (0x1FU<<0)
#define HSTX_CTRL_BIT0_SEL_P_0                  (0x1U<<0)
#define HSTX_CTRL_BIT0_SEL_N                    (0x1FU<<8)
#define HSTX_CTRL_BIT0_SEL_N_0                  (0x1U<<8)
#define HSTX_CTRL_BIT0_INV                      (0x1U<<16)
#define HSTX_CTRL_BIT0_CLK                      (0x1U<<17)

// BIT1 Configuration

#define HSTX_CTRL_BIT1_SEL_P                    (0x1FU<<0)
#define HSTX_CTRL_BIT1_SEL_P_0                  (0x1U<<0)
#define HSTX_CTRL_BIT1_SEL_N                    (0x1FU<<8)
#define HSTX_CTRL_BIT1_SEL_N_0                  (0x1U<<8)
#define HSTX_CTRL_BIT1_INV                      (0x1U<<16)
#define HSTX_CTRL_BIT1_CLK                      (0x1U<<17)

// BIT2 Configuration

#define HSTX_CTRL_BIT2_SEL_P                    (0x1FU<<0)
#define HSTX_CTRL_BIT2_SEL_P_0                  (0x1U<<0)
#define HSTX_CTRL_BIT2_SEL_N                    (0x1FU<<8)
#define HSTX_CTRL_BIT2_SEL_N_0                  (0x1U<<8)
#define HSTX_CTRL_BIT2_INV                      (0x1U<<16)
#define HSTX_CTRL_BIT2_CLK                      (0x1U<<17)

// BIT3 Configuration

#define HSTX_CTRL_BIT3_SEL_P                    (0x1FU<<0)
#define HSTX_CTRL_BIT3_SEL_P_0                  (0x1U<<0)
#define HSTX_CTRL_BIT3_SEL_N                    (0x1FU<<8)
#define HSTX_CTRL_BIT3_SEL_N_0                  (0x1U<<8)
#define HSTX_CTRL_BIT3_INV                      (0x1U<<16)
#define HSTX_CTRL_BIT3_CLK                      (0x1U<<17)

// BIT4 Configuration

#define HSTX_CTRL_BIT4_SEL_P                    (0x1FU<<0)
#define HSTX_CTRL_BIT4_SEL_P_0                  (0x1U<<0)
#define HSTX_CTRL_BIT4_SEL_N                    (0x1FU<<8)
#define HSTX_CTRL_BIT4_SEL_N_0                  (0x1U<<8)
#define HSTX_CTRL_BIT4_INV                      (0x1U<<16)
#define HSTX_CTRL_BIT4_CLK                      (0x1U<<17)

// BIT5 Configuration

#define HSTX_CTRL_BIT5_SEL_P                    (0x1FU<<0)
#define HSTX_CTRL_BIT5_SEL_P_0                  (0x1U<<0)
#define HSTX_CTRL_BIT5_SEL_N                    (0x1FU<<8)
#define HSTX_CTRL_BIT5_SEL_N_0                  (0x1U<<8)
#define HSTX_CTRL_BIT5_INV                      (0x1U<<16)
#define HSTX_CTRL_BIT5_CLK                      (0x1U<<17)

// BIT6 Configuration

#define HSTX_CTRL_BIT6_SEL_P                    (0x1FU<<0)
#define HSTX_CTRL_BIT6_SEL_P_0                  (0x1U<<0)
#define HSTX_CTRL_BIT6_SEL_N                    (0x1FU<<8)
#define HSTX_CTRL_BIT6_SEL_N_0                  (0x1U<<8)
#define HSTX_CTRL_BIT6_INV                      (0x1U<<16)
#define HSTX_CTRL_BIT6_CLK                      (0x1U<<17)

// BIT7 Configuration

#define HSTX_CTRL_BIT7_SEL_P                    (0x1FU<<0)
#define HSTX_CTRL_BIT7_SEL_P_0                  (0x1U<<0)
#define HSTX_CTRL_BIT7_SEL_N                    (0x1FU<<8)
#define HSTX_CTRL_BIT7_SEL_N_0                  (0x1U<<8)
#define HSTX_CTRL_BIT7_INV                      (0x1U<<16)
#define HSTX_CTRL_BIT7_CLK                      (0x1U<<17)

// EXPAND_SHIFT Configuration

#define HSTX_CTRL_EXPAND_SHIFT_RAW_SHIFT        (0x1FU<<0)
#define HSTX_CTRL_EXPAND_SHIFT_RAW_SHIFT_0      (0x1U<<0)
#define HSTX_CTRL_EXPAND_SHIFT_RAW_N_SHIFTS     (0x1FU<<8)
#define HSTX_CTRL_EXPAND_SHIFT_RAW_N_SHIFTS_0   (0x1U<<8)
#define HSTX_CTRL_EXPAND_SHIFT_ENC_SHIFT        (0x1FU<<16)
#define HSTX_CTRL_EXPAND_SHIFT_ENC_SHIFT_0      (0x1U<<16)
#define HSTX_CTRL_EXPAND_SHIFT_ENC_N_SHIFTS     (0x1FU<<24)
#define HSTX_CTRL_EXPAND_SHIFT_ENC_N_SHIFTS_0   (0x1U<<24)

// EXPAND_TMDS Configuration

#define HSTX_CTRL_EXPAND_TMDS_L0_ROT            (0x1FU<<0)
#define HSTX_CTRL_EXPAND_TMDS_L0_ROT_0          (0x1U<<0)
#define HSTX_CTRL_EXPAND_TMDS_L0_NBITS          (0x7U<<5)
#define HSTX_CTRL_EXPAND_TMDS_L0_NBITS_0        (0x1U<<5)
#define HSTX_CTRL_EXPAND_TMDS_L1_ROT            (0x1FU<<8)
#define HSTX_CTRL_EXPAND_TMDS_L1_ROT_0          (0x1U<<8)
#define HSTX_CTRL_EXPAND_TMDS_L1_NBITS          (0x7U<<13)
#define HSTX_CTRL_EXPAND_TMDS_L1_NBITS_0        (0x1U<<13)
#define HSTX_CTRL_EXPAND_TMDS_L2_ROT            (0x1FU<<16)
#define HSTX_CTRL_EXPAND_TMDS_L2_ROT_0          (0x1U<<16)
#define HSTX_CTRL_EXPAND_TMDS_L2_NBITS          (0x7U<<21)
#define HSTX_CTRL_EXPAND_TMDS_L2_NBITS_0        (0x1U<<21)
