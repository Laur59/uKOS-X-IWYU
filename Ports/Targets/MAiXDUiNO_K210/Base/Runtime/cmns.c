/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 */

#include    "cmns.h"

#include    <stdint.h>

#include    "Registers/K210_sysctl.h"
#include    "Registers/K210_uart.h"
#include    "clockTree.h"
#include    "macros.h"
#include    "macros_core.h"
#include    "macros_soc.h"
#include    "modules.h"
#include    "types.h"
#include    "serial/serial.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "cmns         Minimal I/O (not under uKOS-X).           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "Cmns\n"
                                    "====\n\n"

                                    "This code provides some minimal I/O.\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
    Cmns,                           // Module name (the first letter has to be upper case)
    KID_FAM_STARTUPS,               // Family (defined in the module.h)
    KNUM_CMNS,                      // Module identifier (defined in the module.h)
    nullptr,                        // Address of the initialisation code (early pre-init)
    nullptr,                        // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                        // Address of the clean code (clean the module)
    " 1.0",                         // Revision string (major . minor)
    (1U<<BSHOW),                    // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                               // Execution cores
);

/*
 * \brief cmns_init
 *
 *
 * \note This function does not return a value (None).
 *
 */
void    cmns_init(void) {

// Turn on the UART1 (used by the core 1)

    sysctl->clk_en_peri.uart1_clk_en = 1U;
    uart1->LCR |= 1U<<7U;

    BAUDRATE(KFREQUENCY_APB0, KSERIAL_DEFAULT_BAUDRATE, uart1->DLH, uart1->DLL, uart1->DLF);

    uart1->LCR  = 0U;
    uart1->LCR  = UART_LCR_NBBIT8 | UART_LCR_STBIT1 | UART_LCR_PARITYNONE;
    uart1->LCR &= (uint32_t)~(1U<<7U);
    uart1->IER |= 0x80U;
    uart1->FCR  = (UART_FCR_RECEIVE_FIFO_1 | UART_FCR_SEND_FIFO_8) | (1U<<3U) | 0x1U;

// Turn on the UART2 (used by the core 0)

    sysctl->clk_en_peri.uart2_clk_en = 1U;
    uart2->LCR |= 1U<<7U;

    BAUDRATE(KFREQUENCY_APB0, KSERIAL_DEFAULT_BAUDRATE, uart2->DLH, uart2->DLL, uart2->DLF);

    uart2->LCR  = 0U;
    uart2->LCR  = UART_LCR_NBBIT8 | UART_LCR_STBIT1 | UART_LCR_PARITYNONE;
    uart2->LCR &= (uint32_t)~(1U<<7U);
    uart2->IER |= 0x80U;
    uart2->FCR  = (UART_FCR_RECEIVE_FIFO_1 | UART_FCR_SEND_FIFO_8) | (1U<<3U) | 0x1U;
}

/*
 * \brief cmns_send
 *
 * \param[in]   serialManager   Serial Communication Manager
 * \param[in]   *ascii          Ptr on the ascii buffer
 *
 * \note This function does not return a value (None).
 *
 */
void    cmns_send([[maybe_unused]] serialManager_t serialManager, const char_t *ascii) {
            uint8_t     data;
            uint32_t    core;
    const   char_t      *wkAscii = ascii;

    core = GET_RUNNING_CORE;

    switch (core) {

// Core 0

        default:
        case KCORE_0: {
            while (true) {
                while ((uart2->LSR & UART_LSR_TEMT) != 0U) { ; }

                data = (uint8_t)*wkAscii;
                wkAscii++;
                if(data == (uint8_t)'\0') {
                    return;
                }

                uart2->THR = data;
            }
            break;
        }

// Core 1

        case KCORE_1: {
            while (true) {
                while ((uart1->LSR & UART_LSR_TEMT) != 0U) { ; }

                data = (uint8_t)*wkAscii;
                wkAscii++;
                if(data == (uint8_t)'\0') {
                    return;
                }

                uart1->THR = data;
            }
            break;
        }

    }
}

/*
 * \brief cmns_receive
 *
 * \param[in]   serialManager   Serial Communication Manager
 * \param[out]  *data           Data received
 *
 * \note This function does not return a value (None).
 *
 */
void    cmns_receive([[maybe_unused]] serialManager_t serialManager, char_t *data) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    switch (core) {

// Core 0

        default:
        case KCORE_0: {
            while ((uart2->LSR & UART_LSR_DATAREADY) == 0U) { ; }

            *data = (uint8_t)(uart2->RBR & 0xFFU);
            break;
        }

// Core 1

        case KCORE_1: {
            while ((uart1->LSR & UART_LSR_DATAREADY) == 0U) { ; }

            *data = (uint8_t)(uart1->RBR & 0xFFU);
            break;
        }
    }
}

/*
 * \brief cmns_wait
 *
 * \param[in]   us      Delay in us
 *
 * \note This function does not return a value (None).
 *
 */
void    cmns_wait(uint32_t us) {
    uint32_t    wkUs = us, time;

    wkUs = (wkUs / 7U) * (KFREQUENCY_CORE / 1000000U);

    wkUs = (wkUs == 0U) ? 1U : wkUs;
    for (time = 0U; time < wkUs; time++) { NOP; }
}
