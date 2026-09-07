# Package quality

This fork's stated purpose is code hygiene rather than new functionality, so the checks
below are part of ordinary work rather than an occasional audit. They form six layers,
from the one that runs on every build to the ones you invoke deliberately:

| Layer | Tool | Invoked |
|---|---|---|
| Compiler diagnostics | the warning set in `system.cmake` | every build |
| Include hygiene | `include-what-you-use` | `checkiwyu`, `module-check-iwyu.sh` |
| Header self-containment | clang `-fsyntax-only` | `check-self-contained.sh` |
| Static analysis | clang-tidy, Cppcheck | `run-analyser`, `code_analysis.sh` |
| **Host unit tests** | a native harness under `Tools/Developer/tests` | `run-tests` |
| **On-target console tests** | `ukos-serial` driven from a per-board table | `run-board-tests` |

The first four layers read the code. The last two **run** it, and they answer different
questions: the host suite proves what a CLI module computes, including error paths that
need a manager to fail; the board suite proves that the firmware on a real target still
behaves. Neither subsumes the other — see §7 and §8.

`Tools/Developer/bin/` holds symlinks to the scripts, so putting that directory on your
`PATH` gives you `checkiwyu`, `run-analyser`, `clangd-target`, `latotale`, `regression`,
`run-tests` and `run-board-tests` as plain commands. The examples below use the symlink
names.

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

## 7. Host unit tests

`Tools/Developer/bin/run-tests` builds and runs a native test suite over the CLI modules.
The module under test is compiled **unmodified** from `OS/` and executed on the host, so a
command's argument parsing, conversion and output can be checked in seconds rather than
through a cross-compile, a flash and a serial session.

```sh
run-tests               # drift checks, configure, build, run
run-tests -s            # again under asan + ubsan
run-tests -i            # one process per test, so a crash names its test
run-tests -t port_      # one tier, or any substring of a suite or test name
```

It needs no cross toolchain and no board — but note that the uKOS-X shell environment puts
the embedded toolchain first in `PATH`, so a bare `clang` is the **ARM cross compiler**.
The build pins the host compiler through `xcrun` before `project()` for that reason.

Two tiers: modules that compile against the production headers unchanged, and modules that
additionally need a small stub for the per-core and per-SoC headers, which are inline
assembly and MMIO. A tier-2 run labels itself. `Tools/Developer/tests/README.md` documents
the method for adding a module — costing it with `nm -u` before starting, deriving the
matrix from the dispatch rather than the happy path, keeping a hand-copied double honest
with a drift check, and mutation checking the result rather than trusting a first green
run.

The suites currently sit on `develop` **without** the source fixes they assert, so eight of
them fail on purpose — each failure is a defect the suite detected in code the branch does not
change. `Tools/Developer/tests/EXPECTED-FAILURES` names them and the commit that fixes each;
a listed suite failing keeps the run green, a listed suite *passing* fails it so the entry
gets removed, and anything else failing is a genuine regression. Two of the eight (`hexloader`
and `sloader`) hang rather than fail, which is why every suite runs under a hard 10-second
budget — a suite normally takes about 3 ms.

Defects found while writing these tests are recorded in `Tools/Developer/tests/DEFECTS.md`
and left unfixed unless fixing them is the task at hand; tests that touch one pin **current**
behaviour and say so, so that a later fix turns the suite red rather than silently changing
what it asserts.

### Beyond the CLI and the kernel

Two further modules are covered. `mlpn` (`OS/Lib_neurals`, tier 1) is the only one in the
tree with no environmental coupling at all — no clock, no random source, no heap, no port
layer, no kernel — so its assertions are exact numeric ones rather than string comparisons.
`text` (`OS/Lib_generics`, tier 2) covers the four pure functions behind the CLI's
tokeniser; its blocking line editor is deliberately excluded, because it would hang the
runner rather than fail it.

### The kernel tier

