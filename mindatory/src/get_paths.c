/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:25:19 by hazaouya          #+#    #+#             */
/*   Updated: 2022/06/08 09:36:12 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_is_path(char *env)
{
	int		i;
	char	*path;

	path = (char *) malloc(sizeof(char) * 5);
	ft_strlcpy(path, "PATH", 5);
	i = 0;
	while (i < 4)
	{
		if (env[i] != path[i])
			return (0);
		i++;
	}
	return (1);
}

char	**get_paths(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	paths = NULL;
	while (env[i])
	{
		if (ft_is_path(env[i]))
			break ;
		i++;
	}
	if (env[i])
		paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths && paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		i++;
	}
	return (paths);
}

int	**get_pipes(int num)
{
	int		i;
	int		**pipes;

	i = 0;
	pipes = (int **)malloc(sizeof(int *) * num);
	while (i < num)
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		if (pipe(pipes[i]) < 0)
			perror("");
		i++;
	}
	return (pipes);
}
