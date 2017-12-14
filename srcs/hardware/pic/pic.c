#include "types.h"
#include "hardware/pic/pic.h"
#include "io/io.h"

void pic_init()
{
    u8 save_mask_pic1;
    u8 save_mask_pic2;
 
	save_mask_pic1 = inb(PIC1_DATA);
	save_mask_pic2 = inb(PIC2_DATA);
 
	outb(PIC1, ICW1_INIT+ICW1_ICW4);  
	io_wait();
	outb(PIC2, ICW1_INIT+ICW1_ICW4);
	io_wait();
	outb(PIC1_DATA, PIC_1_OFFSET);                 
	io_wait();
	outb(PIC2_DATA, PIC_2_OFFSET);        
	io_wait();
	outb(PIC1_DATA, 4);                     
	io_wait();
	outb(PIC2_DATA, 2);                     
	io_wait();
 
	outb(PIC1_DATA, ICW4_8086);
	io_wait();
	outb(PIC2_DATA, ICW4_8086);
	io_wait();
 
	outb(PIC1_DATA, save_mask_pic1);  
	outb(PIC2_DATA, save_mask_pic2);
}