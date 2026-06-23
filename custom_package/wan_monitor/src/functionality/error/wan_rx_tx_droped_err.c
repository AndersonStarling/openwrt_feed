#include "file_handler.h"

#define DATA_FILE_TX_DROP "/sys/class/net/eth0/statistics/tx_dropped"
#define DATA_FILE_RX_DROP "/sys/class/net/eth0/statistics/rx_dropped"

int wan_get_tx_droped_err(void)
{
    int tx_drop_err = 0;

    tx_drop_err = read_int_from_file(DATA_FILE_TX_DROP);

    return tx_drop_err;
}

int wan_get_rx_droped_err(void)
{
    int rx_drop_err = 0;

    rx_drop_err = read_int_from_file(DATA_FILE_RX_DROP);

    return rx_drop_err;
}





