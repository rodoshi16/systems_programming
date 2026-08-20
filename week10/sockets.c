#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>    
#include <arpa/inet.h> 

/*

Sockets give you an endpoint to talk to another machine. 

- socket(AF_INET, SOCK_STREAM, 0); 
- domain, type, protocol
- TCP is the protocol (rules) socket uses to communicate
- it does the job of socket communication really well and easy to program
- on failure: returns -1
- creating the phone

HOW DO WE CALL THIS PHONE? NEED A NUMBER - BIND 


Each machine has an IP address. 

To give information on the internet from one machine to another, we need the 
machine's address + the port. 

27 yorkshire, apt 13 (port)

Messages sent from one machine are enclosed in packets - they contain the address and the content


The router faciliates transfer of packets and knows where to send 

Server - program running on a specific port waiting for a program to send a message

Server just waits for data to be sent to the specific port

Client - sends the initial message and a connection between client and server

Sockets help establish this communication channel

Stream sockets - connection oriented that gurantee that messages will not be lost in transit

int socket(int domain, int type, int protocol); 

- success: returns index of an entry in a file descriptor table
- failure: return -1
- domain: what kind of address system you're using AF_NET
- type: SOCK_STREAM
- protocol: 0

int bind(listen_soc, const struct sockaddr *address, sockelen_t address_len)

- sockaddr: generic addresss
- sockaddr_in: specific address of AF_INET


htons - convert the byte order of host machine to network byte order


*/

int main(){
    //get yourself a phone
    int listen_soc = socket(AF_INET, SOCK_STREAM, 0); 
    if (listen_soc == -1){
        perror("socket"); 
        exit(1); 
    }

    //with AF_INET, its a IPv4 address so we use sockaddr_in
    struct sockaddr_in addr; 
    addr.sin_family = AF_INET; 
    addr.sin_port = htons(54321);
    //sin_zero: unused space in the struct
    // before: just has random bytes in the spot
    //after: same bytes are all zeros - good practise to pass clean structure to the os
    memset(&addr.sin_zero, 0, 8);  


    if (bind(listen_soc, (struct sockaddr*) &addr, sizeof(struct sockaddr_in) == -1)){
        perror("server"); 
        close(listen_soc);
        exit(1); 
    }

    //all clear - socket is waiting for incoming connections from another socket (client socket)
    //backlog - max number of incoming requests in the queue
    // when queue is full, it will make the 6th socket wait

    if (listen(listen_soc, 5))



}