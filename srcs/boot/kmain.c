#include "boot/boot.h"
#include "video/implementations/bos_text_implem.h"


void bos_kmain(s_boot_info* p_bif)
{
    i_abstract_video_api.init_driver = init_driver();


    i_abstract_video_api.clear_screen();

    while (1)
    {

    }
}
