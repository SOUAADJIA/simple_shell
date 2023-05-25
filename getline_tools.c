#include "main.h"

/**
 * refill_buffer - Refill the buffer by reading from the stream.
 * @n_read: Pointer to the number of bytes read in the buffer.
 * @buff: Buffer to store the read data.
 * @stream: The stream to read from.
 * Return: The number of bytes read, or -1 on failure.
 */
ssize_t refill_buffer(ssize_t *n_read, char *buff, FILE *stream)
{
	*n_read = read(fileno(stream), buff, BUFFER_SIZE);
	return (*n_read);
}

/**
 * find_line_length - Find the length of the line in the buffer.
 * @buff: Buffer containing the data.
 * @n_read: Number of bytes read in the buffer.
 * @pos: Current position in the buffer.
 * Return: The length of the line, or 0 if no newline found.
 */
ssize_t find_line_length(char *buff, ssize_t n_read, ssize_t pos)
{
	ssize_t line_len = 0;
	ssize_t i;

	for (i = pos; i < n_read; i++)
	{
		if (buff[i] == '\n')
		{
			line_len = i - pos + 1;
			break;
		}
	}
	return (line_len);
}

/**
 * should_resize_buffer - Check if the buffer needs to be resized.
 * @lineptr: Pointer to the buffer storing the read line.
 * @n: Size of the buffer.
 * @line_len: Length of the line to be stored.
 * Return: 1 if the buffer needs to be resized, 0 otherwise.
 */
int should_resize_buffer(char **lineptr, ssize_t n, ssize_t line_len)
{
	return (!*lineptr || n < line_len + 1);
}

/**
 * resize_buffer - Resize the buffer to accommodate the line.
 * @lineptr: Pointer to the buffer storing the read line.
 * @n: Pointer to the size of the buffer.
 * @line_len: Length of the line to be stored.
 * Return: 0 on success, -1 on failure.
 */
ssize_t resize_buffer(char **lineptr, ssize_t *n, ssize_t line_len)
{
	ssize_t new_size = *n + line_len + 1;
	char *new_buff = malloc(new_size * sizeof(char));

	if (!new_buff)
		return (-1);
	if (*lineptr)
	{
		memcpy(new_buff, *lineptr, *n);
		free(*lineptr);
	}
	*lineptr = new_buff;
	*n = new_size;
	return (0);
}

/**
 * copy_line_to_buffer - Copy the line from the buffer to the lineptr.
 * @lineptr: Pointer to the buffer storing the read line.
 * @buff: Buffer containing the data.
 * @pos: Current position in the buffer.
 * @line_len: Length of the line to be copied.
 */
void copy_line_to_buffer(char **lineptr, char *buff, ssize_t pos,
ssize_t line_len)
{
	ssize_t i;

	for (i = 0; i < line_len; i++)
	{
		(*lineptr)[i] = buff[pos + i];
	}
	(*lineptr)[line_len] = '\0';
}
