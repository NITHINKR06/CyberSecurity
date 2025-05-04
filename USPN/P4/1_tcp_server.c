// TCP Server for Windows
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib") // Link Winsock library

int main() {
    WSADATA wsa;
    SOCKET server_fd, new_socket;
    struct sockaddr_in server_addr;
    char buffer[1024] = {0};
    int addrlen = sizeof(server_addr);
    
    WSAStartup(MAKEWORD(2, 2), &wsa); // Initialize Winsock
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    
    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_fd, 5);
    
    printf("Server listening...\n");
    new_socket = accept(server_fd, (struct sockaddr*)&server_addr, &addrlen);
    
    recv(new_socket, buffer, sizeof(buffer), 0);
    printf("Client: %s\n", buffer);
    
    closesocket(new_socket);
    closesocket(server_fd);
    WSACleanup(); // Cleanup Winsock
    
    return 0;
}

// gcc tcp_server.c -o tcp_server -lws2_32
// .\tcp_server.exe