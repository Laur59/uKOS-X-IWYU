/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 */

#pragma once

/*!
 * \defgroup Lib_cryptographics Library for the crypto tools
 *
 * \brief Cryptographic manager system calls
 *
 * The Lib_cryptographics library provides a manager devoted to randomness.
 * Its role is to ensure that numbers may be created without pattern or bias.
 *
 * The random manager may rely on hardware entropy or on software routines.
 * In both cases, it delivers values that resist prediction and imitation.
 * Randomness is vital for security. Keys, tokens, and nonces all depend on
 * numbers that cannot be guessed. Without them, encryption would be fragile.
 * Beyond security, randomness brings life to simulations, games, and models.
 * It allows fair trials, varied outcomes, and realistic scientific results.
 * By offering both speed and reliability, the random manager turns chance
 * into a controlled resource. It shows that uncertainty can be engineered.
 *
 * Together these managers show that discipline and design can live side by side.
 * Lib_cryptographics is both a toolbox for developers and a lesson in clarity.
 *
 * @{
 */

// IWYU pragma: begin_exports

#ifdef CONFIG_MAN_RANDOM_S
#include    "random/random.h"
#endif

// IWYU pragma: end_exports

/**!@}*/
