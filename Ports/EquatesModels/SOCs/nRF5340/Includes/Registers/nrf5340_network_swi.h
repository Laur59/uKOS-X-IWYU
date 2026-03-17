/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; nrf5340_network_swi.
; ====================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     nrf5340_network_swi equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// SWI address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    UNUSED;
} SWI_TypeDef;

#ifdef __cplusplus
#define SWI0_NS reinterpret_cast<SWI_TypeDef *>(0x4101A000U)
#define SWI1_NS reinterpret_cast<SWI_TypeDef *>(0x4101B000U)
#define SWI2_NS reinterpret_cast<SWI_TypeDef *>(0x4101C000U)
#define SWI3_NS reinterpret_cast<SWI_TypeDef *>(0x4101D000U)

#else
#define SWI0_NS ((SWI_TypeDef *)0x4101A000U)
#define SWI1_NS ((SWI_TypeDef *)0x4101B000U)
#define SWI2_NS ((SWI_TypeDef *)0x4101C000U)
#define SWI3_NS ((SWI_TypeDef *)0x4101D000U)
#endif
