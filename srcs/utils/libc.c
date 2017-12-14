#include "utils/libc.h"

void *memcpy(void *p_dest, const void *p_src, u32 p_len)
{
    for (u32 i = 0; i < p_len; ++i)
    {
	((char *) p_dest)[i] = ((char *) p_src)[i];
    }
    return (p_dest);
}
