# -*- coding: utf-8 -*-
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen

"""Shared pieces of the on-target console tests.

run-board-tests and board-regression both drive a flashed board through
ukos-serial and both resolve the same per-CLI specs (cli/<module>.json) against
the variant the board reports. This module holds that common part:

- talking to ukos-serial (serial, send_json, identify, session lookup);
- resolving the specs (read_variant, resolve_core, expand, load_specs,
  prepare, skip_reason);
- recovering from a crash (probe_for_port, reset_board, parse_dump,
  symbolize) - used by board-regression only, because run-board-tests never
  touches the port or the probe.
"""

import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
import time

# realpath, not abspath: the scripts are reached through Tools/Developer/bin,
# and the shell tools resolve their own symlink the same way with ${0:A}.
KHERE   = os.path.dirname(os.path.realpath(__file__))
KROOT   = os.path.normpath(os.path.join(KHERE, "..", "..", "..", ".."))
KSERIAL = os.path.normpath(os.path.join(KHERE, "..", "..", "ukos-serial"))
KSPECS  = os.path.join(KHERE, "cli")

# What ${VCS} matches when no expected SHA pins it.
KVCS_SHAPE = "[0-9a-f]{7,}(-dirty)?"


class Refusal(Exception):
    """A setup problem: nothing was, or should be, sent to the board."""


class Unresolved(Exception):
    """A placeholder that cannot be filled here; the row is skipped."""


# ukos-serial
# ===========

def serial(args, name=None):
    """Run one ukos-serial subcommand. Returns (exit code, stdout, stderr)."""

    cmd = [sys.executable, KSERIAL]
    if name:
        cmd += ["--name", name]
    cmd += args
    done = subprocess.run(cmd, capture_output=True, text=True)
    return done.returncode, done.stdout, done.stderr


def send_json(command, name, timeout, unsafe=False, expect=None, refute=None):
    args = ["send", command, "--timeout", str(timeout), "--json"]
    if unsafe:
        args.append("--unsafe")
    for pattern in (expect or []):
        args += ["--expect", pattern]
    for pattern in (refute or []):
        args += ["--refute", pattern]

    rc, out, err = serial(args, name)
    try:
        return rc, json.loads(out)
    except ValueError:
        return rc, {"pass": False, "error": (err or out).strip()}


def rundir():
    """Where ukos-serial keeps its sessions; the same rule as ukos-serial's."""

    base = os.environ.get("XDG_RUNTIME_DIR") or tempfile.gettempdir()
    return os.path.join(base, "ukos-serial")


def session_for_port(port):
    """Name of a live ukos-serial session holding `port`, or None."""

    directory = rundir()
    if not os.path.isdir(directory):
        return None
    for entry in sorted(os.listdir(directory)):
        if not entry.endswith(".json"):
            continue
        try:
            with open(os.path.join(directory, entry)) as handle:
                meta = json.load(handle)
        except (OSError, ValueError):
            continue
        name = entry[:-5]
        if meta.get("port") == port and serial(["status"], name)[0] == 0:
            return name
    return None


def only_session():
    """Name of the single live ukos-serial session - the one ukos-serial itself
    falls back to without --name - or None when there are none or several."""

    try:
        found = [f[:-5] for f in os.listdir(rundir()) if f.endswith(".sock")]
    except OSError:
        return None
    return found[0] if len(found) == 1 else None


def log_path(name):
    return os.path.join(rundir(), name + ".log")


def log_mark(name):
    """Current end of the session log, to read what a command printed."""

    try:
        return os.path.getsize(log_path(name))
    except OSError:
        return 0


def log_since(name, mark):
    try:
        with open(log_path(name), "rb") as handle:
            handle.seek(mark)
            text = handle.read().decode("utf-8", "replace")
    except OSError:
        return ""
    # The same normalisation as ukos-serial's --expect: every line ending
    # becomes \n, so patterns write $ and never \r?$.
    return text.replace("\r\n", "\n").replace("\r", "\n")


RX_IDENT = re.compile(r"^\s*(Board|Variant|SoC|Core|VCS#)\s*:\s*(\S+)\s*$",
                      re.M)
