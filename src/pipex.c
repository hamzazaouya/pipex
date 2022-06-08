/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:24:16 by hazaouya          #+#    #+#             */
/*   Updated: 2022/06/08 09:25:06 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_init(int argc, char **argv, char **env, t_pipedata *pipedata)
{
	pipedata->files_name = get_files(argc, argv);
	pipedata->paths = get_paths(env);
	pipedata->argv = argv;
	pipedata->argc = argc;
	pipedata->env = env;
	pipedata->cmd_num = argc - 3;
	pipedata->pipe_num = argc - 4;
	pipedata->pipes = get_pipes(argc - 4);
}

int	main(int argc, char **argv, char **env)
{
	t_pipedata	pipedata;

	if (argc >= 5)
	{
		ft_init(argc, argv, env, &pipedata);
		ft_pipex(&pipedata);
	}
	else
		write(1, "Less Argument\n", 14);
}
