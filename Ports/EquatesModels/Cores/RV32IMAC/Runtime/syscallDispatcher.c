/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * RV32IMAC – Syscall dispatcher, called from vExce_indExcVectors[core][11].
 * first_dispatch_ecall() in first_riscv.c sets vMessage = a0 before calling here.
 */

#include    "syscallDispatcher.h"

#include    <stdint.h>

#include    "macros_core.h"
#include    "types.h"

// Weak stubs — overridden by the RISC-V kernel model in Phase 3.3.

[[gnu::weak]]
void kernel_message_C0(void) { }

#if (KNB_CORES == 2)
[[gnu::weak]]
void kernel_message_C1(void) { }
#endif

/*
 * \brief syscallDispatcher
 *
 * - Routes ecall to the kernel context-switch entry point based on vMessage
 * - Registered in vExce_indExcVectors[core][11] by exce_init()
 *
 */
void    syscallDispatcher(void) {
    uint32_t    core = GET_RUNNING_CORE;

    #ifdef PRIVILEGED_USER_S

// Privilege elevation / restoration (R5). RISC-V ecall carries no immediate (unlike ARM's
// svc #N), so the RIGHTS_ELEVATION / SET_USER_MODE ecalls in kern_setPrivilegeMode() are
// distinguished from kernel-message ecalls by the saved return address (mepc, frame word
// [0]), which equals the sanctioned priv_returnElevation / priv_returnRestore label (the
// label sits right after the ecall). Edit the saved frame's mstatus (word [2]) MPP field
// and return to the SAME process — no scheduler, no context switch; first_handle_trap then
// mret's back to it with the new privilege.

    extern  volatile    uintptr_t   vSaveStack[KNB_CORES];
    extern  uint8_t                 priv_returnElevation[];
    extern  uint8_t                 priv_returnRestore[];

    uint32_t    *frame = (uint32_t *)vSaveStack[core];
    uintptr_t   mepc   = (uintptr_t)frame[0];

    if (mepc == (uintptr_t)priv_returnElevation) {
        frame[2] |= (uint32_t)MSTATUS_MPP;          // elevate: MPP = 3 (M-mode)
        return;
    }
    if (mepc == (uintptr_t)priv_returnRestore) {
        frame[2] &= ~(uint32_t)MSTATUS_MPP;         // restore: MPP = 0 (U-mode)
        return;
    }
    #endif

    #if (KNB_CORES == 2)
    if (core == KCORE_0) {
        kernel_message_C0();
    }
    else {
        kernel_message_C1();
    }
    #else
    kernel_message_C0();
    #endif
}
