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
#include    "macros_soc.h"
#include    "modules.h"
#include    "serial/serial.h"
#include    "soc_reg.h"
#include    "types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

// Bound for the TX wait. cmns_send() is the only way an exception can report
// itself, and it is reachable before cmns_init() has enabled the device - a
// fault inside init_init() gets there with the peripheral still off. The
// ready flag never comes in that state, so an unbounded wait hangs the core
// mid-report: no character sent, and cb_signal() never reached, so not even
// its LED blink. Giving up on the text is always better than never returning.

#define KCMNS_TX_RETRIES            100000U

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

    RCC->APB1ENR2 |= RCC_APB1ENR2_LPUART1EN;

    LPUART1->BRR = BAUDRATE_LP(KFREQUENCY_APB1, KSERIAL_DEFAULT_BAUDRATE);
    LPUART1->CR1 = (LPUART1_CR1_UE | LPUART1_CR1_TE | LPUART1_CR1_RE);

    #ifdef CONFIG_MAN_URT1_S
    RCC->APB1ENR1 |= RCC_APB1ENR1_USART2EN;

    USART2->BRR = BAUDRATE(KFREQUENCY_APB1, KSERIAL_DEFAULT_BAUDRATE);
    USART2->CR1 = (USART2_CR1_UE | USART2_CR1_TE | USART2_CR1_RE);
    #endif

    #ifdef CONFIG_MAN_URT2_S
    RCC->APB1ENR1 |= RCC_APB1ENR1_USART3EN;

    USART3->BRR = BAUDRATE(KFREQUENCY_APB1, KSERIAL_DEFAULT_BAUDRATE);
    USART3->CR1 = (USART3_CR1_UE | USART3_CR1_TE | USART3_CR1_RE);
    #endif
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
            uint32_t    retry;
    const   char_t      *wkAscii = ascii;

    if (ascii == nullptr) { return; }

// Nothing can leave the chip while the device is disabled, and the TX flag
// never sets in that state. Drop the text rather than wait for it forever.

    switch (serialManager) {

// UART 0 device

        default:
        case KURT0: {
            if ((LPUART1->CR1 & LPUART1_CR1_UE) == 0U) { return; }

            while (true) {
                retry = KCMNS_TX_RETRIES;
                while (((LPUART1->ISR & LPUART1_ISR_TXFE) == 0U) && (retry != 0U)) {
                    retry--;
                }
                if (retry == 0U) { return; }

                data = (uint8_t)*wkAscii;
                wkAscii++;
                if (data == '\0') {
                    return;
                }

                LPUART1->TDR = (uint16_t)data;
            }
        }

// UART 1 device

        #ifdef CONFIG_MAN_URT1_S
        case KURT1: {
            if ((USART2->CR1 & USART2_CR1_UE) == 0U) { return; }

            while (true) {
                retry = KCMNS_TX_RETRIES;
                while (((USART2->ISR & USART2_ISR_TXFE) == 0U) && (retry != 0U)) {
                    retry--;
                }
                if (retry == 0U) { return; }

                data = (uint8_t)*wkAscii;
                wkAscii++;
                if (data == '\0') {
                    return;
                }

                USART2->TDR = (uint16_t)data;
            }
        }
        #endif

// UART 2 device

        #ifdef CONFIG_MAN_URT2_S
        case KURT2: {
            if ((USART3->CR1 & USART3_CR1_UE) == 0U) { return; }

            while (true) {
                retry = KCMNS_TX_RETRIES;
                while (((USART3->ISR & USART3_ISR_TXFE) == 0U) && (retry != 0U)) {
                    retry--;
                }
                if (retry == 0U) { return; }

                data = (uint8_t)*wkAscii;
                wkAscii++;
                if (data == '\0') {
                    return;
                }

                USART3->TDR = (uint16_t)data;
            }
        }
        #endif
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

// Same hazard as cmns_send(): the RX flag never sets while the device is
// disabled. The waits below stay unbounded on purpose - this is a blocking
// read - but they must not be entered when nothing can ever arrive.

    switch (serialManager) {

// UART 0 device

        default:
        case KURT0: {
            if ((LPUART1->CR1 & LPUART1_CR1_UE) == 0U) { *data = '\0'; return; }

            while ((LPUART1->ISR & LPUART1_ISR_RXFNE) == 0U) { ; }

            *data = (uint8_t)LPUART1->RDR;
            break;
        }

// UART 1 device

        #ifdef CONFIG_MAN_URT1_S
        case KURT1: {
            if ((USART2->CR1 & USART2_CR1_UE) == 0U) { *data = '\0'; return; }

            while ((USART2->ISR & USART2_ISR_RXFNE) == 0U) { ; }

            *data = (uint8_t)USART2->RDR;
            break;
        }
        #endif

// UART 2 device

        #ifdef CONFIG_MAN_URT2_S
        case KURT2: {
            if ((USART3->CR1 & USART3_CR1_UE) == 0U) { *data = '\0'; return; }

            while ((USART3->ISR & USART3_ISR_RXFNE) == 0U) { ; }

            *data = (uint8_t)USART3->RDR;
            break;
        }
        #endif
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
