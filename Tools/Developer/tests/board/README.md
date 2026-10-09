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
Tools/Developer/bin/board-regression --board Nucleo_H743      # or --port /dev/cu.usbmodemXXXX
Tools/Developer/bin/board-regression --board Discovery_N657 --expect-libc llvmlibc --allow-unsafe
```

Flash the board yourself first; the tool never flashes. Then, for one board:

1. **Board.** `--port`, or `--board NAME`, which asks `uKOS` on every ST-Link
   console; with neither, the only ST-Link console that answers. A board
   behind a UART bridge (K210, Firefly) has no ST-Link, so it needs `--port`;
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
without an ST-Link console (Firefly, K210, Pico2) run, but a crash ends them.

### Known failures

`KNOWN-FAILURES` lists rows that fail today, and how - one line each:

```
<Board>  <row id>  <fail|crash|hang>  <reference>
```

It is empty today; its last entry was `Discovery_N657 test_ram/one-pass crash`,
until `test_ram` was fixed.

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
| `${SOC}` | the variant's `set(SOC …)` |
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
Tools/Developer/bin/board-regression --board <Board> --allow-unsafe \
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

`KBOARDS` carries `Discovery_U5G9`, `Nucleo_H743` and `Nucleo_L4R5`, all three
verified end to end including the SWD recovery. Between them they cover two C
libraries — the L4R5 image is `llvmlibc`, the other two `newlib` — so the dump's
own `snprintf` formatting is exercised under both.

Another board needs a faulting address and its programmer device name added
there. Take both from the board's own `Ports/EquatesModels/SOCs/<SOC>/Burn/`
script rather than guessing: the L4R5 reports `STM32L4Rxxx/STM32L4Sxxx`, not the
`STM32L4xx` the pattern of the other two suggests, and the string has to match
exactly. The address must be *checked*, not assumed: confirm the console dies
and a dump appears, because a read of an unmapped region can just as easily
return zeros.

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
