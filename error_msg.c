#include "main.h"
/**
 * not_found - Prints a "not found" error message.
 * @argv: The command that was not found.
 * @command_num: The command number.
 */
void not_found(char *argv, int command_num)
{
	char *shell_name;

	shell_name = _getenv("_");
	write(STDOUT_FILENO, shell_name, _strlen(shell_name));
	if (!shell_name)
		free(shell_name);

	write(STDOUT_FILENO, ": ", 2);

	write(STDOUT_FILENO, int_convert_string(command_num),
			_strlen(int_convert_string(command_num)));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, argv, _strlen(argv));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
}
/**
 * illegal_status - Prints an "illegal status" error message.
 * @argv: The argument causing the illegal status.
 * @command_num: The command number.
 */
void illegal_status(char *argv, int command_num)
{
	char *shell_name;

	(void)argv;

	shell_name = _getenv("_");
	write(STDOUT_FILENO, shell_name, _strlen(shell_name));
	if (!shell_name)
		free(shell_name);

	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, int_convert_string(command_num),
			_strlen(int_convert_string(command_num)));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "exit: Illegal number", 20);
	write(STDOUT_FILENO, "\n", 1);
}
