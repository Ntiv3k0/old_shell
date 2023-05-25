#include "main.h"

ShellVar **getspecial()
{
	static ShellVar *special;
	return (&special);
}



ShellVar **getvars()
{
	static ShellVar *vars;
	return (&vars);
}


char *_getpid()
{
	char *s, *pid, *n;
	char *file = "/proc/self/status";
	int fd;
	s = malloc(256);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (_getline(&s, fd))
	{
		n = _strtok(s, ":");
		if (!_strcmp(n, "Pid"))
		{
			pid = _strdup(_strtok(NULL, "\n \t"));
			free(s);
			return (pid);
		}
		free(s);
		s = NULL;
	}
	return (NULL);
}
