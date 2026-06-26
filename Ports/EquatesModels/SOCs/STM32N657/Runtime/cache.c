/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:    Cortex N657 L1 cache management.
 */

#include    "cache.h"

#define DCACHE_LINE_SIZE    32      // Cache line size of 32-bytes
#define ICACHE_LINE_SIZE    32      // Cache line size of 32-bytes

#include    "model_I_D_cache.c_inc"

/*
 * \brief cache_D_Enable
 *
 * - Enable the data cache
 *
 */
void    cache_D_Enable(void) {

    model_cache_D_Enable();
}

/*
 * \brief cache_D_Disable
 *
 * - Disable the data cache
 *
 */
void    cache_D_Disable(void) {

    model_cache_D_Disable();
}

/*
 * \brief cache_D_Invalidate
 *
 * - Invalidate the data cache
 *
 */
void    cache_D_Invalidate(void) {

    model_cache_D_Invalidate();
}

/*
 * \brief cache_D_Invalidate_Add
 *
 * - Invalidate the data cache by address
 *
 */
void    cache_D_Invalidate_Add(const void *address, int32_t size) {

    model_cache_D_Invalidate_Add(address, size);
}

/*
 * \brief cache_D_Clean
 *
 * - Clean the data cache
 *
 */
void    cache_D_Clean(void) {

    model_cache_D_Clean();
}

/*
 * \brief cache_D_Clean_Add
 *
 * - Clean the data cache by address
 *
 */
void    cache_D_Clean_Add(const void *address, int32_t size) {

    model_cache_D_Clean_Add(address, size);
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
 * \brief cache_I_Invalidate_Add
 *
 * - Invalidate the instruction cache by address
 *
 */
void    cache_I_Invalidate_Add(const void *address, int32_t size) {

    model_cache_I_Invalidate_Add(address, size);
}
