/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_network_dcnf equates.
 */

#pragma once

#include    <stdint.h>

// DCNF address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    RESERVED0[264];
    volatile    uint32_t    CPUID;
} DCNF_TypeDef;

#ifdef __cplusplus
#define DCNF_NS reinterpret_cast<DCNF_TypeDef *>(0x41000000U)

#else
#define DCNF_NS ((DCNF_TypeDef *)0x41000000U)
#endif

// CPUID Configuration

#define DCNF_CPUID_CPUID    (0xFFU<<0U)
#define DCNF_CPUID_CPUID_0  (0x1U<<0U)
