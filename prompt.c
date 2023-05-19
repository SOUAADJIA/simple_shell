#include "main.h"

void print_prompt()
{
    if (isatty(STDIN_FILENO))
    {
        write(STDOUT_FILENO, "$ ", 2);
        fflush(stdout);
    }
}

ssize_t read_command(char **entry, size_t *n)
{
    ssize_t n_read;

    n_read = _getline(entry, n, stdin);

    return (n_read);
}