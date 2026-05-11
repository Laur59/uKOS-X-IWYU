/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Important macros.
 */

#pragma once

#include    "Registers/core_addendum.h"
#include    "Registers/core_debug.h"
#include    "Registers/scb.h"   // IWYU pragma: export
#include    "Registers/soc_vectors.h"
#include    "exce.h"
#include    "kern/kern.h"
#include    "linker.h"
#include    "core.h"    // IWYU pragma: keep
#include    "macros_soc.h"
#include    "memo/memo.h"       // IWYU pragma: keep for KMEMO_ALIGN_8
#include    "syscallDispatcher.h"

// uKernel macros
// --------------

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

// Core machine in bits

#define KMACHINE_BITS           (32U)

// Preemptions

#ifndef PREEMPTION
#define PREEMPTION              stub_kern_stopProcessTimeout();                                                                 \
                                REG(SCB)->ICSR = (1U<<BKERN_PREEMPTION);                                                        \
                                __asm volatile ("                                                                            \n \
                                sev"                                                                                            \
                                );                                                                                              \
                                MEMO_SYNC_BARRIER;                                                                              \
                                DATA_SYNC_BARRIER;                                                                              \
                                INST_SYNC_BARRIER;
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
#ifdef PRIVILEGED_USER_S
#define PRIVILEGE_ELEVATE       kern_setPrivilegeMode(KPROC_PRIVILEGED)

#else
#define PRIVILEGE_ELEVATE
#endif
#endif

#ifndef PRIVILEGE_RESTORE
#ifdef PRIVILEGED_USER_S
#define PRIVILEGE_RESTORE       kern_setPrivilegeMode(KPROC_USER)

#else
#define PRIVILEGE_RESTORE
#endif
#endif

#ifndef RIGHTS_ELEVATION
#define RIGHTS_ELEVATION        __asm volatile ("                                                                            \n \
                                .global     priv_returnElevation                                                             \n \
                                svc         %0                                                                               \n \
                                priv_returnElevation:"                                                                          \
                                :                                                                                               \
                                : "i" (KPRIV_ELEVATION)                                                                         \
                                :                                                                                               \
                                );                                                                                              \
                                MEMO_SYNC_BARRIER;                                                                              \
                                DATA_SYNC_BARRIER;                                                                              \
                                INST_SYNC_BARRIER;
#endif

#ifndef SET_USER_MODE
#define SET_USER_MODE           core_setCONTROL(core_getCONTROL() | CONTROL_SET_USER_MODE);                                     \
                                INST_SYNC_BARRIER
#endif

#ifndef SET_PRIVILEGED_MODE
#define SET_PRIVILEGED_MODE     core_setCONTROL(core_getCONTROL() & ~CONTROL_SET_USER_MODE);                                    \
                                INST_SYNC_BARRIER
#endif

#ifndef GET_ADDRESS_ELEVATION_CALLER
#define GET_ADDRESS_ELEVATION_CALLER                                                                                            \
                                __asm volatile ("                                                                            \n \
                                tst         lr,#0x4                                                                          \n \
                                ite         eq                                                                               \n \
                                mrseq       r0,msp                                                                           \n \
                                mrsne       r0,psp                                                                           \n \
                                ldr         r0,[r0,#24]"                                                                        \
                                )
#endif

#ifndef GET_ADDRESS_CALLER
#define GET_ADDRESS_CALLER(address)                                                                                             \
                                address = core_getLR()
#endif

#ifndef CALL_FNCT_ELEVATION
#define CALL_FNCT_ELEVATION(function)                                                                                           \
                                __asm volatile ("                                                                            \n \
                                push        {lr}                                                                             \n \
                                mov         r1,%0                                                                            \n \
                                blx         r1                                                                               \n \
                                pop         {lr}"                                                                               \
                                :                                                                                               \
                                : "r" (function)                                                                                \
                                : "r0"                                                                                          \
                                )
#endif

#ifndef KERN_RETURN_ELEVATION
#define KERN_RETURN_ELEVATION   __asm volatile ("                                                                            \n \
                                bx          lr"                                                                                 \
                                )
#endif

// Interruption macros
// -------------------

#ifndef INTERRUPTION_SET
#define INTERRUPTION_SET        core_setBASEPRI((uint32_t)KINT_IMASK_ALL<<(uint32_t)KNVIC_PRIORITY_SHIFT)
#endif

#ifndef INTERRUPTION_SET_PERIPH
#define INTERRUPTION_SET_PERIPH core_setBASEPRI((uint32_t)KINT_IMASK_PERIPHERALS<<(uint32_t)KNVIC_PRIORITY_SHIFT)
#endif

