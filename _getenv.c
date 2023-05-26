#include "main.h"

/**
 * _getenv - Retrieve the value of an environment variable.
 * @name: The name of the environment variable.
 * Return: A pointer to the value of the environment variable,
 *         or NULL if the variable is not found.
 */
char *_getenv(const char *name)
{
    int i, name_length = strlen(name);

    for (i = 0; environ[i] != NULL; i++) 
    {
        if (strncmp(environ[i], name, name_length) == 0 && environ[i][name_length] == '=') 

            return (environ[i] + name_length + 1);
    }
    return (NULL);
}