#ifndef BOS_TEXT_IMPLEM_H_
#define BOS_TEXT_IMPLEM_H_

#include "video/abstraction/video_abstract.h"

char* g_video;
s_resolution g_resolution;

typedef struct
{
    char color;
} s_char_parameter;

void set_screen_resolution(s_coords p_position);
s_resolution get_screen_resolution(void);

void print_char(char p_char, void *p_parameters, s_coords p_position);

void clear_screen(void);

void clear_area(s_coords p_position, s_coords p_size);

s_abstract_video_api i_abstract_video_api;

#endif