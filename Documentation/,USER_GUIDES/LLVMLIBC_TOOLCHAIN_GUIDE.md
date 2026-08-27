<!-- SPDX-License-Identifier: MIT -->
<!-- SPDX-FileCopyrightText: 2026 Laurent von Allmen -->

# LLVM libc Toolchain Guide

uKOS-X can be built against three C libraries, selected with the CMake variable
`C_LIBRARY`: **newlib** (default), **picolibc**, and **llvmlibc** (the LLVM
project's own C library, shipped for ARM by the *Arm Toolchain for Embedded*,
ATfE, and for RISC-V by the LLVM embedded toolchain).

LLVM libc is significant for the future: per the ATfE changelog it **becomes the
default C library in ATfE 24**, with picolibc demoted to an overlay in ATfE 25.
Adding `C_LIBRARY=llvmlibc` now keeps uKOS-X building cleanly as that shift lands.

> **Scope:** LLVM libc support is **Clang only** — there is no GCC path, and
> selecting `llvmlibc` with GCC is a configuration error (CMake stops with a clear
> message). Both architectures are supported, each from its own dedicated
> toolchain: ARM from ATfE (`PATH_LLVM_ARML`) and RISC-V from an LLVM embedded
> toolchain built with LLVM libc (`PATH_LLVM_RVXXL`).

## 1. Toolchain

Install a toolchain that provides LLVM libc and point a dedicated environment
variable at it — one per architecture:

```bash
export PATH_LLVM_ARML=/path/to/ATfE_llvmlibc-XX.Y.Z-<host>       # ARM
export PATH_LLVM_RVXXL=/path/to/<riscv-llvm-toolchain-with-llvmlibc>  # RISC-V

$PATH_LLVM_ARML/bin/clang --version    # ATfE tags the banner with "llvmlibc"
```

The RISC-V banner carries no such tag; check the runtime headers instead:

```bash
ls $PATH_LLVM_RVXXL/lib/clang-runtimes/*/include/__llvm-libc-common.h
```

These variables are used **only** for `C_LIBRARY=llvmlibc`, mirroring the existing
per-library convention (`PATH_LLVM_ARM` / `PATH_LLVM_RVXX` = newlib,
`PATH_LLVM_ARMP` / `PATH_LLVM_RVXXP` = picolibc).

Minimum ARM version: **ATfE 22.1.0** (first release with LLVM libc in the main package).

### Toolchain patch (required)

Stock baremetal LLVM libc defaults `CLOCKS_PER_SEC` to **100** on Arm, matching
the centiseconds an Arm semihosting `SYS_CLOCK` time source returns. uKOS-X drives
`clock()` from its own 1-us kernel counter, so it builds the ARM toolchain with

```
ukos_patches/0006-llvm-libc-use-microsecond-also-for-32-bit-Arm-cores.patch
```

which moves 32-bit Arm to the microsecond branch of
`libc/include/llvm-libc-macros/baremetal/time-macros.h`. It mirrors the newlib
patch `0002-Patch-time.h-for-uKOS.patch` and is applied the same way, with the
rest of the uKOS-X patchset.

The patch is preferred over passing `-D__CLK_TCK=1000000` from the uKOS-X build
because `libc/src/time/baremetal/clock.cpp` is compiled against that header, so
patching keeps `libc.a` and the application on the same unit; a `-D` at
application build time would only change the application's side.

RISC-V already takes the microsecond branch and needs no patch. Building with an
unpatched toolchain stops on a `static_assert` in `llvmlibc.c`; the interim
workaround it names is `-DCFLAGS_APPEND=-D__CLK_TCK=1000000`.

## 2. Building a target

```bash
cd Ports/Targets/Nucleo_H743/Variant_Test
cmake --preset llvm -DC_LIBRARY=llvmlibc -B build
cmake --build build
```

`C_LIBRARY=llvmlibc` requires `USE_LLVM=ON` (the `llvm*` presets set this).

### Batch builds

The build scripts accept a `-L` flag for llvmlibc:

```bash
cd Ports/Targets && ./_build.sh -L                 # all systems, llvmlibc
cd Applications/uKOS_Appls_Downloadable && ./_build.sh -L
```

`Tools/Developer/latotale.sh` also runs an llvmlibc pass automatically when
`PATH_LLVM_ARML` is set — note that `-M` is its own flag to *exclude* that pass,
not the llvmlibc selector. The pass covers the RISC-V targets too, so
`PATH_LLVM_RVXXL` must be set as well or they stop on a missing-variable
configuration error.

## 3. How selection works

- **No `--config` needed for a dedicated LLVM-libc ATfE build** — pointing the
  toolchain at such an install selects LLVM libc directly. Only an *overlay*
  install needs `--config=llvmlibc.cfg`; set `-DLLVMLIBC_CONFIG=llvmlibc.cfg` in
  that case.
- `select-arm-toolchain.cmake` resolves the compiler from `PATH_LLVM_ARML`,
  `select-riscv-toolchain.cmake` from `PATH_LLVM_RVXXL`.
- `system.cmake` / `application.cmake` define `CONFIG_MAN_LLVMLIBC_S`, wrap the
  allocator (`--wrap=malloc/free/realloc/calloc` onto `memo_malloc`),
  force-include the declaration shim (see below) and add
  `OS/Lib_generics/llvmlibc/compat` to the include path so `<sys/time.h>`
  resolves.
- The C library source is `OS/Lib_generics/llvmlibc/llvmlibc.c`, selected by the
  `add_clib_manager_source()` helper in `Ports/cmake/proj_config.cmake`.

## 4. What uKOS-X provides for LLVM libc

Baremetal LLVM libc is intentionally minimal, so `llvmlibc.c` supplies the glue
that newlib/picolibc get from the library:

