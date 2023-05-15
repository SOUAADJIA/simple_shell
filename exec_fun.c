#include "main.h"


void exec_fun(char **argv)
{
	int action;

	if (argv)
	{
		action = execve(argv[0], argv, NULL);
		if (action == -1)
			perror("./shell: No such file or directory\n");
	}
}
