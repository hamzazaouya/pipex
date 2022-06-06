#ifndef PIPEX_H
# define PIPEX_H
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include <fcntl.h>
# include<stdlib.h>
# include "libft/libft.h"

typedef struct commands{
    char **command;
} t_command;

typedef struct pipedata{
	char **argv;
	int cmd_num;
	int	 argc;
	char **env;
	int	 **pipes;
	char **paths;
	int		*files_ds;
	char **command;
	char *command_path;
	int pipe_num;
} t_pipedata;

char **command(t_pipedata *pipedata, char *cmd);
int *get_files(int argc, char **argv);
int check_file(char *file_name, int file_num);
char **get_paths(char **env);
int	**get_pipes(int num);
void ft_error(int num);

#endif