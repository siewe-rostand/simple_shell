
#ifndef _SHELL_H_
#define _SHELL_H_

#define BUFFSIZE 1024;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int count_args(char *input);
void fork_wait(char **cmd, char *input, char *argv[], char **env);
char *handle_newline(char *str);
void handle_comment(char *buffer);
char *remove_space(char *str);
void prompt(void);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int check_env(char *input);
void *_get_line(void);
char doubleptr_realloc(char ** dbptr, unsigned int old_size, unsigned int new_size);
char parse_string(char *user_input);
char *_strtok(char *str, const char *delim);
unsigned int check_delim(char c, const char *str);
void print_string(char *str);
int _putchar(char c);
#endif
