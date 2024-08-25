#include "main.h"

/**
 * main - Entry point of the shell program
 * @argc: Argument count
 * @argv: Argument vector
 * @env: Environment variables
 *
 * Return: Always 0
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive_mode();
	}
	else 
		non_interactive_mode();

	return (0);
}

void interactive_mode(void)
{
	char *command = NULL;
	size_t size = 0;
	ssize_t nread;
	int status = -1;

	while (1)
	{
		printf("#cisfun$ ");
		nread = _getline(&command, &size,STDIN_FILENO);
		if (nread == -1)
		{
			free(command);
			if (feof(stdin))
			{
				exit(EXIT_SUCCESS);
			}
			perror("getline");
			exit(EXIT_FAILURE);
		}
		if (command[nread - 1] == '\n')
		{
			command[nread - 1] = '\0';
		}
		if (command[0] != '\0')
		{
			status = execute_command(command, environ);
		}
		if (status >= 0)
		{
			exit(status);
		}
	}
	free(command);
}

void non_interactive_mode(void)
{
	char *command = NULL;
	size_t size = 0;
	ssize_t nread;
	int status = -1;

	while (1)
	{
		nread = _getline(&command, &size,STDIN_FILENO);
		if (nread == -1)
		{
			free(command);
			if (feof(stdin))
			{
				exit(EXIT_SUCCESS);
			}
			perror("getline");
			exit(EXIT_FAILURE);
		}
		if (command[nread - 1] == '\n')
		{
			command[nread - 1] = '\0';
		}
		if (command[0] != '\0')
		{
			status = execute_command(command, environ);
		}
		if (status >= 0)
		{
			exit(status);
		}
	}
	free(command);

}
