# On-target console tests

Runs console commands against a **flashed board** and asserts what comes back.
The host suite next door proves a CLI module's logic with no hardware; this
proves that the firmware on a real board still behaves — a different question,
with different limits. Nothing here depends on the host suite; it only lives
next to it.

Two entry points share one library (`ukos_board.py`) and the same specs:

- **`board-regression`** — the one to run after flashing a kernel change. It
  owns the session, checks the firmware is HEAD, survives crashes and gives a
  verdict. See *Regression runs* below.
- **`run-board-tests`** — the bare runner: an existing session, no recovery,
  every row printed. For writing and debugging specs.

Three more tools sit beside them: **`coredump-test`** (see *The core dump test*),
**`board-matrix`** (see *Every configuration*) and **`app-regression`**, which
runs the downloadable applications (see *The applications*). The last two are
the ones that flash.

```sh
ukos-serial start --port /dev/cu.usbmodem21403      # once, by hand
Tools/Developer/bin/run-board-tests                 # the per-CLI specs, for the board that answers
Tools/Developer/bin/run-board-tests -n --variant Ports/Targets/Discovery_N657/Variant_Test
Tools/Developer/bin/run-board-tests --expect-sha "$(git rev-parse --short HEAD)"
Tools/Developer/bin/run-board-tests -t date         # only ids containing "date"
Tools/Developer/bin/run-board-tests --allow-unsafe --have loopback
```

Exit codes match `ukos-serial`: `0` all passed, `1` error, `2` the board went
unreachable mid-run, `3` at least one assertion failed.

The runner **never opens the port and never starts a session** — re-opening the
device toggles DTR, which resets some targets. It also refuses to run if the
variant disagrees with the board that answered, so an H743 test set cannot
half-pass on a Pico2 and leave you reading the failures as firmware bugs.

## Regression runs

```sh
Tools/Developer/bin/board-regression --board Nucleo_H753      # or --port /dev/cu.usbmodemXXXX
Tools/Developer/bin/board-regression --board Discovery_N657 --expect-libc llvmlibc --allow-unsafe
```

Flash the board yourself first; the tool never flashes. Then, for one board:

1. **Board.** `--port`, or `--board NAME`, which asks `uKOS` on every ST-Link
   console and on the consoles `KJLINK` names for that board; with neither, the
   only ST-Link console that answers. Another board without an ST-Link (K210
   behind a UART bridge, Firefly_H743 on its own USB CDC port) needs `--port`,
   and so does `Firefly_H757`, whose two cores answer on two consoles;
   adding `--board` then checks the answer. A `ukos-serial` session already
   holding the port is reused and left running; otherwise one is started at
   the console's baud rate and stopped on exit. That rate comes from the
   variants' `stub_startUp.c` (switch position 0): the board's own with
   `--board`, otherwise each rate any variant declares, most common first,
   since a wrong rate captures nothing (the K210 runs at 115200, every other
   board at 460800). `--baud` overrides.
2. **Firmware.** Its `VCS#` must be HEAD, or the tool refuses: a stale image
   would otherwise pass. The refusal says how far behind the image is and
   whether `OS/`, `Ports/` or `Applications/` changed since, which is what
   decides whether `--any-firmware` is reasonable. `--expect-libc` refuses the
   wrong C library the same way.
3. **Health.** `ukos-serial verify` (processes, log, C library) runs before
   and after the specs, as `health/*` and `health-after/*` rows.
4. **Specs.** Every row of `cli/*.json` for the CLIs the variant compiles.
5. **Crashes.** A row whose prompt never comes back is a **CRASH** when the
   core dump banner is in the capture, and a **HANG** when the console is
   silent; a slow command whose console still answers is an ordinary FAIL. The
   dump is summarised (exception, `MMFAR`, `PC`) and the PC named through
   `llvm-symbolizer` — only when the variant's `build/version.h` says the local
   `FLASH.elf` is the firmware on the board, since another build's ELF would
   name a plausible, wrong function. Then the board is reset over SWD and the
   run continues. `--no-reset` stops instead and marks the rest NOT RUN.
6. **Verdict.** `PASS`, `REGRESSION` or `BOARD LOST`; exit `0`, `3` or `2`
   (`1` for a refusal).

A board that fails the first health check is refused (`--allow-dirty`
overrides). Besides `verify`, that check reads `mutex`: between commands no
serial manager may be reserved, and a held one blocks every other writer.
The one exception is on a multi-core image (K210): the idle console of
another core holds its own receiver (`Reserve_urt0_R`, `Console_urt0`) while
it waits for a line, which is expected.
That rule came from a run that started on a board left poisoned by the run
before it: the `cycle` rows failed, then a MicroPython session blocked the
console, and the rest of the run was lost.

