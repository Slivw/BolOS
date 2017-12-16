#include "boot/boot.h"
#include "hardware/pic/pic.h"
#include "idt/idt.h"
#include "hardware/ide/ide.h"
#include "io/io.h"

void bos_kmain(s_boot_info* p_bif)
{
    pic_init();
    idt_init();
    ide_init();
    //sti;
    while (1);
}
