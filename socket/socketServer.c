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
    printf("Listening for the conenction form PORT: %d\n", PORT_NUM);
    // accpeted the client throught the clinet socekt with the client sever addrss 
   if (client_socket = accept(server_socket, (struct addr*)&client_address, &client_address_len) == -1 ) {
         perror("Connecting to accpit failed"); 
	 exit(EXIT_FAILURE); 
   
   
   } 
   // Reciving data form client 
   recv(client_socket, message, sizeof(message), 0); 
   printf("Reciving form clinet: %s", message); 

   // send a reponece back to the clinet
   strcpy(message, "Hello, You Connected to AT&T net service:)"); 
   send(client_socket, message, strlen(message), 0); 
   printf("Sent to client %s",message); 
   close(cilent_socket); 
   close(server_socket);

    return 0; 
}
