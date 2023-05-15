#include "main.h"


void exec_fun(char **argv)
{
	int action;

	action = execve(argv[0], argv, NULL);
	if (action == -1)
		printf("./shell: No such file or directory\n");
}
