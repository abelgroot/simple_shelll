#include "main.h"

/**
 * print_prompt - Prints the shell prompt.
 */
void print_prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}

/**
 * main - Entry point for the shell.
 * @argc: Argument count.
 * @argv: Argument vector.
 * @env: Environment variables.
 *
 * Return: Always 0.
 */
int main(int argc, char **argv, char **env)
{
	char *command = NULL;
	char **args;
	int status;

	if (argc != 1)
		return (1);

	while (1)
	{
		print_prompt();
		command = read_command();
		if (command == NULL)
			break;

		args = split_command(command);
		if (args == NULL)
		{
			free(command);
			continue;
		}

		execute_command(args[0], env);

		free(command);
		free(args);
	}

	return (0);
}
