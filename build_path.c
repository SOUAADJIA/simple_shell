#include "main.h"

/**
 * find_directory - Find a directory in the PATH environment variable.
 * @path_command: The PATH environment variable.
 * @command: The command to find the full path for.
 * Return: The full path of the command if found, or NULL if not found.
 */
char *find_directory(char *path_command, char *command)
{
	char *path_command_copy = _strdup(path_command);
	char *path_token = _strtok(path_command_copy, ":");
	char *file_path = NULL;

	while (path_token != NULL)
	{
		file_path = build_file_path(path_token, command);

		if (file_path != NULL)
		{
			free(path_command_copy);
			return (file_path);
		}

		path_token = _strtok(NULL, ":");
	}

	free(path_command_copy);

	return (NULL);
}

/**
 * build_file_path - Build the path by concatenating the directory and command.
 * @directory: The directory to append to the command.
 * @command: The command.
 * Return: The full path of the command if found, or NULL if not found.
 */
char *build_file_path(char *directory, char *command)
{
	int command_len = _strlen(command);
	int directory_len = _strlen(directory);
	struct stat buffer;
	char *file_path;

	file_path = malloc(sizeof(char) * (command_len + directory_len + 2));

	if (!file_path)
	{
		perror("./shell");
		return (NULL);
	}

	_strcpy(file_path, directory);
	_strcat(file_path, "/");
	_strcat(file_path, command);
	_strcat(file_path, "\0");

	if (stat(file_path, &buffer) == 0)
	{
		return (file_path);
	}
	else
	{
		free(file_path);
		return (NULL);
	}
}

/**
 * build_path - Builds the full path of a command by searching through
 * the directories listed in the PATH environment variable.
 * @command: The command to find the full path for.
 * Return: The full path of the command if found, or NULL if not found.
 */
char *build_path(char *command)
{
	char *path_command, *file_path;
	struct stat buffer;
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			path_command = *env + 5;
			file_path = find_directory(path_command, command);

			if (file_path != NULL)
			{
				return (file_path);
			}

			if (stat(command, &buffer) == 0)
			{
				return (command);
			}

			return (NULL);
		}
	}

	return (NULL);
}

