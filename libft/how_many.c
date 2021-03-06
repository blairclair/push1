/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_many.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 10:27:18 by agrodzin          #+#    #+#             */
/*   Updated: 2018/10/04 10:27:20 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	how_many(char *str, char c)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (str[i] == c)
			num++;
		i++;
	}
	return (num);
}
