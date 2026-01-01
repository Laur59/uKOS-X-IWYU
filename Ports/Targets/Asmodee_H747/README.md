# Target Asmodee_H747

(c) 2025-2026, Edo. Franzi, 2025-01-01

## Base

| Base       |                                                     |
| ---------- | --------------------------------------------------- |
| CPU        | STM32H747 @ 480-MHz / 240-MHz                       |
| Core       | H7 - M4                                             |
| Memory     | 8-MBytes SDRAM                                      |
| Comm       | urt0..1,  (See Arduino spec)                        |
| Periph     | Power management, i2c0, spi0, 8-LEDs, fast DMA XFER |
| Extensions | VIP connector                                       |

## Variants

| Variant          | Description       | Specific                  |
| ---------------- | ----------------- | ------------------------- |
| Variant_Test_CM4 | For Initial tests | test_mcore                |
| Variant_Test_CM7 | For Initial tests | With MicroPython embedded |
|                  |                   | With test_mcore           |
|                  |                   | With HS CDC TinyUSB       |
|                  |                   | With HS Video TinyUSB     |
