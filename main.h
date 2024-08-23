#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

extern char **environ;

#define BUFFER_SIZE 1024

/* Function Prototypes */
void print_prompt(void);
char *read_command(void);
char **split_command(char *command);
int execute_command(char *full_path, char **args, char **env);
char *find_path(char *command, char **env);
char **build_path_list(char **env);
void free_path_list(char **path_list);
char *get_env_var(const char *name, char **env);
void *_realloc(char *str);
int _putchar(char c);
void _flush_buffer(void);

#endif /* MAIN_H */
