#ifndef __WAN_ERROR_H__
#define __WAN_ERROR_H__

int wan_get_crc_err(void);

int wan_get_tx_droped_err(void);
int wan_get_rx_droped_err(void);

int wan_get_tx_errors(void);
int wan_get_rx_errors(void);

#endif /* __WAN_ERROR_H__ */
