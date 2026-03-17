/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; lib_serials.
; ============

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     lib_serials system call interface module.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

/*!
 * \defgroup Lib_serials Library for Serial Communication Manager
 *
 * \brief Serial manager system calls
 *
 * The Lib_serials library offers managers for communication across many
 * channels. It unifies serial links and ensures that data flows with order.
 *
 * The serial manager provides a common foundation. It abstracts details,
 * so that higher layers may send and receive bytes without confusion.
 *
 * The urtx manager controls UART lines. It enables traditional serial I/O,
 * still essential in embedded design, debugging, and configuration.
 *
 * The cdcx manager extends serial links through USB CDC. By appearing as a
 * virtual port, it joins the flexibility of USB with the clarity of UART.
 *
 * The wfi0 manager opens the path to wireless. Using the ESP32 module, it
 * delivers Wi-Fi connectivity, bringing networks into embedded systems.
 *
 * Together these managers make Lib_serials a bridge between machines and
 * their environment. From a simple cable to a wireless link, all is aligned.
 *
 * @{
 */

// IWYU pragma: begin_exports

#ifdef CONFIG_MAN_SERIAL_S
#include    "serial/serial.h"
#else
#define KDEF0   0
#endif
#ifdef CONFIG_MAN_URT0_S
#include    "urt0/urt0.h"
#endif
#ifdef CONFIG_MAN_URT1_S
#include    "urt1/urt1.h"
#endif
#ifdef CONFIG_MAN_URT2_S
#include    "urt2/urt2.h"
#endif
#ifdef CONFIG_MAN_URT3_S
#include    "urt3/urt3.h"
#endif
#ifdef CONFIG_MAN_URT4_S
#include    "urt4/urt4.h"
#endif
#ifdef CONFIG_MAN_CDC0_S
#include    "cdc0/cdc0.h"
#endif
#ifdef CONFIG_MAN_CDC1_S
#include    "cdc1/cdc1.h"
#endif
#ifdef CONFIG_MAN_WFI0_S
#include    "wfi0/wfi0.h"
#endif

// IWYU pragma: end_exports

/**!@}*/
