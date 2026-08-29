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

if <statement>
    echo 
else 
    echo 
fi 

```

lt - less than 
>>> test 2 -lt 3


Test comparison operators:

- lt: less than
- gt: greater than
- ne: not equal to 
- le: less than or equal to 
- ge: greater than or equal to 

-f: file 
-d: directory 
-s: plain file size zero

```

while test $i -lt 10
do 
    i=`expr $i+1`
done



```

while read x y 
do 
    echo x is $x and y is $y
done

```

```

while grep Q file
do 
    (echo ld; echo w) | ed -file
done
$

```

if $x -gt 10 && $x -lt 100


if foo
then 
    bar1
elif foo2
then 
    bar2
else
    bar3
fi

NOTE: YOU NEED A TEST BEFORE ANY OF THESE -LT GT

test $temp -gt 0

In test, the boolean and symbol is -a

/dev/null - special provided by Unix to discard data 

If theres output we want to discard, we redirect it to dev/null

