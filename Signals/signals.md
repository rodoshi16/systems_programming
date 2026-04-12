***Signals***

Signals are notifications that are sent to a process and they can either be handled, blocked or ignored. 

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

Sigaction is a system call which lets you define custom behaviour for when certain signals are received.

Hander fuction will dictate what to do:

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
