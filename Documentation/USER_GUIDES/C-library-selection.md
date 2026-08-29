# C Library Selection

uKOS-X builds against one of three C libraries, chosen with the CMake variable
`C_LIBRARY`. Each library is selected together with the toolchain that provides it:
the choice is not a compile flag on a single install, but a switch between distinct
toolchain trees pointed at by dedicated environment variables.

| `C_LIBRARY` | Library | GCC | Clang | ARM | RISC-V |
|-------------|---------|-----|-------|-----|--------|
| `newlib` (default) | newlib | yes | yes | yes | yes |
| `picolibc` | picolibc | yes | yes | yes | yes |
| `llvmlibc` | LLVM libc | no  | yes | yes | yes |

All five combinations are exercised by the regression script; the most recently added,
GCC + picolibc on RISC-V, is green on the K210 target (`regression -GP -t MAiXDUiNO_K210`,
32/32 builds, 2026-08-29).

Why three: newlib is the historical default and the only library every toolchain ships;
picolibc is markedly smaller and is the natural target for memory-constrained variants;
LLVM libc is where the Arm Toolchain for Embedded (ATfE) is heading — per the ATfE
changelog it **becomes the default C library in ATfE 24**, with picolibc demoted to an
overlay in ATfE 25. Keeping the three paths alive means that shift lands without a scramble.

---

## 1. Environment variables

The default toolchains cover newlib and are required in all cases:

```bash
export PATH_GCC_ARM=Your_Path_To_The_gcc_arm
export PATH_GCC_RVXX=Your_Path_To_The_gcc_riscv
export PATH_LLVM_ARM=Your_Path_To_The_llvm_arm
export PATH_LLVM_RVXX=Your_Path_To_The_llvm_riscv
```

Each non-default C library adds its own variables, set only if that library is used:

| C library | Compiler | ARM | RISC-V |
|-----------|----------|-----|--------|
| newlib    | GCC      | `PATH_GCC_ARM`   | `PATH_GCC_RVXX` |
| newlib    | Clang    | `PATH_LLVM_ARM`  | `PATH_LLVM_RVXX` |
| picolibc  | GCC      | `PATH_GCC_ARMP`  | `PATH_GCC_RVXXP` |
| picolibc  | Clang    | `PATH_LLVM_ARMP` | `PATH_LLVM_RVXXP` |
| llvmlibc  | Clang    | `PATH_LLVM_ARML` | `PATH_LLVM_RVXXL` |

```bash
export PATH_GCC_ARMP=Your_Path_To_The_gcc_arm_picolibc        # -DC_LIBRARY=picolibc (GCC, ARM)
export PATH_GCC_RVXXP=Your_Path_To_The_gcc_riscv_picolibc     # -DC_LIBRARY=picolibc (GCC, RISC-V)
export PATH_LLVM_ARMP=Your_Path_To_The_llvm_arm_picolibc      # -DC_LIBRARY=picolibc (Clang, ARM)
export PATH_LLVM_RVXXP=Your_Path_To_The_llvm_riscv_picolibc   # -DC_LIBRARY=picolibc (Clang, RISC-V)
export PATH_LLVM_ARML=Your_Path_To_The_llvm_arm_llvmlibc      # -DC_LIBRARY=llvmlibc (Clang, ARM)
export PATH_LLVM_RVXXL=Your_Path_To_The_llvm_riscv_llvmlibc   # -DC_LIBRARY=llvmlibc (Clang, RISC-V)
```

A missing variable is a configuration error, not a silent fallback: `select-arm-toolchain.cmake`
and `select-riscv-toolchain.cmake` stop with `Environment variable PATH_... is not defined`.

---

## 2. Toolchain requirements

### 2.1 newlib

Nothing special: the stock ARM and RISC-V GCC and Clang toolchains are used as installed.

### 2.2 picolibc with GCC — the toolchain must be picolibc-native

`PATH_GCC_ARMP` and `PATH_GCC_RVXXP` must point at a GCC whose **default** C library is
picolibc — not at a newlib GCC carrying picolibc as an overlay reached through
`-specs=picolibc.specs`. The build passes no such specs on the compile line, so an overlay
toolchain would resolve `<stdlib.h>` and `-lc` to newlib while the image declares the
picolibc manager. A single GCC install can therefore no longer serve newlib as its main
C library and picolibc as an overlay; keep two toolchains per architecture, which is how
they are already configured.

