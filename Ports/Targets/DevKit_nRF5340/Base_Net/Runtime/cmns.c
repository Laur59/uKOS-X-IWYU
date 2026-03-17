/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; cmns.
; =====

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Some common routines used in many modules.
;
;-----
;------------------------------------------------------------------------
*/

#include    "cmns.h"

#include    <stdint.h>
#include    <string.h>

#include    "clockTree.h"
#include    "serial/serial.h"
#include    "macros.h"
#include    "macros_core.h"
#include    "macros_soc.h"
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

#define KCMNS_SZ_TX_BUF             128U

static  char_t  vTxBuffer_0[KCMNS_SZ_TX_BUF];

/*
 * \brief cmns_init
 *
 * \param[in]   -
 *
 * \note This function does not return a value (None).
 *
 */
void    cmns_init(void) {

    REG(UARTE0)->ENABLE   = 0x8U;
    REG(UARTE0)->BAUDRATE = BAUDRATE_NRF(KSERIAL_DEFAULT_BAUDRATE);
    REG(UARTE0)->CONFIG   = 0U;
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
    size_t  length;

    if (ascii == nullptr) { return; }

    switch (serialManager) {

// UART 0 device

        default:
        case KURT0: {
            length = strlen(ascii);
            length = (length >= KCMNS_SZ_TX_BUF) ? (KCMNS_SZ_TX_BUF) : length;
            memcpy(vTxBuffer_0, ascii, length);

            REG(UARTE0)->TXD_PTR       = (uint32_t)vTxBuffer_0;
            REG(UARTE0)->TXD_MAXCNT    = (uint32_t)length;
            REG(UARTE0)->TASKS_STARTTX = 1U;

            while ((REG(UARTE0)->EVENTS_ENDTX & 1U) == 0U) { ; }
            REG(UARTE0)->EVENTS_ENDTX  = 0U;
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

// NOLINTBEGIN(readability-non-const-parameter)
//
void    cmns_receive(serialManager_t serialManager, char_t *data) {

    switch (serialManager) {

// UART 0 device

        default:
        case KURT0: {
            REG(UARTE0)->RXD_PTR       = (uint32_t)data;
            REG(UARTE0)->RXD_MAXCNT    = 1U;
            REG(UARTE0)->TASKS_STARTRX = 1U;

            while ((REG(UARTE0)->EVENTS_ENDRX & 1U) == 0U) { ; }
            REG(UARTE0)->EVENTS_ENDRX  = 0U;
            break;
        }
    }
}
// NOLINTEND(readability-non-const-parameter)
//

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

    #ifdef CACHE_S
    wkUs = (wkUs / 6U) * (KFREQUENCY_CORE / 1000000U);

    #else
    wkUs = (wkUs / 12U) * (KFREQUENCY_CORE / 1000000U);
    #endif

    for (time = 0U; time < wkUs; time++) { NOP; }
}
