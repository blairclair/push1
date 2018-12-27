/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:48:01 by agrodzin          #+#    #+#             */
/*   Updated: 2018/05/07 13:42:23 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
int	get_char_pos(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int	get_next_line(const int fd, char **line)
{
	char	*buf;
	int		ret;
	static char	*tmp = NULL;
	char	*final;

	buf = ft_memalloc(50);
	while (1)
	{
		ft_bzero(buf, ft_strlen(buf));
		ret = read(fd, buf, 20);
		if (buf == NULL || ret == 0)
			return (0);
		buf[ret + 1] = '\0';
		if (tmp)
			final = ft_strjoin(tmp, buf);
		else
			final = buf;
		printf("final 1: %s\n", final);
		if ((tmp = ft_strchr(final, '\n')) != NULL)
		{
			final[get_char_pos(final, '\n')] = '\0';
			printf("final 2: %s\n", final);
			(*line) = final;
			break ;
		}
		
	}
	if (tmp)
		return (1);
	return (0);
}