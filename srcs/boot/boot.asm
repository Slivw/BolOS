DD 0x1BADB002
DD 0x00000002
DD 0xffffffff - (0x1BADB002 + 0x00000002)
_start:
    extern bos_kmain
    call bos_kmain
