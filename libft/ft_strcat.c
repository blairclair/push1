/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 18:53:17 by agrodzin          #+#    #+#             */
/*   Updated: 2018/04/30 18:59:14 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("s2: %s\n", s2);
	printf("hithere\n");
	while (s1[i])
	{
		i++;
	}
	printf("ko\n");
	while (s2[j])
	{
		// printf("k3\n");
		s1[i] = s2[j];
		// printf("k4\n");
		j++;
		i++;
	}
	printf("k2\n");
	s1[i] = '\0';
	return (s1);
}
