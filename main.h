#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1024

/**
* struct path_list - A node in the linked list of PATH directories.
* @path: A directory path.
* @next: Pointer to the next node in the list.
*/
typedef struct path_list
{
	char *path;
	struct path_list *next;
} path_list;

char *read_command(void);
char *find_path(char *command, char *env[]);
int execute_command(char *command_path, char *args[], char *env[]);
void handle_command_not_found(char *command);
int is_absolute_path(char *path);
int setenv(const char *name, const char *value);

#endif /* MAIN_H */
