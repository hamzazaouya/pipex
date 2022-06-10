/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:59:41 by momeaizi          #+#    #+#             */
/*   Updated: 2021/12/01 11:33:09 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	ft_strcat(char *new_line, char *buff, int i)
{
	int	j;

	j = 0;
	while (buff[j])
	{
		new_line[i] = buff[j];
		if (new_line[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
		j++;
	}
	new_line[i] = 0;
}

char	*ft_strjoin(char *line, char *buff)
{
	int		i;
	char	*new_line;
	int		l_line;
	int		l_buff;

	i = 0;
	l_line = ft_strlen(line);
	l_buff = ft_strlen(buff);
	if (!l_buff)
		return (NULL);
	new_line = (char *) malloc(sizeof(char) * (l_line + l_buff + 1));
	if (!new_line)
		return (NULL);
	if (line)
	{
		while (line[i])
		{
			new_line[i] = line[i];
			i++;
		}
		free(line);
		line = NULL;
	}
	ft_strcat(new_line, buff, i);
	return (new_line);
}

void	reset_buff(char *buff)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(buff);
	j = 0;
	while (buff[i])
		buff[j++] = buff[i++];
	while (j < i)
		buff[j++] = 0;
}

void	ft_free_buff(char **buff)
{
	free(*buff);
	*buff = NULL;
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	int			bytes;

	line = NULL;
	if (buff == NULL)
		buff = (char *) ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (NULL);
	line = ft_strjoin(line, buff);
	while (!ft_check_buff(buff))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buff[bytes] = 0;
		line = ft_strjoin(line, buff);
	}
	reset_buff(buff);
	if (ft_strlen_nol(buff) == 0 && bytes <= 0)
		ft_free_buff(&buff);
	return (line);
}
