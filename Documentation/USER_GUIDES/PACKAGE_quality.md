# Package quality

This fork's stated purpose is code hygiene rather than new functionality, so the checks
below are part of ordinary work rather than an occasional audit. They form four layers,
from the one that runs on every build to the ones you invoke deliberately:

| Layer | Tool | Invoked |
|---|---|---|
| Compiler diagnostics | the warning set in `system.cmake` | every build |
| Include hygiene | `include-what-you-use` | `checkiwyu`, `module-check-iwyu.sh` |
| Header self-containment | clang `-fsyntax-only` | `check-self-contained.sh` |
| Static analysis | clang-tidy, Cppcheck | `run-analyser`, `code_analysis.sh` |

`Tools/Developer/bin/` holds symlinks to the scripts, so putting that directory on your
`PATH` gives you `checkiwyu`, `run-analyser`, `clangd-target`, `latotale` and `regression`
as plain commands. The examples below use the symlink names.

The result of the last full sweep is recorded in `../analysis-baseline.md`, one section per
variant. Compare a new run against it: a finding that is not listed there is a regression,
and one listed there that no longer appears is a fix. Its notes also record which recurring
findings are configuration-dependent and must not be acted on.

## 1. Compiler diagnostics

The system build compiles with `-Wall -Wextra -Wpedantic -Wconversion -Wshadow
-Wunreachable-code -Wswitch-default -Wcast-align -Wcast-qual`, plus `-Wstrict-prototypes`
and `-Wc++-compat` for C. New code must be clean under both toolchains, because
`Ports/Targets/_build.sh` reports a variant as `WARNING` on *any* diagnostic, not only on
an error. Building every variant with each compiler is therefore the cheapest quality gate
available:

```bash
cd Ports/Targets
./_build.sh          # LLVM
./_build.sh -G       # GCC
```

## 2. Include What You Use

IWYU is the check this fork exists for. It reports, per translation unit, the includes
that are used but not declared, and those declared but unused — the two halves of the IWYU
rule. Together with layer 3 it is what keeps headers self-contained and include lists
honest.

### Prerequisites

- `include-what-you-use` on your `PATH` (it is not shipped with the embedded toolchains)
- `jq`, used to read `compile_commands.json`
- `PATH_LLVM_ARM` and `PATH_LLVM_RVXX`, for the toolchain system-header directories

### Checking one variant

```bash
cd Ports/Targets/Nucleo_H743/Variant_Test
checkiwyu                    # defaults to the llvm preset
checkiwyu llvm-nouser        # any llvm* preset
```

Only LLVM presets are accepted; the script refuses anything else, because it rewrites the
clang invocations that CMake recorded. It wipes `build/`, reconfigures with
`CMAKE_EXPORT_COMPILE_COMMANDS=ON`, then replays every entry of
`build/compile_commands.json` through IWYU, printing each file as it goes.

### Checking one module across every target

A module's headers are reached differently by different boards, so an include list that
satisfies one target can still be wrong for another:

```bash
Tools/Developer/module-check-iwyu.sh OS/CLI
```

### How the check is built

The compile command CMake recorded cannot be handed to IWYU unchanged, and the script's
transformations are worth knowing when a result looks wrong:

- `clang`/`clang++` is replaced by `include-what-you-use`, and the CPU flags — `-mcpu`,
  `-march`, `-mfloat-abi`, `-mfpu`, `-mabi`, `-mthumb` — are stripped. IWYU parses with
  its own clang, which does not need them and rejects some of them.
- `--target=` is kept for ARM but normalised to `riscv32-unknown-elf` /
  `riscv64-unknown-elf` for RISC-V, and the matching
  `<toolchain>/lib/clang-runtimes/<triple>/include` is added with `-isystem`. IWYU is a
  separate binary from the toolchain's clang and does not find those headers on its own.
- For C++ sources, `include/c++/v1` is added **before** the C include directory. libc++'s
  `math.h` and friends are wrappers that `#include_next` the real newlib header; in the
  other order newlib's `math.h` shadows the wrapper and the parse fails.
- Assembly files and the generated `FLASH.sig` source are skipped.

### The mapping file

`Tools/Developer/check-iwyu/iwyu-ukosx.imp` tells IWYU which private headers are reachable
only through a public one, so it stops suggesting the private path:

```json
[
  { "include": ["<__float_float.h>", "private", "<float.h>", "public"] },
  { "include": ["<tusb_os_custom.h>", "private", "<tusb.h>", "public"] }
]
```

Extend it when IWYU proposes an include that a user of the API is not supposed to name —
a toolchain-internal header, or a third-party header meant to be reached through its
umbrella. Do not silence a suggestion in the mapping file when the honest fix is to add
the include.

## 3. Header self-containment

