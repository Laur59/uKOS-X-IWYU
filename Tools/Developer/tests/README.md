# Host unit tests

Native (macOS) unit tests for uKOS-X CLI modules. The module under test is
compiled **unmodified** from `OS/` and executed on the host, so a command's
argument parsing, conversion and output can be checked in milliseconds instead
of a cross-compile, a flash and a serial session.

```sh
Tools/Developer/bin/run-tests            # drift checks, configure, build, run
Tools/Developer/bin/run-tests -s         # again under asan + ubsan
Tools/Developer/bin/run-tests -i         # one process per test
Tools/Developer/bin/run-tests -c         # drive the run through ctest
Tools/Developer/bin/run-tests -t argc3   # only tests whose name contains "argc3"
```

The default path runs the test executables directly, because `ctest` hides a
*passing* test's output — which is exactly where the known-bug report lives.
`add_test()` is still wired up, so `-c` (or plain `ctest`) works for CI-style
pass/fail.

This complements, and does not replace, the existing quality layers described in
`Documentation/USER_GUIDES/PACKAGE_quality.md`: it is the only one that executes
code with assertions, but it says nothing about a real board.

## How a firmware module runs on the host

`shim/ukos_host_shim.h` is force-included ahead of the module and does exactly
three things:

1. **Redirects `dprintf()` and `time()`** onto test doubles, so output can be
   captured and "now" pinned. Both are *function-like* macros: an object-like
   `#define time X` would rewrite the identifier everywhere downstream and
   collide with unrelated uses such as `struct ntptimeval::time`.
   `ukos_test_dprintf` keeps a `format(printf, 2, 3)` attribute, without which
   replacing `dprintf` would silently disable `-Wformat` on every format string
   in the module.
2. **Rewrites the `MODULE()` section attribute.** `modules.h` places the
   directory entry in `.directory`; Mach-O requires a `segment,section` pair, so
   this is the one and only construct that does not compile natively.
   `aName_Specifications` is still emitted, so tests reach the module through
   `oExecution` and never `#include` the `.c` file.
3. Nothing else. Every other project header is the real one, so the tests also
   guard their host-cleanliness.

## Three tiers, and a fourth thing that is not a tier

**Tier 1 — real headers only.** Every project header on the include path is the
production one; the shim's three rewrites above are the entire divergence. A
module here also guards its own host-cleanliness.

**Tier 2 — real headers plus a stub port layer.** Headers under `port/` stand in
for the per-core and per-SoC ones, which are inline assembly and MMIO.
Everything else — `kern/`, `memo/`, `record/`, `serial/`, `text/`, `system/`,
and the real `spin.h` — is still the production header. Tier 2 buys reach and
pays for it in fidelity; what each stub does and does not assert is in
[`port/README.md`](port/README.md).

Tier-2 executables are named `ukos_tests_port_*`, their sources live in
`cli/port/`, and each run prints `[port stubs: …]` under the suite name, so a
run against stubs is self-labelling. `run-tests -t port_` selects the tier.

**Tier 3 — the real kernel.** Tiers 1 and 2 test a CLI module against a *faked*
kernel. Tier 3 inverts that: it compiles real `OS/Lib_kernels/kern` sources and
fakes only what surrounds them.

The two cannot be mixed, and the build enforces it rather than trusting a
convention. `fakes/ukos_fakes_kern.c` **defines** `vKern_mutx`, `vKern_sema`,
`vKern_proc`, `vKern_mbox`, `vKern_sign` and fourteen counters — exactly what
`mutexes.c`, `semaphores.c`, `processes.c`, `mailboxes.c` and `signals.c` define
themselves. `ukos_kern_support` therefore does not link `ukos_port_support`, so
a mistake is a duplicate symbol at link rather than a silent substitution. That
is also why `ukos_fake_runningCore` exists twice in this tree, once per tier.

Tier-3 executables are named `ukos_tests_kern_*`, their sources live in `kern/`,
and they print `[kern: …]` under the suite name. Note `run-tests -t kern_` is
**not** a clean selector — `szkern`'s own test names contain it. Use
`-t ukos_tests_kern_`.

| Tier | Modules |
|---|---|
| 1 | `date` `kill` `list` `man` `mlpn` `rnd` `run` `uKOS` |
| 2 | `dump` `dumplog` `dumptrace` `fill` `hexloader` `mutex` `object` `semaphore` `sloader` `szkern` `text` `X` |
| 3 | `identifier` `lists` `mailboxes` `mutexes` `pools` `semaphores` `signals` `statistics`, plus `kernenv` for the fakes' own contracts |

