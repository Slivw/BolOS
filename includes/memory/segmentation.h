#ifndef SEGMENTATION_H_
#define SEGMENTATION_H_

#include "types.h"

#define BOS_HANDLED_MEMORY          0xFFFFFFFF
#define BOS_SEGMENTATION_ADDRESS    0x3FC0

typedef struct {
    u16 limit;
    u32 base;
} __attribute__ ((packed)) s_gdt;

typedef struct {
    u16 limit0_15;
    u16 base0_15;
    u8 base16_23;
    u8 access;
    u8 limit16_19_flags;
    u8 base24_31;
} __attribute__ ((packed)) s_gdt_entry;

typedef struct {
    s_gdt_entry empty;
    s_gdt_entry kernel_code;
    s_gdt_entry kernel_data;
    s_gdt_entry kernel_stack;
} __attribute__ ((packed)) s_segments;


/*
    Initialize segmentation, load from assembly
*/
void segmentation_load();

/*
    Write the segments into the corresponding structure
*/
void segmentation_init(s_segments *);

void segmentation_entry(s_gdt_entry* p_entry, u32 p_base, u32 p_limit, u8 p_access,
			u8 p_flags);
u8 segmentation_access(u8 p_privilege, u8 p_executable, u8 p_direction,
		       u8 p_rw);
u8 segmentation_flags(u8 p_granu, u8 p_size);

#endif
