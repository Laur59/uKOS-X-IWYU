/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Vectors for the uKOS-X system (first).
 */

#pragma once

#include    <stdint.h>

#ifdef __riscv

#include    "macros_soc.h"

// Ecall context-switch state, per hart: the trap handler stores the kernel
// message (a0) and the stack pointer here, and reloads sp from it before mret.

extern  volatile    uintptr_t   vSaveStack[KNB_CORES];
extern  volatile    uint32_t    vMessage[KNB_CORES];

// Hazard3 vectored-mode trap table for core 0. Tests that want vectored
// interrupts write its address OR'd with mtvec.MODE = 1 into mtvec.

void    vector_table_C0(void);

#else

extern  const   uintptr_t   g_pfnVectors_C0[];
extern  const   uintptr_t   g_pfnVectors_C1[];

#endif
