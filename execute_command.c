#include "main.h"

/**
 * handle_command_not_found - Handles a command not found error.
 * @command: The command that was not found.
 */
void handle_command_not_found(char *command)
{
	printf("%s: command not found\n", command);
}

/**
 * execute_command_in_child - Executes a command in a child process.
 * @command_path: The path to the command.
 * @args: The arguments to the command.
 * @env: The environment variables.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_command_in_child(
	char *command_path, char *args[], char *env[])
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0)
	{
		if (execve(command_path, args, env) == -1)
		{
			perror("execve");
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
			return (-1);
	}

	return (0);
}

/**
 * is_absolute_path - Checks if the path is an absolute path.
 * @path: The path to check.
 *
 * Return: 1 if absolute path, 0 otherwise.
 */
int is_absolute_path(char *path)
{
	return (path[0] == '/');
}

/**
 * execute_command - Executes a command based on its path.
 * @command_path: The path to the command.
 * @args: The arguments to the command.
 * @env: The environment variables.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char *command_path, char *args[], char *env[])
{
	return (execute_command_in_child(command_path, args, env));
}