#ifndef INTERRUPTION_OFF_HARD
#define INTERRUPTION_OFF_HARD   __asm volatile ("                                                                            \n \
                                cpsid       i                                                                                \n \
                                isb         0xF"                                                                                \
                                :                                                                                               \
                                :                                                                                               \
                                : "memory"                                                                                      \
                                )
#endif

#ifndef INTERRUPTION_ON_HARD
#define INTERRUPTION_ON_HARD    __asm volatile ("                                                                            \n \
                                cpsie       i                                                                                \n \
                                isb         0xF"                                                                                \
                                :                                                                                               \
                                :                                                                                               \
                                : "memory"                                                                                      \
                                )
#endif

#ifndef INTERRUPTION_OFF
#define INTERRUPTION_OFF        [[maybe_unused]] volatile    uint32_t    saveBASEPRI ;                                   \
                                                                                                                                \
                                saveBASEPRI = core_getBASEPRI();                                                                \
                                (void)saveBASEPRI;                                                                              \
                                core_setBASEPRI((uint32_t)KINT_IMASK_OFF<<(uint32_t)KNVIC_PRIORITY_SHIFT)
#endif

#ifndef INTERRUPTION_RESTORE
#define INTERRUPTION_RESTORE    core_setBASEPRI(saveBASEPRI)
#endif

#ifndef RETURN_INT_RESTORE
#define RETURN_INT_RESTORE(status)                                                                                              \
                                INTERRUPTION_RESTORE;                                                                           \
                                return status
#endif

#ifndef INTERRUPTION_OFF_CRITICAL
#define INTERRUPTION_OFF_CRITICAL(savemMask)                                                                                    \
                                savemMask = core_getBASEPRI();                                                                  \
                                core_setBASEPRI((uint32_t)KINT_IMASK_OFF<<(uint32_t)KNVIC_PRIORITY_SHIFT)
#endif

#ifndef INTERRUPTION_RESTORE_CRITICAL
#define INTERRUPTION_RESTORE_CRITICAL(savemMask)                                                                                \
                                core_setBASEPRI(savemMask)
#endif

#ifndef WAITING_INTERRUPTION
#define WAITING_INTERRUPTION    DATA_SYNC_BARRIER;                                                                              \
                                __asm volatile ("                                                                            \n \
                                wfi"                                                                                            \
                                );                                                                                              \
                                INST_SYNC_BARRIER;
#endif

#ifndef IS_EXCEPTION
#define IS_EXCEPTION            ((REG(SCB)->ICSR & 0x000001FFU) != 0U)
#endif

#ifndef GET_CURRENT_PROCESS_STACK
#define GET_CURRENT_PROCESS_STACK(stack)                                                                                        \
                                stack = core_getPSP()
#endif

#ifndef EXCEPTION_SPECIFIC_HANDLER
#define KEXCEPTION              0U

extern  volatile    bool    vPriv_insideException[KNB_CORES];
[[noreturn]]
extern              void    model_coreDump_displayExceptions(uintptr_t lr, uintptr_t *msp);

#define EXCEPTION_SPECIFIC_HANDLER(exc)                                                                                         \
                                [[gnu::used]]                                                                                   \
                                static void exc##_local_IRQHandler(uintptr_t lr, uintptr_t *msp) {                              \
                                    uint32_t    core = GET_RUNNING_CORE;                                                        \
                                    void        (*go)(void);                                                                    \
                                                                                                                                \
                                    go = vExce_indExcVectors[core][(int32_t)exc##_IRQn + (int32_t)KNB_EXCEPTIONS];              \
                                    if (go == nullptr) {                                                                        \
                                        model_coreDump_displayExceptions(lr, msp);                                              \
                                    }                                                                                           \
                                    vPriv_insideException[core] = true;                                                         \
                                    (*go)();                                                                                    \
                                    vPriv_insideException[core] = false;                                                        \
                                }                                                                                               \
                                                                                                                                \
                                [[gnu::weak, gnu::naked]]                                                                       \
                                void exc##_IRQHandler(void) {                                                                   \
                                                                                                                                \
                                    __asm volatile ("                                                                        \n \
                                    mov         r0,lr                                                                        \n \
                                    mrs         r1,msp"                                                                         \
                                    );                                                                                          \
                                    JUMP_FNCT(exc##_local_IRQHandler);                                                          \
                                }
#endif

#ifndef INTERRUPT_SPECIFIC_HANDLER
#define KINTERRUPTION           1U

[[noreturn]]
extern  void    model_coreDump_displayInterruptions(uintptr_t lr, uintptr_t *msp);