The reason the specs file cannot simply be passed is that it breaks C++. Its `*cpp:` and
`*cc1plus:` stanzas `-isystem`-prepend `<sysroot>/<target>/include` so picolibc's headers
win over a co-installed newlib, which hoists the C header directory **above** the C++ ones:

```
1. .../arm-none-eabi/include            <- picolibc's stdlib.h
2. .../arm-none-eabi/include/c++/<ver>  <- <cstdlib>
```

libstdc++'s `<cstdlib>` is found in 2 and reaches the C header with
`#include_next <stdlib.h>`, which by definition searches only the directories **after**
its own — so it can never see 1. Every C++ translation unit then fails with

```
cstdlib:83:15: fatal error: stdlib.h: No such file or directory
```

while C compiles fine. On a picolibc-native GCC the sysroot include sits last, where
`#include_next` expects it, and no specs are needed: the default `libc.a` is already picolibc.

Everything else the specs contributed is covered without them — the include and library
paths are the toolchain's own defaults, `picolibc.ld` is overridden by `-T`, `crt0` by
`-nostartfiles`, the `--defsym` printf variants need opt-in macros this project never sets,
and `-mstack-protector-guard=global` is already GCC's default for `arm-none-eabi` (verified:
identical `__stack_chk_guard` code with and without the specs). The one exception is
`--gc-sections`, which the application build now adds explicitly (see §4).

**The build checks this for you.** `check-picolibc-default.cmake` compiles a probe that
includes `<stdlib.h>` and requires `__PICOLIBC__`; configuration stops with
`the default C library of ... is not picolibc` if the toolchain fails it. To vet a
candidate toolchain by hand:

```bash
# 1. the sysroot include must come LAST, after the c++ directories
$PATH_GCC_ARMP/bin/arm-none-eabi-g++ -mcpu=cortex-m55 -E -v -x c++ /dev/null 2>&1 \
    | sed -n '/#include <...> search starts/,/End of search/p'

# 2. the default libc.a must be picolibc: this must print 0
$PATH_GCC_ARMP/bin/arm-none-eabi-nm --defined-only \
    "$($PATH_GCC_ARMP/bin/arm-none-eabi-gcc -mcpu=cortex-m55 -print-file-name=libc.a)" \
    | grep -cE '_impure_ptr|__sfp'

# 3. C++ must compile with no specs
echo '#include <cstdlib>' > /tmp/t.cpp
$PATH_GCC_ARMP/bin/arm-none-eabi-g++ -mcpu=cortex-m55 -fsyntax-only /tmp/t.cpp
```

> A picolibc sysroot also ships a `newlib.h` — it is picolibc's own compatibility stub
> (BSD-3-Clause, "Copyright © 2019 Keith Packard"), **not** evidence of an overlay. Use the
> three checks above instead.

### 2.3 picolibc on RISC-V — `picolibc.specs` at link time only

RISC-V GCC is the one exception to "no specs". `gcc/config/riscv/elf.h` hardcodes

```
*lib: --start-group -lc %{!specs=nosys.specs:-lgloss} --end-group
```

so the driver always asks for `-lgloss`, newlib's board-support library. picolibc ships
neither `libgloss` nor a `nosys.specs` to suppress it, and the link dies with
`cannot find -lgloss`. `picolibc.specs` replaces that `*lib` stanza, so the reference
disappears — and it is applied to the **link only**, where the header-path damage of §2.2
cannot occur: that damage lives in the `*cpp:` and `*cc1plus:` stanzas, which the linker
never expands. ARM's driver adds no such library and needs nothing.

Both `Ports/cmake/system.cmake` and `Applications/cmake/application.cmake` add it under
`$<$<AND:$<C_COMPILER_ID:GNU>,$<STREQUAL:${CMAKE_SYSTEM_PROCESSOR},RISCV>>`.

### 2.4 picolibc with Clang — built with TLS disabled