A reset counts only when a **new boot banner** reaches the log. A console
that answers proves nothing: a running N657 refuses SWD, so the reset does
nothing, and the console answers because it never went down. A run once
reported such a non-reset as "console back" and left the board poisoned for
the next run.

### Resetting exactly one board

The USB serial number of an ST-Link's virtual COM port *is* the probe's serial
number — the `sn=` that `STM32_Programmer_CLI` takes. So the tool resets the
board behind the console it is talking to and nothing else. The `Burn/`
scripts and `coredump-test` find a probe by connecting under reset to each in
turn, which reboots every board they try. The reset mode is per board
(`KRESET` in `ukos_board.py`): `mode=UR` by default, `mode=HOTPLUG ap=1` on the
N657, where the programmer reports "Unable to run MCU" and the board reboots
anyway — so success is judged only by the console answering again. **The N657
can be reached over SWD only while it is faulted** ("Cannot connect to access
port 1" while it runs normally), so it recovers from a CRASH but a HANG ends as
BOARD LOST. To get a fresh N657 boot without touching the board, fault it
first (`dump F0000000 F0000010` raises a BusFault) and then reset it. Boards
without an ST-Link console (Firefly_H743, K210, Pico2) run, but a crash ends
them; `Firefly_H757` recovers through its J-Link.

### Boards behind a J-Link

`KJLINK` in `ukos_board.py` lists the boards reached through a SEGGER J-Link,
per variant: the J-Link device and the USB product name of the console. On
`Asmodee_H747` the CM4 console is pinned to `cu.usbserial-uKOS_3`, because the
four FT4232 channels share a product name, and the CM7 dumps come out on USART6,
`cu.usbserial-uKOS_2`, which no console holds (`dump_port`). `Firefly_H757`,
measured on the board:

| | |
|---|---|
| CM7 console | cdc0, `cu.usbmodem*` with product `uKOS-X Firefly_H757` |
| CM4 console | urt0, the CH340 bridge (product `USB Serial`) |
| Reset | `SYSRESETREQ` only, since the probe's nRESET reaches nothing; from either core it restarts both |
| Attach, core in WFI | refused (0 of 8 on each core), under reset as well |
| Attach, core running `bench` | accepted (8 of 8 on the CM7, 4 of 4 on the CM4), but only by the core that runs it |
| Attach, core faulted | accepted, because it spins |
| Storage | SD card slot, an on-board **sdnand** chip (SDMMC, `CONFIG_MAN_SDNAND_S`, CM7 only) and the `flash` drive |

So `jlink_run()` first tries without any load, which is all a crashed board
needs, then starts `bench` on the console and attaches at once, since later
phases of `bench` leave gaps. **A board hung with its core in WFI cannot be
reached**: that ends as BOARD LOST, and it takes a person with the BOOT0 button
or the power switch. The J-Link is not identified by board, so keep one attached.

A reset takes the USB device away with it, so `ukos-serial` waits for a CDC node
to return and opens it again, in the same session, and the banner still reaches
its log. A core dump does not reach cdc0 at all: it goes out through
`cmns_send()` on USART1, which is the wire of the CM4's console. On the CM7
`board-regression` therefore reports a crash as a **HANG**, and recovers it the
same way. `coredump-test --dump-name` reads the dump from the other session.

No CLI exercises the sdnand or the FatFs volumes, so no spec row covers them:
the only on-target check is the downloadable `p_Specials/test_fatfs`, which
`app-regression` runs (see *The applications*). Its drives are chosen at compile time by the board's `_S`
macro, not detected at run time: `/sdcard` and `/flash` on `Alastor_H743` and
`Firefly_H743`, `/sdcard`, `/sdnand` and `/flash` on `Firefly_H757`. A drive a
board selects but does not have stops the run at `f_mkfs erreur`, where the app
spins.

It **formats every drive it tests**, the SD card in the slot included, so run
it only with a card whose contents you do not need (the same rule as `--have
sdcard-scratch`). Each drive gets three folders and one file in each; a pass
prints `f_mkfs passed` once per drive, every `f_* passed` line nine times on the
H757 and no `erreur`, reads back the nine quotes `F1:` to `F9:`, and ends with
`3 dirs, 0 files.` for each root and a tree of three folders and three
`TEST_<n>.TXT` per drive. File dates read `29-02-2024` because the RTC is not
set after a reset; that is not a failure. On `Firefly_H757` the full run passes
on all three drives (`91b6dd839`, the tree of `c77e112f1`, `llvm` + `newlib`,
2026-11-09). The two H743 boards have not been run since the 6.15.0 change.

### Known failures

`KNOWN-FAILURES` lists rows that fail today, and how - one line each:

```
<Board>[/<Variant>]  <row id>  <fail|crash|hang>  <reference>
```

`<Board>/<Variant>` limits a line to one variant, for a row that fails on one
core of a dual-core board and passes on the other: `bench/all` runs out of heap
on `Asmodee_H747/Variant_Test_CM4` only. The other entry today is
`Alastor_H743 X/sensor-range`; `Discovery_N657 test_ram/one-pass crash` went
when `test_ram` was fixed.

A result matching its line is reported **known** and does not fail the run. A
different failure of a listed row is a regression, and a listed row that now
**passes** fails the run too: the line must go, because a stale entry would
hide the next regression of that row. This is the same contract as the host
suite's `EXPECTED-FAILURES`.

### Verified on

Both boards attached at once. `Nucleo_H743` (`f7e612159-dirty`, llvmlibc):
refused without `--any-firmware`, then 36 pass, 2 skip, PASS. `Discovery_N657`
(`ed172ba1f`, llvmlibc): `test_ram` CRASH named as `inline_memset_arm_mid_end`,
reset in 2 s, the remaining CLIs run, 1 known, PASS — while a session held on
the H743 recorded no reboot through five N657 resets. Negative controls, each
by exit code: an empty known list (`3`), a known entry for a passing row (`3`),
a known entry of the wrong kind (`3`), a wrong `--expect-libc` (`1`),
`--no-reset` (`3`, the rest NOT RUN, the board left dead).

## Per-CLI specs

One JSON file per CLI module under `cli/`, named after the command
(`cli/uKOS.json`), and the list of CLIs to run comes from the build rather than
from a hand-maintained per-board table (the runner's original form, whose
`Nucleo_H743` rows are now spread over `cli/`):

1. **Which variant.** `--variant <dir>`, or else
   `Ports/Targets/<Board>/<Variant>/` as the board names them in its `uKOS`
   answer. With `--variant`, a board that reports another Board or Variant is a
   refusal (exit `1`).
2. **Which CLIs.** Every `${PATH_OSYS}/CLI/<name>/<name>.c` in that variant's
   `CMakeLists.txt` — the backreference leaves `bench/bench_00.c` and friends
   out. No variant adds a CLI inside an `if()`, which is what makes a regex
   exact here.
3. **Inventory check.** Each of those CLIs must appear in the board's `list`
   (family `X`). One that does not is a failure `inventory/<cli>`: the image on
   the board was not built from this tree, or the module is not registered. A
   CLI the board has but the variant does not declare is only a warning.
4. **Coverage.** A CLI with no spec file is listed under `cover` — visible, not
   a failure. Every CLI of `Discovery_N657` has a spec (31/31); so does every CLI of `Nucleo_H743` (28/28).
5. **Rows.** Each spec's rows run in file order, specs in alphabetical order,
   except for two kinds that are moved: `terminal` rows run after all ordinary
   ones, and `poisons` rows last of all. `module:<cli>` is implied in
   `requires`.

```json
{ "module": "uKOS", "note": "...", "tests": [ { "id": "uKOS/identity", "cmd": "uKOS", "expect": ["^SoC:     ${SOC}$"] } ] }
```

`module` must equal the file name. The row fields are described below.

### Placeholders

`cmd`, `expect`, `refute` and the steps' fields may use:

| Placeholder | Value |
|---|---|
| `${BOARD}`, `${VARIANT}` | the variant directory's parent and own name |
| `${SOC}` | the variant's `set(SOC …)`, or the SoC the board reports when it builds on that one or on the same base (`soc_base()`: `SOCs/<SoC>/soc_base.cmake`, else the `STM32H7x<n>` family directory, as in `Ports/cmake/soc-base.cmake`) |
| `${CORE}` | its `set(CORE …)`; on `Pico2_rp2350`, which declares two, the one the board reports — which must be one of them |
| `${CONSOLE}` | the serial manager of the console running the tests - the one `process` shows `Running`; offline, the variant's `KDEF_COMM` |
| `${sym:NAME}`, `${sym:NAME+HEX}` | the address of symbol `NAME` in the variant's `Artefacts/FLASH.elf`, plus an optional hex offset, as bare uppercase hex (what `dump` and `fill` take). Only when that ELF is the build on the board (`build/version.h` equals the board's `VCS#`): an address from another build is plausible and wrong, and `fill` writes to it. Otherwise the rows that use it **skip with the reason**; the rest of the spec runs |
| `${VCS}` | the SHA given with `--expect-sha`, else the shape `[0-9a-f]{7,}(-dirty)?` |

