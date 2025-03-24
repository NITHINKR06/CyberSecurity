// TCP Client for Windows
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib") // Link Winsock library

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server_addr;
    char message[] = "Hello Server";
    
    WSAStartup(MAKEWORD(2, 2), &wsa); // Initialize Winsock
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    send(sock, message, strlen(message), 0);
    
    printf("Message sent to server\n");
    
    closesocket(sock);
    WSACleanup(); // Cleanup Winsock
    
    return 0;
}

// gcc tcp_client.c -o tcp_client -lws2_32
// tcp_client.exe