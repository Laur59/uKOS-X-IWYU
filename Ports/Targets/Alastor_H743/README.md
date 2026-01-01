# Target Alastor_H743

(c) 2025-2026, Edo. Franzi, 2025-01-01

## Base

| Base       |                                                              |
| ---------- | ------------------------------------------------------------ |
| CPU        | STM32H743 @ 400-MHz                                          |
| Core       | H7                                                           |
| Memory     | 8-MBytes SDRAM + 1-MBytes serial Flash                       |
| Comm       | urt0..3, wfi0 (via esp32)                                    |
| Periph     | sdcard, battery management, i2c0..1, spi0..1, 8-LEDs, 3-D IMU, fast DMA XFER |
| Extensions | VIP connector + Generic extension                            |

## Variants

| Variant              | Description       | Specific                  |
| -------------------- | ----------------- | ------------------------- |
| Variant_Test         | For Initial tests | With MicroPython embedded |
