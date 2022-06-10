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

char	**get_files(int argc, char **argv)
{
	char	**files_name;
	int		i;

	i = 0;
	files_name = (char **)ft_calloc(sizeof(char *), 2);
	files_name[0] = argv[1];
	files_name[1] = argv[argc - 1];
	return (files_name);
}
