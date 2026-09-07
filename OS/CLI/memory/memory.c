/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Give the memory information.
 */

#include    <inttypes.h>
#include    <stdio.h>

#include    "kern/kern.h"
#include    "linker.h"
#include    "macros.h"
#include    "macros_core.h"
#include    "macros_soc.h"
#if (KNB_CORES > 1)
#include    "memo/memo.h"               // vMemo is only referenced via SPIN_LOCK on multi-core builds
#endif
#include    "memo/private/private_memo.h"
#include    "modules.h"
#include    "serial/serial.h"
#include    "spin.h"
#include    "types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "memory       Give the memory section information.      (c) EFr-2026";

#ifdef PRIVILEGED_USER_S
STRG_LOC_CONST(aStrHelp[])        = "Give the memory information\n"
                                    "===========================\n\n"

                                    "This tool displays information about the memory\n"
                                    "section (DATA/CODE) of the system.\n\n"

                                    "Input format:  memory\n"
                                    "Output format: Section text:      address: 0x********, length: 0x********\n"
                                    "               Section rodata     address: 0x********, length: 0x********\n"
                                    "               Section data_p:    address: 0x********, length: 0x********\n"
                                    "               Section data_u:    address: 0x********, length: 0x********\n"
                                    "               section bss_p:     address: 0x********, length: 0x********\n"
                                    "               section bss_u:     address: 0x********, length: 0x********\n\n"

                                    "               heap:              address: 0x********, used: x.y%\nn"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";


#else
STRG_LOC_CONST(aStrHelp[])        = "Give the memory information\n"
                                    "===========================\n\n"

                                    "This tool displays information about the memory\n"
                                    "section (DATA/CODE) of the system.\n\n"

                                    "Input format:  memory\n"
                                    "Output format: Section text:      address: 0x********, length: 0x********\n"
                                    "               Section rodata:    address: 0x********, length: 0x********\n"
                                    "               Section data:      address: 0x********, length: 0x********\n"
                                    "               section bss:       address: 0x********, length: 0x********\n\n"

                                    "               heap:              address: 0x********, used: x.y%\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#endif

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    Memory,                                     // Module name (the first letter has to be upper case)
    KID_FAM_CLI,                                // Family (defined in the module.h)
    KNUM_MEMORY,                                // Module identifier (defined in the module.h)
    nullptr,                                    // Address of the initialisation code (early pre-init)
    prgm,                                       // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                                    // Address of the clean code (clean the module)
    " 1.0",                                     // Revision string (major . minor)
    ((1U<<BSHOW) | (1U<<BEXE_CONSOLE)),         // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                                           // Execution cores
);

// CLI tool specific
// =================

#if (KNB_CORES > 2)
#error  "*** The number of cores (KNB_CORES) exceed 2"
#endif

// Prototypes

static  void    local_displayHeap(uint8_t *stHeap, uint32_t blocks, uint32_t used, intptr_t heapSize);
static  uint32_t local_usedPercent(uint32_t used, uintptr_t size);

/*
 * \brief Main entry point
 *
 */
