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
    char *lineptr = NULL;
    char *envp[] = {"/usr/bin", NULL};
    size_t n = 0;
    ssize_t num_read;
    int action;
    
    while (1)
    {
        printf("%s", prompt);
        num_read = getline(&lineptr, &n, stdin);
        if (num_read == -1)
        {
            printf("\n");
            return (-1);
        }
        action = execve(lineptr, argv, envp);
        if (action == -1)
           printf("%s: %d: %s: not found\n", argv[0], argc, lineptr); /***/
        
        free(lineptr);
        lineptr = NULL;
    }

    return (0);
}
