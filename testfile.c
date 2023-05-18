#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

void command_line(char *command)
{
	printf("$ ");
	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
	{
	printf("\n");
	}
}

void parse_arguments(char *command, char *arguments[])
{
	int i = 0;
	arguments[i] = strtok(command, " ");
	while (arguments[i] != NULL && i < MAX_ARGUMENTS - 1)
	{
	i++;
	arguments[i] = strtok(NULL, " ");
	}
	arguments[i] = NULL;
}

void execute_command(char *arguments[])
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
	fprintf(stderr, "Error: Fork failed.\n");
	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	execvp(arguments[0], arguments);
	fprintf(stderr, "Error: Command not found.\n");
	exit(EXIT_FAILURE);
	}
	else
	{
	wait(NULL);
	}
}

int main(int argc, char *argv[])
{
	(void)argc;

	char command[MAX_COMMAND_LENGTH];
	char *arguments[MAX_ARGUMENTS];
	int running = 1;

	while (running)
	{
	command_line(command);
	command[strcspn(command, "\n")] = '\0';

	if (strcmp(command, "exit") == 0)
	{
	running = 0;
	}
	else
	{
	parse_arguments(command, arguments);
	execute_command(arguments);
	}
	}

	return 0;
}
