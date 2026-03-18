/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Kern - Object string identifiers management.
 *
 *           Private uKernel variables.
 */

#pragma once

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \addtogroup identifiers
 * @{
 */

/*!
 * \defgroup private_identifiers Private Identifiers
 *
 * \brief Private variables and structures
 *
 * Internal variables & structures, which are not supposed to be accessed by genuine user application
 *
 * @{
 */

#include    "types.h"

/*!
 * \brief Compare 2 identifiers (string_1 -> string_2)
 *
 * \param[in]   *string_1   Ptr on the string string_1
 * \param[in]   *string_2   Ptr on the string string_2
 * \return      true        string_1 == string_2
 * \return      false       string_1 != string_2
 *
 */
extern  bool    identifiers_cmpStrings(const char_t *string_1, const char_t *string_2);

/**@}*/
/**@}*/
/**@}*/
