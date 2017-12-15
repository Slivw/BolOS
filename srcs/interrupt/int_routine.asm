global _int_asm_clock, _int_asm_default, _int_asm_keyboard
extern int_clock, int_default, int_keyboard

_int_asm_default:
    call int_default
    iret

_int_asm_clock:
    call int_clock
    iret

_int_asm_keyboard:
    call int_keyboard
    iret