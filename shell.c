#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 64
/**
* command_line - displays prompt for user to type command
* @command: command line user inputs
*/
void command_line(char *command)
{
	printf("$ ");
	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
	{
		printf("\n");
	}
}
/**
* parse_args - handles arguments in a command
* @command: command line user input
* @args: arguments to be executed in the command
*/
void parse_args(char *command, char *args[])
{
	int i = 0;

	args[i] = strtok(command, " ");
	while (args[i] != NULL && i < MAX_ARGS - 1)
	{
		i++;
		args[i] = strtok(NULL, " ");
	}
	args[i] = NULL;
}
/**
* execute_command - executes commands
* @args: arguments to be executed in the command
*/
void execute_command(char *args[])
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
		execvp(args[0], args);
		fprintf(stderr, "Error: Command not found.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
/**
* main - pront is printed, user imputs command, arguments
* in the command are executed and give output, exit
* command is to exit the shell.
* Return: Always 0
*/
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];
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
			parse_args(command, args);
			execute_command(args);
		}
	}
	return (0);
}
