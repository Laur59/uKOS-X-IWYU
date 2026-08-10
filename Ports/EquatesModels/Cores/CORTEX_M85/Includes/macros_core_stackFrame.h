/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Stack frame management macros.
 *           This file conains the most sensitive macros
 *           for the uKernel management
 */

#pragma once

#include    <stdlib.h>      // IWYU pragma: keep (for exit)

#include    "Registers/core_debug.h"
#include    "crt0.h"        // IWYU pragma: keep (for exit_terminate)
#include    "kern/kern.h"
#include    "macros_soc.h"
#include    "record/record.h"
#include    "types.h"       // IWYU pragma: keep (for EXIT_OS_PANIC_STACK_UNDERFLOW)

// For the stack sanity

#if (!defined(KMAGICSTACK))
#define KMAGICSTACK             (((uint32_t)'u'<<24U) | ((uint32_t)'K'<<16U) | ((uint32_t)'O'<<8U) | (uint32_t)'S')
#endif

#if (!defined(BREAK_IFDEBUGGING))
#define BREAK_IFDEBUGGING       if ((REG(CoreDebug)->DEMCR & CoreDebug_DEMCR_TRCENA) != 0U) {                                   \
                                    __asm volatile ("bkpt       #1");                                                           \
                                }
#endif

#if (!defined(CHECK_STACK_SANITY))
extern              proc_t  *vKern_runProc[KNB_CORES];
#define CHECK_STACK_SANITY(core)                                                                                                \
                                if ((vKern_runProc[core]->oInternal.oState != 0U) &&                                            \
                                    ((vKern_runProc[core]->oInternal.oState & (1U<<BPROC_FIRST)) == 0U)) {                      \
                                    if ((vKern_runProc[core]->oSpecification.oStackStart > vKern_stackProc[core]) ||            \
                                        (vKern_runProc[core]->oSpecification.oStackStart[core] != KMAGICSTACK)) {               \
                                        LOG(KFATAL_KERNEL, "kern: stack underflow");                                            \
                                        BREAK_IFDEBUGGING;                                                                      \
                                        exit(EXIT_OS_PANIC_STACK_UNDERFLOW);                                                    \
                                    }                                                                                           \
                                }
#endif

// Stack alignment (see processes.h)

#if (!defined(KSTACK_ALIGNMENT))
#define KSTACK_ALIGNMENT        (8U)
#define KSTACK_ALIGNMENT_MASK   (~(KSTACK_ALIGNMENT - 1U))
#define KSTACK_ALIGNMENT_MEMO   (KMEMO_ALIGN_8)
#endif

// Critical stack size when < (51+10) 32-bit words (stack frame + reserve)

#if (!defined(KKERN_CRITICAL_SZ_STACK))
#define KKERN_CRITICAL_SZ_STACK     (51U + 10U)
#endif

// Stack sizes (in machine words of 32-bit)

#if (!defined(KKERN_SZ_STACK_SS))
#define KKERN_SZ_STACK_SS           200U
#endif
#if (!defined(KKERN_SZ_STACK_MM))
#define KKERN_SZ_STACK_MM           400U
#endif
#if (!defined(KKERN_SZ_STACK_LL))
#define KKERN_SZ_STACK_LL           600U
#endif
#if (!defined(KKERN_SZ_STACK_XL))
#define KKERN_SZ_STACK_XL           1000U
#endif
#if (!defined(KKERN_SZ_STACK_MIN))
#define KKERN_SZ_STACK_MIN          300U
#endif
#if (!defined(KKERN_SZ_STACK_XLIB))
#define KKERN_SZ_STACK_XLIB         (400U + 1000U)
#endif
#if (!defined(KKERN_SZ_STACK_MPY))
#define KKERN_SZ_STACK_MPY          (400U + 1000U)
#endif

// Stack frame macros
// ------------------

