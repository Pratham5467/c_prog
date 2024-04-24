#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

int main() {
    struct sockaddr_in s1_addr;
    int connectedSocket;
    char s1[20],s2[20];

    printf("\nEnter the message : ");
    scanf("%[^\n]", s1);

    connectedSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (connectedSocket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    s1_addr.sin_family = AF_INET;
    s1_addr.sin_addr.s_addr = INADDR_ANY;  // Change this to the server's IP address
    s1_addr.sin_port = htons(9145);

    if (connect(connectedSocket, (struct sockaddr*)&s1_addr, sizeof(s1_addr)) == -1) {
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }

    send(connectedSocket, s1, sizeof(s1), 0);

    ssize_t bytesReceived = recv(connectedSocket, &s2, sizeof(s2), 0);

    printf("The message we received from the server again is : %s ",s2);

    close(connectedSocket);

    return 0;
}