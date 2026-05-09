/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Test of the UART0 Rx interruption using Hazard3 vectored interrupts
 * (mtvec.MODE = 1).
 *
 * Expected on hardware:
 * - RED    (GPIO13) toggles every 100 ms (main-loop heartbeat)
 * - YELLOW (GPIO11) toggles once per character received on UART0 Rx,
 *   and "OK interruptions\n" is echoed on UART0 Tx for each one
 */

#include    <stdint.h>

#include    "board.h"
#include    "cmns.h"
#include    "core.h"
#include    "first_riscv.h"
#include    "macros_core.h"
#include    "macros_soc.h"
#include    "soc_reg.h"
#include    "types.h"

void    (*vExce_indExcVectors[KNB_CORES][KNB_EXCEPTIONS])(void);
void    (*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);
bool    vExce_isException[KNB_CORES] = MCSET(false);

// Prototypes

static void local_UART0_IRQHandler(void);

/*
 * \brief test_03
 *
 * - Test of the UART0 Rx interruption
 *
 */
static void test_03(void) {

// Switch the trap entry to the local vector table (mtvec.MODE = 1)
// Safe to do here because mstatus.MIE is still cleared

    core_putCSR(RV_CSR_MTVEC, ((uint32_t)vector_table_C0) | 0x1u);

// Initialise the UART0 to generate Rx interruptions

    INTERRUPT_VECTOR(UART0_IRQ_C0_IRQn, local_UART0_IRQHandler);
    core_enableExternalIRQ(UART0_IRQ_C0_IRQn);
    core_setBitCSR(RV_CSR_MIE, MIE_MEIE);

    cmns_init();

// Fifo 1/8, Interruption in reception & timeout interruption

    REG(UART0)->UARTLCR_H |= UART_UARTLCR_H_FEN;
    REG(UART0)->UARTIFLS   = (0u * UART_UARTIFLS_TXIFLSEL_0) | (0u * UART_UARTIFLS_RXIFLSEL_0);
    REG(UART0)->UARTIMSC  |= (UART_UARTIMSC_RXIM | UART_UARTIMSC_RTIM);

// Waiting for the UART0 interruption

    INTERRUPTION_ON_HARD;

    while (true) {
        cmns_wait(100000);
        LED_RED_TOGGLE;
    }
}

/*
 * \brief local_UART0_IRQHandler
 *
 * - Blink the YELLOW Led
 *
 */
static void local_UART0_IRQHandler(void) {
    uint32_t    iir;

    iir = REG(UART0)->UARTMIS;

    if ((iir & (UART_UARTMIS_RXMIS | UART_UARTMIS_RTMIS)) != 0u ) {

        while ((REG(UART0)->UARTFR & UART_UARTFR_RXFE) == 0u) {
            REG(UART0)->UARTDR;
            cmns_send(KURT0, "OK interruptions\n");

            LED_YELLOW_TOGGLE;
        }

// Acknowledge the UART0 interruption

        REG(UART0)->UARTICR = (UART_UARTICR_RXIC | UART_UARTICR_RTIC);
    }
}

/*
 * \brief main
 *
 * - Execute the test
 *
 */
int     main([[maybe_unused]] int argc, [[maybe_unused]] const char_t *argv[]) {
    test_03();
}
