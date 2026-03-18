/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     random manager.
 */

#pragma once

#include    <stdint.h>

/*!
 * \addtogroup Lib_cryptographics
 */
/**@{*/

/*!
 * \defgroup random Random
 *
 * \brief Random
 *
 * Random management
 *
 * @{
 */

typedef enum {
            KRANDOM_SOFT = 0U,                                  // Software generator
            KRANDOM_HARD                                        // Hardware generator
} randomGenerator_t;

#define KRAND_MAX   ((1U<<31U) - 1)                             // RAND_MAX for 32 bit generator

#ifdef __cplusplus
extern  "C" {
#endif

extern  int32_t stub_random_init(void);
extern  int32_t stub_random_read(randomGenerator_t generator, uint32_t *number);

/*!
 * \brief Read a pool of random numbers
 *
 * Call example in C:
 *
 * \code{.c}
 * #define     KNB_NUMBERS    123
 *
 * int32_t     status;
 * uint32_t    number[KNB_NUMBERS];
 *
 *    status = random_read(KRANDOM_SOFT, &number[0], KNB_NUMBERS);
 * \endcode
 *
 * \param[in]   generator           KRANDOM_SOFT, use the software implementation
 * \param[in]   -                   KRANDOM_HARD, use the hardware implementation
 * \param[out]  *number             Ptr on the number
 * \param[in]   nbNumbers           Number of numbers
 * \return      KERR_RANDOM_NOERR   OK
 * \return      KERR_RANDOM_GEERR   General error
 *
 */
extern  int32_t random_read(randomGenerator_t generator, uint32_t *number, uint32_t nbNumbers);

// Stub functions (target-specific implementations)
// -------------------------------------------------

int32_t stub_random_init(void);
int32_t stub_random_read(randomGenerator_t generator, uint32_t *number);

#ifdef __cplusplus
}
#endif

/**@}*/
/**@}*/
