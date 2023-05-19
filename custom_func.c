#include "main.h"

#define BUFFER_SIZE 1024

/* test getline */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    static ssize_t n_read = 0;
    static char buff[BUFFER_SIZE];
    ssize_t i;

    if (n_read == 0)
    {
        n_read = read(fileno(stream), buff, BUFFER_SIZE);

        /* detecting EOF */
        if (n_read == 0)
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