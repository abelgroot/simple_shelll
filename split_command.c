#include "main.h"

/**
 * split_command - Splits a command string into an array of arguments.
 * @command: The command string to split.
 *
 * Return: An array of arguments or NULL if an error occurs.
 *
 * This function splits a command string by spaces into individual arguments.
 * It uses dynamic memory allocation to create the array and each argument.
 * The caller is responsible for freeing the returned array.
 */
char **split_command(char *command)
{
	char **args = NULL;
	char *token = NULL;
	size_t bufsize = BUFFER_SIZE, i = 0;

	if (command == NULL)
		return (NULL);

	args = malloc(bufsize * sizeof(char *));
	if (args == NULL)
		return (NULL);

	token = strtok(command, " \n");
	while (token != NULL)
	{
		args[i] = token;
		i++;

		if (i >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			args = _realloc((char *)args);  /* Reallocate memory for args */
			if (args == NULL)
				return (NULL);
		}

		token = strtok(NULL, " \n");
	}
	args[i] = NULL;
	return (args);
}
