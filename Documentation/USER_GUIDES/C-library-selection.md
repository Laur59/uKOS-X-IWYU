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
from its own 1-µs kernel counter, so the ARM toolchain is built with two patches from
`Patches/llvm-arm/<version>/` in the toolchain build scripts:

- the one that drops `__arm__` from the centisecond branch of
  `libc/include/llvm-libc-macros/baremetal/time-macros.h`, moving 32-bit Arm to the
  microsecond branch — `0005-llvm-libc-use-microsecond-also-for-32-bit-Arm-cores.patch`
  in 23.1.0;
- the one that nests `arm-software/embedded/patches/newlib/0002-Patch-time.h-for-uKOS.patch`
  into the ATfE tree, so newlib's own `machine/time.h` reports 1'000'000 on Arm rather than
  100 — `0001-Add-patch-so-that-newlib-uses-also-microsecond-for-A.patch` in 23.1.0.

Refer to them by what they do rather than by number: the directory is keyed on the LLVM
version and the series is renumbered at every bump — the same logical change has been
0002, 0001 and 0001/0005 across 21.1.8, 22.1.8 and 23.1.0.

The GCC toolchain applies that same newlib patch from
`Patches/newlib/<version>/0002-Patch-time.h-for-uKOS.patch`. So on a uKOS-X toolchain every
C library agrees on the microsecond, and the `-D_CLOCKS_PER_SEC_=1000000` /
`-D_MACHTIME_H_` pair that `proj_config.cmake` passes for newlib and picolibc is a second,
independent guarantee rather than the only one.

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
| `setenv`, `getenv`, `unsetenv`, `tzset` | library | library | TZ-only environment and POSIX TZ parser in `llvmlibc_tz.c` (§8) |
| `localtime_r`, `localtime`, `mktime` | library | library | uKOS-X overrides in `llvmlibc_tz.c`, so local time honours TZ (§8) |
| Termination | `_exit` | `_exit` | `exit`, `_exit`, `__llvm_libc_exit` → `crt0_exit` |
| `gmtime_r`, `asctime`, `strftime`, … | library | library | library |

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
[TLS_SUPPORT_ASSESSMENT.md](TLS_SUPPORT_ASSESSMENT.md) §4.1.

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
[TLS_SUPPORT_ASSESSMENT.md](TLS_SUPPORT_ASSESSMENT.md) §4.2.

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
assessed in [TLS_SUPPORT_ASSESSMENT.md](TLS_SUPPORT_ASSESSMENT.md).

---

## 8. Known limitations of LLVM libc

Beyond the multi-core `errno` note in §6.4, LLVM libc carries limitations the other two
libraries do not.

- **Timezone support is uKOS-X's own** (see §8.1). LLVM libc has none: `localtime_r()` and
  `localtime()` return UTC (`libc/src/time/time_utils.h:176`, *"TODO: timezone support"*),
  `get_timezone_offset()` is a constant stub (`time_utils.h:351`), `mktime()` treats the
  `struct tm` as UTC and forces `tm_isdst = 0` (`libc/src/time/time_utils.cpp:238`), there
  is no `tzset()` at all, and `setenv` / `getenv` / `unsetenv` are declared but never
  defined. `OS/Lib_generics/llvmlibc/llvmlibc_tz.c` fills all of it in, so the calendar
  manager behaves as it does under newlib and picolibc. Two gaps remain: `ctime()` and
  `ctime_r()` call the internal helper directly (`libc/src/time/ctime.cpp:23`) and stay in
  UTC, and LLVM libc's `struct tm` has no `tm_gmtoff` / `tm_zone` to populate (the library
  declares no `tzname[]`, `timezone` or `daylight` either, so those are not provided).
  Why the support lives here rather than in a patched toolchain is §8.2.
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

### 8.1 Timezone support — `llvmlibc_tz.c`

`OS/Lib_generics/llvmlibc/llvmlibc_tz.c` supplies the half of the timezone story LLVM libc
leaves out, so that `date` prints a real local time instead of a second copy of UTC:

