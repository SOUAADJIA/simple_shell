#include "main.h"

/**
 * main - main function
 * @argc: length of argv
 * @argv: array of strings passed in the command-line
 * Return: Always 0 (Success) 
 */

int main(int argc, char **argv)
{
    char *prompt = "Sshell $ ";
    char *lineptr;
    size_t n = 0;
    ssize_t num_read;

    (void)argc;
    (void)argv;

    while (1)
    {
        printf("%s", prompt);
        num_read = getline(&lineptr, &n, stdin);
        if (num_read == -1)
            return (-1);

        printf("%lu, %s\n", num_read, lineptr); /***/
        
        free(lineptr);
    }

    return (0);
}
