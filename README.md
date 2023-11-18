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
- access (man 2 access)<br>
- chdir (man 2 chdir)<br>
- close (man 2 close)<br>
- closedir (man 3 closedir)<br>
- execve (man 2 execve)<br>
- exit (man 3 exit)<br>
- _exit (man 2 _exit)<br>
- fflush (man 3 fflush)<br>
- fork (man 2 fork)<br>
- free (man 3 free)<br>
- getcwd (man 3 getcwd)<br>
- getline (man 3 getline)<br>
- getpid (man 2 getpid)<br>
- isatty (man 3 isatty)<br>
- kill (man 2 kill)<br>
- malloc (man 3 malloc)<br>
- open (man 2 open)<br>
- opendir (man 3 opendir)<br>
- perror (man 3 perror)<br>
- read (man 2 read)<br>
- readdir (man 3 readdir)<br>
- signal (man 2 signal)<br>
- stat (__xstat) (man 2 stat)<br>
- lstat (__lxstat) (man 2 lstat)<br>
- fstat (__fxstat) (man 2 fstat)<br>
- strtok (man 3 strtok)<br>
- wait (man 2 wait)<br>
- waitpid (man 2 waitpid)<br>
- wait3 (man 2 wait3)<br>
- wait4 (man 2 wait4)<br>
- write (man 2 write)<br>
<hr>

### Tasks to be done:<br>
- [x] **handle the PATH**
- [x] **modified shell functions**
- [x] **Handle getline function**
- [x] **handle arguments for the built-in exit**
- [ ] **Handling memory leaks**
- [x] **using valgrind to chec errors**
