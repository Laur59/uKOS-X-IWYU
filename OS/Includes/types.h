/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Basic predefined types (normally machine independent).
 */

#pragma once

#include    <stdint.h>

#include    "exit_codes.h"      // IWYU pragma: export

// uKOS-X misc

#ifndef tm_t
typedef struct  tm          tm_t;
#endif

#ifndef timeval_t
typedef struct timeval      timeval_t;
#endif

#ifndef reserveMode_t
typedef enum {
            KMODE_READ = 0U,
            KMODE_WRITE,
            KMODE_READ_WRITE,
} reserveMode_t;

#define KMODE_ALL   KMODE_READ_WRITE
#endif

// Serial Communication Manager identifier
//
// Declared here, defined in serial/serial.h (C23 opaque enumeration: the
// fixed underlying type makes the type complete without the enumerators).
// Code that only names a manager - the kernel storing spec_t.oSerialManager,
// a prototype taking one - needs nothing from Lib_serials; only code that
// spells KURT0, KCDC0, ... includes serial/serial.h. Both declarations must
// keep the same underlying type.

#ifndef serialManager_t
enum    serialManager_e : uint32_t;

typedef enum serialManager_e    serialManager_t;
#endif

// Types defined by gcc (version > than 4.8)

#ifndef char_t
typedef char                char_t;
#endif

#ifndef float32_t
typedef float               float32_t;
#endif

#ifndef float64_t
typedef double              float64_t;
#endif
