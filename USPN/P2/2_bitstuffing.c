#include <stdio.h>
#include <string.h>

void bitStuffing(char* input, char* encoded) {
    int count = 0, j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        encoded[j++] = input[i];
        if (input[i] == '1') {
            count++;
            if (count == 5) {
                encoded[j++] = '0';  // Insert '0' after five consecutive '1's
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    encoded[j] = '\0';  // Null-terminate the encoded string
}

void bitUnstuffing(char* encoded, char* decoded) {
    int count = 0, j = 0;
    for (int i = 0; encoded[i] != '\0'; i++) {
        decoded[j++] = encoded[i];
        if (encoded[i] == '1') {
            count++;
            if (count == 5 && encoded[i + 1] == '0') {
                i++;  // Skip the stuffed '0'
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    decoded[j] = '\0';  // Null-terminate the decoded string
}

int main() {
    char input[] = "111110";
    char encoded[100], decoded[100];
    
    printf("Original data: %s\n", input);
    bitStuffing(input, encoded);
    printf("Encoded data with bit stuffing: %s\n", encoded);
    bitUnstuffing(encoded, decoded);
    printf("Decoded data after bit unstuffing: %s\n", decoded);
    
    return 0;
}

// gcc bitstuffing.c -o bitstuffing
// ./bitstuffing