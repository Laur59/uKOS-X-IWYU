/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; stub_urt0_lpuart1.
; ==================

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     stub for the connection of the "urt0" manager to the lpuart1 device.
;
;-----
;------------------------------------------------------------------------
*/

#include    "clockTree.h"
#include    "soc_reg.h"
#include    "urt0/urt0.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define USART                   LPUART1
#define USART_VECTOR_NUMBER     LPUART1_C0_IRQn
#define USART_FREQUENCY         KFREQUENCY_APB1

#define model_usart_init        stub_urt0_init
#define model_usart_configure   stub_urt0_configure
#define model_usart_write       stub_urt0_write
#define model_usart_read        stub_urt0_read
#define model_usart_flush       stub_urt0_flush

#define KUSART_SEMA_RX_S
#define KUSART_SEMA_TX_S
#define KUSART_SEMAPHORE_RX     KURT0_SEMAPHORE_RX
#define KUSART_SEMAPHORE_TX     KURT0_SEMAPHORE_TX

#define KUSART_SZ_TX_BUF        64U
#define KUSART_SZ_RX_BUF        128U

// Model callbacks
// ---------------

/*
 * \brief cb_enable
 *
 * - Enable the device (clock)
 *
 */
static  void    cb_enable(void) {

    RCC->APB1ENR2 |= RCC_APB1ENR2_LPUART1EN;
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
