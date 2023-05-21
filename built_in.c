#include "main.h"

void is_exit(char *token, char *status)
{
    int exit_arg;
    size_t i, length;

    if (strcmp("exit", token) == 0)
    {
        /* Check if an argument (status) is provided */
        if (status == NULL)
        {
            exit(0); /* No status argument provided, exit with status 0 */
        }
        else
        {
            /* check if status argument contains only digits */
            length = _strlen(status);
            for (i = 0; i < length; i++)
            {
                if (!_isdigit(status[i]))
                {
                    perror("./shell");
                    return;
                }
            }
            /* Convert the status argument to an integer */
            exit_arg = atoi(status);
            exit(exit_arg);
        }
    }
}

void is_env(char **argv)
{
    char **env_var;

    if ((strcmp("env", argv[0]) == 0) && (argv[1] == NULL))
    {
        for (env_var = environ; *env_var != NULL; env_var++)
        {
            write(STDOUT_FILENO, *env_var, _strlen(*env_var));
            write(STDOUT_FILENO, "\n", 1);
        }
    }
}
