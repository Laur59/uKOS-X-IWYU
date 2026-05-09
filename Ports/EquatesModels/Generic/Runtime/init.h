/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Low level init interface for target-specific initialization.
 */

#pragma once

#ifdef __cplusplus
extern  "C" {
#endif

extern  void    init_init(void);
extern  void    init_C0_init(void);
extern  void    init_C1_init(void);
extern  void    init_launchCore_1(void (*entry)(void));

#ifdef __cplusplus
}
#endif
