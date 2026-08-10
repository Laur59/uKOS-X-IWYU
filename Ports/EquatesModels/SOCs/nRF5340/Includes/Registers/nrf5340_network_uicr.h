/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_network_uicr equates.
 */

#pragma once

#include    <stdint.h>

// UICR address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    APPROTECT;
    volatile    uint32_t    ERASEPROTECT;
    volatile    uint32_t    RESERVED0[126];
    volatile    uint32_t    NRFFW[32];
    volatile    uint32_t    RESERVED1[32];
    volatile    uint32_t    CUSTOMER[32];
} UICR_TypeDef;

#ifdef __cplusplus
#define UICR_NS reinterpret_cast<UICR_TypeDef *>(0x01FF8000U)

#else
#define UICR_NS ((UICR_TypeDef *)0x01FF8000U)
#endif

// APPROTECT Configuration

#define UICR_APPROTECT_PALL                     (0xFFFFFFFFU<<0U)
#define UICR_APPROTECT_PALL_0                   (0x1U<<0U)
#define UICR_APPROTECT_PALL_UNPROTECTED         (0x50FA50FAU<<0U)
#define UICR_APPROTECT_PALL_PROTECTED           (0x0U<<0U)

// ERASEPROTECT Configuration

#define UICR_ERASEPROTECT_PALL                  (0xFFFFFFFFU<<0U)
#define UICR_ERASEPROTECT_PALL_0                (0x1U<<0U)
#define UICR_ERASEPROTECT_PALL_UNPROTECTED      (0xFFFFFFFFU<<0U)
#define UICR_ERASEPROTECT_PALL_PROTECTED        (0x0U<<0U)

// NRFFW Configuration

#define UICR_NRFFW_NRFFW                        (0xFFFFFFFFU<<0U)
#define UICR_NRFFW_NRFFW_0                      (0x1U<<0U)

// CUSTOMER Configuration

#define UICR_CUSTOMER_CUSTOMER                  (0xFFFFFFFFU<<0U)
#define UICR_CUSTOMER_CUSTOMER_0                (0x1U<<0U)
