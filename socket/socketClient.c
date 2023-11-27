#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <unistd.h>
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
int main() {
    int fd_client; 
    // creating address for our Client 
    struct sockaddr_in client_address; 
    memset(&client_address, 0, sizeof(client_address)); 
    // socket for the Clinet 
    fd_client = socket(AF_INET, SOCK_STREAM, 0);
    // socket client   
    if (fd_client = -1) {
         perror("Couldn't create a Socket"); 
	 exit(EXIT_FAILURE); 
    }
    server_address.sin_family = AF_INET; 
    server_address.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP< &server_address.sin_addr); 
    // connect to the sever 
    if (connect(client_socket, (struct sockaddr*)&sever_address, &server_address_len) == -1 ) {
         perror("Connetiong failed to connect to the server"); 
	 exit(EXIT_FAILURE); 
    
    
    }  
    return 0; 
} 