# "Compiler: clang 22.1.6" / "Compiler: gcc-14.2.1" - the value holds a space,
# so RX_IDENT cannot carry it.
RX_COMPILER = re.compile(r"^\s*Compiler\s*:\s*(\S.*?)\s*$", re.M)
# "FLASH  36  X08_  v 1.1   date         Set / display ..." - the family is the
# letter of the identifier, the module name the first word of the application
# string.
RX_MODULE = re.compile(r"^FLASH\s+\d+\s+([A-Z])\S*\s+v\s*\S+\s+(\S+)", re.M)
# " 8  Process console urt0.   (c) EFr-2026 - Running ..." - the console that
# runs our command is by definition the one in the Running state.
RX_CONSOLE = re.compile(r"^\s*\d+\s+Process console (\w+)\..*-\s+Running\b", re.M)


def identify(name):
    """Ask the board what it is and which modules it registered.

    Returns (0, ident, modules), or (2, None, None) when it does not answer.
    """

    rc, _, err = serial(["status"], name)
    if rc != 0:
        raise Refusal("no usable session (%s)\n"
                      "start one with: ukos-serial start --port "
                      "/dev/cu.usbmodemXXXX" % err.strip())

    rc, rep = send_json("uKOS", name, 10)
    if rc == 2:
        return 2, None, None
    if rc != 0:
        raise Refusal(rep.get("error", "unknown"))
    ident = dict(RX_IDENT.findall(rep.get("text", "")))
    found = RX_COMPILER.search(rep.get("text", ""))
    if found:
        ident["Compiler"] = found.group(1)

    rc, rep = send_json("list", name, 15)
    if rc == 2:
        return 2, None, None
    modules = {}
    for family, module in RX_MODULE.findall(rep.get("text", "")):
        modules.setdefault(module, family)

    rc, rep = send_json("process", name, 15)
    if rc == 2:
        return 2, None, None
    for core, text in per_core(rep.get("text", ""), RX_PROCESS_CORE):
        found = RX_CONSOLE.search(text)
        if found:
            ident["Console"] = found.group(1)
            if core is not None:
                ident["ConsoleCore"] = core
    return 0, ident, modules


# " #  Process information of the core 1 ..." / "Mutexes used by the core 1" -
# a multi-core image (MAiXDUiNO_K210) lists every core in one answer.
RX_PROCESS_CORE = re.compile(r"^.*Process information of the core (\d+)", re.M)
RX_MUTEX_CORE   = re.compile(r"^Mutexes used by the core (\d+)", re.M)


def per_core(text, header):
    """[(core, section)] of an answer split at its per-core headers; a single
    (None, text) when it has none."""

    marks = list(header.finditer(text))
    if not marks:
        return [(None, text)]
    ends = [m.start() for m in marks[1:]] + [len(text)]
    return [(m.group(1), text[m.start():end]) for m, end in zip(marks, ends)]


# Specs
# =====

# ${PATH_OSYS}/CLI/date/date.c - the backreference keeps bench/bench_00.c out.
RX_CLI_SOURCE  = re.compile(r"\$\{PATH_OSYS\}/CLI/(\w+)/\1\.c\b")
RX_SET_SOC     = re.compile(r"^\s*set\(\s*SOC\s+(\S+?)\s*\)", re.M)
RX_SET_CORE    = re.compile(r"^\s*set\(\s*CORE\s+(\S+?)\s*\)", re.M)
RX_PLACEHOLDER = re.compile(r"\$\{([\w:+]+)\}")
RX_SYMBOL      = re.compile(r"^sym:(\w+)(?:\+([0-9A-Fa-f]+))?$")
RX_DEF_COMM    = re.compile(r"^#define\s+KDEF_COMM\s+K(\w+)", re.M)
# { .oFunction="console", ..., .oSW=0x00U, .oBaudrate=KSERIAL_BAUDRATE_115200 }
# or positionally { "console", ..., 0x00U, KSERIAL_BAUDRATE_460800 } - switch
# position 0 is the one the board boots with.
RX_BAUD        = re.compile(r"(?:\.oSW\s*=\s*)?\b0x00U?\s*,\s*"
                            r"(?:\.oBaudrate\s*=\s*)?KSERIAL_BAUDRATE_(\d+)")


