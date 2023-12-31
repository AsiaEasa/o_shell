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

/* shellLOOP.c */
void interactive(void);
void none_interactive(void);

/* interactive.c */
char *read_line(void);
char  **split(char str[BUFFER_SIZE]);
int exec_arg(char **arg);

/* exec_args */
int create_process(char **args);

/* not_interactive */
char *get_line(void);

/*---Builtin func---*/
int env(char **arg);
extern char **environ;
/*exit.c*/
int own_exit(char **args);
#endif
