#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h> /* isdigit */

/* Envirmont Variable */
extern char **environ;

/* prompt.c */
void print_prompt();
ssize_t read_command(char **entry, size_t *n);

/* parsing.c */
char **parsing_entry(char *entry, char *delim);

/* exec_fun.c */
void exec_fun(char **argv);

/* build_path.c */
char *build_path(char *command);

/* built_in.c */
void is_exit(char *token, char *status);
void is_env(char **argv);

/* custom_func.c */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/* string_func.c */
char *_strchr(char *s, char c);
int _isdigit(int c);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);


#endif
