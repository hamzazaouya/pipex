/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazaouya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:12:01 by hazaouya          #+#    #+#             */
/*   Updated: 2021/12/01 12:32:34 by hazaouya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
void	ft_strcat(char *new_line, char *buff, int i);
char	*ft_strjoin(char *line, char *buff);
void	reset_buff(char *buff);
void	ft_free_buff(char **buff);
size_t	ft_strlen(char *str);
size_t	ft_strlen_nol(char *str);
int		ft_check_buff(char *buff);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
#endif
