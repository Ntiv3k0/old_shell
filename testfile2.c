#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

void print_prompt()
{
    printf("$ ");
}

int read_command(char *command)
{
	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
	{
	return 0;
	}
	return 1;
}

void remove_newline(char *command)
{
	size_t len = strlen(command);
	if (len > 0 && command[len - 1] == '\n')
	{
	command[len - 1] = '\0';
	}
}

int parse_arguments(char *command, char *arguments[])
{
	char *token;
	int i = 0;
	
	token = strtok(command, " ");
	
	while (token != NULL && i < MAX_ARGUMENTS - 1)
	{
	i++;
	token = strtok(NULL, " ");
	}
	arguments[i] = NULL;

	return i;
}

void execute_command(char *arguments[])
{
	pid_t pid;
	int status;

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
	waitpid(pid, &status, 0);
	}
}

void run_interactive_mode()
{
	char command[MAX_COMMAND_LENGTH];
	char *arguments[MAX_ARGUMENTS];
	int running = 1;

	while (running)
	{
	print_prompt();
	if (!read_command(command))
	{
	break;
	}
	remove_newline(command);

	int num_arguments;
	num_arguments = parse_arguments(command, arguments);

	if (strcmp(command, "exit") == 0)
	{
	running = 0;
	}

	else if (num_arguments > 0)
	{
	execute_command(arguments);
	}
	}
}

void run_non_interactive_mode(FILE *input_file)
{
	char command[MAX_COMMAND_LENGTH];
	char *arguments[MAX_ARGUMENTS];

	while (fgets(command, MAX_COMMAND_LENGTH, input_file) != NULL)
	{
	remove_newline(command);

int num_arguments = parse_arguments(command, arguments);

	if (num_arguments > 0)
	{
	execute_command(arguments);
	}
}
}

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
	FILE *input_file = fopen(argv[1], "r");
	if (input_file == NULL)
	{
	fprintf(stderr, "Error: Failed to open file '%s'.\n", argv[1]);
	return EXIT_FAILURE;
	}
	run_non_interactive_mode(input_file);
	fclose(input_file);
	}
	else
	{
	run_interactive_mode();
	}

	return EXIT_SUCCESS;
}

