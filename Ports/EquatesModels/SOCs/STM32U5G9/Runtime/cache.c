/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:    Cortex U5G9 L1 cache management.
 */

#include    "cache.h"
#include    "model_I_D_cache.c_inc"

#define KEXT_MEMORY_START   0x60000000U     // First address served by DCACHE1
#define KEXT_MEMORY_END     0x9FFFFFFFU     // Last address served by DCACHE1

/*
 * \brief cache_D_Enable
 *
 * - Enable the data cache
 *
 */
void    cache_D_Enable(uint8_t unit) {

    model_cache_D_Enable(unit);
}

/*
 * \brief cache_D_Disable
 *
 * - Disable the data cache
 *
 */
void    cache_D_Disable(uint8_t unit) {

    model_cache_D_Disable(unit);
}

/*
 * \brief cache_D_Invalidate
 *
 * - Invalidate the data cache
 *
 */
void    cache_D_Invalidate(uint8_t unit) {

    model_cache_D_Invalidate(unit);
}

/*
 * \brief cache_D_Invalidate_Add
 *
 * - Invalidate the data cache by address
 *
 */
void    cache_D_Invalidate_Add(uint8_t unit, const void *address, int32_t size) {

    model_cache_D_Invalidate_Add(unit, address, size);
}

/*
 * \brief cache_D_Clean_Add
 *
 * - Clean the data cache by address
 *
 */
void    cache_D_Clean_Add(uint8_t unit, const void *address, int32_t size) {

    model_cache_D_Clean_Add(unit, address, size);
}

/*
 * \brief cache_I_Enable
 *
 * - Enable the instruction cache
 *
 */
void    cache_I_Enable(void) {

    model_cache_I_Enable();
}

/*
 * \brief cache_I_Disable
 *
 * - Disable the instruction cache
 *
 */
void    cache_I_Disable(void) {

    model_cache_I_Disable();
}

/*
 * \brief cache_I_Invalidate
 *
 * - Invalidate the instruction cache
 *
 */
void    cache_I_Invalidate(void) {

    model_cache_I_Invalidate();
}

/*
 * \brief cache_I_D_Sync_Add
 *
 * - Make a memory area that was written as data executable
 *   - clean the data cache by address, so the memory holds what was written;
 *     DCACHE1 serves only the external memories, the internal RAMs are not cached
 *   - invalidate the instruction cache, which may hold what ran there before
 *
 */
void    cache_I_D_Sync_Add(const void *address, int32_t size) {
    uintptr_t   start = (uintptr_t)address;

    if ((size > 0) && (start <= KEXT_MEMORY_END) && ((start + (uintptr_t)size) > KEXT_MEMORY_START)) {
        model_cache_D_Clean_Add(0U, address, size);
    }
    model_cache_I_Invalidate();
}
