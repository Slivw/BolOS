#include "memory/segmentation.h"

void segmentation_load()
{
    s_gdt gdt;

    segmentation_init((s_segments *) BOS_SEGMENTATION_ADDRESS);
    gdt.base = BOS_SEGMENTATION_ADDRESS;
    gdt.limit = sizeof(s_segments);
    asm ("LGDT %0" :: "g" (gdt));
    asm("MOVW $0x10, %ax");
    asm("MOVW %ax, %ds");
    asm("MOVW %ax, %ss");
    asm("MOVW %ax, %fs");
    asm("MOVW %ax, %es");
    asm("MOVW %ax, %gs");
    asm("LJMP $0x8, $kcode\n \
        kcode:");
}

void segmentation_init(s_segments *segments)
{
    segmentation_entry(&segments->empty, 0, 0, 0, 0);
    segmentation_entry(&segments->kernel_code, 0, BOS_HANDLED_MEMORY,
		       0x9B,
               0x0D);
    segmentation_entry(&segments->kernel_data, 0, BOS_HANDLED_MEMORY,
		       0x93,
		       0x0D);
}

void segmentation_entry(s_gdt_entry *p_entry, u32 p_base, u32 p_limit, u8 p_access,
			u8 p_flags)
{
    p_entry->limit0_15 = (p_limit & 0xFFFF);
    p_entry->base0_15 = (p_base & 0xFFFF);
    p_entry->base16_23 = (p_base & 0xFF0000) >> 16;
    p_entry->access = p_access;
    p_entry->limit16_19 = (p_limit & 0xf0000) >> 16;
    p_entry->flags = (p_flags & 0xf);
    p_entry->base24_31 = (p_base & 0xFF000000) >> 24;
}

u8 segmentation_access(u8 p_privilege, u8 p_executable, u8 p_direction,
		       u8 p_rw)
{
    u8 access = 0;

    access |= 1 << 0;
    access |= (p_privilege << 1) & 0xFF;
    access |= 1 << 3;
    access |= p_executable << 4;
    access |= p_direction << 5;
    access |= p_rw << 6;
    access |= 1 << 7;
    return (access);
}

u8 segmentation_flags(u8 p_granu, u8 p_size)
{
    u8 flags = 0;

    flags |= p_granu & 0xF;
    flags |= (p_size << 1) & 0xF;
    flags |= 0 << 2;
    flags |= 1 << 3;
    return (flags);
}
