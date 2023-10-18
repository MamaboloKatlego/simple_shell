#Simple Shell Project

#Description

A Shell is a user interface that provides an interactive way a user can interact with the operating system. This Shell Project is a simple Unix-like command-line shell implementation written in the C programming language, the aim is intended to provide a primary know-how of how a shell works and serves as a start line for gaining knowledge of running structures standards. The Shell can executes various commands entered by the user including system commands.

#Requirements

Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
Your shell should not have any memory leaks
No more than 5 functions per file
All your header files should be include guarded
Use system calls only when you need to (why?)
Write a README with the description of your project
You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository.

#To compile it using the following command:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

When done, Shell can run in an interactive mode:
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit

Shell can also run in non-interactive mode:
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

#Author(s)

Mamabolo Katlego
(https://github.com/MamaboloKatlego)
