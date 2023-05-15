#include "main.h"

/**
 * main - main function
 * @argc: length of argv
 * @argv: array of strings passed in the command-line
 * Return: Always 0 (Success) 
 */
int main(int ac, char **av)
{
    char *prompt = "$ ", *delim = " ";
    char *entry = NULL;
    size_t n = 0;
    ssize_t n_read;
    int i;

    (void) ac;

    while (1)
    {
        printf("%s", prompt);
        n_read = getline(&entry, &n, stdin);
         /* detecting EOF */
        if (n_read == -1)
        {
            printf("\n\nDisconnected...\n");
            return (0);
        }
        else
        {
            entry[n_read - 1] = '\0'; /* remove the trailing newline character from the last token */

            av = parsing_entry(entry, delim); /* splitting entry into array of strings */

            exec_fun(av); /* executing the first token */

            for (i = 0; av[i] != NULL; i++)
                free(av[i]);
            free(av);
        }
        free(entry);
        entry = NULL;
    }
    return (0);
}