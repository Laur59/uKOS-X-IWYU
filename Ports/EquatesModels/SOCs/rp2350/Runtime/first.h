/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Externals from first_riscv.c shared with the test sources.
 */

#pragma once

#ifndef FIRST_RISCV_H
#define FIRST_RISCV_H

// Hazard3 vectored-mode trap table for core 0. Tests that want vectored
// interrupts write its address OR'd with mtvec.MODE = 1 into mtvec.

void    vector_table_C0(void);

#endif