def read_variant(path):
    """The board facts and CLI inventory a variant's CMakeLists.txt declares."""

    path = os.path.normpath(os.path.abspath(path))
    cmake = os.path.join(path, "CMakeLists.txt")
    if not os.path.exists(cmake):
        raise Refusal("no CMakeLists.txt in %s" % path)
    with open(cmake) as handle:
        text = handle.read()

    clis = []
    for cli in RX_CLI_SOURCE.findall(text):
        if cli not in clis:
            clis.append(cli)
    socs = RX_SET_SOC.findall(text)
    cores = list(dict.fromkeys(RX_SET_CORE.findall(text)))
    if len(set(socs)) != 1:
        raise Refusal("%s: expected one set(SOC ...), found %s"
                      % (cmake, socs or "none"))
    if not cores:
        raise Refusal("%s: no set(CORE ...)" % cmake)

    # The console's serial manager, when the variant fixes it in one place
    # (every board but Pico2_rp2350, which chooses per core). The board's own
    # answer overrides it; this is only for offline use.
    console, baud = None, None
    stub = os.path.join(path, "Processes", "startUp", "stub_startUp.c")
    if os.path.exists(stub):
        with open(stub) as handle:
            source = handle.read()
            found = RX_DEF_COMM.search(source)
            console = found.group(1).lower() if found else None
            found = RX_BAUD.search(source)
            baud = int(found.group(1)) if found else None

    return {"path": path,
            "console": console,
            "baud": baud,
            "board": os.path.basename(os.path.dirname(path)),
            "variant": os.path.basename(path),
            "soc": socs[0],
            "cores": cores,
            "clis": clis}


def console_bauds(board=None):
    """The console baud rates the variants declare - of one board, or of every
    board - most common first. A board opened at the wrong rate captures
    nothing and reads exactly like a dead one (MAiXDUiNO_K210 runs at 115200
    where every other board runs at 460800)."""

    targets = os.path.join(KROOT, "Ports", "Targets")
    boards = [board] if board else sorted(os.listdir(targets))
    count = {}
    for name in boards:
        base = os.path.join(targets, name)
        if not os.path.isdir(base):
            continue
        for entry in sorted(os.listdir(base)):
            if not entry.startswith("Variant_"):
                continue
            try:
                baud = read_variant(os.path.join(base, entry))["baud"]
            except Refusal:
                continue
            if baud:
                count[baud] = count.get(baud, 0) + 1
    return sorted(count, key=lambda b: -count[b])


def resolve_core(variant, ident):
    """The CORE under test: the only one declared, or the one the board reports
    among several (Pico2_rp2350 builds CORTEX_M33 or RV32IMAC from one dir)."""

    cores = variant["cores"]
    reported = (ident or {}).get("Core")
    if reported is not None:
        if reported not in cores:
            raise Refusal("the board reports core %s, %s declares %s"
                          % (reported, variant["path"], ", ".join(cores)))
        return reported
    if len(cores) == 1:
        return cores[0]
    raise Refusal("%s declares several cores (%s); without a board there is "
                  "no telling which one is meant" % (variant["path"],
                                                     ", ".join(cores)))


def expand(text, values, where):
    """Replace ${NAME} placeholders. Values are regex-escaped where the text is
    a pattern; an unknown name is an error, so a typo cannot quietly match."""

    def one(match):
        key = match.group(1)
        symbol = RX_SYMBOL.match(key)
        if symbol:
            table = values.get("sym:")
            if not isinstance(table, dict):
                raise Unresolved(table or "no symbol table")
            if symbol.group(1) not in table:
                raise Refusal("%s: %s is not a symbol of FLASH.elf"
                              % (where, symbol.group(1)))
            return "%X" % (table[symbol.group(1)]
                           + int(symbol.group(2) or "0", 16))
        if key not in values:
            raise Refusal("%s: unknown placeholder ${%s} (known: %s)"
                          % (where, key, ", ".join(sorted(values))))
        return values[key]
    return RX_PLACEHOLDER.sub(one, text)


def symbol_skip(test, table):
    """Why a "sym:NAME" / "!sym:NAME" requirement fails for this build, or None.

    "sym:NAME" runs the row only where the symbol is non-zero (linker_lnEXRAM:
    the board has external RAM), "!sym:NAME" only where it is zero or absent.
    Like ${sym:...}, it needs the symbols of the flashed build.
    """

    for need in test.get("requires", []):
        match = re.match(r"^(!?)sym:(\w+)$", need)
        if not match:
            continue
        if not isinstance(table, dict):
            raise Unresolved(table or "no symbol table")
        nonzero = table.get(match.group(2), 0) != 0
        if match.group(1) == "" and not nonzero:
            return "%s is zero or absent in this build" % match.group(2)
        if match.group(1) == "!" and nonzero:
            return "%s is non-zero in this build" % match.group(2)
    return None