| Provided | What it does |
|---|---|
| `setenv`, `getenv`, `unsetenv` | a TZ-only environment — any other variable is accepted and discarded |
| `tzset` | parses the TZ string into a per-core descriptor |
| `localtime_r`, `localtime` | shift UTC by the offset in force at that instant, then call the library's own `gmtime_r` |
| `mktime` | civil local time → epoch, resolving `tm_isdst = -1` against the rules, then normalise the caller's `struct tm` |

The parser takes the full POSIX form `std offset [dst [offset] [,start[/time],end[/time]]]`:
`<...>`-quoted designations, `[+|-]hh[:mm[:ss]]` offsets, and `Jn` / `n` / `Mm.w.d[/time]`
transition rules, including `w = 5` for "last" and a start later than the end for the
southern hemisphere. A DST designation with no rule falls back on the current United States
rules, as newlib and musl do — POSIX leaves that case implementation defined. Anything that
does not parse leaves the descriptor on UTC.

The three time functions are strong symbols in their own `libc.a` members
(`localtime.cpp.obj`, `localtime_r.cpp.obj`, `mktime.cpp.obj`) that nothing else in the
library references, so these definitions win the link and those members are never pulled in
— the same mechanism the `dprintf` shim uses. `gmtime_r` is deliberately left to the
library. A downloadable application picks the overrides up through `-Wl,--just-symbols`,
because all four entry points are global symbols in `FLASH.elf`.

State is per core, matching the calendar manager's own per-core TZ strings; on a single-core
SoC `GET_RUNNING_CORE` is the constant `0U` and the indexing costs nothing.

**Cost.** Measured as the difference in the linker's `prgm_code` / `prgm_data` report,
`cmake --preset llvm -DC_LIBRARY=llvmlibc`, ATfE 23.1.0:

| Variant | flash | RAM |
|---|---|---|
| the eleven single-core ARM variants | +2412 … +2572 B | +160 … +192 B |
| `MAiXDUiNO_K210` (RV32, two cores) | +3104 B | +0 B (`.bss` unchanged in the report) |
| `Pico2_rp2350`, both cores/architectures | +5032 … +5228 B | +352 B |
| `Longan_Nano_F103` | +2408 B | +176 B |

The object itself is about 2.7 KB of `.text` everywhere; the two outliers are second-order
effects. `Pico2_rp2350` is the only variant without the `date` CLI, so nothing referenced
`gmtime_r` before and LLVM libc's `time_utils.cpp.obj` (2350 B) now joins the link for the
first time. The K210 pays for two cores' worth of descriptor and for RV32 code density.

**Turning it off.** `LLVMLIBC_TIMEZONE` (cache option, default `ON`) reduces the file to the
`setenv` / `tzset` stubs it held before the support existed; local time is then equal to UTC
and LLVM libc's own `localtime_r` / `mktime` are linked. A variant with no room overrides it
before its `add_clib_manager_source()` call:

```cmake
set(LLVMLIBC_TIMEZONE OFF)
add_clib_manager_source(libx_u)
```

`-DKLLVMLIBC_WITH_TIMEZONE_S=false` is recorded in `Artefacts/FLASH.cnf` when the option is
off. **No variant currently sets it.** `Longan_Nano_F103` did between `e8934a55b` and the
toolchain fix in §8.3 — the support overflowed its 128 KB by 1056 B — but it now has 39% of
its flash free and carries the timezone code like every other board.

### 8.2 Why this is not a toolchain patch

The obvious alternative — patch upstream LLVM libc (borrowing from this code or from
picolibc), rebuild the toolchains, and let `libc.a` carry the feature — was measured and
rejected. This fork already patches the toolchain for `CLOCKS_PER_SEC` (§2.5), so the idea
looks reasonable; it is not.

| | `llvmlibc_tz.c` (today) | patched into `libc.a` |
|---|---|---|
| system flash, the 15 variants with `date` | baseline | **−126 B** |
| system flash, `Longan_Nano_F103` | overflows by 1056 B | **still overflows by ~930 B** |
| system flash, `Pico2_rp2350` | +5228 B | ≈ −4 KB (board is at 8 % of 4 MB) |
| flash per application using local time | **0 B** | **+2.6 KB** and its own `time_utils` |
| application behaviour | correct local time | **UTC** — the bug returns |
| per-core TZ (K210, RP2350) | supported | lost — a libc has one global TZ |
| build cost | none | ~1 h per C-library variant, two delivery mechanisms |
| recurring cost | none | rebase the patch series at every LLVM bump |

