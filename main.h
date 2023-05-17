#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Envirmont Variable */
extern char **environ;

/* prompt.c */
void print_prompt();
ssize_t read_command(char **entry, size_t *n);

/* parsing.c */
char **parsing_entry(char *entry, char *delim);

/* exec_fun.c */
void exec_fun(char **argv);
//we might need a forking function here

/* build_path.c */
char *build_path(char *command);

/* built_in.c */
void is_exit(char *token);
void is_env(char **argv);

#endif
