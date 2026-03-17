/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; soc_addendum_application.
; =========================

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     addendum equates.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

// gpio additional definitions
// ---------------------------

#define KPIN_APPCPU                         GPIO_PIN_CNF_MCUSEL_APPMCU
#define KPIN_NETCPU                         GPIO_PIN_CNF_MCUSEL_NETWORKMCU
#define KPIN_PERIPH                         GPIO_PIN_CNF_MCUSEL_PERIPHERAL
#define KPIN_TND                            GPIO_PIN_CNF_MCUSEL_TND

#define KSENS_DISABLE                       GPIO_PIN_CNF_SENSE_DISABLED
#define KSENS_HIGH                          GPIO_PIN_CNF_SENSE_HIGH
#define KSENS_LOW                           GPIO_PIN_CNF_SENSE_LOW

#define KDRIVE_S0S1                         GPIO_PIN_CNF_DRIVE_S0S1
#define KDRIVE_H0S1                         GPIO_PIN_CNF_DRIVE_H0S1
#define KDRIVE_S0H1                         GPIO_PIN_CNF_DRIVE_S0H1
#define KDRIVE_H0H1                         GPIO_PIN_CNF_DRIVE_H0H1
#define KDRIVE_D0S1                         GPIO_PIN_CNF_DRIVE_D0S1
#define KDRIVE_D0H1                         GPIO_PIN_CNF_DRIVE_D0H1
#define KDRIVE_S0D1                         GPIO_PIN_CNF_DRIVE_S0D1
#define KDRIVE_H0D1                         GPIO_PIN_CNF_DRIVE_H0D1
#define KDRIVE_E0E1                         GPIO_PIN_CNF_DRIVE_E0E1

#define KPULL_DISABLE                       GPIO_PIN_CNF_PULL_DISABLED
#define KPULL_DOWN                          GPIO_PIN_CNF_PULL_PULLDOWN
#define KPULL_UP                            GPIO_PIN_CNF_PULL_PULLUP

#define KINPUT_CONNECT                      GPIO_PIN_CNF_INPUT_CONNECT
#define KINPUT_DISCONNECT                   GPIO_PIN_CNF_INPUT_DISCONNECT

#define KDIR_INPUT                          GPIO_PIN_CNF_DIR_INPUT
#define KDIR_OUTPUT                         GPIO_PIN_CNF_DIR_OUTPUT
