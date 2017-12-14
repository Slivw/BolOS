#ifndef SEGMENTATION_H_
#define SEGMENTATION_H_

#include "utils/bits.h"

#define BOS_HANDLED_MEMORY          0xFFFFFFFF
#define BOS_SEGMENTATION_ADDRESS    0x3FC0

typedef struct {
    u16 limit;
    u32 base;
} __attribute__ ((packed)) s_gdt;

typedef struct {
    u8 empty[8];
    u8 kernel_code[8];
    u8 kernel_data[8];
    u8 kernel_stack[8];
} __attribute__ ((packed)) s_segments;

/*
    Initialize segmentation, load from assembly
*/
void segmentation_init();

/*
    Write the segments into memory at BOS_SEGMENTATION_ADDRESS
*/
void segmentation_load();

void segmentation_table(u8 * p_seg, u32 p_base, u32 p_limit, u8 p_access,
			u8 p_flags);
u8 segmentation_access(u8 p_privilege, u8 p_executable, u8 p_direction,
		       u8 p_rw);
u8 segmentation_flags(u8 p_granu, u8 p_size);

#endif
