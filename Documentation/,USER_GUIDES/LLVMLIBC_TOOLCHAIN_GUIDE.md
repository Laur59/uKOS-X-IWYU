<!-- SPDX-License-Identifier: MIT -->
<!-- SPDX-FileCopyrightText: 2026 Laurent von Allmen -->

# LLVM libc Toolchain Guide

uKOS-X can be built against three C libraries, selected with the CMake variable
`C_LIBRARY`: **newlib** (default), **picolibc**, and **llvmlibc** (the LLVM
project's own C library, as shipped by the *Arm Toolchain for Embedded*, ATfE).

LLVM libc is significant for the future: per the ATfE changelog it **becomes the
default C library in ATfE 24**, with picolibc demoted to an overlay in ATfE 25.
Adding `C_LIBRARY=llvmlibc` now keeps uKOS-X building cleanly as that shift lands.

> **Scope:** LLVM libc support is **ARM/AArch64 and Clang only.** ATfE does not
> target RISC-V, and there is no GCC path. Selecting `llvmlibc` with a RISC-V
> target or with GCC is a configuration error (CMake stops with a clear message).

## 1. Toolchain

Install an ATfE build that provides LLVM libc and point a dedicated environment
variable at it:

```bash
export PATH_LLVM_ARML=/path/to/ATfE_llvmlibc-XX.Y.Z-<host>
$PATH_LLVM_ARML/bin/clang --version    # should mention "llvmlibc"
```

`PATH_LLVM_ARML` is used **only** for `C_LIBRARY=llvmlibc`, mirroring the existing
per-library convention (`PATH_LLVM_ARM` = newlib, `PATH_LLVM_ARMP` = picolibc).

Minimum version: **ATfE 22.1.0** (first release with LLVM libc in the main package).

## 2. Building a target

```bash
cd Ports/Targets/Nucleo_H743/Variant_Test
cmake --preset llvm -DC_LIBRARY=llvmlibc -B build
cmake --build build
```

`C_LIBRARY=llvmlibc` requires `USE_LLVM=ON` (the `llvm*` presets set this).

### Batch builds

The build scripts accept a `-M` flag for llvmlibc:

```bash
cd Ports/Targets && ./_build.sh -M                 # all ARM systems, llvmlibc
cd Applications/uKOS_Appls_Downloadable && ./_build.sh -M
```

`Tools/Developer/latotale.sh` also runs an llvmlibc pass automatically when
`PATH_LLVM_ARML` is set (use `-M` there to *exclude* it). The two RISC-V targets
are reported as FAIL under llvmlibc by design.

## 3. How selection works

- **No `--config` needed for a dedicated LLVM-libc ATfE build** — pointing the
  toolchain at such an install selects LLVM libc directly. Only an *overlay*
  install needs `--config=llvmlibc.cfg`; set `-DLLVMLIBC_CONFIG=llvmlibc.cfg` in
  that case.
- `select-arm-toolchain.cmake` resolves the compiler from `PATH_LLVM_ARML`.
- `system.cmake` / `application.cmake` define `CONFIG_MAN_LLVMLIBC_S`, wrap the
  allocator (`--wrap=malloc/free/realloc/calloc` onto `memo_malloc`), and
  force-include the declaration shim (see below).
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
| `time()` | From the kernel Unix-time counter (LLVM libc has no clock source) |
| `setenv` / `tzset` | Stubs — no environment on baremetal |
| `_exit`, `__assert_func` | For prebuilt newlib-compiled third-party archives (e.g. Pico SDK TinyUSB) |
| Termination | `__llvm_libc_exit` → `crt0_exit` |

`errno` is owned by LLVM libc itself (`__llvm_libc_errno`), so — unlike picolibc —
uKOS-X does **not** keep a per-process errno for this library. `gmtime_r`,
`localtime_r`, `mktime`, `asctime`, `strftime`, etc. are provided by the library.

## 5. Known limitations

- **Timezone:** `setenv("TZ",...)`/`tzset()` are stubs, so local time runs in **UTC**.
- **No `FILE*`:** file-based stdio (`fopen`/`fprintf`) is not available on baremetal
  LLVM libc; uKOS-X uses `dprintf` to file descriptors, which the shim covers.
- **errno is not per-process** with LLVM libc (it is with picolibc/newlib).
- **ARM only.** RISC-V and GCC are unsupported for this C library.

## 6. Quick reference

| Build | Environment | CMake |
|-------|-------------|-------|
| Clang + newlib | `PATH_LLVM_ARM` | `--preset llvm` |
| Clang + picolibc | `PATH_LLVM_ARMP` | `--preset llvm -DC_LIBRARY=picolibc` |
| Clang + llvmlibc | `PATH_LLVM_ARML` | `--preset llvm -DC_LIBRARY=llvmlibc` |

### Verify llvmlibc in a build

```bash
grep C_LIBRARY build/CMakeCache.txt                 # -> llvmlibc
grep -o CONFIG_MAN_LLVMLIBC_S Artefacts/FLASH.cnf    # present
```
