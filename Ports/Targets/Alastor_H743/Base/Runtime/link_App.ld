/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Linker description for uKOS-X applications.
 *           User only support
 *
 *                   CODE
 * linker_stTEXT     +-----------------+
 *                   |                 |
 *                   | .header         |
 *                   | .text           |
 *                   | .ctor           |
 *                   | .dtor           |
 * linker_enCTOR     |                 |
 * linker_enDTOR     |                 |
 * linker_enTEXT     |                 |
 * linker_stRODATA   +-----------------+
 *                   |                 |
 *                   | .rodata         |
 * linker_enRODATA   |                 |
 * linker_stDATA     +-----------------+
 *                   |                 |
 *                   | .data           |
 * linker_enDATA     |                 |
 * linker_stBSS      +-----------------+
 *                   |                 |
 *                   | .bss            |
 * linker_enBSS      | COMMON          |
 *                   |                 |
 * _end              +-----------------+
 */

ENTRY(aStart)

MEMORY {
    prgm_code (rx)  : ORIGIN = 0x70200000, LENGTH = 4096K
    prgm_data (rwx) : ORIGIN = 0x70600000, LENGTH = 2048K
}

INCLUDE     application.ld
