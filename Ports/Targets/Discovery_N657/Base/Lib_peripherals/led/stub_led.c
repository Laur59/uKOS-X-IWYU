/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     stub for the "led" manager module.
 */

#include    "led/led.h"

#include    <stdint.h>

#include    "board.h"
#include    "macros_core.h"
#include    "os_errors.h"
#include    "soc_reg.h"

// LED 2 was LD6 (green, active high) on PE15, which is also Arduino D13 and
// now carries SPI5_SCK for spi0: LD6 shows the SPI clock instead. LED 2 is
// accepted and ignored, so code written for three LEDs still runs.

static  bool    vMute;

/*
 * \brief stub_led_init
 *
 * - Initialise some specific hardware parts:
 *   - The LEDs state
 *
 */
int32_t stub_led_init(void) {

    INTERRUPTION_OFF;
    vMute = false;

    REG(GPIOO)->ODR &= (uint32_t)~(1U<<BLED_0);
    REG(GPIOG)->ODR |=            (1U<<BLED_1);
    RETURN_INT_RESTORE(KERR_LED_NOERR);
}

/*
 * \brief stub_led_on
 *
 * - Turn on a LED
 *
 */
int32_t stub_led_on(uint8_t ledNb) {

    INTERRUPTION_OFF;
    if (vMute) { RETURN_INT_RESTORE(KERR_LED_NOERR); }
    switch (ledNb) {
        case 0U: { REG(GPIOO)->ODR |=            (1U<<BLED_0); break; }
        case 1U: { REG(GPIOG)->ODR &= (uint32_t)~(1U<<BLED_1); break; }
        case 2U: {                                             break; }
        default: { RETURN_INT_RESTORE(KERR_LED_NODEV);         break; }
    }

    RETURN_INT_RESTORE(KERR_LED_NOERR);
}

/*
 * \brief stub_led_off
 *
 * - Turn off a LED
 *
 */
int32_t stub_led_off(uint8_t ledNb) {

    INTERRUPTION_OFF;
    if (vMute) { RETURN_INT_RESTORE(KERR_LED_NOERR); }
    switch (ledNb) {
        case 0U: { REG(GPIOO)->ODR &= (uint32_t)~(1U<<BLED_0); break; }
        case 1U: { REG(GPIOG)->ODR |=            (1U<<BLED_1); break; }
        case 2U: {                                             break; }
        default: { RETURN_INT_RESTORE(KERR_LED_NODEV);         break; }
    }

    RETURN_INT_RESTORE(KERR_LED_NOERR);
}

/*
 * \brief stub_led_toggle
 *
 * - Change the state of a LED
 *
 */
int32_t stub_led_toggle(uint8_t ledNb) {

    INTERRUPTION_OFF;
    if (vMute) { RETURN_INT_RESTORE(KERR_LED_NOERR); }
    switch (ledNb) {
        case 0U: { REG(GPIOO)->ODR ^= (1U<<BLED_0);    break; }
        case 1U: { REG(GPIOG)->ODR ^= (1U<<BLED_1);    break; }
        case 2U: {                                     break; }
        default: { RETURN_INT_RESTORE(KERR_LED_NODEV); break; }
    }

    RETURN_INT_RESTORE(KERR_LED_NOERR);
}

/*
 * \brief stub_led_mute
 *
 * - Control (general) of the LEDs
 *
 */
int32_t stub_led_mute(bool mute) {

    if (!mute) { vMute = false; return KERR_LED_NOERR; }

    INTERRUPTION_OFF;
    vMute = true;

    REG(GPIOO)->ODR &= (uint32_t)~(1U<<BLED_0);
    REG(GPIOG)->ODR |=            (1U<<BLED_1);
    RETURN_INT_RESTORE(KERR_LED_NOERR);
}
