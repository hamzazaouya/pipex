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
	t_command *commands;
	char **paths;
	char **files;
	int	command_len;
} t_pipedata;

char **get_paths(char **env);
t_command	*get_command(char **argv, int size);
char		**ft_check_files(int argc, char **argv);
void		ft_error();
void		ft_check_commands(t_pipedata *pipedata);

#endif