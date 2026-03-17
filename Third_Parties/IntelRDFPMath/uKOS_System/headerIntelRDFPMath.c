/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; headerIntelRDFPMath.
; ====================

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     header for IntelRDFPMath library.
;           uKOS-X interface for IntelRDFPMath.
;
;-----
;------------------------------------------------------------------------
*/

#include    "macros.h"
#include    "types.h"
#include    "modules.h"
#include    "ip.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "IntelRDFP    Third party IntelRDFPMath library.        (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "IntelRDFPMath library\n"
                                    "=====================\n\n"

                                    "This library ...\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
    HeaderIntelRDFPMath,            // Module name (the first letter has to be upper case)
    KID_FAM_THIRD_PARTIES,          // Family (defined in the module.h)
    KNUM_INTEL_RDF_MATH,            // Module identifier (defined in the module.h)
    nullptr,                        // Address of the initialisation code (early pre-init)
    nullptr,                        // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                        // Address of the clean code (clean the module)
    " 1.0",                         // Revision string (major . minor)
    (1u<<BSHOW),                    // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                               // Execution cores
);
