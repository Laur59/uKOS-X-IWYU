/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     stub for the connection of the "urt1" manager to the uart3 device.
 */

#include    <stdint.h>

#include    "clockTree.h"
#include    "macros_soc.h"
#include    "serial_common.h"
#include    "soc_reg.h"
#include    "urt1/urt1.h"

// Model callbacks
// ---------------

/*
 * \brief cb_enable_Cx
 *
 * - Enable the device (clock)
 *
 */
static  void    cb_enable_C0(void) {

    sysctl->clk_en_peri.uart3_clk_en = 1;
}

/*
 * \brief cb_CTSCheck_Cx
 *
 * - Verify the CTS state
 *   If CTS =  1, then disable the uart TX interruptions
 *
 */
static  bool    cb_CTSCheck_C0(void) {

    return true;
}

/*
 * \brief cb_init_Cx
 *
 * - Specific initialisations          __
 *   i.e the hardware CTS interruption   \__
 *
 */
static  void    cb_init_C0(void) {

}

// Connect the physical device to the logical manager
// --------------------------------------------------

#define USART_C0                uart3
#define USART_VECTOR_NUMBER_C0  EINT_UART3_INTERRUPT
#define USART_FREQUENCY_C0      KFREQUENCY_UART
#define KUSART_SEMAPHORE_RX_C0  KURT1_SEMAPHORE_RX
#define KUSART_SEMAPHORE_TX_C0  KURT1_SEMAPHORE_TX

#define KUSART_SZ_TX_BUF_C0     1024u
#define KUSART_SZ_RX_BUF_C0     1024u

#define KUSART_SEMA_RX_C0_S
#define KUSART_SEMA_TX_C0_S

#include    "model_usart_C0.c_inc"

int32_t stub_urt1_init(void) {
    uint32_t    core;
    int32_t     status;

    core = GET_RUNNING_CORE;

    if (core == KCORE_0) { status = model_usart_init_C0(); }
    else                 { status = KERR_SERIAL_NODEV;     }
    return status;
}

int32_t stub_urt1_configure(const urtxCnf_t *configure) {
    uint32_t    core;
    int32_t     status;

    core = GET_RUNNING_CORE;

    if (core == KCORE_0) { status = model_usart_configure_C0(configure); }
    else                 { status = KERR_SERIAL_NODEV;                   }
    return status;
}

int32_t stub_urt1_write(const uint8_t *buffer, uint32_t size) {
    uint32_t    core;
    int32_t     status;

    core = GET_RUNNING_CORE;

    if (core == KCORE_0) { status = model_usart_write_C0(buffer, size); }
    else                 { status = KERR_SERIAL_NODEV;                  }
    return status;
}

int32_t stub_urt1_read(uint8_t *buffer, uint32_t *size) {
    uint32_t    core;
    int32_t     status;

    core = GET_RUNNING_CORE;

    if (core == KCORE_0) { status = model_usart_read_C0(buffer, size); }
    else                 { status = KERR_SERIAL_NODEV;                 }
    return status;
}

int32_t stub_urt1_flush(void) {
    uint32_t    core;
    int32_t     status;

    core = GET_RUNNING_CORE;

    if (core == KCORE_0) { status = model_usart_flush_C0(); }
    else                 { status = KERR_SERIAL_NODEV;      }
    return status;
}
