#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "socket.h"

#ifndef PORT
  #define PORT 30000
#endif

#define BUFSIZE 30

int find_network_newline(const char *buf, int n);


int main() {
    setbuf(stdout, NULL);

    struct sockaddr_in *self = init_server_addr(PORT);
    int listenfd = set_up_server_socket(self, 5);

    while (1) {
        int fd = accept_connection(listenfd);
        if (fd < 0) {
            continue;
        }
        char buf[BUFSIZE] = {'\0'};
        int inbuf = 0;           
        int room = sizeof(buf);  
        char *after = buf;      

        int nbytes;
        while ((nbytes = read(fd, after, room)) > 0) {
            inbuf += nbytes; 
            int where;

            while ((where = find_network_newline(buf, inbuf)) > 0) {

                buf[where-2] = '\0'; 
                printf("Next message: %s\n", buf);
                memmove(buf, buf+where, inbuf-where); 
                inbuf -= where; 

            }
            // Step 5: update after and room, in preparation for the next read.
            room = sizeof(buf) - inbuf;
            after = buf + inbuf; 


        }
        close(fd);
        printf("The connection is now closed ...\n");
    }

    free(self);
    close(listenfd);
    return 0;
}


/*
 * Search the first n characters of buf for a network newline (\r\n).
 * Return one plus the index of the '\n' of the first network newline,
 * or -1 if no network newline is found. The return value is the index into buf
 * where the current line ends.
 * Definitely do not use strchr or other string functions to search here. (Why not?)
 */
int find_network_newline(const char *buf, int n) {

    for(int i = 0; i < n-1; i++){
        if (buf[i] == '\r' && buf[i+1] == '\n'){
            return 2 + i; 
        } 
    }

    return -1; 
}
