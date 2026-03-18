/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     n200_timer equates.
 */

#pragma once

#include    <stdint.h>

// N200_TIMER address definitions
// ------------------------------

typedef struct {
    volatile    uint32_t    mtime_lo;
    volatile    uint32_t    mtime_hi;
    volatile    uint32_t    mtimecmp_lo;
    volatile    uint32_t    mtimecmp_hi;
    volatile    uint32_t    reserved[(0xFF8 - 0x10) / sizeof(uint32_t)];
    volatile    uint32_t    mstop;
    volatile    uint32_t    msip;
} N200_TIMER_Type;

#define N200_TIMER  ((N200_TIMER_Type *)0xD1000000U)