**On-demand linking is worth 126 bytes.** The one structural advantage of `libc.a` is
per-member extraction: uKOS-X links its own libraries with `-Wl,-whole-archive`
(`Ports/cmake/system.cmake:242-255`) and passes **no `--gc-sections` on any path** — the
only occurrence in the tree is the `-Wl,--no-gc-sections` at `system.cmake:288-290` that
cancels `picolibc.specs` — whereas `-lc` is driver-injected at the end of the link line,
outside that wrapper. But almost everything in the file is reachable: `calendar.c:120,246`
calls `setenv` + `tzset` unconditionally, and 15 of the 16 variants compile
`OS/CLI/date/date.c`, which calls `localtime_r`, `mktime`, `gmtime_r` and `asctime`. From
the call graph (`llvm-objdump -r -d` on `llvmlibc_tz.o`), only `getenv` and `unsetenv`
— 126 B together — are unreferenced. `Pico2_rp2350` is the one exception, being the only
variant without `date`; it has 4 MB of flash.

**It would break the downloadable applications.** LLVM libc is built with hidden
visibility, so every libc symbol in `FLASH.elf` is LOCAL and `-Wl,--just-symbols` cannot
hand it over — the same boundary that makes `llvmlibc_app_stdio.c` necessary and gives an
application its own `errno` (§8). Today the four entry points are global, so an
application binds to the system image, pays nothing, and shares the TZ the calendar
manager set:

```
0800f164 T localtime_r    <- uKOS-X, GLOBAL   0803761c t memcpy    <- libc, local
0800f2ba T mktime         <- uKOS-X, GLOBAL   08042d68 t gmtime_r  <- libc, local
```

Inside `libc.a` they would be local, so each application would link its own copy **and its
own empty TZ environment**, printing UTC unless it called `setenv` + `tzset` itself.

**This implementation is already the smallest of the three.** Measured with
`llvm-size --format=sysv` on the `armv7m_hard_fpv4_sp_d16_exn_rtti_unaligned_size` multilib
of each installed toolchain:

| | TZ parser | `localtime_r`+`localtime`+`mktime`+`gmtime_r` | flash | static RAM | also drags in |
|---|---|---|---|---|---|
| newlib | 2321 B | 3416 B | ~5961 B | 132 B | `siscanf` 5886 B + `_malloc_r` 2622 B |
| picolibc | 1456 B | 2128 B | ~3600 B | 120 B | `sscanf` 2983 B + `getenv`/`environ` 198 B |
| **`llvmlibc_tz.c`** | 1064 B | 1472 B | **2716 B** | 176 B | **nothing** |

Borrowing from picolibc would make it *larger*: its `tzset` parses the TZ string with
`sscanf`, and newlib's also calls `malloc`. Neither dependency exists here — the parser
reads its own digits. Nor is there an optimization-level win:
`Tag_ABI_optimization_goals` in `.ARM.attributes` shows LLVM libc is built **`-Os`**
(Size × 286 members; Aggressive Speed × 6, only `mem*`), exactly what every variant already
compiles with. newlib is `-O2` and picolibc `-Oz`, so part of the spread in the table above
is an optimization artefact rather than source quality.

**What upstream is missing is the environment, not the algorithm.** The baremetal ARM
`libc.a` in ATfE 23.1.0 has no `tzset`, `setenv`, `getenv`, `unsetenv` or `environ` member
at all; its whole time inventory is `time_utils`, `asctime{,_r}`, `ctime{,_r}`, `difftime`,
`gmtime{,_r}`, `localtime{,_r}`, `mktime`, `strftime{,_l}` and `timespec_get`. Upstream's
`time.h` status page marks `tzset` implemented, but that is the hosted entrypoint set. A
patch would have to invent a process environment for baremetal and extend the entrypoint
list — a design discussion upstream, not a port. It would also have to be delivered twice:
ARM patches live in `Patches/llvm-arm/<version>/`, while the RISC-V build script has **no
patch mechanism at all** and carries its divergence as commits in the `Laur59/RTfE` fork.

