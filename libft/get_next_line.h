/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 11:43:49 by agrodzin          #+#    #+#             */
/*   Updated: 2018/05/07 13:45:49 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 200
# include "libft.h"
struct	s_nums
{
	int		j;
	char	*whole2;
	int		*k;
	int		fd2;
	char	buf[BUFF_SIZE + 1];
};

int		get_next_line(const int fd, char **line);

#endif
