#monitor stdio 用于在wsl控制台中显示 QEMU 的监控界面
SHELL_FOLDER=$(cd "$(dirname "$0")";pwd)
$SHELL_FOLDER/output/qemu/bin/qemu-system-riscv64 \
-M quard-star \
-m 1G \
-smp 8 \
-bios none \
-monitor stdio \
-drive if=pflash,bus=0,unit=0,format=raw,file=$SHELL_FOLDER/output/lowlevelboot/fw.bin \
#-nographic --parallel none \