Finally, §2.5's rule — patch the toolchain *when `libc.a` and the application must agree on
a value* — argues the other way here. Timezone behaviour is code, not a shared constant,
and the point of keeping it in the system image is precisely that the application does
**not** get an independent copy.

### 8.3 The `Longan_Nano_F103` flash budget

`Longan_Nano_F103` is the only board where the 2.4 KB mattered, and the timezone code is
not really what is wrong there:

| C library | flash used | of 128 KB | timezone support |
|---|---|---|---|
| picolibc | 96 373 B | 73.53 % | yes |
| newlib | 119 033 B | 90.81 % | yes |
| **llvmlibc** | **129 781 B** | **99.02 %** | no (option off) |

The LLVM libc image is **10.7 KB larger than the newlib one while delivering less** — the
newlib build carries a working `tzset`/`localtime`/`mktime` inside its 90.81 %. So the
obstacle is not `llvmlibc_tz.c`, and shaving it cannot help: the support needs 1056 B more
than the board has, and its conversion half is only 1472 B in total.

**Where the gap actually is: `printf` float formatting.** Decomposing both maps by archive
member, the difference is entirely in `libc.a` (+10 837 B; every uKOS-X library is within a
few bytes, and compiler-rt is 1956 B *smaller*):

| LLVM libc `libc.a` = 62 670 B | | newlib `libc.a` = 51 833 B | |
|---|---|---|---|
| `snprintf.cpp.obj` | **58 607** | printf / FILE machinery | 16 918 |
| | | scanf family | 7 886 |
| `time_utils.cpp.obj` | 1 440 | float ↔ string (`dtoa`, `mprec`) | 7 958 |
| `strtoul.cpp.obj` | 1 000 | timezone + time | 5 807 |
| everything else (13 members) | 1 623 | malloc family | 4 044 |
| | | everything else | 9 220 |

Of that 58 607 B, **47 738 B is float-to-decimal conversion** — `DyadicFloat<320>`,
`BigInt<128/320/640>` and `multiword` shift/multiply instantiations, i.e. LLVM libc's
correctly-rounded float printing done in arbitrary-precision arithmetic. newlib does the
same job in `dtoa` + `mprec` for **7 958 B**. That single feature is a ~40 KB difference;
LLVM libc claws ~29 KB of it back by not linking `FILE`, `malloc`, `scanf`, `locale` or
`signal`, which is why the *net* is only +10.7 KB.

(Symmetrically, newlib's timezone support is what pulls its scanf and part of its malloc in
on this board: `libc_a-tzset_r.o` has strong undefined references to `siscanf`, `_malloc_r`,
`free` and `_getenv_r`, and no uKOS-X code calls `scanf` at all. Newlib charges roughly
15 KB for the feature `llvmlibc_tz.c` provides in 2716 B.)

**The fix: build `printf` modularly.** LLVM libc can put the float converters behind weak
declarations and move their code into one archive member, `float_impl.cpp.obj`, which
`printf_main` reaches through a single strong reference emitted as
`.reloc ., BFD_RELOC_NONE, __printf_float`. ATfE has passed
`-DLIBC_CONF_PRINTF_MODULAR=ON` since 23.1.0; RTfE set the two neighbouring printf options
and omitted it, which is what made the RISC-V float code unavoidable. Adding it to the RTfE
fork (`release/riscv-software/23.x`, commit `c83a76a0`, pinned by `LLVM_RVXX_COMMIT`)
changed `float_impl.cpp.obj` from 78 bytes with an empty `.text` to 79 774 bytes, and
`snprintf.cpp.obj` from 58 607 to 7 354.

A firmware that never formats a float then defines `__printf_float` itself and the member is
never extracted. That is the `LLVMLIBC_PRINTF_FLOAT` option (cache, default `ON`); `OFF`
compiles the definition in `llvmlibc.c` and records
`-DKLLVMLIBC_WITH_PRINTF_FLOAT_S=false` in `Artefacts/FLASH.cnf`:

```cmake
set(LLVMLIBC_PRINTF_FLOAT OFF)
add_clib_manager_source(libx_u)
```

