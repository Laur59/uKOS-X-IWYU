# STM32H7x3

The STM32H743 and the STM32H753 are the same part: the STM32H753 adds two
peripherals, CRYP and HASH. They share the device ID (0x450), the memory map and
the programmer name (`STM32H7xx`). This directory is the only one for both:
there is no `SOCs/STM32H743` or `SOCs/STM32H753`.

A variant still names the real part (`set(SOC STM32H743)` on Firefly_H743 and
Alastor_H743, `set(SOC STM32H753)` on `Ports/Targets/Nucleo_H753/Variant_Test`), which defines `${SOC}_S` and is
the SoC the board reports. `Ports/cmake/soc-base.cmake` derives
`SOC_BASE = STM32H7x3` from it, the build searches `SOCs/${SOC}` (absent) and
then `SOCs/STM32H7x3`, and defines `STM32H7x3_S` too. A variant naming runtime
sources by path uses `${SOC_BASE}` (`SOCs/${SOC_BASE}/Runtime/first.c`).

What only the STM32H753 has:

| Path | Contents |
|------|----------|
| `Includes/soc_reg_crypto.h` | Includes the two headers below, under `#if defined(STM32H753_S)`. Code that drives CRYP or HASH includes it explicitly; `soc_reg.h` holds what both parts have |
| `Includes/Registers/stm32H753_cryp.h`, `stm32H753_hash.h` | Register equates generated from `STM32H753.svd` |
| `Includes/Registers/STM32H753.svd` | ST's description, version 2.5 (from STM32CubeProgrammer's `Resources/SVD`) |

The CRYP interrupt (vector 79) is empty in the vector table for both parts, as it
was when the STM32H753 was an overlay. HASH shares vector 80 with RNG
(`HASH_RNG_IRQn`). Giving the STM32H753 its CRYP vector means the same
`STM32H753_S` blocks in `soc_vectors.h` and `Runtime/first.c` as
`SOCs/STM32H7x7` has for the STM32H757.

A model that uses the accelerators cannot be chosen by the include order any
more (one directory serves both parts): it goes in `Models/` under
`#if defined(STM32H753_S)`, next to the software version in `Generic/Models`.

The register headers `stm32H7x3_*` come from `STM32H743.svd`, with the
generator of the upstream maintainer. `Tools/Developer/svd2equ.py` reconstructs
its rules: `svd2equ <svd> --verify <dir> --soc STM32H7x3` regenerates 44 of the
68 headers that map onto one SVD peripheral byte for byte (registers sharing an
offset, derived peripherals and hand edits account for the rest), and both
crypto headers (`--soc STM32H753`). One deviation: stripping the redundant
`HASH_` prefix from the digest registers at `0x310` would collide with
`HR0`..`HR4` at `0x0C`, so that bank keeps the SVD names `HASH_HR0`..`HASH_HR7`.

Upstream has `SOCs/STM32H743`; it was moved here with `git mv`, so a merge
follows the renames, but upstream edits name `stm32H743_*` and need renaming by
hand.
