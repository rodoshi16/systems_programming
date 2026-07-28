***What are processes?***

Program - source code / compiled machine code

Process - running instance of the program. Includes machine code + information about current state of the process

When a program is loaded into memory, memory structure:

- Code
- Globals:  current values for variables
- Heap
- Unused
- Stack : what func were executing
- OS : additional state for process

A CPU can only run one process at a time but when you run tops you see its running multiple at the same time. How? 

The OS switches between processes very quickly (basically context switching). Whenever it switches, it needs to remember where it left off. Hence it uses a PCB. 


***Process control block***

Each process has a PCB. 

PID: process ID - unique number that identifies a processs
PC: program counter - stores the address of the next instruction it should execute
SP: stack pointer - stores top of the processe's stack

**Lifecyles of a processs**

- Running: currently running in the CPU and executing instructions
- Ready: process has everything it needs to run but waiting for CPU to be available
- Blocked: process cant continue yet because its waiting for something to happen



