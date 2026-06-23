#include <stdio.h>
#include <stdlib.h>
#include "wan_error.h"
#include "wan_link.h"
#include "wan_speed.h"
#include "wan_rtt_packet_loss.h"

struct wan_monitor_ops
{
    int (*get_wan_speed)(void);
    double (*get_wan_rtt_latency)(void);
    int (*get_wan_packet_loss)(void);
    void (*rtt_packet_loss_check)(void);
    int (*get_wan_link_status)(void);
    int (*get_wan_rx_err)(void);
    int (*get_wan_tx_err)(void);
    int (*get_wan_tx_droped_err)(void);
    int (*get_wan_rx_droped_err)(void);
    int (*get_wan_crc_err)(void);
};

struct wan_monitor_status
{
    int speed;
    double rtt_latency;
    int packet_loss;
    int link_status;
    int rx_err;
    int tx_err;
    int tx_droped_err;
    int rx_droped_err;
    int crc_err;
};

struct wan_monitor_ops wan_ops = {
    .get_wan_speed = wan_get_speed,
    .get_wan_rtt_latency = wan_get_rtt_latency,
    .get_wan_packet_loss = wan_get_packet_loss,
    .rtt_packet_loss_check = wan_rtt_packet_loss_check,
    .get_wan_link_status = wan_get_link_status,
    .get_wan_rx_err = wan_get_rx_errors,
    .get_wan_tx_err = wan_get_tx_errors,
    .get_wan_tx_droped_err = wan_get_tx_droped_err,
    .get_wan_rx_droped_err = wan_get_rx_droped_err,
    .get_wan_crc_err = wan_get_crc_err,
};


void wan_monitor_init(struct wan_monitor_status * status)
{
    /* Initialize the WAN monitor status */
    status->speed = 0;
    status->rtt_latency = 0.0;
    status->packet_loss = 0;
    status->link_status = 0;
    status->rx_err = 0;
    status->tx_err = 0;
    status->tx_droped_err = 0;
    status->rx_droped_err = 0;
    status->crc_err = 0;
}

void wan_monitor_print_status(const struct wan_monitor_status * status)
{
    printf("WAN Status:\n");
    printf("Speed: %d Mbps\n", status->speed);
    printf("RTT Latency: %.2f ms\n", status->rtt_latency);
    printf("Packet Loss: %d%%\n", status->packet_loss);
    printf("Link Status: %s\n", status->link_status ? "Up" : "Down");
    printf("RX Errors: %d\n", status->rx_err);
    printf("TX Errors: %d\n", status->tx_err);
    printf("TX Dropped Errors: %d\n", status->tx_droped_err);
    printf("RX Dropped Errors: %d\n", status->rx_droped_err);
    printf("CRC Errors: %d\n", status->crc_err);
}

int main(void)
{
    struct wan_monitor_status wan_status;

    wan_monitor_init(&wan_status);

    while(1)
    {
        /* get wan status */
        wan_status.link_status = wan_ops.get_wan_link_status();
        wan_status.speed = wan_ops.get_wan_speed();
        wan_status.rtt_latency = wan_ops.get_wan_rtt_latency();
        wan_status.packet_loss = wan_ops.get_wan_packet_loss();

        /* get wan error */
        wan_status.rx_err        = wan_ops.get_wan_rx_err();
        wan_status.tx_err        = wan_ops.get_wan_tx_err();
        wan_status.tx_droped_err = wan_ops.get_wan_tx_droped_err();
        wan_status.rx_droped_err = wan_ops.get_wan_rx_droped_err();
        wan_status.crc_err       = wan_ops.get_wan_crc_err();

        wan_monitor_print_status(&wan_status);

        sleep(5);
    }

    return 0;
}