// Prepare the stack frame
//
// The stack has to be aligned on boundary of 8-bytes
// In this case the (68 + 4) mod 8 has to be 0
//
//  +68 xPSR        = 0x01000000
//  +64 pc          = process address
//  +60 lr          = address of the routine exit_terminate()
//  +56 r12         =
//  +52 r3          =
//  +48 r2          =
//  +44 r1          = init registers
//  +40 r0          = process arguments
//  +36 r11         =
//  +32 r10         =
//  +28 r9          =
//  +24 r8          =
//  +20 r7          =
//  +16 r6          =
//  +12 r5          =
//  +8  r4          = init registers
//  +4  basepri     = NVIC priority
//  +0  0xFFFFFFFD  = Initial exception return (Thread mode without FPU, SP = PSP)

#if (!defined(KERN_PREPARE_FRAME))
#define KERN_PREPARE_FRAME(stack, code, core, argument, priority)                                                               \
                                *(--stack) = 0x01000000U;                                                                       \
                                *(--stack) = (uintptr_t)code;                                                                   \
                                *(--stack) = (uintptr_t)exit_terminate;                                                         \
                                *(--stack) = 0x12121212U;                                                                       \
                                *(--stack) = 0x03030303U;                                                                       \
                                *(--stack) = 0x02020202U;                                                                       \
                                *(--stack) = 0x01010101U;                                                                       \
                                *(--stack) = (uintptr_t)argument;                                                               \
                                *(--stack) = 0x11111111U;                                                                       \
                                *(--stack) = 0x10101010U;                                                                       \
                                *(--stack) = 0x09090909U;                                                                       \
                                *(--stack) = 0x08080808U;                                                                       \
                                *(--stack) = 0x07070707U;                                                                       \
                                *(--stack) = 0x06060606U;                                                                       \
                                *(--stack) = 0x05050505U;                                                                       \
                                *(--stack) = 0x04040404U;                                                                       \
                                *(--stack) = ((uintptr_t)priority<<(uintptr_t)KNVIC_PRIORITY_SHIFT);                            \
                                *(--stack) = 0xFFFFFFFDU;                                                                       \
                                UNUSED(core)
#endif

// Recover the message & save the frame message
//
//  +108 (104)  Message                 uKOS-X message
//  +104 (100)  Message                 uKOS-X message
//  +100        (possible aligner)      (implementation dependent)
//  +96         FPSCR
//  +92         s15..s0
//  +28         xPSR
//  +24         pc
//  +20         lr
//  +16         r12
//  +12         r3
//  +8          r2
//  +4          r1
//  +0          r0  <-- Stacked automatically
//  -32         r11..r4
//  -36         basepri
//  -100        s31..s16
//  -104        lr  <-- Stacked manually
//
// Prepare for the model
//
// r0 -> *stack
// r1 -> message

#if (!defined(KERN_RECOVER_MESSAGE))
#define KERN_RECOVER_MESSAGE    __asm volatile ("                                                                            \n \
                                tst         lr,#0x4                                                                          \n \
                                ite         eq                                                                               \n \
                                mrseq       r0,msp                                                                           \n \
                                mrsne       r0,psp                                                                           \n \
                                add         r1,r0,#(32+4)                                                                    \n \
                                tst         lr,#0x10                                                                         \n \
                                it          eq                                                                               \n \
                                addeq       r1,r0,#(32+68+4)                                                                 \n \
                                ldr         r1,[r1]"                                                                            \
                                )
#endif

#if (!defined(KERN_SAVE_FRAME_MESSAGE))
#define KERN_SAVE_FRAME_MESSAGE __asm volatile ("                                                                            \n \
                                mrs         r2,basepri                                                                       \n \
                                stmdb       r0!,{r2,r4-r11}                                                                  \n \
                                tst         lr,#0x10                                                                         \n \
                                it          eq                                                                               \n \
                                vstmdbeq    r0!,{s16-s31}                                                                    \n \
                                stmdb       r0!,{lr}                                                                         \n \
                                tst         lr,#0x4                                                                          \n \
                                ite         eq                                                                               \n \
                                msreq       msp,r0                                                                           \n \
                                msrne       psp,r0"                                                                             \
                                )
#endif

