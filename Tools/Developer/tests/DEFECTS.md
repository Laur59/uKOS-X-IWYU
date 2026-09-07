# Defects found while extending host test coverage

Recorded, **not fixed**. Tests that touch any of these pin *current* behaviour and carry a
comment pointing back here, so a later fix turns the affected test red rather than silently
changing what the suite asserts.

Nothing in this list has been verified on hardware; each was found by reading the source
while deriving a test matrix.

| Where | Defect |
|---|---|
| `OS/CLI/mutex/mutex.c:43` | Declares `KNUM_SEMAPHORE` as its module identifier, so `mutex` and `semaphore` both register as `X33_`. `KNUM_MUTEX` (`modules.h:210`) is defined but used by nothing, and `list X` shows two rows with the same identifier. Found by a host test asserting the id from `modules.h`. |
| `OS/CLI/mutex/mutex.c:67,133` | The `KERR_MEM` arm is unreachable: `error` is initialised `KERR_NOT` and never assigned, so "Not enough memory." can never print. |
| `OS/CLI/object/object.c:138` | `-mutx` tests `argv[1]` inside the `argc == 4` arm where all six sibling lines test `argv[2]`. Structurally identical to the `-gmt` defect fixed on `Features/unit-test` in `bab328dfc`, so `object 0 -mutx 5` answers "The object does not exist." |
| `OS/CLI/fill/fill.c:85` | `nbBytes = (uint32_t)(endAdd - startAdd)` with no reversed-range handling. `dump.c:96` reinterprets `end < start` as a length; `fill` instead underflows and writes ~4 GB. **No test may pass `fill` a reversed range.** |
| `OS/CLI/dump/dump.c:147` | `(nbBytes + 16U) / 16U` always emits one line too many — 16 bytes prints two lines — and *reads* those 16 bytes. The intended form is `(nbBytes + 15U) / 16U`. |
| `OS/CLI/hexloader/hexloader.c` `local_getHexValue`, and the `sloader` equivalent | A character that is not a hex digit falls through an `else { ; }` and contributes **0**, with no error. A corrupt stream is therefore decoded to wrong data rather than rejected; only the record checksum stands between that and a silent bad load, and a corruption that happens to be checksum-neutral is accepted outright. |
| `OS/CLI/sloader/sloader.c:222` | After the signature check fails the module prints "failed to find the application signature!" and then falls through to `return EXIT_OS_SUCCESS_CLI`. `hexloader` sets `EXIT_OS_FAILURE` on the identical path. The two loaders disagree, and reporting success after refusing to run the download looks like the wrong half. |
| `OS/CLI/dumptrace/dumptrace.c:133` | The ring wrap compares the read pointer against `&traceFifo[KRECORD_SZ_TRACE_FIFO]` — one **past** the end — so a walk that runs off the end reads that element before wrapping. The corrected comparison is against `[SZ - 1U]`. **Confirmed under ASan**, not merely reasoned: seeding the read pointer at slot 1 with a full `nbTraceWrites` gives `heap-buffer-overflow ... READ of size 8 at dumptrace.c:130 in prgm` (line 130 is where the out-of-range record is *rendered*; 133 is the faulty advance). The user-visible effect is one garbage line per wrapped dump, and the ring then runs one slot out of step. The dumptrace suite deliberately keeps every walk inside the buffer so `run-tests -s` stays green. |
| `OS/CLI/object/object.c:91,208` | The `KERR_PAR` arm is unreachable: `error` is only ever assigned `KERR_NOB` or `KERR_NOC`, so "Incorrect arguments." can never print. Same shape as the `mutex` `KERR_MEM` arm. |
| `OS/CLI/object/object.c` printers | An unused object slot has `oIdentifier == NULL`, which is passed straight to `dprintf("%s", …)`. That is undefined behaviour; macOS renders `(null)` but a target libc need not. Reachable by querying any unused object, e.g. `object -mutx 7` on a fresh board. |
| `OS/CLI/power/power.c:70` | `do { … } while (status != KERR_BATTERY_NOERR);` never exits on failure, making the "Battery manager problem!" branch at `:75` unreachable. |
| `OS/CLI/bench/bench.c:70` | `PRIVILEGE_ELEVATE` with no matching `PRIVILEGE_RESTORE` on any path. |
| `OS/CLI/wkspi/wkspi.c:120`, `wki2c/wki2c.c:111`, `wkserial/wkserial.c:119` | `strtoul(argv[1], …)` before any `argc` guard. |
| `OS/CLI/mutex/mutex.c:105`, `OS/CLI/semaphore/semaphore.c` | `idBuffer[core][j]` indexed by `oList.oNbElements` with no bound against `KKERN_NB_PROCESSES`. |
| `OS/CLI/dump/dump.c:141` | `0x%016X` applied to a `uintptr_t`; correct only because the target's `uintptr_t` is 32-bit. |
| `OS/CLI/szkern/szkern.c:115-130` | `sizeof(...)` printed with `%d` / `%"PRIu16"` rather than `%zu`. |
| `OS/CLI/dumptrace/dumptrace.c:131` | `%12lld` for a `uint64_t` timestamp where every sibling uses `PRIu64`. |
| `Tools/Developer/ukos-serial:58-63` | `memory` sits on `KUNSAFE` although it is read-only; `.claude/agents/ukos-board.md:78` already notes the contradiction. |
| `OS/Includes/types_unix.h:34-35` | `EXIT_OS_SUCCESS` declared twice — a dead file that has never compiled. Unreferenced anywhere. |
| `OS/Lib_kernels/kern/kern.h:217` | `extern bool is_exception(void);` is declared and **has no definition anywhere in the repository**, nor a single caller. Only the `IS_EXCEPTION` macro (`Cores/<CORE>/Includes/macros_core.h`) is ever used. Harmless today because nothing references it, but it will link-fail the moment somebody believes the header. |
| `OS/Lib_kernels/kern/private/private_processes.h:49` | `extern const void **vKern_ptrGlobal[KNB_CORES];` is declared, **never defined and never referenced** - zero hits across `OS/`, `Ports/` and `Applications/`. Dead declaration, same shape as the one above. |
| `OS/Lib_kernels/kern/semaphores.c:248` and `:305`, `OS/Lib_kernels/kern/mutexes.c:251` and `:308`, `OS/Lib_kernels/kern/signals.c:280` | The release loops in `kern_killSemaphore`, `kern_restartSemaphore`, `kern_killMutex`, `kern_restartMutex` and the broadcast arm of `kern_signalSignal` **assign** `preemption` on every pass instead of accumulating it, so only the LAST process released has a say. Release a high-priority waiter followed by a low-priority one and no preemption is requested, even though the high-priority process is now runnable and outranks the caller. It stays unscheduled until something else happens to yield. `*preemption` in `local_signalSync` / `local_signalMutex` is correct - it releases exactly one process - so only the multi-waiter loops are affected. Five sites, one shape. Pinned by `semaphores_the_release_loop_only_remembers_the_last_waiter` and its mutex and broadcast twins. |
| `OS/Lib_kernels/kern/mailboxes.c:740` (and the tier-2 fake at `Tools/Developer/tests/fakes/ukos_fakes_kern.c:226`) | `local_readMailbox()` clears `*message` **only in reference mode, and only after the four entry guards**. A read that returns `KERR_KERN_FRISR`, `KERR_KERN_NOMBO` or `KERR_KERN_MBNCF` leaves the caller's pointer exactly as it was. Both the tier-2 fake and the comment at `OS/CLI/X/X.c:120` state the opposite - "stores nullptr in bufRec whenever it returns an error" - so the fake is more generous than production and the comment overstates the guarantee. `X.c` is not broken: it returns on the error and never reaches its `memcpy`. But its stated reason is wrong, and a future caller trusting the documented contract instead of checking the status would read from an uninitialised pointer. Pinned by `mailboxes_read_clears_the_message_only_in_reference_mode`. |
| `OS/Lib_neurals/mlpn/mlpn.c:681` | `local_exp`'s IEEE bit hack is inaccurate everywhere and **breaks down** at the bottom of its range. Measured on the host, not inferred: it returns **0.971 for exp(0)** where the answer is 1 (~3% low, and similarly biased throughout); it returns **NaN from about p = -87.99**; below that it returns **large negative floats** (-4.3e33 at p = -100); and below about **p = -177.4** the `float`-to-`int32_t` conversion overflows, which is **undefined behaviour**. Softmax subtracts the max before calling it, which keeps the argument in range for any sane logit spread - so the guard is load bearing, and `mlpn_softmax_max_subtraction_protects_local_exp` pins it. Note the ratio is far more robust than the individual values: for logits `{-100,-110}` the unprotected version still gives 0.999955 against a correct 0.999952, so only near the NaN band is the damage observable. |
| `OS/Lib_neurals/mlpn/mlpn.c:332` | `mlpn_configure` validates only the five layer pointers. `oNBInput == 0` underflows `oNBInput - 1U` to `0xFFFFFFFF` and writes far out of bounds; `oNBOutput`, `oInput`, `oActivation`, `oOutput` and `oWeight` are never checked at all. |
| `OS/Lib_neurals/mlpn/mlpn.c:253` | `mlpn_compute` without a prior `mlpn_configure` returns `KERR_MLPN_NOERR` and silently wrong results: the bias slot is never written, so every neuron loses its offset. `local_init()` is called on every compute and its body is empty. Pinned by `mlpn_compute_without_configure_is_silently_wrong`. |
| `OS/Lib_neurals/mlpn/mlpn.h:94` and `:119` | The documented `mlpnLayer_t` initialiser lists **six** values for a seven-field struct - `oNonLinear` is missing, so every field shifts by one - declares the layer `const` where `local_initialiseLayer` writes through it, and spells decimal points as commas (`4,6543f`, `05654f`). The example would not compile. `mlpn.c:108` has the corrected version. |
| `OS/Lib_neurals/mlpn/mlpn.c:606`, `:522`, `mlpn.h:149` | `local_relu`'s second branch is dead - both remaining paths `return p`. `local_tan2`'s comment describes the clamp-linear form, which is `local_tan3`. `KERR_MLPN_NOMEM` is documented but unreachable: the library never allocates. |
| `OS/Lib_neurals/lib_neurals.h:21` | Claims the manager "supports forward evaluation as well as back propagation". The C library is **inference only**; back-propagation exists solely in `mlpn/backprop.py`. `CLAUDE.md` had the same shape of error, describing `Lib_neurals` as TensorFlow Lite integration - corrected in the same change. |
| `OS/Lib_neurals/mlpn/backprop.py:88` | `mlp_forward` uses `mlp_tanh` for every hidden layer **unconditionally**, ignoring `config.KNON_LINEAR` - while `mlp_exportNetwork` writes that same `KNON_LINEAR` into the generated `network.c_inc`. So a network configured for `KMLPN_TAN2` is trained with true `tanh` and then run with the Pade approximation. The output activation is handled correctly (`mlp_outputActivation` does check `KNON_LINEAR_OUT`); only the hidden one is not. Real, but **not** the cause of the `class_Py` failure above: re-running that network with `KMLPN_TAN0` gives the identical 3/5, and `cluster_Py` reaches 97.6% despite the same mismatch. |
| `OS/Lib_generics/text/text.c:122` | `text_readArgs` never bounds `argv`. The caller's capacity is not a parameter, so the function cannot check it and does not - it appends one pointer per token for as many tokens as the line holds. `OS/CLI/console/console.c:253` passes a `KLN_CMD_LINE_BUF`-sized array, so a command line with more tokens than that writes past the end of the caller's stack array. A genuine out-of-bounds write. **Not provoked by any test**: doing so would turn `run-tests -s` red for the whole tree. |
| `OS/Lib_generics/text/text.c:166` and `:205` | Neither `text_copyAsciiBufferZ` nor `text_copyAsciiBufferN` bounds its destination - there is no size parameter in either signature. Both are `strcpy` with the same hazard, and `console.c:139` copies `argv[2]` straight into a fixed buffer. |
| `OS/Lib_generics/text/text.c:171` | `text_copyAsciiBufferZ` returns on an empty source **before** writing its terminator, where every other path writes it. Copying `""` into a dirty buffer therefore leaves the previous contents, and a caller reading the destination as a C string gets the old text. Pinned as a QUIRK. |
| `OS/Lib_generics/text/text.c:91` | `text_readArgs` only early-returns when the first byte is *already* a terminator. A leading space is not - it becomes one during pass 1, after that check - so `argv[0]` is set unconditionally and ends up pointing at an empty string, with the real command in `argv[1]`. `console.c` dispatches on `argv[0]`, so a line the user opened with a space is not the command they typed. Pinned as a QUIRK. |

## Fixed on `Features/unit-test` — the fix is NOT in this branch

Each row below is a defect one of the suites found *and* a fix that exists, on the branch
this tooling came from. **This branch carries the tests only.** The code described here is
still broken in it, and the suite that detects the defect still fails — `EXPECTED-FAILURES`
names the same commits and reports those failures as expected rather than as regressions.

They are kept in full, with the measurements taken at the time, so that whoever takes the
work up has the diagnosis and the commit to cherry-pick rather than just a symptom.

| Where | Defect | Fixing commit |
|---|---|---|
| `OS/CLI/dumplog/dumplog.c`, `OS/Lib_generics/record/recordDump.c` | `oMark` is the "already printed" flag of the log's selection sort, and it is **shared state**. `record_printLog()` walks the live `vRecord_logBuffer` in place — it runs on the coredump path, where the allocator cannot be relied on — and left every record it printed marked. `dumplog` copies that buffer, and a record arriving marked is never selected, so **`dumplog` printed nothing at all after a coredump**, exactly when the log is most wanted. `dumplog`'s own attempt to clear the marks was dead code: it ran *before* the `memcpy` that overwrote it. Neither file was wrong alone. `dumplog` now clears the marks in its own copy after the copy, and `record_printLog()` gives the marks back when it is done, so a second dump works too. **Not reachable from a console:** every caller of `record_printLog()` is terminal — the coredump ends in `cb_signal()`, which is `[[noreturn]]`, and every `crt0_exit()` panic ends with `INTERRUPTION_OFF` and never re-enables — so no board can be asked for a `dumplog` after a dump. The host suite is the only cover for the leak itself. What hardware *can* check is that the fix left the coredump path intact, which `Tools/Developer/bin/coredump-test` does on `Discovery_U5G9`: verified identical 13-record output before (`35f7ba715`) and after (`92f41db34`) the fix. | `92f41db34` |
| `Applications/uKOS_Appls_Downloadable/l_MLPs/class_Py/_Training/DB_Creator.py:76`, `:91`, `:102`, `:113` | **The training data was generated 40x too small, and the shipped demo network was consequently useless.** `normalize_point()` already divided by `KABS_MAX_FUNCTION`, and all four `fd.write` calls divided by it again; with `KABS_MAX_FUNCTION = 40` the database held points in +/-0.025 where +/-1 was intended. The `ax.plot()` call between the two used the correct value, which is why `class.png` looked right and only the data was wrong. Measured before the fix: the database spanned +/-0.0250 with a maximum radius of 0.0351 (= 0.025*sqrt(2)) and the ring at 0.0100..0.0175 - every figure exactly 1/40 of the intended geometry. The network trained on it scored **73% on its own learning and validation sets**, never predicted class 1 at all (0 of 1000), and its decision boundary was a single straight line; its layer-2 weights still sat at their initialisation spread. The four write calls now emit the already-normalised value, matching what the sibling `cluster_Py` generator does. **After regenerating and retraining: 98.6% on validation, 99.0% on learning, class 1 predicted 970 of 1000, and the decision map shows the intended ring / inner-outer / square geometry.** The `class_Py` golden in `tests/neural/test_mlpn.c` was refreshed with the new weights, and the test that recorded the misclassification is now a real assertion that all five `KVALIDATION` samples are classified correctly. **That golden is in this branch and the retrained `network.c_inc` is not**, so `ukos_tests_mlpn` fails here until the fix is taken. | `4aa03390a` |
| `OS/CLI/hexloader/hexloader.c`, `OS/CLI/sloader/sloader.c` | The loop waiting for a record mark discarded `local_getByte`'s status. That function sets `*byte = 0` before returning a framing, noise or parity error, so 0 never matched `':'` / `'S'` and any serial error while a loader waited **spun forever** — recoverable only by resetting the board. `sloader` discarded it twice: the mark loop and the type byte that follows. Both now test the status as every other call site does. The suites gained the empty-stream and no-mark tests that were impossible before; against the unfixed code they hang rather than fail. | `9db073a93` |

