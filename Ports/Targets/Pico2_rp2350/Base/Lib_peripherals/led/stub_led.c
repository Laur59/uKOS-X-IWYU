/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Stub for the "led" manager module.
 *  – Connect the "led" manager to the GPIO SIO hardware.
 */

#include    "led/led.h"

#include    "board.h"
#include    "macros_core.h"
#include    "os_errors.h"
#include    "soc_reg.h"

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

    REG(SIO)->GPIO_OUT_CLR = (1U<<BLED_s);
    REG(SIO)->GPIO_OUT_CLR = (1U<<BLED_0);
    REG(SIO)->GPIO_OUT_CLR = (1U<<BLED_1);
    REG(SIO)->GPIO_OUT_CLR = (1U<<BLED_2);
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
        case 0U: { REG(SIO)->GPIO_OUT_SET = (1U<<BLED_s); break; }
        case 1U: { REG(SIO)->GPIO_OUT_SET = (1U<<BLED_0); break; }
        case 2U: { REG(SIO)->GPIO_OUT_SET = (1U<<BLED_1); break; }
        case 3U: { REG(SIO)->GPIO_OUT_SET = (1U<<BLED_2); break; }
        default: { RETURN_INT_RESTORE(KERR_LED_NODEV);    break; }
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
        case 0U: { REG(SIO)->GPIO_OUT_CLR = (1U<<BLED_s); break; }
        case 1U: { REG(SIO)->GPIO_OUT_CLR = (1U<<BLED_0); break; }
        case 2U: { REG(SIO)->GPIO_OUT_CLR = (1U<<BLED_1); break; }
        case 3U: { REG(SIO)->GPIO_OUT_CLR = (1U<<BLED_2); break; }
        default: { RETURN_INT_RESTORE(KERR_LED_NODEV);    break; }
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
        case 0U: { REG(SIO)->GPIO_OUT_XOR = (1U<<BLED_s); break; }
        case 1U: { REG(SIO)->GPIO_OUT_XOR = (1U<<BLED_0); break; }
        case 2U: { REG(SIO)->GPIO_OUT_XOR = (1U<<BLED_1); break; }
        case 3U: { REG(SIO)->GPIO_OUT_XOR = (1U<<BLED_2); break; }
        default: { RETURN_INT_RESTORE(KERR_LED_NODEV);    break; }
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

    REG(SIO)->GPIO_OUT_CLR = (1U<<BLED_s);
    REG(SIO)->GPIO_OUT_CLR = (1U<<BLED_0);
    REG(SIO)->GPIO_OUT_CLR = (1U<<BLED_1);
    REG(SIO)->GPIO_OUT_CLR = (1U<<BLED_2);
    RETURN_INT_RESTORE(KERR_LED_NOERR);
}
