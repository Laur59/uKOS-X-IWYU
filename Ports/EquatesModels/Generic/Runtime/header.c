/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     header for the uKOS-X applications.
 */

#include    <stdint.h>

#include    "modules.h"
#include    "types.h"

extern  int32_t         aStart(uint32_t argc, const char_t *argv[]);
extern  uintptr_t       _lnApplication;
extern  uKOS_module_t   aUserAppl_Specifications;

// The application header is never referenced from C: it is consumed by the
// loaders, which read it at the base of the user memory. Making it static
// would let the compiler drop it as unused, removing the .header section
// altogether, so the external linkage is deliberate.

[[gnu::section(".header")]]
const   uKOS_header_t   appHeader = {   // NOLINT(misc-use-internal-linkage): see above
                            KMEMU,
                            aStart,
                            (uintptr_t)&_lnApplication,
                            &aUserAppl_Specifications,
                        };
