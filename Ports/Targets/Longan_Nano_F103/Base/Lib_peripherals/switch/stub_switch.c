/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     stub for the "switch" manager module.
 */

#include    "switch/switch.h"

#include    <stdint.h>

#include    "os_errors.h"

/*
 * \brief stub_switch_init
 *
 * - Initialise some specific hardware parts
 *
 */
int32_t stub_switch_init(void) {
    return KERR_SWITCH_NOERR;
}

/*
 * \brief stub_switch_read
 *
 * - Read the jumper configuration
 *
 */
int32_t stub_switch_read(uint32_t *mode) {

    *mode = 0U;
    return KERR_SWITCH_NOERR;
}
