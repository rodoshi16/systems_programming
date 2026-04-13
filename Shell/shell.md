***Shell***

Shell lets you interact with computers OS using text commands. It is literally the bridge between you and the OS kernel. You can type commands and shell executes them. 

Graphical commands -> desktop environment -> terminal program -> shell

Print a command -> read a command -> parse the command and execute the command 


**Command line substitutions**

```
$i=3
$ echo $i
```

Shows what the shell expands to 

```
echo *.c
```

**To do math**

```
expr 4+1
i=`expr $i+1`

```

**Input with read**

```
read name
read x y
```

***Standard streams***
| FD | Name   | Default  |
| -- | ------ | -------- |
| 0  | stdin  | keyboard |
| 1  | stdout | screen   |
| 2  | stderr | screen   |


***Redirection***

```
command > file
command >> file


```

```
wc -l << END
line1
line2
END

```

***Access arguments****

$0: script name
$1: first argument
$2: second argument

#: number of arguments

***Shift command***

```
$1 $2 $3

```




