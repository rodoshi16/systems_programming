***Signals***

Signals are notifications that are sent to a process and they can either be handled, blocked or ignored. 

ps aux: 

- ps: process status
- aux: show process from all users, show detailed info and include processes not attached to a terminal

Overall: it prints a snapshot of everything currently running on your system. 


> kill -STOP 3819
> kill -CONT 3819

Ex:

- SIGINT: when you press ctrl+C in the terminal, it kills the process in the terminal
- SIGTERM: sent to process when user wants to ask it to terminate
- SIGKILL: forced kill (cannot be ignored)
- SIGSTOP: suspend a process (also cannot be ignored)
- SIGCHILD: signal sent to parent process when a child changes state (exits or stops)
- SIGPIPE: when you try to write to a pipe that has no readers kernel sends the signal to the process
- SIGFPE: when a program does illegal arithmetic, CPU will generate this
- SIGSEGV: process tries to acess invalid memory 


***What happens when a signal is sent?***

Sigaction is a system call which lets you define custom behaviour for when certain signals are received. It will modify the Process Control Table. 


int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact); 

- signum: the number of the signal being modified 
- *act: pointer to a struct we need to initialize before we call sigaction
- oldact: pointer to a struct 

```
sigaction(SIGINT, &sa, NULL)
```

- when SIGINT happens, check PCB for custom handler and run that. 



Handler function will dictate what to do:

```
void handler(int sig) {
    write(STDOUT_FILENO, "caught signal\n", 14);
}
```

Here is a struct of a sigaction. We have a pointer to the handler function. sa_mask: set of signals that will be blocked during execution. sa_flag: set of flags that modify how the signal is handled. restorer: pointer to a function that is used to restore the state of the process after the signal handler is finished. 

```
struct sigaction {
    void (*sa_handler)(int);  
    void (*sa_sigaction)(int, siginfo_t *, void *); 
    sigset_t sa_mask;
    int sa_flags;
    void (*sa_restorer)(void);
};
```

SIGKILL and SIGSTOP cannot be handled using sigaction. Sending signals DOES require OS to do work. 

For sending signals, it usually uses the Kill system call which is provided by the OS. 

**Information about signals and processes**

1. Any process (with permission) can send a signal to any other process using its PID. 
2. A signal can be sent by OS or a user process. 
3. The kill program is used to terminate a process and send a signal to a process. 
4. Signals can arrive at any time, you cannot always control them 

