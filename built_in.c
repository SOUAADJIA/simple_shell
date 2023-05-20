#include "main.h"

int is_exit(char *token)
{
	char *status_arg;
	int status;
    if (strcmp("exit", token) == 0)
    {
        /*Check if an argument (status) is provided*/
        status_arg = strtok(NULL, " ");
        status = 0;

        /* Convert the status argument to an integer*/
        if (status_arg != NULL)
            status = atoi(status_arg);

        exit(status);
    }
    return (0);
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