Values are `re.escape`d inside patterns. An unknown placeholder is an error
(exit `1`), so a typo cannot silently match nothing. This is what lets one spec
assert the exact identity of every board — a value that is fixed *per variant*
is not a moving value, and pinning it is not the mistake warned about below.
Offline (`-n`, `-l`) the placeholders still need a variant, and Pico2 cannot be
resolved without a board.

### Verified on

`Discovery_N657/Variant_Test`, `llvm` + `llvmlibc`, firmware `ed172ba1f`: 31/31
CLIs registered, every row passes or skips for a stated reason; `test_ram/one-pass`
crashed the board until `test_ram` was fixed (see `../DEFECTS.md`). `Nucleo_H743/Variant_Test`, `llvmlibc`, firmware `f7e612159-dirty`: 28/28 CLIs
registered, 30 rows pass (`test_ram` included), `echo` and `wki2c` skip for
missing hardware. The same board, `llvm` + `llvmlibc`, firmware `c11a60b88`: 28/28 CLIs
with a spec, 92 rows pass and 17 skip (unsafe rows and absent hardware),
the four `X` rows included.

For `cli/uKOS.json`, every negative control fails
with the right exit code — another variant (`1`), a wrong `--expect-sha` (`3`,
identity and history), a wrong SoC literal in a scratch `--specs` copy (`3`), a
misspelt placeholder (`1`), a CLI added to a scratch copy of the variant (`3`,
`inventory/test_sdcard`), and a `(?s)` refute that must span two lines (`3`,
proving the inline flag reaches `ukos-serial` intact).

