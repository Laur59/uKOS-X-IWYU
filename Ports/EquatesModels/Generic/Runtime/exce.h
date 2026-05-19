/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Spurious exception and interrupt handler — public API.
 */

#pragma once

#include    <stdint.h>

#include    "macros_soc.h"      // KNB_CORES
#include    "soc_reg.h"         // KNB_EXCEPTIONS, KNB_INTERRUPTIONS (via Registers/soc_vectors*.h)

#ifdef __cplusplus
extern  "C" {
#endif

// Public variables
// ----------------

extern  uintptr_t   vVectors[KNB_EXCEPTIONS + KNB_INTERRUPTIONS];
extern  void    (*vExce_indExcVectors[KNB_CORES][KNB_EXCEPTIONS])(void);
extern  void    (*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);

// Prototypes
// ----------

extern  void    exce_init(void);

#ifdef __cplusplus
}
#endif