A third tier compiles real `OS/Lib_kernels/kern` sources on the host and fakes only
what surrounds them — the interrupt mask, the running process, the allocator, the four
semaphore calls a pool makes. It covers `identifier`, `lists`, `mailboxes`, `mutexes`, `pools`, `semaphores`,
`signals` and `statistics` — about 3500 of the kernel's ~6900 lines, a little over half.

It must not be mixed with the CLI tiers, and the build enforces that rather than trusting
a convention: `fakes/ukos_fakes_kern.c` *defines* the kernel object tables that the real
kernel sources also define, so the two live in separate libraries and a mistake is a
duplicate symbol at link.

`INTERRUPTION_OFF` / `INTERRUPTION_RESTORE` are stubbed as a **counting** fake, which is
the one sanctioned exception to the rule in `tests/port/README.md` that a working macro
must not become a no-op. It counts scopes and checks they unwind LIFO, so an early return
that skips its restore fails — `pools.c` has 26 restore sites across six error-heavy
functions. It asserts pairing and order, never effect.

What this tier does **not** prove is the kernel's actual job: no interrupt is masked and no
context switch occurs, so `GOTO_KERN_*` records the *decision* to block and then returns
where the real macro never would — the suspension is not modelled, and a test that needs a
waiting process places it on the wait list itself. `KNB_CORES` is 1, so there is no
interleaving. `scheduler.c`, `processes.c` and `privileges.c` are board-only.

## 8. On-target console tests

`Tools/Developer/bin/run-board-tests` drives a table of console commands against a flashed
board through `ukos-serial` and asserts what comes back. Start a session first — the runner
never opens the port itself, because re-opening the device toggles DTR and resets some
targets:

```sh
ukos-serial start --port /dev/cu.usbmodem21403
run-board-tests                      # picks the table by board name
run-board-tests -n                   # dry run: print what would be sent
run-board-tests --allow-unsafe --have loopback
```

The table is data, one JSON file per board under `tests/board/tables/`, so another board is
a new file rather than new code. Rows that need a module the variant does not build, or
hardware that is not attached, are **printed as skips with their reason** rather than
silently passing. Exit codes match `ukos-serial`: `0` pass, `1` error, `2` the board went
unreachable, `3` an assertion failed.

Assertions rest on `ukos-serial send --expect` / `--refute`, which are evaluated against
that command's own captured output. Every pattern must assert *shape*: timestamps,
addresses, uptimes, the `VCS#` and section sizes all move between builds, and a row pinning
one of them is a test that gets deleted rather than fixed.

`Tools/Developer/tests/board/README.md` covers the table schema and, more importantly, what
this layer cannot prove — any branch needing a manager to fail, a module's exit status
(`OS/CLI/console/console.c` collapses success and failure into the same `break;`), and
anything about the other boards.

### The core dump

One check cannot be a table row. `coredump-test` provokes a real fault, and every path that
prints a core dump is terminal — the dump ends in `cb_signal()`, which is `[[noreturn]]`,
and every `crt0_exit()` panic ends with `INTERRUPTION_OFF` and never re-enables — so nothing
answers afterwards. The script asserts the dump's structure, then resets the board over SWD
and waits for it to come back.

```sh
coredump-test --name u5g9 -n                     # dry run
coredump-test --name u5g9 --sn <ST-Link serial>  # --sn: leave the other boards alone
```

It is the only on-target test that reaches `record_printLog()`, whose marks are its loop's
termination condition — so ascending timestamps with no repeat is a real assertion, verified
by mutation (unmarked, the board reprinted one record 3865 times and failed on two
assertions). It cannot, however, detect a `dumplog` inheriting those marks: that needs a
prompt after a dump, which no ARM board offers. Only §7 covers it.

This layer does not replace the hardware verification `CLAUDE.md` requires before changes
under `OS/`, `Ports/` or `Applications/` reach `develop`; it makes it repeatable.
