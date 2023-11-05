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
<hr>
### Functions and System Calls
- `access` ([man 2 access](https://linux.die.net/man/2/access))
- `chdir` ([man 2 chdir](https://linux.die.net/man/2/chdir))
- `close` ([man 2 close](https://linux.die.net/man/2/close))
- `closedir` ([man 3 closedir](https://linux.die.net/man/3/closedir))
- `execve` ([man 2 execve](https://linux.die.net/man/2/execve))
- `exit` ([man 3 exit](https://linux.die.net/man/3/exit))
- `_exit` ([man 2 _exit](https://linux.die.net/man/2/_exit))
- `fflush` ([man 3 fflush](https://linux.die.net/man/3/fflush))
- `fork` ([man 2 fork](https://linux.die.net/man/2/fork))
- `free` ([man 3 free](https://linux.die.net/man/3/free))
- `getcwd` ([man 3 getcwd](https://linux.die.net/man/3/getcwd))
- `getline` ([man 3 getline](https://linux.die.net/man/3/getline))
- `getpid` ([man 2 getpid](https://linux.die.net/man/2/getpid))
- `isatty` ([man 3 isatty](https://linux.die.net/man/3/isatty))
- `kill` ([man 2 kill](https://linux.die.net/man/2/kill))
- `malloc` ([man 3 malloc](https://linux.die.net/man/3/malloc))
- `open` ([man 2 open](https://linux.die.net/man/2/open))
- `opendir` ([man 3 opendir](https://linux.die.net/man/3/opendir))
- `perror` ([man 3 perror](https://linux.die.net/man/3/perror))
- `read` ([man 2 read](https://linux.die.net/man/2/read))
- `readdir` ([man 3 readdir](https://linux.die.net/man/3/readdir))
- `signal` ([man 2 signal](https://linux.die.net/man/2/signal))
- `stat (__xstat)` ([man 2 stat](https://linux.die.net/man/2/stat))
- `lstat (__lxstat)` ([man 2 lstat](https://linux.die.net/man/2/lstat))
- `fstat (__fxstat)` ([man 2 fstat](https://linux.die.net/man/2/fstat))
- `strtok` ([man 3 strtok](https://linux.die.net/man/3/strtok))
- `wait` ([man 2 wait](https://linux.die.net/man/2/wait))
- `waitpid` ([man 2 waitpid](https://linux.die.net/man/2/waitpid))
- `wait3` ([man 2 wait3](https://linux.die.net/man/2/wait3))
- `wait4` ([man 2 wait4](https://linux.die.net/man/2/wait4))
- `write` ([man 2 write](https://linux.die.net/man/2/write))
<hr>
###Tasks to be done:<br>
**handle the PATH**
