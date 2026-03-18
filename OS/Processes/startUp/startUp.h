/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:        startUp process header.
 */

#pragma once

#include    "macros.h"
#include    "types.h"

#ifdef __cplusplus
extern  "C" {
#endif

extern  void    stub_startUp_launch(void);

// Module strings (defined in stub_startUp.c)

extern  VAR_DECLARED_ALIGN(const char_t aStartUp_StrHelp[], 4);

#ifdef __cplusplus
}
#endif
