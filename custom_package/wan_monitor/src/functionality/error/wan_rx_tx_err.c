#include "file_handler.h"

#define DATA_FILE_TX_ERRORS "/sys/class/net/eth0/statistics/tx_errors"
#define DATA_FILE_RX_ERRORS "/sys/class/net/eth0/statistics/rx_errors"

int wan_get_tx_errors(void)
{
    int tx_errors = 0;

    tx_errors = read_int_from_file(DATA_FILE_TX_ERRORS);

    return tx_errors;
}

int wan_get_rx_errors(void)
{
    int rx_errors = 0;

    rx_errors = read_int_from_file(DATA_FILE_RX_ERRORS);

    return rx_errors;
}