`uKOS/extra-argument-shows-target` is the kind of row only this tier can
write: the console splits `uKOS -history extra` into three tokens, `argc == 3`
falls into `default:`, and the target is printed with the extra arguments
ignored. The host test passes `"-history extra"` as a single token and never
sees it.

## The specs are data

Another CLI is a new file rather than new code, and another board needs none. JSON rather than YAML because `ukos-serial` has exactly one
dependency — pyserial — and adding PyYAML to run the *tests* of the tool is a
worse trade than losing comments. The per-row `note` replaces them, and is
better than a comment because it is **printed on failure**.

| Field | Meaning |
|---|---|
| `id` | unique, and what `-t` filters on |
| `cmd` | the console command |
| `expect` | regexes that must all match |
| `refute` | regexes that must none match |
| `timeout` | seconds |
| `unsafe` | passes `ukos-serial --unsafe` for this row |
| `requires` | skip predicates, below; besides `module:`, `hw:` and `unsafe`, `"sym:NAME"` runs the row only where the flashed build's symbol `NAME` is non-zero and `"!sym:NAME"` only where it is zero or absent (`test_ram` keys on `linker_lnEXRAM`, the size of the external RAM) |
| `poisons` | what the row leaves behind until the next reset; see below |
| `prompt` | `false`: the command does not come back to the prompt by itself (it reads input); it is only written, and the steps do the rest |
| `then` | steps after the command, in order - `{"send": ..., "expect", "refute", "timeout"}` writes more input and reads to the console prompt; with `"keep": {name: re}` it also remembers what the group of `re` matched in that answer and with `"same": {name: re}` it demands that same value again, which is how a figure that differs between boards and builds is compared with itself (`viewer` checks that the heap is the same after a second run); `{"write": ...}` writes it and returns at once (input for a sub-prompt such as MicroPython's `>>> `); `{"await": re, "timeout"}` waits for output; `{"absent": re, "timeout"}` fails if matching output arrives, from the previous step on, within the timeout |
| `stop_on_fail` | `true`: the first failed assertion ends the row - for a guard (`runDemo` checks that no demo is installed before calling it) |
| `terminal` | the row ends the console on purpose (`gdb` freezes the kernel); see below |
| `note` | why the row exists; printed when it fails |

An `await` searches the session log from the start of the row, not from when
the step begins, so output that arrived early is not missed; `(?s)` lets it
span lines. A failed assertion in a step does not stop the later steps - they
are usually the cleanup (`cycle -stop`) - but an `await` that times out does.

### Rows that end the console

`gdb` freezes the kernel for a debugger, so nothing answers afterwards.
Such a row is marked `"terminal": "<why>"`. `run-board-tests`, which never
resets anything, always skips it. `board-regression` runs it only with
`--allow-terminal`, after the ordinary rows and the final health check,
and resets the board through its probe after each one. They run **before**
the poisoning rows. That order was learnt the hard way: after the `echo` leak,
`gdb`'s own process blocked on its first print and never froze.

### Rows that poison the board

Some commands leave the board changed until the next reset, and every row
after them tests a different board than the one that was flashed. Each is
marked `"poisons": "<what it leaves>"`, skipped unless `--allow-poison` is
passed, and, when run, **runs after all the others**. `board-regression` then
ends with a reminder to reset.

**No row poisons today.** Six did, each because of a defect that has since
been fixed (`../DEFECTS.md`, "Fixed in this branch"): `viewer/...` left a
semaphore that made the next viewer panic, `bench/all` left the console
privileged, `echo/unknown-input-manager` left its output reservation
held, `hexloader/...` left the user memory reserved, and
`console/already-active` and `cycle/in-use-then-stop` leaked a process stack.
The mechanism stays for the next one.

`restart/reboots` (unsafe) clears all of this - a reboot - but it sorts before
the poisoning rows, so it cannot undo them in the same run; on a board that
SWD cannot reset (the N657 while it runs), `restart` from the console is the
way back to a fresh boot.

Each was found because a row *after* it failed for no reason of its own: the
H743 `bench` ran out of heap after the leaks, the N657 `test_ram` stopped
crashing after `bench`, `cycle` hung after `echo` (both are fixed since, and
their rows no longer poison). When a row fails only in a
full run, run it alone on a fresh boot before suspecting it.

Predicates, all resolved by the runner:

| Predicate | Satisfied when |
|---|---|
| `module:<name>` | the name appears in the `list` output captured once at start-up |
| `hw:<tag>` | the operator passed `--have <tag>` |

`--have <tag>=<command>` also says how to get the hardware ready: the command
is run by the shell just before every row that requires `hw:<tag>`, and a row
whose command fails is skipped with its last line as the reason, like a row
whose hardware is absent. This is for hardware a reset takes away. The one
case today is `hw:video-host`, a host streaming from the board: after
`restart/reboots` the camera application falls back on another camera and
does not come back by itself. `select-video-source` picks the board again in
Quick Camera (macOS, through System Events, so the terminal needs the
Accessibility permission; it never starts the application):

```bash
Tools/Developer/bin/board-regression --board Discovery_U5G9 --allow-unsafe \
    --have video-host=Tools/Developer/bin/select-video-source
```
| `unsafe` | the operator passed `--allow-unsafe` |

Anything unavailable is a **printed SKIP with its reason** — never a silent pass
and never a failure. A row for hardware you do not have still belongs in the
spec: its absence from a green run is then visible rather than forgotten.

## Assert shape, never a value

Timestamps, addresses, uptimes, the `VCS#`, section sizes and the module count
all move between builds. A row pinning one of them is a test that fails on the
next commit and gets deleted rather than fixed. Write

```json
"expect": ["^VCS#:    [0-9a-f]{7,}(-dirty)?$"]
```

not the SHA itself.

Patterns are Python regexes matched **multiline** — so `^` and `$` anchor to
lines — but **not** DOTALL, so `.` never crosses a line. Line endings are
normalised before matching, so write `$` and not `\r?$`. The trailing prompt is
stripped before matching, so a pattern cannot accidentally match it.

## What this tier cannot prove

- **Any branch it cannot reach.** Roughly half the error strings in these
  modules need a manager to fail; `dumplog`'s "Not enough memory." needs heap
  exhaustion. Those belong to the host suite.
- **A module's exit status.** `OS/CLI/console/console.c:277-280` collapses
  `EXIT_OS_SUCCESS_CLI` and `EXIT_OS_FAILURE` into the same `break;`, so only
  printed text is observable. Every assertion here is necessarily about text.
- **Anything about a board it has not run on.** Each run is one board, one
  variant, one C library, one privilege mode.
- **That the behaviour is correct.** The specs pin *current* behaviour,
  including the defects in `../DEFECTS.md` — `object/long-form-mutx-refused` is
  a row that asserts a bug. Green means "the firmware still does what it did",
  not "the firmware is right".

## Rows that change the board

Some rows are not read-only, and the spec says so in their `note`:

- `date/leap-day-accepted` sets the clock, so `date/read` no longer reflects
  real time afterwards.
- `run/nothing-downloaded` assumes nothing has been loaded; a preceding
  `hexloader`/`sloader` row would invalidate it.

Order matters for those. Keep read-only rows first.

## Every configuration

`Tools/Developer/bin/board-matrix` builds, flashes and tests one board in every
compiler / C library / mode combination, then flashes the default build back:

```sh
board-matrix --board Nucleo_H753 -n                          # list the 20 configurations
board-matrix --board Nucleo_H753                             # all of them
board-matrix --board Nucleo_H753 --compilers gcc --modes default,UY --tests coredump
```

Per configuration: build from HEAD in the variant's own `build/` and `Artefacts/`
(the logs go to a scratch directory, `--logs` to choose it), flash through the
probe behind the board's
console port (never a probe found by connecting under reset, which reboots the
other boards), wait for the boot banner, `ukos-serial verify` plus the compiler
the board reports, then `board-regression` and `coredump-test`. A board
coredump-test has no faulting address for reports `n/a`. LLVM libc is built with
Clang only, so the full set is 20, not 24.

It must build in the variant directory: `board-regression` takes the addresses
of its `sym:` rows (`dump`, `fill`, `test_ram`, `X`) from `Artefacts/FLASH.elf`
and accepts that file only when its `build/version.h` names the revision the
board runs. An image built elsewhere leaves a stale one there, and those rows are
skipped. The check compares the revision only, so an image of the same commit
built with another compiler or C library would pass it with wrong addresses -
another reason the image there has to be the flashed one.

`KFLASH` lists the boards that need no physical action, by method: `stlink`, or
`jlink` for `Firefly_H757` and `Asmodee_H747`. A J-Link board may have one variant per core: each
configuration builds them all, writes them in one connection, so the board
resets once, and runs both tools on each console, about 4 minutes per
configuration. Its consoles must answer before the first flash, as the board is
found by them. A board that needs a physical action before it can be flashed -
Pico2_rp2350 (BOOTSEL), Firefly_H743 (DFU), the N657 boards (a jumper) - needs a
flashing method of its own there.

## The core dump test

`Tools/Developer/bin/coredump-test` is a separate script rather than a row in
the table, because it **kills the console**: it provokes a real fault, and every
path that prints a core dump is terminal. The dump ends in `cb_signal()`, which
is `[[noreturn]]` and blinks an LED forever, and every `crt0_exit()` panic ends
with `INTERRUPTION_OFF` and never re-enables. Nothing answers afterwards, so the
script resets the board over SWD and waits for it to come back.

```bash
ukos-serial --name u5g9 start --port /dev/cu.usbmodem21103
coredump-test --name u5g9 -n                     # say what it would do, send nothing
coredump-test --name u5g9 --sn <ST-Link serial>  # the real thing
```

Note the option order: `--name` belongs to `ukos-serial` itself, before the
subcommand, not to `start`.

Pass `--sn` when more than one board is attached. Without it the script has to
identify the probe by connecting to each in turn, and connecting `mode=UR`
resets whatever is on the other end — so it would reboot the other boards.

It faults by reading `0xF0000000`, an address far outside anything any of these
memory maps claims — which is why one address serves all three boards, while
`0x30000000` would serve none of them: it is unmapped-but-readable on the U5G9
and real SRAM on the H743.

Which fault that raises is **not** fixed and is never asserted. Three different
answers have been seen for the identical access: `BusFault / PRECISERR` on
`Discovery_U5G9` at `35f7ba715`, `MemManage / DACCVIOL` on the same board at
`92f41db34` (an MPU region claims the address first), and `HardFault` with
`CFSR = DACCVIOL` and `HFSR = FORCED` on `Nucleo_H743` and `Nucleo_L4R5`, where
it escalates. All are real faults reaching the same handler, which is all the
test needs.

**The `send` exit code is not the fault signal**, and neither is the console
going quiet. `send` reads until the prompt, and the prompt printed *before* the
command can land after its mark — so the very same fault exits 2 on the U5G9 and
the L4R5 but 0 on the H743. The script asks the capture for the core dump banner
instead. If the banner is absent and the console still answers, the address
simply did not fault: it says so and exits 1 without resetting anything.

### What it proves

This is the only on-target test that reaches `record_printLog()`, and a single
dump does exercise its mark mechanism end to end. The marks are the loop's
termination condition: it selects the oldest *unmarked* record, prints it, marks
it, repeats. So strictly increasing timestamps with no repeat, followed by the
stack frame, is a real assertion about that code.

Verified by mutation. With `rOldLogBuffer->oMark = true;` commented out, the
board reprinted the same `260-us` record **3865 times** in the timeout window
and never reached the stack frame; the test failed with exit 3 on two
independent assertions. Restored, it passes again.

### What it does not prove

It does not detect the defect the marks were leaking into — `dumplog`
inheriting marks that `record_printLog()` left in the *live* buffer. That needs
a prompt after a dump, which no ARM board offers. This is not a guess: the
pre-fix firmware `35f7ba715`, which has no mark-clearing loop at all, produces a
capture that **passes every assertion here**. Only the host suite covers that
defect. See `Tools/Developer/tests/DEFECTS.md`.

```bash
ukos-serial --name f7 start --port /dev/cu.usbmodem21201          # CM7, cdc0
ukos-serial --name f4 start --port /dev/cu.usbserial-2140 --no-assert-dtr  # CM4
coredump-test --name f7 --dump-name f4 -v                         # the CM7's
coredump-test --name f4 -v                                        # the CM4's
```

`KBOARDS` carries `Asmodee_H747`, `Discovery_U5G9`, `Firefly_H757`,
`Nucleo_H753` and `Nucleo_L4R5`, all verified end to end including the SWD
recovery; the Asmodee_H747 and Firefly_H757 have no probe to name and reset
through their J-Link, see *Boards behind a J-Link*. Between the other three they cover two C
libraries — the L4R5 image is `llvmlibc`, the other two `newlib` — so the dump's
own `snprintf` formatting is exercised under both.

Another board needs a faulting address and its programmer device name added
there. Take both from the board's own `Ports/EquatesModels/SOCs/<SOC>/Burn/`
script rather than guessing: the L4R5 reports `STM32L4Rxxx/STM32L4Sxxx`, not the
`STM32L4xx` the pattern of the other two suggests, and the string has to match
exactly. The address must be *checked*, not assumed: confirm the console dies
and a dump appears, because a read of an unmapped region can just as easily
return zeros.

## The applications

`Tools/Developer/bin/app-regression` runs the downloadable applications that
`Applications/uKOS_Appls_Downloadable/apps.yaml` lists for one board:

```sh
app-regression --board Firefly_H757 -n                       # what would run, offline
app-regression --board Firefly_H757                          # flash, then every application
app-regression --board Firefly_H757 --no-flash --apps k_Mathematicals,p_Specials/sdcard
app-regression --board Firefly_H757 --allow-unsafe --have sdcard-scratch
app-regression --board Firefly_H757 --apps q_LVGL/big --record /tmp/rec   # write a spec
```

It flashes one configuration (`--compiler`, `--lib`, `--mode`; LLVM newlib by
default) with `board-matrix`'s own code, so it supports `board-matrix`'s boards.
Then, per application: build it against that image, **reset the board**, start
`hexloader` with the row's `args` (handed on to the application, as in
`hexloader test 3`), stream the `.hex` and check the output against
`apps/<group>/<app>.json`. A final reset leaves no application running.

