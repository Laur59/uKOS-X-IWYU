/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
;------------------------------------------------------------------------
; uKOSversion.
; ============
;
; Project: uKOS-X
;
; Purpose:
;   Universal h file for uKOS-X systems.
;------------------------------------------------------------------------
*/

#pragma once

// uKOS-X main constants
// -----------------------

#define uKOS_VERSION_OS         10
#define uKOS_VERSION_NUMBER     "2.21.0"
#define uKOS_VERSION_MAJOR      2
#define uKOS_VERSION_MINOR      21
#define uKOS_VERSION_REVISION   0
#define uKOS_VERSION            uKOS_VERSION_NUMBER " " STRG(uKOS_NAME) "\n" STRG(uKOS_OWNER)
