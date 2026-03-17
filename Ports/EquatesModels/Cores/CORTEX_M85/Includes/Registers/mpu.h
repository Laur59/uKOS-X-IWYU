/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; mpu.
; ====

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     MPU equates.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

// MPU address definitions
// -----------------------

typedef struct {
    volatile    const   uint32_t    TYPE;
    volatile            uint32_t    CTRL;
    volatile            uint32_t    RNR;
    volatile            uint32_t    RBAR;
    volatile            uint32_t    RLAR;
    volatile            uint32_t    RBAR_A1;
    volatile            uint32_t    RLAR_A1;
    volatile            uint32_t    RBAR_A2;
    volatile            uint32_t    RLAR_A2;
    volatile            uint32_t    RBAR_A3;
    volatile            uint32_t    RLAR_A3;
    volatile            uint32_t    RESERVED0;
    volatile            uint32_t    MAIR0;
    volatile            uint32_t    MAIR1;
} MPU_TypeDef;

#if (defined(__cplusplus))
#define MPU_S   reinterpret_cast<MPU_TypeDef *>(0xE000ED90U)
#define MPU_NS  reinterpret_cast<MPU_TypeDef *>(0xE002ED90U)

#else
#define MPU_S   ((MPU_TypeDef *)0xE000ED90U)
#define MPU_NS  ((MPU_TypeDef *)0xE002ED90U)
#endif