static  int32_t prgm([[maybe_unused]] uint32_t argc, [[maybe_unused]] const char_t *argv[]) {
    uint32_t    usdMemory, nbBlocks;
    intptr_t    length;

    #if (KNB_CORES == 1)
    #   ifdef __clang__
    size_t  size_first  = (uintptr_t)linker_topStackFirst_C0  - (uintptr_t)linker_lowStackFirst_C0  + 16;
    size_t  size_system = (uintptr_t)linker_topStackSystem_C0 - (uintptr_t)linker_lowStackSystem_C0 + 16;
    #   else
    size_t  size_first  = (size_t)linker_sizeStackFirst_C0;
    size_t  size_system = (size_t)linker_sizeStackSystem_C0;
    #   endif
    #elif (KNB_CORES == 2)
    #   ifdef __clang__
    size_t  size_first_C0  = (uintptr_t)linker_topStackFirst_C0  - (uintptr_t)linker_lowStackFirst_C0  + 16;
    size_t  size_system_C0 = (uintptr_t)linker_topStackSystem_C0 - (uintptr_t)linker_lowStackSystem_C0 + 16;
    size_t  size_first_C1  = (uintptr_t)linker_topStackFirst_C1  - (uintptr_t)linker_lowStackFirst_C1  + 16;
    size_t  size_system_C1 = (uintptr_t)linker_topStackSystem_C1 - (uintptr_t)linker_lowStackSystem_C1 + 16;
    #   else
    size_t  size_first_C0  = (size_t)linker_sizeStackFirst_C0;
    size_t  size_system_C0 = (size_t)linker_sizeStackSystem_C0;
    size_t  size_first_C1  = (size_t)linker_sizeStackFirst_C1;
    size_t  size_system_C1 = (size_t)linker_sizeStackSystem_C1;
    #   endif
    #endif

    PRIVILEGE_ELEVATE;

    (void)dprintf(KSYST, "Memory information.\n");

// This because of a gcc bug
// !!! Never use this
//     ... if ((int32_t)linker_lnHeap > 0)
//
//     but use this
//     ... int32_t var
//     ... var = (int32_t)linker_lnHeap
//     ... if (var > 0)

    length = (intptr_t)linker_lnHeap;

    kern_criticalSection(KENTER_CRITICAL);

    SPIN_LOCK(vMemo);
    usdMemory = vMemo_heapInfo.oUsdMemory;
    nbBlocks  = vMemo_heapInfo.oNbBlocks;
    SPIN_UNLOCK(vMemo);

    kern_criticalSection(KEXIT_CRITICAL);

    #ifdef PRIVILEGED_USER_S
    uint32_t    usedPrgmCode, usedPrgmData_p, usedPrgmData_u;
    uint32_t    usedPrgmCodep, usedPrgmData_pp, usedPrgmData_up;

    usedPrgmCode    = (uint32_t)((uintptr_t)linker_enTEXT   - (uintptr_t)linker_stTEXT)     \
                    + (uint32_t)((uintptr_t)linker_enRODATA - (uintptr_t)linker_stRODATA)   \
                    + (uint32_t)((uintptr_t)linker_enDATA_p - (uintptr_t)linker_stDATA_p)   \
                    + (uint32_t)((uintptr_t)linker_enDATA_u - (uintptr_t)linker_stDATA_u);

    usedPrgmData_p  = (uint32_t)((uintptr_t)linker_enDATA_p - (uintptr_t)linker_stDATA_p)   \
                    + (uint32_t)((uintptr_t)linker_enBSS_p  - (uintptr_t)linker_stBSS_p);

    usedPrgmData_u  = (uint32_t)((uintptr_t)linker_enDATA_u - (uintptr_t)linker_stDATA_u)   \
                    + (uint32_t)((uintptr_t)linker_enBSS_u  - (uintptr_t)linker_stBSS_u);

    usedPrgmCodep = local_usedPercent(usedPrgmCode, (uintptr_t)linker_lnPrgmCode);
    (void)dprintf(KSYST, "uKOS code:         addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes], used: %2"PRIu32".%02"PRIu32" [%%]\n", (uintptr_t)linker_stPrgmCode,        (uintptr_t)linker_lnPrgmCode,   usedPrgmCodep / 100U, usedPrgmCodep % 100U);

    usedPrgmData_pp = local_usedPercent(usedPrgmData_p, (uintptr_t)linker_lnPrgmData_p);
    (void)dprintf(KSYST, "uKOS data_p:       addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes], used: %2"PRIu32".%02"PRIu32" [%%]\n", (uintptr_t)linker_stPrgmData_p,      (uintptr_t)linker_lnPrgmData_p, usedPrgmData_pp / 100U, usedPrgmData_pp % 100U);

    usedPrgmData_up = local_usedPercent(usedPrgmData_u, (uintptr_t)linker_lnPrgmData_u);
    (void)dprintf(KSYST, "uKOS data_u:       addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes], used: %2"PRIu32".%02"PRIu32" [%%]\n", (uintptr_t)linker_stPrgmData_u,      (uintptr_t)linker_lnPrgmData_u, usedPrgmData_up / 100U, usedPrgmData_up % 100U);

    #else
    uint32_t    usedPrgmCode, usedPrgmData;
    uint32_t    usedPrgmCodep, usedPrgmDatap;

    usedPrgmCode  = (uint32_t)((uintptr_t)linker_enTEXT   - (uintptr_t)linker_stTEXT)       \
                  + (uint32_t)((uintptr_t)linker_enRODATA - (uintptr_t)linker_stRODATA)     \
                  + (uint32_t)((uintptr_t)linker_enDATA   - (uintptr_t)linker_stDATA);

    usedPrgmData  = (uint32_t)((uintptr_t)linker_enDATA   - (uintptr_t)linker_stDATA)       \
                  + (uint32_t)((uintptr_t)linker_enBSS    - (uintptr_t)linker_stBSS);

    usedPrgmCodep = local_usedPercent(usedPrgmCode, (uintptr_t)linker_lnPrgmCode);
    (void)dprintf(KSYST, "uKOS code:         addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes], used: %2"PRIu32".%02"PRIu32" [%%]\n", (uintptr_t)linker_stPrgmCode, (uintptr_t)linker_lnPrgmCode, usedPrgmCodep / 100U, usedPrgmCodep % 100U);

    usedPrgmDatap = local_usedPercent(usedPrgmData, (uintptr_t)linker_lnPrgmData);
    (void)dprintf(KSYST, "uKOS data:         addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes], used: %2"PRIu32".%02"PRIu32" [%%]\n", (uintptr_t)linker_stPrgmData, (uintptr_t)linker_lnPrgmData, usedPrgmDatap / 100U, usedPrgmDatap % 100U);
    #endif

    #if (KNB_CORES == 1)
    (void)dprintf(KSYST, "Stack first:       addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes]\n",   (uintptr_t)linker_lowStackFirst_C0,  size_first);
    (void)dprintf(KSYST, "Stack system:      addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes]\n\n", (uintptr_t)linker_lowStackSystem_C0, size_system);

    #elif (KNB_CORES == 2)
    (void)dprintf(KSYST, "C0 Stack first:    addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes]\n",   (uintptr_t)linker_lowStackFirst_C0,  size_first_C0);
    (void)dprintf(KSYST, "C0 Stack system:   addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes]\n",   (uintptr_t)linker_lowStackSystem_C0, size_system_C0);
    (void)dprintf(KSYST, "C1 Stack first:    addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes]\n",   (uintptr_t)linker_lowStackFirst_C1,  size_first_C1);
    (void)dprintf(KSYST, "C1 Stack system:   addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes]\n\n", (uintptr_t)linker_lowStackSystem_C1, size_system_C1);

    #else
    #error  "*** The number of cores (KNB_CORES) exceed 4"
    #endif

    #ifdef PRIVILEGED_USER_S
    (void)dprintf(KSYST, "Section text:      addr = 0x%016"PRIXPTR", used = 0x%016"PRIXPTR" [Bytes]\n",   (uintptr_t)linker_stTEXT,   ((uintptr_t)linker_enTEXT   - (uintptr_t)linker_stTEXT));
    (void)dprintf(KSYST, "Section rodata:    addr = 0x%016"PRIXPTR", used = 0x%016"PRIXPTR" [Bytes]\n",   (uintptr_t)linker_stRODATA, ((uintptr_t)linker_enRODATA - (uintptr_t)linker_stRODATA));
    (void)dprintf(KSYST, "Section data_p:    addr = 0x%016"PRIXPTR", used = 0x%016"PRIXPTR" [Bytes]\n",   (uintptr_t)linker_stDATA_p, ((uintptr_t)linker_enDATA_p - (uintptr_t)linker_stDATA_p));
    (void)dprintf(KSYST, "Section data_u:    addr = 0x%016"PRIXPTR", used = 0x%016"PRIXPTR" [Bytes]\n",   (uintptr_t)linker_stDATA_u, ((uintptr_t)linker_enDATA_u - (uintptr_t)linker_stDATA_u));
    (void)dprintf(KSYST, "Section bss_p:     addr = 0x%016"PRIXPTR", used = 0x%016"PRIXPTR" [Bytes]\n",   (uintptr_t)linker_stBSS_p,  ((uintptr_t)linker_enBSS_p  - (uintptr_t)linker_stBSS_p));
    (void)dprintf(KSYST, "Section bss_u:     addr = 0x%016"PRIXPTR", used = 0x%016"PRIXPTR" [Bytes]\n\n", (uintptr_t)linker_stBSS_u,  ((uintptr_t)linker_enBSS_u  - (uintptr_t)linker_stBSS_u));

    #else
    (void)dprintf(KSYST, "Section text:      addr = 0x%016"PRIXPTR", used = 0x%016"PRIXPTR" [Bytes]\n",   (uintptr_t)linker_stTEXT,   ((uintptr_t)linker_enTEXT   - (uintptr_t)linker_stTEXT));
    (void)dprintf(KSYST, "Section rodata:    addr = 0x%016"PRIXPTR", used = 0x%016"PRIXPTR" [Bytes]\n",   (uintptr_t)linker_stRODATA, ((uintptr_t)linker_enRODATA - (uintptr_t)linker_stRODATA));
    (void)dprintf(KSYST, "Section data:      addr = 0x%016"PRIXPTR", used = 0x%016"PRIXPTR" [Bytes]\n",   (uintptr_t)linker_stDATA,   ((uintptr_t)linker_enDATA   - (uintptr_t)linker_stDATA));
    (void)dprintf(KSYST, "Section bss:       addr = 0x%016"PRIXPTR", used = 0x%016"PRIXPTR" [Bytes]\n\n", (uintptr_t)linker_stBSS,    ((uintptr_t)linker_enBSS    - (uintptr_t)linker_stBSS));
    #endif

    local_displayHeap(linker_stHeap, nbBlocks, usdMemory, length);

    PRIVILEGE_RESTORE;
    return EXIT_OS_SUCCESS_CLI;
}

