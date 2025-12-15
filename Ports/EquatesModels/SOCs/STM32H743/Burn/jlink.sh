echo if swd >jlink.cmd
echo speed 10000 >>jlink.cmd
echo device stm32h743ii >>jlink.cmd
echo connect >>jlink.cmd
echo r h >>jlink.cmd
echo loadfile FLASH.elf >>jlink.cmd
echo r g >>jlink.cmd
echo q >>jlink.cmd
JLinkExe jlink.cmd
