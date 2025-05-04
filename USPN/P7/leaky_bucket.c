#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep()

#define BUCKET_CAPACITY 10
#define LEAK_RATE 1   // Packets per second

int main() {
    int bucket = 0; // current number of packets in the bucket

    // Simulation: adding packets and leaking from the bucket
    for (int time = 0; time < 20; time++) {
        // Simulate packet arrival (you can change the arrival logic as needed)
        if (bucket < BUCKET_CAPACITY) {
            bucket++;  // a packet arrives
            printf("Time %d: Packet added. Bucket size: %d\n", time, bucket);
        } else {
            printf("Time %d: Bucket full! Packet dropped.\n", time);
        }
        
        // Leak packets at a fixed rate
        if (bucket > 0) {
            bucket -= LEAK_RATE;
            if(bucket < 0) bucket = 0;
            printf("Time %d: Packet leaked. Bucket size: %d\n", time, bucket);
        }
        
        sleep(1); // Wait for 1 second (simulate time)
    }
    
    return 0;
}

// gcc leaky_bucket.c -o leaky_bucket
// ./leaky_bucket
