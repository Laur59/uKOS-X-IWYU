/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; nrf5340_network_acl.
; ====================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     nrf5340_network_acl equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// ACL address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    RESERVED0[512];
    volatile    uint32_t    ACL0_ADDR;
    volatile    uint32_t    ACL0_SIZE;
    volatile    uint32_t    ACL0_PERM;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    ACL1_ADDR;
    volatile    uint32_t    ACL1_SIZE;
    volatile    uint32_t    ACL1_PERM;
    volatile    uint32_t    RESERVED2;
    volatile    uint32_t    ACL2_ADDR;
    volatile    uint32_t    ACL2_SIZE;
    volatile    uint32_t    ACL2_PERM;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    ACL3_ADDR;
    volatile    uint32_t    ACL3_SIZE;
    volatile    uint32_t    ACL3_PERM;
    volatile    uint32_t    RESERVED4;
    volatile    uint32_t    ACL4_ADDR;
    volatile    uint32_t    ACL4_SIZE;
    volatile    uint32_t    ACL4_PERM;
    volatile    uint32_t    RESERVED5;
    volatile    uint32_t    ACL5_ADDR;
    volatile    uint32_t    ACL5_SIZE;
    volatile    uint32_t    ACL5_PERM;
    volatile    uint32_t    RESERVED6;
    volatile    uint32_t    ACL6_ADDR;
    volatile    uint32_t    ACL6_SIZE;
    volatile    uint32_t    ACL6_PERM;
    volatile    uint32_t    RESERVED7;
    volatile    uint32_t    ACL7_ADDR;
    volatile    uint32_t    ACL7_SIZE;
    volatile    uint32_t    ACL7_PERM;
} ACL_TypeDef;

#ifdef __cplusplus
#define ACL_NS  reinterpret_cast<ACL_TypeDef *>(0x41080000U)

#else
#define ACL_NS  ((ACL_TypeDef *)0x41080000U)
#endif

// ADDR Configuration

#define ACL_ACL_ADDR_ADDR           (0xFFFFFFFFU<<0)
#define ACL_ACL_ADDR_ADDR_0         (0x1U<<0)

// SIZE Configuration

#define ACL_ACL_SIZE_SIZE           (0xFFFFFFFFU<<0)
#define ACL_ACL_SIZE_SIZE_0         (0x1U<<0)

// PERM Configuration

#define ACL_ACL_PERM_READ           (0x1U<<2)
#define ACL_ACL_PERM_WRITE          (0x1U<<1)
#define ACL_ACL_PERM_READ_ENABLE    (0x0U<<2)
#define ACL_ACL_PERM_READ_DISABLE   (0x1U<<2)
#define ACL_ACL_PERM_WRITE_ENABLE   (0x0U<<1)
#define ACL_ACL_PERM_WRITE_DISABLE  (0x1U<<1)
