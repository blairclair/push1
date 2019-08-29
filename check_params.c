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

int	is_dup(int *dup_check, int num, int num_dup)
{
	int i;

	i = 0;
	while (i < num_dup)
	{
		if (dup_check[i] == num)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_num(char **str, int *dup_check, int i)
{
	long long	num;
	static int	num_dup = 0;

	while (str[i])
	{
		num = ft_atol(str[i]);
		if (!ft_isnumber(str[i]) || num > 2147483647 ||
		num < -2147483648 || !is_dup(dup_check, num, num_dup))
		{
			return (0);
		}
		dup_check[i] = num;
		num_dup++;
		i++;
	}
	return (1);
}

int	check_num_and_free(int argc, char **str, int ret, int is_string)
{
	int			*dup_check;

	dup_check = ft_memalloc(argc * sizeof(int*) + 1);
	if (!check_num(str, dup_check, 0))
		ret = -1;
	if (is_string)
		free_two_d(str);
	else
		free(str);
	free(dup_check);
	return (ret);
}

int	is_safe(int argc, char *argv[])
{
	char		**str;
	int			ret;
	int			j;
	int			is_string;

	j = 0;
	ret = 1;
	if (argc < 2)
		return (0);
	if (ft_strlen(argv[1]) > 1 && is_ws(argv[1], 0))
	{
		str = ft_strsplit(argv[1], ' ');
		argc = count_num_2d_args(str) + 1;
		ret = 3;
		is_string = 1;
	}
	else
	{
		str = ft_memalloc(argc * sizeof(char*));
		while (argv[j++])
			str[j - 1] = argv[j];
		is_string = 0;
	}
	ret = check_num_and_free(argc, str, ret, is_string);
	return (ret);
}
