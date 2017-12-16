#include "io/io.h"
#include "idt/idt.h"
#include "boot/boot.h"
#include "hardware/pic/pic.h"
#include "memory/segmentation.h"

void bos_kmain(s_boot_info * p_bif)
{
    segmentation_load();
    pic_init();
    idt_init();
    //sti;
    while (1);
}
