# Simple SHELL
<hr>
<img src="https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg">

## Your shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
## But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
### Our SHELL should:
`->Display a prompt and wait for the user to type a command. A command line always ends with a new line.`<br>
`->The prompt is displayed again each time a command has been executed.`<br>
`->The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.`<br>
`->The command lines are made only of one word. No arguments will be passed to programs.`<br>
`->If an executable cannot be found, print an error message and display the prompt again.
Handle errors.`<br>
`->Handles the “end of file” condition (Ctrl+D)`<br>

