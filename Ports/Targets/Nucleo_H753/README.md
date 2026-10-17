# Target Nucleo_H753

(c) 2025-2026, Edo. Franzi, 2025-01-01

## Base

| Base   |                                  |
| ------ | -------------------------------- |
| CPU    | STM32H743 or STM32H753 @ 480-MHz |
| Core   | H7                               |
| Comm   | urt0..1, cdc0                    |
| Periph | I2c0                             |

## Boards

The port targets the NUCLEO-H753ZI, whose STM32H753 is an STM32H743 with the CRYP
and HASH accelerators. ST no longer sells the NUCLEO-H743ZI2, the same circuit board
with an STM32H743; `-DSOC=STM32H743` still builds for it.

| Board          | SoC       | Configure                                |
| -------------- | --------- | ---------------------------------------- |
| NUCLEO-H753ZI  | STM32H753 | `cmake --preset llvm` (default)          |
| NUCLEO-H743ZI2 | STM32H743 | `cmake --preset llvm -DSOC=STM32H743`    |

Both parts report the same device ID and programmer name (`STM32H7xx`), and an
STM32H743 image runs unchanged on the NUCLEO-H753ZI. Both live in
`Ports/EquatesModels/SOCs/STM32H7x3`, where what the STM32H753 adds is guarded by
`STM32H753_S` (see its README). `_build.sh` builds the STM32H753 image only.

Upstream µKOS-X calls this port `Nucleo_H743` and has no STM32H753 support; this fork
called it `Nucleo_H7x3` from 2026-10-15 to 2026-10-17. `Tools/Developer/bin/post-merge-h753`
carries the rename over an upstream merge.

## Variants

| Variant      | Description       | Specific                  |
| ------------ | ----------------- | ------------------------- |
| Variant_Test | For Initial tests | With MicroPython embedded |
|              |                   | With FS CDC TinyUSB       |
|              |                   | With TensorFlow           |
