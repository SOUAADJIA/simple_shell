#include "main.h"

void print_prompt(char *prompt)
{
    printf("%s", prompt);
}

ssize_t read_command(char **entry, size_t *n)
{
    ssize_t n_read;

    n_read = getline(entry, n, stdin);

    return (n_read);
}