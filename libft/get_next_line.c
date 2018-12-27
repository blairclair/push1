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
int	check_if_line_done(char *temp_whole2, int i, struct s_nums *nums, char **line)
{
	static int num_tries[2000];

	ft_bzero(line[0], ft_strlen(line[0]));
	if (temp_whole2[i] != '\0' || (temp_whole2[i] == '\0' &&
		num_tries[nums->fd2] != 3 && temp_whole2[i - 1] == '\n'))
	{
		line[0] = malloc((i - 1) - nums->j);
		line[0] = ft_memmove(line[0], temp_whole2 + nums->j, (i - 1) - nums->j);
		line[0][(i - 1) - nums->j] = '\0';
		if (temp_whole2[i] == '\0')
			num_tries[nums->fd2] = 3;
		return (1);
	}
	else if (temp_whole2[i] == '\0' &&
			num_tries[nums->fd2] != 3 && temp_whole2[i - 1] != '\n')
	{
		line[0] = malloc((i + 1) - nums->j);
		line[0] = ft_memmove(line[0], temp_whole2 + nums->j, (i + 1) - nums->j);
		line[0][(i + 1) - nums->j] = '\0';
		num_tries[nums->fd2] = 3;
		return (0);
	}
	else if (num_tries[nums->fd2] == 3)
		return (3);
	return (1);
}

int	check_while(char *whole2, int i)
{
	while (whole2[i])
	{
		if ((whole2[i] == '\n' && whole2[i + 1] != '\0') || whole2[i] == '\0')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}

int	get_next_line(const int fd, char **line)
{
	static int		i[2000];
	static char		**temp_whole2;
	int				check;
	struct s_nums	nums;

	nums.whole2 = "";
	nums.fd2 = fd;
	nums.whole2 = malloc(700);
	if (fd < 0 || read(fd, 0, 0) < 0 || line == NULL)
		return (-1);
	line[0] = "";
	nums.j = i[fd];
	if (temp_whole2 == NULL)
		temp_whole2 = malloc(700);
	while ((check = read(fd, nums.buf, BUFF_SIZE)) > 0)
	{
		nums.buf[check] = '\0';
		temp_whole2[fd] = ft_strjoin(nums.whole2, nums.buf);
		nums.whole2 = temp_whole2[fd];
		ft_bzero(nums.buf, BUFF_SIZE);
	}
	temp_whole2[fd][ft_strlen(temp_whole2[fd])] = '\0';
	i[fd] = check_while(temp_whole2[fd], i[fd]);
	check = check_if_line_done(temp_whole2[fd], i[fd], &nums, &*line);
	return (check == 0 || check == 1 || check == 2 ? 1 : 0);
}