IWYU judges a translation unit; this checks the complementary property, that a header
compiles on its own. Each header is compiled with `-fsyntax-only` using the flags of a real
target, so it passes only if nothing it needs is missing and nothing it declares is
undefined:

```bash
Tools/Developer/check-self-contained.sh <files-list> [target …]
```

`<files-list>` is a text file with one header path per line; blank lines and lines starting
with `#` are ignored. With no target the check runs against all known targets, configuring
each one once to obtain its compile commands.

## 4. Static analysis

Static analysis complements the two checks above: they police include structure, it looks
for defects inside the code. Both tools write into a `Static_Analysis/` directory created
in the variant you run them from.

### clang-tidy

```bash
cd Ports/Targets/Nucleo_H743/Variant_Test
run-analyser
```

The script replaces `scan-build`, which does not work with this CMake setup: it runs the
clang static analyser over the compile commands and then clang-tidy as a linter,
generating HTML reports under `Static_Analysis/`. It prefers the embedded toolchain's
`clang-tidy` over a system one so that the analysis matches the compiler.

The rule set is `.clang-tidy` at the repository root — `bugprone-*`, `cert-*`,
`performance-*`, `portability-*`, `misc-*`, `readability-*` and `clang-analyzer-*`, with
individual checks disabled by a leading `-`. Note that `misc-include-cleaner` is switched
off there: it overlaps with IWYU and is noisier, so include hygiene is left to IWYU.

### Cppcheck

```bash
cd Ports/Targets/Nucleo_H743/Variant_Test
Third_Parties/Cppcheck/Construction/Tools/code_analysis.sh        # open source
Third_Parties/Cppcheck/Construction/Tools/code_analysis.sh -P     # Premium
Third_Parties/Cppcheck/Construction/Tools/code_analysis.sh -c     # clear previous results
```

`cppcheck` and `cppcheck-htmlreport` must be on your `PATH`. The result is an HTML report
at `Static_Analysis/html/index.html`. The `-P` option enables the Premium rule sets —
`misra-c-2023` and `cert-cpp-2016` — which the open-source build cannot check; the
suppression list for those rules is
`Third_Parties/Cppcheck/Construction/Rules/uKOS_misra_rules.suppress`.

## 5. Whole-package regression

Beyond a single variant, two scripts build the package across configurations:

```bash
latotale             # every system, every configuration, both toolchains
regression           # full regression, out-of-source builds
```

They are the coarse net: anything that breaks a target under some combination of toolchain,
C library, user mode and canary shows up there rather than in a single-variant build.

## 6. Reproducibility

The third-party libraries under `Third_Parties/` build the same bytes from the same
commit. Two things used to prevent that, and `ukos_reproducible_build()` in
`Ports/cmake/reproducible.cmake` handles both. Each package calls it from its
`Construction/cmake/common-build.cmake` (TinyUSB from `Construction/Family/cmake/TinyUSB.cmake`).

- **Archive metadata.** `ar` records each member's mtime, uid and gid, so an archive
  differed even when every object in it was identical. The archive rules now use the
  deterministic `D` modifier and `ranlib -D`. The post-build `strip` needs `-D` too:
  stripping an archive rewrites its members, and without the flag it puts the wall-clock
  metadata straight back.
- **`__DATE__` and `__TIME__`.** Nearly every module ends its help string with
  `"Module built on " __DATE__ " " __TIME__`, so one object per module changed on every
  build. GCC and Clang both compute those macros from `SOURCE_DATE_EPOCH`, which is
  supplied through the compiler launcher. The epoch is the commit date of `HEAD`, so it
  follows the source: move the checkout to another commit and the date moves with it,
  because the configure step depends on the git `HEAD` and `index` files. An epoch
  exported in the environment wins; a checkout that is not a git working tree keeps
  wall-clock dates rather than a misleading fixed one.

The date therefore reports *which commit was built*, not when the compiler ran — the two
coincide only for a freshly committed tree. A dirty tree keeps the epoch of the last
commit; `version.h` carries the `-dirty` marker, and `ukos-serial verify --expect-sha`
is the reliable way to confirm what a board is running.

The launcher does not appear in `compile_commands.json`, so clangd and the IWYU checks
above see the plain compiler command exactly as before.

To check a package, build it twice from clean and compare:

```bash
cd Third_Parties/decnumber
for pass in 1 2; do
    ./very_clean.sh
    cmake -S . -B build -GNinja && cmake --build build && cmake --install build
    (cd Library && find . -type f | sort | xargs shasum -a 256) > /tmp/pass$pass.txt
done
diff /tmp/pass1.txt /tmp/pass2.txt      # no output
```

Scope is the third-party libraries. The system image and the downloadable applications
are **not** covered: the same two settings would extend to a target variant, and the
applications would need `-ffile-prefix-map` besides, because they compile with `-g3` and
absolute paths land in the debug information.
