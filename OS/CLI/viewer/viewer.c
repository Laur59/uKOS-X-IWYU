/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; viewer.
; =======

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Image viewer.
;           This tool allows to send an image via the xfer manager.
;
;-----
;------------------------------------------------------------------------
*/

#include    <stdint.h>
#include    <stdio.h>

#include    "modules.h"
#include    "serial/serial.h"
#include    "types.h"
#include    "viewer/viewer_uvc0.h"

// Prototypes

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    Viewer,                                     // Module name (the first letter has to be upper case)
    KID_FAM_CLI,                                // Family (defined in the module.h)
    KNUM_VIEWER,                                // Module identifier (defined in the module.h)
    nullptr,                                    // Address of the initialisation code (early pre-init)
    prgm,                                       // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    viewer_uvc0_clean,                          // Address of the clean code (clean the module)
    " 1.0",                                     // Revision string (major . minor)
    ((1U<<BSHOW) | (1U<<BEXE_CONSOLE)),         // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                                           // Execution cores
);

/*
 * \brief main
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
static  int32_t prgm(uint32_t argc, const char_t *argv[]) {
    int32_t     status;

    (void)dprintf(KSYST, "Viewer process launched.\n");

    status = viewer_uvc0(argc, argv);
    return status;
}
