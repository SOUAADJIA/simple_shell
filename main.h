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

/* Environment Variable */
extern char **environ;
/*empty command*/
int is_empty_input(char *entry);

/* prompt.c */
void print_prompt(void);
ssize_t read_command(char **entry, ssize_t *n);
ssize_t _getline(char **lineptr, ssize_t *n, FILE *stream);
int should_refill_buffer(ssize_t *n_read, ssize_t pos);

/* getlin_tools.c */
ssize_t find_line_length(char *buff, ssize_t n_read, ssize_t pos);
int should_resize_buffer(char **lineptr, ssize_t n, ssize_t line_len);
ssize_t resize_buffer(char **lineptr, ssize_t *n, ssize_t line_len);
void copy_line_to_buffer(char **lineptr, char *buff, ssize_t pos,
ssize_t line_len);
ssize_t refill_buffer(ssize_t *n_read, char *buff, FILE *stream);


/* parsing.c */
char **parsing_entry(char *entry, char *delim);
char *copy_entry_string(char *entry);
size_t count_tokens(char *entry, char *delim);
char **allocate_token_array(size_t n_tokens);
char *copy_token_string(char *token);

char *tokenize_entry(char *entry, char *delim);
void free_token_array(char **av, int size);
/*Check if the command is a built-in command*/
void check_builtin_command(char **av);
void execute_env_command(char **av);
void execute_exit_command(char *av);
void execute_cd_command(char **av);

/* exec_fun.c */
void exec_fun(char **argv);
int execute_command(const char *command, char **argv);
void wait_for_child(pid_t child_pid);

/* build_path.c */
char *build_path(char *command);
char *find_directory(char *path_command, char *command);
char *build_file_path(char *directory, char *command);

/* built_in.c */
void is_exit(char *token, char *status);
void is_env(char **argv);
void change_directory(const char *path);


/* custom_func.c */
char *_strtok(char *str, const char *delim);

/* string_func.c */
int _isdigit(int c);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *str1, const char *str2, size_t n);
int _atoi(char *s);
char *_strchr(const char *s, int c);

#endif
