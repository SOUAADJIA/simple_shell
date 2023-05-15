#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

char **parsing_entry(char *entry, char *delim);
void exec_fun(char **argv);

#endif
