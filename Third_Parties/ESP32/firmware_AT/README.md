# ESP32 AT firmware

© 2025-2026, Edo. Franzi, 2025-01-01

## Packages used for building ESP32 WROOM applications

### 1. Add to environment :

```bash
IDF_PATH=${PATH_TOOLS_GCC}/cross/esp/esp-idf
IDF_TOOLS_PATH=${IDF_PATH}/tools
ESP_PYTHON=/opt/local/bin/python

PATH=${PATH}:${IDF_PATH}
PATH=${PATH}:${IDF_PATH}/tools

export IDF_PATH
export IDF_TOOLS_PATH
```

### 2. Get the esp-idf

```bash
mkdir -p ${PATH_TOOLS_GCC}/cross/esp
cd ${PATH_TOOLS_GCC}/cross/esp
git clone --recursive https://github.com/espressif/esp-idf.git
```

### 3. Install the tools

```bash
cd IDF_PATH=${PATH_TOOLS_GCC}/cross/esp/esp-idf
sh install.sh
```

### 4. Install esptool.py

```bash
pip install esptool
```

### 5. Get the AT firmware

```bash
https://dl.espressif.com/esp-at/firmwares/esp32/ESP32-WROOM-32/ESP32-WROOM-32-AT-V4.1.1.0.zip
```

## Burn the new AT firmware

```bash
# From the Alastor console type
# esp32 -reset
# esp32 -boot

sh firmware_AT.sh -erase

# From the Alastor console type
# esp32 -reset
# esp32 -boot

sh firmware_AT.sh -burn
```

## Terminate: now configure for the uKOS-X usage

```bash
# Change the baudrate & set the wifi nework name
# From the Alastor console type
# esp32 -reset
# esp32 -connect 115200
# Now we should have access to the AT commandfs

AT+CWSAP="uKOS-X_wifi","",1,0,4,0
AT+UART_DEF=921600,8,1,0,1
```
