// UDP Server for Windows
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib") // Link Winsock library

int main() {
    WSADATA wsa;
    SOCKET server_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024] = {0};
    int client_len = sizeof(client_addr);
    
    WSAStartup(MAKEWORD(2, 2), &wsa); // Initialize Winsock
    server_fd = socket(AF_INET, SOCK_DGRAM, 0); // UDP socket
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    
    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    printf("UDP Server listening...\n");
    
    recvfrom(server_fd, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_addr, &client_len);
    printf("Client: %s\n", buffer);
    
    char response[] = "Hello from Server";
    sendto(server_fd, response, strlen(response), 0, (struct sockaddr*)&client_addr, client_len);
    
    closesocket(server_fd);
    WSACleanup();
    
    return 0;
}

// gcc udp_server.c -o udp_server -lws2_32
// udp_server.exe