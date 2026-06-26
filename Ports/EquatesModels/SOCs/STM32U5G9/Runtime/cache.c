/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:    Cortex U5G9 L1 cache management.
 */

#include    "cache.h"
#include    "model_I_D_cache.c_inc"

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
