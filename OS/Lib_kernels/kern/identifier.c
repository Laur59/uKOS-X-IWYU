/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; identifier.
; ===========

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Kern - Identifier management (compare the object IDs)
;
;           This module is responsible for manipulating the identifiers of the uKernel.
;
;-----
;------------------------------------------------------------------------
*/

#include    <stdint.h>

#include    "kern/kern.h"
#include    "kern/private/private_identifiers.h"
#include    "types.h"

/*
 * \brief Compare 2 identifiers (string_1 -> string_2)
 *
 * \param[in]   *string_1   Ptr on the identifiers string_1
 * \param[in]   *string_2   Ptr on the identifiers string_2
 * \return      true        string_1 == string_2
 * \return      false       string_1 != string_2
 *
 */
bool    identifiers_cmpStrings(const char_t *string_1, const char_t *string_2) {
    uint8_t     i;
    bool        status;

    if ((string_1 == nullptr) || (string_2 == nullptr)) {
        return false;
    }

    for (i = 0U; i < KKERN_OBJECT_SZ_ID; i++) {
        if ((string_1[i] == '\0') || (string_2[i] == '\0')) {
            status = (string_1[i] == string_2[i]);
            return status;
        }

        if (string_1[i] != string_2[i]) {
            return false;
        }

    }
    return true;
}