Three things decide that shape:

- **A reset before every download.** Once `hexloader` has started an
  application it keeps the user memory reserved (its processes may still run
  from there, `../DEFECTS.md`), so the next download is refused with "The user
  memory is busy" until a reset.
- **Build after the flash.** An application links the variant's
  `Artefacts/FLASH.elf` and carries its signature; one built against any other
  image is refused with "failed to find the application signature!".
  `--no-flash` checks that the board runs HEAD and that `Artefacts/` holds it.
- **One hex line per write, 1 ms apart.** Faster overruns hexloader's 128-byte
  receive buffer ("Hex: buffer full error"); `gan`'s 118 486 lines take about
  three minutes.

A spec has the fields of the module docstring of `app-regression`. The ones
that matter most:

| Field | For |
|---|---|
| `expect`, `{"re", "min"}` | output that must appear within `timeout`; `min` counts matches |
| `refute` | output that must not appear |
| `input` | `write` (on the console, or `"on": "dump"` for the dump console's wire), `await`, `sleep`, and `jlink` commands run through another core |
| `dump` | a core dump or panic the application causes on purpose |
| `console: false` | the application keeps or kills the console |
| `boards`, `except` | the boards a row is for, or is not for |
| `after`, `log_allow`, `log_expect` | console commands and `dumplog` checks once the window is over |

Every application's first line follows the console prompt on the same line, so
the prompt is dropped before matching and patterns can begin with `^`. **Never
write "at least n times" as `(?s)(...){n}`**: over a long output (`pooling`
prints ten thousand lines in 15 s) it backtracks exponentially and the runner
hangs; `{"re": ..., "min": n}` counts instead.

A core dump or a panic goes out through `cmns_send()`, which on `Firefly_H757`
is the CM4's wire, so the runner watches that console as well: `canary`'s
"Stack smashing!" is matched there. A dump or panic no row expects is a
**crash**. Rows that change the board are gated as in the CLI specs:
`test_fatfs` formats every drive and `sdcard` tests 2, 4 and 5 write the card,
so they need `--allow-unsafe --have sdcard-scratch`.

The applications that keep the console are not failures: `plotSin`,
`c_Semaphores/basic`, `class_Py`, `cluster_Py`, `n_NewLibs/basic` and `rpn`
return `EXIT_OS_SUCCESS` from `main`, which kills the console process
(`OS/Includes/exit_codes.h`); `canary`, `tracing` and `watchdog` stop or restart
the system on purpose. The silent ones (`gan`, `q_LVGL/big`, `uKOS_minimal`) are
checked through `process`, which must list their processes; the picture on the
panel is not checked. `intIO` counts EXTI line 8, which nothing drives on the
H757, so its row fires the line in software through the CM4's J-Link.

Known failures go to `APP-KNOWN-FAILURES`, in the format of `KNOWN-FAILURES`
and with the same contract; it is a separate file so that `board-regression`
does not report every application row as "not exercised".

### Verified on

`Firefly_H757`, LLVM newlib, 2026-11-09: all 43 applications, 49 rows pass and
one skips (the H743 row of `test_fatfs`), including `test_fatfs`, `sdcard` and
its card-writing tests. Writing the specs found two defects in `sdcard` test 5,
fixed in `3180e677e`: its process stack was too small under newlib, so it broke
the heap ("Panic: memo_malloc descriptor broken!"), and it wrote 10 bytes for two
`float64_t`, so the second read back as 0. Negative controls, each by verdict:
an unexpected core dump (`CRASH`), a missing process in `after`, a warning not
in `log_allow` and a `refute` that matches (`FAIL`), a known failure (`known`)
and a known row that passes (exit `3`).

`Nucleo_L4R5`, LLVM newlib, 2026-11-09 (`17494026b`): all 32 applications pass,
one row skips (the H757's `intIO`). Its first run showed four rows that held on
the H757 only, which is why a second board matters: `multiKill` counted at the
H757's rate, `c_Semaphores/basic` passed only because a stray character reached
the H757's console (the row now types one), `f_Signals/calendar` expected the
2025 that `a_Basics/calendar` had left in the H757's clock (the application never
sets it), and the MicroPython script prints the board's mode switch. On the L4R5
`intIO` counts the user button, PC13; a hot-plug ST-Link attach to fire it in
software was refused ("Unable to get core ID", with `bench` running as well), so
its row checks only that the counter is printed.

`Asmodee_H747`, LLVM newlib, 2026-11-09 (`d583cd3d6`): all 43 applications, 41
rows pass and 6 skip for a stated reason. Three rows need hardware the bench
board lacks: `readIMU`'s `sensor-answers` (`--have imu`; its LSM9DS1 reads a
frozen 0, 0, -0.999912 g, as on `Alastor_H743`) and the two `o_Imagings`
applications (`--have camera`; without one they print "img0 manager
problem"). Two rows are the board's own. `c_Semaphores/basic` watches urt0,
which on this board is the FT4232 wire that also carries the CM7 dumps, not
the console, so its row types on the dump console's session. `intIO` counts
EXTI line 0 (`0x58000008`, bit 0), fired through the CM4's J-Link. Its first
attempt rebooted the board under the application: the probe's reset line is
wired here, and a refused attach to a core idling in WFI falls back to
connecting under reset. A `jlink` step therefore starts `bench` on that
core's console before its first attach.

Not yet run: the other boards of `apps.yaml`. A board needs its consoles and
probe in `board-matrix`'s `KFLASH`, and its own rows where it differs. Watch
for two kinds of over-specific row, both found above: a rate or a count that
depends on the core, and state one application leaves for the next.

## Not yet exercised

One spec carries a non-terminating row: `test_sdcard/write-read-then-kill`
starts a process that streams write/read timings until `kill test_sdcard`,
which a named process allows. Each step that sends an unsafe command needs its
own `"unsafe": true`; the row's flag covers only its `cmd`. The row
**overwrites the card from sector 0**, so it also needs `--have
sdcard-scratch`. It passes on `Firefly_H743`, privileged (`c6e0e87dd`) and
user mode (`8948e2499`), both llvmlibc, and it fails with `await` when the
pattern names a sector the test cannot reach. Two earlier runs failed to
initialise the card (`KERR_STORAGE_CANRE`) for a reason not found: see
`../DEFECTS.md`. Such a failure leaves a fatal log record, so `health-after`
fails until a reset.
While the process streams, its lines interleave with other output, even
inside a `process` listing, whose count `ukos-serial verify` then misreads.

`test_malloc N` starts ten anonymous
processes, above the console's priority, that churn the heap forever; `kill`
works on module names, so **nothing can stop them** short of a reset - and
`Discovery_N657`, the one board that builds it, cannot be reset over SWD unless
it is faulted. So `cli/test_malloc.json` covers only the paths that must start
nothing; the stress run needs either a way to stop it in the OS or an operator
at the RESET button. `test_mcore` (`Pico2_rp2350`) streams too.
The row shape is `nonterminating` plus a
`stop` command, which the `prompt: false` + `then` steps can now express:
`await` the streamed pattern, then `send` the stop command. A bare `send ""`
re-synchronises once the streaming has stopped: the console answers an empty
CR-terminated line with a new prompt. An empty LF-terminated line is still
ignored, because the console treats a leading LF as the tail of a CRLF.

`raw` must never be used to send a command: it bypasses the unsafe list
entirely.
