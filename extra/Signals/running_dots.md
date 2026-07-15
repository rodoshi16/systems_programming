***Seeing signals in action***

dots.c is a simple program which prints dots continuously. 

**How do we compile this?**

C is a compiled language not an interpreted one. The compiler needs to turn code into machine instructions first. 

```
    gcc -Wall -o dots dots.c
```

-gcc : compiler which turns your code into low level CPU instructions
- Wall: show all warnings
-o dots: output file name will be dots
- dots.c: input file 

Return: executable binary file called dots

This contains machine code, CPU instructions your computer can execute

To run this executable file:

```
./dots.c
```

- When the shell sees this, it gets the command to run the executable file. 
- OS loads the program into memory, sets up a process and CPU executes instructions. 



