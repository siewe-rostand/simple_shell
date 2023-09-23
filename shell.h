#ifndef _SHELL_H_
#define _SHELL_H_

#define BUFFSIZE 10240

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

extern char **ENV;
void env_creation(char **envi);
void free_environ(char **env);

int _strlen(char *str);
int _atoi(char *s);
void print_string(char *str);
int _putchar(char c);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strdup(char *str);
int _isalpha(int ch);
char *_itoc(unsigned int n);
void array_rev(char *arr, int len);
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
void prompt_int(int n);
int _echo(char **cmd);
void prompt(char *ch);
void _prerror(char **argv, int counter, char **cmd);
void errormessage(char *input, int counter, char **argv);
void file_error_message(char **argv, int c);

char **commas_separator(char *user_input);
int shell_history(char *userinput);
char *_get_env(char *name);
int path_exec(char **cmd);
char *build_cmd(char *token, char *dir);
void file_cmd(char *file, char **argv);

char **cmd_parser(char *user_input);
char **parse_string(char *user_input);

int buildin_checker(char **cmd);
int buildin_echo(char **cmd);
int cmd_exec(char **cmd, char *userinput, int c, char **argv);
int buildin_handler(char **cmd, int st);
void buildin_exit(char **cmd, char *input, char **argv, int c, int stat);
int echo_buildin(char **cmd, int st);
int show_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int st);
int _cd(char **cmd, __attribute__((unused))int st);

int fork_wait(char **cmd, char *userinput, int counter, char **argv);


void h_all(void);
void h_alias(void);
void h_cd(void);
void h_exit(void);
void h_help(void);
void h_env(void);
void h_setenv(void);
void h_unsetenv(void);
int show_help(char **cmd, __attribute__((unused))int st);
int cmd_history(__attribute__((unused))char **cmd, __attribute__((unused))int status);

void signal_to_handle(int sig);

/**
 * struct _buildin - Defines a struct that conatins build-in commands
 * with their respective implementation functions
 * @command: - Built-in command
 * @function: - Pointer to custom functions that have
 * similar functionalities as the built-in commands
 */
typedef struct _buildin
{
	char *command;
	int (*function)(char **line, int st);
} buildin;
#endif