Both LLVM picolibc toolchains must have picolibc built with `-Dthread-local-storage=false`.
See §7; a TLS-enabled picolibc fails at link on the linker-script assertion, by design.

### 2.5 LLVM libc — toolchain patch required

Minimum ARM version: **ATfE 22.1.0**, the first release shipping LLVM libc in the main
package. Verify the install:

```bash
$PATH_LLVM_ARML/bin/clang --version    # ATfE tags the banner with "llvmlibc"

# The RISC-V banner carries no such tag; check the runtime headers instead
ls $PATH_LLVM_RVXXL/lib/clang-runtimes/*/include/__llvm-libc-common.h
```

Stock baremetal LLVM libc defaults `CLOCKS_PER_SEC` to **100** on Arm, matching the
centiseconds an Arm semihosting `SYS_CLOCK` time source returns. uKOS-X drives `clock()`
from its own 1-µs kernel counter, so the ARM toolchain is built with

```
ukos_patches/0006-llvm-libc-use-microsecond-also-for-32-bit-Arm-cores.patch
```

which moves 32-bit Arm to the microsecond branch of
`libc/include/llvm-libc-macros/baremetal/time-macros.h`. It mirrors the newlib patch
`0002-Patch-time.h-for-uKOS.patch` and is applied with the rest of the uKOS-X patchset.

Patching is preferred over passing `-D__CLK_TCK=1000000` from the uKOS-X build because
`libc/src/time/baremetal/clock.cpp` is compiled against that header: patching keeps
`libc.a` and the application on the same unit, whereas a `-D` at application build time
would only change the application's side. RISC-V already takes the microsecond branch and
needs no patch.

Building against an unpatched toolchain stops on a `static_assert` in `llvmlibc.c`; the
interim workaround it names is `-DCFLAGS_APPEND=-D__CLK_TCK=1000000`.

---

## 3. Building

### 3.1 Presets

| Preset | Compiler | C library |
|--------|----------|-----------|
| `gcc` | GCC | newlib |
| `llvm` | Clang | newlib |
| `gcc-picolibc` | GCC | picolibc |
| `llvm-picolibc` | Clang | picolibc |
| `llvm-llvmlibc` | Clang | LLVM libc |

```bash
cd Ports/Targets/Nucleo_H743/Variant_Test
cmake --preset llvm-picolibc -B build
cmake --build build
```

Every preset sets `USER_MODE=ON` and `CANARY=ON`; append `-DUSER_MODE=OFF` or
`-DCANARY=OFF` to override.

### 3.2 Explicit configuration

The library can also be selected on the command line, on top of the `gcc` / `llvm` preset
or with no preset at all:

```bash
cmake --preset llvm -DC_LIBRARY=picolibc -B build     # Clang + picolibc
cmake --preset gcc  -DC_LIBRARY=picolibc -B build     # GCC   + picolibc
cmake --preset llvm -DC_LIBRARY=llvmlibc -B build     # Clang + LLVM libc
cmake -S . -B build -DUSE_LLVM=ON -DC_LIBRARY=picolibc
```

`C_LIBRARY=llvmlibc` requires `USE_LLVM=ON`; combining it with GCC is a configuration error.

### 3.3 Regression builds

`regression` (`Tools/Developer/run-regression.sh`, on `PATH` through `Tools/Developer/bin`)
is the widest net: it builds every system target and then every application into a
dedicated `artefacts` directory beside the repository, and mirrors its output into a
generated `regression-results-XXXXXX.sh` that replays the results when run.

```bash
regression                          # Clang + newlib, every target
regression -GP                      # GCC   + picolibc
regression -GP -t MAiXDUiNO_K210    # ... restricted to one target
regression -L                       # Clang + llvmlibc
regression -P -n                    # Clang + picolibc, no results script
```

Options: `-G` gcc, `-P` picolibc, `-L` llvmlibc (`-P` and `-L` are mutually exclusive, and
`-L` cannot be combined with `-G`), `-U` privileged mode only, `-Y` no canary, `-v` verbose,
`-n` no results script, `-t <target>` filter by target name.

### 3.4 Batch builds of one tree

