***Select***

In most programs, using read() or write() will block and stop the program execution until that operation is complete. 

If you are handling multiple tasks like waiting for data, handling user input - you cannot stop everything just for one task. 

**select()** - 

- watch multiple file descriptors at once
- sleep until at least one is ready
- avoid blocking on the wrong one 


```
int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout); 
```

- nfds: how many file descriptor to check
- *readfds : which fds you wanna read from
- *writefds: which fds you wanna write to 
- exceptfds: error conditions
- timeval: how long to wait 

***Macros you must know***

- FD_ZERO(&set): clear set
- FD_SET(fd, &set): add set
- FD_CLR(fd, &set): remove fd
- FD_ISSET(fd, &set): check membership 

***What does select return?***

- -1: error
- 0: timeout
- greater than 0: number of ready fds


Code sample1:  We clear set, add fd1 and fd2, find the max and see which fds are ready

```
fd_set read_fds;

FD_ZERO(&read_fds);
FD_SET(fd1, &read_fds);
FD_SET(fd2, &read_fds);

int maxfd = (fd1 > fd2 ? fd1 : fd2) + 1;

int ready = select(maxfd, &read_fds, NULL, NULL, NULL);

```

After select(): check membership of the fds in the set 

```

if (FD_ISSET(fd1, &read_fds)) {
    read(fd1, buf, ...);
}

if (FD_ISSET(fd2, &read_fds)) {
    read(fd2, buf, ...);
}


```


***Timeout***

```

struct timeval tv; 
tv.tv_sec = 5; 
tv.tv_usec = 0; 

select(maxfd, &read_fds, NULL, NULL, &tv);

```






