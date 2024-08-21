#include "main.h"

/**
 * handle_command_not_found - Prints an error
 * message if the command is not found.
 * @cmd: The command that was not found.
 */
void handle_command_not_found(char *cmd)
{
	fprintf(stderr, "./hsh: 1: %s: not found\n", cmd);
}

/**
 * execute_command_in_child - Executes a command in the child process.
 * @cmd_path: The full path to the command.
 * @argv: The arguments for the command.
 */
void execute_command_in_child(char *cmd_path, char *argv[])
{
	if (execve(cmd_path, argv, NULL) == -1)
	{
		perror("./hsh");
		free(cmd_path);
		exit(EXIT_FAILURE);
	}
}

/**
 * is_absolute_path - Checks if a given path is absolute.
 * @path: The path to check.
 *
 * Return: 1 if the path is absolute, 0 otherwise.
 */
int is_absolute_path(const char *path)
{
	return (path[0] == '/');
}

/**
 * handle_absolute_path - Handles execution of commands with absolute paths.
 * @argv: The command and arguments.
 *
 * Return: The full path of the command, or NULL if not executable.
 */
char *handle_absolute_path(char *argv[])
{
	char *cmd_path;

	cmd_path = strdup(argv[0]);
	if (!cmd_path)
		return (NULL);

	if (access(cmd_path, X_OK) != 0)
	{
		handle_command_not_found(argv[0]);
		free(cmd_path);
		return (NULL);
	}

	return (cmd_path);
}

/**
 * execute_command - Executes a command line with arguments.
 * @line: The command line to execute.
 *
 * Return: 0 on success, or -1 on failure.
 */
int execute_command(char *line)
{
	char *argv[MAX_ARGS], *cmd_path;
	int i = 0, status;
	pid_t child_pid;

	argv[i] = strtok(line, " ");
	while (argv[i] != NULL && i < MAX_ARGS - 1)
		argv[i++] = strtok(NULL, " ");
	argv[i] = NULL;

	if (argv[0] == NULL)
		return (0);

	if (is_absolute_path(argv[0]))
	{
		cmd_path = handle_absolute_path(argv);
		if (!cmd_path)
			return (-1);
	}
	else
	{
		cmd_path = find_command_in_path(argv[0]);
		if (cmd_path == NULL)
		{
			handle_command_not_found(argv[0]);
			return (-1);
		}
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("./hsh");
		free(cmd_path);
		return (-1);
	}
	if (child_pid == 0)
		execute_command_in_child(cmd_path, argv);
	else
		waitpid(child_pid, &status, 0);
	free(cmd_path);
	return (0);
}
