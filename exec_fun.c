#include "main.h"


void exec_fun(char **argv)
{
	char *our_command;

	if (argv != NULL)
	{
		our_command = argv[0];
		if (execve(our_command , argv, NULL) == -1)
			perror("Not found");
	}
}
