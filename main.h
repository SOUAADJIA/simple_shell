#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

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
char *_strtok(char* str, const char* delim);


/* string_func.c */
int _isdigit(int c);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(const char* str);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *str1, const char *str2, size_t n);
int _atoi(char *s);
char *_strchr(const char *s, int c);

#endif
