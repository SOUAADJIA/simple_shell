#include "main.h"
/**
 * check_builtin_command - Check if the command is a built-in command.
 * @av: The array of strings representing the command and its arguments.
 */
void check_builtin_command(char **av)
{
	if (av == NULL || av[0] == NULL)
		return;

	if (_strcmp(av[0], "env") == 0)
		execute_env_command(av);
	else if (_strcmp(av[0], "exit") == 0)
		execute_exit_command(av[1]);
	else if (_strcmp(av[0], "cd") == 0)
		execute_cd_command(av);
}
/**
 * execute_env_command - Execute the "env" built-in command.
 * @av: The array of strings representing the command and its arguments.
 */
void execute_env_command(char **av)
{
	is_env(av);
}

/**
 * execute_exit_command - Execute the "exit" built-in command.
 * @av: The exit argument (optional).
 */
void execute_exit_command(char *av)
{
	is_exit("exit", av);
}
/**
 * execute_cd_command - Execute the "cd" built-in command.
 * @av: The array of strings representing the command and its arguments.
 */
void execute_cd_command(char **av)
{
	if (av[1] == NULL)
	{
		perror("cd: No directory specified");
		return;
	}

	change_directory(av[1]);
}
