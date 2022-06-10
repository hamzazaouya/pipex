/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:24:16 by hazaouya          #+#    #+#             */
/*   Updated: 2022/06/10 11:07:40 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_init_pipex(t_pipedata *pipedata)
{
	pipedata->files_name = get_files(pipedata->argc, pipedata->argv);
	pipedata->paths = get_paths(pipedata->env);
	pipedata->cmd_num = pipedata->argc - 3;
	pipedata->pipe_num = pipedata->argc - 4;
	pipedata->pipes = get_pipes(pipedata->pipe_num);
}

void	ft_init_heredoc(t_pipedata *pipedata)
{
	if (ft_strlen(pipedata->argv[2]) == 0)
		pipedata->limiter = ft_strdup("\n");
	else
		pipedata->limiter = pipedata->argv[2];
	pipedata->files_name = get_files(pipedata->argc, pipedata->argv);
	pipedata->paths = get_paths(pipedata->env);
	pipedata->cmd_num = pipedata->argc - 4;
	pipedata->pipe_num = pipedata->argc - 4;
	pipedata->pipes = get_pipes(pipedata->pipe_num);
}

int	main(int argc, char **argv, char **env)
{
	t_pipedata	pipedata;
	int			k;

	pipedata.argc = argc;
	pipedata.argv = argv;
	pipedata.env = env;
	if (argc > 1)
	{
		k = ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc"));
	}
	if (!k && !argv[1][ft_strlen("here_doc")] && argc >= 6)
	{
		ft_init_heredoc(&pipedata);
		ft_here_doc(&pipedata);
	}
	else if (argc >= 5)
	{
		ft_init_pipex(&pipedata);
		ft_pipex(&pipedata);
	}
	else
		write(1, "Less Argument\n", 14);
}
