/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:52:05 by hazaouya          #+#    #+#             */
/*   Updated: 2021/11/22 14:54:57 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
