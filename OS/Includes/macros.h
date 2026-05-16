/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Important generic macros.
 */

#pragma once

#include    <stdint.h>  // IWYU pragma: keep

#if (defined(UKOS_S))
#include    "types.h"           // IWYU pragma: keep (for char_t)
// Note: RESERVE/RELEASE macros use KWAIT_INFINITY from kern/temporal.h
// Users must include kern/temporal.h explicitly to use these macros
#endif

// System & compiler
// -----------------

#define QUOTE(name)             #name
#define STRG(macro)             QUOTE(macro)

#if (defined(__clang__))
#define uKOS_COMPILER           "clang " STRG(__clang_major__) "." STRG(__clang_minor__) "." STRG(__clang_patchlevel__)
#define uKOS_COMPILER_VERSION   ((__clang_major__ * 10000) + (__clang_minor__ * 100) + (__clang_patchlevel__))

#else
#define uKOS_COMPILER           "gcc-" STRG(__GNUC__) "." STRG(__GNUC_MINOR__) "." STRG(__GNUC_PATCHLEVEL__)
#define uKOS_COMPILER_VERSION   ((__GNUC__ * 10000) + (__GNUC_MINOR__ * 100) + (__GNUC_PATCHLEVEL__))
#endif

// Variable alignment macros for C99 & C11
// ---------------------------------------

#if (defined(__STDC_VERSION__)) && (__STDC_VERSION__ < 201112L)
#define VAR_DECLARED_ALIGN(varDeclared, boundary)                                           \
                                varDeclared [[gnu::aligned(boundary)]]

#else
#define VAR_DECLARED_ALIGN(varDeclared, boundary)                                           \
                                alignas (boundary) varDeclared
#endif

// Device reserve/release macros
// -----------------------------

#define RESERVE(device, reserveMode)                                                        \
                                device##_reserve(reserveMode, KWAIT_INFINITY)
#define RELEASE(device, reserveMode)                                                        \
                                device##_release(reserveMode)

// Some useful macros
// ------------------

#define GET_PTR_32(ptr)         (                                                           \
                                ((uint32_t)((const uint8_t *)(ptr))[0]<<24U) |              \
                                ((uint32_t)((const uint8_t *)(ptr))[1]<<16U) |              \
                                ((uint32_t)((const uint8_t *)(ptr))[2]<<8U)  |              \
                                ((uint32_t)((const uint8_t *)(ptr))[3]<<0U))

#define UNUSED(x)               (void)(x)

#define STRG_LOC_CONST(aId)     VAR_DECLARED_ALIGN(static const char_t  aId, 4)
#define STRG_LOC_STATI(aId)     VAR_DECLARED_ALIGN(static       char_t  aId, 4)
#define STRG_GLB_CONST(aId)     VAR_DECLARED_ALIGN(const        char_t  aId, 4)

#define ALIGNED_PTR(type, ptr)  ((type *)__builtin_assume_aligned((ptr), _Alignof(type)))

// Call suffix for Applications (downloadable) or Tools (romable application)
// --------------------------------------------------------------------------

// If application (downloadable):
// int  main(int argc, const char *argv[]);
//
// If tool (romable application):
// static   int32_t prgm(uint32_t argc, const char_t *argv[]);

#if defined(ROMABLE_S)
#if defined(__cplusplus)
#define CPP_INTERNAL_SCOPE_BEGIN        namespace {
#define CPP_INTERNAL_SCOPE_END          }
#define MAIN_ENTRY(argc, argv)          int32_t prgm(uint32_t argc, const char_t *argv)

#else
#define MAIN_ENTRY(argc, argv)  static  int32_t prgm(uint32_t argc, const char_t *argv)
#endif

#else
#define CPP_INTERNAL_SCOPE_BEGIN
#define CPP_INTERNAL_SCOPE_END
#define MAIN_ENTRY(argc, argv)  int main(int argc, const char *argv)
#endif
