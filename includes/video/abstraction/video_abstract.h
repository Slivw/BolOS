#ifndef VIDEO_ABSTRACT_H_
#define VIDEO_ABSTRACT_H_

#include "types.h"

enum video_type
{
    VIDEO,
    TEXT
};

typedef struct
{
    int x;
    int y;
} s_coords;

typedef s_coords s_resolution;
typedef s_coords s_size;

typedef struct 
{
    void (*set_screen_resolution)(s_coords p_position);
    s_resolution (*get_screen_resolution)(void);

    void (*print_char)(char p_char, void *p_parameters, s_coords p_position);
    void (*clear_screen)(void);
    void (*clear_area)(s_coords p_position, s_size p_size);
    void (*init_driver)();
    void (*deinit_driver)();
} s_abstract_video_api;

#endif