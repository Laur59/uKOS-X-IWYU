/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; nrf5340_network_mutex.
; ======================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     nrf5340_network_mutex equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// MUTEX address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    RESERVED0[256];
    volatile    uint32_t    MUTEX[16];
} MUTEX_TypeDef;

#ifdef __cplusplus
#define APPMUTEX_NS reinterpret_cast<MUTEX_TypeDef *>(0x40030000U)
#define APPMUTEX_S  reinterpret_cast<MUTEX_TypeDef *>(0x50030000U)

#else
#define APPMUTEX_NS ((MUTEX_TypeDef *)0x40030000U)
#define APPMUTEX_S  ((MUTEX_TypeDef *)0x50030000U)
#endif

// MUTEX Configuration

#define MUTEX_MUTEX_MUTEX           (0x1U<<0)
#define MUTEX_MUTEX_MUTEX_UNLOCKED  (0x0U<<0)
#define MUTEX_MUTEX_MUTEX_LOCKED    (0x1U<<0)
