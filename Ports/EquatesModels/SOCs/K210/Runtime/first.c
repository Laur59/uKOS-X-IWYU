/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Vectors for the uKOS-X system (first).
 */

#include    <stdint.h>

#include    "core.h"
#include    "core_reg.h"
#include    "crt0.h"
#include    "macros.h"
#include    "macros_soc.h"
#include    "soc_reg.h"

// Prototypes

extern  void        cmns_wait(uint32_t us);

static  void        local_interruptions(uint32_t core, uint64_t number);
static  void        local_exception(uint32_t core, uint64_t number, uint64_t message);

[[gnu::naked]]
void    Reset_Handler(uint32_t core) {

    #ifndef __clang__
    UNUSED(core);
    #endif

    __asm volatile ("j  local_reset");
}
void    local_reset(uint32_t core) {

    if (core == KCORE_0) {

        __asm volatile ("la sp,linker_topStackFirst_C0");

        crt0();
    }
    else {
        if (KNB_CORES == 1) {

// cppcheck-suppress premium-infiniteLoop
//
            while (true) { __asm volatile ("wfi"); }
        }

        __asm volatile ("la sp,linker_topStackFirst_C1");

// Waiting for about 1000-mS.
// Let the core 0 to initialise the memory and the interruptions (crt0_r_mc & exce)
// before continuing with other cores.
// A better synchro (e.g. by wfi & interruption will be implemented later)

        cmns_wait(1000000);
        crt0();
    }
}

// RISC-V Processor internal interruptions & exceptions
// ----------------------------------------------------
//
// The RISC-V (RV64) of the K210 includes a CLIC & PLIC interruption controller
// The CLIC is responsible to handle internal interruptions & Exceptions
//
// mcause bits 62..0 contains the number of the interruption/exception number
//          mcause bit 63 = 1 (interruptions)           mcause bit 63 = 0 (exceptions)
//          number = 11, PLIC sub vectors               number = 11, ECALL
//
//          Internal interruptions                      Internal exceptions
//
// 0        User Software Interrupt                     Instruction Address Misaligned
// 1        Supervisor Software Interrupt               Instruction Access Fault
// 2        Reserved                                    Illegal Instruction
// 3        Machine Software Interrupt                  Breakpoint
// 4        User Timer Interrupt                        Load Address Misaligned
// 5        Supervisor Timer Interrupt                  Load Access Fault
// 6        Reserved                                    Store/AMO Address Misaligned
// 7        Machine Timer Interrupt                     Store/AMO Access Fault
// 8        User External Interrupt                     Environment Call from U-mode
// 9        Supervisor External Interrupt               Environment Call from S-mode
// 10       Reserved                                    Reserved
// 11 >>>>> Machine External Interrupt (PLIC)     >>>>> Environment Call from M-mode
// 12                                                   Instruction Page Fault
// 13                                                   Load Page Fault
// 14                                                   Reserved
// 15                                                   Store/AMO Page Fault
//
// The PLIC uses the internal interruption number 11 (IINT_MACHINE_EXTERNAL)
// to dispatch the peripheral interruptions
//
// Important. Verify the .lst file to be sure that the [[gnu::interrupt]]
// Generate the correct stack frame. The preamble has to be:
// The stack frame change from gcc-13, gcc-14 and clang

[[gnu::interrupt, gnu::aligned(16)]]
void    first_handle_trap(void) {
    uint64_t    message, cause;
    uint32_t    core;

// Recover the message (in case of an ECALL)
// Signale "isException*

    __asm volatile ("                                               \n \
    add         %0,a0,zero"                                            \
    : "=r" (message)                                                   \
    );

    core  = GET_RUNNING_CORE;
    cause = core_getCSR(RV_CSR_MCAUSE);

    vExce_isException[core] = true;

// Internal interruption calls
// Internal exception calls

    if ((cause & MCAUSE_INTERRUPT) != 0) { local_interruptions(core, cause & MCAUSE_CAUSE);      }
    else                                 { local_exception(core, cause & MCAUSE_CAUSE, message); }

    vExce_isException[core] = false;
}

/*
 * \brief local_interruptions
 *
 * - Internal interruption
 *   The number 11, is the Machine External Interrupt (PLIC dispatcher)
 *
 */
[[gnu::noinline]]
static  void    local_interruptions(uint32_t core, uint64_t number) {
    void    (*go)(uint32_t core, uint64_t number);

    go = vExce_intIntVectors[core][number];
    (*go)(core, number);
}

/*
 * \brief local_exception
 *
 * - Internal exceptions
 *   The number 11, is the Environment Call from M-mode (ECALL dispatcher)
 *
 */
[[gnu::noinline]]
static  void    local_exception(uint32_t core, uint64_t number, uint64_t message) {
    void        (*go)(uint32_t core, uint64_t parameter);
    uint64_t    newPC, parameter;

    newPC = core_getCSR(RV_CSR_MEPC);
    newPC += 4;
    core_putCSR(RV_CSR_MEPC, newPC);

    parameter = (number == IEXC_ENVIRONMENTAL_CALL_M_MODE) ? message : number;

    go = vExce_intExcVectors[core][number];
    (*go)(core, parameter);
}

/*
 * \brief first_handle_MachineExternal
 *
 * !!! This handle is initialised by the exec.c
 *
 * - Machine external interruptions
 *   PLIC dispatcher
 *
 */
void    first_handle_MachineExternal(uint32_t core, uint64_t parameter) {
    void        (*go)(uint32_t core, uint64_t number);
    uint64_t    number;

    UNUSED(parameter);

    number = (uint64_t)plic->targets.target[core].claim_complete;

    go = vExce_extIntVectors[core][number];
    (*go)(core, number);
}

/*
 * \brief first_handle_EnvironmentalCallM
 *
 * !!! This handle is initialised by the exec.c
 *
 * - Machine internal exception
 *   ECALL dispatcher
 *
 */
void    first_handle_EnvironmentalCallM(uint32_t core, uint64_t message) {
    void    (*go)(uint32_t core, uint64_t message);

    go = vMsgs_process[core];
    (*go)(core, message);
}
