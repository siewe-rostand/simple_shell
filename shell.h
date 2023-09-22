#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

int _strlen(char *str);
int _atoi(char *s);
void print_string(char *str);
int _putchar(char c);
char *_strcpy(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
int _isalpha(int ch);
char *_itoc(unsigned int n);
int _intlen(int num);

char *_get_line(void);
void handle_comment(char *buffer);
char *handle_newline(char *str);
char *remove_space(char *str);

char *tokenizer(char *str, const char *del);
unsigned int handle_delimiter(char ch, const char *del);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void _free(char **cmd, char *line);

void prompt_num(int n);
int _echo(char **cmd);
int prompt(char ch);
void errormessage(char *input, int counter, char **argv);
void file_error_message(char **argv, int c);

char **commas_separator(char *user_input);
int shell_history(char *userinput);
char *_get_env(char *name);
int path_exec(char **cmd);
char _build_cmd(char *token, char *dir);
void file_cmd(char *file, char **argv);

char **cmd_parser(char *user_input);

#endif
