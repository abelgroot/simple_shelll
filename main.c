#include "main.h"

/**
 * main - Entry point for the simple shell.
 *
 * Return: Always 0 on success, or exit with failure status on error.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int status;

	if (isatty(STDIN_FILENO))
	{
		/* Interactive mode */
		while (1)
		{
			printf("#cisfun$ ");
			nread = read_command(&line, &len);
			if (nread == -1)
			{
				free(line);
				exit(EXIT_FAILURE);
			}

			status = execute_command(line);
			if (status == -1)
				perror("./hsh");
		}
	}
	else
	{
		/* Script mode */
		while ((nread = read_command(&line, &len)) != -1)
		{
			status = execute_command(line);
			if (status == -1)
				perror("./hsh");
		}
		free(line);
	}

	return (0);
}
