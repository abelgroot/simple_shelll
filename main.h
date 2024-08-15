#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Maximum length for a path */
#define MAX_PATH_LENGTH 1024

/* Buffer size for path list */
#define BUFFER_SIZE 1024

/**
 * struct path_list - A node in the linked list of PATH directories.
 * @path: A directory path.
 * @next: Pointer to the next node in the list.
 */
typedef struct path_list
{
    char *path;                /**< A directory path. */
    struct path_list *next;   /**< Pointer to the next node in the list. */
} path_list;

/* Function prototypes */
char *read_command(void);
char **build_path_list(char **env);
void free_path_list(char **path_list);
char *get_env_var(const char *name, char **env);
char *find_path(char *command, char *env[]);
int execute_command(char *command_path, char *args[], char *env[]);
void handle_command_not_found(char *command);
int is_absolute_path(char *path);
int my_setenv(const char *name, const char *value);

/*Helper functions*/
void *_realloc(char *str);

#endif /* MAIN_H */
