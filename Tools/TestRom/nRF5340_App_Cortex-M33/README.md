# nRF5340

(c) 2025-20xx, Edo. Franzi, 2025-01-01

### Specific models and other (platform dependent)

```bash
https://developer.nordicsemi.com/nRF_Connect_SDK/doc/1.5.0/nrf/ug_nrf5340.html#programming-from-the-command-line

nrfjprog --recover --coprocessor CP_NETWORK
nrfjprog --recover

nrfjprog -f NRF53 --coprocessor CP_NETWORK --program testROM.hex --chiperase

cd  /App folder
nrfjprog -f NRF53 --program testROM.hex --chiperase
nrfjprog --pinreset


JLinkExe burn_nRF5340_xx.jlink

if swd
speed 8000
device nrf5340_xxAA_NET
r h
loadfile nRF5340_Net_Cortex-M33/testROM.hex
device nrf5340_xxAA_APP
r h
loadfile nRF5340_App_Cortex-M33/testROM.hex
r
g
device nrf5340_xxAA_NET
r
g
q
```
