#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_NUM 8080

int main() {
    char buffer[2000];
    int server_socket, client_socket;
    // creating address for our server
    struct sockaddr_in server_address, client_address;
    memset(&server_address, 0, sizeof(server_address));

    // socket for the server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket < 0) {
        perror("Error couldn't create a socket");
        exit(EXIT_FAILURE);
    }

    // config our server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT_NUM);

    // Binding our server
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding");
        exit(EXIT_FAILURE);
    }

    printf("Socket binding to PORT: %d\n", PORT_NUM);

    // Listen for the connection from the client
    if (listen(server_socket, 10) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening for connections...\n");

    // Accept a connection from the client
    socklen_t client_address_len = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_len);

    if (client_socket < 0) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    // Now you can communicate with the client using the 'client_socket'
    ssize_t bytes = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes == -1 ) {
         perror("Error message failed to recv:("); 

    } else {
        buffer[bytes] = '\0'; 
	printf("Recv messgae form the clinet: %s\n", buffer); 
    
    }
    //Close sockets
    close(client_socket);
    close(server_socket);

    return 0;
}

