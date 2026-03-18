/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Some consts that could be necessary for debugging tool
 *           susch as Segger Ozone.
 */

#pragma once

// Debug kernel
// ------------

#ifndef DEBUG_KERN_TRACE
#define DEBUG_KERN_TRACE(text);
#endif

// uKOS-X architecture constants
// ------------------------------

// Used architecture
// uKOS_ARCHITECTURE is specially designed for third parties debug
// tools such as Segger Ozone plugin
//
// cortex -M3, -M4, -M7, -M33 -m55 -m85 = 0
// risc-v (RV32) RV32IMAC               = 1
// risc-v (RV64) RV64IMAFDC             = 2

#if (defined(CORTEX_M3_S) || defined(CORTEX_M4_S) || defined(CORTEX_M7_S) || defined(CORTEX_M33_S) || defined(CORTEX_M55_S) || defined(CORTEX_M85_S))
#define uKOS_ARCHITECTURE   0U

#elif (defined(RV32IMAC_S))
#define uKOS_ARCHITECTURE   1U

#elif (defined(RV64IMAFDC_S))
#define uKOS_ARCHITECTURE   2U

#else
#error  "*** Architecture not defined"
#endif
