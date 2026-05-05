/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Test of the UART0 Tx interruption using Hazard3 vectored interrupts
 * (mtvec.MODE = 1).
 */

#include    <stdint.h>

#include    "board.h"
#include    "cmns.h"
#include    "core.h"
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
static void local_default_Handler(void);
static void local_MEI_Handler(void);
extern void local_vector_table(void);

/*
 * \brief local_default_Handler
 *
 * - Catch-all handler for unused vector slots (exceptions, MSI, MTI)
 * - Spins so the failure is visible under a debugger
 *
 */
__attribute__ ((interrupt ("machine"), aligned(4), used))
static void local_default_Handler(void) {

    while (true) {
        NOP;
    }
}

/*
 * \brief local_MEI_Handler
 *
 * - Vectored-mode handler for the Machine External Interrupt (mcause = 11)
 * - Drains the Hazard3 meinext queue and dispatches each pending peripheral
 *   IRQ through the project's vExce_indIntVectors table
 *
 */
__attribute__ ((interrupt ("machine"), aligned(4), used))
static void local_MEI_Handler(void) {
            uint32_t    core;
            uint32_t    meinext;

    core    = GET_RUNNING_CORE;
    meinext = core_getNextExternalIRQ();

    while ((meinext & MEINEXT_NOIRQ) == 0u) {
        uint32_t    irqNum = (meinext & MEINEXT_IRQ_MASK) >> MEINEXT_IRQ_SHIFT;

        if ((irqNum < KNB_INTERRUPTIONS) && (vExce_indIntVectors[core][irqNum] != nullptr)) {
            vExce_indIntVectors[core][irqNum]();
        }
        meinext = core_getNextExternalIRQ();
    }
}

/*
 * \brief local_vector_table
 *
 * - Hazard3 vectored-mode trap table (mtvec.MODE = 1)
 * - Must be aligned on 64 bytes (RP2350 Hazard3 requirement)
 * - One 4-byte slot per cause; .option norvc keeps the C extension from
 *   compressing the j instructions to 2 bytes and corrupting the layout
 *
 *   offset  0 : synchronous exception
 *   offset 12 : Machine Software Interrupt   (cause 3)
 *   offset 28 : Machine Timer Interrupt      (cause 7)
 *   offset 44 : Machine External Interrupt   (cause 11)
 *
 */
__attribute__ ((naked, aligned(64), section(".isr_vector"),used))
void    local_vector_table(void) {
    __asm__ volatile (
        ".option push                           \n"
        ".option norvc                          \n"
        "j      local_default_Handler           \n"     // 0 : exception
        ".word  0                               \n"     // 4
        ".word  0                               \n"     // 8
        "j      local_default_Handler           \n"     // 12: MSI
        ".word  0                               \n"     // 16
        ".word  0                               \n"     // 20
        ".word  0                               \n"     // 24
        "j      local_default_Handler           \n"     // 28: MTI
        ".word  0                               \n"     // 32
        ".word  0                               \n"     // 36
        ".word  0                               \n"     // 40
        "j      local_MEI_Handler               \n"     // 44: MEI
        ".option pop                            \n"
    );
}

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

    core_putCSR(RV_CSR_MTVEC, ((uint32_t)local_vector_table) | 0x1u);

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

void    local_UART0_IRQHandler(void) {
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
