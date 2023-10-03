# CS 616: High Performance Computing

## Assignment 1: C++/OS Review

### Description

- For this assignment, you will build a simple shell program that will familiarize you with several
  Linux system calls (i.e. fork, execlp, wait etc.) and creating new processes.
- Your program should work as follows:
  - The program will prompt a user for a Linux command (i.e ls, pwd, touch, cat, etc.)
  - The program will create a new child process, fork(), and execute the command.
  - If the user enters, exit the program should terminate

### Requirements

- Develop using the text editor of your choice, but make sure your code runs correctly
  within Docker using g++.
- Feel free to use whatever textbooks or Internet sites you want to refresh your memory
  with C++ IO operations & system calls, just cite them in a README file turned in with
  your code. All code you write, of course, must be your own

### Contributors

- Ponthea Zahraii
  - 2366637
  - zahraii@chapman.edu

### Files

- main.cpp
- Makefile

### Execution Instructions

- make all
- ./assignment1.exe
- make realclean

### Workcited

- [Create Fork Processes](https://www.geeksforgeeks.org/create-processes-with-fork-in-cpp/)
- [Fork System Call](https://www.geeksforgeeks.org/fork-system-call/)
- [Child Process](https://stackoverflow.com/questions/69559422/how-can-i-create-a-child-process-from-a-command-line-input)
- [Execvp](https://www.digitalocean.com/community/tutorials/execvp-function-c-plus-plus)
- [Str to Char\*](https://stackoverflow.com/questions/26228723/converting-a-std-string-to-char-using-const-cast)
- [Waitpid](https://stackoverflow.com/questions/21248840/example-of-waitpid-in-use)
