#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;

void hsh_loop(char **env, char *prog_name);
char *hsh_read_line(void);
char **parse_line(char *line);
int execute_cmd(char **av, char **env, char *prog_name);
int exec_external(char **av, char **env, char *prog_name);
int exec_builtins(char **av);
int exit_builtin(char **av);
int env_builtin(char **av);
int cd_builtin(char **av);
typedef int (*func_builtin)(char **av);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
void free_tokens(char **token_string);
char *which_location(char *command);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strncmp(char *s1, char *s2, size_t n);

#endif
