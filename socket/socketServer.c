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
    int fd_socket; 
    // creating address for our sever 
    struct sockaddr_in sever_address; 
    memset(&sever_address, 0, sizeof(sever_address)); 
    // socket for the sever 
    fd_socket = socket(AF_INET, SOCK_STREAM, 0);  
    
    if (fd_socket < 0) {
    
         perror("Error coudln't create a socket"); 
	 exit(EXIT_FAILURE); 
    }
    // confing our address sever 
    sever_address.sin_family = AF_INET; 
    sever_address.sin_addr.s_addr = INADDR_ANY; 
    sever_address.sin_port = htons(PORT_NUM); 

    // Binding our sever 
    if (bind(fd_socket, (struct sockaddr*)&sever_address, sizeof(sever_address)) < 0) {
    
         printf("Socket Binding failed"); 
	 perror("Error binding"); 
	 exit(EXIT_FAILURE); 
    
    }
    printf("Socket binding to PORT: %d", PORT_NUM);
    // Listen for the connection forom client 
    if (listen(fd_socket, 10) < 0) {
        perror("Listen failed"); 
	close(fd_socket); 
	exit(EXIT_FAILURE); 
    
    
    }
    printf("Listening for the conenction form PORT: %d", PORT_NUM); 
    connect(fd_socket, (struct sockaddr*)&sever_address, sizeof(sever_address));
   close(fd_socket);  
    return 0; 
}
