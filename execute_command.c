#include "main.h"

/**
 * execute_command - Executes a command.
 * @command: The command to execute.
 * @env: The environment variables.
 */
void execute_command(char *command, char **env)
{
	pid_t pid;
	char *full_path;
	char **args;
	
	args = split_command(command);
	/*to check if the absolute path is specified i.e /bin/ls*/
	if(args[0][0] == '/' || args[0][1] == '/')
	{
		full_path = args[0];
	}
	else
	{
		full_path = find_path(command, env);
		if (full_path == NULL)
		{
			write(STDERR_FILENO, command, _strlen(command));
			write(STDERR_FILENO, ": command not found\n", 21);
			return;
		}
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(full_path);
		free(args);
		return;
	}

	if (pid == 0)
	{
		execve(full_path, args, env);
		perror("execve");
		free(full_path);
		free(args);
		exit(1);
	}
	else
	{
		wait(NULL);
		free(full_path);
		free(args);
	}
}
