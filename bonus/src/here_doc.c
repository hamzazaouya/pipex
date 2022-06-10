/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:50:59 by hazaouya          #+#    #+#             */
/*   Updated: 2022/06/10 10:57:30 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_read_doc(t_pipedata *pipedata)
{
	int		j;
	char	*limiter;

	j = 0;
	while (1)
	{
		limiter = get_next_line(0);
		j = ft_strncmp(limiter, pipedata->limiter, \
				ft_strlen(pipedata->limiter));
		if (j)
			write(pipedata->doc_pipe[1], limiter, ft_strlen(limiter));
		else
			break ;
	}
	close(pipedata->doc_pipe[1]);
}

void	ft_first_cmd_doc(t_pipedata *pipedata, int p)
{
	int	j;

	j = 0;
	while (j < pipedata->pipe_num)
	{
		close(pipedata->pipes[j][0]);
		if (j != p)
			close(pipedata->pipes[j][1]);
		j++;
	}
	pipedata->command = command(pipedata, pipedata->argv[p + 3]);
	dup2(pipedata->doc_pipe[0], 0);
	dup2(pipedata->pipes[p][1], 1);
	execve(pipedata->command_path, pipedata->command, pipedata->env);
}

void	ft_between_cmd_doc(t_pipedata *pipedata, int p)
{
	int	j;

	j = 0;
	while (j < pipedata->pipe_num)
	{
		if (j != p)
			close(pipedata->pipes[j][1]);
		if (j != p - 1)
			close(pipedata->pipes[j][0]);
		j++;
	}
	pipedata->command = command(pipedata, pipedata->argv[p + 3]);
	dup2(pipedata->pipes[p][1], 1);
	dup2(pipedata->pipes[p - 1][0], 0);
	execve(pipedata->command_path, pipedata->command, pipedata->env);
}

void	ft_last_cmd_doc(t_pipedata *pipedata, int p)
{
	int	j;
	int	fd;

	j = 0;
	while (j < pipedata->pipe_num)
	{
		close(pipedata->pipes[j][1]);
		if (j != p - 1)
			close(pipedata->pipes[j][0]);
		j++;
	}
	fd = open(pipedata->files_name[1], O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		ft_error(pipedata->files_name[1]);
	pipedata->command = command(pipedata, pipedata->argv[p + 3]);
	dup2(fd, 1);
	dup2(pipedata->pipes[p - 1][0], 0);
	execve(pipedata->command_path, pipedata->command, pipedata->env);
}

void	ft_here_doc(t_pipedata *pipedata)
{
	int	i;
	int	p;

	i = 3;
	pipedata->doc_pipe = (int *)malloc(sizeof(int) * 2);
	pipe(pipedata->doc_pipe);
	ft_read_doc(pipedata);
	while (i < pipedata->argc - 1)
	{
		p = i - 3;
		if (!fork())
		{
			if (i == 3)
				ft_first_cmd_doc(pipedata, p);
			else if (i == pipedata->argc - 2)
				ft_last_cmd_doc(pipedata, p);
			else
				ft_between_cmd_doc(pipedata, p);
			return ;
		}
		i++;
	}
	close(pipedata->doc_pipe[0]);
	ft_close_pipes(pipedata);
	ft_wait(pipedata);
}
