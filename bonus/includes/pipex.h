/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:58:23 by hazaouya          #+#    #+#             */
/*   Updated: 2022/06/10 11:01:59 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include<stdio.h>
# include<unistd.h>
# include<sys/wait.h>
# include<fcntl.h>
# include<stdlib.h>
# include "libft/libft.h"

typedef struct commands
{
	char	**command;
}	t_command;

typedef struct pipedata
{
	char	**argv;
	int		cmd_num;
	int		argc;
	char	**env;
	int		**pipes;
	char	**paths;
	char	**files_name;
	char	**command;
	char	*command_path;
	char	*limiter;
	int		pipe_num;
	int		*doc_pipe;
}	t_pipedata;

char	**command(t_pipedata *pipedata, char *cmd);
char	**get_files(int argc, char **argv);
int		check_file(char *file_name, int file_num);
char	**get_paths(char **env);
int		**get_pipes(int num);
void	ft_error(char *str);
void	ft_pipex(t_pipedata *pipedata);
void	ft_error_cmd(char *str, int num);
void	ft_wait(t_pipedata *pipedata);
char	*ft_strchre(char *str, char c);
void	ft_between_cmd(t_pipedata *pipedata, int p);
void	ft_last_cmd(t_pipedata *pipedata, int p);
void	ft_first_cmd(t_pipedata *pipedata, int p);
void	ft_here_doc(t_pipedata *pipedata);
char	*get_next_line(int fd);
void	ft_close_pipes(t_pipedata *pipedata);
#endif
