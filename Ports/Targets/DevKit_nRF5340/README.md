# Target DevKit_nRF5340

(c) 2025-20xx, Edo. Franzi, 2025-01-01

## Base

| Base |                          |
| ---- | ------------------------ |
| CPU  | nRF53 @ 128-MHz / 64-MHz |
| Core | M33F - M33               |
| Comm | 2 x urt0 (1 per core)    |

## Variants

| Variant          | Description       | Specific                  |
| ---------------- | ----------------- | ------------------------- |
| Variant_Test_App | For Initial tests | With MicroPython embedded |
|                  |                   | With FS CDC TinyUSB       |
|                  |                   | With test_mcore           |
| Variant_Test_Net | For Initial tests | With test_mcore           |
