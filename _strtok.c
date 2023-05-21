#include "main.h"

char *_strtok(char *str, const char *delim)
{
    static char *buffer = NULL;
    char *token_start;

    if (str != NULL)
        buffer = str;

    if (buffer == NULL || *buffer == '\0')
        return (NULL);

    /* Skip leading delimiters */
    while (*buffer != '\0' && strchr(delim, *buffer) != NULL)
        buffer++;

    if (*buffer == '\0')
        return (NULL);

    token_start = buffer;

    /* Find the end of the token */
    while (*buffer != '\0' && strchr(delim, *buffer) == NULL)
        buffer++;

    if (*buffer != '\0')
    {
        *buffer = '\0'; /* Replace the delimiter with null character */
        buffer++;
    }

    return (token_start);
}
