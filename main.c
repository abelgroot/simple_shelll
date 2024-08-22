#include "main.h"

/**
 * main - Entry point of the simple shell program.
 * @argc: The number of command line arguments.
 * @argv: The array of command line arguments.
 * @env: The environment variables.
 *
 * Return: 0 on success, or -1 on failure.
 */
int main(int argc, char *argv[], char *env[])
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	(void)argc;
	(void)argv;  /* Mark argv as unused to avoid warnings */

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		execute_command(line, env);
	}

	free(line);
	return (0);
}
