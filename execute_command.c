#include "main.h"

/**
 * execute_command - Executes a command line with arguments.
 * @line: The command line to execute.
 *
 * Return: 0 on success, or -1 on failure.
 */
int execute_command(char *line)
{
	char *argv[MAX_ARGS];
	int i = 0;
	pid_t child_pid;
	int status;

	/* Tokenize the command line into arguments */
	argv[i] = strtok(line, " ");
	while (argv[i] != NULL && i < MAX_ARGS - 1)
	{
		i++;
		argv[i] = strtok(NULL, " ");
	}
	argv[i] = NULL;

	if (argv[0] == NULL)
		return (0);  /* Empty command */

	/* Fork a child process to execute the command */
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("./hsh");
		return (-1);
	}

	if (child_pid == 0)
	{
		/* In child process, execute the command */
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
//	else
//	{
		/* In parent process, wait for the child to finish */
//		waitpid(child_pid, &status, 0);
//	}

	return (0);
}
