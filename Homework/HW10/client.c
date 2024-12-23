#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define HOST "127.0.0.1"
#define PORT 12345
#define BUFFER_SIZE 1024


int main() 
{
    struct sockaddr_in server;
    int sock = 0;
    char buffer[BUFFER_SIZE] = {0};
    char message[BUFFER_SIZE];

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    {
        printf("\nSocket creation error\n");
        return -1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if (inet_pton(AF_INET, HOST, &server.sin_addr) <= 0) 
    {
        printf("\nInvalid address/ Address not supported\n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) 
    {
        printf("\nConnection Failed\n");
        return -1;
    }

    printf("Connected to serverer at %s:%d\n", HOST, PORT);

    while (1) 
    {
        printf("Enter message (type 'quit' to exit): ");
        fgets(message, BUFFER_SIZE, stdin);
        
        message[strcspn(message, "\n")] = 0;

        if (!strcmp(message, "quit")) break;

        send(sock, message, strlen(message), 0);
        printf("Message sent to serverer\n");

        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) 
        {
            printf("serverer disconnected or error occurred\n");
            break;
        }
        buffer[bytes_received] = '\0';
        printf("serverer echoed: %s\n", buffer);

        memset(buffer, 0, sizeof(buffer));
    }

    close(sock);
    printf("Connection closed\n");

    return 0;
}