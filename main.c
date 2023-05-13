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

    (void)argc;
    (void)argv;

    printf("%s", prompt);
    getline(&lineptr, &n, stdin);

    free(lineptr);

    return (0);
}
