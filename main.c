#include "main.h"

/**
 * print_prompt - Prints the shell prompt to the standard output
 *
 * This function displays the prompt symbol for the user to enter a command.
 * It is typically called before reading a command in a loop.
 */
void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
	}
}

/**
 * main - Entry point of the simple shell
 *
 * Return: Status of the shell execution
 */
int main(void)
{
	char *command;
	char **args;
	char *full_path;
	int status = 0;

	while (1)
	{
		print_prompt();

		command = read_command();
		if (command == NULL)
		{
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			break;
		}

		args = split_command(command);
		if (args[0] == NULL)
		{
			free(command);
			free(args);
			continue;
		}

		full_path = find_path(args[0], environ);
		if (full_path == NULL)
		{
			perror(args[0]);
		}
		else
		{
			status = execute_command(full_path, args, environ);
			free(full_path);
		}

		free(command);
		free(args);
	}

	return (status);
}