## Not defects

Recorded because each looks like one until checked:

- `OS/CLI/dump/dump.c:96` — `if (endAdd < startAdd) { endAdd += startAdd; }` is not a
  missing guard but a deliberate reinterpretation: a second argument smaller than the first
  is treated as a **length**. `dump 100 10` dumps 0x10 bytes from 0x100.
- `OS/CLI/list/list.c` omitting `KID_FAM_APPLICATIONS` from its family sweep — downloadable
  applications are not in the built-in directory at all, so the sweep is right and the help
  text advertising `'U'` is what misleads.
- `OS/Lib_kernels/kern/identifier.c:35` — `identifiers_cmpStrings()` comparing at most
  `KKERN_OBJECT_SZ_ID` characters is the documented bound, not a truncation bug: that
  constant is the object-name buffer size *including* the terminator
  (`kern_types.h:144`), so the loop covers the longest legal name and its `'\0'` exactly.
  Two names that differ only past the bound do compare equal, and `kern_getMutexById` and
  its five siblings would then return the wrong handle — but reaching that needs a name
  longer than the buffer is meant to hold. Pinned as a QUIRK by
  `identifier_names_differing_only_past_the_bound_collide`, not listed as a defect.
- `OS/Lib_kernels/kern/mutexes.c:523` — `local_signalMutex` returning while the counter is
  still negative, without clearing `oOwner`, is not a leak of ownership: it is what makes a
  recursive hold safe. A partially unwound mutex must stay owned, or another process could
  take it between two unlocks of the same critical section. The owner is cleared only when
  the count reaches zero.
