#include "main.h"

char *build_path(char *command)
{
    char *path_command, *path_command_copy, *path_token, *file_path;
    int command_len, directory_len;
    struct stat buffer;

    path_command = getenv("PATH");

    if (path_command)
    {
        path_command_copy = strdup(path_command);
        command_len = strlen(command);

        /* break down the path variable and get all the directories in*/
        path_token = strtok(path_command_copy, ":");

        while(path_token != NULL)
        {
            /* Get the length of the directory*/
            directory_len = strlen(path_token);
            /* allocate memory to store the command name + the directory name */
            file_path = malloc(sizeof(char) * (command_len + directory_len + 2)); /*  2 for / and \0 */
            /* path= = copy the directory path + concatenate the command  */
            strcpy(file_path, path_token);
            strcat(file_path, "/");
            strcat(file_path, command);
            strcat(file_path, "\0");

            /* check if this file path actually exists */
            if (stat(file_path, &buffer) == 0) /* return 0 means that the file_path is valid*/
            {
                free(path_command_copy);/*free the memory allocate by strdup*/
                return (file_path);
            }
            else
            {
                free(file_path);
                path_token = strtok(NULL, ":");
            }
        }
        /* if no match, we return NULL, but we need to free up memory for path_command_copy */
        free(path_command_copy);
        /* besote exciting, check if the command itself is a an existing path */
        if (stat(command, &buffer) == 0)
        {
            return (command);
        }
        return (NULL);
    }
    return (NULL);
}

