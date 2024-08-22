#include "main.h"

/**
 * find_path - Finds the full path of a command.
 * @command: The command to find.
 * @env: The environment variables.
 *
 * Return: The full path of the command or NULL if not found.
 */
char *find_path(char *command, char **env)
{
	char **path_list = build_path_list(env);
	char *full_path = NULL;
	int i;

	if (path_list == NULL)
		return (NULL);

	for (i = 0; path_list[i]; i++)
	{
		full_path = malloc(strlen(path_list[i]) + strlen(command) + 2);
		if (full_path == NULL)
		{
			free_path_list(path_list);
			return (NULL);
		}

		strcpy(full_path, path_list[i]);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			free_path_list(path_list);
			return (full_path);
		}
		free(full_path);
	}
	free_path_list(path_list);
	return (NULL);
}

/**
 * build_path_list - Builds a linked list of PATH directories.
 * @env: The environment variables.
 *
 * Return: An array of directories in the PATH or NULL on failure.
 */
char **build_path_list(char **env)
{
	char *path_var = get_env_var("PATH", env);
	char **path_list = NULL;
	int i = 0;

	if (path_var == NULL)
		return (NULL);

	path_list = malloc(BUFFER_SIZE * sizeof(char *));
	if (path_list == NULL)
		return (NULL);

	path_list[i] = strtok(path_var, ":");
	while (path_list[i] != NULL)
	{
		i++;
		path_list[i] = strtok(NULL, ":");
	}
	return (path_list);
}

/**
 * free_path_list - Frees the linked list of PATH directories.
 * @path_list: The list to free.
 */
void free_path_list(char **path_list)
{
	free(path_list);
}
