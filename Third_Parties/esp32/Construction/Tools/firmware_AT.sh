#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Goal:     Burn the flash of the esp32 device
#
#           Usage:
#           Connect and boot uKOS
#           From the console type:
#               esp32 -reset
#               esp32 -boot
#
#           source export.sh
#           ./firmware_AT.sh {-erase | -burn}
#
#           After the burning, change the baudrate to 921600-b/s
#               esp32 -reset
#               esp32 -connect 115200
#           Verify that everithing is OK
#               AT should return
#               AT
#           Set the name of the network
#               AT+CWSAP="uKOS-X_wifi","",1,0,4,0
#           Verify the current baudrate
#               AT+UART_DEF? should return
#               +UART_DEF:115200,8,1,0,1
#           Set the new baudrate
#               AT+UART_DEF=921600,8,1,0,1
#
#           usage with a wifi console
#           console wfi0
#               nc 192.168.4.1 9999 (on the computer)

set -euo pipefail

if [[ -z "${IDF_PATH:-}" ]]; then
    echo 'Variable IDF_PATH is not set!'
    exit 1
fi

if [[ -z "${PATH_UKOS_X_PACKAGE:-}" ]]; then
    echo 'Variable PATH_UKOS_X_PACKAGE is not set!'
    exit 1
fi

# Packages
# --------

export CHIP=esp32
export SERIAL=/dev/cu.usbserial-uKOS_1
export BAUDRATE=115200
export FIRMWARE=V4.1.1.0
export COMMAND="${1:-}"

<<<<<<<< HEAD:Third_Parties/ESP32/Construction/Tools/firmware_AT.sh
cd "${PATH_UKOS_X_PACKAGE}/Third_Parties/ESP32/ESP32-WROOM-32-AT-${FIRMWARE}"
========
cd "${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32/esp-idf-current/AT_firmware/ESP32-WROOM-32-AT-${FIRMWARE}"
>>>>>>>> develop:Third_Parties/esp32/Construction/Tools/firmware_AT.sh
echo 'Start of burning:' > esp32_temp.txt
date >> esp32_temp.txt

# To fully erase/burn the flash

if [[ "${COMMAND}" = '-erase' ]]; then
<<<<<<<< HEAD:Third_Parties/ESP32/Construction/Tools/firmware_AT.sh
	python -m esptool \
		--chip "${CHIP}" \
		--port "${SERIAL}" \
		--baud "${BAUDRATE}" \
		--before 'default-reset' \
		--after 'hard-reset' \
		erase-flash

elif [[ "${COMMAND}" = '-burn' ]]; then
	python -m esptool \
		--chip "${CHIP}" \
		--port "${SERIAL}" \
		--baud "${BAUDRATE}" \
		--before 'default-reset' \
		--after 'hard-reset' \
		write-flash -z --flash-mode dio --flash-freq 40m --flash-size 4MB \
			0x1000 bootloader/bootloader.bin \
			0x100000 esp-at.bin \
			0x8000 partition_table/partition-table.bin \
			0x10000 ota_data_initial.bin \
			0x20000 at_customize.bin \
			0x21000 customized_partitions/mfg_nvs.bin

else
	echo 'Usage: ./firmware_AT.sh {-erase | -burn}'
========
    python -m esptool \
        --chip "${CHIP}" \
        --port "${SERIAL}" \
        --baud "${BAUDRATE}" \
        --before 'default-reset' \
        --after 'hard-reset' \
        erase-flash

elif [[ "${COMMAND}" = '-burn' ]]; then
    python -m esptool \
        --chip "${CHIP}" \
        --port "${SERIAL}" \
        --baud "${BAUDRATE}" \
        --before 'default-reset' \
        --after 'hard-reset' \
        write-flash -z --flash-mode dio --flash-freq 40m --flash-size 4MB \
            0x1000 bootloader/bootloader.bin \
            0x100000 esp-at.bin \
            0x8000 partition_table/partition-table.bin \
            0x10000 ota_data_initial.bin \
            0x20000 at_customize.bin \
            0x21000 customized_partitions/mfg_nvs.bin

else
    echo 'Usage: ./firmware_AT.sh {-erase | -burn}'
>>>>>>>> develop:Third_Parties/esp32/Construction/Tools/firmware_AT.sh
fi

echo 'End of burning:' >> esp32_temp.txt
date >> esp32_temp.txt
mv esp32_temp.txt esp32_ready.txt
