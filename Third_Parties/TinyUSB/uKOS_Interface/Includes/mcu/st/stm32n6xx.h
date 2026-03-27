/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Import the uKOS definition (specially mcu) to provide
 *           the file stm32n6xx.h.
 */

#pragma once

#define __NOP()     __asm volatile ("nop")

// For selecting Secure/NSecure

#ifdef SECURE_S
#define REG(x)                  (x ## _S)
#elif (defined(SECURE_NS))
#define REG(x)                  (x ## _NS)
#else
#define REG(x)                  (x ## _S)
#endif

#define SEC(x)                  (x ## _S)
#define NONSEC(x)               (x ## _NS)

#include    "core_reg.h"
#include    "soc_reg.h"
#include    "model_I_D_cache.c_inc"

// For dwc2_stm32 working in DMA

#define SCB                                         SCB_S
#define SCB_CCR_DC_Pos                              16u
#define SCB_CCR_DC_Msk                              (1ul<<SCB_CCR_DC_Pos)

#define SCB_CleanDCache_by_Addr(x, y)               cache_D_Clean_Add(x, y)
#define SCB_InvalidateDCache_by_Addr(x, y)          cache_D_Invalidate_Add(x, y)
#define SCB_CleanInvalidateDCache_by_Addr(x, y)                                                 \
                                                    do {                                        \
                                                        cache_D_Clean_Add(x, y);                \
                                                        cache_D_Invalidate_Add(x, y);           \
                                                    } while (0)
