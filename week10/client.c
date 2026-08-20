#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>    
#include <arpa/inet.h> 

int main(){
    int soc = socket(AF_INET, SOCK_STREAM, 0); 
    if (soc == -1){
        perror("client: socket"); 
        exit(1); 
    }

    struct sockaddr_in client;
    client.sin_family = AF_INET; 
    memset(&client.sin_zero, 0, 8); 
    client.sin_port = htons(54321); 


    int con = connect(soc, (struct sockaddr *)&client, sizeof(struct sockaddr_in)); 
    return 0; 


}