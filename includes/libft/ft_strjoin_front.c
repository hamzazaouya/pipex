/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:08:35 by hazaouya          #+#    #+#             */
/*   Updated: 2021/11/21 13:49:52 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_front(char *s1, char const *s2)
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s2);
	len = i + ft_strlen(s1) + 1;
	str = (char *) malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
    ft_strlcpy(str, s2, len);
	ft_strlcpy(str + i, s1, len);
	free(s1);
	return (str);
}