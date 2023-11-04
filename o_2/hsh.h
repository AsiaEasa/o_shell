#ifndef HSH_H
#define HSH_H
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define EXPECTED_DELIM " \t\r\n\a\\"
extern char **environ;

/*stringHandlingPart*/
int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *str1, char *str2, int n);
char *_strdup(char *str);
char *_strchr(char *s, char c);
char *str_concat(char *word1, char *word2, char *word3);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

char *Path(char *command);
char *in_env(char *in_env);

/* shellLOOP.c */
void interactive(void);
void none_interactive(void);

/* interactive.c */
char *read_line(void);
char **split(char *line);
int exec_arg(char **arg);

/* exec_args */
int create_process(char **args, char *path);

/* not_interactive */
char *get_line(void);

/*---Builtin func---*/
int env(char **arg);
extern char **environ;
/*exit.c*/
int own_exit(char **args);
#endif
