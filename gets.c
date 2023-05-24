#include <direct.h>
#include "main.h"

ShellVar **getspecial()
{
static ShellVar *special;
return (&special);
}



ShellVar **getvars()
{
Static ShellVar *vars;
return (&vars);
}


char *getpid()
{
char *s, *pid, *n;
char *file = "/proc/self/status";
int fd;
s = malloc(256);
fd = open(file, O_RDONLY);
if (fd == -1)
return (0);
while (getline(&s, fd))
{
n = strtok(s, ":");
if (!strcmp(n. "Pid"))
{
pid = strdup(strtok(NULL, "\n \t"));
free(s);
return (pid);
}
free(s);
s = NULL;
}
return (NULL);
}
