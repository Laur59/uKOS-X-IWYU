/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; led.
; ===

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     led manager.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

/*!
 * \addtogroup Lib_peripherals
 */
/**@{*/

enum {
        KLED_0 = (uint8_t)0U,
        KLED_1 = (uint8_t)1U,
        KLED_2 = (uint8_t)2U,
        KLED_3 = (uint8_t)3U,
        KLED_4 = (uint8_t)4U,
        KLED_5 = (uint8_t)5U,
        KLED_6 = (uint8_t)6U,
        KLED_7 = (uint8_t)7U,
        KLED_8 = (uint8_t)8U,
        KLED_9 = (uint8_t)9U
};

/*!
 * \defgroup led Led
 *
 * \brief Led
 *
 * Led management
 *
 * @{
 */

#ifdef __cplusplus
extern  "C" {
#endif

extern  int32_t stub_led_init(void);
extern  int32_t stub_led_on(uint8_t ledNb);
extern  int32_t stub_led_off(uint8_t ledNb);
extern  int32_t stub_led_toggle(uint8_t ledNb);
extern  int32_t stub_led_mute(bool mute);

/*!
 * \brief Turn on a LED
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    ledNb;
 *
 *     status = led_on(ledNb);
 * \endcode
 *
 * \param[in]   ledNb           LED number
 * \return      KERR_LED_NOERR  OK
 * \return      KERR_LED_NODEV  The selected LED does not exist
 *
 */
extern  int32_t led_on(uint8_t ledNb);

/*!
 * \brief Turn off a LED
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    ledNb;
 *
 *    status = led_off(ledNb);
 * \endcode
 *
 * \param[in]   ledNb           LED number
 * \return      KERR_LED_NOERR  OK
 * \return      KERR_LED_NODEV  The selected LED does not exist
 *
 */
extern  int32_t led_off(uint8_t ledNb);

/*!
 * \brief Change the state of a LED
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    ledNb;
 *
 *    status = led_toggle(ledNb);
 * \endcode
 *
 * \param[in]   ledNb           LED number
 * \return      KERR_LED_NOERR  OK
 * \return      KERR_LED_NODEV  The selected LED does not exist
 *
 */
extern  int32_t led_toggle(uint8_t ledNb);

/*!
 * \brief General control of the LEDs
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = led_mute(true);  //
 *                              //
 *                              //
 *    status = led_mute(false); // Portion of code without any LED activity
 * \endcode
 *
 * \param[in]   mute            true -> turn off all the LEDs, false -> normal mode
 * \return      KERR_LED_NOERR  OK
 *
 */
extern  int32_t led_mute(bool mute);

// Stub functions (target-specific implementations)
// -------------------------------------------------

int32_t stub_led_init(void);
int32_t stub_led_on(uint8_t ledNb);
int32_t stub_led_off(uint8_t ledNb);
int32_t stub_led_toggle(uint8_t ledNb);
int32_t stub_led_mute(bool mute);

#ifdef __cplusplus
}
#endif

/**@}*/
/**@}*/
