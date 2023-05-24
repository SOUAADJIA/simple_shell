#include "main.h"

/**
 * print_prompt - Print the shell prompt if running in interactive mode.
 * Return: void
 */
void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);
	}
}

/**
 * read_command - Read a command from the standard input.
 *
 * @entry: Pointer to the buffer storing the read command.
 * @n: Pointer to the size of the buffer.
 *
 * Return: The number of bytes read, or -1 on failure.
 */
ssize_t read_command(char **entry, size_t *n)
{
	ssize_t n_read;

	n_read = _getline(entry, n, stdin);

	return (n_read);
}

/**
 * _getline - Read a line from the specified stream.
 * @lineptr: Pointer to the buffer storing the read line.
 * @n: Pointer to the size of the buffer.
 * @stream: The stream to read from.
 * Return: The number of bytes read, or -1 on failure.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t n_read;
	static char buff[BUFFER_SIZE];
	ssize_t i;

	if (n_read <= 0) /* Check if there are no bytes left to read */
	{
		n_read = read(fileno(stream), buff, BUFFER_SIZE);
		if (n_read == 0) /* Detecting EOF */
		{
			return (-1); /* Indicate EOF */
		}
	}
	if (!*lineptr || (*n == 0))
	{
		*lineptr = malloc((n_read + 1) * sizeof(char));
		if (!*lineptr)
			return (-1);
		*n = n_read + 1;
	}
	for (i = 0; i < n_read; i++)
		(*lineptr)[i] = buff[i];
	(*lineptr)[i] = '\0'; /* Add null terminator at the end */
	n_read = 0;
	return (i);
}
