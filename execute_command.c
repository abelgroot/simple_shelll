#include "main.h"

/**
 * handle_command_not_found - Prints an error message
 * if the command is not found.
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
	char *cmd_path;

	argv[i] = strtok(line, " ");
	while (argv[i] != NULL && i < MAX_ARGS - 1)
	{
		i++;
		argv[i] = strtok(NULL, " ");
	}
	argv[i] = NULL;

	if (argv[0] == NULL)
		return (0);  /* Empty command */
	cmd_path = find_command_in_path(argv[0]);
	if (cmd_path == NULL)
	{
		handle_command_not_found(argv[0]);
		return (-1);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("./hsh");
		free(cmd_path);
		return (-1);
	}
	if (child_pid == 0)
	{
		execute_command_in_child(cmd_path, argv);
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
	free(cmd_path);
	return (0);
}
