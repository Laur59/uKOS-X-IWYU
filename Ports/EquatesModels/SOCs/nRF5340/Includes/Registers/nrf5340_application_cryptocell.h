/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; nrf5340_application_cryptocell.
; ===============================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     nrf5340_application_cryptocell equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// CRYPTOCELL address definitions
// ------------------------------

typedef struct {
    volatile    uint32_t    RESERVED0[320];
    volatile    uint32_t    ENABLE;
} CRYPTOCELL_TypeDef;

#ifdef __cplusplus
#define CRYPTOCELL_S    reinterpret_cast<CRYPTOCELL_TypeDef *>(0x50844000U)

#else
#define CRYPTOCELL_S    ((CRYPTOCELL_TypeDef *)0x50844000U)
#endif

// ENABLE Configuration

#define CRYPTOCELL_ENABLE_ENABLE            (0x1U<<0)
#define CRYPTOCELL_ENABLE_ENABLE_DISABLED   (0x0U<<0)
#define CRYPTOCELL_ENABLE_ENABLE_ENABLED    (0x1U<<0)
