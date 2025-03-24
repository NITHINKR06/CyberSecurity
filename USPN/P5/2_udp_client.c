// UDP Client for Windows
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib") // Link Winsock library

int main() {
    WSADATA wsa;
    SOCKET client_fd;
    struct sockaddr_in server_addr;
    char buffer[1024] = {0};
    int server_len = sizeof(server_addr);
    
    WSAStartup(MAKEWORD(2, 2), &wsa); // Initialize Winsock
    client_fd = socket(AF_INET, SOCK_DGRAM, 0); // UDP socket
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    char message[] = "Hello from Client";
    printf("Sending message to server...\n");
    sendto(client_fd, message, strlen(message), 0, (struct sockaddr*)&server_addr, server_len);
    
    recvfrom(client_fd, buffer, sizeof(buffer), 0, NULL, NULL);
    printf("Server: %s\n", buffer);
    
    closesocket(client_fd);
    WSACleanup();
    
    return 0;
}

// gcc udp_client.c -o udp_client -lws2_32
// udp_client.exe