Several modules are built twice, so the covered modules produce more executables
than that: `date` with and without a hardware RTC, every tier-2 module and
tier-3 `pools` with and without `PRIVILEGED_USER_S`, and `szkern` at two kernel
configurations.

### Two modules that are neither CLI nor kernel

`mlpn` (`OS/Lib_neurals`) sits in tier 1 and is the only module in the tree with **no
environmental coupling at all** - no clock, no random source, no heap, no port layer, no
kernel. Nothing for a fake to distort, so its assertions are exact numeric ones rather
than string comparisons, using `EXPECT_EQ_F32`. Two things there are pinned with a
tolerance instead, each for a measured reason: `KMLPN_TAN0` goes through the host's
`tanhf`, and the shipped-network golden's 74-element dot products round differently at
`-O0` and `-O2`. What it cannot reach is the Helium/MVE path - `__ARM_FEATURE_MVE` is
M-profile only, so the host compiles the scalar fallback and nothing else.

`text` (`OS/Lib_generics`) is in tier 2 for a purely **lexical** reason: it includes
`kern/kern.h`, which reaches `macros_soc.h`. Nothing tested in it needs the port layer.
Only its four pure functions are covered; the blocking line editor is not, because
`local_waitOrder` is a `while (true)` that exits only on CR or LF and would hang the
runner rather than fail it.

It is also the only suite that compiles the real `text_checkAsciiBuffer`, which is why
`fakes/ukos_fakes_text.c` exists as a translation unit of its own: an archive member is
pulled only when a symbol it defines is still needed, and that suite already has the
symbol from `text.c`. Merging it back into `ukos_fakes.c` reintroduces a duplicate symbol,
and a per-target `#define` cannot fix it - that file is compiled once, into the library.

### What tier 3 does not prove

It does not test the RTOS **as** an RTOS. No interrupt is ever masked — pairing
and nesting only, never effect. No context switch happens, so every
`GOTO_KERN_*` path is out of reach and blocking behaviour is untested.
`KNB_CORES` is 1, so there is no interleaving. `KERN_PREPARE_FRAME` and the
naked save/restore pair have no host equivalent at all.

What it does test is the algorithms and error paths that happen to live in the
kernel: list topology, block allocation, bounded comparison, saturating
arithmetic — and, on every one of them, that the interrupt mask and the
privilege level come back on every return path.

`mutexes` and `semaphores` reach further than the rest: they are blocking
primitives, and `GOTO_KERN_M` does not return on a target. The stub records the
message and returns, so what is tested is **the decision to block** and the code
that runs after resumption - the counter arithmetic on both sides of the trap is
real - never the suspension itself. A test that needs a waiter parks it on the
object's list with the real `lists_connect()`; nothing proves the scheduler
would do the same. The full statement is in `port/macros_core_stackFrame.h`.

One thing the host does better than a board: `IS_EXCEPTION` is settable, so the
`KERR_KERN_FRISR` arms are reachable. On hardware they need a real interrupt
handler and are effectively untestable.

`mailboxes` was the module the "test file `#include`s the `.c`" escape hatch was
approved for, and it turned out not to need it: `local_write` and `local_read`
are called from the public entry points on every transfer, so the ring wrap is
reachable through `kern_writeMailbox` / `kern_readMailbox`. The hatch remains
unused; `scheduler.c`'s `local_getNextProcess` is the only place still likely to
want it.

`signals` is where a host test comes closest to testing the real thing: ten
entry points, no static functions, no allocation, and almost nothing but 32-bit
mask arithmetic. Its one structural trap is that a process's slot in
`sign_t.oSynchro[]` is its OFFSET into `vKern_proc`, so a test process must come
from that array or the module writes out of bounds.

The eight modules covered are about 3500 of the kernel's ~6900 lines - a little
over half.
`scheduler.c`, `processes.c` and `privileges.c` are board-only and are expected
to stay that way.

**[`board/`](board/README.md) is not a third tier of this suite** — it is a
different question answered on different hardware. `run-board-tests` drives a
table of console commands against a flashed board. The host suite proves what a
module computes; the board suite proves that the firmware still behaves. Neither
subsumes the other, and the split is deliberate:

| | proves | cannot prove |
|---|---|---|
| host | every branch, including error paths only reachable by making a manager fail; a module's return value | that any of it works on a target |
| board | the firmware still behaves, on one board, one variant, one C library | any unreachable branch, or a module's exit status — the console collapses success and failure into the same `break;` |

The doubles now cover the calendar, the module directory, the kernel object and
record tables, the mailbox, the allocator, the random generator, the serial
input stream and the download slot. What a given module actually needs is a
`nm -u` away — see step 1 below.