// Save the frame
//
//  +96         FPSCR
//  +92         s15..s0
//  +28         xPSR
//  +24         pc
//  +20         lr
//  +16         r12
//  +12         r3
//  +8          r2
//  +4          r1
//  +0          r0      <-- Stacked automatically
//  -32         r11..r4
//  -36         basepri
//  -100        s31..s16
//  -104        lr      <-- Stacked manually
//
// Prepare for the model
//
// r0 -> *stack

#if (!defined(KERN_SAVE_FRAME_NORMAL))
#define KERN_SAVE_FRAME_NORMAL  __asm volatile ("                                                                            \n \
                                tst         lr,#0x4                                                                          \n \
                                ite         eq                                                                               \n \
                                mrseq       r0,msp                                                                           \n \
                                mrsne       r0,psp                                                                           \n \
                                mrs         r1,basepri                                                                       \n \
                                stmdb       r0!,{r1,r4-r11}                                                                  \n \
                                tst         lr,#0x10                                                                         \n \
                                it          eq                                                                               \n \
                                vstmdbeq    r0!,{s16-s31}                                                                    \n \
                                stmdb       r0!,{lr}                                                                         \n \
                                tst         lr,#0x4                                                                          \n \
                                ite         eq                                                                               \n \
                                msreq       msp,r0                                                                           \n \
                                msrne       psp,r0"                                                                             \
                                )
#endif

// New frame
//
//  -104        lr
//  -100        s31..s16
//  -36         basepri
//  -32         r4..r11 <-- De-stacked manually
//  +0          r0
//  +4          r1
//  +8          r2
//  +12         r3
//  +16         r12
//  +20         lr
//  +24         pc
//  +28         xPSR
//  +92         s15..s0
//  +96         FPSCR   <-- De-stacked automatically
//
// Prepare for the model
//
// r0 -> *stack of the new process

#if (!defined(KERN_NEW_FRAME))
#define KERN_NEW_FRAME          __asm volatile ("                                                                            \n \
                                ldmia       r0!,{lr}                                                                         \n \
                                tst         lr,#0x10                                                                         \n \
                                it          eq                                                                               \n \
                                vldmiaeq    r0!,{s16-s31}                                                                    \n \
                                ldmia       r0!,{r1,r4-r11}                                                                  \n \
                                tst         lr,#0x4                                                                          \n \
                                ite         eq                                                                               \n \
                                msreq       msp,r0                                                                           \n \
                                msrne       psp,r0                                                                           \n \
                                msr         basepri,r1"                                                                         \
                                )
#endif

// Return to a new context

#if (!defined(KERN_RETURN))
#define KERN_RETURN             __asm volatile ("                                                                            \n \
                                dmb                                                                                          \n \
                                dsb                                                                                          \n \
                                isb                                                                                          \n \
                                bx          lr"                                                                                 \
                                )
#endif

// Messages: _I (immediate) _M (memory)

#if (!defined(GOTO_KERN_I))
#define GOTO_KERN_I(msg)        stub_kern_stopProcessTimeout();                                                                 \
                                __asm volatile ("                                                                            \n \
                                movw        r0,%0                                                                            \n \
                                movt        r0,%1                                                                            \n \
                                push        {r0}                                                                             \n \
                                push        {r0}"                                                                               \
                                :                                                                                               \
                                : "i" ((msg) & 0x0000FFFFU), "i" ((msg)>>16U)                                                   \
                                : "r0"                                                                                          \
                                );                                                                                              \
                                __asm volatile ("                                                                            \n \
                                svc         %0                                                                               \n \
                                dmb                                                                                          \n \
                                dsb                                                                                          \n \
                                isb                                                                                          \n \
                                mrs         r0,psp                                                                           \n \
                                add         r0,r0,#8                                                                         \n \
                                msr         psp,r0"                                                                             \
                                :                                                                                               \
                                : "i" (KKERN_MESSAGE)                                                                           \
                                : "r0"                                                                                          \
                                )
#endif

