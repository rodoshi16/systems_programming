#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>    /* Internet domain header */
#include <arpa/inet.h>     /* only needed on mac */

#define PORT 52918// change this value to customize the port per student (step 2)
#define LEGO_PIECES 10
#define MAX_BUF 128
#define MAX_QUEUE 2

/*
 * Accept a new player and return the active socket descriptor for the connection.
 */
int accept_player(int listen_soc, char *name) {
    struct sockaddr_in client_addr;
    unsigned int client_len = sizeof(struct sockaddr_in);
    client_addr.sin_family = AF_INET;

    int client_socket = accept(listen_soc, (struct sockaddr *)&client_addr, &client_len);
    if (client_socket == -1) {
        perror("accept");
        return -1;
    }

    if (strcmp(name, "one") ==0){
        char msg[MAX_BUF];
        sprintf(msg, "Hello player %s! Please wait for player 2 to begin.\r\n", name);
        //telling os to look up resource with ID 4 and write the bytes there
        write(client_socket, msg, strlen(msg));

    }
    
    else {
        char msg[MAX_BUF];
        sprintf(msg, "Hello player %s!\r\n", name);
        //telling os to look up resource with ID 4 and write the bytes there
        write(client_socket, msg, strlen(msg));

    }

    return client_socket;
}

/*
 * Write msg to players with socket descriptors player1 and player2
 */
void write_to_players(char *msg, int player1, int player2) {
    write(player1, msg, strlen(msg));
    write(player2, msg, strlen(msg));



    
}

/* Read and return a valid move from socket.
 * A valid move is a text integer between 1 and 3 followed by a \r\n.
 *
 * Hint: read from the socket into a buffer, loop over the buffer
 *   until you find \r\n and then replace the \r with \0 to make a
 *   string. Then use strtol to convert to an integer. If the result
 *   isn't in range, write a message to the socket and repeat.
 */
int read_a_move(int socket) {

    char buf[MAX_BUF]; 
    read(socket, buf, MAX_BUF); 

    for(int i = 0; i < MAX_BUF; i++){

        if (buf[i] == '\r'){
            buf[i] = '\0';

            //strtol needs a string - which it is now null      terminated
            //10 says to interpret the string as a decimal
            int move = strtol(buf, NULL, 10); 

            if (move >= 1 && move <= 3){
                return move; 
            }

            //write 26 bytes from the string to the socket
            write(socket, "Invalid move\r\n", strlen("Invalid move\r\n")); 
            return read_a_move(socket); 
         }  
    }
    return 1; 
}


int main() {
    // create socket
    int listen_soc = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_soc == -1) {
        perror("server: socket");
        exit(1);
    }

    // initialize server address
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    memset(&server.sin_zero, 0, 8);
    server.sin_addr.s_addr = INADDR_ANY;

    printf("Server is listening on %d\n", PORT);

    // This sets an option on the socket so that its port can be reused right
    // away. Since you are likely to run, stop, edit, compile and rerun your
    // server fairly quickly, this will mean you can reuse the same port.
    int on = 1;
    int status = setsockopt(listen_soc, SOL_SOCKET, SO_REUSEADDR,
                            (const char *) &on, sizeof(on));
    if (status == -1) {
        perror("setsockopt -- REUSEADDR");
    }

    // Bind socket to an address
    if (bind(listen_soc, (struct sockaddr *) &server, sizeof(struct sockaddr_in)) == -1) {
      perror("server: bind");
      close(listen_soc);
      exit(1);
    }

    // Set up a queue in the kernel to hold pending connections.
    if (listen(listen_soc, MAX_QUEUE) < 0) {
        perror("listen");
        exit(1);
    }

    int p1 = accept_player(listen_soc, "one"); 
    int p2 = accept_player(listen_soc, "two");

    char buf[MAX_BUF] = "Basic rules of the game\r\n"; 
    write_to_players(buf, p1, p2); 

    int num_pieces = LEGO_PIECES;
    int round = 0;
    while (num_pieces > 0) {
        char msg[MAX_BUF];
        sprintf(msg, "There are %d lego pieces left.\r\n", num_pieces);
        write_to_players(msg, p1, p2); 



        // Prompt a player to move by writing a message to them
        int curr_player; 

        if (round % 2 == 0){
            curr_player = p1; 
        } else{
            curr_player = p2; 
        }
        sprintf(msg, "Please enter a move between 1-3.\r\n");
        write(curr_player, msg, strlen(msg));

        int move =   read_a_move(curr_player); 
        num_pieces -= move;
        round += 1;


        // Prompt the player to wait
        if (num_pieces != 0) {
            sprintf(msg, "Thanks! Please wait for the other player to move.\r\n");
            write(curr_player, msg, strlen(msg));
        }
    }

    char winner_announcement[MAX_BUF];
    sprintf(winner_announcement, "Winner is player %d!\r\n", (round - 1) % 2 + 1);
    write_to_players(winner_announcement, p1, p2);

    return 0;
}
