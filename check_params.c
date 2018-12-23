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
// fix the fact that the checker reads all the args in one 
// string in the way that they will test it re: corrections pdf
int is_safe(int argc, char *argv[])
{
	int         i;
	int         *dup_check;
	long long   num;
	char		**str;
	int			ret;

	i = 1;
	ret = 1;
	if (argc < 2)
		return (0);
	if (ft_strlen(argv[1]) > 1)
	{
		str = ft_strsplit(argv[1], ' ');
		ret = 3;
		i = 0;
	}
	else
		str = argv;
	dup_check = ft_memalloc(argc * sizeof(int*) + 1);
	while (str[i])
	{
		num = ft_atol(str[i]);
		if (!ft_isnumber(str[i]) || num > 2147483647 || num < -2147483648)
		{
			printf("ai: %s\n", str[i]);
			free(dup_check);
			return (-1);
		}
		if (!is_dup(dup_check, num))
			return (-1);
		dup_check[i - 1] = num;
		i++;
	}
    free(dup_check);
	return (ret);
}

