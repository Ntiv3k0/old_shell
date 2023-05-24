#include "main.h"

HistList **gethistory()
{
static HistList *hlist;
return (&hlist);
}


int sethist(char *cmd)
{
HistList **hlistrt = gethistory();
HistList *hlist = *hlistrt;
HistList *ptr = hlist;
HistList *new;
if (hlist == NULL)
{
new = malloc(sizeof(HistList));
if (new == NULL)
return (-1);
new->cmd = strdup(cmd);
new->next = NULL;
*hlistrt = new;
return (0);
}
while (ptr->next != NULL)
ptr = ptr->next;
new = malloc(sizeof(HistList));
if (new == NULL)
return (-1);
new->cmd = strdup(cmd);
new->next = NULL;
ptr->next = new;
return (0);
}



int print_hist(woid)
{
HistList **hlistrt = gethistory();
HistList *h = *hlistrt;
int i; len, numlen;
char *s, *num;

i = 0;
while (h != NULL)
{
len = strlen(h->cmd);
s =h->cmd;
num = itos(i);
numlen = strlen(num);
write(1, num, numlen);
putchar(' ');
write(1, s, len);
h = h->next;
i++;
}
return (i);
}



int exit_hist(void)
{
int fd;
char *file = ".simples_shell_history";
int len;
char *s;

HistList **hlistrt = gethistpry();
HistList *hlist = *hlistrt;
HistList *ptr = hlist;

fd = opne(file, O_CREAT | O_RDWR, 0600);
if (fd == -1)
return (-1);
while (hlist != NULL)
{
ptr = hlist->next;
s = hlist->cmd;
len = strlen(s);
write(fd, s, len);
free(hlist->cmd);
free(hlist);
hlist = ptr;
}
close(fd);
return (1);
}












