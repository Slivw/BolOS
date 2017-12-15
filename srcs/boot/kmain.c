#include "boot/boot.h"
#include "memory/segmentation.h"

void bos_kmain(s_boot_info *p_bif)
{
    segmentation_load();
    while (1);
}