#if (!defined(GOTO_KERN_M))
#define GOTO_KERN_M(msg)        stub_kern_stopProcessTimeout();                                                                 \
                                __asm volatile ("                                                                            \n \
                                push        {%0}                                                                             \n \
                                push        {%0}"                                                                               \
                                :                                                                                               \
                                : "r" (msg)                                                                                     \
                                :                                                                                               \
                                );                                                                                              \
                                __asm volatile ("                                                                            \n \
                                svc         %0                                                                               \n \
                                dmb                                                                                          \n \
                                dsb                                                                                          \n \
                                isb                                                                                          \n \
                                mrs         r0,psp                                                                           \n \
                                add         r0,r0,#8                                                                         \n \
                                msr         psp,r0"                                                                             \
                                :                                                                                               \
                                : "i" (KKERN_MESSAGE)                                                                           \
                                : "r0"                                                                                          \
                                )
#endif

// Core dump register collection
//
//  +96         FPSCR
//  +92         s15..s0
//  +28         xPSR
//  +24         pc
//  +20         lr
//  +16         r12
//  +12         r3
//  +8          r2
//  +4          r1
//  +0          r0      <-- Stacked automatically
//  -32         r11..r4
//  -36         basepri
//  -100        s31..s16
//  -104        lr
//  -108        psp
//  -112        msp     <-- Stacked manually
//  -116        spp
//
// Prepare for the model
//
// r0 -> *stackBefore saving the frame
// r1 -> *stackAfter having saved the frame

enum {
        SPP = 0U,                                                                           // spp + 0
        PSP, MSP,                                                                           // spp + 1..2
        LR,                                                                                 // spp + 3
        s16, s17, s18, s19, s20, s21, s22, s23, s24, s25, s26, s27, s28, s29, s30, s31,     // spp + 4..19
        BASEPRI,                                                                            // spp + 20
        r04, r05, r06, r07, r08, r09, r10, r11, r00, r01, r02, r03, r12, r14,               // spp + 21..34
        PC, xPSR,                                                                           // spp + 35..36
        s00, s01, s02, s03, s04, s05, s06, s07, s08, s09, s10, s11, s12, s13, s14, s15,     // spp + 37..52
        FPSCR,                                                                              // spp + 53
        ENDREG                                                                              // spp + 54
};

// IMPORTANT!
// On exception entry, Cortex-M automatically stacks the basic CPU context.
// model_coreDump_displayExceptions(lr, msp) receives:
//   - r0 = lr  : EXC_RETURN value
//   - r1 = msp : Main Stack Pointer value at handler entry
//
// This macro reconstructs the interrupted stack context, detects whether
// MSP or PSP was active before the exception, then saves the additional
// registers required for core dump analysis.
//
// Output:
//   - r0 = pointer to the original stacked context (stackBefore)
//   - r1 = pointer to the extended saved context (stackAfter)
//
// These outputs match the ABI expected by:
//   local_processException(uintptr_t *stackBefore, uintptr_t *stackAfter)

#if (!defined(CORE_DUMP_SAVE_STACK_FRAME))
#define CORE_DUMP_SAVE_STACK_FRAME                                                                                              \
                                __asm volatile ("                                                                            \n \
                                cpsid       i                                                                                \n \
                                mov         lr,r0                                                                            \n \
                                msr         msp,r1                                                                           \n \
                                tst         lr,#0x4                                                                          \n \
                                ite         eq                                                                               \n \
                                mrseq       r1,msp                                                                           \n \
                                mrsne       r1,psp                                                                           \n \
                                push        {r1}                                                                             \n \
                                mrs         r2,basepri                                                                       \n \
                                stmdb       r1!,{r2,r4-r11}                                                                  \n \
                                vstmdb      r1!,{s16-s31}                                                                    \n \
                                stmdb       r1!,{lr}                                                                         \n \
                                mrs         r2,msp                                                                           \n \
                                stmdb       r1!,{r2}                                                                         \n \
                                mrs         r2,psp                                                                           \n \
                                stmdb       r1!,{r2}                                                                         \n \
                                pop         {r0}"                                                                               \
                                )
#endif
