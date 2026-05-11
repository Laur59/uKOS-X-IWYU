/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 *   K210_timer equates.
 */

#pragma once

#include    <stdint.h>

// TIMER devices number
// --------------------

typedef enum    _timer_deivce_number {
    TIMER_DEVICE_0,                                 //
    TIMER_DEVICE_1,                                 //
    TIMER_DEVICE_2,                                 //
    TIMER_DEVICE_MAX                                //
} timer_device_number_t;

// TIMER channel number
// --------------------

typedef enum    _timer_channel_number {
    TIMER_CHANNEL_0,                                //
    TIMER_CHANNEL_1,                                //
    TIMER_CHANNEL_2,                                //
    TIMER_CHANNEL_3,                                //
    TIMER_CHANNEL_MAX                               //
} timer_channel_number_t;

// TIMER Control Register
// ----------------------

#define TIMER_CR_ENABLE             0x00000001U     //
#define TIMER_CR_MODE_MASK          0x00000002U     //
#define TIMER_CR_FREE_MODE          0x00000000U     //
#define TIMER_CR_USER_MODE          0x00000002U     //
#define TIMER_CR_INTERRUPT_MASK     0x00000004U     //
#define TIMER_CR_PWM_ENABLE         0x00000008U     //

// The TIMER address map
// ---------------------

typedef struct  [[gnu::packed, gnu::aligned(4)]] _timer_channel {

    volatile    uint32_t        load_count;         // TIMER_N Load Count Register              (0x00+(N-1)*0x14)
    volatile    uint32_t        current_value;      // TIMER_N Current Value Register           (0x04+(N-1)*0x14)
    volatile    uint32_t        control;            // TIMER_N Control Register                 (0x08+(N-1)*0x14)
    volatile    uint32_t        eoi;                // TIMER_N Interrupt Clear Register         (0x0c+(N-1)*0x14)
    volatile    uint32_t        intr_stat;          // TIMER_N Interrupt Status Register        (0x10+(N-1)*0x14)
} timer_channel_t;

typedef struct  [[gnu::packed, gnu::aligned(4)]] _kendryte_timer {
    volatile    timer_channel_t channel[4];         // TIMER_N Register                         (0x00-0x4c)
    volatile    uint32_t        resv1[20];          // reserverd                                (0x50-0x9c)
    volatile    uint32_t        intr_stat;          // TIMER Interrupt Status Register          (0xa0)
    volatile    uint32_t        eoi;                // TIMER Interrupt Clear Register           (0xa4)
    volatile    uint32_t        raw_intr_stat;      // TIMER Raw Interrupt Status Register      (0xa8)
    volatile    uint32_t        comp_version;       // TIMER Component Version Register         (0xac)
    volatile    uint32_t        load_count2[4];     // TIMER_N Load Count2 Register             (0xb0-0xbc)
} kendryte_timer_t;

#define timer0  ((volatile  kendryte_timer_t *)0x502D0000U)
#define timer1  ((volatile  kendryte_timer_t *)0x502E0000U)
#define timer2  ((volatile  kendryte_timer_t *)0x502F0000U)
