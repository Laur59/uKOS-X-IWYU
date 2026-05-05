/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Basic predefined types (normally machine independent).
 */

#pragma once

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
