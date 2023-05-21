#ifndef MAIN_H
#define MAIN_H

extern char **environ;
void print_prompt(void);
int read_command(char *command);
void remove_newline(char *command);
int parse_arguments(char *command, char *arguments[]);
void execute_command(char *arguments[]);
void run_interactive_mode(void);
void run_non_interactive_mode(FILE *input_file);
int main(int argc, char *argv[]);

#endif
