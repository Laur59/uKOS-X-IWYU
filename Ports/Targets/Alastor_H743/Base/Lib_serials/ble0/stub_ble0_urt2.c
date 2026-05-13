/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:    stub for the connection of the "ble0" manager to the "urt2" manager.
 */

#include    <stdint.h>

#include    "ble0/ble0.h"
#include    "types.h"
#include    "urt2/urt2.h"

// Connect the manager ble0 to the manager urt2
// --------------------------------------------

int32_t stub_ble0_reserve(reserveMode_t reserveMode, uint32_t timeout) {

    return(urt2_reserve(reserveMode, timeout));
}

int32_t stub_ble0_release(reserveMode_t reserveMode) {

    return(urt2_release(reserveMode));
}

int32_t stub_ble0_configure(const urtxCnf_t *configure) {

    return(urt2_configure(configure));
}

int32_t stub_ble0_write(const uint8_t *buffer, uint32_t size) {

    return(urt2_write(buffer, size));
}

int32_t stub_ble0_read(uint8_t *buffer, uint32_t *size) {

    return(urt2_read(buffer, size));
}

int32_t stub_ble0_getIdSemaphore(uint8_t semaphore, char_t **identifier) {

    return(urt2_getIdSemaphore(semaphore, identifier));
}

int32_t stub_ble0_flush(void) {

    return(urt2_flush());
}
