#include "kernel_utils/video_text_utils.h"

void print_line(char *p_str, void *p_param)
{
    int str_offset = 0;

    s_resolution screen_resolution =
	i_abstract_video_api.get_screen_resolution();

    s_coords local_coords;

    local_coords.x = 0;
    local_coords.y = screen_resolution.y - 1;	// stay at the botom line

    while (p_str[str_offset] != '\0')
    {

	if (local_coords.x >= screen_resolution.x ||
	    p_str[str_offset] == '\n' || p_str[str_offset] == '\r')
	{
	    move_text_upward();
	    local_coords.x = 0;
	    if (local_coords.x < screen_resolution.x)
		str_offset++;
	}
	print_char(p_str[str_offset], p_param, local_coords);
	local_coords.x++;
	str_offset++;
    }
    move_text_upward();
}

void move_text_upward()
{
    s_resolution screen_resolution =
	i_abstract_video_api.get_screen_resolution();

    // position offirst character of second line
    int buffer_offset = screen_resolution.x * 2;

    int local_position = 0;
    int screen_buffer_size = screen_resolution.x * screen_resolution.y * 2;


    while (local_position < screen_buffer_size)
    {
	g_video[local_position] = g_video[local_position + buffer_offset];
	local_position++;
    }
}
