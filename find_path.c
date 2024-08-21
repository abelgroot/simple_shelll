#include "main.h"

/**
 * build_cmd_path - Builds a full path for the command.
 * @dir: The directory path.
 * @cmd: The command to build the path for.
 *
 * Return: The full path to the command or NULL on failure.
 */
char *build_cmd_path(const char *dir, const char *cmd)
{
	size_t len;
	char *cmd_path;

	len = strlen(dir) + strlen(cmd) + 2;
	cmd_path = malloc(len);
	if (!cmd_path)
		return (NULL);

	snprintf(cmd_path, len, "%s/%s", dir, cmd);
	return (cmd_path);
}

/**
 * find_command_in_path - Searches for a
 * command in the directories listed in PATH.
 * @cmd: The command to search for.
 *
 * Return: The full path to the command if found, or NULL if not found.
 */
char *find_command_in_path(char *cmd)
{
	char *path_env, *path, *cmd_path;
	struct stat st;

	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);

	path = strtok(path_env, ":");
	while (path != NULL)
	{
		cmd_path = build_cmd_path(path, cmd);
		if (!cmd_path)
			return (NULL);

		if (stat(cmd_path, &st) == 0 && S_ISREG(st.st_mode) &&
			(st.st_mode & S_IXUSR))
			return (cmd_path);

		free(cmd_path);
		path = strtok(NULL, ":");
	}

	return (NULL);
}
