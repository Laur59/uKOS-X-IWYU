/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Atomic primitives for multi-core.
 *           These calls uses the low level gcc implementation and
 *           are core independent
 */

#pragma once

#include    <stdatomic.h>

// Structures for locks
// --------------------

typedef atomic_flag atomic_flag_t;

// Prototypes

[[gnu::always_inline]]
static  inline  void    atom_init(atomic_flag_t *lock);
[[gnu::always_inline]]
static  inline  void    atom_lock(atomic_flag_t *lock);
[[gnu::always_inline]]
static  inline  void    atom_unlock(atomic_flag_t *lock);

/*
 * \brief atom_init
 *
 * - Initialise the core shared memory
 *
 * \param[in]   *lock       Prt on the atomic flag
 *
 * \note This function does not return a value (None).
 *
 */
[[gnu::always_inline]]
static  inline  void    atom_init(atomic_flag_t *lock) {

    atomic_flag_clear(lock);
}

/*
 * \brief atom_lock
 *
 * - Lock the access
 *
 * \param[in]   *lock       Prt on the atomic flag
 *
 * \note This function does not return a value (None).
 *
 */
[[gnu::always_inline]]
static  inline  void    atom_lock(atomic_flag_t *lock) {

    while (atomic_flag_test_and_set(lock)) { ; }
}

/*
 * \brief atom_unlock
 *
 * - Unlock the access
 *
 * \param[in]   *lock       Prt on the atomic flag
 *
 * \note This function does not return a value (None).
 *
 */
[[gnu::always_inline]]
static  inline  void    atom_unlock(atomic_flag_t *lock) {

    atomic_flag_clear(lock);
}
