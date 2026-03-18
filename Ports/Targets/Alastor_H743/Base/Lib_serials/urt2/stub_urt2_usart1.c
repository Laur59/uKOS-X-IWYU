/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     stub for the connection of the "urt2" manager to the usart1 device.
 */


#ifdef CONFIG_MAN_URT2_S

#include    "clockTree.h"
#include    "soc_reg.h"
#include    "urt2/urt2.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define USART                   USART1
#define USART_VECTOR_NUMBER     USART1_C0_IRQn
#define USART_FREQUENCY         KFREQUENCY_APB2

#define model_usart_init        stub_urt2_init
#define model_usart_configure   stub_urt2_configure
#define model_usart_write       stub_urt2_write
#define model_usart_read        stub_urt2_read
#define model_usart_flush       stub_urt2_flush

#define KUSART_SEMA_RX_S
#define KUSART_SEMA_TX_S
#define KUSART_SEMAPHORE_RX     KURT2_SEMAPHORE_RX
#define KUSART_SEMAPHORE_TX     KURT2_SEMAPHORE_TX

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

    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
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
#endif
