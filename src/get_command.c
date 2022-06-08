/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:38:21 by hazaouya          #+#    #+#             */
/*   Updated: 2022/06/08 09:42:39 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_command(char *cmd)
{
	char	**command;
	int		i;
	int		len;

	command = ft_split(cmd, ' ');
	return (command);
}

int	command_with_path(t_pipedata *pipedata, char **command)
{
	int		i;
	int		checker;
	char	*path;

	i = 0;
	checker = 1;
	path = ft_strchr(command[0], '/');
	if (path)
	{
		checker = access(path, X_OK);
		if (!checker)
			pipedata->command_path = path;
	}
	return (checker);
}

int	command_without_path(t_pipedata *pipedata, char **command)
{
	int		i;
	int		checker;
	char	*path;

	i = 0;
	while (pipedata->paths[i])
	{
		path = ft_strjoin(pipedata->paths[i], command[0]);
		checker = access(path, X_OK);
		if (!checker)
		{
			pipedata->command_path = path;
			break ;
		}
		free (path);
		i++;
	}
	return (checker);
}

char	**command(t_pipedata *pipedata, char *cmd)
{
	int		checker;
	char	**command;

	checker = 1;
	command = get_command(cmd);
	if (!pipedata->paths)
		ft_error_cmd(command[0], 2);
	else
	{
		checker = command_with_path(pipedata, command);
		if (checker == -1)
			perror(command[0]);
		if (checker == 1)
		{
			checker = command_without_path(pipedata, command);
			if (checker == -1)
				ft_error_cmd(command[0], 1);
		}
	}
	return (command);
}
