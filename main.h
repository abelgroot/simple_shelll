#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_ARGS 64  /* Maximum number of arguments */

/* Function prototypes */
ssize_t read_command(char **line, size_t *len);
int execute_command(char *line);
char *find_command_in_path(char *cmd);

#endif /* MAIN_H */
