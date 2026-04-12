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

