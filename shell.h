#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* for read/write buffers */
#define WRITE_BUF_SIZE 1024
#define READ_BUF_SIZE 1024
#define BUF_FLUSH -1

/* 1 if using system getline() */
#define USE_STRTOK 0
#define USE_GETLINE 0

#define HIST_MAX	4096
#define HIST_FILE	".simple_shell_history"

extern char **environ;

/**
 * struct liststr - Singly linked list
 * @num: Number field
 * @str: String
 * @next: The points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - It contains pseudo-args to pass into a function,
 *                   allowing uniform prototype for function pointer struct
 * @argv: It is an array of strings generated from arg
 * @arg: String generated from getline containing args
 * @argc: Argument count
 * @path: String path for current command
 * @line_count: Error count
 * @linecount_flag: If on count this line of input
 * @err_num: Error code for exit(s)
 * @fname: Program filename
 * @env: The linked list local copy of environ
 * @environ: The custom modified copy of environ from LL env
 * @alias: Alias node
 * @history: History node
 * @env_changed: On if environ was changed
 * @status: It is the return status of the last exec'd command
 * @cmd_buf: The address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @histcount: It is the history line number count
 * @readfd: The fd from which to read line input
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - It contains a builtin string and related function
 * @type: It is the builtin command flag
 * @func: function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* loophsh.c */
int loophsh(char **);

/* toem_shloop.c */
void find_cmd(info_t *);
void fork_cmd(info_t *);
int hsh(info_t *, char **);
int find_builtin(info_t *);

/* toem_parser.c */
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);
int is_cmd(info_t *, char *);

/* toem_string.c */
int _strlen(char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
int _strcmp(char *, char *);

/* toem_string1.c */
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
char *_strcpy(char *, char *);

/* toem_errors.c */
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
void _eputs(char *);
int _eputchar(char);

/* toem_errors1.c */
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);
int _erratoi(char *);
void print_error(info_t *, char *);

/* toem_memory.c */
int bfree(void **);

/* toem_realloc.c */
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
char *_memset(char *, char, unsigned int);

/* toem_tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* toem_exits.c */
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
char *_strncpy(char *, char *, int);

/* toem_atoi.c */
int interactive(info_t *);
int _isalpha(int);
int _atoi(char *);
int is_delim(char, char *);

/* toem_builtin.c */
int _mycd(info_t *);
int _myhelp(info_t *);
int _myexit(info_t *);

/* toem_builtin1.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/*toem_getline.c */
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);
ssize_t get_input(info_t *);
ssize_t input_buf(info_t *info, char **buf, size_t *len);
ssize_t read_buf(info_t *info, char *buf, size_t *i);

/* toem_getinfo.c */
void clear_info(info_t *);
void free_info(info_t *, int);
void set_info(info_t *, char **);

/* toem_environ.c */
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);
char *_getenv(info_t *, const char *);
int _myenv(info_t *);

/* toem_getenv.c */
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);
char **get_environ(info_t *);

/* toem_lists.c */
list_t *add_node(list_t **, const char *, int);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);

/* toem_lists1.c */
size_t list_len(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);

/* toem_history.c */
int write_history(info_t *info);
int read_history(info_t *info);
char *get_history_file(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* toem_vars.c */
int is_chain(info_t *, char *, size_t *);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);

#endif