`_build.sh` builds every variant listed in `variants.yaml`, and exists in both
`Ports/Targets` and `Applications/uKOS_Appls_Downloadable`. It takes the same
`-G` / `-P` / `-L` / `-U` / `-Y` flags:

```bash
cd Ports/Targets
./_build.sh          # Clang + newlib (default)
./_build.sh -GP      # GCC   + picolibc
./_build.sh -L       # Clang + llvmlibc
```

`Tools/Developer/latotale.sh` sweeps every toolchain × library × mode combination. Its
flags **exclude** passes rather than select them:

```bash
./latotale.sh          # everything
./latotale.sh -M       # everything except llvmlibc
./latotale.sh -P       # everything except picolibc
./latotale.sh -N       # everything except newlib
./latotale.sh -G       # clang only
```

The llvmlibc pass runs only when `PATH_LLVM_ARML` is set, and is skipped with a warning
otherwise; it covers the RISC-V targets too, so `PATH_LLVM_RVXXL` must be set as well.

### 3.5 Applications tied to one C library

A few application groups only build against a specific C library and are skipped
automatically under the others — currently `n_NewLibs`, which demonstrates the newlib
manager and includes `newlib/newlib.h`, pulling in a `<sys/reent.h>` that picolibc and
LLVM libc do not provide. The mapping is the `CLIB_ONLY_GROUPS` table, kept in both
`Applications/uKOS_Appls_Downloadable/_build.sh` and `Tools/Developer/run-regression.sh`.

---

## 4. What the build system does per library

Set in `Ports/cmake/system.cmake` (system image) and `Applications/cmake/application.cmake`
(downloadable applications).

| | newlib | picolibc | llvmlibc |
|---|--------|----------|----------|
| Compile definitions | `CONFIG_MAN_NEWLIB_S`, `__DYNAMIC_REENT__` | `CONFIG_MAN_PICOLIBC_S`, `_REENT_GLOBAL_ERRNO` | `CONFIG_MAN_LLVMLIBC_S` |
| Allocator wrapping | `--wrap=_malloc_r/_free_r/_realloc_r/_calloc_r` | `--wrap=malloc/free/realloc/calloc` | `--wrap=malloc/free/realloc/calloc` |
| Manager source | `OS/Lib_generics/newlib/newlib.c` | `OS/Lib_generics/picolibc/picolibc.c` | `OS/Lib_generics/llvmlibc/llvmlibc.c` |
| GCC specs | — | none, except `-specs=picolibc.specs` at link on RISC-V (§2.3) | n/a (Clang only) |
| Section GC | — | system: `--no-gc-sections` (GCC); application: `--gc-sections` | — |
| Extra include path | — | — | `OS/Lib_generics/llvmlibc/compat` |
| Force-included header | — | — | `OS/Lib_generics/llvmlibc/llvmlibc_shim.h` |
| Extra application source | — | — | `OS/Lib_generics/llvmlibc/llvmlibc_app_stdio.c` |

`_GNU_SOURCE` is defined for all three. The manager source is selected by the
`add_clib_manager_source()` helper in `Ports/cmake/proj_config.cmake`, and
`OS/Lib_generics/lib_generics.h` includes the matching `*.h` on the same three macros —
a build with none of them defined fails with `#error "No C library configured"`.

Two details worth knowing:

- **Section garbage collection (picolibc).** `picolibc.specs` unconditionally adds
  `--gc-sections`, which discards `.text` sections coming from `--whole-archive` objects
  when nothing inside the system binary references them. That would drop kernel API
  functions and peripheral drivers (e.g. `watchdog_arm`, `__errno`) that only downloadable
  applications call, so the **system** link adds `--no-gc-sections` for GCC — emitted after
  the specs on the ld command line, where it wins. The **application** link, which wants the
  collection, adds `--gc-sections` explicitly instead, since the specs no longer supply it.
- **LLVM libc `--config`.** A dedicated LLVM-libc toolchain selects the library on its own —
  no `--config` needed, and no such file exists in that install. Only an *overlay* install
  needs one: set `-DLLVMLIBC_CONFIG=llvmlibc.cfg` in that case.

---

## 5. What uKOS-X supplies

