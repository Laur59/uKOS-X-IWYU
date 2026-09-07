# On-target console tests

Runs a table of console commands against a **flashed board** and asserts what
comes back. The host suite next door proves a CLI module's logic with no
hardware; this proves that the firmware on a real board still behaves — a
different question, with different limits.

```sh
ukos-serial start --port /dev/cu.usbmodem21403      # once, by hand
Tools/Developer/bin/run-board-tests                 # picks the table by board name
Tools/Developer/bin/run-board-tests -n              # dry run: send nothing
Tools/Developer/bin/run-board-tests -t date         # only ids containing "date"
Tools/Developer/bin/run-board-tests --allow-unsafe --have loopback
```

Exit codes match `ukos-serial`: `0` all passed, `1` error, `2` the board went
unreachable mid-run, `3` at least one assertion failed.

The runner **never opens the port and never starts a session** — re-opening the
device toggles DTR, which resets some targets. It also refuses to run if the
table's `board` disagrees with the board that answered, so an H743 table cannot
half-pass on a Pico2 and leave you reading the failures as firmware bugs.

## The table is data

One JSON file per board under `tables/`, so another board is a new file rather
than new code. JSON rather than YAML because `ukos-serial` has exactly one
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
| `requires` | skip predicates, below |
| `note` | why the row exists; printed when it fails |

Predicates, all resolved by the runner:

| Predicate | Satisfied when |
|---|---|
| `module:<name>` | the name appears in the `list` output captured once at start-up |
| `hw:<tag>` | the operator passed `--have <tag>` |
| `unsafe` | the operator passed `--allow-unsafe` |

Anything unavailable is a **printed SKIP with its reason** — never a silent pass
and never a failure. A row for hardware you do not have still belongs in the
table: its absence from a green run is then visible rather than forgotten.

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
- **Anything about the other twelve boards.** One board, one variant, one C
  library, one privilege mode.
- **That the behaviour is correct.** The table pins *current* behaviour,
  including the defects in `../DEFECTS.md` — `object/long-form-mutx-refused` is
  a row that asserts a bug. Green means "the firmware still does what it did",
  not "the firmware is right".

## Rows that change the board

Some rows are not read-only, and the table says so in their `note`:

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

The table carries no non-terminating row. `test_malloc`, `test_mcore` and
`test_sdcard` stream forever and can only be stopped with `kill`, which is
itself on the unsafe list — and **none of the three is built into
`Nucleo_H743/Variant_Test`**, so the mechanism for them would ship untested.
When a board that has them is added, the row shape is `nonterminating` plus a
`stop` command, driven as: `send --no-expect`, then `expect <pattern>`, then the
stop command, then a bare `send ""` to re-synchronise on the prompt. This is the
one place `ukos-serial`'s `expect` subcommand is the right tool, because a
streaming command keeps producing output after the mark.

`raw` must never be used to send a command: it bypasses the unsafe list
entirely.
