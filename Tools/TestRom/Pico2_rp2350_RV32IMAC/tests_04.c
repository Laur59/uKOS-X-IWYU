/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Test of the UART0 Tx interruption using Hazard3 vectored interrupts
 * (mtvec.MODE = 1). Each main-loop iteration force-pends the UART0
 * IRQ and lets the handler fill the Tx FIFO until the test string is
 * fully sent.
 *
 * Expected on hardware:
 * - UART0 Tx prints ".. but we are not afraid, we are alway firsts ...\n"
 *   roughly once per second
 * - RED   (GPIO13) toggles once per main-loop iteration (~1 s)
 * - GREEN (GPIO12) toggles on every UART0 IRQ entry and once more on
 *   each completed string transmission (so it blinks rapidly while a
 *   transmission is in progress)
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

#define KUART_SZ_TX_BUF_C0      64U

void    (*vExce_indExcVectors[KNB_CORES][KNB_EXCEPTIONS])(void);
void    (*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);
bool    vExce_isException[KNB_CORES] = MCSET(false);

static  volatile    bool        vTransmitted = false;
static  volatile    bool        vFirstKick = false;
static  volatile    uint8_t     vSndBuffer_C0[KUART_SZ_TX_BUF_C0] = ".. but we are not afraid, we are alway firsts ...\n";
static  volatile    uint8_t     * volatile vRSndBuffer_C0;

// Prototypes

static void local_UART0_IRQHandler(void);

/*
 * \brief test_04
 *
 * - Test of the UART0 Tx interruption
 *
 */
static void test_04(void) {

    vRSndBuffer_C0 = vSndBuffer_C0;

// Switch the trap entry to the local vector table (mtvec.MODE = 1)
// Safe to do here because mstatus.MIE is still cleared

    core_putCSR(RV_CSR_MTVEC, ((uint32_t)vector_table_C0) | 0x1u);

// Initialise the UART0 to generate Tx interruptions

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
        vTransmitted = false;

        REG(UART0)->UARTICR   = UART_UARTICR_TXIC;
        REG(UART0)->UARTIMSC |= UART_UARTIMSC_TXIM;

        vFirstKick = true;
        core_setPendingExternalIRQ(UART0_IRQ_C0_IRQn);

        LED_RED_TOGGLE;

// Let terminate the buffer transfer

        cmns_wait(1000000);
        do { } while (vTransmitted == false);
    }
}

/*
 * \brief local_UART0_IRQHandler
 *
 * - Blink the YELLOW Led on Rx & the GREEN Led on the end Tx
 *
 */

static void local_UART0_IRQHandler(void) {
    uint32_t    iir;

    LED_GREEN_TOGGLE;

    iir = REG(UART0)->UARTMIS;

    if ((iir & (UART_UARTMIS_RXMIS | UART_UARTMIS_RTMIS)) != 0u ) {

// Rx interruption
// Try to get empty the fifo

        while ((REG(UART0)->UARTFR & UART_UARTFR_RXFE) == 0u) {
            REG(UART0)->UARTDR;
            cmns_send(KURT0, "OK interruptions\n");

            LED_YELLOW_TOGGLE;
        }

// Acknowledge the UART0 interruption

        REG(UART0)->UARTICR = (UART_UARTICR_RXIC | UART_UARTICR_RTIC);
    }

    if (((iir & UART_UARTMIS_TXMIS) != 0u) || (vFirstKick == true)) {
        vFirstKick = false;
        core_clearPendingExternalIRQ(UART0_IRQ_C0_IRQn);

// Tx interruption
// Try to fill the fifo

        while ((REG(UART0)->UARTFR & UART_UARTFR_TXFF) == 0u) {
            if (*vRSndBuffer_C0 == '\0') {
                LED_GREEN_TOGGLE;

                vRSndBuffer_C0 = vSndBuffer_C0;
                vTransmitted = true;
                REG(UART0)->UARTIMSC &= ~UART_UARTIMSC_TXIM;
                break;
            }
            REG(UART0)->UARTDR = (uint32_t)*vRSndBuffer_C0;
            vRSndBuffer_C0++;
        }

// Acknowledge the UART0 interruption

        REG(UART0)->UARTICR = UART_UARTICR_TXIC;
    }
}

/*
 * \brief main
 *
 * - Execute the test
 *
 */
int     main([[maybe_unused]] int argc, [[maybe_unused]] const char_t *argv[]) {
    test_04();
}
