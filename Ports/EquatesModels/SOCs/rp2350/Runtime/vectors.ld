/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Common Linker description for uKOS-X systems.
 *
 *                       CODE
 * linker_stVECTORS      +-----------------+
 *                       |                 |
 *                       | .isr_vector     |
 *                       |                 |
 * linker_enVECTORS      +-----------------+
 */

    . = ALIGN(512);
        linker_stVECTORS = ABSOLUTE(.);
        KEEP(*(.isr_vector))
        linker_enVECTORS = ABSOLUTE(.);

    . = ALIGN(8);
        KEEP(*(.picobin_block))
