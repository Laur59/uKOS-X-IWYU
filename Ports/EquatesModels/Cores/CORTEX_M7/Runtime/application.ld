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
    } > prgm_code

    .ARM.extab : {
        *(.ARM.extab*)
    } > prgm_code

    .ARM.exidx : {
        *(.ARM.exidx*)
    } > prgm_code

    .rodata : {
        . = ALIGN(4);
        linker_stRODATA = ABSOLUTE(.);
        *(.rodata .rodata.*)
        *(.srodata .srodata.*)
        . = ALIGN(4);
        linker_enRODATA = ABSOLUTE(.);
    } > prgm_code

    /* .init_array and .fini_array are writable (SHF_WRITE) and must stay
       contiguous with .data. Placed between read-only sections, they land in
       the writable PT_LOAD whilst keeping an address outside its range, which
       ld tolerates but strip rejects.                                        */

    .init_array : {
        . = ALIGN(4);
        linker_stInitArray = ABSOLUTE(.);
        KEEP(*(SORT_BY_INIT_PRIORITY(.init_array.*)))
        KEEP(*(.init_array))
        linker_enInitArray = ABSOLUTE(.);
    } > prgm_code

    .fini_array : {
        . = ALIGN(4);
        linker_stFiniArray = ABSOLUTE(.);
        KEEP(*(SORT_BY_INIT_PRIORITY(.fini_array.*)))
        KEEP(*(.fini_array))
        linker_enFiniArray = ABSOLUTE(.);
    } > prgm_code

    .data : {
        . = ALIGN(4);
        linker_stDATA = ABSOLUTE(.);
        *(.data .data.*)
        . = ALIGN(4);
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

/* uKOS-X applications share the system image's C library and its thread pointer:
   the thread-pointer accessor resolves from FLASH.elf through -Wl,--just-symbols,
   while a thread-local symbol defined here would have its offsets computed against
   the application's own, unallocated, TLS block - the accesses would then land in
   the middle of the system's thread-local data. The system libraries are built
   without thread-local storage, so nothing should reach these sections; fail the
   link rather than corrupt the system at run time. */

    .tdata : {
        *(.tdata .tdata.* .gnu.linkonce.td.*)
    } > prgm_code

    .tbss (NOLOAD) : {
        *(.tbss .tbss.* .gnu.linkonce.tb.*)
        *(.tcommon)
    } > prgm_data

    ASSERT(SIZEOF(.tdata) == 0, "Application defines initialised thread-local data: not supported")
    ASSERT(SIZEOF(.tbss) == 0, "Application defines thread-local bss: not supported (a C library object holding thread-local state was pulled in because the system image does not export that function)")

    /DISCARD/ : {
        *(.note .note.*)
    }

}
