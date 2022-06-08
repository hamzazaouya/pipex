/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exicute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:42:47 by hazaouya          #+#    #+#             */
/*   Updated: 2022/06/08 09:51:04 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_first_cmd(t_pipedata *pipedata, int p)
{
	int	j;
	int	fd;

	j = 0;
	while (j < pipedata->pipe_num)
	{
		close(pipedata->pipes[j][0]);
		if (j != p)
			close(pipedata->pipes[j][1]);
		j++;
	}
	fd = open(pipedata->files_name[0], O_RDWR);
	if (fd == -1)
		ft_error(pipedata->files_name[0]);
	pipedata->command = command(pipedata, pipedata->argv[p + 2]);
	dup2(fd, 0);
	dup2(pipedata->pipes[p][1], 1);
	execve(pipedata->command_path, pipedata->command, pipedata->env);
}

void	ft_last_cmd(t_pipedata *pipedata, int p)
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
	fd = open(pipedata->files_name[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		ft_error(pipedata->files_name[1]);
	pipedata->command = command(pipedata, pipedata->argv[p + 2]);
	dup2(fd, 1);
	dup2(pipedata->pipes[p - 1][0], 0);
	execve(pipedata->command_path, pipedata->command, pipedata->env);
}

void	ft_between_cmd(t_pipedata *pipedata, int p)
{
	int	j;
	int	fd;

	j = 0;
	while (j < pipedata->pipe_num)
	{
		if (j != p)
			close(pipedata->pipes[j][1]);
		if (j != p - 1)
			close(pipedata->pipes[j][0]);
		j++;
	}
	pipedata->command = command(pipedata, pipedata->argv[p + 2]);
	dup2(pipedata->pipes[p][1], 1);
	dup2(pipedata->pipes[p - 1][0], 0);
	execve(pipedata->command_path, pipedata->command, pipedata->env);
}

void	ft_close_pipes(t_pipedata *pipedata)
{
	int	i;

	i = 0;
	while (i < pipedata->pipe_num)
	{
		close(pipedata->pipes[i][0]);
		close(pipedata->pipes[i][1]);
		i++;
	}
}

void	ft_pipex(t_pipedata *pipedata)
{
	int	i;
	int	id;
	int	p;

	i = 2;
	while (i < pipedata->argc - 1)
	{
		p = i - 2;
		id = fork();
		if (id == 0)
		{
			if (i == 2)
				ft_first_cmd(pipedata, p);
			else if (i == pipedata->argc - 2)
				ft_last_cmd(pipedata, p);
			else
				ft_between_cmd(pipedata, p);
			return ;
		}
		i++;
	}
	ft_close_pipes(pipedata);
	ft_wait(pipedata);
}
