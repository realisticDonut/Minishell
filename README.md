# Minishell
This project simulates the functionality of the unix Bash shell.

## Description
The project aim was to recreate the functionality of the unix Bash shell on a smaller scale.
It is part of the obligatory projects at the [42-Heilbronn](https://www.42heilbronn.de/en/) coding school in Heilbronn, Germany.
## Features
The following functionality is included:
- Execution of executables: Executables are first searched for in the $PATH environment variable. If nothing is found, the relative/absolute path is used to search for the executable. Example: "ls -la" or "minishell"
- Redirections: Using "<", "<<", ">", or "<<", the input and output can be redirected if the commands and files are valid.
 *Example:* **Input:** echo hello > out.txt **Behavior:** The output of "echo hello" is written into the file "out.txt".     The file is created if it does not       exist. An error is shown if the user does not have the neccessary access rights   for the file.*
- Pipes: Using "|", the output of one command can be piped to the input of the next.                      
  *Example:* **Input:** echo hello | grep h **Behavior:** The output of the command "echo hello" is used as the input of      the command "grep h". "hello" will be printed to the standard output.
- Environment variables: Environment variables with the prefix '$' are expanded to their corresponding values.    
  *Example:* **Input:** echo $PATH **Behavior:** The value of the environment value "PATH" is written to the standard       output.
- 
