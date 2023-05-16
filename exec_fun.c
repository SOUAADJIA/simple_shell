#include "main.h"


void exec_fun(char **argv)
{
	char *command = NULL, *updated_command = NULL;
	int action;

	if (argv)
	{
		command = argv[0];
		/* generate the path to this command before passing it to execve */
		updated_command = build_path(command);
		action = execve(updated_command, argv, NULL);
		if (action == -1)
			perror("./shell: No such file or directory\n");
	}
}