def resolve_row(test, cli, literal, pattern, where):
    row = dict(test)
    row["cli"] = cli
    row["symskip"] = symbol_skip(test, literal.get("sym:"))
    row["cmd"] = expand(test["cmd"], literal, where)
    row["expect"] = [expand(p, pattern, where) for p in test.get("expect", [])]
    row["refute"] = [expand(p, pattern, where) for p in test.get("refute", [])]
    row["then"] = []
    for step in test.get("then", []):
        step = dict(step)
        if "send" in step:
            step["send"] = expand(step["send"], literal, where)
        if "write" in step:
            step["write"] = expand(step["write"], literal, where)
        if "await" in step:
            step["await"] = expand(step["await"], pattern, where)
        if "absent" in step:
            step["absent"] = expand(step["absent"], pattern, where)
        step["expect"] = [expand(p, pattern, where)
                          for p in step.get("expect", [])]
        step["refute"] = [expand(p, pattern, where)
                          for p in step.get("refute", [])]
        row["then"].append(step)
    requires = list(test.get("requires", []))
    if ("module:" + cli) not in requires:
        requires.insert(0, "module:" + cli)
    row["requires"] = requires
    return row


def find_llvm_tool(name):
    for var in ("PATH_LLVM_ARM", "PATH_LLVM_RVXX"):
        base = os.environ.get(var)
        if base:
            cand = os.path.join(base, "bin", name)
            if os.path.isfile(cand):
                return cand
    return shutil.which(name)


def read_symbols(variant_path, firmware):
    """{name: address} from the variant's FLASH.elf, or a reason string.

    Only when that ELF was built from the revision the board runs (its
    build/version.h), or offline where there is no board to disagree: an
    address from another build is a plausible, wrong address, and here it is
    one the tests write to.
    """

    elf = os.path.join(variant_path, "Artefacts", "FLASH.elf")
    if not os.path.isfile(elf):
        return "no local FLASH.elf for this variant"
    built = elf_revision(variant_path)
    if firmware and built != firmware:
        return "local FLASH.elf is %s, the board runs %s" % (built, firmware)
    tool = find_llvm_tool("llvm-nm")
    if tool is None:
        return "llvm-nm not found"
    out = subprocess.run([tool, elf], capture_output=True, text=True).stdout
    table = {}
    for line in out.splitlines():
        fields = line.split()
        if len(fields) == 3:
            try:
                table.setdefault(fields[2], int(fields[0], 16))
            except ValueError:
                pass
    return table


def load_specs(specs_dir, clis, facts, vcs):
    """Rows for every CLI of the inventory that has a spec; the rest is
    returned as uncovered, so the gap stays visible."""

    symbols = facts.pop("sym:", None)
    literal = dict(facts, VCS=vcs or "")
    pattern = {k: re.escape(v) for k, v in facts.items()}
    pattern["VCS"] = re.escape(vcs) if vcs else KVCS_SHAPE
    # Hex addresses need no escaping, and a reason instead of a table makes
    # expand() raise Unresolved, which skips only the rows that use them.
    literal["sym:"] = pattern["sym:"] = symbols

    rows, uncovered = [], []
    for cli in sorted(clis, key=str.lower):
        path = os.path.join(specs_dir, cli + ".json")
        if not os.path.exists(path):
            uncovered.append(cli)
            continue
        with open(path) as handle:
            try:
                spec = json.load(handle)
            except ValueError as exc:
                raise Refusal("%s is not valid JSON: %s" % (path, exc))
        if spec.get("module") != cli:
            raise Refusal("%s declares module %r, expected %r"
                          % (path, spec.get("module"), cli))

        for test in spec.get("tests", []):
            where = "%s: %s" % (os.path.relpath(path), test.get("id", "?"))
            try:
                row = resolve_row(test, cli, literal, pattern, where)
            except Unresolved as exc:
                row = dict(test, cli=cli, then=[], unresolved=str(exc))
                row["requires"] = ["module:" + cli] + [
                    r for r in test.get("requires", []) if r != "module:" + cli]
            rows.append(row)
    return rows, uncovered