#define INTERRUPT_SPECIFIC_HANDLER(irq)                                                                                         \
                                [[gnu::used]]                                                                                   \
                                static void irq##_local_IRQHandler(uintptr_t lr, uintptr_t *msp) {                              \
                                    uint32_t    core = GET_RUNNING_CORE;                                                        \
                                    void        (*go)(void);                                                                    \
                                                                                                                                \
                                    go = vExce_indIntVectors[core][(int32_t)irq##_IRQn];                                        \
                                    if (go == nullptr) {                                                                        \
                                        model_coreDump_displayInterruptions(lr, msp);                                           \
                                    }                                                                                           \
                                    TIC_EXCEPTION_TIME;                                                                         \
                                    (*go)();                                                                                    \
                                    TAC_EXCEPTION_TIME(core);                                                                   \
                                }                                                                                               \
                                                                                                                                \
                                [[gnu::weak, gnu::naked]]                                                                       \
                                void irq##_IRQHandler(void) {                                                                   \
                                                                                                                                \
                                    __asm volatile ("                                                                        \n \
                                    mov         r0,lr                                                                        \n \
                                    mrs         r1,msp"                                                                         \
                                    );                                                                                          \
                                    JUMP_FNCT(irq##_local_IRQHandler);                                                          \
                                }
#endif

// Vector registration macros
// --------------------------
// Moved from macros_soc.h for IWYU compliance (eliminates circular dependency)

#define EXCEPTION_VECTOR(vectorNb, address)                                                                                     \
                                vExce_indExcVectors[GET_RUNNING_CORE][(int32_t)vectorNb + (int32_t)KNB_EXCEPTIONS] = address

#define INTERRUPT_VECTOR(vectorNb, address)                                                                                     \
                                vExce_indIntVectors[GET_RUNNING_CORE][vectorNb] = address

// Misc assembler macro
// --------------------

#ifndef SET_PSP_STACK
#define SET_PSP_STACK(stack)    core_setPSP((uintptr_t)stack)
#endif

#ifndef SET_MSP_STACK
#define SET_MSP_STACK(stack)    core_setMSP((uintptr_t)stack)
#endif

#ifndef SET_THREAD_STACK
#define SET_THREAD_STACK(stack) __asm volatile ("                                                                            \n \
                                msr         psp,%0"                                                                             \
                                :                                                                                               \
                                : "r" (stack)                                                                                   \
                                :                                                                                               \
                                );                                                                                              \
                                core_setCONTROL(core_getCONTROL() | CONTROL_SET_PSP_STACK);                                     \
                                INST_SYNC_BARRIER
#endif

// Check in wich stack we are operating
// If we operate from the MSP
// - Copy the MSP to the PSP
// - Set the PSP as the active stack

#ifndef CHECKSET_THREAD_STACK
#define CHECKSET_THREAD_STACK   if (core_getPSP() == 0U) {                                                                      \
                                    core_setPSP(core_getMSP());                                                                 \
                                    core_setCONTROL(core_getCONTROL() | CONTROL_SET_PSP_STACK);                                 \
                                    INST_SYNC_BARRIER;                                                                          \
                                }
#endif

#ifndef NOP
#define NOP                     __asm volatile ("                                                                            \n \
                                nop"                                                                                            \
                                )
#endif

#ifndef DATA_SYNC_BARRIER
#define DATA_SYNC_BARRIER       __asm volatile ("                                                                            \n \
                                dsb         0xF"                                                                                \
                                :                                                                                               \
                                :                                                                                               \
                                : "memory"                                                                                      \
                                )
#endif

#ifndef INST_SYNC_BARRIER
#define INST_SYNC_BARRIER       __asm volatile ("                                                                            \n \
                                isb         0xF"                                                                                \
                                :                                                                                               \
                                :                                                                                               \
                                : "memory"                                                                                      \
                                )
#endif

#ifndef MEMO_SYNC_BARRIER
#define MEMO_SYNC_BARRIER       __asm volatile ("                                                                            \n \
                                dmb         0xF"                                                                                \
                                :                                                                                               \
                                :                                                                                               \
                                : "memory"                                                                                      \
                                )
#endif

#ifndef STRONG_BARRIER
#define STRONG_BARRIER          MEMO_SYNC_BARRIER;                                                                              \
                                DATA_SYNC_BARRIER;                                                                              \
                                INST_SYNC_BARRIER
#endif

#ifndef JUMP_FNCT
#define JUMP_FNCT(function)                                                                                                     \
                                __asm volatile ("                                                                            \n \
                                b           "#function                                                                          \
                                )
#endif

#ifndef CALL_FNCT
#define CALL_FNCT(function)                                                                                                     \
                                __asm volatile ("                                                                            \n \
                                bl          "#function                                                                          \
                                :                                                                                               \
                                :                                                                                               \
                                : "lr"                                                                                          \
                                )
#endif
