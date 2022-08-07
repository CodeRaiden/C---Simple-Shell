# Kenneth Igbo and Ayomide Ibitoye

![alt text](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg)

### Description

Kenneth Igbo and Ayomide Ibitoye Shell is a simple UNIX command interpreter that replicates functionalities of the simple shell (sh). Additional functions are also included. This program was written entirely in C as a milestone project for ALX SE programme.

### Installation

Clone this repository into your working directory. For best results, files should be compiled with GCC and the following flags: -Wall -Wextra -Werror -pedantic -Wno-format.

### Usage

After compilation, the resulting program can run stand-alone, either in interactive or non-interactive mode.

#### Interactive Mode

In interactive mode, simply run the program and wait for the prompt to appear. From there, you can type commands freely, exiting with either the "exit" command or ctrl-D.

#### Non-Interactive Mode

In non-interactive mode, echo your desired command and pipe it into the program like this:

```sh
echo "ls" | ./shell
```

In non-interactive mode, the program will exit after finishing your desired command(s).


#### Outside Programs

Our shell can run outside programs by typing their absolute paths (/bin/ls) or the executable name (ls), IF their directory is included in the PATH.

### Examples

```sh
$ ls -l
total 8
drwxrwxr-x 1 root root Apr 2 13:23 directory_1
drwxrwxr-x 2 root root Apr 2 20:30 directory_2
```

```sh
$ /bin/pwd
/home/root/shell
```

```sh
$ hello world
./hsh: 1: hello: not found
```

```sh
$ help env
env: env
	Print the environment.
```

