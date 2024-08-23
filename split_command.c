#include "main.h"

/**
 * split_command - Splits a command string into individual arguments.
 * @command: The command string to split.
 *
 * Return: An array of arguments or NULL on failure.
 */
char **split_command(char *command)
{
	char **args;
	char *token;
	int i = 0;

	if (command == NULL)
		return (NULL);

	args = malloc(BUFFER_SIZE * sizeof(char *));
	if (args == NULL)
		return (NULL);

	token = strtok(command, " \n");
	while (token != NULL)
	{
		args[i] = _realloc(args[i]);
		if (args[i] == NULL)
		{
			free(args);
			return (NULL);
		}
		strcpy(args[i], token);
		i++;
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;
	return (args);
}
