#include "main.h"

void print_prompt()
{
    write(1, "$ ", 2);
}

ssize_t read_command(char **entry, size_t *n)
{
    ssize_t n_read;

    n_read = getline(entry, n, stdin);

    return (n_read);
}