#include "main.h"

ShellVar **getspecial();
ShellVar **getvars();
AliasData **getalist();


char ***getenviron()
{
static char ** environ;
return (&environ);
}


void exitcleanup(char **av)
{
ShellVar *ptr = *(getspecial()), *snext;
AliasData *t = *(getsalist()), *anext;
char **environ = *(getenviron());
int i;
i = 0;
if (av != NULL)
for (i = 0; av[i] != NULL; i++)
free(av[i]);
i = 0;
while (environ[i] != NULL)
free(environ[i++]);
free(environ);
while (ptr != NULL)
{
free(ptr->val);
free(ptr->name);
ptr = ptr->next;
}
free(*(getspecial()));
ptr = *(getvars());
while (t != NULL)
{
free(t->val);
free(t->name);
anext = t -> next;
free(t);
t = anext;
}
}
