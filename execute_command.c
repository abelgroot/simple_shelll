#include "main.h"

/**
 * handle_command_not_found - Prints an error message for not found commands.
 * @cmd: The command that was not found.
 */
void handle_command_not_found(char *cmd)
{
	perror(cmd);
}

/**
 * execute_command_in_child - Forks a child process and executes the command.
 * @argv: The command and its arguments.
 * @env: The environment variables.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_command_in_child(char *argv[], char *env[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("./hsh");
		return (-1);
	}
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			handle_command_not_found(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}

	return (0);
}

/**
 * is_absolute_path - Checks if the command is an absolute path.
 * @cmd: The command to check.
 *
 * Return: 1 if true, 0 otherwise.
 */
int is_absolute_path(char *cmd)
{
	return (cmd[0] == '/');
}

/**
 * execute_command - Executes a command line with arguments.
 * @line: The command line to execute.
 * @env: The environment variables.
 *
 * Return: 0 on success, or -1 on failure.
 */
int execute_command(char *line, char *env[])
{
	char *argv[MAX_ARGS];
	int i = 0;

	argv[i] = strtok(line, " ");
	while (argv[i] != NULL && i < MAX_ARGS - 1)
	{
		i++;
		argv[i] = strtok(NULL, " ");
	}
	argv[i] = NULL;

	if (argv[0] == NULL)
		return (0);
	if (is_absolute_path(argv[0]))
	{
		if (access(argv[0], X_OK) == 0)
			return (execute_command_in_child(argv, env));
		handle_command_not_found(argv[0]);
		return (-1);
	}
	return (execute_command_in_child(argv, env));
}
