/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     COREDEBUG equates.
 */

#pragma once

#include    <stdint.h>

// COREDEBUG address definitions
// -----------------------------

typedef struct {
    volatile    uint32_t    DHCSR;
    volatile    uint32_t    DCRSR;
    volatile    uint32_t    DCRDR;
    volatile    uint32_t    DEMCR;
} CoreDebug_TypeDef;

#ifdef __cplusplus
#define CoreDebug   reinterpret_cast<CoreDebug_TypeDef *>(0xE000EDF0U)

#else
#define CoreDebug   ((CoreDebug_TypeDef *)0xE000EDF0U)
#endif

// DEMCR register

#define CoreDebug_DEMCR_TRCENA      (1U<<24U)
