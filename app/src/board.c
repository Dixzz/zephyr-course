#include<zephyr/init.h>
#include<zephyr/kernel.h>

static int board_esp32_devkitc_foo_procpu_init(void) {
    printk("HELLO\n");
    return 0;
}
SYS_INIT(board_esp32_devkitc_foo_procpu_init, PRE_KERNEL_1, 0);
