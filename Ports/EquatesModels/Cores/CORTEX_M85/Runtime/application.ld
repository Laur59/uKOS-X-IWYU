/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Commun Linker description for uKOS-X applications.
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

_lnApplication  = (linker_enDATA - linker_stTEXT);  /* Length of the application    */

SECTIONS {
    .text : {
        linker_stTEXT = ABSOLUTE(.);
        KEEP(*(.header))
        *(.text .text.*)
        linker_enTEXT = ABSOLUTE(.);

        _stCTOR = ABSOLUTE(.);
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array))
        linker_enCTOR = ABSOLUTE(.);

        _stDTOR = ABSOLUTE(.);
        KEEP(*(SORT(.fini_array.*)))
        KEEP(*(.fini_array))
        linker_enDTOR = ABSOLUTE(.);
    } > prgm_code

    .init_array : {
        . = ALIGN(4);
        linker_stInitArray = ABSOLUTE(.);
        KEEP(*(.init .init.* .init*))
        linker_enInitArray = ABSOLUTE(.);
    } > prgm_code

    .fini_array : {
        . = ALIGN(4);
        linker_stFiniArray = ABSOLUTE(.);
        KEEP(*(.fini .fini.* .fini*))
        linker_enFiniArray = ABSOLUTE(.);
    } > prgm_code

    .ARM.exidx : {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > prgm_code

    .rodata : {
        . = ALIGN(4);
        linker_stRODATA = ABSOLUTE(.);
        *(.rodata .rodata.*)
        *(.srodata .srodata.*)
        . = ALIGN(4);
        linker_enRODATA = ABSOLUTE(.);
    } > prgm_code

    .data : {
        . = ALIGN(4);
        linker_stDATA = ABSOLUTE(.);
        *(.data .data.*)
        . = ALIGN(4);
        *(vtable)
        . = ALIGN(4);
        KEEP(*(.eh_frame))
        . = ALIGN(4);
        *(.ARM.extab*)
        . = ALIGN(4);
        *(.ARM.exidx*)
        linker_enDATA = ABSOLUTE(.);
    } > prgm_code

    .bss (NOLOAD) : {
        . = ALIGN(4);
        linker_stBSS = ABSOLUTE(.);
        KEEP(*(.user))
        *(.bss .bss.*)
        . = ALIGN(4);
        *(COMMON)
        . = ALIGN(4);
        linker_enBSS = ABSOLUTE(.);
    } > prgm_data

    /DISCARD/ : {
        *(.note .note.*)
        *(.eh_frame .eh_frame.*)
        *(.ARM.extab* .gnu.linkonce.armextab.*)
        *(.ARM.exidx*)
    }

}