The manager source (`newlib.c`, `picolibc.c`, `llvmlibc.c`) is the bridge between the C
library and the kernel: file descriptors onto the serial managers, the allocator onto
`memo_malloc`, time onto the kernel counter. newlib and picolibc take most of it through
the usual syscall stubs; baremetal LLVM libc is intentionally minimal, so `llvmlibc.c`
supplies extra glue the other two get from the library itself.

| Concern | newlib | picolibc | llvmlibc |
|---------|--------|----------|----------|
| Standard I/O | `_open_r`, `_close_r`, `_read_r`, `_write_r` | `open`, `close`, `read`, `write` | `__llvm_libc_stdio_read/write` hooks + cookies |
| `dprintf` / `vdprintf` | library | library | uKOS-X shim (no `FILE*` in LLVM libc), declared via force-included `llvmlibc_shim.h` |
| `malloc` family | `__wrap__malloc_r` … → `memo_malloc` | `__wrap_malloc` … → `memo_malloc` | `__wrap_malloc` … → `memo_malloc` |
| `time()`, `gettimeofday()` | `_gettimeofday_r` | `gettimeofday` | from the kernel 64-bit Unix-time counter |
| `clock()` | library | library | defined by uKOS-X, which keeps `clock.cpp.obj` out of the link |
| `<sys/time.h>` | library | library | compatibility header in `OS/Lib_generics/llvmlibc/compat/sys/` |
| `CLOCKS_PER_SEC` | toolchain patch | toolchain | toolchain patch (§2.5) |
| `setenv` / `tzset` | library | library | stubs — accepted and ignored (§8) |
| Termination | `_exit` | `_exit` | `exit`, `_exit`, `__llvm_libc_exit` → `crt0_exit` |
| `gmtime_r`, `mktime`, `strftime`, … | library | library | library |

### Compatibility symbols for prebuilt newlib archives

Third-party archives that ship as binaries were compiled against newlib and reference
symbols the smaller libraries do not define. Both non-newlib managers fill the gaps:

- **`__errno`** — newlib's `<errno.h>` expands `errno` to `(*__errno())`, so every newlib
  object carries an undefined reference to that accessor. picolibc and LLVM libc have no
  equivalent, so both managers define it to return the address of the one `errno` they
  already write to. That puts the prebuilt code on exactly the same `int`, so the
  per-process save and restore of §6 covers it too. Needed by the ST N6 ATON driver
  (`Third_Parties/STM32/STM32N6/Library/AI`, used by the `gan` application on the N657
  boards). It is called only from applications, through `--just-symbols=FLASH.elf`, which
  is why it must survive the system link — see the `--no-gc-sections` note in §4.
- **`_exit`, `__assert_func`** (llvmlibc) — the Pico SDK TinyUSB port used by the RP2350
  target; LLVM libc spells them `exit` and `__assert_fail`.
- **`raise`** (llvmlibc) — `libdecnumber` (`Third_Parties/decnumber`, used by the `rpn` and
  `bid64_xyz` applications) calls `raise(SIGFPE)` when the caller enabled the matching trap.
  Baremetal LLVM libc ships no `<signal.h>` at all, so the manager defines `raise()` as a
  stub returning `-1`: the reference resolves, and no signal is ever delivered.

`exit()` is also overridden under LLVM libc: its own `exit()` walks the
`__cxa_thread_finalize()` / `__cxa_finalize()` list, which is meaningless for a per-process
exit in a baremetal RTOS and faults when that list is not in its initialised empty state.

---

## 6. Per-process state and `errno`

Each library keeps its per-thread state differently, so `xLibrary_update()`
(`OS/Lib_kernels/kern/xLibrary.c`) — called at every context switch — does something
different for each.

### 6.1 newlib — swap the reentrancy structure

newlib is built reentrant (`__DYNAMIC_REENT__`), so each process owns a `struct _reent`
in `proc_t.oInternal.oLocal` and the switch simply repoints `_impure_ptr` at it. `errno`,
the stdio buffers and the strtok/asctime scratch all follow for free.

### 6.2 picolibc — one global, parked per process

