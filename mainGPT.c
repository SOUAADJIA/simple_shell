#include "main.h"

char **split_input(char *input)
{
    char *token, *input_copy;
    char **tokens;
    size_t n_tokens = 0;
    int i;

    /* create copy of input string */
    input_copy = strdup(input);
    if (input_copy == NULL)
    {
        perror("hsh: memory allocation error");
        exit(EXIT_FAILURE);
    }

    /* count number of tokens in input */
    token = strtok(input_copy, " ");
    while (token != NULL)
    {
        n_tokens++;
        token = strtok(NULL, " ");
    }

    /* allocate memory for tokens */
    tokens = malloc((n_tokens + 1) * sizeof(char *));
    if (tokens == NULL)
    {
        perror("hsh: memory allocation error");
        exit(EXIT_FAILURE);
    }

    /* copy tokens into tokens array */
    token = strtok(input, " ");
    for (i = 0; token != NULL; i++)
    {
        tokens[i] = strdup(token);
        if (tokens[i] == NULL)
        {
            perror("hsh: memory allocation error");
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;

    /* free copy of input string */
    free(input_copy);

    return tokens;
}

void free_tokens(char **tokens)
{
    int i;

    for (i = 0; tokens[i] != NULL; i++)
    {
        free(tokens[i]);
    }

    free(tokens);
}

int execute_command(char **tokens)
{
    int status;

    pid_t pid = fork();

    if (pid == -1)
    {
        perror("hsh: fork error");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        /* child process */
        execvp(tokens[0], tokens);
        perror("hsh: execvp error");
        exit(EXIT_FAILURE);
    }
    else
    {
        /* parent process */
        waitpid(pid, &status, 0);
    }

    return status;
}

int main(int ac, char **av)
{
    char *prompt = "$ ";
    char *entry = NULL;
    size_t n = 0;
    ssize_t n_read;
    int status;

    (void) ac;

    while (1)
    {
        printf("%s", prompt);
        n_read = getline(&entry, &n, stdin);
        if (n_read == -1)
        {
            printf("\n\nDisconnected...\n");
            return (0);
        }
        else
        {
            /* remove newline character from input */
            entry[n_read - 1] = '\0';

            /* split input into tokens */
            char **tokens = split_input(entry);

            /* execute command */
            status = execute_command(tokens);

            /* free tokens */
            free_tokens(tokens);

            if (status == -1)
            {
                return -1;
            }
        }
    }

    return (0);
}