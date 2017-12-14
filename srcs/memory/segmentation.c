#include "memory/segmentation.h"

void segmentation_init()
{
    s_gdt gdt;

    segmentation_load();
    gdt.base = BOS_SEGMENTATION_ADDRESS;
    gdt.limit = sizeof(s_segments);
  asm("LGDTL %0":"=g"(gdt));
}

void segmentation_load()
{
    s_segments *segments = (s_segments *) BOS_SEGMENTATION_ADDRESS;

    segmentation_table(segments->empty, 0, 0, 0, 0);
    segmentation_table(segments->kernel_code, 0, BOS_HANDLED_MEMORY,
		       segmentation_access(0, 1, 0, 1),
		       segmentation_flags(0, 1));
    segmentation_table(segments->kernel_data, 0, BOS_HANDLED_MEMORY,
		       segmentation_access(0, 0, 0, 1),
		       segmentation_flags(0, 1));
    segmentation_table(segments->kernel_stack, 0, BOS_HANDLED_MEMORY,
		       segmentation_access(0, 1, 0, 1),
		       segmentation_flags(0, 1));
}

void segmentation_table(u8 * p_table, u32 p_base, u32 p_limit, u8 p_access,
			u8 p_flags)
{
    bits_cpy(&p_table, 0, &p_base, 0, 16);
    bits_cpy(&p_table, 16, &p_limit, 0, 16);
    bits_cpy(&p_table, 32, &p_base, 16, 8);
    bits_cpy(&p_table, 40, &p_access, 0, 8);
    bits_cpy(&p_table, 48, &p_limit, 16, 4);
    bits_cpy(&p_table, 52, &p_flags, 0, 4);
    bits_cpy(&p_table, 56, &p_base, 24, 8);
}

u8 segmentation_access(u8 p_privilege, u8 p_executable, u8 p_direction,
		       u8 p_rw)
{
    u8 access = 0;

    BIT_SET(access, 0, 1);
    bits_cpy(&access, 1, &p_privilege, 0, 2);
    BIT_SET(access, 3, 1);
    BIT_SET(access, 4, p_executable);
    BIT_SET(access, 5, p_direction);
    BIT_SET(access, 6, p_rw);
    BIT_SET(access, 7, 0);
    return (access);
}

u8 segmentation_flags(u8 p_granu, u8 p_size)
{
    u8 flags = 0;

    BIT_SET(flags, 0, p_granu);
    BIT_SET(flags, 1, p_size);
    return (flags);
}
