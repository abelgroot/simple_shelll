#include "main.h"

/**
 * execute_command - Forks a process to execute a command
 * @full_path: The full path to the command
 * @args: The arguments for the command
 * @env: The environment variables
 *
 * Return: The status of the executed command
 */
int execute_command(char *full_path, char **args, char **env)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(full_path, args, env) == -1)
		{
			perror("execve");
			_exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return ((WIFEXITED(status)) ? WEXITSTATUS(status) : -1);
}
