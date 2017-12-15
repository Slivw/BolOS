#include "hardware/pic/pic.h"

void int_clock()
{
    PIC1_EOF_INT;
}

void int_default()
{
    PIC1_EOF_INT;
}

void int_keyboard()
{
    PIC1_EOF_INT;
}