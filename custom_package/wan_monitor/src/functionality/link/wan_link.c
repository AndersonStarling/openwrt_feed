#include "file_handler.h"

#define DATA_FILE "/sys/class/net/eth0/carrier"

int wan_get_link_status(void)
{
    int link_status = 0;

    link_status = read_int_from_file(DATA_FILE);

    return link_status;
}










