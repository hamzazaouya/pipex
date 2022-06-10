/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:36:24 by hazaouya          #+#    #+#             */
/*   Updated: 2022/06/10 10:50:54 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error_cmd(char *str, int num)
{
	write(2, str, ft_strlen(str));
	write(2, ": ", 2);
	if (num == 1)
	{
		write(2, "command not found\n", ft_strlen("command not found\n"));
		exit(0);
	}
	else if (num == 2)
	{
		write(2, "No such file or directory\n"\
				, ft_strlen("No such file or directory\n"));
		exit(127);
	}
}

void	ft_error(char *str)
{
	perror(str);
	exit(0);
}

char	*ft_strchre(char *str, char c)
{
	int	i;
	int	is_in;

	i = 0;
	is_in = 0;
	while (str[i])
	{
		if (str[i] == c)
			is_in = 1;
		i++;
	}
	i = 0;
	while (is_in && str[i])
	{
		if (str[i] != ' ' || str[i] != '\t')
			return (str + i);
		i++;
	}
	return (NULL);
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
