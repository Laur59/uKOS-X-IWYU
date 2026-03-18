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
#include    "macros_core_stackFrame.h"
#include    "macros_soc.h"
#include    "types.h"

extern  void    kernel_message_C0(void);

/*
 * \brief SVCall_IRQHandler_Cx
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
 */
[[gnu::naked]]
void    SVCall_C0_IRQHandler(void) {

// Branch to     --> kernel_message
// Branch to     --> kern_privilegeElevate

    SVC_DISPATCHER_C0;
}

#if (KNB_CORES == 2)
extern  void    kernel_message_C1(void);

[[gnu::naked]]
void    SVCall_C1_IRQHandler(void) {

// Branch to     --> kernel_message
// Branch to     --> kern_privilegeElevate

    SVC_DISPATCHER_C1;
}
#endif

[[noreturn]]
void    syscall(const uintptr_t *arg) {

    UNUSED(arg);

    LOG(KFATAL_SYSTEM, "syscallDispatcher: no system call");
    exit(EXIT_OS_PANIC_NO_SYSCALL);
}
