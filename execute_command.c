#include "main.h"

/**
 * execute_command - Executes a command.
 * @command: The command to execute.
 * @env: The environment variables.
 */
void execute_command(char *command, char **env)
{
	char *full_path;
	pid_t pid;
	int status;

	full_path = find_path(command, env);
	if (full_path == NULL)
	{
		write(STDERR_FILENO, command, strlen(command));
		write(STDERR_FILENO, ": command not found\n", 21);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(full_path);
		return;
	}

	if (pid == 0)
	{
		execve(full_path, (char *const []){command, NULL}, env);
		perror("execve");
		exit(EXIT_FAILURE);
	}

	waitpid(pid, &status, 0);
	free(full_path);
}
