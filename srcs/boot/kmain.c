#include "boot/boot.h"
#include "hardware/pic/pic.h"

void bos_kmain(s_boot_info* p_bif)
{
    init_pic();
    while (1);
}
