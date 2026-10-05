/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     alive process; the system is working.
 */

#include    "alive/alive.h"

#include    <stdint.h>
#include    <stdlib.h>

#include    "kern/kern.h"
#include    "led/led.h"
#include    "macros_core.h"
#include    "types.h"

/*
 * \brief stub_alive_process
 *
 * - Blink the LED alive
 *
 */
[[noreturn]]
void    stub_alive_process(const void *argument) {
            uint8_t         led;
            uint32_t        time[2];
    const   bool            *killRequest;
    const   aliveCnf_t      *configure;

    configure   = (const aliveCnf_t *)argument;
    killRequest = configure->oKillRequest;
    time[0]     = configure->oTime[0];
    time[1]     = configure->oTime[1];
    led         = configure->oLed;

    while (!*killRequest) {
        led_on(led);
        kern_suspendProcess(time[0]);
        led_off(led);
        kern_suspendProcess(time[1]);
    }

// Kill the process & the ressources

    PRIVILEGE_ELEVATE;      // INTERRUPTION_OFF writes the interrupt mask: privileged
    INTERRUPTION_OFF;
    led_off(led);

    exit(EXIT_OS_SUCCESS);
}
