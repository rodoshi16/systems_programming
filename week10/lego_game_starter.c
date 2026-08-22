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

    char msg[MAX_BUF];
    sprintf(msg, "Hello player %s! Please wait for your turn to begin.\r\n", name);
    //telling os to look up resource with ID 4 and write the bytes there
    write(client_socket, msg, strlen(msg));

    return client_socket;
}

/*
 * Write msg to players with socket descriptors player1 and player2
 */
void write_to_players(char *msg, int player1, int player2) {
    // TODO
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
    // TODO
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

    int client_socket = accept_player(listen_soc, "one"); // TODO: accept two players and store their socket descriptors in an array

    int num_pieces = LEGO_PIECES;
    int round = 0;
    while (num_pieces > 0) {
        char msg[MAX_BUF];
        sprintf(msg, "There are %d lego pieces left.\r\n", num_pieces);
        // TODO: Announce the current status to all players (hint: use write_to_players)

        // Prompt a player to move by writing a message to them
        int curr_player = client_socket; // TODO: set curr_player to the socket descriptor of the current player (hint: round % 2 will alternate between 0 and 1)
        sprintf(msg, "Please enter a move between 1-3.\r\n");
        write(curr_player, msg, strlen(msg));

        int move = client_socket; // TODO: Read a move from curr_player using read_a_move
        num_pieces -= move;
        round += 1;

        // Prompt the player to wait
        if (num_pieces != 0) {
            sprintf(msg, "Thanks! Please wait for the other player to move.\r\n");
            write(curr_player, msg, strlen(msg));
        }

        break; // TODO: remove this break statement after implementing the game loop
    }

    char winner_announcement[MAX_BUF];
    sprintf(winner_announcement, "Winner is player %d!\r\n", (round - 1) % 2 + 1);
    // TODO: write winner_announcement to both players (hint: use write_to_players)

    return 0;
}