def prepare(ident, modules, variant_dir, specs_dir, expect_sha):
    """Resolve the variant, the specs and the inventory for one board.

    `ident` and `modules` are what identify() returned, or empty when offline.
    """

    if variant_dir:
        vdir = variant_dir
    elif ident.get("Board") and ident.get("Variant"):
        vdir = os.path.join(KROOT, "Ports", "Targets", ident["Board"],
                            ident["Variant"])
    else:
        raise Refusal("--variant is required without a board")
    variant = read_variant(vdir)

    # Refuse to run against the wrong board. The spec placeholders come from
    # the variant, so the wrong one would turn every identity row red and the
    # failures would look like firmware bugs.
    for key, fact in (("Board", "board"), ("Variant", "variant")):
        if ident and (ident.get(key) != variant[fact]):
            raise Refusal("%s is %s, the board says %s"
                          % (variant["path"], variant[fact], ident.get(key)))

    facts = {"BOARD": variant["board"], "VARIANT": variant["variant"],
             "SOC": variant["soc"], "CORE": resolve_core(variant, ident)}
    console = ident.get("Console") or variant["console"]
    if console:
        facts["CONSOLE"] = console
    facts["sym:"] = read_symbols(variant["path"], ident.get("VCS#"))
    tests, uncovered = load_specs(specs_dir, variant["clis"], facts,
                                  expect_sha)
    # Rows that end the console (each followed by a reset) come after the
    # ordinary ones. Rows that leave the board changed until the next reset
    # come last of all, so they cannot contaminate anything - not even a
    # terminal row, whose own process would block on what they leave behind.
    # sorted() is stable: the spec order is otherwise kept.
    tests = sorted(tests, key=lambda row: (2 if row.get("poisons") else
                                           1 if row.get("terminal") else 0))

    inventory, extra = [], []
    if ident:
        registered = {m for m, f in modules.items() if f == "X"}
        inventory = [(cli, cli in registered) for cli in variant["clis"]]
        extra = sorted(registered - set(variant["clis"]), key=str.lower)

    return {"variant": variant, "facts": facts, "tests": tests,
            "uncovered": uncovered, "inventory": inventory, "extra": extra}


def skip_reason(test, modules, have, allow_unsafe, offline,
                allow_poison=False, allow_terminal=False):
    """Why a row cannot run here, or None."""

    if test.get("terminal") and not allow_terminal:
        return "ends the console (%s); board-regression --allow-terminal" \
            % test["terminal"]
    if test.get("unresolved"):
        return "needs the flashed build's symbols: %s" % test["unresolved"]
    if test.get("symskip"):
        return test["symskip"]
    if test.get("poisons") and not allow_poison:
        return "leaves the board changed until reset (%s); --allow-poison" \
            % test["poisons"]
    for need in test.get("requires", []):
        if need.startswith("module:") and not offline:
            if need[7:] not in modules:
                return "%s not built into this variant" % need
        elif need.startswith("hw:") and (need[3:] not in have):
            return "%s not available (pass --have %s)" % (need, need[3:])
        elif need == "unsafe" and not allow_unsafe:
            return "needs --allow-unsafe"
    return None


