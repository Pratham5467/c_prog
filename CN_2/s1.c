#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

int main() {
    struct sockaddr_in s1_addr, s2_addr;
    int listeningSocket, client1soclket;
    char str[20];

    // Create socket
    listeningSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Set up the server address structure
    s1_addr.sin_family = AF_INET;
    s1_addr.sin_addr.s_addr = INADDR_ANY;
    s1_addr.sin_port = htons(9145);

    // Bind the socket
    bind(listeningSocket, (struct sockaddr*)&s1_addr, sizeof(s1_addr));

    // Listen for incoming connections
    listen(listeningSocket, 5);

    // Accept a connection
    socklen_t s2_addr_len = sizeof(s2_addr);
    client1soclket = accept(listeningSocket, (struct sockaddr*)&s2_addr, &s2_addr_len);


    // Receive message from the client
    ssize_t bytesReceived = recv(client1soclket, &str, sizeof(str), 0);

    if (bytesReceived == -1) {
        perror("Error receiving message");
        exit(EXIT_FAILURE);
    } 
    else if (bytesReceived == 0) {
        printf("Client disconnected.\n");
    } 
    else {
        printf("The message received is: %s\n", str);
    }


    // Close the sockets
    close(client1soclket);
    close(listeningSocket);

    return 0;
}