| Concern | Provided by uKOS-X |
|---------|--------------------|
| Standard I/O | `__llvm_libc_stdio_read/write` hooks + cookies → serial managers |
| `dprintf` / `vdprintf` | Own shim (LLVM libc has no `FILE*`); declared via force-included `llvmlibc_shim.h` |
| `malloc` family | `__wrap_malloc/free/realloc/calloc` → `memo_malloc` |
| `time()`, `gettimeofday()`, `clock()` | From the kernel 64-bit Unix-time counter (LLVM libc has no clock source). `clock()` is defined by uKOS-X rather than by supplying the `__llvm_libc_timespec_get_*` hooks, which keeps `clock.cpp.obj` out of the link |
| `<sys/time.h>` | Compatibility header in `OS/Lib_generics/llvmlibc/compat/sys/`, on the include path for this library only |
| `CLOCKS_PER_SEC` | Comes from the toolchain, not from the uKOS-X build — see *Toolchain patch* below |
| `setenv` / `tzset` | Stubs — accepted and ignored. Not the reason local time is UTC; see *Timezone* under *Known limitations* |
| `_exit`, `__assert_func` | For prebuilt newlib-compiled third-party archives (e.g. Pico SDK TinyUSB) |
| Termination | `__llvm_libc_exit` → `crt0_exit` |

`errno` storage belongs to LLVM libc: one file-local `int` (`shared_errno`) reached
both by `__llvm_libc_errno()` and by the library's internal `Errno::operator=` /
`operator int()`. All three live in the same `libc.a` member, so uKOS-X cannot override
the entry point — a definition of `__llvm_libc_errno` is a duplicate symbol, and the
library would keep using the operators anyway. Because uKOS-X code and library code do
reach the same `int`, the kernel instead makes it per-process by parking and reloading
it at each context switch in `xLibrary_update()`, exactly as for picolibc; the parked
value lives in `proc_t.oErrno`. See
[TLS_SUPPORT_ASSESSMENT.md](TLS_SUPPORT_ASSESSMENT.md) §4.2.

`gmtime_r`, `localtime_r`, `mktime`, `asctime`, `strftime`, etc. are provided by the
library.

## 5. Known limitations

- **Timezone:** local time runs in **UTC**. The cause is not the `setenv`/`tzset`
  stubs — LLVM libc has no timezone support at all, so nothing would read a stored
  TZ string. `localtime_r()` and `localtime()` return UTC
  (`libc/src/time/time_utils.h:176`, *"TODO: timezone support"*), `get_timezone_offset()`
  is a constant stub (`time_utils.h:351`), and `mktime()` treats the `struct tm` as UTC
  and forces `tm_isdst = 0` (`libc/src/time/time_utils.cpp:238`). The calendar manager
  still calls `setenv("TZ", ...)` + `tzset()` (`OS/Lib_generics/calendar/calendar.c:120,246`)
  because newlib and picolibc honour them; under LLVM libc the call is simply inert.

  Making uKOS-X honour TZ here would mean implementing the timezone logic itself: a
  POSIX TZ parser (`CET-1CEST,M3.5.0/2,M10.5.0/2` → std/dst names, offsets and the
  `Mm.w.d/h` transition rules), a DST-in-effect test, and overrides for `localtime_r`,
  `localtime` **and** `mktime` — the last one because `date <d> <m> <y> <h> <m> <s>`
  converts local time back to an epoch, and would otherwise set the clock off by the
  offset. The three are strong symbols in separate `libc.a` members, so uKOS-X
  definitions would win the link the way the `dprintf` shim already does. Two gaps
  would remain even then: `ctime()`/`ctime_r()` call the internal helper directly
  (`libc/src/time/ctime.cpp:23`) and would stay UTC, and LLVM libc's `struct tm` has
  no `tm_gmtoff`/`tm_zone` to populate. Deferred until upstream implements its TODO.
- **No `FILE*`:** file-based stdio (`fopen`/`fprintf`) is not available on baremetal
  LLVM libc; uKOS-X uses `dprintf` to file descriptors, which the shim covers.
- **No POSIX `sys/` headers** apart from `<sys/queue.h>`. Only `<sys/time.h>` has a
  compatibility header so far; another one needs a new file under `compat/sys/`.
- **errno inside an application is that application's own.** In the system image
  `__llvm_libc_errno` and its `shared_errno` storage are *local* symbols, so
  `-Wl,--just-symbols` cannot hand them to a downloadable application; the application
  links its own copy from `-lc` and binds to that. System processes get a per-process
  `errno` (see *What uKOS-X provides* above); an application gets one `errno` for
  itself. Same hidden-visibility boundary that makes `llvmlibc_app_stdio.c` necessary.
  picolibc does not have this split — its `errno` is a global the system image exports.
- **Clang only.** GCC has no LLVM libc path; asking for it is a configuration
  error. ARM and RISC-V are both supported, each from its own toolchain.

## 6. Quick reference

| Build | Environment | CMake |
|-------|-------------|-------|
| Clang + newlib | `PATH_LLVM_ARM` | `--preset llvm` |
| Clang + picolibc | `PATH_LLVM_ARMP` | `--preset llvm -DC_LIBRARY=picolibc` |
| Clang + llvmlibc (ARM) | `PATH_LLVM_ARML` | `--preset llvm -DC_LIBRARY=llvmlibc` |
| Clang + llvmlibc (RISC-V) | `PATH_LLVM_RVXXL` | `--preset llvm -DC_LIBRARY=llvmlibc` |

### Verify llvmlibc in a build

```bash
grep C_LIBRARY build/CMakeCache.txt                 # -> llvmlibc
grep -o CONFIG_MAN_LLVMLIBC_S Artefacts/FLASH.cnf    # present
```
