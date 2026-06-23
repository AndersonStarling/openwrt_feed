#include <stdio.h>

struct wan_ping_status
{
    int packet_loss;
    double min_rtt;
    double avg_rtt;
    double max_rtt;
};

struct wan_ping_status wan_ping_status = {0, 0.0, 0.0, 0.0};

double wan_get_rtt_latency(void)
{
    return wan_ping_status.avg_rtt;
}

int wan_get_packet_loss(void)
{
    return wan_ping_status.packet_loss;
}

void wan_rtt_packet_loss_check(void)
{
    FILE *fp = popen("ping -c 5 -W 1 1.1.1.1", "r");
    if (fp == NULL) {
        perror("popen");
        return;
    }

    /* Process the output from the ping command */
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Handle each line of output
        if (strstr(buffer, "packet loss"))
        {
            /* Extract the packet loss percentage from the output */
            char *loss_str = strstr(buffer, "packet loss");

            if (loss_str) {
                int packet_loss = 0;
                sscanf(loss_str - 2, "%d", &packet_loss); /* Assuming the percentage is right before "packet loss" */
                wan_ping_status.packet_loss = packet_loss;
            }
        }
        else if (strstr(buffer, "round-trip min/avg/max"))
        {
            /* Extract the RTT values from the output */
            char *rtt_str = strstr(buffer, "=");

            if (rtt_str) {
                double min_rtt, avg_rtt, max_rtt;
                sscanf(rtt_str + 1, "%lf/%lf/%lf", &min_rtt, &avg_rtt, &max_rtt);
                wan_ping_status.min_rtt = min_rtt;
                wan_ping_status.avg_rtt = avg_rtt;
                wan_ping_status.max_rtt = max_rtt;
            }
        }
    }
    pclose(fp);
}




















