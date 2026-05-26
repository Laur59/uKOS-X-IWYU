/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Some common routines used in many modules.
 */

#include    "cmns.h"

#include    <stdint.h>

#include    "clockTree.h"
#include    "macros.h"
#include    "macros_core.h"
#include    "modules.h"
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
 * - Initialise the UART0 and UART1 peripherals
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
 * - Send ASCII string via UART
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
 * - Receive a character from UART
 *
 * \param[in]   serialManager   Serial Communication Manager
 * \param[out]  *data           Data received
 *
 * \note This function does not return a value (None).
 *
 */
void    cmns_receive([[maybe_unused]] serialManager_t serialManager, char_t *data) {
    uint32_t    core;
    uint32_t    dr;

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
 * - Simple delay loop
 *
 * \param[in]   us      Delay in microseconds (approximate)
 *
 * \note This function does not return a value (None).
 *
 */
#ifdef __riscv
    // Calibrated for ~150 MHz Hazard3 with cache.
    // The compiled busy-loop body is addi/nop/bltu — 4 cycles per
    // iteration in steady state. wkUs = (us/4) * (clock/1e6) gives
    // the iteration count needed to span `us` microseconds.
    #define CYCLES_PER_ITERATION    4U

#else
    #define CYCLES_PER_ITERATION    7U
#endif
void    cmns_wait(uint32_t us) {
    uint32_t    wkUs = us, time;

    wkUs = (wkUs / CYCLES_PER_ITERATION) * (KFREQUENCY_CORE / 1000000U);

    wkUs = (wkUs == 0U) ? 1U : wkUs;
    for (time = 0; time < wkUs; time++) {
        NOP;
    }
}
