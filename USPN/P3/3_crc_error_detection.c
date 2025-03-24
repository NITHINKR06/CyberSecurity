#include <stdio.h>
#include <string.h>

// Function to perform XOR operation
void xorOperation(char *dividend, const char *divisor, int length) {
    for (int i = 0; i < length; i++) {
        dividend[i] = (dividend[i] == divisor[i]) ? '0' : '1'; // XOR operation
    }
}

// Function to calculate the CRC
void calculateCRC(char *data, const char *divisor, char *crc) {
    int dataLength = strlen(data);
    int divisorLength = strlen(divisor);
    
    // Augment the data with zeros for CRC calculation
    char augmentedData[dataLength + divisorLength];
    strcpy(augmentedData, data);
    for (int i = dataLength; i < dataLength + divisorLength - 1; i++) {
        augmentedData[i] = '0';
    }
    augmentedData[dataLength + divisorLength - 1] = '\0';
    
    // Perform division (XOR)
    for (int i = 0; i < dataLength; i++) {
        if (augmentedData[i] == '1') {
            xorOperation(augmentedData + i, divisor, divisorLength);
        }
    }
    
    // Copy remainder as CRC
    strncpy(crc, augmentedData + dataLength, divisorLength - 1);
    crc[divisorLength - 1] = '\0';
}

int main() {
    char data[100], divisor[100], crc[100];
    
    printf("Enter data (binary): ");
    scanf("%s", data);
    
    printf("Enter divisor (binary): ");
    scanf("%s", divisor);
    
    // Calculate CRC
    calculateCRC(data, divisor, crc);
    printf("CRC (remainder): %s\n", crc);
    
    return 0;
}

// gcc crc_error_detection.c -o crc_error_detection
// ./crc_error_detection