def send_row(test, name):
    """Run one row. Returns (rc, report) like send_json.

    A plain row is one command read to the prompt. A row with `then` goes on
    after its command: {"send": ...} writes more input and reads to the
    prompt, {"write": ...} writes it and returns at once (input for a
    sub-prompt such as a REPL's, which is not the console's), {"await": re}
    waits for output. `"prompt": false`
    says the command itself does not come back to the prompt until its steps
    have run (echo, reading its input) - it is only written.
    """

    steps = test.get("then") or []
    if not steps:
        return send_json(test["cmd"], name, test.get("timeout", 10),
                         unsafe=test.get("unsafe", False),
                         expect=test.get("expect"), refute=test.get("refute"))

    mark = log_mark(name)
    texts, failures = [], []
    if test.get("prompt", True):
        rc, rep = send_json(test["cmd"], name, test.get("timeout", 10),
                            unsafe=test.get("unsafe", False),
                            expect=test.get("expect"),
                            refute=test.get("refute"))
        texts.append(rep.get("text", ""))
        failures += rep.get("failures", [])
        if rc not in (0, 3):
            return rc, dict(rep, text="\n".join(texts), failures=failures)
        if failures and test.get("stop_on_fail"):
            return 3, {"pass": False, "failures": failures,
                       "text": "\n".join(texts)}
    else:
        args = ["send", test["cmd"], "--no-expect"]
        if test.get("unsafe"):
            args.append("--unsafe")
        rc, _, err = serial(args, name)
        if rc != 0:
            return rc, {"pass": False, "error": err.strip()}

    step_mark = mark
    for number, step in enumerate(steps, 1):
        # absent watches from the start of the step before it: after a write
        # the answer can arrive before the absent step even begins.
        previous_mark, step_mark = step_mark, log_mark(name)
        if "send" in step:
            rc, rep = send_json(step["send"], name, step.get("timeout", 10),
                                unsafe=step.get("unsafe", False),
                                expect=step.get("expect"),
                                refute=step.get("refute"))
            texts.append(rep.get("text", ""))
            failures += [dict(f, step=number) for f in rep.get("failures", [])]
            if rc not in (0, 3):
                return rc, {"pass": False, "error": rep.get("error"),
                            "text": "\n".join(texts), "failures": failures}
            if failures and test.get("stop_on_fail"):
                break
        elif "write" in step:
            args = ["send", step["write"], "--no-expect"]
            if step.get("unsafe"):
                args.append("--unsafe")
            rc, _, err = serial(args, name)
            if rc != 0:
                return rc, {"pass": False, "error": err.strip(),
                            "text": log_since(name, mark), "failures": failures}
        elif "await" in step:
            # Read the session log from the row's start rather than asking
            # ukos-serial to expect: its expect marks the stream when the
            # request arrives, and output printed before that would be missed.
            deadline = time.time() + step.get("timeout", 10)
            seen = False
            while time.time() < deadline:
                if re.search(step["await"], log_since(name, mark), re.M):
                    seen = True
                    break
                time.sleep(0.2)
            if not seen:
                failures.append({"kind": "await", "pattern": step["await"],
                                 "timeout": step.get("timeout", 10),
                                 "step": number})
                break
        elif "absent" in step:
            # The opposite of await: nothing matching may arrive, from the
            # previous step on and for the whole timeout - how a frozen console
            # is told from a slow one.
            time.sleep(step.get("timeout", 5))
            found = re.search(step["absent"], log_since(name, previous_mark),
                              re.M)
            if found:
                failures.append({"kind": "absent", "pattern": step["absent"],
                                 "at": found.group(0), "step": number})

    report = {"pass": not failures, "failures": failures,
              "text": log_since(name, mark) or "\n".join(texts)}
    return (3 if failures else 0), report


def describe(failure):
    """One line for a failed assertion, whichever step it came from."""

    where = "step %d: " % failure["step"] if failure.get("step") else ""
    if failure["kind"] == "expect":
        return "%sexpect %s  did not hold" % (where, failure["pattern"])
    if failure["kind"] == "await":
        return "%sawait %s  not seen within %ss" % (where, failure["pattern"],
                                                    failure.get("timeout"))
    if failure["kind"] == "absent":
        return "%sabsent %s  arrived anyway: %r" % (where, failure["pattern"],
                                                    failure.get("at", ""))
    return "%srefute %s  matched %r" % (where, failure["pattern"],
                                        failure.get("at", ""))


# Crash recovery
# ==============

KPROGRAMMER_HINTS = (
    "/Applications/STM32CubeProgrammer/Contents/Resources/bin/STM32_Programmer_CLI",
    "/opt/st/stm32cubeprog/bin/STM32_Programmer_CLI",
)

# How to reset a board over SWD. mode=UR works on the classic STM32 parts; the
# N657 has to be reached through access port 1 without a reset line. There,
# the programmer reports "Unable to run MCU" and the board reboots anyway, so
# the exit code of the reset is never trusted - only the console coming back.
KRESET = {
    "Discovery_N657": ["mode=HOTPLUG", "ap=1"],
    "Nucleo_N657":    ["mode=HOTPLUG", "ap=1"],
}
KRESET_DEFAULT = ["mode=UR"]

KREVIVE_TRIES = 8
KREVIVE_WAIT  = 2          # seconds between attempts


def find_programmer():
    for cand in KPROGRAMMER_HINTS:
        if os.path.isfile(cand):
            return cand
    return shutil.which("STM32_Programmer_CLI")


def probe_for_port(port):
    """The ST-Link serial number behind a console port, or None.

    The USB serial number of an ST-Link's virtual COM port is the probe's own
    serial number - the sn= the programmer takes. Knowing it means resetting
    exactly this board, where finding the probe by connecting under reset (as
    the Burn/ scripts do) resets every board it tries.
    """

    try:
        from serial.tools import list_ports
    except ImportError:
        return None
    for info in list_ports.comports():
        if info.device == port and "STLINK" in (info.product or "").upper():
            return info.serial_number
    return None


