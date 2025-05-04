#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // Windows-specific sleep

int main() {
    int bucket_size, output_rate, n, i;
    int packets[100]; // array to hold incoming packets
    int total_packets = 0, dropped = 0;

    printf("Enter bucket size: ");
    scanf("%d", &bucket_size);
    printf("Enter output rate: ");
    scanf("%d", &output_rate);
    printf("Enter number of seconds to simulate: ");
    scanf("%d", &n);

    // simulate packet arrival for n seconds
    for (i = 0; i < n; i++) {
        int packet_size;
        printf("Enter number of packets at second %d: ", i + 1);
        scanf("%d", &packet_size);

        if (packet_size + total_packets > bucket_size) {
            dropped = packet_size + total_packets - bucket_size;
            total_packets = bucket_size;
        } else {
            total_packets += packet_size;
            dropped = 0;
        }

        printf("Packets in bucket: %d |", total_packets);
        int sent = (total_packets < output_rate) ? total_packets : output_rate;
        total_packets -= sent;
        printf(" Sent: %d | Dropped: %d\n", sent, dropped);

        Sleep(1000); // 1 second delay
    }

    // Send remaining packets after time expires
    while (total_packets > 0) {
        int sent = (total_packets < output_rate) ? total_packets : output_rate;
        total_packets -= sent;
        printf("Packets in bucket: %d | Sent: %d | Dropped: 0\n", total_packets, sent);
        Sleep(1000);
    }

    return 0;
}
// gcc leaky_bucket.c -o leaky_bucket.exe
// .\leaky_bucket.exe
