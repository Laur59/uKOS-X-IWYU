# STM32H7x7

The STM32H747 and the STM32H757 are the same dual-core part (Cortex-M7 and
Cortex-M4); the STM32H757 adds two peripherals, CRYP and HASH. This directory is
the only one for both: there is no `SOCs/STM32H747` or `SOCs/STM32H757`.

A variant still names the real part (`set(SOC STM32H747)`), which defines
`STM32H747_S` and is the SoC the board reports. TinyUSB is built once for the
family (`Third_Parties/TinyUSB/Construction/Family/h7/STM32H7x7`), and both parts
link `Library/TinyUSB/Family/h7/STM32H7x7`.
`Ports/cmake/soc-base.cmake` derives `SOC_BASE = STM32H7x7` from it, the build
searches `SOCs/${SOC}` (absent) and then `SOCs/STM32H7x7`, and defines
`STM32H7x7_S` too. A variant naming runtime sources by path uses `${SOC_BASE}`
(`SOCs/${SOC_BASE}/Runtime/first.c`).

What only the STM32H757 has is guarded by `#if defined(STM32H757_S)`:

| File | Under the guard |
|------|-----------------|
| `Includes/soc_reg.h` | `stm32H757_CM{4,7}_cryp.h`, `stm32H757_CM{4,7}_hash.h` |
| `Includes/Registers/soc_vectors.h` | `CRYP_IRQn` (79), `CRYP_C0_IRQn`, `CRYP_C0_IRQHandler()` |
| `Runtime/first.c` | the vector at `0x017C` (`CRYP_C0_IRQHandler`, else 0) and its handler |
| `Includes/Registers/soc_vectors_CM{4,7}.c_inc` | vector 79, `CRYP_IRQn` |

Everything else is common. The register headers `stm32H7x7_*` were generated
from ST's SVD v2.x (see RM0399): the STM32H747 SVD v1.8 described RAMECC,
DMAMUX and RCC wrongly. All four SVDs are kept in `Includes/Registers/`:
`STM32H747_CM{4,7}.svd` (v1.8) and `STM32H757_CM{4,7}.svd` (v2.3, the source
of the headers).

Each core has its own NVIC, and three vectors differ between them: the CM4
sees `CM7_SEV_IT` (64) and `HSEM1` (126), the CM7 `CM4_SEV_IT` (65) and
`HSEM0` (125). `soc_vectors.h` and `first.c` declare all four, which serves
either core. The reference lists `Includes/Registers/soc_vectors_CM4.c_inc`
and `soc_vectors_CM7.c_inc`, included by nothing, follow the matching SVD;
upstream keeps one `soc_vectors.c_inc`, the CM4 list since its 0.6.7
delivery (the CM7 one before).

`Burn/`: `swd_FT4232_b.sh` (the Asmodee_H747's own FT4232, channel B, and its
default), `jlinkexe.sh` (its `device STM32H747XI` has not been tried on an
STM32H757), `stlink.sh` (names no probe serial: with several ST-Links attached
it flashes the first one), `stm32-dfu.sh`, `dfu-arduino.sh` (the DFU of the
Arduino Portenta bootloader, `2341:035b`, the Portenta_H747's default; never
follow it with `jlinkexe.sh`, whose full-chip `erase` wipes that bootloader).

Upstream has `SOCs/STM32H747`; the files moved here with `git mv`, so a merge
follows them as renames, but their contents still name `stm32H747_*` and need
renaming by hand.
