#include "main.h"

void is_exit(char *token)
{
    if (strcmp("exit", token) == 0)
    {
        exit(EXIT_SUCCESS);
    }
}

void is_env(char **argv)
{
    char **env_var;

    if ((strcmp("env", argv[0]) == 0) && (argv[1] == NULL))
    {
        for (env_var = environ; *env_var != NULL; env_var++)
        {
            write(STDOUT_FILENO, *env_var, strlen(*env_var));
            write(STDOUT_FILENO, "\n", 1);
        }
    }
}