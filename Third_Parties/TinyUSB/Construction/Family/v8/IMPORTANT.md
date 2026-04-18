# TinyUSB for uKOS-X for future STM32V873 cpu's

(c) 2025-2026, Edo. Franzi, 2025-03-19

## tub_config.h

It is important to keep STM32N657 defined in all `tusb_config.h` files. This is because, for now, TinyUSB does not support the STM32V873. The OTG engine of the STM32V873 is identical to that of the STM32N657.

So, keep these definitions.

```c
#define	CFG_TUSB_MCU			OPT_MCU_STM32N6
#define	STM32N657xx				1
```

