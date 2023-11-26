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
    int server_socket; 
    int client_socket; 
    // creating address for our sever 
    struct sockaddr_in server_address, clinet_address; 
    memset(&sever_address, 0, sizeof(sever_address)); 
    // socket for the sever 
    server_socket = socket(AF_INET, SOCK_STREAM, 0);  
    
    if (server_socket < 0) {
    
         perror("Error coudln't create a socket"); 
	 exit(EXIT_FAILURE); 
    }
    // confing our address sever 
    server_address.sin_family = AF_INET; 
    server_address.sin_addr.s_addr = INADDR_ANY; 
    server_address.sin_port = htons(PORT_NUM); 

    // Binding our sever 
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
    
        printf("Socket Binding failed"); 
	 perror("Error binding"); 
	 exit(EXIT_FAILURE); 
    
    }
    printf("Socket binding to PORT: %d", PORT_NUM);
    // Listen for the connection forom client 
    if (listen(server_socket , 10) < 0) {
        perror("Listen failed"); 
	close(server_socket); 
	exit(EXIT_FAILURE); 
    
    
    }
    printf("Listening for the conenction form PORT: %d", PORT_NUM); 
    connect(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));
   close(sever_socket);  
    return 0; 
}
