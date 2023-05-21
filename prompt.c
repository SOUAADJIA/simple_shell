#include "main.h"
/**
 * print_prompt - Print the shell prompt if the input is from a terminal.
 *
 * Return: void
 */
void print_prompt()
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
