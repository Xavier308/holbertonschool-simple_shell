# Simple Shell Project

This project is our take on creating a simple UNIX command interpreter, inspired by the `sh` shell. We're working on this as part of our curriculum at Holberton School. It's all about exploring the fundamental concepts behind a shell environment.

## Authors

- Angel Velazquez Perez
- Xavier J. Cruz Santiago

## Description

The Simple Shell project is designed to replicate some of the basic functionalities of the traditional UNIX shell. This custom shell, called `hsh`, handles command execution and includes basic features such as handling the PATH and executing programs with arguments.

## Learning Objectives

By the end of this project, we should be able to explain:
- The design and implementation of the original Unix operating system by Ken Thompson and others.
- The creation and early developments of the UNIX shell.
- The workings of a shell, including process creation, file handling, and environment management.
- Execution of commands using `execve` and handling of the `PATH`.
- Differences between functions and system calls, process identifiers (pid and ppid), and the concept of EOF.

## Features

- Execution of commands in both interactive and non-interactive modes.
- Basic handling of the environment including execution path.
- Error handling similar to `sh` (e.g., command not found).
- Use of system calls where necessary.

## Installation

Clone the repository:

```shell
git@github.com:Xavier308/holbertonschool-simple_shell.git
```
Compile with:

```shell
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

```

## Usage
Run the shell in interactive mode:

```shell
./hsh
```
Run commands directly:

```shell
echo "/bin/ls" | ./hsh

```
## Example

Running the shell and executing commands:

```shell
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

## Bugs

This shell implementation is a learning exercise and may have bugs. It is not intended for full practical use.

## Acknowledgments

- Julien Barbier
- Spencer Cheng
- All peers at Holberton School who have provided feedback and suggestions.

