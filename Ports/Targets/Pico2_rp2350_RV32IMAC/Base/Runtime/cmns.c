/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:        Common routines for RISC-V TestROM.
 */

#include    <stdint.h>
#include    <reent.h>

#include    "clockTree.h"
#include    "cmns.h"
#include    "macros_core.h"
#include    "soc_reg.h"

// Weak stubs for --wrap linker flags injected by system.cmake.
// The full newlib manager (Phase 2+) provides strong overrides.

__attribute__ ((weak)) void *__wrap__malloc_r (struct _reent *r, size_t size)              { (void)r; (void)size;             return NULL; }
__attribute__ ((weak)) void *__wrap__realloc_r(struct _reent *r, void *ptr, size_t size)  { (void)r; (void)ptr; (void)size;  return NULL; }
__attribute__ ((weak)) void *__wrap__calloc_r (struct _reent *r, size_t nmemb, size_t sz) { (void)r; (void)nmemb; (void)sz;  return NULL; }
__attribute__ ((weak)) void  __wrap__free_r   (struct _reent *r, void *ptr)               { (void)r; (void)ptr;                           }
__attribute__ ((weak, noreturn)) void __wrap___stack_chk_fail(void)                       { while (1) {}                                   }


/*
 * \brief cmns_init
 *
 * - Initialise the UART0 and UART1 peripherals
 *
 *
 * \note This function does not return a value (None).
 *
 */
void    cmns_init(void) {

// Reset of the devices

    REG(RESETS)->RESET &= ~RESETS_RESET_UART0;
    while ((REG(RESETS)->RESET_DONE & RESETS_RESET_UART0) != RESETS_RESET_UART0) { }

    REG(RESETS)->RESET &= ~RESETS_RESET_UART1;
    while ((REG(RESETS)->RESET_DONE & RESETS_RESET_UART1) != RESETS_RESET_UART1) { }

// Disable the UARTx

    REG(UART0)->UARTCR = 0;
    REG(UART1)->UARTCR = 0;

// Bauds:
// Div = UARTCLK / (16 * BAUD) = IBRD + FBRD / 64
// For 150 MHz et 460800 b/s: IBRD = 20, FBRD = 22 (≈460830 b/s)
// Format 8N1

    BAUDRATE(UART0, 150000000, 460800);
    BAUDRATE(UART1, 150000000, 460800);
    REG(UART0)->UARTLCR_H = (3u * UART_UARTLCR_H_WLEN_0);
    REG(UART1)->UARTLCR_H = (3u * UART_UARTLCR_H_WLEN_0);

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
                while ((REG(UART0)->UARTFR & UART_UARTFR_TXFF) != 0u) { }

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
                while ((REG(UART1)->UARTFR & UART_UARTFR_TXFF) != 0u) { }

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
            while ((REG(UART0)->UARTFR & UART_UARTFR_RXFE) != 0u) { }

            dr = REG(UART0)->UARTDR;
            *data = (uint8_t)dr;
            break;
        }

// Core 1

        case KCORE_1: {
            while ((REG(UART1)->UARTFR & UART_UARTFR_RXFE) != 0u) { }

            dr = REG(UART1)->UARTDR;
            *data = (uint8_t)dr;
            break;
        }
    }
}

/*
 * \brief cmns_wait
 *
 * - Simple delay loop for RISC-V
 *
 * \param[in]   us      Delay in microseconds (approximate)
 *
 * \note This function does not return a value (None).
 *
 */
void    cmns_wait(uint32_t us) {
    uint32_t    wkUs = us, time;

    // Calibrated for ~150 MHz Hazard3 with cache.
    // The compiled busy-loop body is addi/nop/bltu — 4 cycles per
    // iteration in steady state. wkUs = (us/4) * (clock/1e6) gives
    // the iteration count needed to span `us` microseconds.

    wkUs = (wkUs / 4u) * (KFREQUENCY_CORE / 1000000u);

    wkUs = (wkUs == 0u) ? (1u) : (wkUs);
    for (time = 0; time < wkUs; time++) {
        __asm volatile ("nop");
    }
}
