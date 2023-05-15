#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void print_prompt(char *prompt);
ssize_t read_command(char **entry, size_t *n);
char **parsing_entry(char *entry, char *delim);
void exec_fun(char **argv);

#endif
