#ifndef BOOT_H_
#define BOOT_H_

#include "types.h"
#include "error.h"

typedef struct
{
  u32 flags;
  u32 mem_lower;
  u32 mem_upper;
} __attribute__((packed)) s_boot_info;

#endif
