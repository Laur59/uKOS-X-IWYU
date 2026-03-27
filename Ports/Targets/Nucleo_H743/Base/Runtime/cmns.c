/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Nucleo_H743 – Minimal I/O routines (pre-kernel UART, delay).
 */

#include    "cmns.h"

#include    <stddef.h>
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

    RCC->APB1LENR |= RCC_APB1LENR_USART3EN;

    USART3->BRR = BAUDRATE(KFREQUENCY_APB1, KSERIAL_DEFAULT_BAUDRATE);
    USART3->CR1 = (USART_CR1_UE | USART_CR1_TE | USART_CR1_RE);

    #ifdef CONFIG_MAN_URT1_S
    RCC->APB1LENR |= RCC_APB1LENR_USART2EN;

    USART2->BRR = BAUDRATE(KFREQUENCY_APB1, KSERIAL_DEFAULT_BAUDRATE);
    USART2->CR1 = (USART_CR1_UE | USART_CR1_TE | USART_CR1_RE);
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
    const   char_t      *wkAscii = ascii;

    if (ascii == nullptr) { return; }

    switch (serialManager) {

// UART 0 device

        default:
        case KURT0: {
            while (true) {
                while ((USART3->ISR & USART_ISR_TXE) == 0U) { ; }

                data = (uint8_t)*wkAscii;
                wkAscii++;
                if (data == '\0') {
                    return;
                }

                USART3->TDR = (uint16_t)data;
            }
        }

// UART 1 device

        #ifdef CONFIG_MAN_URT1_S
        case KURT1: {
            while (true) {
                while ((USART2->ISR & USART_ISR_TXE) == 0U) { ; }

                data = (uint8_t)*wkAscii;
                wkAscii++;
                if (data == '\0') {
                    return;
                }

                USART2->TDR = (uint16_t)data;
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

    switch (serialManager) {

// UART 0 device

        default:
        case KURT0: {
            while ((USART3->ISR & USART_ISR_RXNE) == 0) { ; }

            *data = (uint8_t)USART3->RDR;
            break;
        }

// UART 1 device

        #ifdef CONFIG_MAN_URT1_S
        case KURT1: {
            while ((USART2->ISR & USART_ISR_RXNE) == 0) { ; }

            *data = (uint8_t)USART2->RDR;
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
