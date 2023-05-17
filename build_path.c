#include "main.h"

char *build_path(char *command) 
{
    char *path_command, *path_command_copy, *path_token, *file_path;
    int command_len, directory_len;
    struct stat buffer;
    char **env;

    for (env = environ; *env != NULL; env++) 
    {
        if (strncmp(*env, "PATH=", 5) == 0)
        {
            path_command = *env + 5;/*check after the PATH= */
            path_command_copy = strdup(path_command);
            command_len = strlen(command);

            /* break down the path variable and get all the directories */
            path_token = strtok(path_command_copy, ":");

            while (path_token != NULL)
            {
                /* Get the length of the directory */
                directory_len = strlen(path_token);
                /* Allocate memory to store the command name + the directory name */
                file_path = malloc(sizeof(char) * (command_len + directory_len + 2)); /*  2 for / and \0 */
                if (!file_path)
                {    
                    perror("./shell");
                    return (NULL);
                }
                /* Copy the directory path + concatenate the command */
                strcpy(file_path, path_token);
                strcat(file_path, "/");
                strcat(file_path, command);
                strcat(file_path, "\0");

                /* Check if this file path actually exists */
                if (stat(file_path, &buffer) == 0)
                {
                    free(path_command_copy);
                    return (file_path);
                }
                else
                {
                    free(file_path);
                    path_token = strtok(NULL, ":");
                }
            }

            /* If no match, free memory for path_command_copy */
            free(path_command_copy);

            /* Check if the command itself is an existing path */
            if (stat(command, &buffer) == 0)
            {
                return (command);
            }

            return (NULL);
        }
    }
    return (NULL);
}