Two things to know before using it. `-Wl,--defsym=__printf_float=0` does **not** work — LLD
applies `--defsym` after archive extraction, so the definition has to come from a real
object linked before `-lc`, which every uKOS-X library is. And `printf_core/converter.h`
calls `convert_float()` with **no null guard**, so in such an image a `%a`, `%A`, `%e`,
`%E`, `%f`, `%F`, `%g` or `%G` branches to address 0. Only a variant that provably never
formats a floating-point value may set it.

**Result on the three RISC-V variants**, `cmake --preset llvm -DC_LIBRARY=llvmlibc`:

| | before (non-modular RTfE) | now | |
|---|---|---|---|
| `Longan_Nano_F103` — option **OFF** | 129 781 B (99.02 %), timezone support off and no room for it | **79 793 B (60.88 %)**, timezone support on | **−49 988 B** |
| `MAiXDUiNO_K210` — option `ON` | 1 005 057 B (47.92 %) | 1 026 993 B (48.97 %) | +21 936 B |
| `Pico2_rp2350-RV32IMAC` — option `ON` | 365 572 B (8.72 %) | 391 512 B (9.33 %) | +25 940 B |

**How much the option is worth** varies with architecture and with how much of the printf
surface the image links, so measure rather than assume. Same-image comparisons, option ON
against OFF:

| variant | ON | OFF | saving |
|---|---|---|---|
| `Nucleo_H743` (Cortex-M7) | 347 508 B | 308 440 B | 39 068 B |
| `MAiXDUiNO_K210` (RV64) | 1 026 993 B | 982 361 B | 44 632 B |
| `Pico2_rp2350-RV32IMAC` | 391 512 B | 314 148 B | **77 364 B** |

(The ARM and Pico2 rows are measurements only — neither variant sets the option.)

**The modular build is not free where floats are kept.** Its `float_impl.cpp.obj` is
somewhat larger than the instantiations it replaces, so a variant that still links it pays
about 22–26 KB more than it did under the non-modular toolchain. The K210 and the Pico2 sit
at 49 % of 2 MB and 9 % of 4 MB, so they absorb it; the trade is worth taking because the
Longan is the binding constraint and it is the one that can drop the module. ARM is
unaffected — ATfE has always built modularly, so nothing changed there.

**The precondition has two halves, and the first one is easy to get wrong.**

*No float conversion may survive preprocessing.* Grepping the sources is **not** good
enough — it misses conversions behind `#if`, and it is easy to write a pattern that
silently matches nothing. `OS/CLI/process/process.c:345` prints `%6.2f`, but only inside
`#if (KKERN_WITH_STATISTICS_S == true)`, which `Longan_Nano_F103` disables; whereas
`OS/CLI/memory/memory.c` printed `%5.2f` unconditionally, which a source-level grep of that
variant's file list initially missed. Check the preprocessed output of the configured
build instead, which accounts for every guard:

```bash
# from a configured variant directory
python3 - <<'EOF' > /tmp/pp.sh
import json, re
for e in json.load(open('build/compile_commands.json')):
    c = re.sub(r' -o [^ ]+', '', e['command']).replace(' -c ', ' -E -P ')
    print(f'echo "@@FILE {e["file"]}"; {c} 2>/dev/null')
EOF
zsh /tmp/pp.sh 2>/dev/null | awk '/^@@FILE/{f=$2}
    /"/{ if (match($0, /"[^"]*%[-+ #0-9]*(\.[0-9]+)?[aAeEfFgG]/))
             print f": "substr($0, RSTART, RLENGTH) }' | sort -u
```

Empty output means no `%a`/`%e`/`%f`/`%g` reaches the compiler. The Longan passes it across
all 53 translation units, but only since `memory.c` was changed to print its percentages
with integer arithmetic — that change is what made the option safe there.

*And no downloadable application may target the board.* An application reaches the system
image's `dprintf`, so it inherits whatever the system image linked. `Longan_Nano_F103` has
no applications. The K210 has 31, of which 7 format a float (`a_Basics/calendar`,
`a_Basics/plotSin`, `k_Mathematicals/cordic` and the four `l_MLPs` demos), so it could not
take the option even though it would fit.

Note the option is only useful on a toolchain built with `LIBC_CONF_PRINTF_MODULAR`. Turning
it on against a toolchain without it is harmless but saves nothing: there is no
`__printf_float` reference to satisfy, and the float code sits inside every printf
translation unit instead.

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
