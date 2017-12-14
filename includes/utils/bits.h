#ifndef BITS_H_
#define BITS_H_

#include "types.h"

#define BIT_CHECK(var, pos)     ((var >> pos) & 1U)
#define BIT_SET(var, pos, bit)  (var ^= (-bit ^ var) & (1UL << pos))

/*
    Copy p_len bits from p_src using a position (p_src_pos) into p_dest from another position (p_dest_pos)
    p_dest and p_src MUST NOT overlap
*/
void *bits_cpy(void *p_dest, u32 p_dest_pos, const void *p_src,
	       u32 p_src_pos, u32 p_len);

#endif