picolibc exposes `errno` as a single global `int` (`libc_errno_errno.c.o`). Every member
of the archive that reports an error binds to it — 89 of them, and a real uKOS-X image
links many (`strtol`, `vfprintf`, `vfscanf`, `sscanf`, `abort`, `signal`, the stack
protector, the Ryu float conversions) — as does every uKOS-X translation unit and every
downloadable application.

uKOS-X therefore does not try to redirect `errno`. It gives the one global per-process
semantics by parking and reloading it at each context switch, in the same hook where the
newlib build swaps `_impure_ptr`; the parked value lives in `proc_t.oErrno`. The swap runs
privileged with interrupts off, costs 17 Thumb instructions, and exits early when the
scheduler re-selects the same process.

An earlier design instead defined picolibc's `__PICOLIBC_ERRNO_FUNCTION` hook in
`picolibc.h`, making `errno` expand to `(*__ukos_get_errno())`. It has been removed: the
hook is a picolibc *build-time* option, so the shipped `libc.a` kept using the global and
the two diverged; and the accessor returned a pointer into `proc_t`, which on a
privileged/user build lives in the privileged RAM region and faulted with `DACCVIOL` when
a user-mode process assigned `errno`. Reinstating it would mean rebuilding picolibc with
`-Derrno-function=`, which also makes the toolchain uKOS-X-specific. See
[TLS_SUPPORT_ASSESSMENT.md](../,USER_GUIDES/TLS_SUPPORT_ASSESSMENT.md) §4.1.

> `_REENT_GLOBAL_ERRNO`, still among the picolibc compile definitions, is a newlib-era
> name; picolibc spells it `__GLOBAL_ERRNO`, so the define has no effect. `__DYNAMIC_REENT__`
> on the newlib side is likewise redundant — `sys/config.h` defines it anyway. Both are
> catalogued in the TLS assessment, §4.4.

### 6.3 llvmlibc — same swap, for a different reason

`errno` storage belongs to LLVM libc: one file-local `int` (`shared_errno`) reached both by
`__llvm_libc_errno()` and by the library's internal `Errno::operator=` / `operator int()`.
All three live in the same `libc.a` member, so uKOS-X cannot override the entry point — a
definition of `__llvm_libc_errno` is a duplicate symbol, and the library would keep using
the operators anyway. Because uKOS-X code and library code do reach the same `int`, the
kernel makes it per-process by the same park-and-reload as picolibc, again through
`proc_t.oErrno`. See
[TLS_SUPPORT_ASSESSMENT.md](../,USER_GUIDES/TLS_SUPPORT_ASSESSMENT.md) §4.2.

### 6.4 Known limitation — multi-core

On a multi-core image (K210, rp2350) the harts share the one global under picolibc and
LLVM libc, so `errno` remains racy *between cores*. newlib is unaffected: `_impure_ptr`
is resolved per core.

---

## 7. Thread-local storage

uKOS-X never installs a thread pointer: it links `-nostartfiles` with its own `crt0.c`, so
picolibc's crt0 — the only caller of `_set_tls()` — is never linked and `__tls` stays zero.
TLS accesses then land near address `0x00000008`: harmless-looking in privileged mode on a
Cortex-M (`PRIVDEFENA`, no MPU region at 0), and a `DACCVIOL` fault in user mode.

picolibc decides at build time whether its per-thread state (`errno`, `_asctime_buf`,
`_localtime_buf`, `_locale`, `_strtok_last`, …) lives in `.tbss` or in ordinary globals.
Its default (`thread-local-storage = 'picolibc'`) derives that from
`not cc.has_function('__emutls_get_address')` — false for GCC, whose libgcc ships
`emutls.o`, and true for Clang/compiler-rt. Both LLVM toolchains must therefore pass
`-Dthread-local-storage=false` when building picolibc.

The rule is enforced, not merely documented: all 25 linker scripts under
`Ports/EquatesModels/*/Runtime/` (`system_p.ld`, `system_pu.ld`, `application.ld`, plus the
rp2350 variants) collect `.tdata` / `.tbss` and assert them empty —

```
ASSERT(SIZEOF(.tdata) == 0, ...)
ASSERT(SIZEOF(.tbss)  == 0, ...)
```

