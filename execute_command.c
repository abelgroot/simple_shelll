#include "main.h"

/**
 * execute_command - Executes a command in a child process.
 * @command: The command to execute.
 * @args: The arguments for the command.
 * @env: The environment variables.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char *command, char **args, char *env[])
{
	pid_t pid;
	int status;

	if (command == NULL)
		return (-1);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(command, args, env) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (0);
}

/**
 * is_absolute_path - Checks if a command is an absolute path.
 * @command: The command to check.
 *
 * Return: 1 if true, 0 if false.
 */
int is_absolute_path(char *command)
{
	return (command[0] == '/');
}

/**
 * handle_command_not_found - Handles a command not found situation.
 * @command: The command that was not found.
 */
void handle_command_not_found(char *command)
{
	printf("%s: command not found\n", command);
}
