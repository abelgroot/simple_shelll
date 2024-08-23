#include "main.h"

/**
 * get_env_var - Gets the value of an environment variable
 * @name: The name of the environment variable
 * @env: The environment variables
 *
 * Return: The value of the environment variable, or NULL if not found
 */
char *get_env_var(const char *name, char **env)
{
	int i;
	size_t len = strlen(name);

	for (i = 0; env[i] != NULL; i++)
	{
		if (strncmp(env[i], name, len) == 0 && env[i][len] == '=')
		{
			return (env[i] + len + 1);
		}
	}

	return (NULL);
}
