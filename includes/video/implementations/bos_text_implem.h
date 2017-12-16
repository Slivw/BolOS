#ifndef BOS_TEXT_IMPLEM_H_
#define BOS_TEXT_IMPLEM_H_

#include "video/abstraction/video_abstract.h"

#define LINE_LENGTH 80
#define COLLUMN_NBR 25

#define VIDEO_MEM_ADDR (char*)0xB8000

char* g_video;
s_resolution g_resolution;
byte g_video_type;

typedef struct
{
    char color;
} s_char_parameter;

void set_screen_resolution(s_resolution p_resolution);
s_resolution get_screen_resolution(void);

int print_char(char p_char, void *p_parameters, s_coords p_position);

void clear_screen(void);

void clear_area(s_coords p_position, s_coords p_size);

void init_driver(s_abstract_video_api *p_abstract_api);

void dinit_driver(s_abstract_video_api *p_abstract_api);

#endif