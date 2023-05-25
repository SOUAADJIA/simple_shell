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
ssize_t read_command(char **entry, ssize_t *n)
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
ssize_t _getline(char **lineptr, ssize_t *n, FILE *stream)
{
	static ssize_t n_read;
	static ssize_t pos;
	static char buff[BUFFER_SIZE];
	ssize_t line_len;

	if (should_refill_buffer(&n_read, pos))
	{
		if (refill_buffer(&n_read, buff, stream) <= 0)
			return (-1);
		pos = 0;
	}

	line_len = find_line_length(buff, n_read, pos);

	if (line_len == 0)
		line_len = n_read - pos;

	if (should_resize_buffer(lineptr, *n, line_len))
	{
		if (resize_buffer(lineptr, n, line_len) == -1)
			return (-1);
	}

	copy_line_to_buffer(lineptr, buff, pos, line_len);

	pos += line_len;

	return (line_len);
}

/**
 * should_refill_buffer - Check if the buffer needs to be refilled.
 * @n_read: Pointer to the number of bytes read in the buffer.
 * @pos: Current position in the buffer.
 * Return: 1 if the buffer needs to be refilled, 0 otherwise.
 */
int should_refill_buffer(ssize_t *n_read, ssize_t pos)
{
	return (*n_read <= 0 || pos >= *n_read);
}
