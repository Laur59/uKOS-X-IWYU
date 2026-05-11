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

#define KLED_TARGET_ALIVE   KLED_4
#define KLED_TARGET_IDLE    KLED_5

// Prototypes

static  void    local_myRoutine(uint8_t state);

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

    kern_installCallBack(local_myRoutine);

    configure   = (const aliveCnf_t *)argument;
    killRequest = configure->oKillRequest;
    time[0]     = configure->oTime[0];
    time[1]     = configure->oTime[1];
    led         = KLED_TARGET_ALIVE;

    while (!*killRequest) {
        led_on(led);
        kern_suspendProcess(time[0]);
        led_off(led);
        kern_suspendProcess(time[1]);
    }

// Kill the process & the ressources

    INTERRUPTION_OFF;
    led_off(led);

    exit(EXIT_OS_SUCCESS);
}

// Local routines
// ==============

/*
 * \brief local_myRoutine
 *
 * - Callback routine (called by the idle daemon)
 *
 */
static  void    local_myRoutine(uint8_t state) {

    if (state == KKERN_IDLE_IN) { led_off(KLED_TARGET_IDLE); }
    else                        { led_on(KLED_TARGET_IDLE);  }
}
