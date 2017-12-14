MAGIC equ 0x1BADB002
FLAGS equ 0x1BADB002
CHECKSUM equ -(MAGIC + FLAGS)
PILE_SIZE equ 50000

section .multiboot
align 4
DD MAGIC
DD FLAGS
DD CHECKSUM

section .text
global _start:function (_start.end - _start)
_start:
    mov esp, bottom_pile
    push ebx

    extern bos_kmain
    call bos_kmain
    cli
.hlt:
    hlt
    jmp .hlt
.end:


section .bss
resb PILE_SIZE
bottom_pile:
