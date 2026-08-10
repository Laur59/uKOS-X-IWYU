/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     nrf5340_application_cache equates.
 */

#pragma once

#include    <stdint.h>

// CACHE address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    RESERVED0[256];
    volatile    uint32_t    PROFILING0_IHIT;
    volatile    uint32_t    PROFILING0_IMISS;
    volatile    uint32_t    PROFILING0_DHIT;
    volatile    uint32_t    PROFILING0_DMISS;
    volatile    uint32_t    RESERVED1[4];
    volatile    uint32_t    PROFILING1_IHIT;
    volatile    uint32_t    PROFILING1_IMISS;
    volatile    uint32_t    PROFILING1_DHIT;
    volatile    uint32_t    PROFILING1_DMISS;
    volatile    uint32_t    RESERVED2[52];
    volatile    uint32_t    ENABLE;
    volatile    uint32_t    INVALIDATE;
    volatile    uint32_t    ERASE;
    volatile    uint32_t    PROFILINGENABLE;
    volatile    uint32_t    PROFILINGCLEAR;
    volatile    uint32_t    MODE;
    volatile    uint32_t    DEBUGLOCK;
    volatile    uint32_t    ERASESTATUS;
    volatile    uint32_t    WRITELOCK;
} CACHE_TypeDef;

#ifdef __cplusplus
#define NCACHE_S    reinterpret_cast<CACHE_TypeDef *>(0x50001000U)

#else
#define NCACHE_S    ((CACHE_TypeDef *)0x50001000U)
#endif

// IHIT Configuration

#define CACHE_PROFILING_IHIT_HITS                           (0xFFFFFFFFU<<0U)
#define CACHE_PROFILING_IHIT_HITS_0                         (0x1U<<0U)

// IMISS Configuration

#define CACHE_PROFILING_IMISS_MISSES                (0xFFFFFFFFU<<0U)
#define CACHE_PROFILING_IMISS_MISSES_0              (0x1U<<0U)

// DHIT Configuration

#define CACHE_PROFILING_DHIT_HITS                   (0xFFFFFFFFU<<0U)
#define CACHE_PROFILING_DHIT_HITS_0                 (0x1U<<0U)

// DMISS Configuration

#define CACHE_PROFILING_DMISS_MISSES                (0xFFFFFFFFU<<0U)
#define CACHE_PROFILING_DMISS_MISSES_0              (0x1U<<0U)

// ENABLE Configuration

#define CACHE_ENABLE_ENABLE                         (0x1U<<0U)
#define CACHE_ENABLE_ENABLE_DISABLED                (0x0U<<0U)
#define CACHE_ENABLE_ENABLE_ENABLED                 (0x1U<<0U)

// INVALIDATE Configuration

#define CACHE_INVALIDATE_INVALIDATE                 (0x1U<<0U)
#define CACHE_INVALIDATE_INVALIDATE_INVALIDATE      (0x1U<<0U)

// ERASE Configuration

#define CACHE_ERASE_ERASE                           (0x1U<<0U)
#define CACHE_ERASE_ERASE_ERASE                     (0x1U<<0U)

// PROFILINGENABLE Configuration

#define CACHE_PROFILINGENABLE_ENABLE                (0x1U<<0U)
#define CACHE_PROFILINGENABLE_ENABLE_DISABLE        (0x0U<<0U)
#define CACHE_PROFILINGENABLE_ENABLE_ENABLE         (0x1U<<0U)

// PROFILINGCLEAR Configuration

#define CACHE_PROFILINGCLEAR_CLEAR                  (0x1U<<0U)
#define CACHE_PROFILINGCLEAR_CLEAR_CLEAR            (0x1U<<0U)

// MODE Configuration

#define CACHE_MODE_MODE                             (0x1U<<0U)
#define CACHE_MODE_MODE_CACHE                       (0x0U<<0U)
#define CACHE_MODE_MODE_RAM                         (0x1U<<0U)

// DEBUGLOCK Configuration

#define CACHE_DEBUGLOCK_DEBUGLOCK                   (0x1U<<0U)
#define CACHE_DEBUGLOCK_DEBUGLOCK_UNLOCKED          (0x0U<<0U)
#define CACHE_DEBUGLOCK_DEBUGLOCK_LOCKED            (0x1U<<0U)

// ERASESTATUS Configuration

#define CACHE_ERASESTATUS_ERASESTATUS               (0x1U<<0U)
#define CACHE_ERASESTATUS_ERASESTATUS_IDLE          (0x0U<<0U)
#define CACHE_ERASESTATUS_ERASESTATUS_FINISHED      (0x1U<<0U)

// WRITELOCK Configuration

#define CACHE_WRITELOCK_WRITELOCK                   (0x1U<<0U)
#define CACHE_WRITELOCK_WRITELOCK_UNLOCKED          (0x0U<<0U)
#define CACHE_WRITELOCK_WRITELOCK_LOCKED            (0x1U<<0U)
