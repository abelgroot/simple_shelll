#include "main.h"

/**
 * handle_args - Tokenizes the command and allocates arguments array.
 * @command: The command to tokenize.
 * @args: Double pointer to store arguments.
 * @args_size: Pointer to store the size of the arguments array.
 *
 * Return: Number of arguments.
 */
static int handle_args(char *command, char ***args, size_t *args_size)
{
	char *token;
	int i;

	*args = malloc(*args_size * sizeof(char *));
	if (*args == NULL)
	{
		perror("malloc");
		return (-1);
	}

	token = strtok(command, " \t\n");
	i = 0;
	while (token != NULL)
	{
		if (i >= (int)(*args_size))
		{
			*args_size *= 2;
			*args = realloc(*args, *args_size * sizeof(char *));
			if (*args == NULL)
			{
				perror("realloc");
				return (-1);
			}
		}
		(*args)[i++] = token;
		token = strtok(NULL, " \n");
	}
	(*args)[i] = NULL;

	return (i);
}

/**
 * process_command - Processes and executes a command.
 * @command: The command to process.
 * @env: Environment variables.
 *
 * Return: 0 on success, or -1 on failure.
 */
static int process_command(char *command, char *env[])
{
	char **args;
	size_t args_size;
	int num_args;
	char *command_path;

	args_size = 128;
	num_args = handle_args(command, &args, &args_size);
	if (num_args == -1)
	{
		free(command);
		return (-1);
	}

	if (args[0] != NULL)
	{
		if (is_absolute_path(args[0]))
			command_path = args[0];
		else
			command_path = find_path(args[0], env);

		if (execute_command(command_path, args, env) == -1)
			handle_command_not_found(args[0]);
	}

	free(args);
	return (0);
}

/**
 * main - Entry point of the shell program.
 * @argc: Argument count (unused).
 * @argv: Argument vector (unused).
 * @env: Environment variables.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[], char *env[])
{
	char *command;

	(void)argc;
	(void)argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("#cisfun$ ");
		}
		command = read_command();
		if (command == NULL)
			break;

		if (process_command(command, env) == -1)
			perror("shell");

		free(command);
	}

	return (0);
}
