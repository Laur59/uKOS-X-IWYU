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

        KEEP(*(.restart))
        linker_stVECTORS = ABSOLUTE(.);
        KEEP(*(.vectors))
        linker_enVECTORS = ABSOLUTE(.);
