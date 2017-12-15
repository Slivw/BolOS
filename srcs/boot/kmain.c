#include "boot/boot.h"
#include "kernel_utils/video_text_utils.h"
#include "kernel_utils/motd.h"


void bos_kmain(s_boot_info* p_bif)
{
    p_bif = p_bif;

    init_driver(&i_abstract_video_api);
    i_abstract_video_api.clear_screen();
    byte param = 0x5;
    print_line(MOTD, &param);

// test part



// end test part
    while (1)
    {}
}
