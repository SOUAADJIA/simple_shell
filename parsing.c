#include "main.h"

char **parsing_entry(char *entry, char *delim)
{
    char *token, *entry_copy;
    size_t n_tokens;
    char **av;
    int i;

    /* copy entry */
    entry_copy = malloc(sizeof(char) * (strlen(entry) + 1));
    if (!entry_copy)
    {
        perror("hsh: memory allocation error");
        exit(EXIT_FAILURE);
    }
    strcpy(entry_copy, entry);

    /* counting number of tokens in entry */
    token = strtok(entry, delim);
    n_tokens = 0;
    while (token != NULL)
    {
        n_tokens++;
        token = strtok(NULL, delim);
    }
    /* copy tokens into the array of strings */
    av = malloc(sizeof(char *) * (n_tokens + 1));
    if (!av)
    {
        perror("hsh: memory allocation error");
        exit(EXIT_FAILURE);
    }
    token = strtok(entry_copy, delim);

    for (i = 0; token != NULL; i++)
    {
        av[i] = malloc(sizeof(char) * strlen(token));
        strcpy(av[i], token);

        token = strtok(NULL, delim);
    }
    av[i] = NULL;
    free(token);
    free(entry_copy);

    return (av);
}
