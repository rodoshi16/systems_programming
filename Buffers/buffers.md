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






