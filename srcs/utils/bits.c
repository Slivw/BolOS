#include "utils/bits.h"

void *bits_cpy(void *p_dest, u32 p_dest_pos, const void *p_src,
	       u32 p_src_pos, u32 p_len)
{
    for (u32 i = 0; i < p_len; ++i)
    {
	BIT_SET(*((char *) p_dest), (p_dest_pos + i),
		BIT_CHECK(*((char *) p_src), (p_src_pos + i)));
    }
    return (p_dest);
}