def stlink_ports():
    """Every ST-Link console port with its probe serial number."""

    try:
        from serial.tools import list_ports
    except ImportError:
        return []
    return [(info.device, info.serial_number)
            for info in sorted(list_ports.comports(), key=lambda i: i.device)
            if info.device.startswith("/dev/cu.")
            and "STLINK" in (info.product or "").upper()]


def console_answers(name, timeout=6):
    rc, rep = send_json("uKOS", name, timeout, expect=[r"^Board:\s+\S+$"])
    return rc == 0


RX_BANNER = re.compile(r"^uKOS-X, \(c\) ", re.M)


def reset_board(board, sn, name):
    """Reset one board over SWD and wait for its console.

    Returns (rebooted, seconds, detail). A console that answers is not proof
    of a reset - a running Discovery_N657 refuses SWD, the reset silently does
    nothing, and a console that never went down answers anyway. Only the boot
    banner of a new start in the session log counts. The reset returns before
    the firmware answers, so the log is polled rather than trusted after a
    fixed sleep.
    """

    cli = find_programmer()
    if cli is None or not sn:
        return False, 0.0, "no programmer or no probe"
    mark = log_mark(name)
    started = time.time()
    subprocess.run([cli, "-c", "port=SWD", "sn=" + sn]
                   + KRESET.get(board, KRESET_DEFAULT) + ["-rst"],
                   capture_output=True, text=True)
    for _ in range(KREVIVE_TRIES):
        time.sleep(KREVIVE_WAIT)
        if RX_BANNER.search(log_since(name, mark)) and console_answers(name):
            return True, time.time() - started, "console back"
    if console_answers(name):
        return False, time.time() - started, \
            "no reboot: the console answers, but no boot banner followed " \
            "the reset (SWD could not reach the core?)"
    return False, time.time() - started, "console did NOT come back"


RX_DUMP = re.compile(r"^System dead! Core DUMP!!", re.M)


def parse_dump(text):
    """Summary of a core dump in `text`, or None if there is none."""

    match = RX_DUMP.search(text)
    if match is None:
        return None
    body = text[match.start():]

    def field(pattern):
        found = re.search(pattern, body, re.M)
        return found.group(1).strip() if found else None

    return {"exception": field(r"^Exception:\s+(.+)$"),
            "process":   field(r"^Process:\s+(.+)$"),
            "cfsr":      field(r"^CFSR\s+=\s+(.+)$"),
            "mmfar":     field(r"^MMFAR\s+=\s+(0x[0-9A-Fa-f]+)"),
            "bfar":      field(r"^BFAR\s+=\s+(0x[0-9A-Fa-f]+)"),
            "pc":        field(r"r15 \(PC\)\s+=\s+(0x[0-9A-Fa-f]+)")}


def find_symbolizer():
    return find_llvm_tool("llvm-symbolizer")


def elf_revision(variant_path):
    """The VCS# of the local build of this variant, from its version.h."""

    try:
        with open(os.path.join(variant_path, "build", "version.h")) as handle:
            found = re.search(r'SW_VERSION\s+"([^"]+)"', handle.read())
            return found.group(1) if found else None
    except OSError:
        return None


def symbolize(address, variant_path, firmware):
    """Function chain at `address`, or a reason why it cannot be given.

    Only when the local FLASH.elf was built from the revision the board runs:
    an ELF from another build would name a plausible and wrong function.
    """

    elf = os.path.join(variant_path, "Artefacts", "FLASH.elf")
    tool = find_symbolizer()
    if not (address and os.path.isfile(elf) and tool):
        return None, "no ELF or no llvm-symbolizer"
    built = elf_revision(variant_path)
    if built != firmware:
        return None, "local FLASH.elf is %s, the board runs %s" % (built, firmware)

    out = subprocess.run([tool, "--obj=" + elf, address],
                         capture_output=True, text=True).stdout
    lines = [l for l in out.splitlines() if l.strip()]
    frames = []
    for func, where in zip(lines[0::2], lines[1::2]):
        func = func.split("(")[0].split("::")[-1]
        where = os.path.basename(where.split(":")[0])
        frames.append("%s (%s)" % (func, where))
    return (" <- ".join(frames) or None), None
