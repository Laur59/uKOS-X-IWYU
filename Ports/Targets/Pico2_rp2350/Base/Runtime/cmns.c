/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Some common routines used in many modules.
 */

#include    "cmns.h"

#include    "clockTree.h"
#include    "macros.h"
#include    "macros_core.h"
#include    "modules.h"
#include    "serial/serial.h"
#include    "soc_reg.h"
#include    "types.h"

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
 * \param[in]   -
 *
 * \note This function does not return a value (None).
 *
 */
void    cmns_init(void) {

// Reset of the devices

    REG(RESETS)->RESET &= ~RESETS_RESET_UART0;
    while ((REG(RESETS)->RESET_DONE & RESETS_RESET_UART0) != RESETS_RESET_UART0) { ; }

    REG(RESETS)->RESET &= ~RESETS_RESET_UART1;
    while ((REG(RESETS)->RESET_DONE & RESETS_RESET_UART1) != RESETS_RESET_UART1) { ; }

// Disable the UARTx

    REG(UART0)->UARTCR = 0U;
    REG(UART1)->UARTCR = 0U;

// Bauds:
// Div = UARTCLK / (16 * BAUD) = IBRD + FBRD / 64
// For 150 MHz et 460800 b/s: IBRD = 20, FBRD = 22 (≈460830 b/s)
// Format 8N1

    BAUDRATE(UART0, 150000000U, 460800U);
    BAUDRATE(UART1, 150000000U, 460800U);
    REG(UART0)->UARTLCR_H = (3U * UART_UARTLCR_H_WLEN_0);
    REG(UART1)->UARTLCR_H = (3U * UART_UARTLCR_H_WLEN_0);

// Enable the UARTx

    REG(UART0)->UARTCR = UART_UARTCR_UARTEN | UART_UARTCR_RXE | UART_UARTCR_TXE;
    REG(UART1)->UARTCR = UART_UARTCR_UARTEN | UART_UARTCR_RXE | UART_UARTCR_TXE;
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
void    cmns_send(serialManager_t serialManager, const char_t *ascii) {
            uint8_t     data;
            uint32_t    core;
    const   char_t      *wkAscii = ascii;

    UNUSED(serialManager);

    core = GET_RUNNING_CORE;

    if (ascii == nullptr) { return; }

    switch (core) {

// Core 0

        default:
        case KCORE_0: {
            while (true) {
                while ((REG(UART0)->UARTFR & UART_UARTFR_TXFF) != 0U) { ; }

                data = (uint8_t)*wkAscii;
                wkAscii++;
                if (data == '\0') {
                    return;
                }

                cmns_wait(100);
                REG(UART0)->UARTDR = (uint32_t)data;
            }
            break;
        }

// Core 1

        case KCORE_1: {
            while (true) {
                while ((REG(UART1)->UARTFR & UART_UARTFR_TXFF) != 0U) { ; }

                data = (uint8_t)*wkAscii;
                wkAscii++;
                if (data == '\0') {
                    return;
                }

                cmns_wait(100);
                REG(UART1)->UARTDR = (uint32_t)data;
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
void    cmns_receive(serialManager_t serialManager, char_t *data) {
    uint32_t    core;
    uint32_t    dr;

    UNUSED(serialManager);

    core = GET_RUNNING_CORE;

    switch (core) {

// Core 0

        default:
        case KCORE_0: {
            while ((REG(UART0)->UARTFR & UART_UARTFR_RXFE) != 0U) { ; }

            dr = REG(UART0)->UARTDR;
            *data = (uint8_t)dr;
            break;
        }

// Core 1

        case KCORE_1: {
            while ((REG(UART1)->UARTFR & UART_UARTFR_RXFE) != 0U) { ; }

            dr = REG(UART1)->UARTDR;
            *data = (uint8_t)dr;
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
    for (time = 0; time < wkUs; time++) { NOP; }
}
