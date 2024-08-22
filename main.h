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
#include <dirent.h>

#define BUFFER_SIZE 1024

/* Function Prototypes */
int execute_command(char *command, char **args, char *env[]);
char *read_command(void);
char *find_path(char *command, char **env);
int is_absolute_path(char *command);
void handle_command_not_found(char *command);
char **build_path_list(char **env);
void free_path_list(char **path_list);
int _setenv(const char *name, const char *value, int overwrite);
char *get_env_var(const char *name, char **env);

#endif /* MAIN_H */
