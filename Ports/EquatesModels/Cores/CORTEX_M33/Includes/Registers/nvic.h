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
    volatile    uint32_t    ISER[16];
    volatile    uint32_t    RESERVED0[16];
    volatile    uint32_t    ICER[16];
    volatile    uint32_t    RSERVED1[16];
    volatile    uint32_t    ISPR[16];
    volatile    uint32_t    RESERVED2[16];
    volatile    uint32_t    ICPR[16];
    volatile    uint32_t    RESERVED3[16];
    volatile    uint32_t    IABR[16];
    volatile    uint32_t    RESERVED4[16];
    volatile    uint32_t    ITNS[16];
    volatile    uint32_t    RESERVED5[16];
    volatile    uint8_t     IP[496];
    volatile    uint32_t    RESERVED6[580];
    volatile    uint32_t    STIR;
} NVIC_TypeDef;

#ifdef ONLY_ONE_NVIC_S
#ifdef __cplusplus
#define NVIC_S  reinterpret_cast<NVIC_TypeDef *>(0xE000E100U)
#define NVIC_NS reinterpret_cast<NVIC_TypeDef *>(0xE000E100U)

#else
#define NVIC_S  ((NVIC_TypeDef *)0xE000E100U)
#define NVIC_NS ((NVIC_TypeDef *)0xE000E100U)
#endif

#else
#ifdef __cplusplus
#define NVIC_S  reinterpret_cast<NVIC_TypeDef *>(0xE000E100U)
#define NVIC_NS reinterpret_cast<NVIC_TypeDef *>(0xE002E100U)

#else
#define NVIC_S  ((NVIC_TypeDef *)0xE000E100U)
#define NVIC_NS ((NVIC_TypeDef *)0xE002E100U)
#endif
#endif

// System Reset

#define NVIC_VECTRESET              0U
#define NVIC_SYSRESETREQ            2U
#define NVIC_AIRCR_VECTKEY          (0x5FAU<<16)
#define NVIC_AIRCR_ENDIANESS        15U

// NVIC macros

#define NVIC_EnableIRQ(IRQn) \
        REG(NVIC)->ISER[((uint32_t)IRQn) / 32U] = (((uint32_t)1U)<<(((uint32_t)(IRQn)) % 32U))

#define NVIC_DisableIRQ(IRQn) \
        REG(NVIC)->ICER[((uint32_t)IRQn) / 32U] = (((uint32_t)1U)<<(((uint32_t)(IRQn)) % 32U))

#define NVIC_SetPendingIRQ(IRQn) \
        REG(NVIC)->ISPR[((uint32_t)IRQn) / 32U] = (((uint32_t)1U)<<(((uint32_t)(IRQn)) % 32U))

#define NVIC_ClearPendingIRQ(IRQn) \
        REG(NVIC)->ICPR[((uint32_t)IRQn) / 32U] = (((uint32_t)1U)<<(((uint32_t)(IRQn)) % 32U))

#define NVIC_SetPriority(IRQn, priority) \
        if (IRQn >= 0) { REG(NVIC)->IP[(uint32_t)IRQn] = (uint32_t)(((uint32_t)priority)<<(uint32_t)KNVIC_PRIORITY_SHIFT); } \
        else           { REG(SCB)->SHP[((uint32_t)IRQn & 0xFU) - 4U] = ((uint32_t)priority<<(uint32_t)KNVIC_PRIORITY_SHIFT); }
