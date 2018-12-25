/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rng_poss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:41:40 by agrodzin          #+#    #+#             */
/*   Updated: 2018/12/24 16:41:43 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

int		is_good_two(char *str, int num)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == num)
			return (0);
		i++;
	}	
	return (1);
}

char	*rng()
{
	int	i;
	char	*str;
	int		num;
	char	*iti;
	int		in;

	i = 0;
	str = ft_memalloc(20);
	strcpy(str, " ");
	srand(time(0));
	while (i < 5)
	{
		in = rand() % 5 + 1;
		if (!is_good_two(str, in))
		{
			while (!is_good_two(str, in))
				in = rand() % 5 + 1;
		}
		iti = ft_memalloc(20);
		iti = ft_itoa_base(in, 10);
		strcat(str, iti);
		strcat(str, " ");
			i++;
	}
	return (str);
}

int		is_good(char *str, char **args)
{
	int	i;

	i = 0;
	if (args == NULL)
		return (1);
	while (args[i])
	{
		if (!ft_strcmp(args[i], str))
			return (0);
		i++;
	}
	return (1);
}

char	**check_all()
{
	char	**args;
	int		i;
	char	*str;

	i = 0;
	args = ft_memalloc(300000);
	while (i < 5)
	{
		args[i] = ft_memalloc(6);
		str = rng();
		if (is_good(str, args))
			i++;

	}
	return (args);
}

int		main()
{
	char **arg;
	int	i;

	i = 0;
	arg = check_all();
	while (arg[i])
	{
		printf("%s\n", arg[i]);
		i++;
	}
	return (0);
}