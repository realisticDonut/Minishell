# Minishell
This project simulates the functionality of the unix Bash shell.

## Description
The project aim was to recreate the functionality of the unix Bash shell on a smaller scale.
It is part of the obligatory projects at the [42-Heilbronn](https://www.42heilbronn.de/en/) coding school in Heilbronn, Germany.
*Project Rules:* The following functions were allowed, any function not included in this list was forbidden:
```
readline, rl_clear_history, rl_on_new_line,
rl_replace_line, rl_redisplay, add_history,
printf, malloc, free, write, access, open, read,
close, fork, wait, waitpid, wait3, wait4, signal,
sigaction, kill, exit, getcwd, chdir, stat,
lstat, fstat, unlink, execve, dup, dup2, pipe,
opendir, readdir, closedir, strerror, perror,
isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr,
tcgetattr, tgetent, tgetflag, tgetnum, tgetstr,
tgoto, tputs
```
## Features
The following functionality is included:
- Execution of executables: Executables are first searched for in the $PATH environment variable. If nothing is found, the relative/absolute path is used to search for the executable.
  >*Example:* "ls -la" or "minishell"
- Redirections: Using "<", "<<", ">", or "<<", the input and output can be redirected if the commands and files are valid.
  >*Example:* **Input:** echo hello > out.txt **Behavior:** The output of "echo hello" is written into the file "out.txt".     The file is created if it does not       exist. An error is shown if the user does not have the neccessary access rights   for the file.*
- Pipes: Using "|", the output of one command can be piped to the input of the next.                      
  >*Example:* **Input:** echo hello | grep h **Behavior:** The output of the command "echo hello" is used as the input of      the command "grep h". "hello" will be printed to the standard output.
- Environment variables: Environment variables with the prefix '$' are expanded to their corresponding values.    
  >*Example:* **Input:** echo $PATH **Behavior:** The value of the environment value "PATH" is written to the standard       output.
- Exit Status: "$?" expands to the exit status of the most recently executed foreground pipeline.                
  >*Example:* **Input** echo $? **Behavior** The exit code of the last executed pipeline command is printed to the standard   output
- ctrl-C, ctrl-D, ctrl-\: See Bash behavior
- Quotes: Quote interpretation is close to the original behavior in bash                                  
  >*Example:* **Input** echo 'hello $PATH' **Behavior** Due to the single quotes, the $PATH variable is interpreted as a     string, not as an environment variable. "hello $PATH" is written to the standard output.
- Builtins: The following functions were reprogrammed from scratch and are builtin in the minishell. This means they are   always available and independent from the $PATH variable:
  - echo with option -n
  - cd with only a relative or absolute path
  - pwd with no options
  - export with no options
  - unset with no options
  - env with no options or arguments
  - exit with no options
 
## Technologies
 - Programming language: C (C11)
## Usage
### Prerequisites
- Must be a Unix-based system. Please note: Depending on your build, you might get problems during compilation or         execution. Code was tested in Linux 5.11.0-43-generic
- The Readline library must be installed.
  ```
  sudo apt-get install libreadline6 libreadline6-dev
  ```
- GNU Make must be installed
  ```
  sudo apt-get install make
  ```
### Compilation and execution
- Clone the repository to your system
- Navigate to the /minishell directory in the terminal
- execute the ``` make ``` command
- execute the minishell with ```./minishell```
- Input commands just like in the original Bash

