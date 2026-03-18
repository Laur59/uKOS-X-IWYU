/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     header for the uKOS-X applications.
 */

#include    <stdint.h>

#include    "types.h"
#include    "modules.h"

extern  int32_t         aStart(uint32_t argc, const char_t *argv[]);
extern  uintptr_t       _lnApplication;
extern  uKOS_module_t   aUserAppl_Specifications;

__attribute__ ((section(".header")))
const   uKOS_header_t   appHeader = {
                            KMEMU,
                            aStart,
                            (uintptr_t)&_lnApplication,
                            &aUserAppl_Specifications
                        };
