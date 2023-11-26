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
    int fd_client; 
    // creating address for our Client 
    struct sockaddr_in client_address; 
    memset(&client_address, 0, sizeof(client_address)); 
    // socket for the Clinet 
    fd_client = socket(AF_INET, SOCK_STREAM, 0);  
    return 0; 
} 
