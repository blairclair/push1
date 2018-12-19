/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 21:22:02 by agrodzin          #+#    #+#             */
/*   Updated: 2018/12/18 21:22:03 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int is_dup(int *dup_check, int num)
{
	int i;

	i = 0;
	if (!*dup_check)
		return (1);
	while (dup_check[i])
	{
		if (dup_check[i] == num)
		{
			free(dup_check);
			return (0);
		}
		i++;
	}
	return (1);
}

int is_safe(int argc, char *argv[])
{
	int         i;
	int         *dup_check;
	long long   num;

	i = 1;
	if (argc < 2)
		return (0);
	dup_check = ft_memalloc(argc * sizeof(int*) + 1);
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		if (!ft_isnumber(argv[i]) || num > 2147483647 || num < -2147483648)
		{
			free(dup_check);
			return (-1);
		}
		if (!is_dup(dup_check, num))
			return (-1);
		dup_check[i - 1] = num;
		i++;
	}
    free(dup_check);
	return (1);
}

