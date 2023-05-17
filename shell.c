#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

#define MAX_COMMAND_LENGTH 1024

void command_line(char *command)
{
	printf("$ ");
	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
	{
		printf("\n");
	}
	else
	{
		exit(EXIT_FAILURE);
	}
}

void execute_command(char *command)
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
		execlp(command, command, NULL);
		fprintf(stderr, "Error: Command not found.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	int running = 1;

	while (running)
	{
		command_line(command);
		command[strcspn(command, "\n")] = '\0';
		execute_command(command);
	}
	return (0);
}
