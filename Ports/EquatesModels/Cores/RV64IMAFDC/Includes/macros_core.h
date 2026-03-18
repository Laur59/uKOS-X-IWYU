/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Important macros.
 */

#pragma once

#include    "core.h"    // IWYU pragma: keep
#include    "macros_soc.h"

// uKernel macros
// --------------

// Core machine in bits

#define KMACHINE_BITS           (64U)

// Preemptions

#ifndef KSTATUS
#define KSTATUS                 (MSTATUS64_SD | MSTATUS_FS | MSTATUS_MPP | MSTATUS_MPIE)
#endif

#ifndef PREEMPTION_THRESHOLD
#define PREEMPTION_THRESHOLD(core)                                                                                              \
                                do {                                                                                            \
                                    extern  proc_t  *vKern_runProc[KNB_CORES];                                                  \
                                                                                                                                \
                                    if (vKern_runProc[(uint32_t)core]->oSpecification.oPriority > KKERN_PRIORITY_LOW_00) {      \
                                        PREEMPTION;                                                                             \
                                    }                                                                                           \
                                } while (0)
#endif

// Elevation macros
// ----------------

#ifndef PRIVILEGE_ELEVATE
#define PRIVILEGE_ELEVATE
#endif

#ifndef PRIVILEGE_RESTORE
#define PRIVILEGE_RESTORE
#endif

#ifndef RIGHTS_ELEVATION
#define RIGHTS_ELEVATION
#endif

#ifndef SET_USER_MODE
#define SET_USER_MODE
#endif

#ifndef SET_PRIVILEGED_MODE
#define SET_PRIVILEGED_MODE
#endif

#ifndef GET_ADDRESS_ELEVATION_CALLER
#define GET_ADDRESS_ELEVATION_CALLER
#endif

#ifndef GET_ADDRESS_CALLER
#define GET_ADDRESS_CALLER(address)
#endif

#ifndef CALL_FNCT_ELEVATION
#define CALL_FNCT_ELEVATION(function)
#endif

#ifndef KERN_RETURN_ELEVATION
#define KERN_RETURN_ELEVATION
#endif

// Interruption macros
// -------------------

#ifndef KPROCESS_INIT_MCAUSE
#define KPROCESS_INIT_MCAUSE    (MCAUSE_INTERRUPT | 11U)
#endif

#ifndef RETURN_INT_RESTORE
#define RETURN_INT_RESTORE(status)                                                                                              \
                                INTERRUPTION_RESTORE;                                                                           \
                                return (status)
#endif


#ifndef WAITING_INTERRUPTION
#define WAITING_INTERRUPTION    __asm volatile ("                                                                            \n \
                                wfi"                                                                                            \
                                )
#endif

#ifndef GET_CURRENT_PROCESS_STACK
#define GET_CURRENT_PROCESS_STACK(stack)                                                                                        \
                                __asm volatile ("                                                                            \n \
                                add         %0,x0,sp"                                                                           \
                                : "=r" (stack)                                                                                  \
                                :                                                                                               \
                                :                                                                                               \
                                )
#endif

// Vector registration macros
// --------------------------
// Moved from macros_soc.h for IWYU compliance (eliminates circular dependency)
// K210 has PLIC-based interrupt architecture with three types of vectors
// (extern declarations remain in K210 macros_soc.h as they use SoC-specific constants)

#define INT_EXCEPTION_VECTOR(vectorNb, address)                                                                                 \
                                vExce_intExcVectors[GET_RUNNING_CORE][vectorNb] = address

#define INT_INTERRUPT_VECTOR(vectorNb, address)                                                                                 \
                                vExce_intIntVectors[GET_RUNNING_CORE][vectorNb] = address

#define EXT_INTERRUPT_VECTOR(vectorNb, address)                                                                                 \
                                vExce_extIntVectors[GET_RUNNING_CORE][vectorNb] = address

// Misc assembler macro
// --------------------

#ifndef NOP
#define NOP                     __asm volatile ("                                                                            \n \
                                nop"                                                                                            \
                                )
#endif

#ifndef JUMP_FNCT
#define JUMP_FNCT(function)                                                                                                     \
                                __asm volatile ("                                                                            \n \
                                j           "#function                                                                          \
                                )
#endif
