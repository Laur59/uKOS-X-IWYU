/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Important macros.
 */

#pragma once

#include    "Registers/rv32_bumblebee.h"
#include    "Registers/rv32_csr.h"
#include    "exce.h"
#include    "kern/kern.h"       // IWYU pragma: keep for KKERN_PRIORITY_LOW_00
#include    "macros_soc.h"
#include    "memo/memo.h"       // IWYU pragma: keep for KMEMO_ALIGN_16
// #include "macros_core_stackFrame.h"

// uKernel macros
// --------------

// For selecting Secure/NSecure (RISC-V M-mode maps to the Secure world on RP2350)

#ifdef SECURE_S
#define REG(x)                  (x ## _S)
#elif (defined(SECURE_NS))
#define REG(x)                  (x ## _NS)
#else
#define REG(x)                  (x ## _S)
#endif

#define SEC(x)                  (x ## _S)
#define NONSEC(x)               (x ## _NS)

// Core machine in bits

#define KMACHINE_BITS           (32U)

// Preemptions

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
#define KPROCESS_INIT_MCAUSE    (MCAUSE_INTERRUPT | RVBB_MCAUSE_MPP(3U) | RVBB_MCAUSE_MPIE | 11U)
#endif

#ifndef RETURN_INT_RESTORE
#define RETURN_INT_RESTORE(status)                                                                                              \
                                INTERRUPTION_RESTORE;                                                                           \
                                return (status)
#endif

#if (!defined(INTERRUPTION_OFF_HARD))
#define INTERRUPTION_OFF_HARD   core_clrBitCSR(RV_CSR_MSTATUS, MSTATUS_MIE)
#endif

#ifndef INTERRUPTION_ON_HARD
#define INTERRUPTION_ON_HARD    core_setBitCSR(RV_CSR_MSTATUS, MSTATUS_MIE)
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

#ifndef EXCEPTION_SPECIFIC_HANDLER
#define KEXCEPTION              0U

extern  bool    vExce_isException[KNB_CORES];

// Suppress the cppcheck warning for the following code portion
// ------------------------------------------------------------

#define EXCLUDE_CPPCHECK
#ifdef EXCLUDE_CPPCHECK

#define EXCEPTION_SPECIFIC_HANDLER(exc)                                                                                         \
                                [[gnu::used]]                                                                                   \
                                static void exc##_local_IRQHandler(void) {                                                      \
                                    uint32_t    core;                                                                           \
                                    void        (*go)(void);                                                                    \
                                                                                                                                \
                                    core = GET_RUNNING_CORE;                                                                    \
                                    vExce_isException[core] = true;                                                             \
                                    go = vExce_indExcVectors[core][exc##_IRQn];                                                 \
                                    (*go)();                                                                                    \
                                    vExce_isException[core] = false;                                                            \
                                }                                                                                               \
                                                                                                                                \
                                [[gnu::weak, gnu::naked]]                                                                       \
                                void exc##_IRQHandler(void) {                                                                   \
                                                                                                                                \
                                    INTERRUPTION_IN;                                                                            \
                                    CALL_FNCT(exc##_local_IRQHandler);                                                          \
                                    INTERRUPTION_OUT;                                                                           \
                                }
#endif

#else
#define EXCEPTION_SPECIFIC_HANDLER(irq)
#endif

#ifndef INTERRUPT_SPECIFIC_HANDLER
#define KINTERRUPTION           1U

extern  bool    vExce_isException[KNB_CORES];

// Suppress the cppcheck warning for the following code portion
// ------------------------------------------------------------

#define EXCLUDE_CPPCHECK
#ifdef EXCLUDE_CPPCHECK

#define INTERRUPT_SPECIFIC_HANDLER(irq)                                                                                         \
                                [[gnu::used]]                                                                                   \
                                static void irq##_local_IRQHandler(void) {                                                      \
                                    uint32_t    core;                                                                           \
                                    void        (*go)(void);                                                                    \
                                                                                                                                \
                                    core = GET_RUNNING_CORE;                                                                    \
                                    vExce_isException[core] = true;                                                             \
                                    go = vExce_indIntVectors[core][irq##_IRQn];                                                 \
                                    (*go)();                                                                                    \
                                    vExce_isException[core] = false;                                                            \
                                }                                                                                               \
                                                                                                                                \
                                [[gnu::weak, gnu::naked]]                                                                       \
                                void irq##_IRQHandler(void) {                                                                   \
                                                                                                                                \
                                    INTERRUPTION_IN;                                                                            \
                                    CALL_FNCT(irq##_local_IRQHandler);                                                          \
                                    INTERRUPTION_OUT;                                                                           \
                                }
#endif

#else
#define INTERRUPT_SPECIFIC_HANDLER(irq)
#endif

// Vector registration macros
// --------------------------

// Moved from macros_soc.h for IWYU compliance (eliminates circular dependency)

#define EXCEPTION_VECTOR(vectorNb, address)                                                                                         \
                                vExce_indExcVectors[GET_RUNNING_CORE][vectorNb] = address

#define INTERRUPT_VECTOR(vectorNb, address)                                                                                         \
                                vExce_indIntVectors[GET_RUNNING_CORE][vectorNb] = address

// Misc assembler macro
// --------------------

#ifndef NOP
#define NOP                     __asm volatile ("        \n \
                                nop"                        \
                                )
#endif

#ifndef INST_SYNC_BARRIER
#ifdef __riscv_zifencei
#define INST_SYNC_BARRIER       __asm volatile ("fence.i" ::: "memory")
#else
#define INST_SYNC_BARRIER       __asm volatile ("fence" ::: "memory")  // fallback, weaker
#endif
#endif

#ifndef DATA_SYNC_BARRIER
#define DATA_SYNC_BARRIER       __asm volatile ("        \n \
                                fence"                      \
                                :                           \
                                :                           \
                                : "memory"                  \
                                )
#endif

#ifndef JUMP_FNCT
#define JUMP_FNCT(function)                                 \
                                __asm volatile ("        \n \
                                j           "#function      \
                                )
#endif

#ifndef CALL_FNCT
#define CALL_FNCT(function)                                 \
                                __asm volatile ("        \n \
                                jal         "#function      \
                                )
#endif
