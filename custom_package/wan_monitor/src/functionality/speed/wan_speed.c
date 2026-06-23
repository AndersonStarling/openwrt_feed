#include "file_handler.h"

#define DATA_FILE "/sys/class/net/eth0/speed"

int wan_get_speed(void)
{
    int speed = 0;

    speed = read_int_from_file(DATA_FILE);

    return speed;
}