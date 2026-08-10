/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Syscall dispatcher.
 *               - uKernel messages
 *               - manager system calls
 */

#include    "syscallDispatcher.h"

#include    <stdint.h>
#include    <stdlib.h>

#include    "Lib_generics/record/record.h"
#include    "Registers/soc_vectors.h"
#include    "macros.h"
#include    "types.h"

/*
 * \brief SVCall_C0_IRQHandler
 *
 * Stack frame after the SVC(x) instruction
 *
 *  +92      ...
 *  +28      xPSR
 *  +24      pc
 *  +20      lr
 *  +16      r12
 *  +12      r3
 *  +8       r2
 *  +4       r1
 *  +0       r0
 *
 * Determine the current stack
 * If svc #0 ---> kernel_message_C0
 * If svc #1 ---> kern_privilegeElevate
 */
[[gnu::naked]]
void    SVCall_C0_IRQHandler(void) {

// Code of macro SVC_DISPATCHER_C0 moved from macros_core_stackFrame.h
    __asm volatile (
        "tst    lr,#0x4                         \n"
        "ite    eq                              \n"
        "mrseq  r0,msp                          \n"
        "mrsne  r0,psp                          \n"
        "ldr    r1,[r0,#24]                     \n"
        "ldrb.w r1,[r1,#-2]                     \n"
        "cmp    r1,#0                           \n"
        "bne.w  1f                              \n"
        "ldr.w  r2,=kernel_message_C0           \n"
        "bx     r2                              \n"
        "1:                                     \n"
#ifdef PRIVILEGED_USER_S
        "cmp    r1,#1                           \n"
        "bne.w  2f                              \n"
        "ldr.w  r2,=kern_privilegeElevate       \n"
        "bx     r2                              \n"
        "2:                                     \n"
#endif
        "push   {lr}                            \n"
        "bl     syscall                         \n"
        "pop    {lr}                            \n"
        "tst    lr,#0x4                         \n"
        "ite    eq                              \n"
        "mrseq  r1,msp                          \n"
        "mrsne  r1,psp                          \n"
        "str    r0,[r1,#0]                      \n"
        "bx     lr                              \n"
    );
}

[[noreturn]]
void    syscall(const uintptr_t *arg) {

    UNUSED(arg);

    LOG(KFATAL_SYSTEM, "syscallDispatcher: no system call");
    exit(EXIT_OS_PANIC_NO_SYSCALL);
}
