#include "main.h"

/**
 * exec_fun - Executes the specified command with the given arguments.
 * @argv: The arguments array containing the command and its arguments.
 * Return: nothing
 */
void exec_fun(char **argv)
{
	char *command = NULL, *updated_command = NULL;
	int action;
	pid_t child_pid;

	if (argv)
	{
		command = argv[0];
		updated_command = build_path(command);
		if (updated_command != NULL)
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("fork");
				return;
			}
			else if (child_pid == 0)
			{
				check_builtin_command(argv);
				action = execute_command(updated_command, argv);
				exit(action);
			}
			else
			{
				wait_for_child(child_pid);
				if (isatty(STDIN_FILENO))
					free(updated_command);
			}
		}
		else
			not_found(argv[0], 1);
	}
}

/**
 * execute_command - Executes the command with the given arguments .
 * @command: The command to execute.
 * @argv: The arguments array.
 * Return: 0 on success, -1 on failure.
 */
int execute_command(const char *command, char **argv)
{
	int action;

	action = execve(command, argv, NULL);
	if (action == -1)
		perror("./shell");

	return (action);
}

/**
 * wait_for_child - Waits for the specified child process to finish.
 * @child_pid: The PID of the child process.
 * Return: nothing
 */
void wait_for_child(pid_t child_pid)
{
	int status;
	(void)child_pid;

	wait(&status);
}
