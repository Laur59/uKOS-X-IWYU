/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 */

#pragma once

/*!
 * \defgroup Lib_generics Library for generic manager
 *
 * \brief Generic manager system calls
 *
 * The Lib_generics library offers a set of managers that illustrate how a
 * system may combine order and efficiency. Each manager contributes a unique
 * service, yet all together they form a coherent foundation.
 *
 * The asmp manager demonstrates multi-processor control. It divides work
 * among processors, ensuring that heavy tasks may be shared and completed with
 * speed and balance.
 *
 * The calendar manager focuses on time. It parses dates, handles calendars,
 * and measures intervals, allowing events to be scheduled and coordinated.
 *
 * The machine manager provides access to low-level resources. It observes
 * the hardware closely and offers precise control where performance matters.
 *
 * The memo manager governs memory. By allocating and freeing space, it
 * preserves safety, prevents leaks, and ensures resources are well used.
 *
 * The newlib manager supports the familiar functions of the C library. It
 * guarantees that formatted output and essential utilities remain reliable.
 *
 * The system manager explores the environment. It searches modules, adapts
 * to settings, and lets the programme integrate with its wider context.
 *
 * The text manager treats ASCII lines with care. It splits commands into
 * arguments, so that human input may be transformed into clear instruction.
 *
 * Together these managers show that discipline and design can live side by side.
 * Lib_generics is both a toolbox for developers and a lesson in clarity.
 *
 * @{
 */

// IWYU pragma: begin_exports

#ifdef CONFIG_MAN_ASMP_S
#include    "asmp/asmp.h"
#endif
#ifdef CONFIG_MAN_CALENDAR_S
#include    "calendar/calendar.h"
#endif
#ifdef CONFIG_MAN_MACHINE_S
#include    "machine/machine.h"
#endif
#ifdef CONFIG_MAN_MEMO_S
#include    "memo/memo.h"
#endif
#ifdef CONFIG_MAN_SYSTEM_S
#include    "system/system.h"
#endif
#ifdef CONFIG_MAN_TEXT_S
#include    "text/text.h"
#endif

// dprintf and record_trace
// These functions are always defined.

#include    "record/record.h"

// C library integration
#ifdef CONFIG_MAN_NEWLIB_S
#include    "newlib/newlib.h"
#elif defined(CONFIG_MAN_PICOLIBC_S)
#include    "picolibc/picolibc.h"
#else
#error "No C library configured (CONFIG_MAN_NEWLIB_S or CONFIG_MAN_PICOLIBC_S required)"
#endif

// IWYU pragma: end_exports

/**!@}*/
