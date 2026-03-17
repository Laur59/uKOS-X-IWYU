/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; switch.
; =======

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     switch manager.
;
;-----
;------------------------------------------------------------------------
*/

#ifdef CONFIG_MAN_SWITCH_S

#include    "switch.h"

#include    <stdint.h>

#ifdef PRIVILEGED_USER_S
#include    "kern/kern.h"       // IWYU pragma: keep (for KPROC_PRIVILEGED)
#endif
#include    "macros.h"
#include    "macros_core.h"
#include    "macros_soc.h"
#include    "modules.h"
#include    "os_errors.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "switch       switch manager.                           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "switch manager\n"
                                    "==============\n\n"

                                    "This manager ...\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
    Switch,                         // Module name (the first letter has to be upper case)
    KID_FAM_PERIPHERALS,            // Family (defined in the module.h)
    KNUM_SWITCH,                    // Module identifier (defined in the module.h)
    nullptr,                        // Address of the initialisation code (early pre-init)
    nullptr,                        // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                        // Address of the clean code (clean the module)
    " 1.0",                         // Revision string (major . minor)
    (1U<<BSHOW),                    // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                               // Execution cores
);

// Library specific
// ================

// Prototypes

static  int32_t     local_init(void);

/*
 * \brief Read the configuration mode
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    mode;
 *
 *    status = switch_read(&mode);
 * \endcode
 *
 * \param[out]  *mode               Ptr on the jumper value
 * \return      KERR_SWITCH_NOERR   OK
 *
 */
int32_t switch_read(uint32_t *mode) {
    int32_t     status;

    PRIVILEGE_ELEVATE;
    status = local_init();
    if (status != KERR_SWITCH_NOERR) { PRIVILEGE_RESTORE; return status; }

    status = stub_switch_read(mode);
    PRIVILEGE_RESTORE;
    return status;
}

// Local routines
// ==============

/*
 * \brief local_init
 *
 * - This function initialises the manager and
 *   has to be called at least once
 *
 */
static  int32_t local_init(void) {
            int32_t     status = KERR_SWITCH_NOERR;
            uint32_t    core;
    static  bool        vInit[KNB_CORES] = MCSET(false);

    core = GET_RUNNING_CORE;

    INTERRUPTION_OFF;
    if (!vInit[core]) {
        vInit[core] = true;

        status = stub_switch_init();
    }
    RETURN_INT_RESTORE(status);
}

#endif
