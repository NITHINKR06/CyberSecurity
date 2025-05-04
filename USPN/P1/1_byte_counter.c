#include <stdio.h>
#include <string.h>

int main() {
    // Predefined frames 
    char frames[3][100] = {
        "Hello",
        "World", 
        "FrameData"
    };  

    int frameCount = 3; // Number of frames

    // Sender Module: Count the bytes in each frame
    for (int i = 0; i < frameCount; i++) {
        printf("Sender: Frame %d has %d bytes\n", i + 1, (int)strlen(frames[i]));
    }

    // Receiver Module: Display each frame received
    for (int i = 0; i < frameCount; i++) {
        printf("Receiver: Frame %d received: %s\n", i + 1, frames[i]);
    }
    
    return 0;
}

// gcc byte_counter.c -o byte_counter
// ./byte_counter