— so a TLS-enabled C library fails at link instead of at run time. GNU ld and LLD share the
same `.ld` files; there are no separate `.lld` scripts.

Supporting declarations live in `Ports/EquatesModels/Generic/Runtime/linker.h`
(`linker_stTBSS` / `linker_enTBSS`) and the `.tbss` zero-initialisation in `crt0.c`, both
guarded by `#ifdef __clang__`.

The full account of why the thread pointer is never installed is *picolibc and
thread-local storage* in `CLAUDE.md`; what it would cost to lift the restriction is
assessed in [TLS_SUPPORT_ASSESSMENT.md](../,USER_GUIDES/TLS_SUPPORT_ASSESSMENT.md).

---

## 8. Known limitations of LLVM libc

Beyond the multi-core `errno` note in §6.4, LLVM libc carries limitations the other two
libraries do not.

- **Local time runs in UTC.** The cause is not the `setenv` / `tzset` stubs — LLVM libc has
  no timezone support at all, so nothing would read a stored TZ string. `localtime_r()` and
  `localtime()` return UTC (`libc/src/time/time_utils.h:176`, *"TODO: timezone support"*),
  `get_timezone_offset()` is a constant stub (`time_utils.h:351`), and `mktime()` treats the
  `struct tm` as UTC and forces `tm_isdst = 0` (`libc/src/time/time_utils.cpp:238`). The
  calendar manager still calls `setenv("TZ", ...)` + `tzset()`
  (`OS/Lib_generics/calendar/calendar.c:120,246`) because newlib and picolibc honour them;
  under LLVM libc the call is simply inert.

  Honouring TZ would mean uKOS-X implementing the timezone logic itself: a POSIX TZ parser
  (`CET-1CEST,M3.5.0/2,M10.5.0/2` → std/dst names, offsets, `Mm.w.d/h` transition rules), a
  DST-in-effect test, and overrides for `localtime_r`, `localtime` **and** `mktime` — the
  last because `date <d> <m> <y> <h> <m> <s>` converts local time back to an epoch and would
  otherwise set the clock off by the offset. The three are strong symbols in separate
  `libc.a` members, so uKOS-X definitions would win the link the way the `dprintf` shim
  already does. Two gaps would remain: `ctime()` / `ctime_r()` call the internal helper
  directly (`libc/src/time/ctime.cpp:23`) and would stay UTC, and LLVM libc's `struct tm`
  has no `tm_gmtoff` / `tm_zone` to populate. Deferred until upstream implements its TODO.
- **No `FILE*`.** File-based stdio (`fopen`, `fprintf`) is not available on baremetal LLVM
  libc; uKOS-X uses `dprintf` to file descriptors, which the shim covers.
- **No POSIX `sys/` headers** apart from `<sys/queue.h>`. Only `<sys/time.h>` has a
  compatibility header so far; another one needs a new file under `compat/sys/`.
- **No `<signal.h>`.** `raise` is supplied by the manager (§5) for the one archive that
  needs it; there is no signal delivery.
- **An application's `errno` is its own.** In the system image `__llvm_libc_errno` and its
  `shared_errno` storage are *local* symbols, so `-Wl,--just-symbols` cannot hand them to a
  downloadable application: the application links its own copy from `-lc` and binds to that.
  System processes get a per-process `errno` (§6.3); an application gets one `errno` for
  itself. This is the same hidden-visibility boundary that makes `llvmlibc_app_stdio.c`
  necessary. picolibc has no such split — its `errno` is a global the system image exports,
  so its `__errno` shim (§5) hands prebuilt code the very same `int` the kernel swaps. Under
  LLVM libc the shim returns the address of whichever `shared_errno` its own image links.
- **Clang only.** GCC has no LLVM libc path; asking for it is a configuration error.

---

## 9. Verifying and troubleshooting

Which toolchains are visible:

```bash
echo $PATH_GCC_ARM  $PATH_GCC_ARMP  $PATH_GCC_RVXXP
echo $PATH_LLVM_ARM $PATH_LLVM_ARMP $PATH_LLVM_ARML $PATH_LLVM_RVXXL
```

What a configured build actually selected:

