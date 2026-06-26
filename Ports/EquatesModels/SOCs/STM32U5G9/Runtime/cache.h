/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:    Cortex U5G9 L1 cache management.
 */

#pragma once

#include    <stdint.h>

/*
 * \brief cache_D_Enable
 *
 * - Enable the data cache
 *
 */
extern  void    cache_D_Enable(uint8_t unit);

/*
 * \brief cache_D_Disable
 *
 * - Disable the data cache
 *
 */
extern  void    cache_D_Disable(uint8_t unit);

/*
 * \brief cache_D_Invalidate
 *
 * - Invalidate the data cache
 *
 */
extern  void    cache_D_Invalidate(uint8_t unit);

/*
 * \brief cache_D_Invalidate_Add
 *
 * - Invalidate the data cache by address
 *
 */
extern  void    cache_D_Invalidate_Add(uint8_t unit, const void *address, int32_t size);

/*
 * \brief cache_D_Clean_Add
 *
 * - Clean the data cache by address
 *
 */
extern  void    cache_D_Clean_Add(uint8_t unit, const void *address, int32_t size);

/*
 * \brief cache_I_Enable
 *
 * - Enable the instruction cache
 *
 */
extern  void    cache_I_Enable(void);

/*
 * \brief cache_I_Disable
 *
 * - Disable the instruction cache
 *
 */
extern  void    cache_I_Disable(void);

/*
 * \brief cache_I_Invalidate
 *
 * - Invalidate the instruction cache
 *
 */
extern  void    cache_I_Invalidate(void);