## The tests arrive before the fixes

This branch carries the suites **without** the source changes they assert. That
is deliberate: the tests are a detector, and whether to take the fixes or to
schedule the work is the team's call, not the tooling's. Eight suites therefore
fail here, and each failure is a defect found in code this branch does not
touch.

`EXPECTED-FAILURES` is the record. Each line names a suite, the commit on
`Features/unit-test` that makes it pass, and what it detects:

| a suite listed there that… | is reported as | run exits |
|---|---|---|
| fails | *failed as expected* | 0 |
| **passes** | **FIXED — remove its line** | **1** |
| is not listed and fails | an unexpected failure | 1 |

The middle row is the important one, and it is the same polarity as the
harness's XPASS: once a fix lands, the entry has become a lie and the run fails
until the line is deleted. The file is not a way to silence a test — it is a
statement that a specific defect is still present, and removing a line is how a
fix gets acknowledged.

So a green run on this branch means *no regressions*, not *no defects*. The
summary says which.

### Nothing may hang

Two of those suites do not fail — they **hang**. `hexloader` and `sloader` spin
forever against the unfixed loop, which is exactly the defect they were written
to expose, and a detector that hangs is not a detector.

`run-tests` therefore gives every suite a hard budget and kills it: **10 seconds,
30 under `-s`**. That is not a guess. A suite takes about **3 milliseconds**, so
the budget is three orders of magnitude of headroom while still bounding a hung
run at a few seconds. macOS has no `timeout(1)`, so the runner backgrounds each
executable, polls, and kills; 124 is reported for a timeout, following GNU
`timeout`, so a caller can tell one from a failure.

## Drift guards

Two pieces of production code are duplicated here because their originals are
not host-buildable — the `MODULE()` macro and the body of
`text_checkAsciiBuffer()`. `run-tests.sh` diffs both against their originals
before configuring and **aborts on any divergence**, so the copies cannot rot
into testing stale semantics.

## Reading the result

A test that passes with nothing to say stays silent. A test that reports
something gets a header, so a tag is never orphaned from the case that produced
it, and the run ends with a tally:

```
   date_argc3_gmt_passes_argv1_not_argv2
      KNOWN BUG date-gmt-passes-argv1
      KNOWN BUG date-gmt-passes-argv1
   ...

   Behaviour asserted but not desired
      KNOWN BUG date-gmt-passes-argv1                    3 assertion(s)
      QUIRK     text-checkAsciiBuffer-space-terminates   2 assertion(s)
      ...

   41 passed, 0 failed, 209 assertions, 14 known-bug assertion(s) still holding
```

`KNOWN_BUG` / `QUIRK` mark behaviour that is asserted but not desired. A defect
that is **still present** is reported and does *not* fail the suite; a defect
that has been **fixed** reports `FIXED` and *does* fail, so whoever repairs the
module is forced to update the expectation rather than leave an assertion that
no longer asserts anything.

Timezones are pinned per test with POSIX TZ strings (`UTC0`,
`CET-1CEST,M3.5.0,M10.5.0/3`) — never zoneinfo names, which newlib has no
equivalent for. `ctest` injects a hostile `TZ=Pacific/Kiritimati` so a test that
forgets to pin one fails loudly.

## Adding a module

### 1. Cost it before committing to it

The price of a module is the number of symbols that must be faked, and whether
any of them reach the kernel or a peripheral. Measure it instead of guessing —
compile the module against the existing shim and list what is left undefined:

```sh
SP=$(mktemp -d)
INC=(-IOS/Includes -IOS/Lib_cryptographics -IOS/Lib_generics -IOS/Lib_kernels
     -IOS/Lib_peripherals -IOS/Lib_serials -I"$SP")
/usr/bin/clang -std=c23 -c -include Tools/Developer/tests/shim/ukos_host_shim.h \
    "${INC[@]}" OS/CLI/<module>/<module>.c -o "$SP/m.o" && nm -u "$SP/m.o"
```

Read the result as a verdict:

| What comes back | Meaning |
|---|---|
| libc only, plus `ukos_test_dprintf` | free — no new fake |
| one or two `<lib>_<verb>` symbols | cheap, the normal case |
| `kern_*`, `serial_*`, peripheral symbols | **poor fit** — see below |
| `SW_VERSION` and friends undeclared | needs build-time macros, not a fake |

**A module that links cleanly may contain nothing at all.** Most managers are
wrapped in `#ifdef CONFIG_MAN_<NAME>_S`, and without that define the whole file
compiles away - no code, no descriptor, and so nothing left undefined. Confirm
there is something to test before celebrating:

```sh
size "$SP/m.o"                       # a text size of 0 means the body vanished
nm "$SP/m.o" | grep _Specifications  # no descriptor means the same
```

`microPython` looks free by the probe and is entirely compiled out; it is
excluded for that reason, not because of its dependencies.

`__stack_chk_fail` and `__stack_chk_guard` are noise: macOS enables the stack
protector for functions holding arrays, and libSystem resolves both at link.
Ignore them when counting.

Run the probe across several modules at once and it ranks the candidates for
you — that is how `kill` turned out to need nothing but the `system_getModuleName`
double that `man` already installed.

A module dominated by `kern_*` and `serial_*` is not a good candidate. `echo`
needs nine such symbols, and its whole purpose is to loop data through real
serial hardware — faking all of it would only assert against the fakes. That
one belongs to `ukos-board` on a real target. The split is deliberate: this
harness covers logic, hardware verification covers hardware.

### 2. Derive the matrix from the dispatch, not from the happy path

Read `prgm()` and write one row per branch *before* writing any code. The
recurring shape of a uKOS-X CLI tool gives most of the matrix for free:

| Source of a row | Rows to write |
|---|---|
| Each `argc` arm | one nominal case each |
| The `default:` arm | **every** count that reaches it, including 0 and a surplus argument |
| Each value of the error enum | one case that provokes it, asserting the exact wording |
| Each external call | one case where it returns an error status |
| Each parsed number | valid, both boundaries, out of range, non numeric, trailing garbage, negative, empty |
| Each flag | exact, prefix, superstring, wrong case, and with a trailing remainder |
| Each distinct output shape | one golden case asserting the **exact** string |
| The `MODULE()` descriptor | id, flags, revision, application string, help prefix |

Two rows are worth adding by habit, because they have caught real defects:

- **the module's own metadata**, which pins the id and the revision;
- **a poisoned stack** (`ukos_t_poisonStack()`) before a call whose status the
  module might ignore — that is how `date` printing an unwritten `unixTime` was
  found.

### 3. Expect these five, they recur in every module

Earned from `date`, `list`, `man`, `rnd` and `uKOS`:

1. **`text_checkAsciiBuffer` stops at the first space** of its *first*
   argument. So `-rtc extra` matches `-rtc`, while `-rt` and `-rtcx` do not.
   Every flag comparison in the tree inherits this; test all four forms.
2. **`argc` rarely validates.** Most tools treat any unexpected count as their
   default arm, so `list P junk`, `man date junk`, `rnd -hard 8 junk` and
   `uKOS -history junk` all silently do something else rather than complain.
3. **`strtoul`'s end pointer is written and never read.** `"4abc"` parses as 4
   and `""` as 0 unless the module checks — `date` now does, `rnd` does not.
4. **Return statuses get discarded.** Check what the module does when a
   manager fails, not only when it succeeds.
5. **Flag semantics differ between tools.** `list` hides `BCONFIDENTIAL`;
   `man` requires `BSHOW`. Never assume one implies the other.

### 4. Write the fake to match production, and say how it is kept honest

A double must reproduce the real contract, or the tests assert fiction. Two
cases, and the difference matters:

- **The original is pure** — copy it verbatim and add a drift check to
  `run-tests.sh`, as `text_checkAsciiBuffer` has.
- **The original is wrapped in privilege macros or reaches a linker symbol** —
  it cannot be copied, so mirror the algorithm, name the source file in a
  comment, and pin the contract with a test. `system_getModuleFamily` is
  mirrored that way and guarded by `list_fake_directory_contract`.

Give every fake a call counter, the last arguments received, a settable return
status, and a `writeOut` flag so the "manager failed and wrote nothing" path
can be exercised.

### 5. Keep it deterministic

Anything a module reads from the environment has to be pinned, or the suite
passes on your machine and fails elsewhere:

- **timezone** — `ukos_t_begin("UTC0")`, always POSIX strings such as
  `CET-1CEST,M3.5.0,M10.5.0/3`, never zoneinfo names; `ctest` injects a hostile
  `TZ` so a test that forgets is caught.
- **the clock** — the shim redirects `time()`; drive the module from the fake.
- **the firmware revision** — `CMakeLists.txt` generates a fixed `version.h`.
- **build identity** — pass `BOARD`/`VARIANT`/`SOC`/`CORE` through `DEFINES`.

Assert **exact** output strings rather than parsed fields. The column spacing
is part of the contract, and it is what a careless edit breaks first: `date`
puts four spaces after `UTC time:` and two after `Local time:`, and `list`
formats its index with `%3d`.

