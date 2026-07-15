***Buffers in networking***

Buffers are used to temporarily store data as it travels between sender and receiver. Buffers exist in:

- user space: memory space where the application runs
- kernel space: managed by the operating system and acts as a middleman that handles actual data transmission. 

*Data flow*:

Sender Side:
User Space (your app) → User Buffer → send() → Kernel Space → Kernel Send Buffer → Network

Receiver Side:
Network → Kernel Receive Buffer → recv() → Kernel Space → User Buffer → User Space (your app)


***Socket connection functions***

int socket(int domain, int type, int protocol):

- creates a new socket


int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)

- associates a local IP address and port number with sockfd

int listen(int sockfd, int backlog)

- marks a sockfd as a listening socket 

int accept(int sockfd, struct sockaddr *addr, sockelen_t *addrlen)

- blocks untol a client requests to connect 

int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)

- initiates a connection to addr 

ssize_t send(int sockfd, const void *buf, size_t len, int flags)

- copies up tp len bytes from buf into the sockets send buffer

ssize t recv(int sockfd,
void *buf, size t len, int flags)

- reads up to len bytes from the socket into buf, blocks until data is available

int close(int sockfd)

- closes the socket fd  

Example framework:

1. Create a socket
2. Fill address struct 
3. Bind socket to address
4. Listen for connections
5. Accept loop 



```
int sfd = socket(AF_INET, SOCK_STREAM, 0); 

struct sockaddr_in server;
server.sin_family = AF_INET;
server.sin_port = htons(PORT);
server.sin_addr.s_addr = INADDR_ANY;
memset(&server.sin_zero,0,8); 

listen(sfd, 5); 

while (1) {
    struct sockaddr_in client;
    unsigned int len = sizeof(client)
    int cfd = accept(sfd, (struct sockaddr *)&client, &len); 
}

 char buf[256];
    int n = read(cfd, buf, sizeof(buf));
    write(cfd, buf, n);   // echo back
    close(cfd);           // done with this client

```


***Example***

Lets say you are building an application where you communicate over a network and send messages between client and server. TCP doesn't always gurantee that you will get the full message in one go. 

TCP doesn't know when one message ends and another begins. It doesn't add boundaries to your messages - just a flow of data. You might get the data in chunks. 

*A buffer* is used to accumulate all the data you receive until you have enough to form a full message. 


1. keep reading until you get a full message
2. Scan for message terminator
3. Process the message
4. Shift remaining data





