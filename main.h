#ifndef MAIN_H
#define MAIN_H

/*#define _GNU_SOURCE*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
/*
typedef struct ShellVar
{
char *n;
char*val;
struct ShellVar *next;
} ShellVar;

typedef struct HistList
{
char *cmd;
struct HistList *next;
} HistList;

typedef struct AliasData
{
char *n;
char *val;
struct AliasData *next;
} AliasData;
*/
int atoi(char *s);
char **getallenv();
int setallenv(char **envin, char *newval);
char *getenv(char *n);
int setenv(char *n, char *val);
int unsetenv(char *n);
int getline(char **lineptr, int fd);
int putchar(char c);
int printenv(void);
void *realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/*char *strtok(char *str, char *delim);*/
char *strtokqe(char *str, char *delim, int escflags);
AliasData **getalist();
char *getalias(char *n);
int setalias(char *n, char *val);
int unsetalias(char *n);
int aliascmd(char *av[]);
int cd(char *av[]);
int checkpath(char *av[]);
int cmdcall(char *av[], char *cmd);
int builtincall(char *av[]);
void exitcleanup(char **av);
char ***getenviron();
char *getpid();
ShellVar **getspecial();
ShellVar **getvars();
int help(char *cmd);
HistList **gethistory();
int sethist(char *cmd);
int print_hist(void);
int exit_hist(void);
int inputvalidator(char **buf, int fd);
int shintmode(void);
int scriptmode(char *av[]);
char *parsesetsvar(char *buf);
char *subsvars(char **buf);
char *cleanarg(char *arg);
char *tildeexpand(char *buf);
int parseargs(char **buf);
int initsvars(int ac, char **av);
char *getsvar(char *n);
int setsvar(char *n, char *val);
int unsetsvar(char *n);
int strcmp(char *s1, char *s2);
size_t strlen(char *str);
char *strcpy(char *dest, char *src);
char *strdup(char *str);
char *strcat(char *dest, char *src);
int linecount(int increment);
char *itos(int digits);
int printerr(char *str);
int fprintstrs(int fd, char *str, ...);
char *strchr(char *s, char c);
int main(int ac, char *av[], char **environ);

#endif