```bash
grep C_LIBRARY        build/CMakeCache.txt      # newlib | picolibc | llvmlibc
grep CMAKE_C_COMPILER build/CMakeCache.txt      # the toolchain that was resolved
```

CMake also prints the decision at configure time, e.g.
`C library compile definitions (picolibc): CONFIG_MAN_PICOLIBC_S, _REENT_GLOBAL_ERRNO`
and `C library malloc wrapping: --wrap=malloc, ...`.

What ended up in the image:

```bash
strings build/FLASH.elf | grep -i picolibc      # "picolibc manager"
grep -o CONFIG_MAN_LLVMLIBC_S Artefacts/FLASH.cnf
grep '\.tbss' build/FLASH.map                   # must be empty or absent (§7)
```

Common configuration errors:

| Message | Cause |
|---------|-------|
| `Environment variable PATH_GCC_ARMP is not defined` | `-DC_LIBRARY=picolibc` with GCC, picolibc toolchain not exported (`PATH_GCC_RVXXP` for RISC-V) |
| `the default C library of ... is not picolibc` | `PATH_GCC_*P` points at a newlib GCC with a picolibc overlay (§2.2) |
| `cannot find -lgloss` | RISC-V GCC + picolibc without `-specs=picolibc.specs` on the link (§2.3) |
| `cstdlib:83:15: fatal error: stdlib.h: No such file or directory` | `-specs=picolibc.specs` reached a C++ compile line (§2.2) |
| `Environment variable PATH_LLVM_ARML is not defined (required for C_LIBRARY=llvmlibc)` | `-DC_LIBRARY=llvmlibc` without the LLVM-libc install |
| `C_LIBRARY=llvmlibc requires the LLVM toolchain (USE_LLVM=ON)` | `llvmlibc` asked for with GCC |
| `static_assert` failure in `llvmlibc.c` | LLVM libc toolchain built without the `CLOCKS_PER_SEC` patch (§2.5) |
| `ASSERT(SIZEOF(.tbss) == 0)` failure at link | picolibc built with TLS enabled (§7) |
| `undefined symbol: __errno` | prebuilt newlib archive linked without the manager's compatibility shim (§5) |

---

## 10. Quick reference

| Build | Environment | CMake |
|-------|-------------|-------|
| GCC + newlib | `PATH_GCC_ARM` / `PATH_GCC_RVXX` | `--preset gcc` |
| Clang + newlib | `PATH_LLVM_ARM` / `PATH_LLVM_RVXX` | `--preset llvm` |
| GCC + picolibc | `PATH_GCC_ARMP` / `PATH_GCC_RVXXP` | `--preset gcc-picolibc` |
| Clang + picolibc | `PATH_LLVM_ARMP` / `PATH_LLVM_RVXXP` | `--preset llvm-picolibc` |
| Clang + llvmlibc | `PATH_LLVM_ARML` / `PATH_LLVM_RVXXL` | `--preset llvm-llvmlibc` |

## 11. Where the switch is implemented

| File | Role |
|------|------|
| `Ports/cmake/commonPresets.json` | the five presets |
| `Ports/cmake/select-arm-toolchain.cmake` | `C_LIBRARY` → ARM toolchain path, GCC/llvmlibc rejection |
| `Ports/cmake/select-riscv-toolchain.cmake` | the same for RISC-V |
| `Ports/cmake/check-picolibc-default.cmake` | rejects a GCC whose default C library is not picolibc |
| `Ports/cmake/system.cmake` | defines, allocator wrapping, section GC, include paths for the system image |
| `Ports/cmake/proj_config.cmake` | `add_clib_manager_source()` |
| `Applications/cmake/application.cmake` | the same for downloadable applications |
| `OS/Lib_generics/{newlib,picolibc,llvmlibc}/` | the three C library managers |
| `OS/Lib_generics/lib_generics.h` | header switch on `CONFIG_MAN_*_S` |
| `OS/Lib_kernels/kern/xLibrary.c` | per-process C library state at context switch |
| `Ports/EquatesModels/*/Runtime/*.ld` | TLS assertions |
| `Tools/Developer/run-regression.sh` | full regression matrix, `CLIB_ONLY_GROUPS` |
