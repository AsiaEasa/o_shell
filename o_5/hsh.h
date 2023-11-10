#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define EXPECTED_DELIM " \t\r\n\a\\"
#define BUFFER_SIZE 1024

/*stringHandlingPart*/
int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *str1, char *str2, int n);
char *_strcpy(char *dest, char *src);
char *my_itoa(int num, char str[], int base);
void reverse(char str[], int length);
void ch_er(char *arg_v);
int _atoi(char *s);

/* shellLOOP.c */
void interactive(void);
void none_interactive(void);

/* interactive.c */
char *_read(void);
char **str_tok(char *line);
int check(char **arg);
char *in_env(char *in_env);
/* exec_args */
int create_process(char **args);

/* not_interactive */
char *get_line(void);

/*---Builtin func---*/
int env(char **arg);
extern char **environ;
/*exit.c*/
int handle_exit(char **args);
void error_exit(char *arg_v);

int cd(char **arg);
int envi(void);
void print_env(char *str);
#endif
