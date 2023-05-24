#include "main.h"
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

	if (n_read == 0) /* Check if there are no bytes left to read */
	{
		n_read = read(fileno(stream), buff, BUFFER_SIZE);
		if (n_read == 0) /* detecting EOF */
		{
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		if (n_read == -1)
		{
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	if (!*lineptr || (*n == 0))
	{
		*lineptr = malloc(n_read * sizeof(char));
		if (!*lineptr)
			return (-1);
		*n = n_read;
	}
	for (i = 0; i < n_read; i++)
		(*lineptr)[i] = buff[i];
	n_read = 0;
	return (i);
}
