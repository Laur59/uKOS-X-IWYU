/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Host stub for Ports/EquatesModels/Generic/Runtime/linker.h.
 *
 * SHADOWS the real header, which is generic and declaration-only. It is stubbed
 * anyway because the declarations are portable but the SEMANTICS are not: the
 * real symbols are placed by the linker script, and two of their properties
 * cannot be reproduced by defining host arrays.
 *
 *   - szkern computes (en - st) for four section pairs. Two independently
 *     defined host arrays have no guaranteed relative placement; the difference
 *     is whatever the Mach-O linker happens to produce, and can be negative.
 *   - hexloader and sloader read linker_lnUMemo's ADDRESS as a length. No C
 *     definition can give a symbol a chosen address.
 *
 * Declaring POINTERS instead, with setters, reproduces both exactly. Every use
 * in the affected modules is an immediate cast - (uintptr_t), (uint8_t *),
 * (size_t) - so the module source and its observable behaviour are unchanged.
 * Only the declaration form differs.
 *
 * Set them with ukos_fake_setKernelImage() / ukos_fake_setUserMemory(); both are
 * cleared between tests.
 */

#ifndef UKOS_PORT_STUB_LINKER_H
#define UKOS_PORT_STUB_LINKER_H     1

#include    <stdint.h>

extern  uint8_t     *linker_stTEXT_KERN_p;
extern  uint8_t     *linker_enTEXT_KERN_p;
extern  uint8_t     *linker_stRODATA_KERN_p;
extern  uint8_t     *linker_enRODATA_KERN_p;
extern  uint8_t     *linker_stDATA_KERN_p;
extern  uint8_t     *linker_enDATA_KERN_p;
extern  uint8_t     *linker_stBSS_KERN_p;
extern  uint8_t     *linker_enBSS_KERN_p;

// The downloadable-application window. linker_lnUMemo is the clearest case for
// the pointer form: the loaders read its ADDRESS as a length, so a host array
// could never carry the right value.

extern  uint8_t     *linker_stUMemo;
extern  uint8_t     *linker_lnUMemo;

#endif
