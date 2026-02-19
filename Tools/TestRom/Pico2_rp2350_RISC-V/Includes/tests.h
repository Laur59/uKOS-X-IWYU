/*
; tests.
; ======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:   Laurent von Allmen      The 2026-02-16
; Modifs:
;
; Project:  uKOS-X
; Goal:     Test ROM routine collection.
;------------------------------------------------------------------------
*/

#pragma once

#include    "types.h"
#include    "cmns.h"
#include    "debug.h"
#include    "core_reg.h"
#include    "soc_reg.h"
#include    "board.h"
#include    "clockTree.h"
#include    "macros.h"
#include    "macros_soc.h"
#include    "macros_core.h"
#include    "core.h"
#include    "spin.h"

#define NO_KERNEL_S         // No kernels (naked function entries)
