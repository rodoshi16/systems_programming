***Sockets***

A communication endpoint for processes. When processes want to communicate across a network, they do so using sockets. 

- local process
- remote process

Each machine on a network is identified by its IP address. 

***IP Adress?***

Unique ID assigned to every device connected to a network. It can identify the host or device and tell the network wher eto send data. 

- IPv4: 192.168.1.42 (32 bits)

***What is a port?***

Port - a 16 bit integer which identifies a socket. 

Think of IP addressess as house address and ports as door numbers. 

***How to set up a socket?***

Server does this:

- create a socket fd (socket())
- attach to a port (bind:80)
- mark as a listener listen()

accept(): block and wait for a connection request

A client also creates a socket to connect to the server:

- socket()
- connect(192.168.1.42:80) // blocks and waits un-
til the server accepts


The client will use this socket to send data to the server and/or to receive
data from

***What is a 3way handshake?***

Before you start your meeting, you always confirm if the person can hear you on zoom and if you can hear them. Same thing. 

client to server: can you hear me?
server to client: i can hear you, can u hear me?
client to server: yes i can 

All set. 

This creates a new connected socket to communicate with the client. 

Client set up framework:

1. Create socket
2. Fill server address
3. Get server IP from hostname
4. Connect 
5. Read/write 

```
// Step 1: Create socket
int soc = socket(AF_INET, SOCK_STREAM, 0);

// Step 2: Fill server address
struct sockaddr_in server;
server.sin_family = AF_INET;
server.sin_port = htons(PORT);     // htons() REQUIRED
memset(&server.sin_zero, 0, 8);

// Step 3: Get server IP from hostname
struct addrinfo *ai;
getaddrinfo("teach.cs.toronto.edu", NULL, NULL, &ai);
server.sin_addr = ((struct sockaddr_in *)ai->ai_addr)->sin_addr;

// Step 4: Connect
connect(soc, (struct sockaddr *)&server, sizeof(server));

// Step 5: Read/write
write(soc, "hello\r\n", 7);
read(soc, buf, sizeof(buf));
```

