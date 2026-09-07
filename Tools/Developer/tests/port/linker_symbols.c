/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Definitions for the stubbed linker symbols, and the include-order canary.
 */

#include    <stddef.h>
#include    <stdint.h>
#include    <string.h>

#include    "linker.h"
#include    "ukos_fakes_kern.h"
#include    "ukos_test.h"

// port/ must precede Ports/EquatesModels/Generic/Runtime on the include path.
// If the real header is ever resolved first the symbols become arrays, every
// setter below stops compiling, and this says why.

#if !defined(UKOS_PORT_STUB_LINKER_H)
#error "the real Generic/Runtime/linker.h was resolved; port/ must come first"
#endif

uint8_t     *linker_stTEXT_KERN_p;
uint8_t     *linker_enTEXT_KERN_p;
uint8_t     *linker_stRODATA_KERN_p;
uint8_t     *linker_enRODATA_KERN_p;
uint8_t     *linker_stDATA_KERN_p;
uint8_t     *linker_enDATA_KERN_p;
uint8_t     *linker_stBSS_KERN_p;
uint8_t     *linker_enBSS_KERN_p;
uint8_t     *linker_stUMemo;
uint8_t     *linker_lnUMemo;

void ukos_fake_setKernelImage(uintptr_t text,   uint32_t lnText,
                              uintptr_t rodata, uint32_t lnRodata,
                              uintptr_t data,   uint32_t lnData,
                              uintptr_t bss,    uint32_t lnBss) {

    linker_stTEXT_KERN_p   = (uint8_t *)text;
    linker_enTEXT_KERN_p   = (uint8_t *)(text   + lnText);
    linker_stRODATA_KERN_p = (uint8_t *)rodata;
    linker_enRODATA_KERN_p = (uint8_t *)(rodata + lnRodata);
    linker_stDATA_KERN_p   = (uint8_t *)data;
    linker_enDATA_KERN_p   = (uint8_t *)(data   + lnData);
    linker_stBSS_KERN_p    = (uint8_t *)bss;
    linker_enBSS_KERN_p    = (uint8_t *)(bss    + lnBss);
}

// Unlike the kernel sections, the user memory IS written through - the loaders
// decode into it - so point it at a real buffer the test owns and let ASan guard
// every store. The length is carried in the symbol's own address, exactly as the
// linker script arranges it.

void ukos_fake_setUserMemory(void *base, size_t length) {

    linker_stUMemo = (uint8_t *)base;
    linker_lnUMemo = (uint8_t *)length;
}

// The sections are never dereferenced - only differenced and printed - so a
// test may hand over any address it likes, including one that would fault.

static void local_reset(void) {

    linker_stTEXT_KERN_p   = NULL;  linker_enTEXT_KERN_p   = NULL;
    linker_stRODATA_KERN_p = NULL;  linker_enRODATA_KERN_p = NULL;
    linker_stDATA_KERN_p   = NULL;  linker_enDATA_KERN_p   = NULL;
    linker_stBSS_KERN_p    = NULL;  linker_enBSS_KERN_p    = NULL;
    linker_stUMemo         = NULL;  linker_lnUMemo         = NULL;
}

__attribute__((constructor)) static void local_register(void) {

    ukos_t_addResetHook(local_reset);
}
