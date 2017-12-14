#include "video/implementations/bos_text_implem.h"

void clear_screen(void) 
{
    int count = (g_resolution.x + g_resolution.y * 80) * 2;

    while (count >= 0)
        g_video[count--] = 0;
}

void set_screen_resolution(s_coords p_position)
{
    // not implemented yet
}

s_resolution get_screen_resolution(void)
{
    return (g_resolution);
}

void print_char(char p_char, void *p_parameters, s_coords p_position)
{
    byte offset = 2;

    int coord = (p_position.x + (p_position.y * 80)) * offset;
    char* param = p_parameters;

    g_video[coord] = p_char;
    g_video[coord + 1] = *param;    
}

void clear_area(s_coords p_position, s_size p_size)
{
    byte char_data = 0;
    int initial_x = p_position.x;
    int initial_y = p_position.y;
    
    while (p_position.x < initial_x + p_size.x)
    {
        p_position.y = initial_y;
        while (p_position.y < initial_y + p_size.y)
        {
            i_abstract_video_api.print_char('\0', &char_data, p_position);
            p_position.y++;
        }
        p_position.x++;
    }
}

void init_driver()
{
    i_abstract_video_api.set_screen_resolution = set_screen_resolution;
    i_abstract_video_api.get_screen_resolution = get_screen_resolution;
    i_abstract_video_api.print_char = print_char;
    i_abstract_video_api.clear_screen = clear_screen;
    i_abstract_video_api.clear_area = clear_area;

    g_video = (char*)0xB8000;
    g_resolution.x = 80;
    g_resolution.y = 25;
}

void dinit_driver()
{
    i_abstract_video_api.set_screen_resolution = NULL;
    i_abstract_video_api.get_screen_resolution = NULL;
    i_abstract_video_api.print_char = NULL;
    i_abstract_video_api.clear_screen = NULL;
    i_abstract_video_api.clear_area = NULL;
}
