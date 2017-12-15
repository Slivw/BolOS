#include "boot/boot.h"
#include "kernel_utils/video_text_utils.h"


void bos_kmain(s_boot_info* p_bif)
{
    p_bif = p_bif;
    init_driver(&i_abstract_video_api);

    i_abstract_video_api.clear_screen();

// test part

    char array[103] = "salut les copains comment ca va bien ? ca marche ou pas ? on va bien voir quand on sera 90 characteres";
    array[102] = '\0';

    byte param = 0x5;
    print_line(array, &param);

    print_line(array, &param);
    print_line(array, &param);
    print_line(array, &param);
    print_line(array, &param);
    print_line(array, &param);
    print_line(array, &param);

// end test part
    while (1)
    {}
}

