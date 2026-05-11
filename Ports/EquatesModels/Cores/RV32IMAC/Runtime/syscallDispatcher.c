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
void kernel_message_C0(void) {}

#if (KNB_CORES == 2)
[[gnu::weak]]
void kernel_message_C1(void) {}
#endif

/*
 * \brief syscallDispatcher
 *
 * - Routes ecall to the kernel context-switch entry point based on vMessage.
 * - Registered in vExce_indExcVectors[core][11] by exce_init().
 *
 */
void    syscallDispatcher(void) {

    #if (KNB_CORES == 2)
    if (GET_RUNNING_CORE == KCORE_0) {
        kernel_message_C0();
    }
    else {
        kernel_message_C1();
    }
    #else
    kernel_message_C0();
    #endif

    // KPRIV_ELEVATION is a no-op on RV32IMAC (no U-mode in this build).
}
