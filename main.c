#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

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
	char *command = NULL;
	size_t size = 0;
	ssize_t nread;

	printf("is a tty %d", isatty(STDIN_FILENO));
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			printf("#cisfun$ ");
		}
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
			execute_command(command, environ);
		}
	}
	free(command);
	return (0);
}
