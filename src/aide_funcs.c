/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:36:24 by hazaouya          #+#    #+#             */
/*   Updated: 2022/06/08 09:38:14 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error_cmd(char *str, int num)
{
	write(1, str, ft_strlen(str));
	write(1, ": ", 2);
	if (num == 1)
	{
		write(1, "command not found\n", ft_strlen("command not found\n"));
		exit(0);
	}
	else if (num == 2)
	{
		write(1, "No such file or directory\n"\
				, ft_strlen("No such file or directory\n"));
		exit(127);
	}
}

void	ft_error(char *str)
{
	perror(str);
	exit(0);
}

void	ft_wait(t_pipedata *pipedata)
{
	int	i;

	i = 0;
	while (i < pipedata->cmd_num)
	{
		wait(NULL);
		i++;
	}
}
