#include "main.h"
/**
 * is_exit - Checks if the given token is "exit" and handles the exit status
 * @token: The token to check if it is "exit".
 * @status: The optional argument for the exit status.
 * Return: nothing
 */
void is_exit(char *token, char *status)
{
	int exit_arg;
	size_t i, length;

	if (_strcmp("exit", token) == 0)
	{
		/* Check if an argument (status) is provided */
		if (status == NULL)
		{
			exit(0); /* No status argument provided, exit with status 0 */
		}
		else
		{
			/* check if status argument contains only digits */
			length = _strlen(status);
			for (i = 0; i < length; i++)
			{
				if (!_isdigit(status[i]))
				{
					perror("./shell");
					return;
				}
			}
			/* Convert the status argument to an integer */
			exit_arg = _atoi(status);
			exit(exit_arg);
		}
	}
}
/**
 * is_env - Checks if is "env" and prints the environment variables.
 * @argv: The arguments array containing the command and optional arguments.
 * Return: nothing
 */

void is_env(char **argv)
{
	char **env_var;

	if ((_strcmp("env", argv[0]) == 0) && (argv[1] == NULL))
	{
		for (env_var = environ; *env_var != NULL; env_var++)
		{
			write(STDOUT_FILENO, *env_var, _strlen(*env_var));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
}
/**
 * change_directory - Change the current working directory.
 *
 * @path: The path of the directory to change to.
 *
 * This function changes the current working directory to the specified path.
 * It also updates the PWD environment variable with the new working directory.
 * If an error occurs during the process, an error message is printed.
 */
void change_directory(const char *path)
{
	char cwd[BUFFER_SIZE];

	/* Get the current working directory */
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("cd: Failed to get current working directory");
		return;
	}

	/* Update the PWD environment variable */
	if (setenv("PWD", cwd, 1) != 0)
	{
		perror("cd: Failed to update PWD environment variable");
		return;
	}

	/* Change the directory */
	if (chdir(path) != 0)
	{
		perror("cd: Failed to change directory");
		return;
	}
}