// Local routines
// ==============

/*
 * \brief local_displayHeap
 *
 * - Display the memory segment characteristics
 *
 */
/*
 * \brief local_usedPercent
 *
 * - Return the used fraction of a memory region, in hundredths of a percent
 *
 * The caller prints it as <whole>.<hundredths> instead of using %5.2f, so that
 * the memory command needs no floating-point conversion in printf. That keeps it
 * working on a target built with LLVMLIBC_PRINTF_FLOAT=OFF, where LLVM libc's
 * float converters are deliberately absent and a %f would branch to address 0
 * (see __printf_float in OS/Lib_generics/llvmlibc/llvmlibc.c). The rendering is
 * unchanged: both forms occupy five columns for a value below 100.
 *
 * The division rounds to nearest, as %.2f does.
 *
 */
static  uint32_t    local_usedPercent(uint32_t used, uintptr_t size) {

    if (size == 0U) { return (0U); }
    return ((uint32_t)((((uint64_t)used * 10000U) + ((uint64_t)size / 2U)) / (uint64_t)size));
}

static  void    local_displayHeap(uint8_t *stHeap, uint32_t blocks, uint32_t used, intptr_t heapSize) {

    (void)dprintf(KSYST, "Heap:              addr = 0x%016"PRIXPTR"\n", (uintptr_t)stHeap);

    (void)dprintf(KSYST, "                   total size                          %16"PRIdPTR" [Bytes]\n",   heapSize);
    (void)dprintf(KSYST, "                   total used memory:                  %16"PRIu32" [Bytes]\n",    used);
    (void)dprintf(KSYST, "                   total used blocks:                  %16"PRIu32" [-]\n\n",      blocks);
}
