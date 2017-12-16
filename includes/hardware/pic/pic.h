#ifndef PIC_H_
#define PIC_H_

#include "io/io.h"

#define PIC1		0x20
#define PIC2		0xA0

#define PIC1_DATA	0x21
#define PIC2_DATA	0xA1

#define PIC_EOI		0x20

#define ICW1_ICW4	0x01
#define ICW1_INIT	0x10
 
#define ICW4_8086	0x01

#define PIC_1_OFFSET 0X20
#define PIC_2_OFFSET 0X28

#define PIC1_EOF_INT outb(PIC1,PIC_EOI)
 
#define PIC2_EOF_INT outb(PIC2,PIC_EOI)

void pic_init();

#endif