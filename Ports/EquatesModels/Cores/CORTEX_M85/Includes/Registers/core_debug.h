/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; core_debug.
; ===========

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     COREDEBUG equates.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

// COREDEBUG address definitions
// -----------------------------

typedef struct {
    volatile    uint32_t    DHCSR;
    volatile    uint32_t    DCRSR;
    volatile    uint32_t    DCRDR;
    volatile    uint32_t    DEMCR;
    volatile    uint32_t    DSCEMCR;
    volatile    uint32_t    DAUTHCTRL;
    volatile    uint32_t    DSCSR;
} CoreDebug_TypeDef;

#if (defined(__cplusplus))
#define CoreDebug_S     reinterpret_cast<CoreDebug_TypeDef *>(0xE000EDF0U)
#define CoreDebug_NS    reinterpret_cast<CoreDebug_TypeDef *>(0xE002EDF0U)

#else
#define CoreDebug_S     ((CoreDebug_TypeDef *)0xE000EDF0U)
#define CoreDebug_NS    ((CoreDebug_TypeDef *)0xE002EDF0U)
#endif

// DEMCR register

#define CoreDebug_DEMCR_TRCENA      (1u<<24)
