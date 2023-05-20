#include "main.h"

void exec_fun(char **argv)
{
    char *command = NULL, *updated_command = NULL;
    int action;
    pid_t child_pid;

    if (argv)
    {
        command = argv[0];
        /* generate the path to this command before passing it to execve */
        updated_command = build_path(command);
        if (updated_command != NULL)
        {
            child_pid = fork();
            if (child_pid == -1)
            {
                perror("fork");
                return;
            }
            else if (child_pid == 0)
            {
                action = execve(updated_command, argv, NULL);
                if (action == -1)
                    perror("./shell");
                exit(EXIT_FAILURE); /*Child process exits after execution or on failure*/
            }
            else
            {
                int status;

                wait(&status); /* Parent process waits for the child to finish*/
            }
        }
        else
        {
            perror("./shell");
        }
    }
}
