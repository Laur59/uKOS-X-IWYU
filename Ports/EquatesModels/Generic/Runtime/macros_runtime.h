/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Important runtime macros.
 */

#pragma once

#include    "linker.h"

// C++ constructors initialissation
// --------------------------------

#define CPP_INIT_ARRAYS                                                                             \
                            do {                                                                    \
                                uintptr_t   *ptrInitArray;                                          \
                                uintptr_t   *ptrEndInitArray;                                       \
                                                                                                    \
                                ptrInitArray    = ALIGNED_PTR(uintptr_t, linker_stInitArray);       \
                                ptrEndInitArray = ALIGNED_PTR(uintptr_t, linker_enInitArray);       \
                                while (ptrInitArray < ptrEndInitArray) {                            \
                                    ((void (*)(void))*ptrInitArray)();                              \
                                    ptrInitArray++;                                                 \
                                }                                                                   \
                            } while (0)
