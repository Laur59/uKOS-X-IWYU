/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     NVIC equates.
 */

#pragma once

#include    <stdint.h>

// NVIC address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    ISER[8];
    volatile    uint32_t    RESERVED0[24];
    volatile    uint32_t    ICER[8];
    volatile    uint32_t    RSERVED1[24];
    volatile    uint32_t    ISPR[8];
    volatile    uint32_t    RESERVED2[24];
    volatile    uint32_t    ICPR[8];
    volatile    uint32_t    RESERVED3[24];
    volatile    uint32_t    IABR[8];
    volatile    uint32_t    RESERVED4[56];
    volatile    uint8_t     IP[240];
    volatile    uint32_t    RESERVED5[644];
    volatile    uint32_t    STIR;
} NVIC_TypeDef;

#ifdef __cplusplus
#define NVIC    reinterpret_cast<NVIC_TypeDef *>(0xE000E100U)

#else
#define NVIC    ((NVIC_TypeDef *)0xE000E100U)
#endif

// System Reset

#define NVIC_VECTRESET              0U
#define NVIC_SYSRESETREQ            2U
#define NVIC_AIRCR_VECTKEY          (0x5FAU<<16U)
#define NVIC_AIRCR_ENDIANESS        15U

// NVIC macros

#define NVIC_EnableIRQ(IRQn) \
        NVIC->ISER[((uint32_t)IRQn) / 32U] = (((uint32_t)1U)<<(((uint32_t)(IRQn)) % 32U))

#define NVIC_DisableIRQ(IRQn) \
        NVIC->ICER[((uint32_t)IRQn) / 32U] = (((uint32_t)1U)<<(((uint32_t)(IRQn)) % 32U))

#define NVIC_SetPendingIRQ(IRQn) \
        NVIC->ISPR[((uint32_t)IRQn) / 32U] = (((uint32_t)1U)<<(((uint32_t)(IRQn)) % 32U))

#define NVIC_ClearPendingIRQ(IRQn) \
        NVIC->ICPR[((uint32_t)IRQn) / 32U] = (((uint32_t)1U)<<(((uint32_t)(IRQn)) % 32U))

#define NVIC_SetPriority(IRQn, priority) \
        if (IRQn >= 0) { NVIC->IP[(uint32_t)IRQn] = (uint32_t)(((uint32_t)priority)<<(uint32_t)KNVIC_PRIORITY_SHIFT); } \
        else           { SCB->SHP[((uint32_t)IRQn & 0xFU) - 4U] = ((uint32_t)priority<<(uint32_t)KNVIC_PRIORITY_SHIFT); }
