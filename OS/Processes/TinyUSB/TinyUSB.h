/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     "TinyUSB" management.
 */

#pragma once

#include    "kern/kern_types.h"
#include    "macros_soc.h"
#include    "types.h"

#ifdef __cplusplus
extern  "C" {
#endif

extern mutx_t  *vTinyUSB_API[KNB_CORES];

extern  void    stub_TinyUSB_init(void);
extern  void    stub_TinyUSB_cyclic(void);

// Return the USB product name of this board, or nullptr to keep the generic
// one held by the TinyUSB archive. Unlike the unique identifier above this is
// not a board stub: the name is simply BOARD, which the system build defines
// for every translation unit, so one implementation serves every board.

extern  const   char_t  *TinyUSB_getProductName(void);

#ifdef __cplusplus
}
#endif