- `OS/Lib_kernels/kern/mailboxes.c:780` — `*size == 0` on a copy-mode read meaning "give me the
  whole message" rather than "copy nothing" is deliberate, not an inverted test: it lets a caller
  that does not know the message length pass 0 and receive whatever is there. The hazard is real
  but is the caller's - a buffer smaller than `oDataEntrySize` combined with a 0 size overflows,
  and nothing in the signature warns of it. Pinned as a QUIRK by
  `mailboxes_copy_mode_treats_a_zero_size_as_give_me_everything`; changing it would break every
  caller using 0 as "whatever is there".
- `OS/Lib_neurals/mlpn/mlpn.c:534` — `local_tan2` clamping with `>=` where `local_tan1` uses
  `>` is not an inconsistency worth fixing: at exactly `p == 3` the ratio is
  `3(27+9)/(27+81)` = `108/108` = **exactly 1.0**, so TAN2's clamp is redundant at its own
  bound and the two forms are indistinguishable. A mutation weakening it survives and always
  will.
- `OS/Lib_neurals/mlpn/mlpn.c:608` — `local_relu` testing `p <= 0` rather than `p < 0` is
  likewise unobservable: the only input the two treat differently is `-0.0`, where one
  returns `+0.0` and the other `-0.0`. IEEE says those compare equal and nothing downstream
  can distinguish them.

**Recorded but deliberately NOT provoked**: `text_checkAsciiBuffer`
(`OS/Lib_generics/text/text.c:247`) reads one byte past the terminator when its FIRST
argument is empty — the do-while compares `'\0'` against `'\0'`, increments both pointers
past the NUL, and only then evaluates its loop condition. The drift-checked copy in
`Tools/Developer/tests/fakes/ukos_fakes_text.c` has the same defect byte for byte, and that
copy is linked by every other executable in the suite. A test that provoked it would turn
`run-tests -s` red across the whole tree, so **no test may pass an empty first argument to
`text_checkAsciiBuffer`** — the same treatment as `fill.c`'s reversed range.
