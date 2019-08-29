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

#include "get_next_line.h"

static int		set_the_line(struct s_line *file_stuff)
{
	char	*buf;
	int		ret;
    char    *temp;

    buf = ft_memalloc(BUFF_SIZE + 1);
	if ((ret = read(file_stuff->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
        temp = file_stuff->buf;
		file_stuff->buf = ft_strjoin(file_stuff->buf, buf);
		free(temp);
	}
    free(buf);
	return (ret);
}

static struct s_line	*get_the_file(const int fd, struct s_line **head)
{
	struct s_line *mem_stuff;

	mem_stuff = *head;
	while (mem_stuff)
	{
		if (mem_stuff->fd == fd)
			break;
		mem_stuff = mem_stuff->next;
	}
	if (!mem_stuff)
	{
		mem_stuff = ft_memalloc(sizeof(struct s_line));
		mem_stuff->fd = fd;
		mem_stuff->buf = ft_memalloc(0);
		mem_stuff->next = *head;
		*head = mem_stuff;
	}
	return (mem_stuff);
}

static int          get_the_line(struct s_line *file_stuff, char **line)
{
    int i;
    char *tmp;
	char	*tmp2;

    i = 0;
	tmp = NULL;
	while (!(ft_strchr(file_stuff->buf, '\n')))
	{
        i  = set_the_line(file_stuff);
		if (i < 0)
			return (-1);
		if (i == 0 && ((ft_strchr(file_stuff->buf, '\n') == 0)))
		{
			CHECKX(file_stuff->buf[0]);
            *line = file_stuff->buf;
			return (1);
		}
	}
	*line = ft_strsub(file_stuff->buf, 0,
	(ft_strchr(file_stuff->buf, '\n') - file_stuff->buf));
    tmp = file_stuff->buf;
	tmp2 = ft_strchr(file_stuff->buf, '\n');
	file_stuff->buf = ft_strdup(tmp2 + 1);
	free(tmp);
	tmp = NULL;
    return (1);
}

int				get_next_line(const int fd, char **line)
{
	static struct s_line	*head;
	struct s_line			*file_stuff;

	if (fd < 0 || !line)
		return (-1);
	file_stuff = get_the_file(fd, &head);
    CHECKX(file_stuff->buf);
    return (get_the_line(file_stuff, line));
}