
Inputs and outputs can be redirected. 
If you said 

```
scanf("%d/n", number)
printf("The number is %d\n", &number)

```

This will ask the user for input and print that on the screen. BUT if you wanted it redirect the input so it takes the number from a file, 

The file you get after compiling the previous code is a.out. We are redirecting the input from numbers file

>>> ./a.out < numbers.txt


Output redirection -> output will go to a file 

>>> ./a.out > output.txt