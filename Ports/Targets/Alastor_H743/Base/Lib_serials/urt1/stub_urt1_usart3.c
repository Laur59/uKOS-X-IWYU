/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     stub for the connection of the "urt1" manager to the usart3 device.
 */

#include    "clockTree.h"
#include    "soc_reg.h"
#include    "urt1/urt1.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define USART                   USART3
#define USART_VECTOR_NUMBER     USART3_C0_IRQn
#define USART_FREQUENCY         KFREQUENCY_APB1

#define model_usart_init        stub_urt1_init
#define model_usart_configure   stub_urt1_configure
#define model_usart_write       stub_urt1_write
#define model_usart_read        stub_urt1_read
#define model_usart_flush       stub_urt1_flush

#define KUSART_SEMA_RX_S
#define KUSART_SEMA_TX_S
#define KUSART_SEMAPHORE_RX     KURT1_SEMAPHORE_RX
#define KUSART_SEMAPHORE_TX     KURT1_SEMAPHORE_TX

#define KUSART_SZ_TX_BUF        1024U
#define KUSART_SZ_RX_BUF        1024U

// Model callbacks
// ---------------

/*
 * \brief cb_enable
 *
 * - Enable the device (clock)
 *
 */
static  void    cb_enable(void) {

    RCC->APB1LENR |= RCC_APB1LENR_USART3EN;
}

/*
 * \brief cb_CTSCheck
 *
 * - Verify the CTS state
 *   If CTS =  1, then disable the uart TX interruptions
 *
 */
static  bool    cb_CTSCheck(void) {

    return true;
}

/*
 * \brief cb_init
 *
 * - Specific initialisations          __
 *   i.e the hardware CTS interruption   \__
 *
 */
static  void    cb_init(void) {

}

#include    "model_usart.c_inc"
