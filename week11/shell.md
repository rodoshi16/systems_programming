>>> echo hello 
hello 

//all the files which end in .c it will echo
>>> echo *.c 

//note that ? is a special char in shell
>>> echo Are you ok'?'

Command line sub

>>> i=3
>>> echo $i
3

>>> echo i would like $i internships

>>> i=i+1
>>> echo $i

Shell doesn't recognize + sign or any math operations - use expr

>>> expr 4 + 1

Backquote - used to substitude values in expression

>>> i='expr 4+1'

To get input from the console - use read 

If theres more input than variables - last one gets it call

>>>read x y 
foo bar baz
>>> echo $x
foo
>>> echo $y
bar baz

NOTE THAT SPECIAL CHARACTERS NEED \ SYMBOL LIKE 

area=`expr $width \* $height`

HOW WOULD YOU KNOW THE EXIT STATUS OF YOUR LAST PROGRAM - $?

>>> cat file
>>> echo $?
0 

(because the last program was a success, if it was not, it would be non zero exit value )

```



```