### 6. Wire it up

```cmake
ukos_add_cli_module_test(
    NAME          ukos_tests_<module>
    MODULE_SOURCE ${UKOS_ROOT}/OS/CLI/<module>/<module>.c
    TEST_SOURCE   cli/test_<module>.c)
```

Tests self-register through `TEST(...)`, so there is no list to update. If the
module has a compile-time variant, pass `DEFINES` and it becomes a second
executable, as `date` does for `KCALENDAR_WITH_HW_RTC_S`; the shared test source
is then compiled into both and every unaffected case runs twice for free.

### 7. Mutation check before believing a green run

**A first-time green run is not evidence.** All five suites here passed
immediately, and only mutation testing showed which behaviours were actually
guarded. Break the module on purpose and confirm the suite notices:

```sh
mutate () {                      # $1 = sed expression, $2 = label
    sed -i '' "$1" OS/CLI/<module>/<module>.c
    if git diff --quiet OS/CLI/<module>/<module>.c; then
        echo "  !! $2: MUTATION DID NOT APPLY"
    else
        printf "  %-40s %s\n" "$2" \
          "$(Tools/Developer/bin/run-tests -k -t <module>_ 2>&1 | grep -oE '[0-9]+ failed')"
    fi
    git checkout -q OS/CLI/<module>/<module>.c
}
```

Three rules, each learned the hard way:

- **Verify the mutation applied WHERE you meant.** `git diff --quiet` proves that
  something changed, not that the intended thing did. An anchor that is a
  substring of a more deeply indented copy of the same statement - which the
  selective and broadcast arms of `kern_signalSignal()` are - silently mutates
  the wrong branch, and the run then reports a survivor for code that is
  actually covered. Read the diff, not just its exit code.
- **Verify the mutation applied.** A `sed` whose pattern does not match changes
  nothing and looks exactly like a passing test. The `rnd` clamp mutation did
  this and appeared to reveal a coverage hole that did not exist — hence the
  `git diff --quiet` guard above.
- **Not every survivor is a gap.** `nbRandomNumber >= 1U` → `>= 2U` cannot be
  killed: for the only input that distinguishes them the ternary yields 1 either
  way. Decide whether a survivor is an *equivalent mutant* before writing a test
  that cannot fail.
- **A mutation can be caught by crashing.** Removing a null check on a function
  pointer takes the whole executable down, so no summary line is printed and a
  grep for "N failed" finds nothing. Judge by the exit code, and re-run with
  `-i` to turn the crash into named failing tests.
- **A mutation can also be caught by hanging.** Removing `oMark = true` from
  `dumplog` does not fail the suite, it loops forever - marking is the only
  thing that terminates its scan. A batch of mutations will simply stall. Run a
  suspect mutation as a single test under a hard timeout:

```sh
( "$BUILD"/ukos_tests_port_dumplog --only <test> & echo $! > /tmp/m.pid )
sleep 8
kill -0 $(cat /tmp/m.pid) 2>/dev/null && echo "INFINITE LOOP" && kill -9 $(cat /tmp/m.pid)
```

- **Sanitizers are load-bearing here, not a nicety.** `run-tests -s` is what
  turns a module's out-of-bounds read into evidence. `dumptrace.c:133` was
  confirmed that way - `heap-buffer-overflow ... READ of size 8` - rather than
  by reading the comparison and reasoning about it. The corollary is that a
  suite must not routinely provoke a module's own overflow, or `-s` stops being
  usable: keep such a path out of the tests and record it in `DEFECTS.md`.
- **Aim for two independent guards** on each behaviour that matters. `man`
  initially caught every mutation with exactly one test, which a single deletion
  would have silently removed; a mixed-directory golden case fixed that.

### 8. Decide what to tag

A defect you are **not** fixing in the same change gets `KNOWN_BUG`; a
deliberate oddity worth pinning gets `QUIRK`; anything else is a plain
`EXPECT_*` with a comment explaining why the behaviour is intended. Do not tag
something merely because it is surprising — `list` omitting the Applications
family looks wrong until you know downloadable applications are not in the
built-in directory at all.

Remember the polarity: a tagged defect that is later **fixed** turns the run
red, on purpose, so whoever repaired it must come back and update the
expectation.

## Note on the compiler

The uKOS-X shell environment puts the embedded cross toolchain first in `PATH`,
so a bare `clang` is the **ARM cross compiler**. `cmake/HostCompiler.cmake`
resolves the host compiler through `xcrun` before `project()`; a pre-set `CC` is
honoured.
