#include "file_handler.h"

#define DATA_FILE "/sys/class/net/eth0/statistics/rx_crc_errors"


int wan_get_crc_err(void)
{
    int crc_err = 0;

    crc_err = read_int_from_file(DATA_FILE);

    return crc_err;
}







