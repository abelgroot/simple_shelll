#include "main.h"

/**
 * _setenv - Sets or modifies an environment variable.
 * @name: The name of the variable.
 * @value: The value of the variable.
 * @overwrite: Overwrite flag (1 to overwrite, 0 to not).
 *
 * Return: 0 on success, -1 on failure.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	if (get_env_var(name, environ) != NULL && !overwrite)
		return (0);

	return (setenv(name, value, 1));
}

/**
 * get_env_var - Retrieves an environment variable.
 * @name: The name of the variable.
 * @env: The environment variables.
 *
 * Return: The value of the variable or NULL if not found.
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
